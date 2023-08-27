#pragma once

#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

#include <chrono>

#include <ArduinoJson.h>
#include <Wire.h>
#include <esp_now.h>

#include "sleep.h"

namespace TestESPNow
{
    // Peer information
    constexpr esp_now_peer_info_t peerInfo = {
        .peer_addr = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, // Broadcast
        .channel = 0,
        .encrypt = false,
    };

    inline void setupESPNow()
    {
        // Set device as a WiFi Station
        WiFi.mode(WIFI_STA);

        // Init ESP-Now
        if (esp_now_init() != ESP_OK)
        {
            Serial.println("Error initializing ESP-Now");
            return;
        }

        // Fill out peer info
        // memcpy(peerInfo.peer_addr, BROADCAST_ADDRESS, 6);
        // peerInfo.channel = 0;
        // peerInfo.encrypt = false;

        // Add peer
        if (esp_now_add_peer(&peerInfo) != ESP_OK)
        {
            Serial.println("Failed to add peer");
            return;
        }
    }

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
        StaticJsonDocument<128> json;
        json["tem"] = 1.2345f;
        json["hum"] = 55;
        json["pre"] = 5000;
        json["soc"] = 10;
        json["ill"] = 500;
        sendESPNow(json);
        sleep(std::chrono::seconds(10));
    }

    inline void loop() { yield(); }
} // namespace TestESPNow
