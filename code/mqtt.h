#pragma once

#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

#include <ArduinoJson.h>
#include <PubSubClient.h>

#include "HomeAssistant.h"

void addDeviceInfo(JsonDocument& json, const String& deviceID)
{
    auto dev = json[HA::Property::Device];
    dev[HA::Property::DeviceManufacturer] = "enwi";
    // dev[HA::Property::DeviceModel] = String(MODEL) + " " + HARDWARE_VERSION;
    dev[HA::Property::Name] = deviceID;
    // dev[HA::Property::DeviceSoftwareVersion] = SOFTWARE_VERSION;
    dev[HA::Property::DeviceConfigUrl] = String("http://") + WiFi.localIP().toString();

    dev.createNestedArray(HA::Property::DeviceIdentifiers).add(deviceID);
}

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
    return mqtt.endPublish();

    // char jsonStr[600];
    // serializeJson(json, jsonStr);
    // mqtt.publish(topic.c_str(), 0, true, jsonStr);
    // return true;
}

void publishSensorDiscovery(PubSubClient& mqtt, const String& deviceID, const String& name, const String& id,
    const String& deviceClass, const String& unit, const String& stateClass, const String& valueTemplate,
    const String& icon = "")
{
    StaticJsonDocument<600> autoConfig;

    // const String deviceID = getDeviceID();
    addDeviceInfo(autoConfig, deviceID);

    autoConfig[HA::Property::DeviceClass] = deviceClass;
    autoConfig[HA::Property::UnitOfMeasurement] = unit;
    autoConfig[HA::Property::StateClass] = stateClass;

    autoConfig[HA::Property::Name] = deviceID + " " + name;
    autoConfig[HA::Property::UniqueId] = deviceID + "_" + id;
    // autoConfig[HA::Topic::Base] = mqttConfig.topic;
    autoConfig[HA::Topic::Base] = "EPDBase/" + deviceID;
    // autoConfig["avty_t"] = "~/lwt";
    // autoConfig["pl_avail"] = CONNECTED;
    // autoConfig["pl_not_avail"] = DISCONNECTED;
    autoConfig[HA::Topic::State] = "~/state";
    autoConfig[HA::Property::ValueTemplate] = valueTemplate;
    if (!icon.isEmpty())
    {
        autoConfig[HA::Property::Icon] = icon;
    }

    const String topic = "homeassistant/sensor/" + deviceID + "/" + id + "/config";
    publishJSON(mqtt, topic, autoConfig, true);
}

void publishSensorDiscovery(PubSubClient& mqtt, const String& deviceID, const String& name, const String& id,
    const String& valueTemplate, const String& icon = "")
{
    StaticJsonDocument<600> autoConfig;

    // const String deviceID = getDeviceID();
    addDeviceInfo(autoConfig, deviceID);

    autoConfig[HA::Property::Name] = deviceID + " " + name;
    autoConfig[HA::Property::UniqueId] = deviceID + "_" + id;
    // autoConfig[HA::Topic::Base] = mqttConfig.topic;
    autoConfig[HA::Topic::Base] = "EPDBase/" + deviceID;
    // autoConfig["avty_t"] = "~/lwt";
    // autoConfig["pl_avail"] = CONNECTED;
    // autoConfig["pl_not_avail"] = DISCONNECTED;
    autoConfig[HA::Topic::State] = "~/state";
    autoConfig[HA::Property::ValueTemplate] = valueTemplate;
    if (!icon.isEmpty())
    {
        autoConfig[HA::Property::Icon] = icon;
    }

    const String topic = "homeassistant/sensor/" + deviceID + "/" + id + "/config";
    publishJSON(mqtt, topic, autoConfig, true);
}