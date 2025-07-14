/*

  AT89C2051/LcdControl
  Demonstrates LCD control using AT89C2051.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/8051/AT89C2051/LcdControl

 */

#define MICROCONTROLLER_AT89CX051
#include <mcs51reg.h>

#define RS P3_0
#define E P3_1

void init_lcd(void);
void write_welcome(void);
void send_command(unsigned int command_value);
void send_data(unsigned int data_value);
void ms_delay(unsigned int ms);

/*
 * Command: main loop
 */
void main(void) {
  init_lcd();
  write_welcome();
  while(1) {
    // do nothing
  }
}

void write_welcome(void) {
  send_command(0x80)	; // force cursor on 1st line
  send_data('M');
  send_data('A');
  send_data('K');
  send_data('E');
  send_data(' ');
  send_data('M');
  send_data('O');
  send_data('R');
  send_data('E');

  send_command(0xC0)	; // force cursor on 2nd line
  send_data('P');
  send_data('R');
  send_data('O');
  send_data('J');
  send_data('E');
  send_data('C');
  send_data('T');
  send_data('S');
}

/*
 * Command: initialise the LCD
 */
void init_lcd(void) {
  send_command(0x38); // 2 lines and 5x7 matrix
  send_command(0x0E); // display on cursor blink
  send_command(0x01); // clear display screen
}

/*
 * Command: send LCD command. Assumes RW=0 (write mode) is hard-wired.
 */
void send_command(unsigned int command_value ) {
  P1=command_value;
  RS=0;
  E=1;
  ms_delay(10);
  E=0;
}

/*
 * Command: send LCD data. Assumes RW=0 (write mode) is hard-wired.
 */
void send_data(unsigned int data_value) {
  P1=data_value;
  RS=1;
  E=1;
  ms_delay(10);
  E=0;
}

/*
 * Command: delay for a specified time in milliseconds
 * This is calibrated for the processor running @ 16MHz
 */
void ms_delay(unsigned int ms) {
  for(unsigned int i=0; i<ms; i++) {
    for(unsigned int j=0; j<186; j++);
  }
}
