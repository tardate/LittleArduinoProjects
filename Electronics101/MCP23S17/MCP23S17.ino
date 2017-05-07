/*

  MCP23S17
  Test the MCP23S17 16-Bit I/O Expander

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/MCP23S17

 */

#include <SPI.h>

SPISettings portExpanderSettings(16000000, MSBFIRST, SPI_MODE0);

const int PORT_EXPANDER_SS_PIN = 7;
const int PORT_INTA_PIN = 2;
const uint8_t PORT_EXPANDER_ADDRESS = 0;
const uint8_t SLAVE_CONTROL_BYTE = 0b1000000 | (PORT_EXPANDER_ADDRESS << 1);

#define    IOCON     (0x0A)
#define    IODIRA    (0x00)
#define    IODIRB    (0x01)
#define    GPIOA     (0x12)
#define    GPIOB     (0x13)

#define    GPINTENA  (0x04)
#define    DEFVALA   (0x06)
#define    INTCONA   (0x08)

uint8_t INTA_PIN = 1; // GPA1
uint8_t LED1_PIN = 3; // GPA3
uint8_t LED2_PIN = 4; // GPB4
uint8_t LED3_PIN = 1; // GPB1

volatile uint8_t led3_value = 0;
volatile boolean inta_flag = false;


/*
 * Command: setup SPI, ports and interrupts.
 */
void setup() {
  pinMode(PORT_EXPANDER_SS_PIN, OUTPUT);
  digitalWrite(PORT_EXPANDER_SS_PIN, HIGH);
  SPI.begin();
  SPI.beginTransaction(portExpanderSettings);

  writeByte(IOCON,  0b00001000); // enable hardware address pins; bank=0 addressing
  writeByte(IODIRA, 0xFF ^ (1 << LED1_PIN)); // set GPA3 output ports
  writeByte(IODIRB, 0xFF ^ ((1 << LED2_PIN) | (1 << LED3_PIN))); // set GPB4 output ports
  writeByte(INTCONA, (1 << INTA_PIN)); // compare GPA1 to DEFVAL
  writeByte(DEFVALA, (1 << INTA_PIN)); // set GPA1 default compare value to 1 (normally pulled high)
  writeByte(GPINTENA, (1 << INTA_PIN)); // set GPA1 interrupt on change

  // enable hardware interrupt from INTA_PIN
  pinMode(PORT_INTA_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(PORT_INTA_PIN), handleIntA, FALLING);

}

/*
 * Command: main loop
 * toggle the LEDs every half a second; clear any interrupts
 */
void loop() {
  toggleLeds();
  if(inta_flag) readByte(GPIOA);
  delay(500);
}

/*
 * Command: INTA interrupt handler
 * toggle the LED3 status and set the interrupt flag
 */
void handleIntA() {
  inta_flag = true;
  led3_value ^= 1;
}

/*
 * Command: toggle LEDS
 * toggle the output status of the two LEDs on the port expander
 */
void toggleLeds() {
  static uint8_t current_value = 0;
  uint8_t GPIOA_value;
  uint8_t GPIOB_value;

  current_value ^= 1;

  GPIOA_value = (current_value & 1) << LED1_PIN;
  GPIOB_value = ((current_value ^ 1) << LED2_PIN) | (led3_value << LED3_PIN);

  // write the GPIO registers. Two methods are used here purely for demonstration purposes
  // (in real life, you would just pick the most appropriate).
  // If the current value is high, then it writes register by register.
  // If the current value is low, then it performs a sequential write in one operation.
  if(current_value) {
    writeByte(GPIOA, GPIOA_value);
    writeByte(GPIOB, GPIOB_value);
  } else {
    // with IOCON.BANK = 0, GPIOA address is immediately followed by GPIOB
    writeSequentialBytes(GPIOA, GPIOA_value, GPIOB_value);
  }

}


/*
 * Command: write a single byte to the specified register
 */
void writeByte(uint8_t reg, uint8_t data) {
  digitalWrite(PORT_EXPANDER_SS_PIN, LOW);

  SPI.transfer(SLAVE_CONTROL_BYTE);
  SPI.transfer(reg);
  SPI.transfer(data);

  digitalWrite(PORT_EXPANDER_SS_PIN, HIGH);
}


/*
 * Returns: byte read from specified register
 */
uint8_t readByte(uint8_t reg) {
  digitalWrite(PORT_EXPANDER_SS_PIN, LOW);

  SPI.transfer(SLAVE_CONTROL_BYTE | 1);
  SPI.transfer(reg);
  uint8_t data = SPI.transfer(0);

  digitalWrite(PORT_EXPANDER_SS_PIN, HIGH);
  return data;
}


/*
 * Command: write two bytes to specified register
 * demonstrates sequential write and transfer16 alternate SPI method.
 */
void writeSequentialBytes(uint8_t reg, uint8_t first, uint8_t last) {
  digitalWrite(PORT_EXPANDER_SS_PIN, LOW);

  SPI.transfer16((uint16_t)SLAVE_CONTROL_BYTE << 8 | reg);
  SPI.transfer16((uint16_t)first << 8 | last);

  digitalWrite(PORT_EXPANDER_SS_PIN, HIGH);
}
