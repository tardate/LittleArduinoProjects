/*

  RingCounterController
  Control the classic CD4017 walking-ring counter with an Arduino

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/RingCounterController

 */

#include "ring_counter.h"

#define ENABLE_PIN 10
#define CLOCK_PIN 11
#define RESET_PIN 12

RingCounter ring_counter(CLOCK_PIN, ENABLE_PIN, RESET_PIN);

void setup() {
  ring_counter.init();
}

void loop() {
  indicateNextTest();
  gradualRamp();

  indicateNextTest();
  randomSteps();

  indicateNextTest();
  pulseWhenDisabled();
}

void indicateNextTest() {
  ring_counter.reset();
  delay(500);
  for(int step=0; step<20; step++) ring_counter.pulse();
  ring_counter.reset();
  delay(500);
}

void gradualRamp() {
  int min = 2;
  int max = 100;

  for(int step=max; step>min; step--) {
    ring_counter.pulse();
    delay(step/2);
  }
  for(int step=min; step<=max; step++) {
    ring_counter.pulse();
    delay(step/2);
  }
}

void randomSteps() {
  srand(rand());
  for(int step=0; step<100; step++) {
    ring_counter.pulse();
    delay(rand() % 100);
  }
}

void pulseWhenDisabled() {
  ring_counter.disable();
  for(int step=0; step<100; step++) {
    ring_counter.pulse();
    delay(20);
  }
  ring_counter.enable();
}
