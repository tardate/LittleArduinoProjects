#ifndef MCP2200_COMMON
#define MCP2200_COMMON

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h> // no good for Windows?

#include "hidapi.h"

#define VENDOR_ID 0x04d8
#define PRODUCT_ID 0x00df
#define REPORT_SIZE 16

#define CONFIGURE_OPCODE (0x10)
#define READ_ALL_OPCODE (0x80)

#define Config_Alt_Pins (5)
#define Config_Alt_Options (7)

#define RxLED (1 << 3)
#define TxLED (1 << 2)
#define RxTGL (1 << 7)
#define TxTGL (1 << 6)
#define LEDX (1 << 5)

/*
  use hid_enumerate to list all MCP2200 devices and open the first device by the path
 */
hid_device * scan_devices();

/*
  open the first MCP2200 device found
 */
hid_device * open_first_device();

/*
  close the device handles
 */
void close_device(hid_device * device_handle);

#endif
