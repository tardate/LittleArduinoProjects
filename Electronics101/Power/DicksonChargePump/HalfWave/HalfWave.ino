/*

  DicksonChargePump
  Zener-regulated 12V Dickson Charge Pump driven with Arduino PWM using a single pin.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/Power/DicksonChargePump/HalfWave

 */

const int PUMP_PIN=11;

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

void PwmOn() {
  pinMode(PUMP_PIN, OUTPUT);
}

void PwmOff() {
  pinMode(PUMP_PIN, INPUT);

}

void setup() {
  startPwm();
}

void loop() {
  PwmOn();
  delay(5000);
  PwmOff();
  delay(5000);
}
