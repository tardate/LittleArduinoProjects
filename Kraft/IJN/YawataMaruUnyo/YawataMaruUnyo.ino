/*

  YawataMaru/Unyo
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Kraft/IJN/YawataMaruUnyo

 */

const int LEFT_FOREGROUND_LED  = 1;
const int LEFT_BACKGROUND_LED  = 0;
const int RIGHT_FOREGROUND_LED = 3;
const int RIGHT_BACKGROUND_LED = 4;

const int NO_LED = -1;

const int FLICKER_DELAY = 15;
const int FADE_DELAY = 25;
const int PAGE_DELAY = 1000;

const int PWM_MIN = 0;
const int PWM_MAX = 255;


/*
 * Command: one-time setup
 */
void setup() {
  pinMode(LEFT_FOREGROUND_LED, OUTPUT);
  pinMode(LEFT_BACKGROUND_LED, OUTPUT);
  pinMode(RIGHT_FOREGROUND_LED, OUTPUT);
  pinMode(RIGHT_BACKGROUND_LED, OUTPUT);
  digitalWrite(LEFT_FOREGROUND_LED, LOW);
  digitalWrite(LEFT_BACKGROUND_LED, LOW);
  digitalWrite(RIGHT_FOREGROUND_LED, LOW);
  digitalWrite(RIGHT_BACKGROUND_LED, LOW);
  delay(PAGE_DELAY);
}


/*
 * Command: main loop
 */
void loop() {
  featureUnyo();
  featureYawataMaru();
}


void featureYawataMaru() {
  int pin1 = LEFT_FOREGROUND_LED;
  int pin2 = LEFT_BACKGROUND_LED;

  // transition on slow
  fade(pin1, pin2, PWM_MIN, PWM_MAX, 5);

  // effects
  delay(PAGE_DELAY);
  fade(NO_LED, pin2, PWM_MAX, 10, 2);
  delay(PAGE_DELAY * 2);
  fade(NO_LED, pin2, 10, PWM_MAX, 2);
  delay(PAGE_DELAY);

  // transition off slow
  fade(pin1, pin2, PWM_MAX, PWM_MIN, 1);
}


void featureUnyo() {
  int pin1 = RIGHT_FOREGROUND_LED;
  int pin2 = RIGHT_BACKGROUND_LED;

  // transition on fast
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);

  // effects
  flicker(pin2, 9, 3);
  delay(PAGE_DELAY);
  flicker(pin2, 5, 2);
  delay(PAGE_DELAY);
  flicker(pin2, 9, 3);
  delay(PAGE_DELAY);
  flicker(pin2, 6, 4);
  delay(PAGE_DELAY);

  // transition off fast
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}


/*
 * Command: fade 1 or 2 pins PWM level from->to in step increments
 */
 void fade(int pin1, int pin2, int from, int to, int step) {
  if (to > from) {
    fadeOn(pin1, pin2, from, to, step);
  } else {
    fadeOff(pin1, pin2, from, to, step);
  }
}


void fadeOn(int pin1, int pin2, int from, int to, int step) {
  int pwm = from;
  do {
    if (pin1 >= 0) analogWrite(pin1, pwm);
    if (pin2 >= 0) analogWrite(pin2, pwm);
    delay(FADE_DELAY);
    pwm += step;
    if (pwm>to) pwm = to;
  } while (pwm < to);
  if (to == PWM_MAX) {
    if (pin1 >= 0) digitalWrite(pin1, HIGH);
    if (pin2 >= 0) digitalWrite(pin2, HIGH);
  }
}


void fadeOff(int pin1, int pin2, int from, int to, int step) {
  int pwm = from;
  do {
    if (pin1 >= 0) analogWrite(pin1, pwm);
    if (pin2 >= 0) analogWrite(pin2, pwm);
    delay(FADE_DELAY);
    pwm -= step;
    if (pwm<to) pwm = to;
  } while (pwm > to);
  if (to == PWM_MIN) {
    if (pin1 >= 0) digitalWrite(pin1, LOW);
    if (pin2 >= 0) digitalWrite(pin2, LOW);
  }
}


void flicker(int pin, int times, int rate) {
  for (int i = times; i > 0; --i) {
    digitalWrite(pin, LOW);
    delay(FLICKER_DELAY * i / rate);
    digitalWrite(pin, HIGH);
    delay(FLICKER_DELAY * i / rate);
  }
}
