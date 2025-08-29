/*

  AvrHardwarePWM/ATmega
  Demonstrate hardware PWM with the Arduino UNO/ATmega328

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/AvrHardwarePWM

 */

#define SWITCH_PIN         (12)
#define SWITCH_READ_PERIOD (25000)

/*
 * initialise pins and Serial comms.
 * Send intial PWM register values to serial.
 */
void setup() {
  pinMode(SWITCH_PIN, INPUT);
  Serial.begin(115200);
  Serial.println("Reset..");
  printPwmRegisters();
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
    demoTimer2b();
    break;
  case 2:
    demoTimer1a();
    break;
  case 3:
    demoTimer1b();
    break;
  case 4:
    demoTimer0a();
    break;
  default:
    demoTimer2a();
    mode = 0;
  }

  printPwmRegisters();
}

void demoTimer0a() {
  Serial.println("0a> Switching to Timer0 on pin 5, 6");
  Serial.println("  Fast PWM  : WGM01 WGM00");
  Serial.println("  Clear OC0A/OC0B on Compare Match, set OC0A/OC0B at BOTTOM (COM0A1/COM0B1)");
  Serial.println("  Frequency : 16MHz/64/256 = 977Hz (CS01 CS00)");
  Serial.println("  Pin 6     : (127+1)/256 = 50% duty cycle (OCR0A)");
  Serial.println("  Pin 5     : (191+1)/256 = 75% duty cycle (OCR0B)");

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
  TCCR0B = _BV(CS01) | _BV(CS00);
  OCR0A = 127;
  OCR0B = 191;
}

void demoTimer1a() {
  Serial.println("1a> Switching to Timer1 on pin 9, 10");
  Serial.println("  Fast PWM, 10-bit : WGM12 WGM11 WGM10");
  Serial.println("  Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM (COM1A1/COM1B1)");
  Serial.println("  Frequency : 16MHz/8/0x3FF = 1955Hz (CS11)");
  Serial.println("  Pin 9     : (510+1)/0x3FF = 50% duty cycle (OCR1A)");
  Serial.println("  Pin 10    : (766+1)/0x3FF = 75% duty cycle (OCR1B)");

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM11) | _BV(WGM10);
  TCCR1B = _BV(CS11) | _BV(WGM12);
  OCR1A = 510;
  OCR1B = 766;
}

void demoTimer1b() {
  Serial.println("1b> Switching to Timer1 on pin 9, 10");
  Serial.println("  Phase Correct PWM, 8-bit : WGM10");
  Serial.println("  Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM (COM1A1/COM1B1)");
  Serial.println("  Frequency : 16MHz/8/0xFF/2 = 3906Hz (CS11)");
  Serial.println("  Pin 9     : (127)/0xFF = 50% duty cycle (OCR1A)");
  Serial.println("  Pin 10    : (191)/0xFF = 75% duty cycle (OCR1B)");

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);
  TCCR1B = _BV(CS11);
  OCR1A = 127;
  OCR1B = 191;
}

void demoTimer2a() {
  Serial.println("2a> Switching to Timer2 on pin 3, 11");
  Serial.println("  Fast PWM  : WGM21 WGM20");
  Serial.println("  Clear OC2A/OC2B on Compare Match (COM2A1/COM2B1)");
  Serial.println("  Frequency : 16MHz/1/256 = 62.5kHz (CS20)");
  Serial.println("  Pin 11    : (127+1)/256 = 50% duty cycle (OCR2A)");
  Serial.println("  Pin 3     : (191+1)/256 = 75% duty cycle (OCR2B)");

  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);

  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS20);
  OCR2A = 127;
  OCR2B = 191;
}

void demoTimer2b() {
  Serial.println("2b> Switching to Timer2 on pin 3, 11");
  Serial.println("  Fast PWM  : WGM21 WGM20");
  Serial.println("  Clear OC2A/OC2B on Compare Match (COM2A1/COM2B1)");
  Serial.println("  Frequency : 16MHz/64/256 = 977Hz (CS22)");
  Serial.println("  Pin 11    : (127+1)/256 = 50% duty cycle (OCR2A)");
  Serial.println("  Pin 3     : (191+1)/256 = 75% duty cycle (OCR2B)");

  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);

  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS22);
  OCR2A = 127;
  OCR2B = 191;
}

/*
 * print all the PWM-related register current settings
 */
void printPwmRegisters() {
  Serial.print("GTCCR: "); Serial.println(GTCCR, BIN);

  Serial.print("TCCR0A : "); Serial.println(TCCR0A, BIN);
  Serial.print("TCCR0B : "); Serial.println(TCCR0B, BIN);
  Serial.print("OCR0A  : "); Serial.println(OCR0A, BIN);
  Serial.print("OCR0B  : "); Serial.println(OCR0B, BIN);

  Serial.print("TCCR1A : "); Serial.println(TCCR1A, BIN);
  Serial.print("TCCR1B : "); Serial.println(TCCR1B, BIN);
  Serial.print("OCR1A  : "); Serial.println(OCR1A, BIN);
  Serial.print("OCR1B  : "); Serial.println(OCR1B, BIN);

  Serial.print("TCCR2A : "); Serial.println(TCCR2A, BIN);
  Serial.print("TCCR2B : "); Serial.println(TCCR2B, BIN);
  Serial.print("OCR2A  : "); Serial.println(OCR2A, BIN);
  Serial.print("OCR2B  : "); Serial.println(OCR2B, BIN);

  Serial.print("\n");
}

/*
 * Turn off all PWM output.
 * Trick: digitalWrite turns off PWM output
 */
void turnOffAllPwm() {
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}
