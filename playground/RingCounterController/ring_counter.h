#ifndef RingCounter_h
#define RingCounter_h

#include <Arduino.h>

class RingCounter {
  public:
    RingCounter(int clock_pin, int enable_pin, int reset_pin);

    void init();

    void pulse();
    void reset();
    void enable();
    void disable();

  private:
    int pulse_width;
    int clock_pin;
    int enable_pin;
    int reset_pin;

};

#endif
