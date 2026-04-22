/*

  MUX Gate with NAND Logic

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/NandLogic/MUX

 */

const int PIN_A = 2;
const int PIN_B = 3;
const int PIN_S = 4;
const int DELAY = 250;


/*
 * Command: one-time setup
 */
void setup() {
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_S, OUTPUT);
}


/*
 * Command: main loop
 */
void loop() {
  for (uint8_t input = 0; input < 8; input++) {
    digitalWrite(PIN_B, input & 0b01);
    digitalWrite(PIN_A, input >> 1 & 0b01);
    digitalWrite(PIN_S, input >> 2 & 0b01);
    delay(DELAY);
  }
}
