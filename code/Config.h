#pragma once

/// @todo Use WiFiManager
/// @brief Your WiFi SSID
constexpr static const char* SSID PROGMEM = "YourSSID";
/// @brief Your WiFi password
constexpr static const char* PASS PROGMEM = "YourPassword";

/// @brief MQTT Broker IP
constexpr static const char* MQTT_HOST PROGMEM = "192.168.2.3";
/// @brief MQTT Broker port
constexpr static const uint16_t MQTT_PORT PROGMEM = 1883;
/// @brief MQTT Client id
constexpr static const char* MQTT_DEVICE PROGMEM = "EPDBase";
/// @brief MQTT Client user
constexpr static const char* MQTT_USER PROGMEM = "mosquitto";
/// @brief MQTT Client password
constexpr static const char* MQTT_PASS PROGMEM = "dietpi";