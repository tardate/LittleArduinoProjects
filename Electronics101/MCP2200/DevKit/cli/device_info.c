#include "common.h"

/*
  read the current configuration
 */
void read_all(hid_device *device_handle) {
  unsigned char report_buffer[REPORT_SIZE];
  int result;

  printf("READ_ALL report:\n");

  // Request READ_ALL report
  report_buffer[0] = READ_ALL_OPCODE;
  result = hid_write(device_handle, report_buffer, REPORT_SIZE);

  // Read report
  result = hid_read(device_handle, report_buffer, REPORT_SIZE);

  printf("[ 0] READ_ALL command                                         opcode = 0x%x\n", report_buffer[0]);
  printf("[ 1] EEP_Addr:                               Current EEPROM location = 0x%x\n", report_buffer[1]);
  printf("[ 3] EEP_Val:                              Current value at EEP_Addr = 0x%x\n", report_buffer[3]);
  printf("[ 4] IO_bmap:                                            GPIO bitmap = 0x%x\n", report_buffer[4]);
  printf("[ 5] Config_Alt_Pins:         Alternative configuration pin settings = 0x%x\n", report_buffer[5]);
  printf("[ 6] IO_Default_Val_bmap:                  Default GPIO value bitmap = 0x%x\n", report_buffer[6]);
  printf("[ 7] Config_Alt_Options:                Alternative function options = 0x%x\n", report_buffer[7]);
  printf("[ 8] Baud_H:              High byte of the default baud rate setting = 0x%x\n", report_buffer[8]);
  printf("[ 9] Baud_L:               Low byte of the default baud rate setting = 0x%x\n", report_buffer[9]);
  printf("[10] IO_Port_Val_bmap:                Bitmap of the GPIO port values = 0x%x\n", report_buffer[10]);

}


/*
  main program - just scan for devices, and print the config of the first
 */
int main(int argc, char* argv[]) {
  hid_device *device_handle;  // pointer to the selected MCP2200 device

  device_handle = scan_devices();
  if(!device_handle) {
    printf("No MCP2200 devices found, sorry!\n");
    return 1;
  }
  read_all(device_handle);
  close_device(device_handle);

  return 0;
}