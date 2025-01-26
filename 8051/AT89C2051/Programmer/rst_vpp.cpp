#include "rst_vpp.h"

/*
 * Command: setup charge pump
 * Enable Timer2 Fast PWM on pin 3, 11
 *   NB: pins must be set to OUTPUT for PWM to appear on the pins
 *   Fast PWM  : WGM21 WGM20
 *   Clear OC2A on Compare Match (COM2A1)
 *   Set   OC2B on Compare Match (COM2B1 + COM2B0)
 *   Frequency : 16MHz/1/256 = 62.5kHz (CS20)
 *   Pin 11    : (127+1)/256 = 50% duty cycle (OCR2A)
 *   Pin 3     : (127+1)/256 = 50% duty cycle (OCR2B)
 */
void RST_VPP::setup(void) {
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(COM2B0) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS20);
  OCR2A = 127;
  OCR2B = 127;
  pinMode(RST_PIN, OUTPUT);
  setVoltage(0);
}

// set RST/VPP pin to 12V, 5V or (default) 0V
void RST_VPP::setVoltage(uint8_t voltage) {
  delay(1);
  switch(voltage) {
  case 12:
    digitalWrite(RST_PIN, HIGH);
    on();
    break;
  case 5:
    off();
    digitalWrite(RST_PIN, HIGH);
    break;
  default:
    off();
    digitalWrite(RST_PIN, LOW);
  }
  delay(1);
}

// enable charge pump
void RST_VPP::on(void) {
  pinMode(PUMP_A_PIN, OUTPUT);
  pinMode(PUMP_B_PIN, OUTPUT);
}

// disable charge pump
void RST_VPP::off(void) {
  pinMode(PUMP_A_PIN, INPUT);
  pinMode(PUMP_B_PIN, INPUT);
}
