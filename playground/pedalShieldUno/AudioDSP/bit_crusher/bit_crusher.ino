/*

  pedalShieldUno/AudioDSP/bit_crusher
  Alternate implementation of the pedalshield_uno_bit_crusher effect.

  - reads the ADC and shift the bits creating a high distorted sound.
  - pressing the pushbutton_1 or 2 turns the bit shift harder or softer.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/pedalShieldUno/AudioDSP/bit_crusher

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

  int16_t bit_crush = map(pb_level, 0, 1024, 0, 15);

  return input << bit_crush;

}

/* Timer 1 interrupt service routine
 * Perform audio input/processing/output here
 */
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform(&transformer);
}
