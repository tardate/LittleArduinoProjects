/*

  AT89C2051/Counters

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/8051/AT89C2051/Counters

 */

#define MICROCONTROLLER_AT89CX051
#include <mcs51/mcs51reg.h>

#define RS P3_0
#define E P3_1

void run_counter(void);
void init_lcd(void);
void write_count(unsigned int count_value);
void write_welcome(void);
void send_set_cursor(unsigned int col, unsigned int row);
void send_command(unsigned int command_value);
void send_data(unsigned int data_value);
void ms_delay(unsigned int ms);

/*
 * Implements main loop that sets up the LCD and runs the counter demonstration
 */
void main(void) {
  init_lcd();
  write_welcome();
  run_counter();
}

/*
 * Command: run the counter, updating the LCD display with the current count value.
 * Limits the count to 42
 */
void run_counter(void) {
  TMOD=0b00000110; // counter 0, mode 2, 8 bit mode
  while(1) {
    TL0 = 0x00;
    TH0 = 0x00;
    TR0 = 1; // counter 0 on
    while(!TF0) { // loop until overflow
      if (TL0 == 43) break; // limit the count
      write_count(TL0);
    }
    TR0 = 0; // counter 0 off
    TF0 = 0; // clear flag
  }
}

/*
 * Command: write the current count value to the LCD (2 digits)
 */
void write_count(unsigned int count_value) {
  send_set_cursor(7, 1);
  send_data(count_value / 10 + 0x30); //Display Tens place
  send_data(count_value % 10 + 0x30);	//Display unit place
}

/*
 * Command: write welcome prompt to screen
 */
void write_welcome(void) {
  send_set_cursor(0, 0);
  send_data('P');
  send_data('R');
  send_data('E');
  send_data('S');
  send_data('S');
  send_data(' ');
  send_data('T');
  send_data('O');

  send_set_cursor(0, 1);
  send_data('C');
  send_data('O');
  send_data('U');
  send_data('N');
  send_data('T');
  send_data(':');
  send_data(' ');
}

/*
 * Command: initialise the LCD
 */
void init_lcd(void) {
  send_command(0b00111000); // 2 lines and 5x8 matrix font
  send_command(0b00001100); // display on, no cursor
  send_command(0b00000001); // clear display screen
}

/*
 * Command: set LCD cursor position. Assumes col, row within bounds for the screen.
 */
void send_set_cursor(unsigned int col, unsigned int row) {
	int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
	send_command(0x80 | (col + row_offsets[row]));
}

/*
 * Command: send LCD command. Assumes RW=0 (write mode) is hard-wired.
 */
void send_command(unsigned int command_value ) {
  P1 = command_value;
  RS = 0;
  E = 1;
  ms_delay(10);
  E = 0;
}

/*
 * Command: send LCD data. Assumes RW=0 (write mode) is hard-wired.
 */
void send_data(unsigned int data_value) {
  P1 = data_value;
  RS = 1;
  E = 1;
  ms_delay(10);
  E = 0;
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
