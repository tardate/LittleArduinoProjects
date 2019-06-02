#include "matrix_display.h"


MatrixDisplay::MatrixDisplay(LedControl *led_control) {
  this->led_control = led_control;
}


void MatrixDisplay::begin() {
  led_control->shutdown(0, false);
  led_control->setIntensity(0,8);
  led_control->clearDisplay(0);
  writeSprite(Sprites::Question);
}


void MatrixDisplay::showCardEmoji(uint8_t card_id) {
  writeSprite((card_id + 1)/ 2);
}


void MatrixDisplay::writeSprite(uint8_t index) {
  led_control->clearDisplay(0);
  for(int column=0; column<MATRIX_WIDTH; ++column) {
    if (column < FONT_WIDTH) {
      led_control->setRow(0, column, FONT[index][column]);
    } else {
      led_control->setRow(0, column, 0x00);
    }
  }
}


uint8_t MatrixDisplay::maxCardPairs() {
  return FONT_COUNT - SPECIAL_FONTS;
}
