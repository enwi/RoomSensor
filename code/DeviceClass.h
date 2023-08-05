#pragma once

enum class SensorClass
{
    NONE,
    /// @brief Apparent power in VA
    APPARENT_POWER,
    /// @brief Air Quality Index (unitless).
    AQI,
    /// @brief Atmospheric pressure in cbar, bar, hPa, inHg, kPa, mbar, Pa or psi
    ATMOSPHERIC_PRESSURE,
    /// @brief Percentage of battery that is left in %
    BATTERY,
    /// @brief Carbon Dioxide in CO2 (Smoke) in ppm
    CARBON_DIOXIDE,
    /// @brief Carbon Monoxide in CO (Gas CNG/LPG) in ppm
    CARBON_MONOXIDE,
    /// @brief Current in A, mA
    CURRENT,
    /// @brief Data rate in bit/s, kbit/s, Mbit/s, Gbit/s, B/s, kB/s, MB/s, GB/s, KiB/s, MiB/s or GiB/s
    DATA_RATE,
    /// @brief Data size in bit, kbit, Mbit, Gbit, B, kB, MB, GB, TB, PB, EB, ZB, YB, KiB, MiB, GiB, TiB, PiB, EiB, ZiB
    /// or YiB
    DATA_SIZE,
    /// @brief Date string (ISO 8601)
    DATE,
    /// @brief Generic distance in km, m, cm, mm, mi, yd, or in
    DISTANCE,
    /// @brief Duration in d, h, min, or s
    DURATION,
    /// @brief Energy in Wh, kWh, MWh, MJ, or GJ
    ENERGY,
    /// @brief Stored energy in Wh, kWh, MWh, MJ, or GJ
    ENERGY_STORAGE,
    /// @brief Has a limited set of (non-numeric) states
    ENUM,
    /// @brief Frequency in Hz, kHz, MHz, or GHz
    FREQUENCY,
    /// @brief Gasvolume in m³, ft³ or CCF
    GAS,
    /// @brief Percentage of humidity in the air in %
    HUMIDITY,
    /// @brief The current light level in lx
    ILLUMINANCE,
    /// @brief Irradiance in W/m² or BTU/(h⋅ft²)
    IRRADIANCE,
    /// @brief Percentage of water in a substance in %
    MOISTURE,
    /// @brief The monetary value (ISO 4217)
    MONETARY,
    /// @brief Concentration of Nitrogen Dioxide in µg/m³
    NITROGEN_DIOXIDE,
    /// @brief Concentration of Nitrogen Monoxide in µg/m³
    NITROGEN_MONOXIDE,
    /// @brief Concentration of Nitrous Oxide in µg/m³
    NITROUS_OXIDE,
    /// @brief Concentration of Ozone in µg/m³
    OZONE,
    /// @brief Potential hydrogen (pH) value of a water solution
    PH,
    /// @brief Concentration of particulate matter less than 1 micrometer in µg/m³
    PM1,
    /// @brief  Concentration of particulate matter less than 2.5 micrometers in µg/m³
    PM25,
    /// @brief Concentration of particulate matter less than 10 micrometers in µg/m³
    PM10,
    /// @brief Power factor (unitless), unit may be None or %
    POWER_FACTOR,
    /// @brief Power in W or kW
    POWER,
    /// @brief Accumulated precipitation in cm, in or mm
    PRECIPITATION,
    /// @brief Precipitation intensity in in/d, in/h, mm/d or mm/h
    PRECIPITATION_INTENSITY,
    /// @brief Pressure in Pa, kPa, hPa, bar, cbar, mbar, mmHg, inHg or psi
    PRESSURE,
    /// @brief Reactive power in var
    REACTIVE_POWER,
    /// @brief Signal strength in dB or dBm
    SIGNAL_STRENGTH,
    /// @brief Sound pressure in dB or dBA
    SOUND_PRESSURE,
    /// @brief Generic speed in ft/s, in/d, in/h, km/h, kn, m/s, mph or mm/d
    SPEED,
    /// @brief Concentration of sulphur dioxide in µg/m³
    SULPHUR_DIOXIDE,
    /// @brief Temperature in °C, °F or K
    TEMPERATURE,
    /// @brief Datetime object or timestamp string (ISO 8601)
    TIMESTAMP,
    /// @brief Concentration of volatile organic compounds in µg/m³
    VOC,
    /// @brief Ratio of volatile organic compounds in ppm or ppb
    VOCP,
    /// @brief Voltage in V, mV
    VOLTAGE,
    /// @brief Generic volume in L, mL, gal, fl. oz., m³, ft³, or CCF
    VOLUME,
    /// @brief Generic stored volume in L, mL, gal, fl. oz., m³, ft³, or CCF
    VOLUME_STORAGE,
    /// @brief Water consumption in L, gal, m³, ft³, or CCF
    WATER,
    /// @brief Generic mass in kg, g, mg, µg, oz, lb, or st
    WEIGHT,
    /// @brief Wind speed in ft/s, km/h, kn, m/s, or mph
    WIND_SPEED,
};

