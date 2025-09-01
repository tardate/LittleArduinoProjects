/*

  LEDCubes/Mini4
  Drive a mini 4x4x4 LED cube with a 3x74HC595 register interface

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/LEDCubes/Mini4

 */

#include <FlexiTimer2.h>      // use timer for scheduling the display update
#include "cube_driver.h"      // main cube controller class

// LED sequence implementations
#include "seq_flash.h"
#include "seq_the_loneliness_of_the_long_distance_runner.h"
#include "seq_rolling_in_the_deep.h"
#include "seq_the_writer.h"

// define pins for the shift register control
#define SH_CP_CLOCK_PIN 3
#define ST_CP_LATCH_PIN 4
#define DS_DATA_PIN 5

CubeDriver cube_driver(ST_CP_LATCH_PIN, SH_CP_CLOCK_PIN, DS_DATA_PIN);

// Command: update the LED display. This is a shim between the timer interrupt and the object redraw method
void redrawCube() {
  cube_driver.redraw();
}

void setup() {
  cube_driver.init();
  FlexiTimer2::set(1, redrawCube);
  FlexiTimer2::start();
}

void loop() {
  seq_flash(&cube_driver);
  seq_the_loneliness_of_the_long_distance_runner(&cube_driver);
  seq_rolling_in_the_deep(&cube_driver);
  seq_the_writer(&cube_driver);
}
