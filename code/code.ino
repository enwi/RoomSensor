#include "Base.h"
#include "Sensor.h"
// #include "TestBLE.h"
// #include "TestESPNow.h"
// #include "TestSensor.h"
// #include "TestWiFi.h"

enum class Type
{
    BASE,
    SENSOR,
    TEST_BLE,
    TEST_WIFI,
    TEST_ESPNOW,
    TEST_SENSOR,
};

/// @brief Select which code to use
/// @note In order to receive ESP NOW messages while the BASE is connected to WiFi
/// you need to make sure that the SENSOR is using the same WiFi channel as the WiFi network
constexpr static const Type type = Type::SENSOR;

void setup()
{
    switch (type)
    {
    case Type::BASE:
        Base::setup();
        break;
    case Type::SENSOR:
        Sensor::setup();
        break;
    case Type::TEST_BLE:
        // BLETest::setup();
        break;
    case Type::TEST_WIFI:
        // TestWiFi::setup();
        break;
    case Type::TEST_ESPNOW:
        // TestESPNow::setup();
        break;
    case Type::TEST_SENSOR:
        // TestSensor::setup();
        break;
    }
}

void loop()
{
    switch (type)
    {
    case Type::BASE:
        Base::loop();
        break;
    case Type::SENSOR:
        Base::loop();
        break;
    case Type::TEST_BLE:
        // BLETest::loop();
        break;
    case Type::TEST_WIFI:
        // TestWiFi::loop();
        break;
    case Type::TEST_ESPNOW:
        // TestESPNow::loop();
        break;
    case Type::TEST_SENSOR:
        // TestSensor::loop();
        break;
    }
}