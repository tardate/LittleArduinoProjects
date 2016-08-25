/*

  AudioDSP/Crunch
  Simple distortion (asymmetrical Schetzen clipping) effect.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/AudioDSP/Crunch

 */

#include <AudioDspDriver.h>  // main AudioDSP controller class

AudioDspDriver dsp_driver;

void setup() {
  dsp_driver.init();
}

void loop() {
  dsp_driver.process_controls();
}

/* Crunch transformer
 * the input signal is 16 bit signed (values from -32768 to +32767, INT16_MIN to INT16_MAX)
 * pb_level is 0-1024 with midpoint 512.
 * the output/transformed value is fuzzed with asymmetrical clipping based on Schetzen formula
 * the pb_level controls the output volume
 */
int16_t transformer(int16_t input, int pb_level) {
  int16_t output;
  uint16_t uinput = input + 0x8000;

  double x = 1.0 * uinput / UINT16_MAX;
  //double fx = 1 - pow(2.0 - 3 * x, 3) / 3.0;
  // .. but expanded by parts to avoid domain errors:
  double fbase = 2.0 - 3 * x;
  double fx = 1 - fbase / 3.0 * fbase * fbase;


  if(x>fx) output = uinput * 2 - 0x8000;
  else {
    if(fx>1) fx = 1;
    output = UINT16_MAX * fx - 0x8000;
  }
  return map(output, 0, 1024, 0, pb_level);
}

// Timer 1 interrupt service routine
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform(&transformer);
}
