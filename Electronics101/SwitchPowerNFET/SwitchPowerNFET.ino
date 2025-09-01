/*

  SwitchPowerNFET
  Low-side n-channel MOSFET switching of large loads with a microcontroller.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/SwitchPowerNFET

 */

#include <FlexiTimer2.h>

const int CONTROL_PIN = 7;

void setup() {
  pinMode(CONTROL_PIN, OUTPUT);

  // start a time to toggle output every 5ms i.e. 1/(2*5ms) = 100Hz
  FlexiTimer2::set(5, toggle);
  FlexiTimer2::start();
}

void loop() {
}

/*
 * toggle the CONTROL_PIN
 */
void toggle() {
  static boolean output = HIGH;

  digitalWrite(CONTROL_PIN, output);

  output = !output;
}
