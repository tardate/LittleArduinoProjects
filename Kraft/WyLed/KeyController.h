/*

  A simple Key controller - processes key state

*/

#pragma once

#include <Arduino.h>

const uint8_t BUTTON_BYTES = 4;
const uint8_t BUTTON1_MASK = _BV(2);
const uint8_t BUTTON2_MASK = _BV(6);
const int DEBOUNCE_DELAY = 250;

class KeyController {

  public:

    uint8_t current_value[BUTTON_BYTES];

    KeyController() : current_value {} {};

    bool keyPressed();

    bool bothKeysPressed();

    bool decrementKeyPressed();

    bool incrementKeyPressed();

    void debounceDelay();

};
