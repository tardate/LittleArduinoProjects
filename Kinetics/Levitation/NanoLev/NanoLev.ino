/*

  NanoLev

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Kinetics/Levitation/NanoLev

 */

volatile boolean toggle_flag = false;

/*
 * ISR: timer1 interrupt 80kHz toggles pin A0-A1 and A2-A3
 * generates pulse wave of frequency 80kHz/2 = 40kHz (takes two cycles for full wave)
 */
ISR(TIMER2_COMPA_vect) {
  if (toggle_flag) {
    PORTC = 0b00000101;
    toggle_flag = false;
  } else {
    PORTC = 0b00001010;
    toggle_flag = true;
  }
}

/*
 * Command: one-time setup
 */
void setup() {
  DDRC = 0b00001111; // A0 to A3 are the signal outputs
  PORTC = 0b00000000;

  cli();

  // set timer2 interrupt at 80kHz
  TCCR2A = 0; // set entire TCCR2A register to 0
  TCCR2B = 0; // same for TCCR2B
  TCNT2  = 0; // initialize counter value to 0
  OCR2A = 24; // (16*10^6) / (80000*8) - 1 (must be <256) // set compare match register
  TCCR2A |= (1 << WGM21);  // turn on CTC mode
  TCCR2B |= (1 << CS21);   // Set CS21 bit for 8 prescaler
  TIMSK2 |= (1 << OCIE2A); // enable timer compare interrupt

  sei();
}


/*
 * Command: main loop
 */
void loop() {
  // NOP
}
