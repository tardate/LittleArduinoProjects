# #496 ESP32 Getting Started

Getting started with the ESP32: connecting and programming from MacOSX with the Arduino IDE using a WiFi scanner script as an example.

![Build](./assets/GettingStarted_build.jpg?raw=true)

## Notes

I've had an ESP32-WROOM-32 kicking around for a while.
Reading a copy of [The Complete ESP32 Projects Guide](https://www.goodreads.com/book/show/47562312-the-complete-esp32-projects-guide) by Dogan Ibrahim,
and its given me the motivation to finally fire it up!

The Espressif documentation is now quite impressive (a far cry from early ESP8266 days).
The
[ESP32-DevKitC V4 Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/hw-reference/get-started-devkitc.html)
is just about all you need to get up and running.

In this proejct, I'll document my journey getting the ESP32 connected and programmed from MacOSX.

## The ESP32-DevKitC V4

The module I'm using is an ESP32-DevKitC V4 design:

[![esp32-devkitc-functional-overview](./assets/esp32-devkitc-functional-overview.jpg?raw=true)](https://docs.espressif.com/projects/esp-idf/en/latest/hw-reference/get-started-devkitc.html)

Some key features:

* the EN button performs a reset
* the BOOT button is used for programming (hold the button down while programming)
* micro USB, for programming and/or power
* 2 LEDs: one is a power indicator, the other is connected on port D2 and available for use.

Power Supply Options:

* Micro USB port, default power supply
* 5V / GND header pins
* 3V3 / GND header pins

Only one of the power options should be usde at a time.

Pinout guide from lastminuteengineers:

[![ESP32-Development-Board-Pinout.jpg](./assets/ESP32-Development-Board-Pinout.jpg?raw=true)](https://lastminuteengineers.com/esp32-arduino-ide-tutorial/)

## MacOSX Installation

After plugging the ESP32-DevKitC V4 into my MacOSX system, it wasn't initially recognised as a character device. But it did show up on USB (checked with the Systme Information app):

```
CP2102 USB to UART Bridge Controller:

  Product ID: 0xea60
  Vendor ID:  0x10c4  (Silicon Laboratories, Inc.)
  Version:  1.00
  Serial Number:  0001
  Speed:  Up to 12 Mb/sec
  Manufacturer: Silicon Labs
  Location ID:  0x14200000 / 4
  Current Available (mA): 500
  Current Required (mA):  100
  Extra Operating Current (mA): 0
```

A quick Google search told me this is nromal, and it just means my system needs the correct driver. It is available for installation from Silicon Labs:
[CP210x USB to UART Bridge VCP Drivers](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers).
After installation, th eESP32 shows up as a device:

```
$ ls -1 /dev/cu*
/dev/cu.Bluetooth-Incoming-Port
/dev/cu.SLAB_USBtoUART  # <== the ESP32 via SiLabs driver
```

Connecting with screen (`$ screen /dev/cu.SLAB_USBtoUART 115200`) and pressing reset/EN proves everything is alive. Console displays the boot log:

```
ets Jun  8 2016 00:22:57

rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
flash read err, 1000
ets_main.c 371
ets Jun  8 2016 00:22:57

rst:0x10 (RTCWDT_RTC_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0x00
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0008,len:8
load:0x3fff0010,len:3472
load:0x40078000,len:7804
load:0x40080000,len:252
entry 0x40080034
I (43) boot: ESP-IDF v2.0 2nd stage bootloader
I (44) boot: compile time 03:23:43
I (44) boot: Enabling RNG early entropy source...
I (60) boot: SPI Speed      : 40MHz
I (72) boot: SPI Mode       : DIO
I (85) boot: SPI Flash Size : 4MB
I (97) boot: Partition Table:
I (108) boot: ## Label            Usage          Type ST Offset   Length
I (131) boot:  0 phy_init         RF data          01 01 0000f000 00001000
I (154) boot:  1 otadata          OTA data         01 00 00010000 00002000
I (177) boot:  2 nvs              WiFi data        01 02 00012000 0000e000
I (200) boot:  3 at_customize     unknown          40 00 00020000 000e0000
I (224) boot:  4 ota_0            OTA app          00 10 00100000 00180000
I (247) boot:  5 ota_1            OTA app          00 11 00280000 00180000
I (270) boot: End of partition table
I (284) boot: Disabling RNG early entropy source...
I (300) boot: Loading app partition at offset 00100000
I (1476) boot: segment 0: paddr=0x00100018 vaddr=0x00000000 size=0x0ffe8 ( 65512)
I (1477) boot: segment 1: paddr=0x00110008 vaddr=0x3f400010 size=0x1c5d0 (116176) map
I (1493) boot: segment 2: paddr=0x0012c5e0 vaddr=0x3ffb0000 size=0x0215c (  8540) load
I (1523) boot: segment 3: paddr=0x0012e744 vaddr=0x40080000 size=0x00400 (  1024) load
I (1547) boot: segment 4: paddr=0x0012eb4c vaddr=0x40080400 size=0x1b028 (110632) load
I (1625) boot: segment 5: paddr=0x00149b7c vaddr=0x400c0000 size=0x00034 (    52) load
I (1626) boot: segment 6: paddr=0x00149bb8 vaddr=0x00000000 size=0x06450 ( 25680)
I (1643) boot: segment 7: paddr=0x00150010 vaddr=0x400d0018 size=0x7a544 (501060) map
I (1670) heap_alloc_caps: Initializing. RAM available for dynamic allocation:
I (1693) heap_alloc_caps: At 3FFBA6B8 len 00025948 (150 KiB): DRAM
I (1714) heap_alloc_caps: At 3FFE8000 len 00018000 (96 KiB): D/IRAM
I (1735) heap_alloc_caps: At 4009B428 len 00004BD8 (18 KiB): IRAM
I (1756) cpu_start: Pro cpu up.
I (1768) cpu_start: Single core mode
I (1781) cpu_start: Pro cpu start user code
I (1841) cpu_start: Starting scheduler on PRO CPU.
I (2098) uart: queue free spaces: 10
I (2100) wifi: wifi firmware version: c604573
I (2100) wifi: config NVS flash: enabled
I (2100) wifi: config nano formating: disabled
I (2107) wifi: Init dynamic tx buffer num: 32
I (2108) wifi: wifi driver task: 3ffc4da4, prio:23, stack:3584
I (2113) wifi: Init static rx buffer num: 10
I (2117) wifi: Init dynamic rx buffer num: 0
I (2121) wifi: Init rx ampdu len mblock:7
I (2125) wifi: Init lldesc rx ampdu entry mblock:4
I (2129) wifi: wifi power manager task: 0x3ffca14c prio: 21 stack: 2560
I (2136) wifi: wifi timer task: 3ffcb1cc, prio:22, stack:3584
E (2141) phy_init: PHY data partition validated
I (2166) phy: phy_version: 329, Feb 22 2017, 15:58:07, 0, 0
I (2167) wifi: mode : softAP (30:ae:a4:35:ef:55)
I (2170) wifi: mode : sta (30:ae:a4:35:ef:54) + softAP (30:ae:a4:35:ef:55)
I (2173) wifi: mode : softAP (30:ae:a4:35:ef:55)
```

## Using the Arduino IDE

Next step is to try and program it with the Arduino IDE. I'm using the IDE v1.8.9 at the time of writing.

Before programming the ESP32, it is necessary to isntall the appropriate board manager.
The current list of 3rd party board managers is available at
[https://github.com/arduino/Arduino/wiki/Unofficial-list-of-3rd-party-boards-support-urls](https://github.com/arduino/Arduino/wiki/Unofficial-list-of-3rd-party-boards-support-urls).

This confirmed that the current Espressif ESP32 board index is at https://dl.espressif.com/dl/package_esp32_index.json.
This gets added to the additional board managers URL list in the Arduino preferences:

![ide_add_board_urls](./assets/ide_add_board_urls.png?raw=true)

Once added, it is possible to search for and install esp32 in the Board Manager:

![ide_board_manager](./assets/ide_board_manager.png?raw=true)

With that done, it is possible to select "ESP32 Dev Module" from the `Tools > Board` menu, and the examples will change accordingly.
Compiling programs with this configuration is actually using [Arduino core for the ESP32](https://github.com/espressif/arduino-esp32).

### Programming Wifi Scanner

The GettingStarted.ino sketch is based on the WiFi Scanner example shipped with the ESP32 board support.

To program the ESP32 over USB, it is simply necessary to hold down the the BOOT button while compiling/uploading.
If you let the button go before the final reset, the board will reset itself. If you keep the BOOT button pressed too long,
it may be neceassary to press the EN/reset button to manually reset the board after programming is complete.

![ide_programming](./assets/ide_programming.png?raw=true)

The GettingStarted.ino sketch will scan available SSIDs every 5 seconds and list them to the serial port (at 115200 baud)

![ide_runtime](./assets/ide_runtime.png?raw=true)

## Construction

There is no "circuit" to construct so far - simply plugging the ESP32 into the USB port!
But I did go searching for a suitable Fritzing Part.

The best I found was probably the [ESP32S_HiLetgo](https://forum.fritzing.org/t/esp32s-hiletgo-dev-boad-with-pinout-template/5357?u=steelgoose), which I've started to use.
The pinouts are however not correct for the Devkit board I have (so care will be required when wiring from a schematic).

![Breadboard](./assets/GettingStarted_bb.jpg?raw=true)

![Schematic](./assets/GettingStarted_schematic.jpg?raw=true)

The version of the ESP32 DevKit I have includes useful pin labels marked on the board. However this does make the board a little too wide to
fit on a standard breadboard (only one side of the board will have space to connect jumper wires). So I sit is on two connected breadboards

![Build](./assets/GettingStarted_build.jpg?raw=true)

## Credits and References

* [ESP32-DevKitC V4 Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/hw-reference/get-started-devkitc.html)
* [ESP-IDF Programming Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/) - espressif docs
* [CP210x USB to UART Bridge VCP Drivers](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)
* [The Complete ESP32 Projects Guide](https://www.goodreads.com/book/show/47562312-the-complete-esp32-projects-guide) by Dogan Ibrahim
* [Insight Into ESP32 Features & Using It With Arduino IDE](https://lastminuteengineers.com/esp32-arduino-ide-tutorial/) - excellent resource by lastminuteengineers
* [Arduino core for the ESP32](https://github.com/espressif/arduino-esp32) - GitHub
* [Getting started with ESP32 and the Arduino IDE](https://www.elektormagazine.com/magazine/elektor-201707/40510) - elektormagazine
* [ESP32 for Power Users - Native programming](https://www.elektormagazine.com/magazine/elektor-201709/40717) - elektormagazine
