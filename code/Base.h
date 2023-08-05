#pragma once

#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

#include <array>
#include <memory>
#include <set>

#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <esp_now.h>

#include "Config.h"
#include "Debug.h"
#include "Key.h"
#include "mqtt.h"

namespace Base
{
    /// @brief LED pin
    // In theory 2 is the on board LED, but it is always on
    constexpr static const uint8_t LED = 2;

    /// @brief Set of all known sensor clients
    std::set<String> knownClients = {};

    /// @brief WiFi client used for MQTT
    WiFiClient wifiClient;
    /// @brief MQTT client
    PubSubClient mqtt;
    /// @brief Timer called for connecting to WiFi
    TimerHandle_t wifiReconnectTimer;
    /// @brief Timer called for connecting to MQTT
    TimerHandle_t mqttReconnectTimer;

    inline void led(const bool on)
    {
        // digitalWrite(LED, on);
    }

    /// @brief Handle the discovery message for the given DataKey
    /// @tparam clazz Device class
    /// @tparam unit Data unit
    /// @param json
    /// @param mac
    /// @param key
    inline void handleDiscovery(const JsonDocument& json, const String& mac, const DataKey& key)
    {
        if (json.containsKey(key.getKey()))
        {
            key.publishDiscovery(mqtt, mac);
        }
    }

    /// @brief ESPNow data callback
    /// @param macPtr Pointer to client mac address
    /// @param data Pointer to received data packet
    /// @param len Length of data
    void onESPNowData(const uint8_t* macPtr, const uint8_t* data, int len)
    {
        led(true);
        // Convert MAC to string
        char buffer[13];
        snprintf(buffer, sizeof(buffer), "%02x%02x%02x%02x%02x%02x", macPtr[0], macPtr[1], macPtr[2], macPtr[3],
            macPtr[4], macPtr[5]);
        const String mac = buffer;

        // Deserialize data
        StaticJsonDocument<128> json;
        deserializeMsgPack(json, data, len);

        // Check if client is already known
        if (knownClients.find(mac) == knownClients.end())
        {
            // Add client to known ones and send mqtt auto config for HA
            knownClients.emplace(mac);

            RS_DEBUGF("[Base] Sending auto config for %s\n", mac.c_str());
            for (const auto& key : Key::KEYS)
            {
                handleDiscovery(json, mac, key);
            }
        }

        // Print debug information
        RS_DEBUG("[");
        RS_DEBUG(mac);
        RS_DEBUG("] ");
#ifdef RS_DEBUG_SERIAL
        serializeJsonPretty(json, RS_DEBUG_SERIAL);
#endif
        RS_DEBUGLN();

        // Push data to MQTT
        const String topic = "EPDBase/" + mac + "/state";
        if (!publishJSON(mqtt, topic, json))
        {
            RS_DEBUGLN("[Base] Could not publish sensor update");
        }
        led(false);
    }

    /// @brief Connect to WiFi AP
    void connectToWifi()
    {
        RS_DEBUGLN("[WiFi] Connecting...");
        WiFi.begin(SSID, PASS);
    }

    /// @brief Connect to MQTT broker
    void connectToMqtt()
    {
        RS_DEBUGLN("[MQTT] Connecting...");
        mqtt.setClient(wifiClient);
        mqtt.setServer("192.168.2.3", 1883);
        const bool connected = mqtt.connect("EPDBase", "mosquitto", "dietpi");
        // (mqttConfig.topic + "/lwt").c_str(), 2, true, DISCONNECTED);

        if (connected)
        {
            RS_DEBUGLN("[MQTT] connected");
            xTimerStop(mqttReconnectTimer, 0);
        }
    }

    /// @brief Setup ESPNow
    void setupESPNow()
    {
        esp_err_t state = esp_now_init();
        if (state != ESP_OK)
        {
            RS_DEBUG("[ESPNow] Error initializing: ");
            RS_DEBUGLN(esp_err_to_name(state));
            return;
        }

        state = esp_now_register_recv_cb(onESPNowData);
        if (state != ESP_OK)
        {
            RS_DEBUG("[ESPNow] Error setting callback: ");
            RS_DEBUGLN(esp_err_to_name(state));
            return;
        }
    }

    /// @brief WiFi event callback
    /// @param event Event
    void onWiFiEvent(WiFiEvent_t event)
    {
        switch (event)
        {
        case SYSTEM_EVENT_STA_GOT_IP:
            RS_DEBUG("[WiFi] Connected: ");
            RS_DEBUGLN(WiFi.localIP());
            xTimerStop(wifiReconnectTimer, 0);
            xTimerStart(mqttReconnectTimer, 0);
            break;
        case SYSTEM_EVENT_STA_DISCONNECTED:
            RS_DEBUGLN("[WiFi] lost connection");
            xTimerStop(mqttReconnectTimer, 0); // ensure we don't reconnect to MQTT while reconnecting to WiFi
            xTimerStart(wifiReconnectTimer, 0);
            break;
        }
    }

    /// @brief Setup
    inline void setup()
    {
        // pinMode(LED, OUTPUT);
        led(false);
        Serial.begin(115200);
        RS_DEBUGLN();
        RS_DEBUG("[Base] MAC: ");
        RS_DEBUGLN(WiFi.macAddress());

        mqttReconnectTimer = xTimerCreate("mqttTimer", pdMS_TO_TICKS(2000), pdFALSE, (void*)0,
            reinterpret_cast<TimerCallbackFunction_t>(connectToMqtt));
        wifiReconnectTimer = xTimerCreate("wifiTimer", pdMS_TO_TICKS(2000), pdFALSE, (void*)0,
            reinterpret_cast<TimerCallbackFunction_t>(connectToWifi));

        WiFi.onEvent(onWiFiEvent);

        // Need to use WIFI_AP_STA otherwise ESPNow packets are not received while connected to WiFi
        WiFi.mode(WIFI_AP_STA);

        setupESPNow();
        connectToWifi();
    }

    bool lastMqttConnected = false;

    /// @brief Loop
    inline void loop()
    {
        const bool connected = mqtt.loop();
        if (connected != lastMqttConnected)
        {
            lastMqttConnected = connected;

            if (!connected)
            {
                RS_DEBUGLN("[MQTT] Disconnected");
                xTimerStart(mqttReconnectTimer, 0);
            }
        }
        yield();
    }
} // namespace Base
