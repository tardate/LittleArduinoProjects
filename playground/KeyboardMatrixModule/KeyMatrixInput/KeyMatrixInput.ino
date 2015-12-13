/*

  KeyboardMatrixModule/KeyMatrixInput
  Demo multiplexed key input on a simple pushbutton/LED matrix module

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/KeyboardMatrixModule/KeyMatrixInput

 */

const int START_L_PIN=2;
const int START_R_PIN=6;
const int MATRIX_SIZE=4;
const int POLL_DELAY=150;

void setup() {
  Serial.begin(9600);
  // set the L pins as output LOW by default
  for(int lpin = START_L_PIN; lpin < START_L_PIN + MATRIX_SIZE; ++lpin) {
    pinMode(lpin, OUTPUT);
    digitalWrite(lpin, HIGH);
  }
  // set the R pins as input with pullup (normally high)
  for(int rpin = START_R_PIN; rpin < START_R_PIN + MATRIX_SIZE; ++rpin) {
    pinMode(rpin, INPUT_PULLUP);
  }
  Serial.println(F("Scanning for key presses.."));
}

void loop() {
  scanKeyMatrix();
  delay(POLL_DELAY);
}

void scanKeyMatrix() {
  for(int lpin = START_L_PIN; lpin < START_L_PIN + MATRIX_SIZE; ++lpin) {
    // pull a set of L keys LOW
    digitalWrite(lpin, LOW);
    for(int rpin = START_R_PIN; rpin < START_R_PIN + MATRIX_SIZE; ++rpin) {
      // see if any corresponding R inputs are LOW
      if(!digitalRead(rpin)) {
        // key is pressed
        int key = (lpin - START_L_PIN) * MATRIX_SIZE + rpin - START_R_PIN + 1;
        Serial.print(F("Key pressed: K"));
        Serial.println(key);
      }
    }
    digitalWrite(lpin, HIGH);
  }
}

