/*

  DelayOn

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/555Timer/DelayOn

 */

const int LED_PIN = 13;
const int DELAY = 500;


/*
 * Command: one-time setup
 */
void setup() {
  pinMode(LED_PIN, OUTPUT);
}


/*
 * Command: main loop
 */
void loop() {
  static boolean output = HIGH;

  digitalWrite(LED_PIN, output);
  delay(DELAY);

  output = !output;
}
