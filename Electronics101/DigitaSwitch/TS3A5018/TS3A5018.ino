/*

  DigitaSwitch/TS3A5018
  Run a simple example demonstrating the TS3A5018 digital switch

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/DigitaSwitch/TS3A5018

 */

const int SIGNAL_PIN = 2;
const int DELAY      = 5000;

void setup() {
  pinMode(SIGNAL_PIN, OUTPUT);
}

void loop() {
  static boolean output = HIGH;

  digitalWrite(SIGNAL_PIN, output);
  delay(DELAY);

  output = !output;
}
