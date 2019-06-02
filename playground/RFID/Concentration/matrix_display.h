#pragma once

#include <Arduino.h>
#include <LedControl.h>

const byte FONT_WIDTH = 8;
const byte MATRIX_WIDTH = 8;


/**
 * Mnemonic sprite indexing
 */
enum Sprites : uint8_t {
    Error          = 0,
    Question       = 11,
    Correct        = 12,
    Incorrect      = 13
};


/**
 * All the sprites we can display on the LED matrix
 */
static const byte FONT[][FONT_WIDTH] =
{
  {
    B00000000,
    B00000000,
    B01011110,
    B00000000,
    B00000000,
    B01011110,
    B00000000,
    B00000000
  } // 0
  ,{
    B00000001,
    B00000011,
    B00000111,
    B00001111,
    B00011111,
    B00111111,
    B01111111,
    B11111111
  } // 1 - start of card fonts
  ,{
    B00000000,
    B01111110,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01111110,
    B00000000
  } // 2
  ,{
    B11111111,
    B10000001,
    B10111101,
    B10100101,
    B10100101,
    B10111101,
    B10000001,
    B11111111,
  } // 3
  ,{
    B00000000,
    B01111110,
    B01000010,
    B01011010,
    B01011010,
    B01000010,
    B01111110,
    B00000000
  } // 4
  ,{
    B11111111,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B11111111,
  } // 5
  ,{
    B00000001,
    B00000011,
    B00000111,
    B00011111,
    B00011111,
    B00000111,
    B00000011,
    B00000001
  } // 6
  ,{
    B00000001,
    B00000011,
    B00000111,
    B11111111,
    B11111111,
    B00000111,
    B00000011,
    B00000001
  } // 7
  ,{
    B11111111,
    B11000011,
    B11000011,
    B11111111,
    B11111111,
    B11000011,
    B11000011,
    B11111111
  } // 8
  ,{
    B10000000,
    B11000110,
    B11100110,
    B11110000,
    B11111000,
    B11111100,
    B11111110,
    B11111111
  } // 9
  ,{
    B00000000,
    B00000000,
    B00000000,
    B00011000,
    B00011000,
    B00000000,
    B00000000,
    B00000000
  } // 10 - last card font
  ,{
    B00000000,
    B00000000,
    B00000110,
    B00000001,
    B10110001,
    B00001001,
    B00000110,
    B00000000
  } // 11 - Question
  ,{
    B00000000,
    B00100000,
    B01000000,
    B00100000,
    B00010000,
    B00001000,
    B00000100,
    B00000000
  } // 12 - Correct
  ,{
    B00000000,
    B01000010,
    B00100100,
    B00011000,
    B00011000,
    B00100100,
    B01000010,
    B00000000
  } // 13 - Incorrect
};

const byte FONT_COUNT = sizeof(FONT) / FONT_WIDTH;
const byte SPECIAL_FONTS = 2;


/**
 * Encapsulates control of the 8x8 LED matrix
 */
class MatrixDisplay {
  public:
    MatrixDisplay(LedControl *led_control);

    /**
     * Initializes indictor LEDs
     */
    void begin();

    /*
     * Command: display font for specified card.
     */
    void showCardEmoji(uint8_t card_id);

    /*
     * Command: display a specified character from the font set.
     */
    void writeSprite(uint8_t index);

    /*
     * Command: returns the max number of card pairs we can display.
     */
    uint8_t maxCardPairs();

  private:
    LedControl *led_control;
};
