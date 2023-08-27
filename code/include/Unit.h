#pragma once

enum class Unit
{
    //  Power units
    WATT,
    KILO_WATT,

    //  Voltage units
    VOLT,

    //  Energy units
    WATT_HOUR,
    KILO_WATT_HOUR,

    //  Electrical units
    AMPERE,
    VOLT_AMPERE,

    // Degree units
    DEGREES,

    // Currency units
    EURO,
    DOLLAR,
    CENT,

    // Temperature units
    CELSIUS,
    FAHRENHEIT,
    KELVIN,

    // Time units
    MICROSECONDS,
    MILLISECONDS,
    SECONDS,
    MINUTES,
    HOURS,
    DAYS,
    WEEKS,
    MONTHS,
    YEARS,

    // Length units
    MILLIMETERS,
    CENTIMETERS,
    METERS,
    KILOMETERS,

    INCHES,
    FEET,
    YARD,
    MILES,

    // Frequency units
    HERTZ,
    GIGAHERTZ,

    // Pressure units
    PA,
    HPA,
    BAR,
    MILLI_BAR,
    INHG,
    PSI,

    // Volume units
    LITERS,
    MILLILITERS,
    CUBIC_METERS,
    CUBIC_FEET,
    GALLONS,
    FLUID_OUNCE,

    // Volume Flow Rate units
    CUBIC_METERS_PER_HOUR,

    CUBIC_FEET_PER_MINUTE,

    // Area units
    SQUARE_METERS,

    // Mass units
    GRAMS,
    KILOGRAMS,
    MILLIGRAMS,
    MICROGRAMS,

    OUNCES,
    POUNDS,

    // Conductivity units
    CONDUCTIVITY,

    // Light units
    LUX,

    // UV Index units
    UV_INDEX,

    // Percentage units
    PERCENTAGE,

    // Irradiation units
    WATTS_PER_SQUARE_METER,

    // Precipitation units
    MILLIMETERS_PER_HOUR,

    // Concentration units
    MICROGRAMS_PER_CUBIC_METER,
    MILLIGRAMS_PER_CUBIC_METER,

    PARTS_PER_CUBIC_METER,
    PARTS_PER_MILLION,
    PARTS_PER_BILLION,

    // Speed units
    MILLIMETERS_PER_DAY,
    INCHES_PER_DAY,
    METERS_PER_SECOND,
    INCHES_PER_HOUR,
    KILOMETERS_PER_HOUR,
    MILES_PER_HOUR,

    // Signal_strength units
    DECIBELS,
    DECIBELS_MILLIWATT,

    // Data units
    BITS,
    KILOBITS,
    MEGABITS,
    GIGABITS,
    BYTES,
    KILOBYTES,
    MEGABYTES,
    GIGABYTES,
    TERABYTES,
    PETABYTES,
    EXABYTES,
    ZETTABYTES,
    YOTTABYTES,
    KIBIBYTES,
    MEBIBYTES,
    GIBIBYTES,
    TEBIBYTES,
    PEBIBYTES,
    EXBIBYTES,
    ZEBIBYTES,
    YOBIBYTES,
    BITS_PER_SECOND,
    KILOBITS_PER_SECOND,
    MEGABITS_PER_SECOND,
    GIGABITS_PER_SECOND,
    BYTES_PER_SECOND,
    KILOBYTES_PER_SECOND,
    MEGABYTES_PER_SECOND,
    GIGABYTES_PER_SECOND,
    KIBIBYTES_PER_SECOND,
    MEBIBYTES_PER_SECOND,
    GIBIBYTES_PER_SECOND,
};

template <Unit unit>
constexpr const char* toStr()
{
    return "none";
};
template <>
constexpr const char* toStr<Unit::CELSIUS>()
{
    return "°C";
};
template <>
constexpr const char* toStr<Unit::LUX>()
{
    return "lx";
};
template <>
constexpr const char* toStr<Unit::PERCENTAGE>()
{
    return "%";
};
template <>
constexpr const char* toStr<Unit::PA>()
{
    return "Pa";
};
template <>
constexpr const char* toStr<Unit::VOLT>()
{
    return "V";
};