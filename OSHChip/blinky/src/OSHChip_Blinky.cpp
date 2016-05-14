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
    blink an LED (active low)
 */
void blink(DigitalOut &led)
{
    led = LED_ON;
    wait_ms(DELAY);
    led = LED_OFF;
}

int main(void)
{
    uint32_t    loop_count;

    OSHChip_Init();

    /* configure OSHChip_Pin_7 for high drive active low */
    NRF_GPIO->PIN_CNF[OSHChip_Pin_7] =
          (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)   // turn off pin sensing
        | (GPIO_PIN_CNF_DRIVE_H0S1 << GPIO_PIN_CNF_DRIVE_Pos)       // high drive 0, standard 1
        | (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos)     // disable pullups
        | (GPIO_PIN_CNF_INPUT_Disconnect << GPIO_PIN_CNF_INPUT_Pos) // input buffer disconnect
        | (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos);        // for output

    loop_count = 0;

    while(1) {

        blink(red_led);
        blink(green_led);
        blink(blue_led);
        blink(yellow_led);

        printf("Loop Count:  %8d\r\n", loop_count++);

    }
}
