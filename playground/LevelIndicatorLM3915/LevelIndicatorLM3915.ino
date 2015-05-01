/*

  LevelIndicatorLM3915
  Drive a 10-segment display with a single Arduino pin

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/LevelIndicatorLM3915

 */

#define STEP_DELAY 10

// Arduino 5V - the actual "5V" provided by the Arduino
const int VMAX_MV = 4930;

// LM3915 VREF - the voltage at which the last LED should light
const int VREF_MV = 2530;

const int SIG_PIN = 6;
const int MODE_PIN = 7;

void setup() {
  Serial.begin(9600);
  pinMode(SIG_PIN, OUTPUT);
  pinMode(MODE_PIN, OUTPUT);
}

void loop() {
  digitalWrite(MODE_PIN, LOW);
  bounceSequence();
  digitalWrite(MODE_PIN, HIGH);
  bounceSequence();
  delay(1000);
}

void bounceSequence() {
  int vout;
  for(int v=0; v < VREF_MV; v=v+10) {
    analogWrite(SIG_PIN, map(v, 0, VMAX_MV, 0, 255) );
    delay(STEP_DELAY);
  }
  for(int v=VREF_MV; v > 0; v=v-10) {
    analogWrite(SIG_PIN, map(v, 0, VMAX_MV, 0, 255) );
    delay(STEP_DELAY);
  }
}
