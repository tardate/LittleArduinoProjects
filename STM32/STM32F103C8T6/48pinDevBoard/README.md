# #546 STM32F103C8T6 Dev Board

Programming the 48 pin version of the ARM Cortex-M3 STM32F103C8T6 board with the Arduino IDE.

![Build](./assets/48pinDevBoard_build.jpg?raw=true)

## Notes

This a [48-pin ARM Cortex-M3 STM32F103C8T6 Core Board](https://www.aliexpress.com/item/32952591766.html) that one sees around quite a bit.
As far as I can tell, it's electrically similar to the ["Blue Pill"](../../BluePill) board, but just breaks out more of the pins to
convenient headers.

In this project, I'm just going to investigate the board in a bit more detail, and program it with the Arduino IDE
and the `STM32F1xx/GD32F1xx boards` package.

### Dev Board Features

STM32F103C8T6 core board main features, quoting one of the sellers:

1. One main chip of STM32F103C8, soldered on the motherboard
2. 8M crystal (up to 72M through the internal PLL of the chip) ST official standard parameters
3. LM1117-3.3V voltage regulator chip, providing a maximum current of 800mA
4. All the way to miniUSB interface, you can power the system version, reserved USB communication function
5. Reset (download) button
6. A set of function switch jumper pins
7. A standard JTAG download port, support JLink, ULINK, STLink
8. A standard SWD download interface, support JLink, ULINK, STLink
9. All user IO ports are led out (gold-plated pin header)
10. 1 power indicator
11. A function indicator, used to verify the basic functions of the IO port
12. Reserved serial port download interface, easy to connect with 5V development board, you can download the program by serial port
13, the use of two large-capacity filter capacitors to improve the stability of the product and anti-interference
14. Size: 45x62mm

The seller offers [programming software](https://pan.baidu.com/s/1o8wTzp4) but it is behind a membership wall, and it is probably Windows only,
so I have left that well alone.

![module_layout](./assets/module_layout.jpg?raw=true)


### Programming with the Arduino IDE

Adding Board Support to the IDE

A Boards Manager package is created by Dan Drown, the instructions are on
[the stm32duino site](http://wiki.stm32duino.com/index.php?title=Boards_Manager_package)

Add custom boards package [package_STM32duino_index.json](http://dan.drown.org/stm32duino/package_STM32duino_index.json) in Preferences.

### Connecting a Serial Programmer

I'm using a CH340G USB-serial adapter from MacOSX (similar but different to FTDI-based adapters).

Connections are as follows:

| USB-Serial | Board    |
|------------|----------|
|  GND       |  GND     |
|  VCC       |  5V      |
|  RXD       |  TXD     |
|  TXD       |  RXD     |


### Uploading Sketch

The [Blinky.ino](./Blinky/Blinky.ino) sketch is just about the simplest thing possible - blinks the LED connected on port PC13.
This is not showing off the board capabilities at all - I'm just trying to verify the programming process.

Selecting programming options:

![arduino_ide_programming_settings](./assets/arduino_ide_programming_settings.png?raw=true)

To program, BOOT0 needs to be pulled high to 3.3V, and BOOT1 pulled to ground.
On the 48pin board, this requires adding a patch wire on each pin.


| BOOT0 | BOOT1 | Mode |
|-------|-------|------|
| 0     | x     | Boot from User Flash. This is normal operating mode. |
| 1     | 0     | Boot from System Memory. This contains the embedded bootloader, and is used for programming |
| 1     | 1     | Boot from embedded SRAM. Used for other STM32 variants, but not the STM32F10x |


Console log from the programming phase:

```
Sketch uses 14012 bytes (21%) of program storage space. Maximum is 65536 bytes.
Global variables use 2464 bytes (12%) of dynamic memory, leaving 18016 bytes for local variables. Maximum is 20480 bytes.
/Users/paulgallagher/Library/Arduino15/packages/stm32duino/tools/stm32tools/2018.4.29/macosx/serial_upload cu.wchusbserial1420 {upload.altID} {upload.usbID} /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_499495/Blinky.ino.bin
stm32flash Arduino_STM32_0.9

http://github.com/rogerclarkmelbourne/arduino_stm32

Using Parser : Raw BINARY
Interface serial_posix: 115200 8E1
Version      : 0x22
Option 1     : 0x00
Option 2     : 0x00
Device ID    : 0x0410 (Medium-density)
- RAM        : 20KiB  (512b reserved by bootloader)
- Flash      : 128KiB (sector size: 4x1024)
- Option RAM : 16b
- System RAM : 2KiB
Write to memory
Erasing memory

Wrote address 0x08000100 (1.83%)
Wrote address 0x08000200 (3.65%)
...(etc)...
Wrote address 0x08003600 (98.66%)
Wrote address 0x080036bc (100.00%) Done.

Starting execution at address 0x08000000... done.
```


![Build](./assets/48pinDevBoard_build.jpg?raw=true)

## Credits and References

* [48-pin ARM Cortex-M3 STM32F103C8T6 Core Board](https://www.aliexpress.com/item/32952591766.html) - example from an aliexpress seller
* [STM32F103C8 product info](https://www.st.com/content/st_com/en/products/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus/stm32-mainstream-mcus/stm32f1-series/stm32f103/stm32f103c8.html)
