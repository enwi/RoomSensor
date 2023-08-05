#pragma once

#include "Roboto_16.h"
#include "Roboto_24.h"
#include "Roboto_30.h"
#include "Roboto_35.h"
#include "Roboto_40.h"
#include "Roboto_45.h"
#include "Roboto_50.h"
#include "Roboto_70.h"
#include "Roboto_71.h"

class ONE_BIT_DISPLAY;

namespace Roboto
{
    /// @brief Calc baseline of font with given pixel height
    /// @param pixel Font height in pixels
    /// @return Baseline
    constexpr uint8_t baseline(const uint8_t pixel) { return pixel - pixel / 3.465; }
    static_assert(baseline(45) == 32);
    // static_assert(baseline(70) == 50);
    // static_assert(baseline(71) == 51);

    /// @brief Set the current font to a Roboto font of the given size
    /// @tparam size Font size in pixels
    /// @param epd Display to set font for
    /// @return Baseline position in pixels
    template <uint8_t size>
    inline uint8_t setFont(ONE_BIT_DISPLAY& epd)
    {
        switch (size)
        {
        case 16:
            epd.setFreeFont(&Roboto_16);
            break;
        case 24:
            epd.setFreeFont(&Roboto_24);
            break;
        case 30:
            epd.setFreeFont(&Roboto_30);
            break;
        case 35:
            epd.setFreeFont(&Roboto_35);
            // constexpr auto bl = baseline(35);
            return 25;
        case 40:
            epd.setFreeFont(&Roboto_40);
            break;
        case 45:
            epd.setFreeFont(&Roboto_45);
            break;
        case 50:
            epd.setFreeFont(&Roboto_50);
            break;
        case 70:
            epd.setFreeFont(&Roboto_70);
            return 50;
        case 71:
            epd.setFreeFont(&Roboto_71);
            return 51;

        default:
            break;
        }
        return baseline(size);
    }
} // namespace Roboto
