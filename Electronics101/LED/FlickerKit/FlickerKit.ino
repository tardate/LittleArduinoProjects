/*

  LED/FlameKit
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/LED/FlameKit

 */

#include "flame.h"
#include "dial.h"

Flame flame1;
Flame flame2;
Dial dial;

const int FLAME1_PIN = 1; // ATtiny85 DIP8: PB1, pin 6
const int FLAME2_PIN = 4; // ATtiny85 DIP8: PB4, pin 3
const int DIAL_PIN = A1; // ATtiny85 DIP8: pin 7

/*
 * Command: one-time setup
 */
void setup() {
  dial.setup(DIAL_PIN, 100, 100);
  flame1.setup(FLAME1_PIN, 50, 30);
  flame2.setup(FLAME2_PIN, 30, 30);
}

/*
 * Command: main loop
 */
void loop() {
  dial.update();
  flame1.flicker(dial.level);
  flame2.flicker(dial.level);
}
