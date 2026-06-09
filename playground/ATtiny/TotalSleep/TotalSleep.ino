/*

  TotalSleep
  Test a total power shutdown with an ATtiny85 processor on a breadboard

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/ATtiny/TotalSleep

 */

const int POWER_PIN = PB0; // ATtiny pin 5
const int LED_PIN = PB4; // ATtiny pin 3

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
  // switch the power-pin to high-impedance input state
  pinMode(POWER_PIN, INPUT);
  while(true) {
    // do nothing, just wait for the power-down
  }
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
