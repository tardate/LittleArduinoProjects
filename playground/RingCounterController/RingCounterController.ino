/*

  RingCounterController
  Control the classic CD4017 walking-ring counter with an Arduino

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/RingCounterController

 */

#define ENABLE_PIN 10
#define CLOCK_PIN 11
#define RESET_PIN 12

#define PULSE_WIDTH 1

void setup() {
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(RESET_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);

  reset();
  clockEnable();
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
  reset();
  delay(500);
  for(int step=0; step<20; step++) pulse();
  reset();
  delay(500);
}

void gradualRamp() {
  int min = 2;
  int max = 100;

  for(int step=max; step>min; step--) {
    pulse();
    delay(step/2);
  }
  for(int step=min; step<=max; step++) {
    pulse();
    delay(step/2);
  }
}

void randomSteps() {
  srand(rand());
  for(int step=0; step<100; step++) {
    pulse();
    delay(rand() % 100);
  }
}

void pulseWhenDisabled() {
  clockDisable();
  for(int step=0; step<100; step++) {
    pulse();
    delay(20);
  }
  clockEnable();
}

void pulse() {
  digitalWrite(CLOCK_PIN, HIGH);
  delay(PULSE_WIDTH);
  digitalWrite(CLOCK_PIN, LOW);
}

void reset() {
  digitalWrite(RESET_PIN, HIGH);
  delay(PULSE_WIDTH);
  digitalWrite(RESET_PIN, LOW);
}

void clockEnable() {
  digitalWrite(ENABLE_PIN, LOW);
}

void clockDisable() {
  digitalWrite(ENABLE_PIN, HIGH);
}
