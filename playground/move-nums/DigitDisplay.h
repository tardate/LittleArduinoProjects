#pragma once

#include <Arduino.h>

class DigitDisplay {
  public:
    DigitDisplay(uint8_t mosi_pin, uint8_t sck_pin, uint8_t cs_pin, int8_t initial_value=-1, int8_t min_value=0, int8_t max_value=9);

    /*
      Command: reset display state
    */
    void reset(void);

    /*
      Command: update the display on the 7-segment LED
    */
    void update(void);

    /*
      Command: increment the internal digit counter. no wrapping.
    */
    void inc(void);

    /*
      Command: decrement the internal digit counter. no wrapping.
    */
    void dec(void);

    /*
      Command: set the internal digit counter to a specific value
    */
    void set(int8_t value);

    /*
      Return: true if the current value is valid for display
    */
    bool valid(void);

    /*
      Return: current value
    */
    int8_t value(void);

  private:
    uint8_t mosi_pin;
    uint8_t sck_pin;
    uint8_t cs_pin;

    int8_t current_value;
    int8_t initial_value;
    int8_t min_value;
    int8_t max_value;

    /*
      Command: send +data+ byte to the LED 7-segment 74HC595 shift register
    */
    void pushLed7SegmentRegister(byte data);
    void writeLed7SegmentDigit(byte digit, boolean withDP);
    void writeDigit(byte digit);
    void clearDigit();
};
