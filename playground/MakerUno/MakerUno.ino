/*

  MakerUno
  A quick demo of some of the on-board features of the Maker UNO

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/MakerUno

 */

const int TONE_PIN = 8;
const int BUTTON_PIN = 2;
const int STEP_DELAY = 250;

uint8_t leds[]   = {  3,   4,   5,   6,   7,   9,  10,  11,  12,  13};
uint16_t tones[] = {131, 147, 165, 175, 196, 220, 247, 262, 294, 330};
uint8_t max_step = sizeof(leds) - 1;
int8_t step = 0;
volatile int8_t step_delta = 1;


/*
 * Calculate the next step (going up or down)
 */
void nextStep() {
  step += step_delta;
  if(step > max_step) step = 0;
  if(step < 0) step = max_step;
}


/*
 * On button press (falling interrupt), reverse direction
 */
void reverseDirection() {
  if(step_delta == 1) step_delta = -1;
  else step_delta = 1;
}


/*
 * setup: initialise pins and set interrupt handler for the button
 */
void setup() {
  for(int pin_index = 0; pin_index <= max_step; ++pin_index) {
    pinMode(leds[pin_index], OUTPUT);
  }
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), reverseDirection, FALLING);
}


/*
 * loop: play a tone and light an LED, then go to next step
 */
void loop() {
  tone(TONE_PIN, tones[step], STEP_DELAY);
  digitalWrite(leds[step], HIGH);
  delay(STEP_DELAY);
  digitalWrite(leds[step], LOW);
  delay(STEP_DELAY);
  nextStep();
}
