/*

  ShiftRegister

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/CD4027/ShiftRegister

 */

const int DATA_PIN = 4;
const int CLOCK_PIN = 5;
const int RESET_PIN = 6;
const int TOGGLE_DELAY = 10;
const int SHORT_DELAY = 90;
const int LONG_DELAY = 990;


/*
 * Command: one-time setup
 */
void setup() {
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(RESET_PIN, OUTPUT);
  digitalWrite(DATA_PIN, LOW);
  digitalWrite(CLOCK_PIN, LOW);
  digitalWrite(RESET_PIN, LOW);
}


/*
 * Command: main loop
 */
void loop() {
  reset();
  for (int num = 0b0001; num <= 0b1111; num++) {
    shiftNumber(num);
  }
}

/*
 * Command: toggle a pin high/low
 */
void toggleHighLow(int pin) {
  digitalWrite(pin, HIGH);
  delay(TOGGLE_DELAY);
  digitalWrite(pin, LOW);
}

/*
 * Command: trigger reset
 */
void reset() {
  toggleHighLow(RESET_PIN);
  delay(LONG_DELAY);
}


void shiftBit(int level) {
  digitalWrite(DATA_PIN, level);
  toggleHighLow(CLOCK_PIN);
}


void shiftNumber(int num) {
  for (int bit = 0; bit <= 3; bit++) {
    int level = (num >> bit) & 1;
    shiftBit(level);
    delay(SHORT_DELAY);
  }
  delay(LONG_DELAY);
}
