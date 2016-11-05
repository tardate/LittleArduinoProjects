/*

  XYplotter/tree
  Draw a Christmas Tree with an Arduino on a Digital Oscilloscope

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/XYplotter

 */

#include <SPI.h>

SPISettings digipotSettings(16000000, MSBFIRST, SPI_MODE0);

// Standard hardware SPI pins are used used for clock and data, but slave select can be any free pin.
// Note that setPot uses direct port manipulation that assumes digital pin 9 is used (PB1)
const int DIGIPOT_SS_PIN = 9;

#define CMD_WRITE (0b00010000)
#define CMD_P0    (0b01)
#define CMD_P1    (0b10)
#define CMD_X     (CMD_WRITE | CMD_P0)
#define CMD_Y     (CMD_WRITE | CMD_P1)

#include "data.h"

void setup() {
  SPI.begin();
  pinMode(DIGIPOT_SS_PIN, OUTPUT);
  SPI.beginTransaction(digipotSettings);
}

void loop() {
  int last_p = NUM_POINTS - 1;
  for(int p = 0; p < NUM_POINTS; p++) {
    setPot(VERTICES[p][0], VERTICES[p][1]);
    last_p = p;
  }
}

// Command: set the x and y pot levels
// This uses direct port manipulation instad of digitalWrite
// in order to achieve a sufficiently high refresh rate.
// Unfortunately it appears the MCP42010 cannot handle two commands in a
// single SPI transaction, hence X and Y settings need to be sent separately.
void setPot(byte x, byte y) {
  //digitalWrite(DIGIPOT_SS_PIN, LOW);
  PORTB &= ~(_BV(1));

  SPI.transfer16(CMD_Y << 8 | y);

  //digitalWrite(DIGIPOT_SS_PIN, HIGH);
  //digitalWrite(DIGIPOT_SS_PIN, LOW);
  PORTB |= _BV(1);
  PORTB &= ~(_BV(1));

  SPI.transfer16(CMD_X << 8 | x);

  //digitalWrite(DIGIPOT_SS_PIN, HIGH);
  PORTB |= _BV(1);
}
