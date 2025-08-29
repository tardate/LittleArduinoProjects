/*

  LED7Segment/ShiftDriveSPI
  Using SPI to control a 7-segment display via a 74HC595 shift register

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/LED7Segment/ShiftDriveSPI

 */

#include <SPI.h>

SPISettings shiftRegisterSettings(2000000, MSBFIRST, SPI_MODE0);

// Standard SPI pins are used used for clock and data, but slave select can be any free pin
#define ST_CP_LATCH_PIN 4

#define STEP_DELAY 500

// define the bitmasks for characters 0-9
// where bits represent dp,G,F..A from MSB to LSB
byte LED_DIGIT_MASK[] = {
  0b00111111,
  0b00000110,
  0b01011011,
  0b01001111,
  0b01100110,
  0b01101101,
  0b01111101,
  0b00000111,
  0b01111111,
  0b01101111
};

// define the bitmasks for clear and decimal point
#define LED_CLEAR_MASK 0b00000000
#define LED_DP_MASK    0b10000000


void setup() {
  SPI.begin();
  pinMode(ST_CP_LATCH_PIN, OUTPUT);
}


void loop() {
  for(int d=0; d<10; d++) {
    writeDigit(d, d % 2 == 0);
    delay(STEP_DELAY);
  }
  clearDigit();
  delay(STEP_DELAY);
}


// Command: send +data+ byte to the 74HC595 shift register using SPI
// Note: since only using one SPI device,
// beginTransaction()/endTransaction() is actually redundant here
// SPI setup could be done in the setup() function
void pushSegmentRegister(byte data) {
  SPI.beginTransaction(shiftRegisterSettings);
  digitalWrite(ST_CP_LATCH_PIN, LOW);
  SPI.transfer(data);
  digitalWrite(ST_CP_LATCH_PIN, HIGH);
  SPI.endTransaction();
}


void writeDigit(byte digit, boolean withDP) {
  if(withDP) pushSegmentRegister(LED_DIGIT_MASK[digit] | LED_DP_MASK);
  else pushSegmentRegister(LED_DIGIT_MASK[digit]);
}


void writeDigit(byte digit) {
  pushSegmentRegister(LED_DIGIT_MASK[digit]);
}


void clearDigit() {
  pushSegmentRegister(LED_CLEAR_MASK);
}
