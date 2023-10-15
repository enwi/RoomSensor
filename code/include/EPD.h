#pragma once

#include <OneBitDisplay.h>

#include "Debug.h"
#include "Literals.h"
#include "icons.h"
#include "stuff.h"

#include "font/Roboto.h"

struct DisplayData
{
    /// @brief Pressure in pascals
    uint32_t pressure;
    /// @brief Gas resistance in Ohms
    uint32_t gas;
    /// @brief Temperature in °C
    float temperature;
    /// @brief Relative humidity in %
    uint8_t humidity;
    /// @brief State of charge in %
    uint8_t soc;
    /// @brief Illuminance
    Illuminance illuminance;
    /// @brief Thermal perception
    ThermalPerception perception;
};

template <typename T>
constexpr T clamp(const T min, const T max, const T value)
{
    return std::max(min, std::min(value, max));
}

namespace EPD
{
    constexpr static const uint8_t epdh = 128;
    constexpr static const uint16_t epdw = 296;
    constexpr long double height(const uint8_t lower)
    {
        return (epdh - lower) / 2.0;
    }
    constexpr auto third = height(16);

    constexpr static const uint8_t largeThirdHeight = 56; /// 56 pixel large third
    constexpr static const uint8_t smallThirdHeight = 16; /// 16 pixel small third

    constexpr static const uint8_t lowerThirdPosition = largeThirdHeight * 2;

    /// @brief 12Mhz is fast enough
    constexpr static const int32_t FREQ = 12000000;
    constexpr static const uint8_t CS = 5;
    constexpr static const uint8_t BUSY = 4;
    constexpr static const uint8_t RST = 16;
    constexpr static const uint8_t DC = 17;
    constexpr static const uint8_t SCK = 18;
    constexpr static const uint8_t MOSI = 23;

    constexpr const uint8_t calcPitch(const uint8_t size)
    {
        return std::ceil(size / 8.0);
    }
    static_assert(calcPitch(50) == 7);

    void init(ONE_BIT_DISPLAY& epd)
    {
        // Initialize the library by telling it how the display is connected
        epd.setSPIPins(CS, -1, -1, DC, RST, BUSY);
        // epd.setBitBang(false);
        // 2.9" = EPD29R_128x296
        epd.SPIbegin(EPD29R_128x296, FREQ);
        // epd.sleep();

        // Set the orientation to draw in the direction we want
        epd.setRotation(270); // the panel is actually 128 wide by 296 tall, but oriented 90 right
        epd.allocBuffer(); // allocate a back buffer and keep it internal to the class
        epd.fillScreen(OBD_WHITE); // 0 for EPDs is white (for OneBitDisplay)
    }

    void drawBattery(ONE_BIT_DISPLAY& epd, const uint8_t soc)
    {
        epd.drawRect(0, epd.height() - 8, 18, 8, OBD_BLACK);
        epd.fillRect(18, epd.height() - 6, 2, 4, OBD_BLACK);

        const uint8_t clamped = clamp<uint8_t>(0, 100, soc);
        epd.fillRect(1, epd.height() - 7, 1 + clamped / 100.0 * 15.0, 6, clamped <= 30 ? OBD_RED : OBD_BLACK);
    }

    void drawTemperatureGauge(
        ONE_BIT_DISPLAY& epd, const ThermalPerception& perception, const uint8_t x = 0, const uint8_t y = 0)
    {
        constexpr uint8_t xOffset = 13;
        epd.drawSprite(&(epd_bitmap_temperature[0]), 50, 50, calcPitch(50), x - xOffset, y, 1);

        const uint32_t color
            = perception < ThermalPerception::SLIGHTLY_COOL || perception > ThermalPerception::SLIGHTLY_WARM
            ? OBD_RED
            : OBD_BLACK;

        epd.fillCircle(23 - xOffset + x, 40 + y, 4, color);
        constexpr uint8_t totalLength = 40 - 4 - 5; // 40 px center of circle - radius - top spacing
        const uint8_t length = ((uint8_t)perception / 8.0f) * (totalLength);
        const uint8_t startY = y + 5 + totalLength - length;
        epd.fillRect(22 - xOffset + x, startY, 3, length, color);

        // // center 10 | 39
        // epd.drawCircle(x + 10, y + 39, 10, OBD_BLACK);
        // epd.drawLine(x+);
    }

