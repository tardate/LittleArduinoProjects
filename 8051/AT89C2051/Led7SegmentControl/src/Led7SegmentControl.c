/*

  AT89C2051/Led7SegmentControl
  Demonstrates controlling a 7-segment display with an AT89C2051 microcontroller.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/8051/AT89C2051/Led7SegmentControl

 */

#define MICROCONTROLLER_AT89CX051
#include <mcs51/mcs51reg.h>

#define CPU_MHZ (16)
#define TIMER_TICKS_PER_MS ((CPU_MHZ * 1000000UL) / 12 / 1000)
#define MAX_STEPS_PER_TIMER_CYCLE (0xFFFF / TIMER_TICKS_PER_MS)
#define DELAY (1000)
#define LED_IS_COMMON_CATHODE (1)

void ms_delay(unsigned int ms);

unsigned char LED_COMMON_CATHODE_DIGITS[] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

/*
 * Implements main loop that counts from 0 to 9 on a 7-segment display.
 */
void main(void) {
  while(1) {
    for (int i = 0; i < 10; i++) {
      P1 = LED_IS_COMMON_CATHODE ? LED_COMMON_CATHODE_DIGITS[i] : ~LED_COMMON_CATHODE_DIGITS[i];
      ms_delay(DELAY);
    }
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
