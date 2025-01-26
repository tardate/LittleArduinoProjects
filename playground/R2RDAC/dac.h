#ifndef DAC_h
#define DAC_h

#include <Arduino.h>

class DAC {
  public:
    DAC(int data_pin, int latch_pin, int clock_pin);

    void write16(unsigned int data);

  private:
    int clock_pin;
    int latch_pin;
    int data_pin;

    void init();
};

#endif
