#ifndef MotorSubsystem_h
#define MotorSubsystem_h

#define STEP_DELAY 500
#define WALK_LR_OFFSET 30
#define WALK_CENTER 90
#define WALK_LEFT WALK_CENTER - WALK_LR_OFFSET
#define WALK_RIGHT WALK_CENTER + WALK_LR_OFFSET

#ifdef ENABLE_MOTOR_SUBSYSTEM

Servo myservo;

void centerServo() {
  myservo.write(90);
}

void setupMotorSystem() {
  myservo.attach(MOTOR_CONTROL_PIN);
  centerServo();
}

void walkSingleStep(int left_limit, int right_limit) {
  myservo.write(left_limit);
  delay(STEP_DELAY);
  myservo.write(right_limit);
  delay(STEP_DELAY);
}

void walkAhead() {
  walkSingleStep(WALK_LEFT,WALK_RIGHT);
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
void walkLeft() {
}
void walkRight() {
}

#endif

#endif
