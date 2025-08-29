/*

  ATtiny/FlickeringFireEffect
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/ATtiny/FlickeringFireEffect

 */

#include "flame.h"
#include "level_control.h"

Flame flame1;
Flame flame2;
Flame flame3;
LevelControl level_control;

/*
 * Command: one-time setup
 */
void setup() {
  level_control.setup(A1);
  flame1.setup(0, &level_control, 60);
  flame2.setup(1, &level_control, 50);
  flame3.setup(4, &level_control, 40);
}

/*
 * Command: main loop
 */
void loop() {
  flame1.flicker();
  flame2.flicker();
  flame3.flicker();
}
