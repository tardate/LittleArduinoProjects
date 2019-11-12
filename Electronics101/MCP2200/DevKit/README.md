# #334 MCP2200/DevKit

Exploring the capabilities of the MCP2200 USB-to-UART transceiver and program it from a MacOSX host.

![Build](./assets/DevKit_build.jpg?raw=true)

## Notes

The MCP2200 is a USB-to-UART (Universal Serial Bus-to-Universal Asynchronous Receiver/Transmitter) serial converter device.
It is getting a bit on the old side, only supporting USB 2.0, and all the software support provided is Windows-only.

Nevertheless, I got hold of the MCP2200 Breakout Module to find out more.
The module is Microchip's development and evaluation platform for the MCP2200. It includes USB mini connector, 3.3 and 5V supply regulation,
and breaks out all the chip pins to pin headers.

I was particularly intersted to see how far I could get under MacOSX, including configuration over the HID Interface.
The answer is pleasantly: all the way!

### Unboxing

It's a helluva box for such a small component!

![DevKit_unboxing](./assets/DevKit_unboxing.jpg?raw=true)

![DevKit_pcb_front](./assets/DevKit_pcb_front.jpg?raw=true)

![DevKit_pcb_rear](./assets/DevKit_pcb_rear.jpg?raw=true)

With pins installed (headers are not included in the dev kit), the eval board is breadboard-compatible:

![DevKit_pcb_with_pins](./assets/DevKit_pcb_with_pins.jpg?raw=true)


### USB Connection

First up, I was pleased to see the chips recognised without any trouble (or drivers) on MacOSX. It is meant to be compatible with 10.7 and up.

Heres how it appears in Disk Utility:

```
MCP2200 USB Serial Port Emulator:

  Product ID: 0x00df
  Vendor ID:  0x04d8  (Microchip Technology Inc.)
  Version:  1.01
  Serial Number:  0001139059
  Speed:  Up to 12 Mb/sec
  Manufacturer: Microchip Technology Inc.
  Location ID:  0x14530000 / 31
  Current Available (mA): 500
  Current Required (mA):  100

```

![disk_utility](./assets/disk_utility.png?raw=true)


### Basic UART Operation

On MacOSX, the programmer shows up as a character device:

```
$ ls -1 /dev/cu*
/dev/cu.Bluetooth-Incoming-Port
/dev/cu.Bluetooth-Modem
/dev/cu.usbmodem1412
/dev/cu.usbmodem14511  # <- this one (it appeared after connecting the module)
/dev/cu.usbmodem14531
```

The simplest way of getting connected on MacOSX is to use screen, in this case at 115200 baud:

```
$ screen /dev/cu.usbmodem14511 115200
```

