/*

  CD4047/AstableOscillator
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/CD4047/AstableOscillator

 */

#define XX_PIN 13

void setup() {
  pinMode(XX_PIN, OUTPUT);
}

void loop() {
  static boolean output = HIGH;

  digitalWrite(XX_PIN, output);
  delay(500);

  output = !output;
}
