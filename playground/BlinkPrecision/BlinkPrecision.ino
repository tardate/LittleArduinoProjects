/*
  BlinkPrecision
  Blink an LED with precision timing.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/BlinkPrecision

 */

#include <FlexiTimer2.h>

#define LED_PIN 13                           // pin 13 has an LED connected on most Arduino boards

void setup() {
  pinMode(LED_PIN, OUTPUT);

  FlexiTimer2::set(500, 1.0/1000, flash);    // call every 500 1ms "ticks"
  FlexiTimer2::start();
}

void loop() {
  // NOP
}

void flash() {
  static boolean output = HIGH;

  digitalWrite(LED_PIN, output);
  output = !output;
}
