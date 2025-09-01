/*

  KeyboardMatrixModule/SwitchInterrupts
  Demo interrupt-driven switch input on a simple pushbutton/LED matrix module

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/KeyboardMatrixModule/SwitchInterrupts

 */

#define EI_ARDUINO_INTERRUPTED_PIN
#include <EnableInterrupt.h>

const int START_S_PIN=2;
const int S_PINS=4;
volatile uint8_t switch_pressed=0;

void interruptFunction () {
  switch_pressed = arduinoInterruptedPin - START_S_PIN + 1;
}

void setup() {
  Serial.begin(9600);
  for(int spin = START_S_PIN; spin < START_S_PIN + S_PINS; ++spin) {
    pinMode(spin, INPUT);
    enableInterrupt(spin, interruptFunction, FALLING);
  }
  Serial.println(F("Waiting for switch interrupts..."));
}

void loop() {
  if(switch_pressed) {
    Serial.print(F("Switch pressed: S"));
    Serial.println(switch_pressed);
    switch_pressed = 0;
  }
}
