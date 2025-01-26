#ifndef display_72R02_h
#define display_72R02_h

#include <Arduino.h>

#define DISPLAY_DIGITS 7

class Display72R02 {
  public:
    Display72R02(int data_pin);

    void init();
    void clear();


    // STATUS INDICATOR CONTROLS
    // Command: set the status indicator +status_index+ (rpelace all indicators)
    void setStatus(byte status_index);
    // Command: enable the status indicator +status_index+ (to existing status)
    void enableStatus(byte status_index);
    // Command: set indicators to +status_indicators+
    void setStatusIndictors(byte status_indicators);
    // Command: clear all indicators
    void clearStatusIndictors();


    // DIGIT CONTROLS
    // Command: set +digit+ to +value+ (0-9)
    void setDigit(byte digit, byte value);
    // Command: clear all digits
    void clearDigits();


    // DISPLAY CONTROLS
    // Command: update display output. Should be called frequently (like on a timer)
    void refresh();
    // Command: send data bytes to the 74HC595 shift register using SPI
    // Note: if more that one SPI device, assumes caller takes responsibility for
    // SPI beginTransaction()/endTransaction()
    void pushDisplayUpdate(byte status_indicators, byte segment_enable, byte digit_enable);


  private:
    int data_pin;
    byte status_indicators;
    byte current_digit;
    byte digits[DISPLAY_DIGITS] = {0,0,0,0,0,0,0};

    // define the bitmasks for characters 0-9
    // where bits represent G,F,E,D,C,B,A,(unused) from MSB to LSB
    byte segment_mask[10] = {
      0b01111110,
      0b00001100,
      0b10110110,
      0b10011110,
      0b11001100,
      0b11011010,
      0b11111010,
      0b00001110,
      0b11111110,
      0b11011110
    };

};

#endif
