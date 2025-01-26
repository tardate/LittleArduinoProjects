/*

  ATtiny/PwmMotorControl
  Variable speed PWM motor control with an ATtiny85.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ATtiny/PwmMotorControl

 */

const int PWM_OUT_PIN = 0; // ATtiny85 DIP8: PB0, pin 5
const int PWM_LEVEL_PIN = A1; // ATtiny85 DIP8: pin 7
const int STEP_DELAY = 100;

/*
 * Command: one-time setup
 */
void setup() {
  pinMode(PWM_OUT_PIN, OUTPUT);
  pinMode(PWM_LEVEL_PIN, INPUT);
}

/*
 * Command: main loop
 */
void loop() {
  update_pwm();
  delay(STEP_DELAY);
}

/*
 * Command: read pot level and set PMW level
 */
void update_pwm() {
  int pwm_level = map(analogRead(PWM_LEVEL_PIN), 0, 1023, 0, 255);
  analogWrite(PWM_OUT_PIN, pwm_level);
}
