#include "Base.h"
#include "Sensor.h"

#ifdef TEST_BLE
#include "TestBLE.h"
#endif
#ifdef TEST_ESPNOW
#include "TestESPNow.h"
#endif
#ifdef TEST_SENSOR
#include "TestSensor.h"
#endif
#ifdef TEST_WIFI
#include "TestWiFi.h"
#endif

enum class Type
{
    BASE,
    SENSOR,
    TEST_BLE,
    TEST_WIFI,
    TEST_ESPNOW,
    TEST_SENSOR,
};

void setup()
{
    switch (Type::TYPE)
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
    switch (Type::TYPE)
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