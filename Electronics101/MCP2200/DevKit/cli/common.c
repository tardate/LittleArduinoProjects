#include "common.h"

hid_device * scan_devices() {
  struct hid_device_info *device_info, *current_device;
  int devices_count = 0;
  hid_device *found_device;

  device_info = hid_enumerate(VENDOR_ID, PRODUCT_ID);
  current_device = device_info;
  while (current_device) {
    printf("Device Found\n  type: %04hx %04hx\n  path: %s\n  serial_number: %ls",
      current_device->vendor_id, current_device->product_id, current_device->path, current_device->serial_number);
    printf("\n");
    printf("  Manufacturer: %ls\n", current_device->manufacturer_string);
    printf("  Product:      %ls\n", current_device->product_string);
    printf("\n");

    if(devices_count == 0) {
      found_device = hid_open_path(current_device->path);
    }
    ++devices_count;
    current_device = current_device->next;
  }
  hid_free_enumeration(device_info);
  return found_device;
}

hid_device * open_first_device() {
  return hid_open(VENDOR_ID, PRODUCT_ID, NULL);
}

void close_device(hid_device *device_handle) {
  hid_close(device_handle);
}
