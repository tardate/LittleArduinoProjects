/*

  A simple die model

*/

#pragma once

#include <Arduino.h>
#include "TM1638.h"

class Die {
  public:
    uint8_t value;

    Die();

    void clear();
    void blank();
    void enable();
    void disable();
    void roll();

  private:
    bool enabled;

};
