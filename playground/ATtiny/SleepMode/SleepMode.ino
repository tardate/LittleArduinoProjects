/*

  SleepMode
  Test sleep mode with an ATtiny85 processor on a breadboard

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ATtiny/SleepMode

 */

#include <avr/sleep.h>

#define INTERRUPT 0 // digital pin 2 / ATtiny pin 7
#define LED_PIN 4

void setup() {
  pinMode(LED_PIN, OUTPUT);
  attachInterrupt(INTERRUPT, wakeyWakey, LOW);
}

void loop() {
  performOperation();
  gotoSleep();
}

void gotoSleep() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_mode();
}

void wakeyWakey() {
  // NOP
}

void performOperation() {
  for(int i=0; i<24; i++) flashLed();
}

void flashLed() {
  static boolean output = HIGH;
  digitalWrite(LED_PIN, output);
  delay(200);
  output = !output;
}
