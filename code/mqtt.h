#pragma once

#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

#include <ArduinoJson.h>
#include <PubSubClient.h>

#include "HomeAssistant.h"

constexpr static const char* CONNECTED PROGMEM = "Connected";
constexpr static const char* DISCONNECTED PROGMEM = "Disconnected";

bool publishJSON(PubSubClient& mqtt, const String& topic, const JsonDocument& json, const bool retain = false)
{
    const size_t size = measureJson(json);
    if (!mqtt.beginPublish(topic.c_str(), size, true))
    {
        RS_DEBUGF("[MQTT] Could not begin publish with size %d\n", size);
        return false;
    }
    serializeJson(json, mqtt);
    const bool result = mqtt.endPublish();

    // #ifdef RS_DEBUG_SERIAL
    //     serializeJsonPretty(json, RS_DEBUG_SERIAL);
    // #endif

    // char jsonStr[600];
    // serializeJson(json, jsonStr);
    // mqtt.publish(topic.c_str(), 0, true, jsonStr);
    // return true;

    return result;
}
