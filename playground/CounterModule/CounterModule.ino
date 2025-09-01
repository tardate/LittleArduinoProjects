/*

  CounterModule
  A simple test of the general-purpose CD4017 counter module.
  It resets the module then pulses the clock at a constant frequency.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/CounterModule

 */

#define RESET_PIN 10
#define CLOCK_PIN 11
#define CLOCK_ENABLE_PIN 12  // NB: unused in the sketch, pulled low by default

#define STEP_DELAY 200

void setup() {
  pinMode(RESET_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);

  pulse(RESET_PIN);
}

void loop() {
  pulse(CLOCK_PIN);
  delay(STEP_DELAY);
}

void pulse(int pin) {
  digitalWrite(pin, HIGH);
  digitalWrite(pin, LOW);
}
