#include "mbed.h"
#include "OSHChip_Pin_Names.h"

#define SHORT_DELAY (50)
#define STEP_DELAY (SHORT_DELAY * 2)
#define LONG_DELAY (STEP_DELAY * 5)

#define MOSI_PIN (OSHChip_Pin_6)
#define MISO_PIN (OSHChip_Pin_5)
#define SCLK_PIN (OSHChip_Pin_7)
#define LATCH_PIN (OSHChip_Pin_4)

SPI spi(PinName MOSI_PIN, PinName MISO_PIN, PinName SCLK_PIN); 
DigitalOut led_module_cs(PinName LATCH_PIN);

// Command: write 16 bits to the module
void writeData(uint16_t data) {
    led_module_cs = 0;
    // even though SPI.write takes an "int", 
    // it actually sends 8 bits, so transfer in two calls
    spi.write(data);
    spi.write(data >> 8);
    led_module_cs = 1;
}

void clear() {
    writeData(0xFFFF);
    wait_ms(LONG_DELAY);
}

void chaser(bool clockwise) {
    /*
      move a single LED around the board
    */
    uint16_t data;
    for(int position=0; position<16; position++) {
    if(clockwise) {
        data = 0xFFFF ^ ((uint16_t)1 << (16 - position));
    } else {
        data = 0xFFFF ^ ((uint16_t)1 << position);
    }
    writeData(data);
    wait_ms(SHORT_DELAY);
    }
}

void chequers() {
    /*
      off               on
      on                off
      off               on
      on                off
      off               on
      on                off
      off               on
      on                off
    */
    uint16_t pattern = 0b1010101010101010;
    uint16_t pattern_reversed = 0b0101010101010101;
    
    for(int r=0; r<10; r++) {
        writeData(pattern);
        wait_ms(STEP_DELAY);
        writeData(pattern_reversed);
        wait_ms(STEP_DELAY);
    }
}

void fourBlocks() {
    /*
      off               on
      off               on
      off               on
      off               on
      on                off
      on                off
      on                off
      on                off
    */
    uint16_t pattern = 0b1111000011110000;
    uint16_t pattern_reversed = 0b0000111100001111;
    
    for(int r=0; r<10; r++) {
        writeData(pattern);
        wait_ms(STEP_DELAY);
        writeData(pattern_reversed);
        wait_ms(STEP_DELAY);
    }
}


int main() {
    // Deselect the module
    led_module_cs = 1; 
    // Setup spi: 8 bit data frame, spi mode 0, 1MHz clock rate
    spi.format(8, 0);
    spi.frequency(1000000);
    
    while(true) {
      clear();
      fourBlocks();
      clear();
      chequers();
      clear();
      chaser(false);
      chaser(false);
      chaser(true);
      chaser(true);
      chaser(false);
      clear();
    }
}

