/*

  cordwood/aanimate
  Run a demo animation using aaronjasso's Cordwood library

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/BoldportClub/cordwood/aanimate

 */

#include <FlexiTimer2.h>
#include <Cordwood.h>

// using the analog pins for digital out, as they are the
// only 6 GPIO pins in an unbroken sequence directly tapped from
// the ATmega328
Cordwood cw(A0, A1, A2, A3, A4, A5);

const byte MODES = 3;
volatile byte mode = 0;

void setup() {
  // Note: the Cordwood library takes care of GPIO setup.

  FlexiTimer2::set(6000, switch_modes);
  FlexiTimer2::start();
}

void loop() {

  switch(mode) {
  case 1:
    cw.wheel(3);
    break;
  case 2:
    cw.bounce(5);
    break;
  default:
    cw.chase(3);
  }

}

void switch_modes() {
  if(mode < MODES - 1) mode++;
  else mode = 0;
  cw.allOff();
}
