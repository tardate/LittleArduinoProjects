/*

  DigitalLogic/DFlipFlop
  Simple sketch to provide a ~10Hz data signal for testing a D Flip-flop

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/DigitalLogic/DFlipFlop

 */

const int SIGNAL_PIN = 4;

void setup() {
  pinMode(SIGNAL_PIN, OUTPUT);
}

void loop() {
  static boolean output = HIGH;

  digitalWrite(SIGNAL_PIN, output);
  delay(50);

  output = !output;
}
