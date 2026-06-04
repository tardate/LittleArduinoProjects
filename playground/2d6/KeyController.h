/*

  A simple Key controller - processes key state

*/

#pragma once

#include <Arduino.h>
#include "TM1638.h"

const uint8_t BUTTON_BYTES = 4;
const uint8_t BUTTON1_MASK = _BV(2);
const uint8_t BUTTON2_MASK = _BV(6);
const int DEBOUNCE_DELAY = 250;

class KeyController {

  public:

    KeyController(TM1638Driver* driver) : tm1638_driver(driver), current_value {} {};

    void readKeys();
    bool rollKeyPressed();
    bool bothDiceEnabled();
    void debounceDelay();

  private:

    TM1638Driver* tm1638_driver;
    uint8_t current_value[BUTTON_BYTES];

};
