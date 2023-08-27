#pragma once

#ifdef ESP32
#include <WiFi.h>
#include <esp_wifi.h>
#else
#include <ESP8266WiFi.h>
#endif

#include <chrono>

#include <ArduinoJson.h>
#include <Wire.h>
#include <esp_now.h>

#include "Debug.h"
#include "EPD.h"
#include "Key.h"
#include "Sensors.h"
#include "StopWatch.h"
#include "sleep.h"

RTC_DATA_ATTR int bootCount = 0;

namespace Sensor
{
    /// @brief WiFi channel to use for sending ESP NOW data
    /// @note This needs to be the same channel as the WiFi network the BASE is connecting to
    constexpr static uint8_t WIFI_CHANNEL = 6;

    /// @brief Peer information
    constexpr esp_now_peer_info_t peerInfo = {
        .peer_addr = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, // Broadcast
        .channel = 0,
        .encrypt = false,
    };

    /// @brief Print free RAM
    inline void printRAM() { RS_DEBUGF("Free RAM is %d\n", heap_caps_get_free_size(MALLOC_CAP_INTERNAL)); }

    /// @brief Setup ESPNow for sending broadcast messages
    inline void setupESPNow()
    {
        // Set device as a WiFi Station
        WiFi.mode(WIFI_STA);
        if (WIFI_CHANNEL > 0)
        {
            esp_wifi_set_channel(WIFI_CHANNEL, WIFI_SECOND_CHAN_NONE);
        }

        // Init ESP-Now
        if (esp_now_init() != ESP_OK)
        {
            RS_DEBUGLN("Error initializing ESP-Now");
            return;
        }

        // Fill out peer info
        // memcpy(peerInfo.peer_addr, BROADCAST_ADDRESS, 6);
        // peerInfo.channel = 0;
        // peerInfo.encrypt = false;

        // Add peer
        if (esp_now_add_peer(&peerInfo) != ESP_OK)
        {
            RS_DEBUGLN("Failed to add peer");
            return;
        }
    }

    /// @brief Send the given json data using ESPNow
    /// @param json Key value pairs to send
    inline void sendESPNow(const JsonDocument& json)
    {
        setupESPNow();
        uint8_t data[128];
        const size_t bytes = serializeMsgPack(json, data);
        esp_now_send(peerInfo.peer_addr, data, bytes);
        esp_now_deinit();
        WiFi.mode(WIFI_MODE_NULL);
    }

    inline void setup()
    {
#ifdef RS_DEBUG_SERIAL
        StopWatch total;
        total.start();
#endif
        // Increment boot number and print it every reboot
        ++bootCount;

        // Turn LED on
        pinMode(33, OUTPUT);
        digitalWrite(33, HIGH);
#ifdef RS_DEBUG_SERIAL
        // Init Serial Monitor
        RS_DEBUG_SERIAL.begin(115200);
        RS_DEBUG_SERIAL.printf("Boot #%d\n", bootCount);
#endif

#ifdef RS_DEBUG_SERIAL
        StopWatch watch;
        watch.start();
#endif
        // Turn sensor power on
        pinMode(14, OUTPUT);
        digitalWrite(14, LOW);
        // Set values to send
        Wire.begin(SDA, SCL, 1000000);
        // Turn LED off
        digitalWrite(33, LOW);
        const auto sensor = BME680::read();
        Wire.end();
        const uint16_t luminance = (uint16_t)LDR::getIlluminance(3.3_V).lx;
        // Turn sensor power off
        digitalWrite(14, HIGH);

        // Data being sent
        StaticJsonDocument<128> json;
        json[Key::TEMPERATURE.getKey()] = sensor.temperature;
        json[Key::HUMIDITY.getKey()] = sensor.humidity;
        json[Key::PRESSURE.getKey()] = sensor.pressure;
        json[Key::ILLUMINANCE.getKey()] = luminance;

        const Voltage battery = Battery::getVoltage();
        const uint8_t soc = Battery::voltageToSOC(battery);
        json[Key::BATTERY_SOC.getKey()] = soc;
        json[Key::BATTERY_VOLTAGE.getKey()] = (double)battery.volt;

        RS_DEBUGF("Sensors: %dms\n", std::chrono::duration_cast<std::chrono::milliseconds>(watch.stop()));
        RS_DEBUGF("Battery: %.3fV\n", battery);
#ifdef RS_DEBUG_SERIAL
        watch.start();
#endif
        sendESPNow(json);
        RS_DEBUGF("ESPNow: %dms\n", std::chrono::duration_cast<std::chrono::milliseconds>(watch.stop()));

#ifdef RS_DEBUG_SERIAL
        watch.start();
#endif
        DisplayData displayData = {};
        displayData.temperature = sensor.temperature;
        displayData.perception = getThermalPerception(sensor.temperature);
        displayData.humidity = sensor.humidity;
        displayData.pressure = sensor.pressure;
        displayData.gas = sensor.gas;
        displayData.soc = soc;

        ONE_BIT_DISPLAY epd;
        EPD::init(epd);
        EPD::update(epd, displayData, bootCount % 24 != 1);
        RS_DEBUGF("EPD: %dms\n", std::chrono::duration_cast<std::chrono::milliseconds>(watch.stop()));

        RS_DEBUGF("Total time: %dms\n", std::chrono::duration_cast<std::chrono::milliseconds>(total.stop()));
        // sleep(std::chrono::seconds(330)); // Accomodate sleeping 30s before epd is done updating
        sleep(std::chrono::seconds(210)); // Accomodate sleeping 30s before epd is done updating
        // sleep(std::chrono::seconds(20));
    }

    inline void loop() { }
} // namespace Sensor
