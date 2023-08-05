#pragma once

#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

#include <array>
#include <chrono>
#include <memory>

#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <esp_now.h>

#include "Config.h"
#include "sleep.h"

namespace TestWiFi
{
    /// @brief WiFi client used for MQTT
    WiFiClient wifiClient;
    /// @brief MQTT client
    PubSubClient mqtt;

    /// @brief Connect to WiFi AP
    bool connectToWifi()
    {
        Serial.println("[WiFi] Connecting...");
        WiFi.begin(SSID, PASS);
        return WiFi.waitForConnectResult() == WL_CONNECTED;
    }

    /// @brief Connect to MQTT broker
    bool connectToMqtt()
    {
        Serial.println("[MQTT] Connecting...");
        mqtt.setClient(wifiClient);
        mqtt.setServer("192.168.2.3", 1883);
        const bool connected = mqtt.connect("TestWiFi", "mosquitto", "dietpi");
        // (mqttConfig.topic + "/lwt").c_str(), 2, true, DISCONNECTED);

        if (!connected)
        {
            Serial.println("[MQTT] Could not connect");
            return false;
        }
        Serial.println("[MQTT] connected");

        // Publish example payload
        mqtt.publish("test/1234", R"({"tem":20.10582352,"hum":53,"pre":98936,"soc":0,"ill":0})");
        mqtt.loop();
        return true;
    }

    inline void setup()
    {
        Serial.begin(115200);
        connectToWifi() && connectToMqtt();
        sleep(std::chrono::seconds(10));
    }

    inline void loop() { yield(); }
} // namespace TestWiFi
