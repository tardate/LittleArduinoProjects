#include <generated/csr.h>
#include <irq.h>
#include <rgb.h>
#include <usb.h>
#include <time.h>
#include <stdbool.h>

void isr(void) {
    unsigned int irqs;

    irqs = irq_pending() & irq_getmask();

    if (irqs & (1 << USB_INTERRUPT))
        usb_isr();
}

enum LED_STATE {
  RUNNING = 0,
  IDLE,
  SUCCESS,
  FAILED
};

// this is the value we'll poke over the wishbone bus,
// marked volatile so it doesn't get optimized away:
volatile int desired_state = IDLE;

// tracks the current state, so it only needs to
// be updated when out of date:
int current_state = FAILED;

// returns true if state has changed
static inline bool new_state(void) {
    return (current_state != desired_state);
}

// set LED configuration
static void rgb_multi(uint8_t r, uint8_t g, uint8_t b, uint8_t on_ms, uint8_t off_ms, uint8_t br_ms) {
    rgb_write(BLINK_TIME_MS(on_ms), LEDDONR);
    rgb_write(BLINK_TIME_MS(off_ms), LEDDOFR);
    if (br_ms > 0) {
        rgb_write(
            BREATHE_ENABLE | BREATHE_EDGE_BOTH | BREATHE_MODE_MODULATE | BREATHE_RATE_MS(br_ms),
            LEDDBCRR
        );
        // ignore LEDDBCFR since BREATHE_EDGE_BOTH
    } else {
        rgb_write(0, LEDDBCRR);
        rgb_write(0, LEDDBCFR);
    }
    rgb_set(r, g, b);
}

// command: switch to the new LED state
static void change_state(void) {
    current_state = desired_state;

    switch (current_state) {
    case RUNNING:
        rgb_multi(0x08, 0xb3, 0xd4, 125, 125, 16);
        break;
    case IDLE:
        rgb_multi(0x20, 0x20, 0x0a, 20, 0, 0);
        break;
    case SUCCESS:
        rgb_multi(0x22, 0xdb, 0x05, 200, 200, 16);
        break;
    default: // failed or other
        rgb_multi(0xf0, 0x0c, 0x0, 100, 100, 3);
        break;
    }
}

int main(void) {
    irq_setmask(0);
    irq_setie(1);
    usb_init();
    rgb_init();

    usb_connect();

    while (1) {
        msleep(80);
        if (new_state()) {
            change_state();
        }
    }
}