    void drawWindow(ONE_BIT_DISPLAY& epd, const uint8_t rh)
    {
        // https://blog.wellcare-global.com/blog/ideal-room-humidity-and-best-temperatures-for-sleeping
        if (rh < 40 || rh > 60)
        {
            constexpr uint8_t size = 50;
            constexpr uint8_t xOffset = 3;
            epd.drawSprite(&(epd_bitmap_window_open[0]), size, size, calcPitch(size), epd.width() - 1 - size + xOffset,
                largeThirdHeight * 2 - 1 - size, 1);
        }
    }

    void drawFloat(ONE_BIT_DISPLAY& epd, const uint8_t x, const uint8_t y, const float value)
    {
        float intPart;
        const float decimalPart = std::modf(value, &intPart);

        auto baseline = Roboto::setFont<70>(epd);
        epd.setCursor(x, y + baseline);
        epd.printf("%2d", int8_t(intPart));

        baseline = Roboto::setFont<35>(epd);

        epd.setCursor(x + 80, y + baseline);
        epd.printf("%d", uint8_t(decimalPart * 10.0f));

        epd.fillCircle(x + 80 - 1, y + baseline - 2, 2, OBD_BLACK);

        // RS_DEBUGF("Int: %f, Decimal %f\n", intPart, decimalPart);
    }

    void draw(ONE_BIT_DISPLAY& epd, const DisplayData& data)
    {
        const uint8_t centerX = epd.width() / 2 - 1;
        epd.setTextColor(OBD_BLACK);

        // epd.drawLine(16, 0, 16, 50 - 1, OBD_BLACK);

        drawTemperatureGauge(epd, data.perception);
        // epd.setCursor(17, baseline);
        // epd.printf("%2.1f", data.temperature);
        drawFloat(epd, 27, 0, data.temperature);

        auto baseline = Roboto::setFont<70>(epd);
        constexpr uint8_t xOffset = 9;
        epd.drawSprite(&(epd_bitmap_humidity[0]), 50, 50, calcPitch(50), centerX - xOffset, 0, 1);
        epd.setCursor(centerX + 42 - xOffset, baseline);
        epd.printf("%3d", data.humidity);

        // epd.setCursor(17, largeThirdHeight * 2 - 6);
        // const float dewPoint = calcDewPoint(data.temperature, data.humidity);
        // epd.printf("%2.1f", dewPoint);
        // epd.printf("%d", sensor.pressure);

        // epd.setCursor(centerX + 32, largeThirdHeight * 2 - 6);
        // const float ah = calcAbsoluteHumidity(data.temperature, data.humidity);
        // epd.printf("%2.1f", ah);
        // epd.printf("%d", sensor.gas);

        // epd.drawLine(0, 32, epd.width() - 1, 32, OBD_BLACK);
        // epd.drawLine(0, 0, 0, 32 - 1, OBD_BLACK);

        constexpr auto lineY = largeThirdHeight * 2 - 1;
        epd.drawLine(0, lineY, epd.width() - 1, lineY, OBD_BLACK);

        baseline = Roboto::setFont<16>(epd);
        epd.setCursor(24, epd.height());
        // epd.setTextColor(OBD_RED);
        epd.print(thermalPerceptionToString(data.perception));

        drawBattery(epd, data.soc);
        drawWindow(epd, data.humidity);
    }

    /// @brief Update the EPD
    ///
    /// @param epd
    /// @param data
    /// @param fast Do a fast update
    void update(ONE_BIT_DISPLAY& epd, const DisplayData& data, const bool fast = false)
    {
        draw(epd, data);
        // epd.display(true, false); // do a full update, but don't wait for it
        // epd.display(true, true); // do a full update and wait for it
        // if (fast)
        // {
        //     const int result = epd.displayFast();
        //     RS_DEBUGF("displayFast %d\n", result);
        // }
        // else
        // {
        const int result = epd.display(true, false); // do a full update, but don't wait for it
        // const int result = epd.display(true, true); // do a full update and wait for it
        RS_DEBUGF("display %d\n", result);
        // }

        // epd.setPower(false);
        // epd.sleep();
        // RS_DEBUGF("[%s] free RAM is %d\n", __FUNCTION__, heap_caps_get_free_size(MALLOC_CAP_INTERNAL));

        // When you're done, call vTaskDelete. Don't forget this!
        // vTaskDelete(NULL);
    }
} // namespace EPD
