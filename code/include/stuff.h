#pragma once

#include <cmath>

/// @brief Calculate absolute humidity in g/m^3
/// @param t Temperatuere in °C
/// @param rh Relative humidity in %
/// @return Absolute humidity in g/m^3 (~[0,30])
constexpr float calcAbsoluteHumidity(const float t, const float rh)
{
    return (6.112f * std::exp((17.67f * t) / (t + 243.5f)) * rh * 2.1674f) / (273.15f + t);
}

/// @brief Calculate dew point
/// @param t Temperatuere in °C
/// @param rh Relative humidity in %
/// @return Dew point in °C
constexpr float calcDewPoint(const float t, const float rh)
{
    return 243.04f * (std::log(rh / 100.0f) + ((17.625f * t) / (243.04f + t)))
        / (17.625 - std::log(rh / 100.0f) - ((17.625f * t) / (243.04f + t)));
}

constexpr float calcHeatIndex(const float t, const float rh)
{
    return -42.379f + (2.04901523f * t) + (10.1433127f * rh) - (0.22475541f * t * rh)
        - (6.83783 * std::pow(10, -3) * t * t) - (5.481717 * std::pow(10, -2) * rh * rh)
        + (1.22874 * std::pow(10, -3) * t * t * rh) + (8.5282 * std::pow(10, -4) * t * rh * rh)
        - (1.99 * std::pow(10, -6) * t * t * rh * rh);
}

constexpr uint8_t pointsToPixels(const float pt)
{
    return pt / 0.75f;
}

constexpr float pixelsToPoints(const uint8_t px)
{
    return 0.75f * px;
}

// Taken from https://gmd.copernicus.org/articles/13/3055/2020/gmd-13-3055-2020.pdf
// Calculating human thermal comfort and thermal stress in the PALM model system 6.0
// PET (◦C) | Thermal perception | Grade of physical stress
// > 41     | Very hot           | Extreme heat stress
// 35 to 41 | Hot                | Strong heat stress
// 29 to 35 | Warm               | Moderate heat stress
// 23 to 29 | Slightly warm      | Slight heat stress
// 18 to 23 | Comfortable        | No thermal stress
// 13 to 18 | Slightly cool      | Slight cold stress
// 8 to 13  | Cool               | Moderate cold stress
// 4 to 8   | Cold               | Strong cold stress
// ≤ 4      | Very cold          | Extreme cold stress

enum class ThermalPerception
{
    VERY_COLD,
    COLD,
    COOL,
    SLIGHTLY_COOL,
    COMFORTABLE,
    SLIGHTLY_WARM,
    WARM,
    HOT,
    VERY_HOT,
};

/// @brief Get thermal perception
/// @param t Temperature in °C
/// @return ThermalPerception
ThermalPerception getThermalPerception(const float t)
{
    if (t > 41.0f)
    {
        return ThermalPerception::VERY_HOT;
    }
    else if (t > 35.0f)
    {
        return ThermalPerception::HOT;
    }
    else if (t > 29.0f)
    {
        return ThermalPerception::WARM;
    }
    else if (t > 23.0f)
    {
        return ThermalPerception::SLIGHTLY_WARM;
    }
    else if (t > 18.0f)
    {
        return ThermalPerception::COMFORTABLE;
    }
    else if (t > 13.0f)
    {
        return ThermalPerception::SLIGHTLY_COOL;
    }
    else if (t > 8.0f)
    {
        return ThermalPerception::COOL;
    }
    else if (t > 4.0f)
    {
        return ThermalPerception::COLD;
    }
    return ThermalPerception::VERY_COLD;
}

const char* thermalPerceptionToString(const ThermalPerception tp)
{
    switch (tp)
    {
    case ThermalPerception::VERY_HOT:
        return "Very hot";
    case ThermalPerception::HOT:
        return "Hot";
    case ThermalPerception::WARM:
        return "Warm";
    case ThermalPerception::SLIGHTLY_WARM:
        return "Slightly warm";
    case ThermalPerception::COMFORTABLE:
        return "Comfortable";
    case ThermalPerception::SLIGHTLY_COOL:
        return "Slightly cool";
    case ThermalPerception::COOL:
        return "Cool";
    case ThermalPerception::COLD:
        return "Cold";
    case ThermalPerception::VERY_COLD:
        return "Very cold";
    default:
        return "Unknown";
    }
}

// template <typename T>
// constexpr T round2(const T value)
// {
//     return static_cast<T>(static_cast<int32_t>(value * 100.0 + 0.5)) / 100.0;
// }

// template <uint8_t decimals, typename T>
// constexpr T round(const T value)
// {
//     return static_cast<T>(static_cast<int32_t>(value * pow(10, decimals + 1) + 0.5)) / pow(10, decimals + 1);
// }