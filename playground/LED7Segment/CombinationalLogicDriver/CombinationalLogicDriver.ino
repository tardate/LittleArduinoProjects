/*

  LED7Segment/CombinationalLogicDriver
  Generate an 8421-BCD sequence to automate the demonstration of the 7-segment LED driver.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/LED7Segment/CombinationalLogicDriver

 */

const int PIN_w = 2;
const int PIN_x = 3;
const int PIN_y = 4;
const int PIN_z = 5;
const int STEP_DELAY = 500;

void setup() {
  pinMode(PIN_w, OUTPUT);
  pinMode(PIN_x, OUTPUT);
  pinMode(PIN_y, OUTPUT);
  pinMode(PIN_z, OUTPUT);
}

void loop() {
  for (int d=0; d<10; ++d) {
    digitalWrite(PIN_w, (d & 0b1000) > 0);
    digitalWrite(PIN_x, (d & 0b0100) > 0);
    digitalWrite(PIN_y, (d & 0b0010) > 0);
    digitalWrite(PIN_z, (d & 0b0001) > 0);
    delay(STEP_DELAY);
  }
}
