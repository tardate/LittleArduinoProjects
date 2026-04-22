/*

  NOT Gate with NAND Logic

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/NandLogic/NOT

 */

const int PIN_A = 2;
const int DELAY = 1000;


/*
 * Command: one-time setup
 */
void setup() {
  pinMode(PIN_A, OUTPUT);
}


/*
 * Command: main loop
 */
void loop() {
  static boolean output = LOW;

  digitalWrite(PIN_A, output);
  delay(DELAY);

  output = !output;
}
