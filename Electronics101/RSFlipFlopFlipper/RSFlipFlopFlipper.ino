/*

  RSFlipFlopFlipper

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/RSFlipFlopFlipper

 */

#include <FlexiTimer2.h>                // use timer for sampling to get even time base for data

const int SET_PIN = 6;
const int RESET_PIN = 7;

const int READ_OUT1_PIN = A0;
const int READ_OUT2_PIN = A1;

void setup() {
  Serial.begin(115200);                 // initialize serial communications (to match that used by PlotNValues.pde)

  pinMode(SET_PIN, OUTPUT);
  pinMode(RESET_PIN, OUTPUT);

  FlexiTimer2::set(10, sample);         // set sampling procedure on timer interrupt
  FlexiTimer2::start();
}

#define TRIGGER_DELAY 500
#define TRIGGER_DURATION 40

volatile int set_state = 0;
volatile int reset_state = 0;

void loop() {
  // run a set/reset test sequence
  pressSet();
  pressSet();
  pressReset();
  pressSet();
  pressReset();
  pressReset();
  pressSet();
  pressReset();
}

void pressSet() {
  set_state = 1023;
  digitalWrite(SET_PIN, HIGH);
  delay(TRIGGER_DURATION);
  digitalWrite(SET_PIN, LOW);
  set_state = 0;
  delay(TRIGGER_DELAY);
}

void pressReset() {
  reset_state = 1023;
  digitalWrite(RESET_PIN, HIGH);
  delay(TRIGGER_DURATION);
  digitalWrite(RESET_PIN, LOW);
  reset_state = 0;
  delay(TRIGGER_DELAY);
}

// read the current value and send to the serial port
// sending raw value (0-1023) because that is what PlotNValues expects.
void sample() {
  String result = "";
  Serial.println(result + set_state + "," + reset_state + "," + analogRead(READ_OUT1_PIN) + "," + analogRead(READ_OUT2_PIN));
}
