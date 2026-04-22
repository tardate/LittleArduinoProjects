/*

  OR Gate with NAND Logic

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/NandLogic/OR

 */

const int PIN_A = 2;
const int PIN_B = 3;
const int DELAY = 500;


/*
 * Command: one-time setup
 */
void setup() {
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
}


/*
 * Command: main loop
 */
void loop() {
  for (uint8_t input = 0; input < 4; input++) {
    digitalWrite(PIN_B, input & 0b01);
    digitalWrite(PIN_A, input >> 1 & 0b01);
    delay(DELAY);
  }
}
