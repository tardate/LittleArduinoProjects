/*

  A simplified TM1638 interface

*/

#pragma once

#include <Arduino.h>

const uint8_t TM1638_data_command               = _BV(6);
const uint8_t TM1638_data_command_mask          = 0b00001111;
const uint8_t TM1638_data_command_write         = 0;
const uint8_t TM1638_data_command_read          = _BV(1);
const uint8_t TM1638_data_command_incr_address  = 0;
const uint8_t TM1638_data_command_fixed_address = _BV(2);
const uint8_t TM1638_data_command_normal        = 0;
const uint8_t TM1638_data_command_test          = _BV(3);

const uint8_t TM1638_address_command            = _BV(7) | _BV(6);
const uint8_t TM1638_address_command_mask       = 0b00111111;

const uint8_t TM1638_display_command            = _BV(7);
const uint8_t TM1638_display_command_mask       = 0b00000111;
const uint8_t TM1638_display_command_on         = _BV(3);


/*
 * simple "font" definition for the TM1638 with 7-segment displays
 */

static const byte NUMBERS[] = {
  B00111111,  // 0
  B00000110,  // 1
  B01011011,  // 2
  B01001111,  // 3
  B01100110,  // 4
  B01101101,  // 5
  B01111101,  // 6
  B00000111,  // 7
  B01111111,  // 8
  B01101111,  // 9
  B01110111,  // A
  B01111100,  // b
  B01011000,  // c
  B01011110,  // d
  B01111001,  // e
  B01110001,  // f
  B01000000,  // -
  B00000000   // <blank>
};

static const uint8_t NUMBER_OF_NUMBERS = sizeof(NUMBERS) / sizeof(byte);
static const uint8_t NUMBER_BLANK = NUMBER_OF_NUMBERS - 1;
static const uint8_t NUMBER_CLEAR = NUMBER_OF_NUMBERS - 2;

class TM1638Driver {

  public:

    TM1638Driver(int clk_pin, int data_pin, int cs_pin, uint8_t brightness = 7) :
      clk_pin(clk_pin), data_pin(data_pin), cs_pin(cs_pin), brightness(brightness) {};

    /*
     * Initialise controls and ports.
     */
    void begin();

    /*
     * Clears all display registers.
     */
    void clearAll();

    /*
     * Sets the encoded values on the display.
     */
    void setDisplayValues(uint8_t c1, uint8_t c0);

    /*
     * Displays two numbers on the display.
     */
    void displayNumbers(uint8_t n1, uint8_t n0);

    /*
     * Displays a 2-digit number on the display.
     */
    void displayNumber(uint16_t counter);

    /*
     * Read the current key state into k
     */
    void readKeys(uint8_t k[]);

  private:

    int clk_pin;
    int data_pin;
    int cs_pin;
    uint8_t brightness;

    void setDataInbound();
    void setDataOutbound();

    void select();
    void deselect();

    uint8_t readData();
    void writeData(uint8_t data);
    void sendData(uint8_t data);
    void setDataCommand(uint8_t command);
    void writeDataFixedAddress(uint8_t address, uint8_t data);

    /*
     * Enable or disable the display.
     */
    void setDisplayControl(bool enabled);

};
