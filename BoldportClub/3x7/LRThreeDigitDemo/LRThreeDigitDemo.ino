/*

  3x7/LRThreeDigitDemo
  Driving the Boldport 3x7 display from a Cuttle (Arduino) and the LRThreeDigits library.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/BoldportClub/3x7/LRThreeDigitDemo

 */

#include <LRThreeDigits.h>

namespace ltd = lr::ThreeDigits;


void setup() {
    // Initialize the driver.
    ltd::initialize(ltd::Frequency::Fast);
}


void loop() {
    // Count from 0 to 999 and repeat.
    char buffer[10];
    for (uint16_t i = 0; i < 1000; ++i) {
        sprintf(buffer, "%3d", i);
        ltd::setDigits(buffer);
        delay(100);
    }
}
