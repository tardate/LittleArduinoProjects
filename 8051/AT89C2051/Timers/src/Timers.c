/*

  AT89C2051/Timers
  Simple LED blinker using timers to set the frequency.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/8051/AT89C2051/Timers

 */

#define MICROCONTROLLER_AT89CX051
#include <mcs51/mcs51reg.h>

#define CPU_MHZ (16)
#define TIMER_TICKS_PER_MS ((CPU_MHZ * 1000000UL) / 12 / 1000)
#define MAX_STEPS_PER_TIMER_CYCLE (0xFFFF / TIMER_TICKS_PER_MS)
#define DELAY (500)

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
 * Command: delay for a specified time in milliseconds.
 */
void ms_delay(unsigned int ms) {
  TMOD = 0x01; // timer 0, mode 1, 16 bit mode

  unsigned int counter;
  unsigned int step = MAX_STEPS_PER_TIMER_CYCLE;

  while (ms > 0) {
    if (ms < step) step = ms;
    ms -= step;

    counter = 0xFFFF - step * TIMER_TICKS_PER_MS + 1;
    TL0 = counter & 0xFF; // Low byte
    TH0 = (counter >> 8) & 0xFF; // High byte
    TR0 = 1; // timer on
    while (!TF0); // wait until overflow
    TR0 = 0; // timer off
    TF0 = 0; // clear flag
  }
}
