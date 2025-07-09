/*

  AT89C2051/LedChaser
  Run an AT89C2051 8 LED chaser controlled with a timer interrupt.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/8051/AT89C2051/LedChaser

 */

#define MICROCONTROLLER_AT89CX051
#include <mcs51reg.h>
#include <stdint.h>

#define INTERRUPTS_PER_SECOND 5208 // at 16MHz: 16000000/12/(2^8) = 5208 = 0x1458
#define TICKS_PER_STEP 2604        // INTERRUPTS_PER_SECOND / 2 = 2Hz


volatile uint16_t timer_counter = TICKS_PER_STEP;

volatile uint8_t led_state = 1;


void timer0_isr(void) __interrupt (1) {
    timer_counter--;
    if(timer_counter == 0) {
        led_state <<= 1;
        if(led_state==0) led_state = 1;
        timer_counter = TICKS_PER_STEP;
    }
}


int main(void) {
    TMOD &= 0xF0; // Don't care about Timer1, clear Timer0 settings
    TMOD |= 0x03; // Set Timer0 mode 3: 8 bit, software gate
    TH0 = 0x00;   // Clear counter
    TL0 = 0x00;   // Clear counter
    ET0=1;        // Enable Timer0 interrupt.
    EA=1;         // Enable global interrupt.
    TR0=1;        // Set Timer0 run

    while(1) {
        P1 = 0xFF ^ led_state; // translate led_state to active-low logic
    }
}
