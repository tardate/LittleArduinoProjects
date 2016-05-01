/*

  LedPanelDisplay72R02
  Test 7-digit & 7-status indicator LED display

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/LedPanelDisplay72R02

 */

#include <SPI.h>
#include <FlexiTimer2.h>
#include "display_72R02.h"

// Standard SPI pins are used used for clock and data, but slave select can be any free pin
const int ST_CP_LATCH_PIN = 8;

SPISettings shiftRegisterSettings(2000000, MSBFIRST, SPI_MODE0);

Display72R02 display_unit(ST_CP_LATCH_PIN);

const int DEMO_SHORT_DELAY = 40;
const int DEMO_LONG_DELAY = 300;

void setup() {
  SPI.begin();
  SPI.beginTransaction(shiftRegisterSettings); // only one SPI device, so no need to begin/end transactions

  display_unit.init();

  FlexiTimer2::set(5, refresh); // update display every 5 ms
  FlexiTimer2::start();
}

// Command: refresh display on timer interrupt
void refresh() {
  display_unit.refresh();
}


void loop() {
  SimpleCounterDemo();
  digitKnightRiderDemo();
  statusIndicatorKnightRiderDemo();
  statusIndicatorAllCombosDemo();
}

void clearDemo() {
  display_unit.clear();
  delay(DEMO_LONG_DELAY);
}

void statusIndicatorAllCombosDemo() {
  for(int i=0; i<0b10000000; i++) {
    display_unit.setStatusIndictors(i);
    delay(DEMO_SHORT_DELAY / 2);
  }
  clearDemo();
}

void statusIndicatorKnightRiderDemo() {
  for(int r=0; r<6; r++) {
    for(int i=0; i<7; i++) {
      display_unit.setStatus(i);
      delay(DEMO_SHORT_DELAY);
    }
    for(int i=6; i>0; i--) {
      display_unit.setStatus(i);
      delay(DEMO_SHORT_DELAY);
    }
  }
  clearDemo();
}

void SimpleCounterDemo() {
  for(byte digit=0; digit<7; digit++) {
    for(byte value=0; value<10; value++) {
      display_unit.setDigit(digit, value);
      delay(DEMO_SHORT_DELAY * 2);
    }
  }
  clearDemo();
}

void digitKnightRiderDemo() {
  for(int value=0; value<10; value++) {

    if(value<7) display_unit.setStatus(value);
    else display_unit.setStatusIndictors(0b1001001);

    for(int i=0; i<7; i++) {
      display_unit.clearDigits();
      display_unit.setDigit(i, value);
      delay(DEMO_SHORT_DELAY * 2);
    }
    for(int i=6; i>0; i--) {
      display_unit.clearDigits();
      display_unit.setDigit(i, value);
      delay(DEMO_SHORT_DELAY * 2);
    }
  }
  clearDemo();
}




