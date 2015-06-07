/*

  BJTCurrentSink
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/BJTCurrentSink

 */

#define XX_PIN 13

void setup() {
  pinMode(XX_PIN, OUTPUT);
}

void loop() {
  static boolean output = HIGH;

  digitalWrite(XX_PIN, output);
  output = !output;
}

