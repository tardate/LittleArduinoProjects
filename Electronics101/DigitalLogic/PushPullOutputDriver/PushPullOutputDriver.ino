/*

  PushPullOutputDriver

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/DigitalLogic/PushPullOutputDriver

 */

const int LED_PIN = 9;
const int DELAY = 1000;


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
