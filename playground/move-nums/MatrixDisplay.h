#pragma once

#include <Arduino.h>
#include <LedControl.h>

const uint8_t MAX_COLS = 8;
const int ANIMATION_DELAY = 100;

class MatrixDisplay {
  public:
    MatrixDisplay(LedControl *lc);
    void begin(void);
    void reset(void);
    void confirm_column(uint8_t column);
    void update_column(uint8_t column, int8_t position);
    void display_column(uint8_t column);
    bool column_valid(uint8_t column);
    void moveNums(int8_t n);
  private:
    LedControl *lc;
    int8_t columns[MAX_COLS];
};
