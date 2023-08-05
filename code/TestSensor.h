#pragma once

// #define USE_ADAFRUIT

#ifdef USE_ADAFRUIT
#include <Adafruit_BME680.h>
#else
#include <BME68X.h>
#endif
#include <chrono>

#include <Adafruit_SHT31.h>
#include <SCD41.h>

#include "StopWatch.h"
#include "sleep.h"

namespace TestSensor
{
    inline void testBME68X()
    {
#ifdef USE_ADAFRUIT
        Adafruit_BME680 bme680;
#else
        Wire.begin();
        delay(100);
        BME68X bme680;
#endif
        if (!bme680.begin(0x76))
        {
            Serial.println("[BME68X] Could not find device");
            return;
        }
#ifdef USE_ADAFRUIT
        bme680.setTemperatureOversampling(BME680_OS_8X);
        bme680.setHumidityOversampling(BME680_OS_2X);
        bme680.setPressureOversampling(BME680_OS_4X);
        bme680.setIIRFilterSize(BME680_FILTER_SIZE_3);
        // bme680.setGasHeater(320, 150);
#else
        bme680.setTOffset(-2.0f);
        bme680.setConfig(
            BME68X::Oversampling::X2, BME68X::Oversampling::X8, BME68X::Oversampling::X4, BME68X::FilterSize::SIZE_3);
#endif

        while (!bme680.performReading()) { }

        Serial.printf("[BME68X] t: %2.2f, h: %3.0f, p: %d\n", bme680.temperature, bme680.humidity, bme680.pressure);
    }

    inline void testSHT31()
    {
        Adafruit_SHT31 sht31;
        if (!sht31.begin(0x44))
        {
            Serial.println("[SHT31] Could not find device");
            return;
        }
        float temperature;
        float humidity;
        sht31.readBoth(&temperature, &humidity);

        Serial.printf("[SHT31] t: %2.2f, h: %3.0f\n", temperature, humidity);
    }

    inline void testSCD40()
    {
        SCD41 scd4x;
        if (scd4x.init() != SCD41_SUCCESS)
        {
            Serial.println("[SCD40] Could not find device");
            return;
        }
        scd4x.start(SCD41_MODE_SINGLE_SHOT);
        scd4x.getSampleAsync(true);
        while (!scd4x.getSampleAsync()) { };

        Serial.printf("[SCD40] t: %2.2f, h: %3d, c: %d\n", scd4x.temperature(), scd4x.humidity(), scd4x.co2());
    }

    inline void setup()
    {
        Serial.begin(115200);
        StopWatch watch;
        watch.start();
        // testBME68X();
        // testSHT31();
        testSCD40();
        RS_DEBUGF("Took %dms\n", std::chrono::duration_cast<std::chrono::milliseconds>(watch.stop()));
        sleep(std::chrono::seconds(10));
    }
    inline void loop() { }
} // namespace TestSensor
