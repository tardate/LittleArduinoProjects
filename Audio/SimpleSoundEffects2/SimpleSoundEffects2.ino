/*

  SimpleSoundEffects2
  Building the ATtiny version of the Elektor Simple Sound Effects project, with a port to Arduino/C++.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Audio/SimpleSoundEffects2

 */

const int POT_INPUT_PIN = A1;
const int AUDIO_OUT_PIN = PB4;

volatile uint8_t timer_preset = 203; // called `Preload` in the original program
volatile uint16_t modulation_period = 100; // called `Fd` in the original program


/*
 * Command: setup Timer1
 * Normal port operation, OC0A/OC0B disconnected. Top = 0xFF, 256 prescaler (31.25kHz)
 * Enable Timer1 Overflow Interrupt
 * TCNT1 init to timer_preset
 */
void enableTimer() {
  TCCR1 = _BV(CS13) | _BV(CS10);
  TIMSK = _BV(TOIE1);
  TCNT1 = timer_preset;
}


/*
 * Command: setup the ports and timer
 */
void setup() {
  pinMode(AUDIO_OUT_PIN, OUTPUT);
  digitalWrite(AUDIO_OUT_PIN, LOW);
  enableTimer();
}


/*
 * Command: main loop
 */
void loop() {
  // emulates the original algorithm:
  // uint16_t base_period = map(analogRead(POT_INPUT_PIN), 0, 1023, 200, 3269);
  // timer_preset = map(base_period + modulation_period, 300, 4269, 203,  251);

  // a modified algorithm..
  uint16_t base_period = map(analogRead(POT_INPUT_PIN), 0, 1023, 203, 240);
  timer_preset = map(modulation_period, 100, 1000, base_period, 253);
}


/*
 * Command: oscillator running on Timer1
 */
ISR(TIMER1_OVF_vect) {
  PORTB ^= _BV(4);
  TCNT1 = timer_preset;

  modulation_period += 1;
  if (modulation_period > 1000) {
    modulation_period = 100;
  }
}
