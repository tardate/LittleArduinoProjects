/*

  pedalShieldUno/AudioDSP/daft_punk_octaver
  Alternate implementation of the pedalshield_uno_daft_punk_octaver effect.

  - reads the ADC and plays it into the PWM output.
  - pressing the pushbutton_1 or 2 turns the volume up or down.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/pedalShieldUno/AudioDSP/daft_punk_octaver

 */


#include <AudioDspDriver.h>  // main AudioDSP controller class

AudioDspDriver dsp_driver;
volatile int trigger = 0;
volatile int16_t last_output = 0;

void setup() {
  dsp_driver.init();
  dsp_driver.pb_level(10);
}

void loop() {
  dsp_driver.process_controls();
}

/* transformer
 * the input signal is 16 bit signed (values from -32768 to +32767, INT16_MIN to INT16_MAX)
 * pb_level is 0-1024 with midpoint 512
 */
int16_t transformer(int16_t input, int pb_level) {

  trigger++;
  if(trigger>=pb_level) {
    trigger=0;
    last_output = input;
    return last_output;
  } else {
    return last_output;
  }

}

/* Timer 1 interrupt service routine
 * Perform audio input/processing/output here
 */
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform(&transformer);
}
