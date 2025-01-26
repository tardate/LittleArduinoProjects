// charge pump voltage multiplier drive and control for RST/VPP pin
// defaults to 0V on the pin - can be switched to 0V, 5V or 12V for programming the chip's Flash memory
// ceptimus.  January 2016

#pragma once

#include <Arduino.h>

#define RST_PIN     (A0)
#define PUMP_A_PIN  ( 3)
#define PUMP_B_PIN  (11)

class RST_VPP {
  public:
    static void setup(void);           // setup charge pump
    static void setVoltage(uint8_t voltage); // set RST/VPP pin to 12V, 5V or (default) 0V
    static void on(void);              // enable charge pump
    static void off(void);             // disable charge pump
};
