#pragma once

// #include <Adafruit_BME680.h>
#include <BME68X.h>

#include "literals.h"

// #include <driver/adc.h>

namespace BME680
{
    struct Data
    {
        /// @brief Temperature in °C
        float temperature;
        /// @brief Relative humidity in %
        uint8_t humidity;
        /// @brief Pressure in Pascals
        uint32_t pressure;
        /// @brief Gas resistance in Ohms
        uint32_t gas;
        bool hasData;
    };

    Data read()
    {
        // timing: cold start, repetetive
        BME68X bme680; // 7781ms, 7702ms
        // Adafruit_BME680 bme680; // 8780ms, 8702ms
        if (!bme680.begin(0x76))
        {
            return {0, 0, 0, 0, false};
        }
        bme680.setTOffset(-2.0f);
        bme680.setConfig(
            BME68X::Oversampling::X2, BME68X::Oversampling::X8, BME68X::Oversampling::X4, BME68X::FilterSize::SIZE_3);
        // bme680.setTemperatureOversampling(BME680_OS_8X);
        // bme680.setHumidityOversampling(BME680_OS_2X);
        // bme680.setPressureOversampling(BME680_OS_4X);
        // bme680.setIIRFilterSize(BME680_FILTER_SIZE_3);
        // bme680.setGasHeater(320, 150);

        while (!bme680.performReading()) { }

        return {bme680.temperature, (uint8_t)bme680.humidity, bme680.pressure, bme680.gasResistance, true};
        // return {bme680.temperature, bme680.humidity, bme680.pressure, bme680.gas_resistance, true};
    }
} // namespace BME680

// const uint32_t readADC(const adc1_channel_t channel)
// {
//     // adc1_config_width(ADC_WIDTH_12Bit);
//     // adc1_config_channel_atten(ADC_PIN, ADC_ATTEN_0db);
//     uint32_t sum = 0;
//     for (uint8_t i = 0; i < 100; ++i)
//     {
//         sum += adc1_get_raw(channel);
//     }
//     return sum / 100;
// }

/// @brief Read the given analog gpio
/// @param gpio Analog gpio number
/// @return Average raw adc value
const long double readADC(const uint8_t gpio)
{
    uint32_t sum = 0;
    for (uint8_t i = 0; i < 100; ++i)
    {
        sum += analogRead(gpio);
    }
    const long double result = sum / 100.0;
    return result;
}

namespace Battery
{
    /// @brief Pin the battery voltage divider is connected to
    constexpr static const uint8_t PIN = 35;
    // constexpr static const adc1_channel_t PIN = ADC1_CHANNEL_7;

    /// @brief Read and calculate battery voltage
    /// @return Battery voltage
    Voltage getVoltage()
    {
        pinMode(PIN, INPUT);
        analogReadResolution(12);
        // Vout = Vin * R2 / (R1 + R2)
        // Vin = Vout * (R1 + R2) / R2
        constexpr auto R1 = 1.0_MOhm;
        constexpr auto R2 = 1.0_MOhm;
        // If voltage is read too low increase it here
        // constexpr auto factor = (R1 + R2) / R2 * 3.3_V / 4096.0;
        constexpr auto factor = (R1 + R2) / R2 * 3.5_V / 4096.0;
        return readADC(PIN) * factor;
    }

    constexpr Voltage divider(Resistance r1, Resistance r2, Voltage vout) { return (r1 + r2) / r2 * vout; }
    constexpr auto v1 = divider(1.0_MOhm, 1.0_MOhm, 0.0_V);
    constexpr auto v2 = divider(1.0_MOhm, 1.0_MOhm, 2.1_V);
    constexpr auto bla = (4.2_V / 2.0_MOhm).uA();

    /// @brief Calculate battery runtime
    /// @param batteryCapacity Battery capacity e.g. 1.0_Ah
    /// @param cycleEnergy Energy used per cycle (wake + sleep) e.g. 100.0_mAs
    /// @param cycleTime The time one cycle takes in ms (sleep + wake)
    /// @return The runtime in seconds
    constexpr long double calcRuntime(
        const Charge batteryCapacity, const Charge cycleEnergy, const long double cycleTime)
    {
        // Same as (batteryCapacity / cycleEnergy) / (1000.0 / cycleTime)
        return (batteryCapacity * cycleTime) / (cycleEnergy * 1000.0);
    }
    constexpr auto dur2 = calcRuntime(1.0_Ah, 470.0_mAs, 215000.0) / (60.0 * 60.0);

    /// @brief Convert a given battery voltage to a state of charge in %
    /// @param voltage Battery voltage
    /// @return SOC in %
    constexpr uint8_t voltageToSOC(const Voltage voltage)
    {
        // f(x)=d+((a-d)/(1+(x/c)^b))
        return 100 + ((0 - 100) / (1 + std::pow(voltage.volt / 3.85070895651188, 38.8302821020661)));
    }
} // namespace Battery

namespace LDR
{
    /// @brief Pin the light sensor voltage divider is connected to
    constexpr static const uint8_t PIN = 34;
    // constexpr static const adc1_channel_t PIN = ADC1_CHANNEL_6;

    constexpr auto relativeLightCurrent100lx = calcYBetweenAtX(Point2D {3.0, 1.0}, Point2D {3.5, 1.015}, 3.3);
    /// @brief Calculate relative light current temperature offset
    /// @param t Temperature in °C
    /// @return Relative current offset
    constexpr const long double tempOffset(const long double t)
    {
        return 1e-7 * t * t * t - 4e-5 * t * t + 0.0071 * t + 0.7373;
    }

    /// @brief Convert the given current to Illuminance based on an LED light source
    /// @param current
    /// @return
    Illuminance currentToLuxLED(const Current current)
    {
        const auto uA = current.uA();
        return {uA <= 15.0 ? 6.666666666666666963 * uA : 4.9451 * uA + 25.824};
    }
    // constexpr Illuminance currentToLuxLED(const Current current)
    // {
    //     return {current.uA() <= 15.0 ? 6.666666666666666963 * current.uA() : 4.9451 * current.uA() + 25.824};
    // }
    // constexpr auto ill = currentToLuxLED(290.0_uA);

    /// @brief Convert the given current to Illuminance based on an incandescent light source
    ///
    /// @param current
    /// @return constexpr Illuminance
    constexpr Illuminance currentToLuxIncandescent(const Current current) { return {1.9239 * current.uA()}; }
    /// @brief Convert the given current to Illuminance based on a fluorescent light source
    /// @param current
    /// @return
    constexpr Illuminance currentToLuxFluorescent(const Current current) { return {6.6728 * current.uA()}; }

    /// @brief Read and calculate LDR current
    /// @param vcc Sensor supply voltage
    /// @return LDR current
    Current getCurrent(const Voltage vcc)
    {
        // Vout = Iph * Rl <= Vsat = Vcc - 0.4V
        // Iph = Vout / Rl
        // Iph = Vout / 10000
        pinMode(PIN, INPUT);
        analogReadResolution(12);
        return readADC(PIN) * vcc / 4096.0 / 10.0_kOhm;
    }

    /// @brief Read LDR and calculate illuminance
    /// @param vcc Sensor supply voltage
    /// @return Sensor reading in Lux
    Illuminance getIlluminance(const Voltage vcc) { return currentToLuxLED(getCurrent(vcc)); }
}; // namespace LDR