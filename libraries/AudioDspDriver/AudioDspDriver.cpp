#include "AudioDspDriver.h"


AudioDspDriver::AudioDspDriver() {
  reset();
}


void AudioDspDriver::reset() {
  this->led_pin = DEFAULT_LED_PIN;
  this->footswitch_pin = DEFAULT_FOOTSWITCH_PIN;
  this->toggle_pin = DEFAULT_TOGGLE_PIN;
  this->pb_left_pin = DEFAULT_PUSHBUTTON_LEFT_PIN;
  this->pb_right_pin = DEFAULT_PUSHBUTTON_RIGHT_PIN;
  this->pb_step = DEFAULT_PUSHBUTTON_STEP;
  this->pwm_freq = DEFAULT_PWM_FREQ;
  this->pwm_mode = DEFAULT_PWM_MODE;
  this->pwm_qty = DEFAULT_PWM_QTY;
  this->pb_level_value = 512;
  this->current_input = 0;
  this->current_output = 0;
}


void AudioDspDriver::init() {
  // setup IO - inputs/outputs pins configurations and pull-ups
  pinMode(led_pin, OUTPUT);
  pinMode(footswitch_pin, INPUT_PULLUP);
  pinMode(toggle_pin, INPUT_PULLUP);
  pinMode(pb_left_pin, INPUT_PULLUP);
  pinMode(pb_right_pin, INPUT_PULLUP);
  init_adc();
  init_pwm();
  sei();
}


void AudioDspDriver::init_adc() {
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
}


void AudioDspDriver::init_pwm() {

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
  TCCR1A = (((pwm_qty - 1) << 5) | 0x80 | (pwm_mode << 1));

  /* TCCR1B: Timer/Counter1 Control Register B
   * WGM13: Waveform Generation Mode = 1
   * WGM12: Waveform Generation Mode = PWM_MODE
   * Clock Select = 1 = clk/1 (no prescaling)
   */
  TCCR1B = ((pwm_mode << 3) | 0x11);

  /* TIMSK1: Timer/Counter1 Interrupt Mask Register
   * 0x20 =
   * ICIE1 not enabled: Timer/Counter1, Input Capture Interrupt Enable
   * OCIE1A enabled: Timer/Counter1, Output Compare A Match Interrupt Enable
   */
  TIMSK1 = 0x20;

  /* ICR1H and ICR1L: Input Capture Register 1
   * The Input Capture is updated with the counter (TCNT1) value each time an event occurs on the ICP1 pin (or optionally on the Analog
   * Comparator output for Timer/Counter1). The Input Capture can be used for defining the counter TOP value.
   */
  ICR1H = (pwm_freq >> 8);
  ICR1L = (pwm_freq & 0xff);

  /* DDRB: The Port B Data Direction Register
   */
  DDRB |= ((pwm_qty << 1) | 0x02); // turn on outputs

}


void AudioDspDriver::process_controls() {
  process_footswitch();
  process_pushbuttons();
  process_toggle();
}


void AudioDspDriver::process_footswitch() {
  this->footswitch_value = digitalRead(footswitch_pin);
  led(footswitch_value);
}

void AudioDspDriver::process_toggle() {
  this->toggle_value = digitalRead(toggle_pin);
}


void AudioDspDriver::process_pushbuttons() {

  if (!digitalRead(pb_right_pin)) {
    // increase when pressing right
    if (pb_level_value<1024) this->pb_level_value += pb_step;
  }
  if (!digitalRead(pb_left_pin)) {
    // decrease when pressing left
    if (pb_level_value>0) this->pb_level_value -= pb_step;
  }

}


void AudioDspDriver::led(bool state) {
  digitalWrite(led_pin, state);
}


int16_t AudioDspDriver::read() {
  uint8_t ADC_low, ADC_high;

  // read the ADC input signal data: 2 bytes Low and High.
  // Low byte needs to be fetched first
  ADC_low = ADCL;
  ADC_high = ADCH;

  // construct the input sample summing the ADC low and high byte.
  this->current_input = ((ADC_high << 8) | ADC_low) - 0x8000; // make a signed 16b value
  this->current_output = this->current_input;
  return current_output;
}


void AudioDspDriver::write() {
  // write the PWM output signal
  OCR1AL = ((current_output + 0x8000) >> 8); // convert to unsigned, send out high byte
  OCR1BL = current_output; // send out low byte
}


void AudioDspDriver::transform() {
  read();
  write();
}


void AudioDspDriver::transform(int16_t (*transformer)(int16_t, int)) {
  read();
  this->current_output = (*transformer)(current_output, pb_level_value);
  write();
}


void AudioDspDriver::pb_level(int new_level) {
  this->pb_level_value = new_level;
}

int AudioDspDriver::pb_level() {
  return pb_level_value;
}

bool AudioDspDriver::toggle_state() {
  return (bool)toggle_value;
}

bool AudioDspDriver::footswitch_state() {
  return (bool)footswitch_value;
}
