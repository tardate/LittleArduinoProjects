/*
  QuadNOR
  Demo cascading NOR gate logic.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/QuadNOR

 */

#define INPUT_A1 6
#define INPUT_B1 7
#define INPUT_A2 8
#define INPUT_B2 9
#define STEP_DELAY 135

void setup() {
  pinMode(INPUT_A1, OUTPUT);
  pinMode(INPUT_B1, OUTPUT);
  pinMode(INPUT_A2, OUTPUT);
  pinMode(INPUT_B2, OUTPUT);
}

void loop() {
  for (int i=0; i<16; i++) {
    digitalWrite(INPUT_A1, i & 1);
    digitalWrite(INPUT_B1, i & 2);
    digitalWrite(INPUT_A2, i & 4);
    digitalWrite(INPUT_B2, i & 8);
    delay(STEP_DELAY);
  }
}
