/*

  AT89C2051/Blinky
  Simple LED blinker on P1_0. Uses do-nothing loop to approximate 1Hz cycle.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/8051/AT89C2051/Blinky

 */

#define MICROCONTROLLER_AT89CX051
#include <mcs51reg.h>


/*
 * Command: delay for a bit.
 * this just wastes time in a NOP loop
 */
void delay(void)
{
    int i, j;
    for(i=0; i<0xff; i++)
        for(j=0; j<0xff; j++);
}


/*
 * Implements main loop that just toggles P1_0
 */
void main(void)
{
    while(1) {
         P1_0 = 1;
         delay();
         P1_0 = 0;
         delay();
    }
}

