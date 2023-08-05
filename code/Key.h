#pragma once

#include "DeviceClass.h"
#include "Unit.h"
#include "mqtt.h"

// template <SensorClass clazz, Unit... units>
// class SensorClassTest
// {
// public:
//     constexpr SensorClassTest() { }

//     static constexpr std::array<Unit, sizeof...(units)> value = {{units...}};
// };

// constexpr static const auto test = SensorClassTest<SensorClass::POWER, Unit::POWER_WATT, Unit::POWER_KILO_WATT>();

// template <SensorClass clazz, std::enable_if>
// void make_test()
// { }

// namespace HA
// {
//     class Sensor
//     {
//     public:
//         constexpr Sensor(const SensorClass clazz, const char* classStr, const Unit unit, const char* unitStr)
//             : m_class(clazz), m_classStr(classStr), m_unit(unit), m_unitStr(unitStr)
//         { }

//         constexpr SensorClass getClass() { return m_class; }
//         constexpr const char* getClassStr() { return m_classStr; }
//         constexpr Unit getUnit() { return m_unit; }
//         constexpr const char* getUnitStr() { return m_unitStr; }

//     private:
//         SensorClass m_class;
//         const char* m_classStr;
//         Unit m_unit;
//         const char* m_unitStr;
//     };

//     template <SensorClass clazz, Unit unit>
//     constexpr Sensor make_device()
//     {
//         return Sensor(clazz, toStr<clazz>(), unit, toStr<unit>());
//     }

//     constexpr static const Sensor VoltAmpere = make_device<SensorClass::APPARENT_POWER,
//     Unit::ELECTRICAL_VOLT_AMPERE>();

//     // constexpr static const Sensor VoltAmpere = make_device<DeviceClass::AQI, Unit::none>();

//     constexpr static const Sensor Watt = make_device<SensorClass::POWER, Unit::POWER_WATT>();
//     constexpr static const Sensor KiloWatt = make_device<SensorClass::POWER, Unit::POWER_KILO_WATT>();

//     constexpr static const Sensor Voltage = make_device<SensorClass::VOLTAGE, Unit::VOLT>();

//     constexpr static const Sensor WattHour = make_device<SensorClass::ENERGY, Unit::ENERGY_WATT_HOUR>();
//     constexpr static const Sensor KiloWattHour = make_device<SensorClass::ENERGY, Unit::ENERGY_KILO_WATT_HOUR>();

//     // constexpr static const Sensor Current = make_device<SensorClass::CURRENT, Unit::ELECTRICAL_CURRENT_AMPERE>();

//     // constexpr static const Sensor VoltAmpere = make_device<SensorClass::de, Unit::ELECTRICAL_VOLT_AMPERE>();
// } // namespace HA

class DataKey
{
public:
    constexpr DataKey(const char* clazz, const char* unit, const char* key, const char* name, const char* valueTemplate)
        : m_class(clazz), m_unit(unit), m_key(key), m_name(name), m_valueTemplate(valueTemplate)
    { }

    constexpr const char* getClass() const { return m_class; }
    constexpr const char* getUnit() const { return m_unit; }
    constexpr const char* getKey() const { return m_key; }
    constexpr const char* getValueTemplate() const { return m_valueTemplate; }

    void publishDiscovery(PubSubClient& mqtt, const String& mac) const
    {
        publishSensorDiscovery(mqtt, mac, m_name, m_key, getClass(), getUnit(), "measurement", m_valueTemplate);
    }

private:
    const char* m_class;
    const char* m_unit;
    const char* m_key;
    const char* m_name;
    const char* m_valueTemplate;
};

// namespace Sensor
// {
//     typedef DataKey<SensorClass::BATTERY, Unit::PERCENTAGE> BatteryPercentage;

//     typedef DataKey<SensorClass::HUMIDITY, Unit::PERCENTAGE> Humidity;

//     typedef DataKey<SensorClass::PRESSURE, Unit::PRESSURE_PA> PressurePa;

//     typedef DataKey<SensorClass::TEMPERATURE, Unit::TEMPERATURE_CELSIUS> TemperatureCelsius;

//     typedef DataKey<SensorClass::ILLUMINANCE, Unit::LIGHT_LUX> Illuminance;

// } // namespace Sensor

template <SensorClass clazz, Unit unit>
constexpr DataKey make_datakey(const char* key, const char* name, const char* valueTemplate)
{
    return DataKey(toStr<clazz>(), toStr<unit>(), key, name, valueTemplate);
}

/// @brief Different json keys and HA templates
namespace Key
{
    /// @brief Key for State Of Charge in %
    constexpr static const auto SOC
        = make_datakey<SensorClass::BATTERY, Unit::PERCENTAGE>("soc", "SOC", "{{value_json.soc}}");
    /// @brief Key for temperature measurement in °C
    constexpr static const auto TEMPERATURE
        = make_datakey<SensorClass::TEMPERATURE, Unit::CELSIUS>("tem", "Temperature", "{{value_json.tem|round(1)}}");
    /// @brief Key for relative humidity measurement in %
    constexpr static const auto HUMIDITY
        = make_datakey<SensorClass::HUMIDITY, Unit::PERCENTAGE>("hum", "Humidity", "{{value_json.hum}}");
    /// @brief Key for pressure measurement in pascals
    constexpr static const auto PRESSURE
        = make_datakey<SensorClass::PRESSURE, Unit::PA>("pre", "Air Pressure", "{{value_json.pre}}");
    /// @brief Key for illuminance measurement in lux
    constexpr static const auto ILLUMINANCE
        = make_datakey<SensorClass::ILLUMINANCE, Unit::LUX>("ill", "Illuminance", "{{value_json.ill}}");

    constexpr static const std::array<DataKey, 5> KEYS = {SOC, TEMPERATURE, HUMIDITY, PRESSURE, ILLUMINANCE};

} // namespace Key
