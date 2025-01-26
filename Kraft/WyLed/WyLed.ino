/*

  WyLed
  The WyLed free-form sculture reacts to sound and blinks a 4-digit LED display.
  An ATTiny85 provides a little brain, and the TM1638 handles all input and output.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Kraft/WyLed

 */


#include "TM1638.h"
#include "KeyController.h"

// pins set for an ATtiny.
const uint8_t DIN_PIN = 0;
const uint8_t CLK_PIN = 1;
const uint8_t CS_PIN  = 2;

const int BLINK_SHORT = 5;
const int BLINK_LONG = BLINK_SHORT * 6;

TM1638Driver tm1638_driver(CLK_PIN, DIN_PIN, CS_PIN);
KeyController key_controller;

uint16_t counter = 0;

/*
 * Command: one-time setup
 */
void setup() {
  tm1638_driver.begin();
  tm1638_driver.clearAll();
  tm1638_driver.eyesOpen();
}

/*
 * Command: main loop
 */
void loop() {

  tm1638_driver.readKeys(key_controller.current_value);
  if (key_controller.keyPressed()) {
    int blink_speed = random(9) + 1;
    tm1638_driver.eyesHalf();
    delay(BLINK_SHORT * blink_speed);
    tm1638_driver.eyesClosed();
    delay(BLINK_LONG * blink_speed);
    tm1638_driver.eyesHalf();
    delay(BLINK_SHORT * blink_speed);
    tm1638_driver.eyesOpen();
  }
}
