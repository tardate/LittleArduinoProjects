/*

  2d6

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/2d6

 */

#include "TM1638.h"
#include "KeyController.h"
#include "Die.h"

#ifdef ARDUINO_attiny
const uint8_t CS_PIN  = 0;
const uint8_t DIN_PIN = 1;
const uint8_t CLK_PIN = 2;
#else
const uint8_t CS_PIN  = 10;
const uint8_t DIN_PIN = 11;
const uint8_t CLK_PIN = 13;
#endif

TM1638Driver tm1638_driver(CLK_PIN, DIN_PIN, CS_PIN);
KeyController key_controller(&tm1638_driver);
Die die0, die1;

const uint8_t MIN_ROLL_FACTOR = 5;
const uint8_t MAX_ROLL_FACTOR = 20;

/*
 * Command: one-time setup
 */
void setup() {
  tm1638_driver.begin();
  tm1638_driver.clearAll();
  randomSeed(analogRead(0));
  key_controller.readKeys();
  drawDice();
}

/*
 * Command: check dice enabled status and update display with current values
 */
void drawDice() {
  if (key_controller.bothDiceEnabled()) {
    die1.enable();
  } else {
    die1.disable();
  }
  tm1638_driver.displayNumbers(die1.value, die0.value);
}

/*
 * Command: single roll of the dice
 */
void rollDice() {
  die0.roll();
  die1.roll();
  drawDice();
}

/*
 * Command: animate the final rolldown of the dice
 */
void rollDown(uint16_t roll_factor) {
  for (int i=0; i<roll_factor; ++i) {
    rollDice();
    delay(10 * i);
  }
}

/*
 * Command: main loop
 */
void loop() {
  if (key_controller.rollKeyPressed()) {
    uint16_t roll_factor = MIN_ROLL_FACTOR;
    do {
      rollDice();
      if (roll_factor < MAX_ROLL_FACTOR) ++roll_factor;
    } while (key_controller.rollKeyPressed());
    rollDown(roll_factor);
    key_controller.debounceDelay();
  }
}
