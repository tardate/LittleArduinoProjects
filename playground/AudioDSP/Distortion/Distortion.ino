/*

  AudioDSP/Distortion
  Simple distortion (clipping) effect.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/AudioDSP/Distortion

 */


#include <AudioDspDriver.h>  // main AudioDSP controller class

AudioDspDriver dsp_driver;

void setup() {
  dsp_driver.init();
}

void loop() {
  dsp_driver.process_controls();
}

/* distortion transformer
 * the input signal is 16 bit signed (values from -32768 to +32767, INT16_MIN to INT16_MAX)
 * pb_level is 0-1024 with midpoint 512
 * the output/transformed value is clipped to the |pb_level| value
 */
int16_t transformer(int16_t input, int pb_level) {

  int16_t clipping_threshold = map(pb_level, 1024, 0, 0, INT16_MAX);

  if(input > clipping_threshold) return clipping_threshold;
  if(input < -clipping_threshold) return -clipping_threshold;
  return input;

}

// Timer 1 interrupt service routine
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform(&transformer);
}
