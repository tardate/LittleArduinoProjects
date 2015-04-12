#ifndef MotorSubsystem_h
#define MotorSubsystem_h

int walkCounter = 0;
int pauseCounter = 0;

#ifdef ENABLE_MOTOR_SUBSYSTEM

#define STEP_DELAY 500
#define WALK_LR_OFFSET 50
#define WALK_CENTER 90
#define WALK_LEFT WALK_CENTER - WALK_LR_OFFSET
#define WALK_RIGHT WALK_CENTER + WALK_LR_OFFSET

// custom min/max pulse width settings that best suit my servos
// NB: default vaules are min pulse width=544, max pulse width=2400
#define IDEAL_MIN_PW 600
#define IDEAL_MAX_PW 2320

Servo myservo;

void centerServo() {
  myservo.write(90);
}

void setupMotorSystem() {
  myservo.attach(MOTOR_CONTROL_PIN, IDEAL_MIN_PW, IDEAL_MAX_PW);
  centerServo();
}

void walkSingleStep(int left_limit, int right_limit) {
  myservo.write(left_limit);
  delay(STEP_DELAY);
  myservo.write(right_limit);
  delay(STEP_DELAY);
}

void walkAhead() {
  if(pauseCounter <= 0) {
    walkCounter = random(2, 6);
    pauseCounter = walkCounter;
  }
  if(walkCounter-- > 0) {
    walkSingleStep(WALK_LEFT,WALK_RIGHT);
  } else {
    if(pauseCounter-- > 0) {
      delay(STEP_DELAY * 2);
    }
  }
}

void stopWalking() {
  walkCounter = 0;
  delay(STEP_DELAY * 2);
}

void walkLeft() {
  walkSingleStep(WALK_LEFT,WALK_CENTER);
}

void walkRight() {
  walkSingleStep(WALK_CENTER,WALK_RIGHT);
}

#else
// NOP functions for when motors disabled

void setupMotorSystem() {
}
void walkAhead() {
}
void stopWalking() {
}
void walkLeft() {
}
void walkRight() {
}

#endif

#endif
