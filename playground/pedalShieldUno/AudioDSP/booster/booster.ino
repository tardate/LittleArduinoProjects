/*

  pedalShieldUno/AudioDSP/booster
  Alternate implementation of the pedalshield_uno_booster effect.

  - reads the ADC and plays it into the PWM output.
  - pressing the pushbutton_1 or 2 turns the volume up or down.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/pedalShieldUno/AudioDSP/booster

 */


#include <AudioDspDriver.h>  // main AudioDSP controller class

AudioDspDriver dsp_driver;

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

  int16_t volume = map(pb_level, 0, 1024, 0, INT16_MAX);
  return map(input, INT16_MIN, INT16_MAX, -volume, volume);

}

/* Timer 1 interrupt service routine
 * Perform audio input/processing/output here
 */
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform(&transformer);
}
