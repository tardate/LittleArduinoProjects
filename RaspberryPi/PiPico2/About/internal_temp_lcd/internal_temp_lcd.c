#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"

const int LCD_REFRESH_DELAY_MS = 2000;

// commands
const int LCD_CLEARDISPLAY = 0x01;
const int LCD_RETURNHOME = 0x02;
const int LCD_ENTRYMODESET = 0x04;
const int LCD_DISPLAYCONTROL = 0x08;
const int LCD_CURSORSHIFT = 0x10;
const int LCD_FUNCTIONSET = 0x20;
const int LCD_SETCGRAMADDR = 0x40;
const int LCD_SETDDRAMADDR = 0x80;

// flags for display entry mode
const int LCD_ENTRYSHIFTINCREMENT = 0x01;
const int LCD_ENTRYLEFT = 0x02;

// flags for display and cursor control
const int LCD_BLINKON = 0x01;
const int LCD_CURSORON = 0x02;
const int LCD_DISPLAYON = 0x04;

// flags for display and cursor shift
const int LCD_MOVERIGHT = 0x04;
const int LCD_DISPLAYMOVE = 0x08;

// flags for function set
const int LCD_5x10DOTS = 0x04;
const int LCD_2LINE = 0x08;
const int LCD_8BITMODE = 0x10;

// flag for backlight control
const int LCD_BACKLIGHT = 0x08;

const int LCD_ENABLE_BIT = 0x04;

// By default these LCD display drivers are on bus address 0x27. Mine are on 0x3F
static int lcd_addr = 0x3F;

// Modes for lcd_send_byte
const uint8_t LCD_CHARACTER = 1;
const uint8_t LCD_COMMAND = 0;

const uint8_t MAX_LINES = 2;
const uint8_t MAX_CHARS = 16;

void i2c_write_byte(uint8_t val) {
    i2c_write_blocking(i2c_default, lcd_addr, &val, 1, false);
}

void lcd_toggle_enable(uint8_t val) {
    // Toggle enable pin on LCD display
    // We cannot do this too quickly or things don't work
    const int LCD_TOGGLE_DELAY_US = 600;
    sleep_us(LCD_TOGGLE_DELAY_US);
    i2c_write_byte(val | LCD_ENABLE_BIT);
    sleep_us(LCD_TOGGLE_DELAY_US);
    i2c_write_byte(val & ~LCD_ENABLE_BIT);
    sleep_us(LCD_TOGGLE_DELAY_US);
}

// The display is sent a byte as two separate nibble transfers
void lcd_send_byte(uint8_t val, int mode) {
    uint8_t high = mode | (val & 0xF0) | LCD_BACKLIGHT;
    uint8_t low = mode | ((val << 4) & 0xF0) | LCD_BACKLIGHT;

    i2c_write_byte(high);
    lcd_toggle_enable(high);
    i2c_write_byte(low);
    lcd_toggle_enable(low);
}

void lcd_clear(void) {
    lcd_send_byte(LCD_CLEARDISPLAY, LCD_COMMAND);
}

void lcd_set_cursor(int line, int position) {
    int val = (line == 0) ? 0x80 + position : 0xC0 + position;
    lcd_send_byte(val, LCD_COMMAND);
}

static inline void lcd_char(char val) {
    lcd_send_byte(val, LCD_CHARACTER);
}

void lcd_string(const char *s) {
    while (*s) {
        lcd_char(*s++);
    }
}

void lcd_init() {
    lcd_send_byte(0x03, LCD_COMMAND);
    lcd_send_byte(0x03, LCD_COMMAND);
    lcd_send_byte(0x03, LCD_COMMAND);
    lcd_send_byte(0x02, LCD_COMMAND);

    lcd_send_byte(LCD_ENTRYMODESET | LCD_ENTRYLEFT, LCD_COMMAND);
    lcd_send_byte(LCD_FUNCTIONSET | LCD_2LINE, LCD_COMMAND);
    lcd_send_byte(LCD_DISPLAYCONTROL | LCD_DISPLAYON, LCD_COMMAND);
    lcd_clear();
}

float read_internal_temperature() {
    uint16_t raw = adc_read();
    const float conversion_factor = 3.3f / (1 << 12);
    float voltage = raw * conversion_factor;
    float temperature_c = 27.0f - (voltage - 0.706f) / 0.001721f;
    return temperature_c;
}

int setup() {
    // Initialise I2C and the LCD display
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));
    lcd_init();

    // Initialise ADC for reading the internal temperature sensor
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);

    return PICO_OK;
}

void loop() {
    static char message[] = "Internal temp:";
    lcd_set_cursor(0, (MAX_CHARS / 2) - strlen(message) / 2);
    lcd_string(message);

    char current_reading[MAX_CHARS];
    float temperature_c = read_internal_temperature();
    snprintf(
        current_reading,
        sizeof(current_reading),
        "%.2fC",
        temperature_c
    );
    lcd_set_cursor(1, (MAX_CHARS / 2) - strlen(current_reading) / 2);
    lcd_string(current_reading);

    sleep_ms(LCD_REFRESH_DELAY_MS);
    lcd_clear();
}

int main() {
    int rc = setup();
    hard_assert(rc == PICO_OK);

    while (1) {
        loop();
    }
}
