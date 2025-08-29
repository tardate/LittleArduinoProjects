/*

  AT89C2051/Blinky
  Simple LED blinker on P1_0. Uses do-nothing loop to approximate 1Hz cycle.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/8051/AT89C2051/Blinky

 */

#define MICROCONTROLLER_AT89CX051
#include <mcs51/mcs51reg.h>

const int DELAY = 1000;

void ms_delay(unsigned int ms);

/*
 * Implements main loop that just toggles P1_0
 */
void main(void)
{
  while(1) {
    P1_0 = 1;
    ms_delay(DELAY);
    P1_0 = 0;
    ms_delay(DELAY);
  }
}

/*
 * Command: delay for a specified time in milliseconds
 * This is calibrated for the processor running @ 16MHz
 */
void ms_delay(unsigned int ms) {
  for(unsigned int i=0; i<ms; i++) {
    for(unsigned int j=0; j<186; j++);
  }
}
