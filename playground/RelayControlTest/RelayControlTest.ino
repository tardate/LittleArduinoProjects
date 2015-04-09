/*
  RelayControlTest
  Switch a relay with precision timing.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/RelayControlTest

 */

#include <FlexiTimer2.h>

#define RELAY_CONTROL_PIN 6

void setup() {
  pinMode(RELAY_CONTROL_PIN, OUTPUT);

  FlexiTimer2::set(500, 1.0/1000, toggle); // call every 500 1ms "ticks"
  FlexiTimer2::start();
}

void loop() {
  // NOP
}

void toggle()
{
  static boolean output = HIGH;

  digitalWrite(RELAY_CONTROL_PIN, output);
  output = !output;
}
