/*

  LED/LED8x8Module
  Building and using an 8x8 LED matrix with MAX7219 driver module

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/LED/LED8x8Module

 */

#include <LedControl.h>

const uint8_t CS_PIN  = 10;
const uint8_t DIN_PIN = 11;
const uint8_t CLK_PIN = 13;

const byte MATRIX_WIDTH = 8;

const uint16_t DEMO_DELAY_LONG   = 600;
const uint16_t DEMO_DELAY_MEDIUM = 150;
const uint16_t DEMO_DELAY_SHORT  = 20;

LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
}

void loop() {
  scanner();
}


/*
 Scan through each digit ("row") turning on a single LED ("column") etc..
 */
void scanner() {
  lc.clearDisplay(0);
  for (byte column=0; column<8; column++) {
    for (byte row=0; row<=8; row++) {
      lc.setRow(0, row, 0x01 << column);
      delay(DEMO_DELAY_SHORT);
    }
  }
}
