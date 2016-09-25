/*

  pedalShieldUno/AudioDSP/delay
  Alternate implementation of the pedalshield_uno_delay effect.

  - reads the ADC, saves it into the DelayBuffer[] array and plays it into the PWM output.
  - pressing the pushbutton_1 or 2 makes the delay longer or shorter

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/pedalShieldUno/AudioDSP/delay

 */


#include <AudioDspDriver.h>  // main AudioDSP controller class

AudioDspDriver dsp_driver;

#define MAX_DELAY (700)
int16_t delay_buffer[MAX_DELAY];
int delay_tail = 0;
int delay_head = 1;
volatile int delay_depth = 2;

void setup() {
  dsp_driver.init();
}

void loop() {
  dsp_driver.process_controls();
  delay_depth = map(dsp_driver.pb_level(), 0, 1024, 0, MAX_DELAY);
}

/* transformer
 * the input signal is 16 bit signed (values from -32768 to +32767, INT16_MIN to INT16_MAX)
 * pb_level is 0-1024 with midpoint 512
 */
int16_t transformer(int16_t input, int pb_level) {

  delay_head++;
  if(delay_head >= delay_depth) delay_head = 0;

  delay_tail++;
  if(delay_tail >= delay_depth) delay_tail = 0;

  delay_buffer[delay_head] = input;

  return input + delay_buffer[delay_tail];

}

/* Timer 1 interrupt service routine
 * Perform audio input/processing/output here
 */
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform(&transformer);
}
