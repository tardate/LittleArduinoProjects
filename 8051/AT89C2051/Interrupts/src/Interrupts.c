/*

  AT89C2051/Interrupts
  Simple LED blinker using external and timer interrupts.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/8051/AT89C2051/Interrupts

 */

#define MICROCONTROLLER_AT89CX051
#include <mcs51/mcs51reg.h>

/*
 * Implements main loop: configures interrupts and then does nothing
 */
void main(void)
{
  EX0 = 1; // Enable external interrupt 0
  IT0 = 1; // Configure INT0 for falling edge trigger

  TMOD = 0b00000001; // Set Timer 0 to mode 1 (16-bit timer)
  TH0 = 0; // Load Timer 0 high byte
  TL0 = 0; // Load Timer 0 low byte
  ET0 = 1; // Enable Timer 0 interrupt
  TR0 = 1; // Start Timer 0

  EA = 1; // Enable global interrupts

  while(1);
}

/*
 * Command: external interrupt 0 ISR - toggles P1_0
 */
void external_interrupt_0_isr(void) __interrupt (0)
{
  P1_0 = !P1_0;
}

/*
 * Command: timer 0 interrupt ISR - toggles P1_1
 */
void timer_0_interrupt_isr(void) __interrupt (1)
{
  P1_1 = !P1_1;
}
