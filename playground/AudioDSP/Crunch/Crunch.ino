/*

  AudioDSP/Crunch
  Simple distortion effect based on the pedalSHIELD examples from from http://www.linse.ufsc.br/.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/AudioDSP/Crunch

 */

#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include <math.h>
#include <AudioDspDriver.h>  // main AudioDSP controller class

AudioDspDriver dsp_driver;

void setup() {
  dsp_driver.init();
}

void loop() {
  dsp_driver.process_controls();
}

/* Crunch transformer
 * the input signal is 16 bit signed (values from -32768 to +32768, INT16_MIN to INT16_MAX)
 * pb_level is 0-1024 with midpoint 512.
 * the output/transformed value is fuzzed with symmetrical clipping based on Schetzen formula
 * the pb_level controls mixing of original/transformed signal
 */
int16_t transformer(int16_t input, int pb_level) {

  if(pb_level==0) return input;

  double x = 1.0 * input / INT16_MAX;

  int16_t fx = (3 - pow(2 - 3 * x, 3)) / 3.0 * input;

  if(pb_level==1024) return fx;

  return map(input, 0, 1024, 0, 1024 - pb_level) + map(fx, 0, 1024, 0, pb_level);

}

// Timer 1 interrupt service routine
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform(&transformer);
}
