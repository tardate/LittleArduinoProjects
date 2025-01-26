/*

  LedCurrentControl
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/LedCurrentControl

 */

const int POT_INPUT_PIN = A0;
const int LED_PIN = 6;
const int STEP_DELAY = 50;

const int PWM_MIN = 120;
const int PWM_MAX = 255;


/*
 * Command: one-time setup
 */
void setup() {
  pinMode(LED_PIN, OUTPUT);
}


/*
 * Command: main loop
 */
void loop() {
  int pwm_level = map(analogRead(POT_INPUT_PIN), 0, 1023, PWM_MIN, PWM_MAX);
  analogWrite(LED_PIN, pwm_level);
  delay(STEP_DELAY);
}
