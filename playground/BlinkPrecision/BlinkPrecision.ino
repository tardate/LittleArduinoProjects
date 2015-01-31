/*
  BlinkPrecision
  Blink an LED with precision timing.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/BlinkPrecision

 */

#include <FlexiTimer2.h>

// Pin 13 has an LED connected on most Arduino boards.
int led_pin = 13;

void setup() {
  pinMode(led_pin, OUTPUT);

  FlexiTimer2::set(500, 1.0/1000, flash); // call every 500 1ms "ticks"
  FlexiTimer2::start();
}

void loop() {
}

void flash()
{
  static boolean output = HIGH;

  digitalWrite(led_pin, output);
  output = !output;
}
