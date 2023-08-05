/// @file Debug.h
/// @author Moritz Wirger (contact@wirmo.de)
/// @brief Simple debug logger using progmen
#pragma once

#if (defined(__AVR__))
#include <avr\pgmspace.h>
#else
#include <pgmspace.h>
#endif

#include <HardwareSerial.h>

// #define RS_DEBUG_SERIAL Serial1
// #define RS_DEBUG_SERIAL Serial

#ifdef RS_DEBUG_SERIAL
#define RS_DEBUG(s) RS_DEBUG_SERIAL.print(s)
#define RS_DEBUGLN(s) RS_DEBUG_SERIAL.println(s)
#if defined(__cplusplus) && (__cplusplus > 201703L)
#define RS_DEBUGF(format, ...) RS_DEBUG_SERIAL.printf_P(PSTR(format), __VA_OPT__(, ) __VA_ARGS__)
#else // !(defined(__cplusplus) && (__cplusplus >  201703L))
#define RS_DEBUGF(format, ...) RS_DEBUG_SERIAL.printf_P(PSTR(format), ##__VA_ARGS__)
#endif
#else
#define RS_DEBUG(s)
#define RS_DEBUGLN(s)
#define RS_DEBUGF(format, ...)
#endif