template <SensorClass clazz>
constexpr const char* toStr()
{
    return "none";
};
template <>
constexpr const char* toStr<SensorClass::APPARENT_POWER>()
{
    return "apparent_power";
};
template <>
constexpr const char* toStr<SensorClass::AQI>()
{
    return "aqi";
};
template <>
constexpr const char* toStr<SensorClass::ATMOSPHERIC_PRESSURE>()
{
    return "atmospheric_pressure";
};
template <>
constexpr const char* toStr<SensorClass::BATTERY>()
{
    return "battery";
};
template <>
constexpr const char* toStr<SensorClass::CARBON_DIOXIDE>()
{
    return "carbon_dioxide";
};
template <>
constexpr const char* toStr<SensorClass::CARBON_MONOXIDE>()
{
    return "carbon_monoxide";
};
template <>
constexpr const char* toStr<SensorClass::CURRENT>()
{
    return "current";
};
template <>
constexpr const char* toStr<SensorClass::DATA_RATE>()
{
    return "data_rate";
};
template <>
constexpr const char* toStr<SensorClass::DATA_SIZE>()
{
    return "data_size";
};
template <>
constexpr const char* toStr<SensorClass::DATE>()
{
    return "date";
};
template <>
constexpr const char* toStr<SensorClass::DISTANCE>()
{
    return "distance";
};
template <>
constexpr const char* toStr<SensorClass::DURATION>()
{
    return "duration";
};
template <>
constexpr const char* toStr<SensorClass::ENERGY>()
{
    return "energy";
};
template <>
constexpr const char* toStr<SensorClass::ENERGY_STORAGE>()
{
    return "energy_storage";
};
template <>
constexpr const char* toStr<SensorClass::ENUM>()
{
    return "enum";
};
template <>
constexpr const char* toStr<SensorClass::FREQUENCY>()
{
    return "frequency";
};
template <>
constexpr const char* toStr<SensorClass::GAS>()
{
    return "gas";
};
template <>
constexpr const char* toStr<SensorClass::HUMIDITY>()
{
    return "humidity";
};
template <>
constexpr const char* toStr<SensorClass::ILLUMINANCE>()
{
    return "illuminance";
};
template <>
constexpr const char* toStr<SensorClass::IRRADIANCE>()
{
    return "irradiance";
};
template <>
constexpr const char* toStr<SensorClass::MOISTURE>()
{
    return "moisture";
};
template <>
constexpr const char* toStr<SensorClass::MONETARY>()
{
    return "monetary";
};
template <>
constexpr const char* toStr<SensorClass::NITROGEN_DIOXIDE>()
{
    return "nitrogen_dioxide";
};
template <>
constexpr const char* toStr<SensorClass::NITROGEN_MONOXIDE>()
{
    return "nitrogen_monoxide";
};
template <>
constexpr const char* toStr<SensorClass::NITROUS_OXIDE>()
{
    return "nitrous_oxide";
};
template <>
constexpr const char* toStr<SensorClass::OZONE>()
{
    return "ozone";
};
template <>
constexpr const char* toStr<SensorClass::PH>()
{
    return "ph";
};
template <>
constexpr const char* toStr<SensorClass::PM1>()
{
    return "pm1";
};
template <>
constexpr const char* toStr<SensorClass::PM25>()
{
    return "pm25";
};
template <>
constexpr const char* toStr<SensorClass::PM10>()
{
    return "pm10";
};
template <>
constexpr const char* toStr<SensorClass::POWER_FACTOR>()
{
    return "power_factor";
};
template <>
constexpr const char* toStr<SensorClass::POWER>()
{
    return "power";
};
template <>
constexpr const char* toStr<SensorClass::PRECIPITATION>()
{
    return "precipitation";
};
template <>
constexpr const char* toStr<SensorClass::PRECIPITATION_INTENSITY>()
{
    return "precipitation_intensity";
};
template <>
constexpr const char* toStr<SensorClass::PRESSURE>()
{
    return "pressure";
};
template <>
constexpr const char* toStr<SensorClass::REACTIVE_POWER>()
{
    return "reactive_power";
};
template <>
constexpr const char* toStr<SensorClass::SIGNAL_STRENGTH>()
{
    return "signal_strength";
};
template <>
constexpr const char* toStr<SensorClass::SOUND_PRESSURE>()
{
    return "sound_pressure";
};
template <>
constexpr const char* toStr<SensorClass::SPEED>()
{
    return "speed";
};
template <>
constexpr const char* toStr<SensorClass::SULPHUR_DIOXIDE>()
{
    return "sulphur_dioxide";
};
template <>
constexpr const char* toStr<SensorClass::TEMPERATURE>()
{
    return "temperature";
};
template <>
constexpr const char* toStr<SensorClass::TIMESTAMP>()
{
    return "timestamp";
};
template <>
constexpr const char* toStr<SensorClass::VOC>()
{
    return "volatile_organic_compounds";
};
template <>
constexpr const char* toStr<SensorClass::VOCP>()
{
    return "volatile_organic_compounds_parts";
};
template <>
constexpr const char* toStr<SensorClass::VOLTAGE>()
{
    return "voltage";
};
template <>
constexpr const char* toStr<SensorClass::VOLUME>()
{
    return "volume";
};
template <>
constexpr const char* toStr<SensorClass::VOLUME_STORAGE>()
{
    return "volume_storage";
};
template <>
constexpr const char* toStr<SensorClass::WATER>()
{
    return "water";
};
template <>
constexpr const char* toStr<SensorClass::WEIGHT>()
{
    return "weight";
};
template <>
constexpr const char* toStr<SensorClass::WIND_SPEED>()
{
    return "wind_speed";
};
