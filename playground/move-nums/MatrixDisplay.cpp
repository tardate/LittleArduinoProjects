#include "MatrixDisplay.h"

MatrixDisplay::MatrixDisplay(LedControl *lc) {
  this->lc = lc;
  reset();
}

void MatrixDisplay::begin(void) {
  lc->shutdown(0, false);
  lc->setIntensity(0, 15);
}

void MatrixDisplay::reset(void) {
  for (uint8_t c = 0; c < MAX_COLS; c++) {
    columns[c] = 0;
  }
  lc->clearDisplay(0);
}

void MatrixDisplay::confirm_column(uint8_t column) {
  // columns[column] = position;
}

bool MatrixDisplay::column_valid(uint8_t column) {
  return columns[column] > 0 && columns[column] <= 8;
}

void MatrixDisplay::update_column(uint8_t column, int8_t position) {
  columns[column] = position;
  display_column(column);
}

void MatrixDisplay::display_column(uint8_t column) {
  byte display_bits = 0xFF >> (8 - columns[column]);
  lc->setRow(0, 7 - column, display_bits);
}

void MatrixDisplay::moveNums(int8_t n) {
  for (uint8_t c = 0; c < MAX_COLS; c++) {
    if (columns[c] != n) continue;

    for (uint8_t swap = c; swap < MAX_COLS; swap++) {
      if (columns[swap] != n) {
        columns[c] = columns[swap];
        columns[swap] = n;
        display_column(c);
        delay(ANIMATION_DELAY);
        display_column(swap);
        delay(ANIMATION_DELAY);
        break;
      }
    }
  }
}
