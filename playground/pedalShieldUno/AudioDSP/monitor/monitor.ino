/*

  pedalShieldUno/AudioDSP/monitor
  Alternate implementation of the pedalshield_uno_monitor effect.

  - reads the ADC and plays it back into the PWM output
  - logs settings to serial port

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/pedalShieldUno/AudioDSP/monitor

 */


#include <AudioDspDriver.h>  // main AudioDSP controller class

AudioDspDriver dsp_driver;

void setup() {
  Serial.begin(115200);
  dsp_driver.init();
}

void loop() {
  dsp_driver.process_controls();
  dump_levels();
}

void dump_levels() {
  cli();
  int16_t current_input = dsp_driver.current_input;
  int16_t current_output = dsp_driver.current_output;
  sei();

  Serial.print(" signal in    : ");Serial.println(current_input, HEX);
  Serial.print(" signal out   : ");Serial.println(current_output, HEX);
  Serial.print(" pb level     : ");Serial.println(dsp_driver.pb_level());
  Serial.print(" toggle switch: ");Serial.println(dsp_driver.toggle_state());
  Serial.print(" foot-switch  : ");Serial.println(dsp_driver.footswitch_state());
  Serial.println();

}

/* Timer 1 interrupt service routine
 * Perform audio input/processing/output here
 */
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform();
}
