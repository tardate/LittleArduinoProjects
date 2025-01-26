#ifndef _RGB_H_
#define _RGB_H_

#define BREATHE_ENABLE (1 << 7)
#define BREATHE_EDGE_ON (0 << 6)
#define BREATHE_EDGE_BOTH (1 << 6)
#define BREATHE_MODE_MODULATE (1 << 5)
#define BREATHE_MODE_FIXED (0 << 5)

// Breathe rate is in 128 ms increments
#define BREATHE_RATE_MS(x) ((((x)+1) / 128 & 7) << 0)

// Blink on/off time is in 32 ms increments
#define BLINK_TIME_MS(x) (((x)) / 32)

#define LEDDEN (1 << 7)
#define FR250 (1 << 6)
#define OUTPUL (1 << 5)
#define OUTSKEW (1 << 4)
#define QUICK_STOP (1 << 3)
#define PWM_MODE_LFSR (1 << 2)
#define PWM_MODE_LINEAR (0 << 2)

void rgb_init(void);
void rgb_set(uint8_t r, uint8_t g, uint8_t b);

// The amount of time to stay off or on
void rgb_on_time(uint8_t ms);
void rgb_off_time(uint8_t ms);

// The amount of time to breathe in/out
void rgb_in_time(uint8_t ms);
void rgb_out_time(uint8_t ms);

enum led_registers {
    LEDDCR0 = 8,
    LEDDBR = 9,
    LEDDONR = 10,
    LEDDOFR = 11,
    LEDDBCRR = 5,
    LEDDBCFR = 6,
    LEDDPWRR = 1,
    LEDDPWRG = 2,
    LEDDPWRB = 3,
};

void rgb_write(uint8_t value, uint8_t addr);

#endif /* _RGB_H_ */