To give it a quick test, I fired up the [LEAP#333 VoltageSelfMeasurement](../../../playground/VoltageSelfMeasurement) sketch
on and Arduino Uno. It outputs the Vcc measurement to the serial port every second.

Connections:

* Arduino plugged into USB
* MCP2200 plugged into another USB port
* Arduino ground connected to MCP2200 ground
* Arduino Rx connected to MCP2200 Tx
* Arduino Tx connected to MCP2200 Rx

![DevKit_bb](./assets/DevKit_bb.jpg?raw=true)


In the screenshot here, I'm watching:

* the serial output direct from the Arduino on the Arduino IDE Console (attached to `/dev/cu.usbmodem14531`)
* simulatenously watching the same input from the MCP2200 via screen attached to `/dev/cu.usbmodem14511`

As you can see, no trouble at all:

![serial_chatter](./assets/serial_chatter.png?raw=true)


### Configuration over the HID Interface

The [MCP2200 HID Interface](http://ww1.microchip.com/downloads/en/DeviceDoc/93066A.pdf) provides a range of commands including:

* controlling the GPIO ports, including Tx/Rx LED indicators
* reading/writing the EEPROM

Microchip provide some sample code and "SimpleIO" library, but unfortunately it is Windows-only,
and the source code for SimpleIO is not released. Crazy that this isn't open source, as it is just generic HID code.

But no matter, just another excuse to take advantage of [hidapi](http://www.signal11.us/oss/hidapi/)
and write some simple scripts to play with the MCP2200 HID interface.

See the examples in [cli](./cli) folder, compiled thus:

```
$ cd cli
$ make
```

#### Read Configuration

[device_info.c](./cli/device_info.c) enumerates all MCP2200 devices plugged into USB.
With just the first one it finds, it requests a READ_ALL report and prints the configuration

```
$ ./device_info
Device Found
  type: 04d8 00df
  path: USB_04d8_00df_14510000
  serial_number: 0001139059
  Manufacturer: Microchip Technology Inc.
  Product:      MCP2200 USB Serial Port Emulator

READ_ALL report:
[ 0] READ_ALL command                                         opcode = 0x80
[ 1] EEP_Addr:                               Current EEPROM location = 0x0
[ 3] EEP_Val:                              Current value at EEP_Addr = 0x0
[ 4] IO_bmap:                                            GPIO bitmap = 0xff
[ 5] Config_Alt_Pins:         Alternative configuration pin settings = 0x0
[ 6] IO_Default_Val_bmap:                  Default GPIO value bitmap = 0xff
[ 7] Config_Alt_Options:                Alternative function options = 0x0
[ 8] Baud_H:              High byte of the default baud rate setting = 0x2
[ 9] Baud_L:               Low byte of the default baud rate setting = 0x70
[10] IO_Port_Val_bmap:                Bitmap of the GPIO port values = 0xff
```

#### Enable and Disabled Tx/Rx LEDs

[enable_leds.c](./cli/enable_leds.c) sets the Rx and Tx pins to blink slowly
when communicaitons are active. These are active low by default.

The [disable_leds.c](./cli/disable_leds.c) script turns them back off.

```
$ ./enable_leds
Turning on the Tx and Rx LEDs..
$ ./device_info
Device Found
  type: 04d8 00df
  path: USB_04d8_00df_14510000
  serial_number: 0001139059
  Manufacturer: Microchip Technology Inc.
  Product:      MCP2200 USB Serial Port Emulator

READ_ALL report:
[ 0] READ_ALL command                                         opcode = 0x80
[ 1] EEP_Addr:                               Current EEPROM location = 0x0
[ 3] EEP_Val:                              Current value at EEP_Addr = 0x0
[ 4] IO_bmap:                                            GPIO bitmap = 0x3f
[ 5] Config_Alt_Pins:         Alternative configuration pin settings = 0xc
[ 6] IO_Default_Val_bmap:                  Default GPIO value bitmap = 0xff
[ 7] Config_Alt_Options:                Alternative function options = 0x20
[ 8] Baud_H:              High byte of the default baud rate setting = 0x0
[ 9] Baud_L:               Low byte of the default baud rate setting = 0x67
[10] IO_Port_Val_bmap:                Bitmap of the GPIO port values = 0xc4

$ ./disable_leds
Turning off the Tx and Rx LEDs..
$ ./device_info
Device Found
  type: 04d8 00df
  path: USB_04d8_00df_14510000
  serial_number: 0001139059
  Manufacturer: Microchip Technology Inc.
  Product:      MCP2200 USB Serial Port Emulator

READ_ALL report:
[ 0] READ_ALL command                                         opcode = 0x80
[ 1] EEP_Addr:                               Current EEPROM location = 0x0
[ 3] EEP_Val:                              Current value at EEP_Addr = 0x0
[ 4] IO_bmap:                                            GPIO bitmap = 0x3f
[ 5] Config_Alt_Pins:         Alternative configuration pin settings = 0x0
[ 6] IO_Default_Val_bmap:                  Default GPIO value bitmap = 0xff
[ 7] Config_Alt_Options:                Alternative function options = 0x0
[ 8] Baud_H:              High byte of the default baud rate setting = 0x0
[ 9] Baud_L:               Low byte of the default baud rate setting = 0x67
[10] IO_Port_Val_bmap:                Bitmap of the GPIO port values = 0xff
```

Here are the LEDs in action (I'm holding a key down in `screen` to keep the red Tx LED on):

![Build](./assets/DevKit_build.jpg?raw=true)

#### GPIO

The MCP2200 has 8 GPIO pins that can be used for digital input and output.
Four of the pins have alternative functions which may render them unavailable.

But GPIO on a USB to UART chip?? Perhaps a few reasons:

* for control signals to the attached device (like toggle a reset line)
* for building USB gizmos

See [LEAP#335 Chaser](../Chaser) for a demonstration of input and output capabiltiies.


## Module Schematic

![Schematic](./assets/DevKit_schematic.jpg?raw=true)


## Credits and References
* [MCP2200 datasheet and info](http://www.microchip.com/wwwproducts/en/en546923)
* [MCP2200 Breakout Module](http://www.microchip.com/DevelopmentTools/ProductDetails.aspx?PartNO=ADM00393)
* [MCP2200 HID Interface Command Description](http://ww1.microchip.com/downloads/en/DeviceDoc/93066A.pdf)
* [hidapi source](http://www.signal11.us/oss/hidapi/)
* [USBanana_UART](https://github.com/regendrogenbogen/USBanana_UART) - breakout board design for the MCP2200
* [..as mentioned on my blog](https://blog.tardate.com/2017/08/leap334-exercising-the-mcp2200-usb-uart-transceiver.html)
