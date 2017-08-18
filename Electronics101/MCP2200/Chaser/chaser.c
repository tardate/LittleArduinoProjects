#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h> // no good for Windows?

#include "hidapi.h"

#define VENDOR_ID 0x04d8
#define PRODUCT_ID 0x00df
#define REPORT_SIZE 16

#define SET_CLEAR_OUTPUTS (0x08)
#define CONFIGURE_OPCODE (0x10)
#define READ_ALL_OPCODE (0x80)

#define IO_bmap (4)
#define Config_Alt_Pins (5)
#define IO_Default_Val_bmap (6)
#define IO_Port_Val_bmap (10)
#define Set_bmap (11)
#define Clear_bmap (12)

#define RxLED (1 << 3)
#define TxLED (1 << 2)
#define RxTGL (1 << 7)
#define TxTGL (1 << 6)
#define LEDX (1 << 5)
#define GP0 (1)
#define GP1 (1 << 1)
#define GP2 (1 << 2)
#define GP3 (1 << 3)
#define GP4 (1 << 4)
#define GP5 (1 << 5)
#define GP6 (1 << 6)
#define GP7 (1 << 7)
#define GP_OUTPUTS (GP7 | GP6 | GP5 | GP4 | GP3 | GP2 | GP1)

static const int STEP_DELAY = 150;        // ms between LED steps
static volatile bool keepRunning = true;  // exit when 0 (via interrupt)
hid_device *device_handle;                // pointer to the selected MCP2200 device

/*
  open the first MCP2200 device found and return the handle
 */

hid_device * open_first_device() {
  return hid_open(VENDOR_ID, PRODUCT_ID, NULL);
}

/*
  close the device handle
 */
void close_device() {
  hid_close(device_handle);
}

/*
  configure the GPIO pin modes and defaults
 */
void configure() {
  unsigned char report_buffer[REPORT_SIZE];
  int result;

  printf("Configuring the GPIO pins..\n");

  report_buffer[0] = READ_ALL_OPCODE;
  result = hid_write(device_handle, report_buffer, REPORT_SIZE);
  result = hid_read(device_handle, report_buffer, REPORT_SIZE);

  report_buffer[0] = CONFIGURE_OPCODE;
  report_buffer[Config_Alt_Pins] = 0;              // no special functions
  report_buffer[IO_bmap] = GP0;                    // only GP0 is input
  report_buffer[IO_Default_Val_bmap] = GP_OUTPUTS; // default output = 1
  result = hid_write(device_handle, report_buffer, REPORT_SIZE);
}

/*
  deconfigure device
 */
void deconfigure() {
  unsigned char report_buffer[REPORT_SIZE];
  int result;

  printf("Deconfiguring the GPIO pins..");

  report_buffer[0] = READ_ALL_OPCODE;
  result = hid_write(device_handle, report_buffer, REPORT_SIZE);
  result = hid_read(device_handle, report_buffer, REPORT_SIZE);

  report_buffer[0] = CONFIGURE_OPCODE;
  report_buffer[Config_Alt_Pins] = 0;              // no special functions
  report_buffer[IO_bmap] = 0xff;                   // all inputs
  report_buffer[IO_Default_Val_bmap] = 0xff;       // all = 1
  result = hid_write(device_handle, report_buffer, REPORT_SIZE);
  printf("done. Goodbye!\n");

}

/*
  detect button pressed (active-low) on GP0
 */
bool button_pressed() {
  unsigned char report_buffer[REPORT_SIZE];
  int result;

  report_buffer[0] = READ_ALL_OPCODE;
  result = hid_write(device_handle, report_buffer, REPORT_SIZE);
  result = hid_read(device_handle, report_buffer, REPORT_SIZE);

  return (report_buffer[IO_Port_Val_bmap] & GP0) == 0;
}


/*
  turns on LED at position (active-low logic)
 */
void toggle_led(int position) {
  unsigned char report_buffer[REPORT_SIZE];

  report_buffer[0] = SET_CLEAR_OUTPUTS;
  report_buffer[Set_bmap] = GP_OUTPUTS ^ (1 << position);
  report_buffer[Clear_bmap] = (1 << position); // clear everything else
  hid_write(device_handle, report_buffer, REPORT_SIZE);
}


/*
  handle ctrl-c
 */
void interrutHandler(int dummy) {
  keepRunning = false;
}

/*
  basic demo to cycle: runs the LED chaser
 */
void demo_cycle() {
  signal(SIGINT, interrutHandler);
  printf("Running the LED chaser thru MCP2200 GPIO (GP1-7); ctrl-c to end ..\n");
  bool forward = true;

  while (keepRunning) {
    for(int position=1; position<8; ++position) {
      toggle_led(forward ? position : 8 - position);
      usleep(STEP_DELAY * 1000);
      if(!keepRunning) break;
      if(button_pressed()) {
        printf(".. button pressed on GP0, reversing ..\n");
        forward = !forward;
      }
    }
  }
}

/*
  main program - find the first MCP2200 and run the chaser
 */
int main(int argc, char* argv[]) {

  hid_init();

  device_handle = open_first_device();
  if(!device_handle) {
    printf("No MCP2200 devices found, sorry!\n");
    return 1;
  }

  configure();
  demo_cycle();
  deconfigure();

  close_device();

  hid_exit();

  return 0;
}
