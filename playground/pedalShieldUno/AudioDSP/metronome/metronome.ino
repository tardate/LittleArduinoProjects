/*

  pedalShieldUno/AudioDSP/metronome
  Alternate implementation of the pedalshield_uno_metronome effect.

  - plays a beep (togheter with the LED) like a metronome.
  - pressing the pushbutton_1 or 2 changes the speed.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/pedalShieldUno/AudioDSP/metronome

 */


#include <AudioDspDriver.h>  // main AudioDSP controller class
#include "waveform.h"

AudioDspDriver dsp_driver;
const int BEEP_LENGTH_MS = 50;
int sample = 0;

void setup() {
  dsp_driver.init();
}

void loop() {
  dsp_driver.process_controls();
  play_beep();
}

/* play_beep
 * enable the interrupts long enough to play a beep
 */
void play_beep() {
  dsp_driver.led(HIGH);
  sei();
  delay(BEEP_LENGTH_MS);
  dsp_driver.led(LOW);
  cli();
  delay(((uint16_t)1024 - dsp_driver.pb_level()) << 6);
}

/* transformer
 * the input signal is 16 bit signed (values from -32768 to +32767, INT16_MIN to INT16_MAX)
 * pb_level is 0-1024 with midpoint 512
 * the output/transformed value is clipped to the |pb_level| value
 */
int16_t transformer(int16_t input, int pb_level) {

  input = waveform[sample] << 8 | waveform[sample];

  sample = sample + 20;
  if(sample>=1023) sample = 0;

  return input;

}

/* Timer 1 interrupt service routine
 * Perform audio input/processing/output here
 */
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform(&transformer);
}
