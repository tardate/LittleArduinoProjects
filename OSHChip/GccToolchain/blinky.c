//
//  blinky.c
//

#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "OSHChip_Pin_Names.h"

#define DELAY   (150)

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    // Configure LED-pins as outputs.
    nrf_gpio_cfg_output(LED_GREEN);
    nrf_gpio_cfg_output(LED_BLUE);

    // RED, GREEN and BLUE onboard LEDs blink alternately.
    while (true)
    {
        nrf_gpio_pin_set(LED_BLUE);
        nrf_delay_ms(DELAY);
        nrf_gpio_pin_clear(LED_BLUE);

        nrf_gpio_pin_set(LED_GREEN);
        nrf_delay_ms(DELAY);
        nrf_gpio_pin_clear(LED_GREEN);
    }
}
