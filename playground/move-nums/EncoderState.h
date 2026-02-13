#pragma once

#include <Arduino.h>
#include <Rotary.h>

class EncoderState {
  public:
    EncoderState(int8_t min_position=0, int8_t max_position=9);
    void reset(void);
    bool process(unsigned char direction);
    bool inc(void);
    bool dec(void);
    bool change(int8_t amount);
    void clear();

    int8_t position;
    bool has_changed;
  private:
    int8_t min_position;
    int8_t max_position;
};
