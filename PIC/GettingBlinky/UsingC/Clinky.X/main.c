/*
 * File:   main.c
 * Author: paulgallagher
 *
 * Created on 19 May, 2018, 5:38 PM
 */

// PIC12F675 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTRCCLK  // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

#define _XTAL_FREQ (4000000)    // 4MHz clock

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

// LED controls - active-low
#define LED_OFF (1)
#define LED_ON  (0)

// use a shadow register to simplify bit manipulation
GPIObits_t gpio_shadow;

/*
 * Setup:
 * GP0 and GP1 as Output pins for active-low LEDs
 */
void setup(void) {
  //TRISIO &= !0b11;
  TRISIObits.TRISIO0 = 0;
  TRISIObits.TRISIO1 = 0;
  gpio_shadow = GPIObits;
}

/*
 * Main loop body: toggles LEDs on GP0/GP1
 */
void loop(void) {
    gpio_shadow.GP0 = LED_OFF;
    gpio_shadow.GP1 = LED_ON;
    GPIObits = gpio_shadow;
    __delay_ms(100);
    gpio_shadow.GP0 = LED_ON;
    gpio_shadow.GP1 = LED_OFF;
    GPIObits = gpio_shadow;
    __delay_ms(1000);
}

void main(void) {
    setup();
    while(1) loop();
    return;
}
