/*

  pedalShieldUno/AudioDSP/distortion
  Alternate implementation of the pedalshield_uno_distortion effect.

  - reads the ADC signal and clip it to a threshold value.
  - pressing the pushbutton_1 or 2 turns the distortion harder or softer.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/pedalShieldUno/AudioDSP/distortion

 */


#include <AudioDspDriver.h>  // main AudioDSP controller class

AudioDspDriver dsp_driver;

void setup() {
  dsp_driver.init();
  dsp_driver.pb_level(    // empirical - a good place to start
    map(6000, 0, INT16_MAX, 1024, 0)
  );
}

void loop() {
  dsp_driver.process_controls();
}

/* transformer
 * the input signal is 16 bit signed (values from -32768 to +32767, INT16_MIN to INT16_MAX)
 * pb_level is 0-1024 with midpoint 512
 */
int16_t transformer(int16_t input, int pb_level) {

  int16_t clipping_threshold = map(pb_level, 1024, 0, 0, INT16_MAX);

  if(input > clipping_threshold) return clipping_threshold;
  return input;

}

/* Timer 1 interrupt service routine
 * Perform audio input/processing/output here
 */
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform(&transformer);
}
