/*

  pedalShieldUno/AudioDSP/tremelo
  Alternate implementation of the pedalshield_uno_tremelo effect.

  - creates a tremolo effect, modulating the volume with a sinewave.
  - pressing the pushbutton_1 or 2 makes the modulation faster or slower.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/pedalShieldUno/AudioDSP/tremelo

 */


#include <AudioDspDriver.h>  // main AudioDSP controller class
#include "waveform.h"

AudioDspDriver dsp_driver;
int sample = 0;
int step = 0;

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

  int adjustment = map(pb_level, 0, 1024, 9, 0);
  step++;
  if(step >= adjustment) {
    step = 0;
    sample++;
    if(sample>1023) sample = 0;
  }

  int16_t volume = map(waveform[sample], 0, 0xFF, 0, INT16_MAX);
  return map(input, INT16_MIN, INT16_MAX, -volume, volume);

}

/* Timer 1 interrupt service routine
 * Perform audio input/processing/output here
 */
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform(&transformer);
}
