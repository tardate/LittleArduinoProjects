/*

  ATtiny/SoftwarePWM
  Generating arbitrary PWM signals with an ATtiny85 and bit-banging techniques.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/ATtiny/SoftwarePWM

 */

#define TIMER_CLOCK_PRESCALAR     (_BV(CS12) | _BV(CS11))        // div 32
#define TIMER_TICKS_PER_INTERRUPT (F_CPU/1000000 * 16.7/32 - 1)  // approx 16.7µs increments

const uint16_t pwm_1_hi_low_counts[] = {48, 0}; // number of interrupt cycles high, low -> implies frequency and duty
volatile uint8_t pwm_1_step = 0;                // tracks whether doing high or low
volatile uint16_t pwm_1_counter = 0;            // current counter

const uint16_t pwm_2_hi_low_counts[] = {12, 3}; // as above, but for the second PWM signal
volatile uint8_t pwm_2_step = 0;
volatile uint16_t pwm_2_counter = 0;

#define LED_PIN         (PB1)
#define PWM_1_PIN       (PB0)
#define PWM_2_PIN       (PB2)


/*
 * Set the pins for output and start Timer1 interrutps
 */
void setup() {
  pinMode(PWM_1_PIN, OUTPUT);
  pinMode(PWM_2_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  initTimer1();
}


/*
 * The main loop toggles another GPIO just to prove we have some cycles left for other things
 */
void loop() {
  static boolean output = HIGH;

  digitalWrite(LED_PIN, output);
  delay(500);

  output = !output;
}


/*
 * Setup Timer1 to call our ISR at a preset frequency
 */
void initTimer1(void) {
  TCCR1 =
    _BV(CTC1)                        // clear timer on compare match
    | TIMER_CLOCK_PRESCALAR;         // set clock prescaler
  OCR1C = TIMER_TICKS_PER_INTERRUPT;
  TIMSK |= _BV(OCIE1A);              // enable compare match interrupt
}


/*
 * The Timer1 ISR. Calculates when to toggle the two PWM signals.
 * Tries to use as few clock cycles here as possible.
 */
ISR(TIMER1_COMPA_vect) {
  if(pwm_1_counter) --pwm_1_counter;
  else {
    if(pwm_1_step) PORTB |= _BV(PWM_1_PIN);
    else PORTB &= ~(_BV(PWM_1_PIN));
    pwm_1_step = !pwm_1_step;
    pwm_1_counter = pwm_1_hi_low_counts[pwm_1_step];
  }

  if(pwm_2_counter) --pwm_2_counter;
  else {
    if(pwm_2_step) PORTB |= _BV(PWM_2_PIN);
    else PORTB &= ~(_BV(PWM_2_PIN));
    pwm_2_step = !pwm_2_step;
    pwm_2_counter = pwm_2_hi_low_counts[pwm_2_step];
  }
}
