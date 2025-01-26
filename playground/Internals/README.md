# #020 Internals

This is an investigation of all the internal details of the Arduino Board from a programming perspective.
Results are dumped to the serial port.

## Notes

This is a sketch that reports on a chip's capabilities. It runs on the chip itself, rather than examining externally.

I've since enhanced this to merge in capabilities from Nick Gammon's
[Atmega_Self_Read_Signature](https://github.com/nickgammon/arduino_sketches/tree/master/Atmega_Self_Read_Signature)

Here's typical output (from an Arduino Uno):

![Internals_build](./assets/Internals_build.jpg?raw=true)

## Collecting the Details

Some notes and references for how various details are collected...

### Digital Pins

Reporting on the digital pins relies on macros from Arduino core:

* [`NUM_DIGITAL_PINS`](https://github.com/arduino/ArduinoCore-avr/blob/3d09a51bd20f095e1354243e6d8addedfcb6001e/variants/standard/pins_arduino.h#L28)
* [digitalPinToInterrupt](https://github.com/arduino/ArduinoCore-avr/blob/3d09a51bd20f095e1354243e6d8addedfcb6001e/variants/standard/pins_arduino.h#L79)
* [digitalPinHasPWM](https://github.com/arduino/ArduinoCore-avr/blob/3d09a51bd20f095e1354243e6d8addedfcb6001e/variants/standard/pins_arduino.h#L32)

Since these are marcos based on the compiled source, they don't actually interogate the hardware - just report on the board
selected at compile time.

### Analog Pins

Reporting on the analog pins relies on macros from Arduino core:

* [`NUM_ANALOG_INPUTS`](https://github.com/arduino/ArduinoCore-avr/blob/3d09a51bd20f095e1354243e6d8addedfcb6001e/variants/standard/pins_arduino.h#L29)
* [analogInputToDigitalPin](https://github.com/arduino/ArduinoCore-avr/blob/3d09a51bd20f095e1354243e6d8addedfcb6001e/variants/standard/pins_arduino.h#L30)

Since these are marcos based on the compiled source, they don't actually interogate the hardware - just report on the board
selected at compile time.

### Processor Details

Reporting on processor details relies on macros from Arduino core:

* [clockCyclesPerMicrosecond](https://github.com/arduino/ArduinoCore-avr/blob/3d09a51bd20f095e1354243e6d8addedfcb6001e/cores/arduino/Arduino.h#L104) macro

Since these are marcos based on the compiled source, they don't actually interogate the hardware - just report on the board
selected at compile time.


### Memory Map

The AVR-libc manual has good information on
[AVR Memory Sections](https://www.nongnu.org/avr-libc/user-manual/mem_sections.html)
and how
[malloc uses memory](https://www.nongnu.org/avr-libc/user-manual/malloc.html)

A good summary explanation is available at
[www.avr-developers.com](http://www.avr-developers.com/mm/memoryusage.html)
The forum post on [Map layout of RAM](http://forum.arduino.cc/index.php?topic=186630.0) has a good example of accessing memory region addresses.

I first saw a trick for calculating free memory in 17.4. Storing and Retrieving Strings in Program Memory from the
[Arduino Cookbook](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU) - it basically calculating the delta between the address of a new function-level variable and
first location not yet allocated.


### EEPROM

The EEPROM address size is reported based on the
[E2END](https://www.nongnu.org/avr-libc/user-manual/group__avr__io.html) macro.

This is correct according to the board selection, hwoever it doesn't actually verify that is the actual EEPROM on the board.

There are techniques for probing EEPROM to verify the actual size (not implemented in this sketch).
See for example [Re: Runtime determination of EEPROM size](http://forum.arduino.cc/index.php?topic=120346.msg905783#msg905783)


## Output Full Transcript

Here's an example of the full output

```
--------------------------------
A Rundown of the Board Internals
Compiled on Jul 28 2018 at 14:29:46 with Arduino IDE 10802.
Signature: 0x1E950F
Processor: ATmega328P
Clock speed: 16 MHz
Fuses:
  Low:  11111111
  High: 11011110
  Ext:  11111101
  Lock: 11001111
--------------------------------
Number of digital pins: 20
0:
1:
2: (interrupt:0)
3: (interrupt:1) (PWM)
4:
5: (PWM)
6: (PWM)
7:
8:
9: (PWM)
10: (PWM)
11: (PWM)
12:
13: (internal LED)
14:
15:
16:
17:
18:
19:
Number of analog inputs: 6
A0: (pin:14)
A1: (pin:15)
A2: (pin:16)
A3: (pin:17)
A4: (pin:18)
A5: (pin:19)
--------------------------------
Memory Map:
0x0100 __data_start
0x0426 __data_end
0x0426 __bss_start
0x04D0 __bss_end
0x04D0 __heap_start
0x0000 __heap_end
0x04CC __brkval
0x04D0 __malloc_heap_start
0x0000 __malloc_heap_end
Free memory: 1060 bytes
0x08F4 &free_memory
--------------------------------
Flash memory size: 32768 bytes
Flash Page Size: 128 bytes
Last Flash Address: 0x7FFF
Last RAM Address: 0x08FF
Last Extended RAM Address: 0x08FF
--------------------------------
EEPROM memory: 1024 bytes
EEPROM page size: 4 bytes
--------------------------------
Bootloader in use: Yes
EEPROM preserved through erase: No
Watchdog timer always on: No
Bootloader is 512 bytes starting at 7E00
7E00: 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F
7E10: 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F
7E20: 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F
7E30: 30 31 32 33 34 35 36 37 38 39 3A 3B 3C 3D 3E 3F
7E40: 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F
7E50: 50 51 52 53 54 55 56 57 58 59 5A 5B 5C 5D 5E 5F
7E60: 60 61 62 63 64 65 66 67 68 69 6A 6B 6C 6D 6E 6F
7E70: 70 71 72 73 74 75 76 77 78 79 7A 7B 7C 7D 7E 7F
7E80: 80 81 82 83 84 85 86 87 88 89 8A 8B 8C 8D 8E 8F
7E90: 90 91 92 93 94 95 96 97 98 99 9A 9B 9C 9D 9E 9F
7EA0: A0 A1 A2 A3 A4 A5 A6 A7 A8 A9 AA AB AC AD AE AF
7EB0: B0 B1 B2 B3 B4 B5 B6 B7 B8 B9 BA BB BC BD BE BF
7EC0: C0 C1 C2 C3 C4 C5 C6 C7 C8 C9 CA CB CC CD CE CF
7ED0: D0 D1 D2 D3 D4 D5 D6 D7 D8 D9 DA DB DC DD DE DF
7EE0: E0 E1 E2 E3 E4 E5 E6 E7 E8 E9 EA EB EC ED EE EF
7EF0: F0 F1 F2 F3 F4 F5 F6 F7 F8 F9 FA FB FC FD FE FF
7F00: 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F
7F10: 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F
7F20: 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F
7F30: 30 31 32 33 34 35 36 37 38 39 3A 3B 3C 3D 3E 3F
7F40: 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F
7F50: 50 51 52 53 54 55 56 57 58 59 5A 5B 5C 5D 5E 5F
7F60: 60 61 62 63 64 65 66 67 68 69 6A 6B 6C 6D 6E 6F
7F70: 70 71 72 73 74 75 76 77 78 79 7A 7B 7C 7D 7E 7F
7F80: 80 81 82 83 84 85 86 87 88 89 8A 8B 8C 8D 8E 8F
7F90: 90 91 92 93 94 95 96 97 98 99 9A 9B 9C 9D 9E 9F
7FA0: A0 A1 A2 A3 A4 A5 A6 A7 A8 A9 AA AB AC AD AE AF
7FB0: B0 B1 B2 B3 B4 B5 B6 B7 B8 B9 BA BB BC BD BE BF
7FC0: C0 C1 C2 C3 C4 C5 C6 C7 C8 C9 CA CB CC CD CE CF
7FD0: D0 D1 D2 D3 D4 D5 D6 D7 D8 D9 DA DB DC DD DE DF
7FE0: E0 E1 E2 E3 E4 E5 E6 E7 E8 E9 EA EB EC ED EE EF
7FF0: F0 F1 F2 F3 F4 F5 F6 F7 F8 F9 FA FB FC FD FE FF

MD5 sum of bootloader = 0xF5 0xC8 0xE3 0xC3 0x1C 0x04 0x4B 0xAE 0x0E 0x65 0x56 0x95 0x60 0xB5 0x43 0x32
```

### Cross-checking the map file

Given last compilation with the Arduino IDE showed that it generated
`/var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_427024/Internals.ino.elf` in the console,
the  `avr-objdump` program was used to generate the map file:

    avr-objdump -t /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_427024/Internals.ino.elf > Internals.map

It verifies some of the basic memory details reported by the sketch, like `__bss_end`.

## Credits and References

* Chapter 17. Advanced Coding and Memory Handling - [Arduino Cookbook](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU)
* [A Tour of Arduino Internals](http://urbanhonking.com/ideasfordozens/2009/05/18/an_tour_of_the_arduino_interna/) - interesting blog post disecting how pin operations actually interact with the AVR microcontroller
* [Atmega_Self_Read_Signature](https://github.com/nickgammon/arduino_sketches/tree/master/Atmega_Self_Read_Signature) - part of Nick Gammon's suite of interesting sketches
