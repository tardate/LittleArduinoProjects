/*

  OnePinThreeV

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/Power/DicksonChargePump/OnePinThreeV

 */

const int PUMP_PIN=11;
const int MODE_DELAY=100;

/*
 * Enable Timer2 Fast PWM on pin 11
 *   NB: pins must be set to OUTPUT for PWM to appear on the pins
 *   Fast PWM  : WGM21 WGM20
 *   Clear OC2A on Compare Match (COM2A1)
 *   OC2B disconnected
 *   Frequency : 16MHz/1/256 = 62.5kHz (CS20)
 *   Pin 11    : (127+1)/256 = 50% duty cycle (OCR2A)
 */
void startPwm() {
  TCCR2A = _BV(COM2A1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS20);
  OCR2A = 127;
}

void stopPwm() {
  TCCR2A = 0;
  TCCR2B = 0;
}

void setOutputPwm() {
  startPwm();
}

void setOutputHigh() {
  stopPwm();
  digitalWrite(PUMP_PIN, HIGH);
}

void setOutputLow() {
  stopPwm();
  digitalWrite(PUMP_PIN, LOW);
}

void setup() {
  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {
  setOutputLow();
  delay(MODE_DELAY);
  setOutputHigh();
  delay(MODE_DELAY);
  setOutputPwm();
  delay(MODE_DELAY);
}
