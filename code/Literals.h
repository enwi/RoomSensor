#pragma once

#include <type_traits>

/// @brief Class representing a voltage measured in Volt
struct Voltage
{
    /// @brief Voltage
    long double volt;

    constexpr bool operator==(const Voltage& rhs) { return volt == rhs.volt; }

    constexpr Voltage operator+(const Voltage& rhs) const { return {volt + rhs.volt}; }

    constexpr Voltage operator-(const Voltage& rhs) const { return {volt - rhs.volt}; }

    template <typename T>
    constexpr Voltage operator*(const T& rhs) const
    {
        return {volt * rhs};
    }

    // template <typename T, typename std::enable_if<!std::is_same<Voltage, T>::value>::type>
    template <typename T>
    constexpr Voltage operator/(const T& rhs) const
    {
        return {volt / rhs};
    }

    /// @brief Dividing a voltage by a voltage results in a unitless value
    /// @param rhs
    /// @return
    constexpr long double operator/(const Voltage& rhs) const { return volt / rhs.volt; }
};
/// @brief Kilovolt literal
/// @param kilovolts Voltage in Kilovolt
/// @return Voltage in Volt
constexpr Voltage operator"" _kV(long double kilovolts)
{
    return {kilovolts * 1000.0};
}
/// @brief Volt literal
/// @param volts Voltage in Volt
/// @return Voltage in Volt
constexpr Voltage operator"" _V(long double volts)
{
    return {volts};
}
/// @brief Milivolt literal
/// @param millivolts Voltage in Millivolt
/// @return Voltage in Volt
constexpr Voltage operator"" _mV(long double millivolts)
{
    return {millivolts / 1000.0};
}

// static_assert(1000_mV == 1_V);
// static_assert(1000_V == 1_kV);

/// @brief Class representing a current measured in Ampere
struct Current
{
    /// @brief Current in Ampere
    long double ampere;

    constexpr bool operator==(const Current& rhs) { return ampere == rhs.ampere; }

    constexpr Current operator+(const Current& rhs) const { return {ampere + rhs.ampere}; }

    constexpr Current operator-(const Current& rhs) const { return {ampere - rhs.ampere}; }

    template <typename T>
    constexpr Current operator*(const T& rhs)
    {
        return {ampere * rhs};
    }

    template <typename T, typename std::enable_if<!std::is_same<Current, T>::value>::type>
    constexpr Current operator/(const T& rhs) const
    {
        return {ampere / rhs};
    }

    /// @brief Dividing a current by a current results in a unitless value
    /// @param rhs
    /// @return
    constexpr long double operator/(const Current& rhs) const { return ampere / rhs.ampere; }

    /// @brief Get current as milli ampere
    /// @return Current in mA
    constexpr long double mA() { return ampere * 1000.0; }
    /// @brief Get current as micro ampere
    /// @return Current in uA
    constexpr long double uA() { return ampere * 1000000.0; }
    /// @brief Get current as nano ampere
    /// @return Current in nA
    constexpr long double nA() { return ampere * 1000000000.0; }
};
/// @brief Ampere literal
/// @param ampere Current in Ampere
/// @return Current in Ampere
constexpr Current operator"" _A(const long double ampere)
{
    return {ampere};
}
/// @brief Milliampere literal
/// @param milliampere Current in Milliampere
/// @return Current in Ampere
constexpr Current operator"" _mA(const long double milliampere)
{
    return {milliampere / 1000.0};
}
/// @brief Microampere literal
/// @param microampere Current in Microampere
/// @return Current in Ampere
constexpr Current operator""_uA(const long double microampere)
{
    return {microampere / 1000000.0};
}

/// @brief Class representing a resistance measured in Ohm
struct Resistance
{
    /// @brief Resistance in Ohm
    const long double ohm;

    constexpr Resistance operator+(const Resistance& rhs) const { return {ohm + rhs.ohm}; }

    constexpr Resistance operator-(const Resistance& rhs) const { return {ohm - rhs.ohm}; }

    template <typename T>
    constexpr Resistance operator*(const T& rhs) const
    {
        return {ohm * rhs};
    }

