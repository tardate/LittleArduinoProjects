/*

  AudioDSP/Boost
  Simple clean boost/volume control example.
  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/AudioDSP/Boost

  Based on Electrosmash and OpenMusicLabs previous works:

  CC-by-www.Electrosmash.com
  Based on OpenMusicLabs previous works.
  pedalshield_uno_booster.ino: pressing the pushbutton_1 or 2 turns the volume up or down.


 */

#include <AudioDspDriver.h>  // main AudioDSP controller class

AudioDspDriver dsp_driver;

void setup() {
  dsp_driver.init();
}

void loop() {
  dsp_driver.process_controls();
}

// Timer 1 interrupt service routine
ISR(TIMER1_CAPT_vect) {
  dsp_driver.transform();
}
