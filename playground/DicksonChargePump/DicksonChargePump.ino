/*

  DicksonChargePump
  Zener-regulated 12V Dickson Charge Pump driven with Arduino PWM.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/DicksonChargePump

 */

const int PUMP_A=3;
const int PUMP_B=11;

/*
 * Enable Timer2 Fast PWM on pin 3, 11
 *   NB: pins must be set to OUTPUT for PWM to appear on the pins
 *   Fast PWM  : WGM21 WGM20
 *   Clear OC2A on Compare Match (COM2A1)
 *   Set   OC2B on Compare Match (COM2B1 + COM2B0)
 *   Frequency : 16MHz/1/256 = 62.5kHz (CS20)
 *   Pin 11    : (127+1)/256 = 50% duty cycle (OCR2A)
 *   Pin 3     : (127+1)/256 = 50% duty cycle (OCR2B)
 */
void startPwm() {
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(COM2B0) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS20);
  OCR2A = 127;
  OCR2B = 127;
}

void PwmOn() {
  pinMode(PUMP_A, OUTPUT);
  pinMode(PUMP_B, OUTPUT);
}

void PwmOff() {
  pinMode(PUMP_A, INPUT);
  pinMode(PUMP_B, INPUT);

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
