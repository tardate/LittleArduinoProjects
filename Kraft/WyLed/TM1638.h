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
  B01101111   // 9
};

static const byte EYES[] = {
  B00001111,  // open r
  B00111001,  // open l
  B01001100,  // half-lo r
  B01011000,  // half-lo l
  B01000000,  // closed-mid r
  B01000000,  // closed-mid l
  B00001000,  // closed-lo r
  B00001000   // closed-lo l
};


class TM1638Driver {

  public:

    TM1638Driver(int clk_pin, int data_pin, int cs_pin);

    /*
     * Initialise controls and ports.
     */
    void begin();

    void writeData(uint8_t data);

    uint8_t readData();

    void sendData(uint8_t data);

    void setDataCommand(uint8_t command);

    void writeDataFixedAddress(uint8_t address, uint8_t data);

    void setDisplayControl(bool enabled, uint8_t level);

    /*
     * Clears all display registers.
     * This is a demonstration of incremental addressing mode
     */
    void clearAll();
    void displayNumber(uint16_t counter);
    void readKeys(uint8_t k[]);
    void eyesOpen();
    void eyesHalf();
    void eyesClosed();

  private:

    int clk_pin;
    int data_pin;
    int cs_pin;

    void select();
    void deselect();
    void setDataInbound();
    void setDataOutbound();


};
