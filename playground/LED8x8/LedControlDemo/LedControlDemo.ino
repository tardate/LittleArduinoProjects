/*

  LedControlDemo
  Test driving and LED matrix with the LedControl library

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/LED8x8/LedControlDemo

 */

#include <LedControl.h>
#include "font.h"

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
  writeDemoText();
  scanner();
  writeAllCharacters();
}

/*
 Write some text to the matrix, one char at a time.
 */
void writeDemoText() {
  lc.clearDisplay(0);
  writeString("Arduino");
}

/*
 Display a specified character from the font set.
 */
void writeCharacter(char character) {
  for(int column=0; column<MATRIX_WIDTH; ++column) {
    if (column < FONT_WIDTH) {
      lc.setRow(0, column, FONT[character - FONT_FIRST_CHARACTER][column]);
    } else {
      lc.setRow(0, column, 0x00);
    }
  }
}

/*
 Write a string to the display a character at a time.
 */
void writeString(char *characters) {
  while(*characters) {
    writeCharacter(*characters++);
    delay(DEMO_DELAY_LONG);
  }
}

/*
 Scan through and display all characters in the font set.
 */
void writeAllCharacters() {
  for(int i=0; i<FONT_COUNT; ++i) {
    writeCharacter(FONT_FIRST_CHARACTER + i);
    delay(DEMO_DELAY_MEDIUM);
  }
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
