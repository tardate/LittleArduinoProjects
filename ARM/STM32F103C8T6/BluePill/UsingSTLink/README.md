# #547 Using STLink with the Arduino IDE

Programming an ARM Cortex-M3 STM32F103C8T6 Blue Pill with an ST Link v2 programmer and the Arduino IDE.

![Build](./assets/UsingSTLink_build.jpg?raw=true)

## Notes

In my [first experiments](../) programming the STM32F103C8T6 with the Arduino IDE, I used the serial
programming technique over a CH340G USB-serial adapter (similar but different to FTDI-based adapters).

I have a third-party [ST-Link/V2 programmer](https://www.aliexpress.com/item/32867333890.html), so I'm keen to see if it can also be used
with the Arduino IDE.

It turns out - yes, it works fine, with the benefit of being much more convenient because there is no need
to adjust jumpers on the board and boot the device into bootloarder mode.

### Connecting the Programmer

The ST-Link/V2 programmer connects to the SWD header on the module.
Only 4 pins need to be connected from the 10-pin shroud on the programmer: 3.3V, GND, SWDIO, SWDCLK

![programmer_connections](./assets/programmer_connections.jpg?raw=true)

![Breadboard](./assets/UsingSTLink_bb.jpg?raw=true)

![Schematic](./assets/UsingSTLink_schematic.jpg?raw=true)

### Configure and Upload from the Arduino IDE

In addition to selecting the appropriate settings for the board/chip, the critical setting is "Upload method: STLink":

![arduino_ide_programming_settings](./assets/arduino_ide_programming_settings.png?raw=true)

The SWD interface does not require a bootloader to be running, so there is no need
to adjust jumpers on the board and boot the device into bootloarder mode.

With STLink upload method selected, the Arduino IDE can be used as normal - just click on the upload button to program the device.

I'm using a simple blinky sketch: [UsingSTLink.ino](./UsingSTLink.ino).

![program_upload](./assets/program_upload.png?raw=true)

Example transcript from the console (excluding compilation steps):

```
Archiving built core (caching) in: /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_cache_474411/core/core_33a28a35d5be94a4487e04df0719a759.a
Linking everything together...
/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++ -Os -Wl,--gc-sections -mcpu=cortex-m3 -T/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/variants/generic_stm32f103c/ld/jtag_c8.ld -Wl,-Map,/var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/UsingSTLink.ino.map -L/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/variants/generic_stm32f103c/ld -o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/UsingSTLink.ino.elf -L/var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335 -lm -lgcc -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/sketch/UsingSTLink.ino.cpp.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/core/wirish/start.S.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/core/wirish/start_c.c.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/core/wirish/syscalls.c.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/core/board.cpp.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/core/wirish/boards.cpp.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/core/wirish/boards_setup.cpp.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/core/core.a -Wl,--end-group
/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-objcopy -O binary /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/UsingSTLink.ino.elf /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/UsingSTLink.ino.bin
/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-size -A /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/UsingSTLink.ino.elf
Sketch uses 16008 bytes (24%) of program storage space. Maximum is 65536 bytes.
Global variables use 3088 bytes (15%) of dynamic memory, leaving 17392 bytes for local variables. Maximum is 20480 bytes.
/Users/paulgallagher/Library/Arduino15/packages/stm32duino/tools/stm32tools/2018.4.29/macosx/stlink_upload cu.wchusbserial1420 {upload.altID} {upload.usbID} /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_716335/UsingSTLink.ino.bin
2020-05-02T12:05:31 INFO /Users/kuwatay/src/stlink-master/src/usb.c: -- exit_dfu_mode
2020-05-02T12:05:31 INFO /Users/kuwatay/src/stlink-master/src/common.c: Loading device parameters....
2020-05-02T12:05:31 INFO /Users/kuwatay/src/stlink-master/src/common.c: Device connected is: F1 Medium-density device, id 0x20036410
2020-05-02T12:05:31 INFO /Users/kuwatay/src/stlink-master/src/common.c: SRAM size: 0x5000 bytes (20 KiB), Flash: 0x10000 bytes (64 KiB) in pages of 1024 bytes
2020-05-02T12:05:31 INFO /Users/kuwatay/src/stlink-master/src/common.c: Attempting to write 16008 (0x3e88) bytes to stm32 address: 134217728 (0x8000000)

Flash page at addr: 0x08000000 erased
Flash page at addr: 0x08000400 erased
Flash page at addr: 0x08000800 erased
Flash page at addr: 0x08000c00 erased
Flash page at addr: 0x08001000 erased
Flash page at addr: 0x08001400 erased
Flash page at addr: 0x08001800 erased
Flash page at addr: 0x08001c00 erased
Flash page at addr: 0x08002000 erased
Flash page at addr: 0x08002400 erased
Flash page at addr: 0x08002800 erased
Flash page at addr: 0x08002c00 erased
Flash page at addr: 0x08003000 erased
Flash page at addr: 0x08003400 erased
Flash page at addr: 0x08003800 erased2020-05-02T12:05:31 INFO /Users/kuwatay/src/stlink-master/src/common.c: Finished erasing 16 pages of 1024 (0x400) bytes
2020-05-02T12:05:31 INFO /Users/kuwatay/src/stlink-master/src/common.c: Starting Flash write for VL/F0/F3 core id
2020-05-02T12:05:31 INFO /Users/kuwatay/src/stlink-master/src/flash_loader.c: Successfully loaded flash loader in sram

Flash page at addr: 0x08003c00 erased

  0/15 pages written
  1/15 pages written
  2/15 pages written
  3/15 pages written
  4/15 pages written
  5/15 pages written
  6/15 pages written
  7/15 pages written
  8/15 pages written
  9/15 pages written
 10/15 pages written
 11/15 pages written
 12/15 pages written
 13/15 pages written
 14/15 pages written2020-05-02T12:05:32 INFO /Users/kuwatay/src/stlink-master/src/common.c: Starting verification of write complete

 15/15 pages written2020-05-02T12:05:32 INFO /Users/kuwatay/src/stlink-master/src/common.c: Flash written and verified! jolly good!

```

## Credits and References

* [ST-Link/V2 USB programmer](https://www.aliexpress.com/item/32867333890.html) - examples from an aliexpress seller
* [ST-LINK/V2 is an in-circuit debugger and programmer](https://www.st.com/en/development-tools/st-link-v2.html) - original ST
