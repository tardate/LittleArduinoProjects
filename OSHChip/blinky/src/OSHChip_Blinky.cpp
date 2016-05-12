//
//  OSHChip_Blinky.cpp
//
//  Default mbed nRF51822 platforms all have BLE added
//
//  Default UART output on OSHChip pin 1 should be connected to OSHChip_CMSIS_DAP connector J5
//  which is the 2 pin connector in the corner of the board. Connect to the pin closest to the
//  corner of the board.  If you are going to use serial input, connect the other pin of J5 to
//  pin 2 of OSHChip. If you are not going to use the UART, OSHChip pins 1 and 2 can be re-assigned
//

#include "mbed.h"
#include "OSHChip_Pin_Names.h"

#define YELLOW_LED_EXT (OSHChip_Pin_7)

DigitalOut red_led(PinName LED_RED);
DigitalOut green_led(PinName LED_GREEN);
DigitalOut blue_led(PinName LED_BLUE);
DigitalOut yellow_led(PinName YELLOW_LED_EXT);

#define DELAY       (1000)
#define LED_ON      (0)
#define LED_OFF     (1)

/*
    blink an on-board LED (active high)
 */
void blink(DigitalOut &led) 
{
    led = LED_ON;
    wait_ms(DELAY);
    led = LED_OFF;
}

/*
    blink an external LED (active low)
    how to switch to active high? still figuring that out..
 */
void blink_external(DigitalOut &led) 
{
    led = LED_OFF;
    wait_ms(DELAY);
    led = LED_ON;
}
    
int main(void) 
{
    uint32_t    loop_count;
    
    OSHChip_Init();

    loop_count = 0;

    while(1) {

        blink(red_led);
        blink(green_led);
        blink(blue_led);
        blink_external(yellow_led);
        
        printf("Loop Count:  %8d\r\n", loop_count++);
        
    }
}
