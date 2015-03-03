/*

  PrecisionTimer
  Comparing the precision and constraints of various methods for timing an operation with an Atmega328.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/PrecisionTimer

 */

#include "MicroTimer2.h"

const uint8_t BUTTON_INTERRUPT_PIN = 2;
bool button_pressed = false;


unsigned long millis_start;
unsigned long millis_stop;
unsigned long micros_start;
unsigned long micros_stop;
float micro2_start;
float micro2_stop;

/*
 * Command: one-time setup
 */
void setup() {
  Serial.begin(115200);
  enableIntA();

  Serial.println("PrecisionTimer");
  Serial.println("* press the button to start and stop a timing operation");
}


/*
 * Command: main loop
 */
void loop() {
  static bool running = false;

  if (button_pressed) {
    if (running) {
      // end timing run
      stopTimers();
      reportTiming();
      running = false;
    } else {
      // start timing run
      startTimers();
      running = true;
    }
    // reset the button
    delay(500);
    button_pressed = false;
  }
}


/*
 * Command: start timers and record the start count
 */
void startTimers() {
  millis_start = millis();
  micros_start = micros();
  micro2_start = microTimer2.micros();

  Serial.print("Timing started .. ");
}


/*
 * Command: stop timers and record the end count
 */
void stopTimers() {
  millis_stop = millis();
  micros_stop = micros();
  micro2_stop = microTimer2.micros();

  Serial.println("timing ended.");
}


/*
 * Command: report timing results for he various methods
 */
void reportTiming(){
  Serial.println("Results:");

  Serial.print("millis: ");
  Serial.print(millis_stop - millis_start);
  Serial.println("ms");

  Serial.print("micros: ");
  Serial.print(micros_stop - micros_start);
  Serial.print("us, ");
  Serial.print((float)(micros_stop - micros_start)/1000);
  Serial.println("ms");

  Serial.print("microTimer2: ");
  Serial.print(micro2_stop - micro2_start);
  Serial.print("us, ");
  Serial.print((float)(micro2_stop - micro2_start)/1000);
  Serial.println("ms");

}


/*
 * Command: enable hardware interrupt from button
 */
void enableIntA() {
  pinMode(BUTTON_INTERRUPT_PIN, INPUT_PULLUP);
  delay(200);
  attachInterrupt(digitalPinToInterrupt(BUTTON_INTERRUPT_PIN), handleButtonInterrupt, FALLING);
}


/*
 * Command: button interrupt handler
 */
void handleButtonInterrupt() {
  if (!button_pressed) {
    button_pressed = true;
  }
}
