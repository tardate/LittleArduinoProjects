/*

  DigitalPots/M62429
  Control the M62429 dual channel volume control with an Arduino.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/DigitalPots/M62429

 */

#include "volume_control.h"

VolumeControl vol(7, 8);

void setup() {
  vol.begin();
  vol.set_db(0, LEFT_CHANNEL);
}

void loop() {
  for (byte level = 0; level <= 100; level++) {
    vol.set_level(level, RIGHT_CHANNEL);
    delay(1);
  }
}

