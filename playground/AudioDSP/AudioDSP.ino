/*

  AudioDSP
  Simple clean boost/volume control example.
  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/AudioDSP

  Based on Electrosmash and OpenMusicLabs previous works:

  CC-by-www.Electrosmash.com
  Based on OpenMusicLabs previous works.
  pedalshield_uno_booster.ino: pressing the pushbutton_1 or 2 turns the volume up or down.

 */


// define harware resources.
  #define LED 13
  #define FOOTSWITCH 12
  #define TOGGLE 2
  #define PUSHBUTTON_1 A5
  #define PUSHBUTTON_2 A4

// define output PWM parameters
  #define PWM_FREQ 0x00FF // pwm frequency - 31.3KHz
  #define PWM_MODE 0 // Fast (1) or Phase Correct (0)
  #define PWM_QTY 2 // 2 PWMs in parallel

// signal variables
  volatile int volume=512;
  volatile int input;


void setup() {

  // setup IO - inputs/outputs pins configurations and pull-ups
  pinMode(FOOTSWITCH, INPUT_PULLUP);
  pinMode(TOGGLE, INPUT_PULLUP);
  pinMode(PUSHBUTTON_1, INPUT_PULLUP);
  pinMode(PUSHBUTTON_2, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  // setup ADC - configured to be reading automatically the whole time.
  ADMUX = 0x60;  /* ADC Multiplexer Selection Register = b01100000
                  * REFS[1:0] = 01 = AVCC with external capacitor at AREF pin
                  * ADLAR: ADC Left Adjust Result = 1
                  * MUX[3:0]: Analog Channel Selection Bits = 0 = ADC0
                  */
  ADCSRA = 0xe5; /* ADC Control and Status Register A = b11100101
                  * ADEN: ADC Enable
                  * ADSC: ADC Start Conversion
                  * ADATE: ADC Auto Trigger Enable
                  * ADPS[2:0] ADC Prescaler = CLOCK/32
                  */
  ADCSRB = 0x07; /* ADC Control and Status Register B = b00000111
                  * ADTS[2:0]: ADC Auto Trigger Source = 111 = Timer/Counter1 Capture Event
                  */
  DIDR0 = 0x01;  /* Digital Input Disable Register 0
                  * ADC0D digital input buffer for adc0 disabled
                  */

  /*
   * setup PWM - for more info about this config check the forum.
   *
   * PWM_MODE      | 0 | 1 |
   * --------------|---|---|
   * WGM13         | 1 | 1 |
   * WGM12 (CTC1)  | 0 | 1 |
   * WGM11 (PWM11) | 0 | 1 |
   * WGM10 (PWM10) | 0 | 0 |
   * Mode          | PWM, Phase and Frequency Correct | Fast PWM |
   * TOP           | ICR1 | ICR1 |
   */

  /* TCCR1A: Timer/Counter1 Control Register A
   * COM1A1:0: Compare Output Mode for Channel A = 10 = Clear OC1A on Compare Match
   * COM1B1:0: Compare Output Mode for Channel B = (PWM_QTY - 1) << 5 = 10 for PWM_QTY = 2 = Clear OC1B on Compare Match
   * WGM11:0: Waveform Generation Mode = PWM_MODE << 1
   */
  TCCR1A = (((PWM_QTY - 1) << 5) | 0x80 | (PWM_MODE << 1));

  /* TCCR1B: Timer/Counter1 Control Register B
   * WGM13: Waveform Generation Mode = 1
   * WGM12: Waveform Generation Mode = PWM_MODE
   * Clock Select = 1 = clk/1 (no prescaling)
   */
  TCCR1B = ((PWM_MODE << 3) | 0x11);

  /* TIMSK1: Timer/Counter1 Interrupt Mask Register
   * 0x20 = OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable
   */
  TIMSK1 = 0x20;

  /* ICR1H and ICR1L: Input Capture Register 1
   * The Input Capture is updated with the counter (TCNT1) value each time an event occurs on the ICP1 pin (or optionally on the Analog  * Comparator output for Timer/Counter1). The Input Capture can be used for defining the counter TOP value.
   */
  ICR1H = (PWM_FREQ >> 8);
  ICR1L = (PWM_FREQ & 0xff);

  /* DDRB: The Port B Data Direction Register
   */
  DDRB |= ((PWM_QTY << 1) | 0x02); // turn on outputs
  sei(); // turn on interrupts - not really necessary with arduino

}

/*
 * Main loop - process input buttons
 */
void loop() {
  static int scaler = 0;
  scaler++;
  if (scaler<100) return;

  process_footswitch();
  process_pushbuttons();

}


/*
 * Turn on the LED if the effect is ON.
 */
void process_footswitch() {

  if (digitalRead(FOOTSWITCH)) digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW);

}


/*
 * Pushbuttons control the volume up/down
 */
void process_pushbuttons() {

  if (!digitalRead(PUSHBUTTON_1)) {
    // increase the vol
    if (volume<1024) volume=volume+1;
  }
  if (!digitalRead(PUSHBUTTON_2)) {
    // decrease vol
    if (volume>0) volume=volume-1;
  }

}


// Timer 1 interrupt service routine
ISR(TIMER1_CAPT_vect) {

  uint8_t ADC_low, ADC_high;

  // read the ADC input signal data: 2 bytes Low and High.
  // Low byte needs to be fetched first
  ADC_low = ADCL;
  ADC_high = ADCH;

  // construct the input sample summing the ADC low and high byte.
  input = ((ADC_high << 8) | ADC_low) - 0x8000; // make a signed 16b value

  // the amplitude of the signal is modified following the volume
  input = map(input, 0, 1024, 0, volume);

  // write the PWM output signal
  OCR1AL = ((input + 0x8000) >> 8); // convert to unsigned, send out high byte
  OCR1BL = input; // send out low byte

}
