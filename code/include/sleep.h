#pragma once

#include <chrono>

#include "Debug.h"

/// @brief Sleep for the given duration
/// @tparam _Rep
/// @tparam _Period
/// @param duration
template <typename _Rep, typename _Period>
void sleep(const std::chrono::duration<_Rep, _Period>& duration)
{
    // Turn off some stuff
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_OFF);
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_SLOW_MEM, ESP_PD_OPTION_ON);
    // esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_SLOW_MEM, ESP_PD_OPTION_OFF);
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_FAST_MEM, ESP_PD_OPTION_OFF);
    esp_sleep_pd_config(ESP_PD_DOMAIN_XTAL, ESP_PD_OPTION_OFF);

    esp_sleep_enable_timer_wakeup(std::chrono::duration_cast<std::chrono::microseconds>(duration).count());
    // Or when the button is pressed
    // rtc_gpio_pullup_en(GPIO_NUM_13);
    // esp_sleep_enable_ext0_wakeup(GPIO_NUM_13, 0);

    // digitalWrite(GPIO_NUM_2, LOW);
    RS_DEBUGLN("Sleep!");

    // Flush any output
    // Serial.flush();

    // Sleep
    esp_deep_sleep_start();
}