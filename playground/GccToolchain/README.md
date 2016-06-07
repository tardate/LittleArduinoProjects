# #220 GccToolchain

Programming an Arduino with C and a command line.

## Notes

The [Arduino IDE](https://www.arduino.cc/en/Main/Software) is the most convenient way to get started with Arduino,
but it does obscure the underlying mechanics of building software for an Arduino.

How to do it from scratch?

I use a Mac and homebrew, so what follows is a MacOSX-specific guide to building software for an Arduino from the command line.
I'm using a few posts from the net as my guide, in particular
[Setting up AVR-GCC Toolchain on Linux and Mac OS X](http://maxembedded.com/2015/06/setting-up-avr-gcc-toolchain-on-linux-and-mac-os-x/)
from maxembedded.


### Software Components

[homebrew](https://github.com/Homebrew/homebrew)

### Software Installation

```
brew tap osx-cross/avr
brew install avr-libc
brew install avrdude --with-usb
```

### Testing the Software Installation

```
$ which avr-gcc
/usr/local/bin/avr-gcc
$ avr-gcc --version
avr-gcc (GCC) 4.9.3
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
$ which avrdude
/usr/local/bin/avrdude
$ avrdude -?
Usage: avrdude [options]
[...]
avrdude version 6.3, URL: <http://savannah.nongnu.org/projects/avrdude/>
```

All good to go!

### Example: blinky.c

Use avr-lib to compile and generate the Intel Hex format file.
Source is `blinky/blinky.c` and is written for an atmega328p/Arduino Uno.

```
$ cd blinky
$ avr-gcc -w -Os -Wl,--gc-sections -DF_CPU=16000000UL -mmcu=atmega328p -c blinky.c
$ avr-gcc -mmcu=atmega328p blinky.o -o blinky.elf
$ avr-objcopy -j .text -j .data -O ihex blinky.elf blinky.hex
```

I have an Arduino connected to the USB and appearing on /dev/cu.usbmodem14541.
Use avrdude to flash it with some options:

* `-D` : disable auto erase for flash
* `-v` : verbose output
* `-c arduino` : specify the programmer to be used
* `-p atmega328p`
* `-P /dev/cu.usbmodem14541` : port
* `-b 115200` : baud rate
* `-U flash:w:blinky.hex:i` : Perform a memory operation:
  * `flash` : memtype is flash ROM
  * `w` : read the specified file (blinky.hex) and write it to flash (memtype)
  * `i` : specify the file is Intel Hex format


```
$ avrdude -D -v -c arduino -p atmega328p -P /dev/cu.usbmodem14541 -b 115200 -U flash:w:blinky.hex:i

avrdude: Version 6.3, compiled on Mar 15 2016 at 21:26:45
         Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
         Copyright (c) 2007-2014 Joerg Wunsch

         System wide configuration file is "/usr/local/Cellar/avrdude/6.3/etc/avrdude.conf"
         User configuration file is "/Users/paulgallagher/.avrduderc"
         User configuration file does not exist or is not a regular file, skipping

         Using Port                    : /dev/cu.usbmodem14541
         Using Programmer              : arduino
         Overriding Baud Rate          : 115200
         AVR Part                      : ATmega328P
         Chip Erase delay              : 9000 us
         PAGEL                         : PD7
         BS2                           : PC2
         RESET disposition             : dedicated
         RETRY pulse                   : SCK
         serial program mode           : yes
         parallel program mode         : yes
         Timeout                       : 200
         StabDelay                     : 100
         CmdexeDelay                   : 25
         SyncLoops                     : 32
         ByteDelay                     : 0
         PollIndex                     : 3
         PollValue                     : 0x53
         Memory Detail                 :

                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           eeprom        65    20     4    0 no       1024    4      0  3600  3600 0xff 0xff
           flash         65     6   128    0 yes     32768  128    256  4500  4500 0xff 0xff
           lfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
           hfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
           efuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
           lock           0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
           calibration    0     0     0    0 no          1    0      0     0     0 0x00 0x00
           signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00

         Programmer Type : Arduino
         Description     : Arduino
         Hardware Version: 3
         Firmware Version: 4.4
         Vtarget         : 0.3 V
         Varef           : 0.3 V
         Oscillator      : 28.800 kHz
         SCK period      : 3.3 us

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.00s

avrdude: Device signature = 0x1e950f (probably m328p)
avrdude: safemode: hfuse reads as 0
avrdude: safemode: efuse reads as 0
avrdude: reading input file "blinky.hex"
avrdude: writing flash (178 bytes):

Writing | ################################################## | 100% 0.04s

avrdude: 178 bytes of flash written
avrdude: verifying flash memory against blinky.hex:
avrdude: load data flash data from input file blinky.hex:
avrdude: input file blinky.hex contains 178 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 0.03s

avrdude: verifying ...
avrdude: 178 bytes of flash verified

avrdude: safemode: hfuse reads as 0
avrdude: safemode: efuse reads as 0
avrdude: safemode: Fuses OK (E:00, H:00, L:00)

avrdude done.  Thank you.
```

### Example: Makefile

The commands above are a bit tedious. A simple [Makefile](./blinky/Makefile) automates the process:

```
$ cd blinky
$ make clean
rm *.o
rm *.elf
rm *.hex
$ make
avr-gcc -w -Os -Wl,--gc-sections -DF_CPU=16000000UL -mmcu=atmega328p -c blinky.c
avr-gcc -mmcu=atmega328p blinky.o -o blinky.elf
avr-objcopy -j .text -j .data -O ihex blinky.elf blinky.hex
$ make flash
avrdude -D -v -c arduino -p atmega328p -P /dev/cu.usbmodem14541 -b 115200 -U flash:w:blinky.hex:i
[...]
avrdude done.  Thank you.
```

## Credits and References
* [homebrew](https://github.com/Homebrew/homebrew)
* [avr-gcc](https://gcc.gnu.org/wiki/avr-gcc) - GCC Wiki
* [avrdude](http://savannah.nongnu.org/projects/avrdude/)
* [avrdude manual](http://ftp.yzu.edu.tw/nongnu//avrdude/avrdude-doc-5.10.pdf)
* [Setting up AVR-GCC Toolchain on Linux and Mac OS X](http://maxembedded.com/2015/06/setting-up-avr-gcc-toolchain-on-linux-and-mac-os-x/)
* [Programming Arduino Uno in pure C](https://balau82.wordpress.com/2011/03/29/programming-arduino-uno-in-pure-c/)
* [Options for the C compiler avr-gcc](http://www.nongnu.org/avr-libc/user-manual/using_tools.html)
* [Intel HEX](https://en.wikipedia.org/wiki/Intel_HEX) - wikipedia
