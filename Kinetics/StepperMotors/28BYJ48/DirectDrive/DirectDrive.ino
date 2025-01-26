/*

  StepperMotors/28BYJ48/DirectDrive
  Demonstrates direct drive using full, half and double steps - one rotation clockwise and counter-clockwise each.
  This is mainly helpful for ensuring the board/circuit behaves as expected.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Kinetics/StepperMotors/28BYJ48/DirectDrive

 */

static const int STEPS_PER_REVOLUTION = 32 * 64;

static const int PIN_IN1_BLUE         = 8;
static const int PIN_IN2_PINK         = 9;
static const int PIN_IN3_YELLOW       = 10;
static const int PIN_IN4_ORANGE       = 11;

static const int STEPS_DELAY          = 4;
static const int DEMO_DELAY           = 500;

boolean clockwise = true;
int step = 0;


//
// Command: updates global step given miximum steps allowed
//
void nextStep(int max_step) {
  if (clockwise) {
    if (step == max_step) {
      step = 0;
    } else {
      ++step;
    }
  } else {
    if (step == 0) {
      step = max_step;
    } else {
      --step;
    }
  }

}


//
// Setup: enable pins
//
void setup() {
  pinMode(PIN_IN1_BLUE, OUTPUT);
  pinMode(PIN_IN2_PINK, OUTPUT);
  pinMode(PIN_IN3_YELLOW, OUTPUT);
  pinMode(PIN_IN4_ORANGE, OUTPUT);
}


//
// Main loop: runs each "demo" in sequence then repeats
//
void loop() {
  fullStepDemo();
  halfStepDemo();
  doubleStepDemo();
}


//
// Runs the double-step demo. Double stepping is not an effective operating mode
// but it does confirm the opposing coils are correctly matched
// * steps/revolution is halved
// * delay per stp is floored at 30ms - any faster and this mode does not work
//
void doubleStepDemo() {
  for(int i=0; i < STEPS_PER_REVOLUTION / 2; ++i) {
    clockwise = true;
    doubleStep();
    delay(30);
  }
  delay(DEMO_DELAY);

  for(int i=0; i < STEPS_PER_REVOLUTION / 2; ++i) {
    clockwise = false;
    doubleStep();
    delay(30);
  }
  delay(DEMO_DELAY);
}

void doubleStep() {

  switch(step) {
    case 0:
      if (clockwise) {
        digitalWrite(PIN_IN1_BLUE, HIGH);
        digitalWrite(PIN_IN2_PINK, LOW);
      } else {
        digitalWrite(PIN_IN1_BLUE, LOW);
        digitalWrite(PIN_IN2_PINK, HIGH);
      }
      digitalWrite(PIN_IN3_YELLOW, LOW);
      digitalWrite(PIN_IN4_ORANGE, LOW);

      break;
    case 1:
      digitalWrite(PIN_IN1_BLUE, LOW);
      digitalWrite(PIN_IN2_PINK, LOW);
      if (clockwise) {
        digitalWrite(PIN_IN3_YELLOW, HIGH);
        digitalWrite(PIN_IN4_ORANGE, LOW);
      } else {
        digitalWrite(PIN_IN3_YELLOW, LOW);
        digitalWrite(PIN_IN4_ORANGE, HIGH);
      }
      break;
  }

  nextStep(1);

}


//
// Run the full-step demo
//
void fullStepDemo() {
  for(int i=0; i < STEPS_PER_REVOLUTION; ++i) {
    clockwise = true;
    fullStep();
    delay(STEPS_DELAY);
  }
  delay(DEMO_DELAY);

  step=3; //counter clockwise rotation should start with the 4th step
  for(int i=0; i < STEPS_PER_REVOLUTION; ++i) {
    clockwise = false;
    fullStep();
    delay(STEPS_DELAY);
  }
  delay(DEMO_DELAY);
}

