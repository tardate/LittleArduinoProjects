/*

  AppleSilicon
  Using the Arduino IDE with Apple Silicon (ARM) machines.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/AppleSilicon

 */

const int LED_PIN = 13;


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
  delay(500);

  output = !output;
}
