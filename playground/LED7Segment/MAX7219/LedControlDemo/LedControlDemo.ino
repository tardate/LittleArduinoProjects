/*

  LED7Segment/MAX7219/LedControlDemo
  Driving a series of 7-segment LED displays with the MAX7219 and the LedControl library.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/LED7Segment/MAX7219/LedControlDemo

 */

#include <LedControl.h>

const uint8_t CS_PIN  = 10;
const uint8_t DIN_PIN = 11;
const uint8_t CLK_PIN = 13;

const uint8_t MODULE_ADDRESS = 0;

const uint16_t DEMO_DELAY  = 1000;

LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);

void setup() {
  lc.shutdown(MODULE_ADDRESS, false);
  lc.setIntensity(MODULE_ADDRESS, 8);
  lc.clearDisplay(MODULE_ADDRESS);
  lc.setScanLimit(MODULE_ADDRESS, 1);
}

void loop() {
  counter();
}

/*
 Run a looping second counter ..
 */
void counter() {
  for (byte value=0; value<100; ++value) {
    lc.setDigit(MODULE_ADDRESS, 0, value % 10, false);
    lc.setDigit(MODULE_ADDRESS, 1, value / 10, true);
    delay(DEMO_DELAY);
  }
}
