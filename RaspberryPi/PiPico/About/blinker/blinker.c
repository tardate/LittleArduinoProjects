#include "pico/stdlib.h"

const int LED_DELAY_MS = 250;

// LED pin definitions. The code assumes these are sequential GPIO pins.
const uint8_t LED1 = 7;
const uint8_t LED2 = 8;
const uint8_t LED3 = 9;
const uint8_t LED4 = 10;
const uint8_t LED5 = 11;
const uint8_t LED6 = 12;
const uint8_t LED7 = 13;

int led_init(void) {
    for(int l = LED1; l <= LED7; l++) {
        gpio_init(l);
        gpio_set_dir(l, GPIO_OUT);
    }
    return PICO_OK;
}

void set_led_trio(bool led_state) {
    for(int l = LED1; l <= LED3; l++) {
        gpio_put(l, led_state);
    }
}

void set_quad_counter(uint8_t counter) {
    for(int l = LED4; l <= LED7; l++) {
        gpio_put(l, (counter & (1 << (LED7 - l + 1))) != 0);
    }
}

void loop() {
    static bool trio_state = false;
    static uint8_t quad_counter = 0;

    set_led_trio(trio_state);
    set_quad_counter(quad_counter);

    sleep_ms(LED_DELAY_MS);

    trio_state = !trio_state;
    quad_counter++;
}

int main() {
    int rc = led_init();
    hard_assert(rc == PICO_OK);
    while (true) {
        loop();
    }
}
