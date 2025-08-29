/*

  pedalShieldUno/AudioDSP/signal_generator
  Alternate implementation of the pedalshield_uno_signal_generator effect.

  - plays a provided waveform.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/pedalShieldUno/AudioDSP/signal_generator

 */


#include <AudioDspDriver.h>  // main AudioDSP controller class
#include "waveform.h"

AudioDspDriver dsp_driver;
int sample = 0;

void setup() {
  dsp_driver.init();
}

void loop() {
  dsp_driver.process_controls();
}

/* transformer
 * the input signal is 16 bit signed (values from -32768 to +32767, INT16_MIN to INT16_MAX)
 * pb_level is 0-1024 with midpoint 512
 */
int16_t transformer(int16_t input, int pb_level) {

  input = waveform[sample] << 8 | waveform[sample];

  sample = sample + 20;
  if(sample>=1023) sample = 0;

  return input;
}

/* Timer 1 interrupt service routine
 * Perform audio input/processing/output here
 */
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform(&transformer);
}
