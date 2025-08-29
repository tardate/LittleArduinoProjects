/*

  AvrHardwarePWM/ATtiny
  Demonstrate hardware PWM with the ATtiny85

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/AvrHardwarePWM/ATtiny

 */

#define SWITCH_PIN         (PB2)
#define SWITCH_READ_PERIOD (15000)

void setup() {
  pinMode(SWITCH_PIN, INPUT);
}

/*
 * The main loop just watches for SWITCH_PIN button-presses
 */
void loop() {
  static int fudged_delay = 0;
  fudged_delay++;
  if (fudged_delay >= SWITCH_READ_PERIOD) {
    fudged_delay = 0;
    if (digitalRead(SWITCH_PIN)) nextMode();
  }
}

/*
 * switch to the next PWM mode
 */
void nextMode() {
  static int mode = 0;
  mode++;

  turnOffAllPwm();

  switch(mode) {
  case 1:
    demoTimer0a();
    break;
  case 2:
    demoTimer0b();
    break;
  case 3:
    demoTimer0c();
    break;
  case 4:
    demoTimer1a();
    break;
  default:
    demoTimer1b();
    mode = 0;
  }

}

/*
 * 0a) Timer0 on PB0 and PB1
 * Fast PWM, TOP=0xFF (WGM01, WGM00)
 * Prescaler: 1 (CS00)
 */
void demoTimer0a() {
  pinMode(PB0, OUTPUT);
  pinMode(PB1, OUTPUT);

  TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
  TCCR0B = _BV(CS00);
  OCR0A = 127;
  OCR0B = 191;
}

/*
 * 0b) Timer0 on PB0 and PB1
 * Phase Correct PWM, TOP=0xFF (WGM00)
 * Prescaler: 1 (CS00)
 */
void demoTimer0b() {
  pinMode(PB0, OUTPUT);
  pinMode(PB1, OUTPUT);

  TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM00);
  TCCR0B = _BV(CS00);
  OCR0A = 127;
  OCR0B = 191;
}

/*
 * 0c) Timer0 on PB0 and PB1
 * Fast PWM, TOP=0xFF (WGM01, WGM00)
 * Prescaler: 64 (CS01, CS00)
 */
void demoTimer0c() {
  pinMode(PB0, OUTPUT);
  pinMode(PB1, OUTPUT);

  TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
  TCCR0B = _BV(CS01) | _BV(CS00);
  OCR0A = 127;
  OCR0B = 191;
}

/*
 * 1a) Timer1 on PB1 and PB4
 * Fast PWM A and B (PWM1A, PWM1B)
 * Prescaler: PCK (CS10)
 */
void demoTimer1a() {
  pinMode(PB1, OUTPUT);
  pinMode(PB4, OUTPUT);

  TCCR1 = _BV(PWM1A) | _BV(COM1A1) | _BV(CS10);
  GTCCR = _BV(PWM1B) | _BV(COM1B1);
  OCR1A = 50;
  OCR1B = 100;
  OCR1C = 127;
}

/*
 * 1b) Timer1 on PB1 and PB4, with complementary output on PB0 and PB3
 * Fast PWM A and B (PWM1A, PWM1B)
 * Prescaler: PCK (CS10)
 * Complementary outputs enabled (COM1A0, COM1B0)
 *  - OC1x cleared on compare match. Set when TCNT1 = $00.
 *  - OC1x set on compare match. Cleared when TCNT1 = $00.
 */
void demoTimer1b() {
  pinMode(PB1, OUTPUT);
  pinMode(PB4, OUTPUT);
  pinMode(PB0, OUTPUT);
  pinMode(PB3, OUTPUT);

  TCCR1 = _BV(PWM1A) | _BV(COM1A0) | _BV(CS10);
  GTCCR = _BV(PWM1B) | _BV(COM1B0);
  OCR1A = 127;
  OCR1B = 100;
  OCR1C = 255;
}

/*
 * Turn off all PWM output.
 * Trick: digitalWrite turns off PWM output
 */
void turnOffAllPwm() {
  digitalWrite(PB0, LOW);
  digitalWrite(PB1, LOW);
  digitalWrite(PB3, LOW);
  digitalWrite(PB4, LOW);
}