    template <typename T, typename std::enable_if<!std::is_same<Resistance, T>::value>::type>
    constexpr Resistance operator/(const T& rhs) const
    {
        return {ohm / rhs};
    }

    /// @brief Dividing a resistance by a resistance results in a unitless value
    /// @param rhs
    /// @return
    constexpr long double operator/(const Resistance& rhs) const { return ohm / rhs.ohm; }
};
/// @brief Ohm literal
/// @param ohm Resistance in Ohm
/// @return Resistance in Ohm
constexpr Resistance operator"" _Ohm(long double ohm)
{
    return {ohm};
}
/// @brief Kiloohm literal
/// @param kiloOhm Resistance in Kiloohm
/// @return Resistance in Ohm
constexpr Resistance operator"" _kOhm(long double kiloOhm)
{
    return {kiloOhm * 1000.0};
}
/// @brief Megaohm literal
/// @param megaOhm Resistance in Megaohm
/// @return Resistance in Ohm
constexpr Resistance operator"" _MOhm(long double megaOhm)
{
    return {megaOhm * 1000000.0};
}

template <typename T>
constexpr Voltage operator*(const T& lhs, const Voltage& rhs)
{
    return {lhs * rhs.volt};
}
template <>
constexpr Voltage operator*(const Voltage& lhs, const Voltage& rhs)
{
    return {lhs.volt * rhs.volt};
}

template <typename T>
constexpr Resistance operator*(const T& lhs, const Resistance& rhs)
{
    return {lhs * rhs.ohm};
}
template <>
constexpr Resistance operator*(const Resistance& lhs, const Resistance& rhs)
{
    return {lhs.ohm * rhs.ohm};
}

/// @brief U = R * I
/// @param lhs
/// @param rhs
/// @return
constexpr Voltage operator*(const Resistance& lhs, const Current& rhs)
{
    return {lhs.ohm * rhs.ampere};
}
constexpr Voltage operator*(const Current& lhs, const Resistance& rhs)
{
    return {lhs.ampere * rhs.ohm};
}

/// @brief I = U / R
/// @param lhs
/// @param rhs
/// @return
constexpr Current operator/(const Voltage& lhs, const Resistance& rhs)
{
    return {lhs.volt / rhs.ohm};
}

/// @brief R = U / I
/// @param lhs
/// @param rhs
/// @return
constexpr Resistance operator/(const Voltage& lhs, const Current& rhs)
{
    return {lhs.volt * rhs.ampere};
}

struct Distance
{
    long double meter;
};

struct Area
{
    long double squareMeter;
};

struct Volume
{
    long double cubicMeter;
};

/// @brief Luminous flux in lumen
struct LuminousFlux
{
    /// @brief Lumen
    long double lm;
};

/// @brief Illuminance in Lux
struct Illuminance
{
    /// @brief Lux
    long double lx;
};

/// @brief Lux = LuminousFlux / Area
/// @param lhs
/// @param rhs
/// @return
constexpr Illuminance operator/(const LuminousFlux& lhs, const Area& rhs)
{
    return {lhs.lm / rhs.squareMeter};
}

/// @brief area = meter * meter
/// @param lhs
/// @param rhs
/// @return
constexpr Area operator*(const Distance& lhs, const Distance& rhs)
{
    return {lhs.meter * rhs.meter};
}

/// @brief Volumne = meter * meter * meter
/// @param lhs
/// @param rhs
/// @return
constexpr Volume operator*(const Area& lhs, const Distance& rhs)
{
    return {lhs.squareMeter * rhs.meter};
}

/// @brief Volumne = meter * meter * meter
/// @param lhs
/// @param rhs
/// @return
constexpr Volume operator*(const Distance& lhs, const Area& rhs)
{
    return {lhs.meter * rhs.squareMeter};
}

struct Point2D
{
    const long double x;
    const long double y;
};

constexpr const long double slope(const Point2D p1, const Point2D p2)
{
    // return slope(p2.x - p1.x, p2.y - p1.y);
    return (p2.y - p1.y) / (p2.x - p1.x);
}

constexpr const long double calcYBetweenAtX(const Point2D p1, const Point2D p2, const long double x)
{
    return p1.y + slope(p1, p2) * (x - p1.x);
}

