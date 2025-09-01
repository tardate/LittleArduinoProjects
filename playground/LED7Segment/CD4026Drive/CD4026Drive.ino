/*

  LED7Segment/CD4026Drive
  Driving a 7-segment display with CD4026 Counter

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/LED7Segment/CD4026Drive

 */

#include <FlexiTimer2.h>

#define CD4026_CLOCK_PIN 8
#define CD4026_RESET_PIN 9
#define STEP_DELAY 1000

void setup() {
  pinMode(CD4026_CLOCK_PIN, OUTPUT);
  pinMode(CD4026_RESET_PIN, OUTPUT);

  sendReset();

  FlexiTimer2::set(STEP_DELAY, sendPulse);
  FlexiTimer2::start();
}

void loop() {
  // NOP
}

/*
  send a single clock pulse to the counter
 */
void sendPulse() {
  digitalWrite(CD4026_CLOCK_PIN, HIGH);
  digitalWrite(CD4026_CLOCK_PIN, LOW);
}

void sendReset() {
  digitalWrite(CD4026_RESET_PIN, HIGH);
  digitalWrite(CD4026_RESET_PIN, LOW);
}
