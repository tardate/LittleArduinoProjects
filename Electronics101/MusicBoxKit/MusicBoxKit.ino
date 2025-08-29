/*

  MusicBoxKit
  Run an automated demo of the sounds provided by the MusicBox module.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/MusicBoxKit

 */

const int MASTER_CONTROL = 8;
const int CRTL_PINS[] = {7, 6, 5, 4};  // DCBA

#define SAMPLE_DURATION (2000)
#define SAMPLE_DELAY    (500)
#define CYCLE_DELAY     (5000)

void setup() {
  pinMode(MASTER_CONTROL, OUTPUT);
  for (int pin = 0; pin < 4; pin++) {
    pinMode(CRTL_PINS[pin], OUTPUT);
  }
  digitalWrite(MASTER_CONTROL, LOW);
}

void loop() {

  for(int i = 0; i < 16; i++) {
    for (int pin = 0; pin < 4; pin++) {
      digitalWrite(CRTL_PINS[pin], (i & (1 << pin)) > 0);
    }
    digitalWrite(MASTER_CONTROL, HIGH);
    delay(SAMPLE_DURATION);
    digitalWrite(MASTER_CONTROL, LOW);
    delay(SAMPLE_DELAY);
  }
  delay(CYCLE_DELAY);

}