/// @brief Represents an electrical charge in Coulomb aka Amperesecond
struct Charge
{
    /// @brief Charge in Coulomb
    long double coulomb;

    constexpr bool operator==(const Charge& rhs) { return coulomb == rhs.coulomb; }

    template <typename T>
    constexpr Charge operator*(const T& rhs) const
    {
        return {coulomb * rhs};
    }

    template <typename T, typename std::enable_if<!std::is_same<Charge, T>::value>::type>
    constexpr Charge operator/(const T& rhs) const
    {
        return {coulomb / rhs};
    }

    /// @brief Dividing a charge by a charge results in a unitless value
    /// @param rhs
    /// @return
    constexpr long double operator/(const Charge& rhs) const { return coulomb / rhs.coulomb; }

    /// @brief Comvert charge to Amperehours
    /// @return Amperehours
    constexpr long double Ah() { return coulomb / 3600.0; }
    /// @brief Convert charge to Watthours
    /// @param voltage Nominal voltage
    /// @return Watthours
    constexpr long double Wh(const Voltage voltage) { return Ah() * voltage.volt; }
};

/// @brief Coulomb literal
/// @param coulomb Charge in Coulomb
/// @return Charge in Coulomb
// constexpr Charge operator"" _C(long double coulomb)
// {
//     return {coulomb};
// }
/// @brief Ampseconds literal
/// @param ampseconds Charge in Ampseconds
/// @return Charge in Coulomb
constexpr Charge operator"" _As(long double ampseconds)
{
    return {ampseconds};
}
/// @brief Milliampseconds literal
/// @param ampseconds Charge in Milliampseconds
/// @return Charge in Coulomb
constexpr Charge operator"" _mAs(long double milliampseconds)
{
    return {milliampseconds / 1000.0};
}
/// @brief Amphours literal
/// @param amphours Charge in Amphours
/// @return Charge in Coulomb
constexpr Charge operator"" _Ah(long double amphours)
{
    return {amphours * 3600.0};
}
static_assert(1.0_Ah == 3600.0_As);
static_assert(1.0_As == 1000.0_mAs);

#include <chrono>

constexpr std::chrono::milliseconds operator/(const Charge& lhs, const Current& rhs)
{
    return std::chrono::milliseconds(static_cast<int64_t>(lhs.coulomb / rhs.ampere * 1000.0));
}

// constexpr auto time = std::chrono::duration_cast<std::chrono::hours>(1.0_Ah / 1.0_A);
// constexpr auto time = std::chrono::duration_cast<std::chrono::hours>(200.0_Ah / 6.66_A);

struct Power
{
    long double watt;

    constexpr bool operator==(const Power& rhs) { return watt == rhs.watt; }
};

/// @brief Watt literal
/// @param amphours Power in Watt
/// @return Power in Watt
constexpr Power operator"" _W(long double watt)
{
    return {watt};
}
/// @brief Kilowatt literal
/// @param amphours Power in Kilowatt
/// @return Power in Watt
constexpr Power operator"" _kW(long double kilowatt)
{
    return {kilowatt * 1000.0};
}
static_assert(1000.0_W == 1.0_kW);

/// @brief Power = Voltage * Current
/// @param lhs
/// @param rhs
/// @return
constexpr Power operator*(const Voltage& lhs, const Current& rhs)
{
    return {lhs.volt * rhs.ampere};
}
/// @brief Power = Current * Voltage
/// @param lhs
/// @param rhs
/// @return
constexpr Power operator*(const Current& lhs, const Voltage& rhs)
{
    return {lhs.ampere * rhs.volt};
}

/// @brief Current = Power / Voltage
/// @param lhs
/// @param rhs
/// @return
constexpr Current operator/(const Power& lhs, const Voltage& rhs)
{
    return {lhs.watt / rhs.volt};
}
static_assert(800.0_W / 240.0_V == 3.3333333333333333_A);

/// @brief Voltage = Power / Current
/// @param lhs
/// @param rhs
/// @return
constexpr Voltage operator/(const Power& lhs, const Current& rhs)
{
    return {lhs.watt / rhs.ampere};
}
static_assert(800.0_W / 3.3333333333333333_A == 240.0_V);