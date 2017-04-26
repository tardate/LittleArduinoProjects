/*

  FM/TEA5767
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/FM/TEA5767

 */

const int XX_PIN=13;

void setup() {
  pinMode(XX_PIN, OUTPUT);
}

void loop() {
  static boolean output = HIGH;

  digitalWrite(XX_PIN, output);
  delay(500);

  output = !output;
}

