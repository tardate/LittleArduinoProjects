/*

  LED7Segment/TM1638/RawDrive
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/LED7Segment/TM1638

 */


#include "TM1638.h"
#include "KeyController.h"

const uint8_t CS_PIN  = 10;
const uint8_t DIN_PIN = 11;
const uint8_t CLK_PIN = 13;

TM1638Driver tm1638_driver(CLK_PIN, DIN_PIN, CS_PIN);
KeyController key_controller;

uint16_t counter = 0;

/*
 * Command: one-time setup
 */
void setup() {
  Serial.begin(115200);
  tm1638_driver.begin();

  tm1638_driver.clearAll();
  tm1638_driver.displayNumber(counter);
}

/*
 * Command: loop function for manual mode
 */
void manualStrategy() {
  if (key_controller.keyPressed()) {
    if (key_controller.decrementKeyPressed() && counter > 0) {
      --counter;
    }
    if (key_controller.incrementKeyPressed() && counter < 99) {
      ++counter;
    }
    tm1638_driver.displayNumber(counter);
    key_controller.debounceDelay();
  }
}

/*
 * Command: loop function for automatic mode
 */
void automaticStrategy() {
  static unsigned long last_incr = millis();
  if (millis() - last_incr > 1000) {
    if (counter < 99) ++counter;
    else counter = 0;
    last_incr = millis();
    tm1638_driver.displayNumber(counter);
  }
}

/*
 * Command: main loop
 */
void loop() {
  static void (*counterStrategy)(void) = &automaticStrategy;
  (*counterStrategy)();

  tm1638_driver.readKeys(key_controller.current_value);
  if (key_controller.bothKeysPressed()) { // switch between manual and automatic modes
    tm1638_driver.clearAll();
    counter = 0;
    tm1638_driver.displayNumber(counter);
    if (counterStrategy == &automaticStrategy) {
      counterStrategy = &manualStrategy;
    } else {
      counterStrategy = &automaticStrategy;
    }
    key_controller.debounceDelay();
  }
}
