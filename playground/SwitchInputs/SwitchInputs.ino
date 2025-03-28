/*

  SwitchInputs

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/SwitchInputs

 */

const int pinA = 2;
const int pinA_led = 3;
const int pinB = 4;
const int pinB_led = 5;
const int pinC = 6;
const int pinC_led = 7;


/*
 * Command: one-time setup
 */
void setup() {
  pinMode(pinA, INPUT);
  pinMode(pinA_led, OUTPUT);
  pinMode(pinB, INPUT);
  pinMode(pinB_led, OUTPUT);
  pinMode(pinC, INPUT_PULLUP);
  pinMode(pinC_led, OUTPUT);
}


/*
 * Command: main loop
 */
void loop() {
  static boolean pinA_state;
  static boolean pinB_state;
  static boolean pinC_state;

  pinA_state = digitalRead(pinA);
  digitalWrite(pinA_led, pinA_state);

  pinB_state = digitalRead(pinB);
  digitalWrite(pinB_led, pinB_state);

  pinC_state = digitalRead(pinC);
  digitalWrite(pinC_led, pinC_state);
}
