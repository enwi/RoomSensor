#pragma once

#include "DeviceClass.h"
#include "Unit.h"
#include "mqtt.h"

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
        StaticJsonDocument<600> autoConfig;
        addDeviceInfo(autoConfig, mac);

        autoConfig[HA::Property::DeviceClass] = m_class;
        autoConfig[HA::Property::Name] = mac + " " + m_name;
        autoConfig[HA::Property::StateClass] = "measurement";
        autoConfig[HA::Property::UniqueId] = mac + "_" + m_key;
        autoConfig[HA::Property::UnitOfMeasurement] = m_unit;
        autoConfig[HA::Property::ValueTemplate] = m_valueTemplate;

        autoConfig[HA::Topic::Base] = "EPDBase/" + mac;
        autoConfig[HA::Topic::State] = "~/state";

        const String topic = "homeassistant/sensor/" + mac + "/" + m_key + "/config";
        publishJSON(mqtt, topic, autoConfig, true);
    }

private:
    void addDeviceInfo(JsonDocument& json, const String& deviceID) const
    {
        auto dev = json[HA::Property::Device];
        dev[HA::Property::DeviceManufacturer] = "wirmo";
        dev[HA::Property::Name] = deviceID;
        dev[HA::Property::DeviceSoftwareVersion] = SOFTWARE_VERSION;
        dev[HA::Property::DeviceConfigUrl] = String("http://") + WiFi.localIP().toString();

        dev.createNestedArray(HA::Property::DeviceIdentifiers).add(deviceID);
    }

private:
    const char* m_class;
    const char* m_unit;
    const char* m_key;
    const char* m_name;
    const char* m_valueTemplate;
};

template <SensorClass clazz, Unit unit>
constexpr DataKey make_datakey(const char* key, const char* name, const char* valueTemplate)
{
    return DataKey(toStr<clazz>(), toStr<unit>(), key, name, valueTemplate);
}

/// @brief Different json keys and HA templates
namespace Key
{
    /// @brief Key for State Of Charge in %
    constexpr static const auto BATTERY_SOC
        = make_datakey<SensorClass::BATTERY, Unit::PERCENTAGE>("soc", "SOC", "{{value_json.soc}}");
    /// @brief Key for battery voltage measurement in volt
    constexpr static const auto BATTERY_VOLTAGE
        = make_datakey<SensorClass::VOLTAGE, Unit::VOLT>("bvo", "Battery Voltage", "{{value_json.bvo}}");
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

    constexpr static const std::array<DataKey, 6> KEYS
        = {BATTERY_SOC, BATTERY_VOLTAGE, TEMPERATURE, HUMIDITY, PRESSURE, ILLUMINANCE};

} // namespace Key
