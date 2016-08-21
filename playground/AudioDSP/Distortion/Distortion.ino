/*

  AudioDSP/Distortion
  Simple distortion effect based on the pedalSHIELD examples.

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
 * the input signal is 16bits (values from -32768 to +32768
 * the value is clipped to the pb_level value
 */
int transformer(int input, int pb_level) {

  int scaled_level = map(pb_level, 1024, 0, 0, 32768);

  if (input>scaled_level) return pb_level;
  else {
    if(input<-scaled_level) return -pb_level;
    else return input;
  }

}

// Timer 1 interrupt service routine
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform(&transformer);
}