void fullStep() {

  switch(step) {
    case 0:
      digitalWrite(PIN_IN1_BLUE, HIGH);
      digitalWrite(PIN_IN2_PINK, HIGH);
      digitalWrite(PIN_IN3_YELLOW, LOW);
      digitalWrite(PIN_IN4_ORANGE, LOW);
      break;
    case 1:
      digitalWrite(PIN_IN1_BLUE, LOW);
      digitalWrite(PIN_IN2_PINK, HIGH);
      digitalWrite(PIN_IN3_YELLOW, HIGH);
      digitalWrite(PIN_IN4_ORANGE, LOW);
      break;
    case 2:
      digitalWrite(PIN_IN1_BLUE, LOW);
      digitalWrite(PIN_IN2_PINK, LOW);
      digitalWrite(PIN_IN3_YELLOW, HIGH);
      digitalWrite(PIN_IN4_ORANGE, HIGH);
      break;
    case 3:
      digitalWrite(PIN_IN1_BLUE, HIGH);
      digitalWrite(PIN_IN2_PINK, LOW);
      digitalWrite(PIN_IN3_YELLOW, LOW);
      digitalWrite(PIN_IN4_ORANGE, HIGH);
      break;
  }

  nextStep(3);

}

//
// Run the half-step demo
// * steps/revolution are doubled
// * halves the delay per step to produce approximately the same rpm as full step
//
void halfStepDemo() {
  for(int i=0; i < STEPS_PER_REVOLUTION * 2; ++i) {
    clockwise = true;
    halfStep();
    delay(STEPS_DELAY / 2);
  }
  delay(DEMO_DELAY);

  for(int i=0; i < STEPS_PER_REVOLUTION * 2; ++i) {
    clockwise = false;
    halfStep();
    delay(STEPS_DELAY / 2);
  }
  delay(DEMO_DELAY);
}

void halfStep() {

  switch(step) {
    case 0:
      digitalWrite(PIN_IN1_BLUE, HIGH);
      digitalWrite(PIN_IN2_PINK, HIGH);
      digitalWrite(PIN_IN3_YELLOW, LOW);
      digitalWrite(PIN_IN4_ORANGE, LOW);
      break;
    case 1:
      digitalWrite(PIN_IN1_BLUE, LOW);
      digitalWrite(PIN_IN2_PINK, HIGH);
      digitalWrite(PIN_IN3_YELLOW, LOW);
      digitalWrite(PIN_IN4_ORANGE, LOW);
      break;
    case 2:
      digitalWrite(PIN_IN1_BLUE, LOW);
      digitalWrite(PIN_IN2_PINK, HIGH);
      digitalWrite(PIN_IN3_YELLOW, HIGH);
      digitalWrite(PIN_IN4_ORANGE, LOW);
      break;
    case 3:
      digitalWrite(PIN_IN1_BLUE, LOW);
      digitalWrite(PIN_IN2_PINK, LOW);
      digitalWrite(PIN_IN3_YELLOW, HIGH);
      digitalWrite(PIN_IN4_ORANGE, LOW);
      break;
    case 4:
      digitalWrite(PIN_IN1_BLUE, LOW);
      digitalWrite(PIN_IN2_PINK, LOW);
      digitalWrite(PIN_IN3_YELLOW, HIGH);
      digitalWrite(PIN_IN4_ORANGE, HIGH);
      break;
    case 5:
      digitalWrite(PIN_IN1_BLUE, LOW);
      digitalWrite(PIN_IN2_PINK, LOW);
      digitalWrite(PIN_IN3_YELLOW, LOW);
      digitalWrite(PIN_IN4_ORANGE, HIGH);
      break;
    case 6:
      digitalWrite(PIN_IN1_BLUE, HIGH);
      digitalWrite(PIN_IN2_PINK, LOW);
      digitalWrite(PIN_IN3_YELLOW, LOW);
      digitalWrite(PIN_IN4_ORANGE, HIGH);
      break;
    case 7:
      digitalWrite(PIN_IN1_BLUE, HIGH);
      digitalWrite(PIN_IN2_PINK, LOW);
      digitalWrite(PIN_IN3_YELLOW, LOW);
      digitalWrite(PIN_IN4_ORANGE, LOW);
      break;
  }

  nextStep(7);
}
