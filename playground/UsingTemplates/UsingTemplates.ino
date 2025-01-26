/*

  UsingTemplates
  Simple demonstration of C++ template functions

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/UsingTemplates

 */

#include "template_functions.hpp"

const int LED_PIN = 13;

/*
 * Command: one-time setup
 */
void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  pinMode(LED_PIN, OUTPUT);
}

/*
 * Command: main loop
 */
void loop() {
  static boolean output = HIGH;
  static uint32_t value1 = 0xabcd0123u;
  static uint16_t value2 = 0x4545u;
  bool wrap1;
  bool wrap2;

  Serial.println(value1, BIN);
  Serial.println(value2, BIN);
  wrap1 = circularShift(value1);
  wrap2 = circularShift(value2);
  if (wrap1 || wrap2) {
    digitalWrite(LED_PIN, output);
    output = !output;
  }
  delay(1000);
}

