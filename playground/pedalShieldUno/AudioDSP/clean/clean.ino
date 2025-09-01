/*

  pedalShieldUno/AudioDSP/clean
  Alternate implementation of the pedalshield_uno_clean effect.

  - reads the ADC and plays it back into the PWM output.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/pedalShieldUno/AudioDSP/clean

 */


#include <AudioDspDriver.h>  // main AudioDSP controller class

AudioDspDriver dsp_driver;

void setup() {
  dsp_driver.init();
}

void loop() {
  dsp_driver.process_controls();
}

/* Timer 1 interrupt service routine
 * Perform audio input/processing/output here
 */
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform();
}
