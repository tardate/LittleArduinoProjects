/*

  AudioDSP/SuperCrunch
  A crunchy symmetrical Schetzen distortion effect based on the pedalSHIELD

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/AudioDSP/SuperCrunch

 */

#include <AudioDspDriver.h>  // main AudioDSP controller class

AudioDspDriver dsp_driver;

void setup() {
  dsp_driver.init();
}

void loop() {
  dsp_driver.process_controls();
}

/* SuperCrunch transformer
 * the input signal is 16 bit signed (values from -32768 to +32767, INT16_MIN to INT16_MAX)
 * pb_level is 0-1024 with midpoint 512.
 * the output/transformed value is fuzzed with symmetrical clipping based on Schetzen formula
 * the pb_level controls the output volume
 */
int16_t transformer(int16_t input, int pb_level) {

  int16_t output;

  double x;
  if(input<0) x = 1.0 * input / INT16_MIN;
  else x = 1.0 * input / INT16_MAX;

  // double fx = (3 - pow(2.0 - 3 * x, 3) )/ 3.0;
  // .. but expanded by parts to avoid domain errors:
  double fbase = 2.0 - 3 * x;
  double fx = 1.0 - fbase / 3.0 * fbase * fbase;

  if(x < 0.33) fx = 2 * x;
  else {
    if(x > 0.66) fx = 1;
  }
  output = input * fx;
  return map(output, 0, 1024, 0, pb_level);

}

// Timer 1 interrupt service routine
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform(&transformer);
}
