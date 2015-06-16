/*

  LedControlDemo
  Test driving and LED matrix with the LedControl library

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/LED8x8/LedControlDemo

 */

#include <LedControl.h>
#include "font.h"

#define DIN_PIN 10
#define CS_PIN 11
#define CLK_PIN 12

#define DEMO_DELAY_LONG 600
#define DEMO_DELAY_SHORT 50

LedControl lc=LedControl(DIN_PIN,CLK_PIN,CS_PIN,1);

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
}

void loop() {
  writeDemoText();
  scanner();
}

/*
 Write some text to the matrix, one char at a time
 */
void writeDemoText() {
  lc.clearDisplay(0);
  writeString("Arduino");
}

void writeCharacter(char character) {
  for(int i=0; i<FONT_WIDTH; i++) lc.setRow(0, i, FONT[character - 0x20][i]);
}

void writeString(char *characters) {
  while(*characters) {
    writeCharacter(*characters++);
    delay(DEMO_DELAY_LONG);
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

