/*

  LEDx16Module

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/LEDx16Module

 */

 // use hardware SPI, MSB first
#include <SPI.h>
SPISettings spiSettings(1800000, MSBFIRST, SPI_MODE0);

// Standard SPI pins are used used for clock and data, but slave select can be any free pin
const int ST_CP_LATCH_PIN = 4;

#define SHORT_DELAY 50
#define STEP_DELAY 100
#define LONG_DELAY 500

void setup() {
  SPI.begin();
  pinMode(ST_CP_LATCH_PIN, OUTPUT);
  SPI.beginTransaction(spiSettings);
}


void loop() {
  clear();
  fourBlocks();
  clear();
  chequers();
  clear();
  chaser(false);
  chaser(false);
  chaser(true);
  chaser(true);
  chaser(false);
  clear();
}

void chaser(bool clockwise) {
  /*
      move a single LED around the board
   */
  uint16_t data;
  for(byte position=0; position<16; position++) {
    if(clockwise) {
      data = 0xFFFF ^ (1 << (16 - position));
    } else {
      data = 0xFFFF ^ (1 << position);
    }
    writeData16(data);
    delay(SHORT_DELAY);
  }
}

void chequers() {
  /*
      on                off
      off               on
      on                off
      off               on
      on                off
      off               on
      on                off
      off               on
   */
  byte pattern = 0b10101010;
  byte pattern_reversed = 0b01010101;

  for(int r=0; r<10; r++) {
    writeData(pattern, pattern);
    delay(STEP_DELAY);
    writeData(pattern_reversed, pattern_reversed);
    delay(STEP_DELAY);
  }
}

void fourBlocks() {
  /*
      on                off
      on                off
      on                off
      on                off
      off               on
      off               on
      off               on
      off               on
   */
  byte pattern = 0b11110000;
  byte pattern_reversed = 0b00001111;

  for(int r=0; r<10; r++) {
    writeData(pattern, pattern);
    delay(STEP_DELAY);
    writeData(pattern_reversed, pattern_reversed);
    delay(STEP_DELAY);
  }
}

void clear() {
  writeData(0xFF, 0xFF);
  delay(LONG_DELAY);
}


// Command: send left and right bytes
void writeData(byte left, byte right) {
  digitalWrite(ST_CP_LATCH_PIN, LOW);
  SPI.transfer(left);
  SPI.transfer(right);
  digitalWrite(ST_CP_LATCH_PIN, HIGH);
}

// Command: write 16 bits to the module
void writeData16(uint16_t data) {
  digitalWrite(ST_CP_LATCH_PIN, LOW);
  SPI.transfer16(data);
  digitalWrite(ST_CP_LATCH_PIN, HIGH);
}
