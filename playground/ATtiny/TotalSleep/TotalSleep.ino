/*

  TotalSleep
  Test a total power shutdown with an ATtiny85 processor on a breadboard

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ATtiny/TotalSleep

 */

#define POWER_PIN  0 // ATtiny pin 5
#define LED_PIN    4 // ATtiny pin 3

void setup() {
  keepAlive();

  // enable the LED pin for the demo behaviour
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // do something, then send ourselves to sleep
  // NB: this could be included at the end of the setup() function
  // instead of in the loop() since we'll only do this once
  performOperation();
  gotoSleep();
}

void keepAlive() {
  // set the power pin high to keep the processor alive
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, HIGH);
}

void gotoSleep() {
  // switch the power-pin to high-impedence input state
  pinMode(POWER_PIN, INPUT);
  delay(5000);

  // we should have powered-down by this point.
  // But for testing purposes, reset the power pin and repeat
  keepAlive();
}

void performOperation() {
  for(int i=0; i<10; i++) flashLed();
  delay(1000);
}

void flashLed() {
  static boolean output = HIGH;
  digitalWrite(LED_PIN, output);
  delay(200);
  output = !output;
}
