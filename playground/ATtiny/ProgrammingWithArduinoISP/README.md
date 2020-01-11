# #070 Programming an ATtiny With ArduinoISP

Programming an ATTINY85-20PU on a breadboard with Arduino ISP

Here's a quick video of it in action:

[![ProgrammingWithArduinoISP](https://img.youtube.com/vi/eILb11BE6pY/0.jpg)](https://www.youtube.com/watch?v=eILb11BE6pY)

## Notes

The objective here is to setup an ATTINY85-20PU chip on a breadboard, and program it using an Arduino operating as an in-system programmer.

### Adding ATiny support for Arduino IDE

I'm running Arduino 1.6.1 (MacOSX), so I first needed to add [ATiny support for Arduino IDE 1.6.x](https://github.com/damellis/attiny/tree/ide-1.6.x).
I always prefer to clone rather than download zips so I'm able to work on the source if necessary.
In these steps ${sketchbook_folder} refers to my actual sketchbook folder location.

```
git clone git@github.com:damellis/attiny.git
cd attiny
git checkout -b ide-1.6.x origin/ide-1.6.x
mkdir ${sketchbook_folder}/hardware
cp -R attiny ${sketchbook_folder}/hardware
```

After restarting Arduino, I now have new Tools menu options.

### Setup the Arduino ISP

Setup the Arduino ISP. Note in this case I'm using an Arduino Uno as the programmer:
* Select `Tools > Board > Arduino Uno`
* Select `Tools > Port > (correct port for Arduino Uno)`
* Upload Examples/ArduinoISP sketch to Arduino Uno
* Select `Programmer > Arduino as ISP`

### Selecting ATtiny options

I went with the basics:
* `Tools > Board > ATtiny`
* `Tools > Processor > ATtiny85`
* `Tools > Clock > 1MHz (internal)`

### Burning the Bootloader

Depending on the state of the chip, this may not be necessary. But if in doubt, burn it again:
* Select `Tools > Burn Bootloader`

### Uploading a Sketch

I'm testing with [TinyBlink](../TinyBlink) which runs LEDs on digital pins 0 and 1.
* Open desired sketch
* Select `File > Upload Using Programmer` (or shift-click the normal upload icon)

Crickey, it works.


### How Fast is the Clock?

The ATtiny85 can use an external clock, but by default it uses an internal oscillator.
The internal oscillator runs at 8 MHz, prescaled down to 1 MHz by default.

The clock settings are in the fuses. I used avrdude to read the settings:

```
$ avrdude -c stk500v1 -p attiny85 -P /dev/cu.usbmodem14521 -b 19200 -U lfuse:r:-:i

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.05s

avrdude: Device signature = 0x1e930b (probably t85)
avrdude: reading lfuse memory:

Reading | ################################################## | 100% 0.02s

avrdude: writing output file "<stdout>"
:01000000629D
:00000001FF

avrdude: safemode: Fuses OK (E:FF, H:DF, L:62)

avrdude done.  Thank you.
```

The [engbedded fusecalc](http://www.engbedded.com/fusecalc) site is invaluable for decoding or calculating fuses values.

It confirms that E:FF, H:DF, L:62 are factory defaults: 8 MHz internal oscillator with CKDIV8 prescaler: so it is running at 1 MHz.


### Programming with avrdude

The Arduino IDE now includes the ability to export the compiled binary.
This option, found in the "Sketch" menu produces [TinyBlink.ino.tiny8.hex](../TinyBlink/TinyBlink.ino.tiny8.hex)
from the [TinyBlink](../TinyBlink) source.

![export_compiled_binary](./assets/export_compiled_binary.png?raw=true)

avrdude can then be used to directly upload the hex file via the Arduino ISP:

```
$ avrdude -v -c stk500v1 -p attiny85 -P /dev/cu.usbmodem14521 -b 19200 -U flash:w:../TinyBlink/TinyBlink.ino.tiny8.hex:i

avrdude: Version 6.3, compiled on Sep 21 2018 at 19:09:46
         Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
         Copyright (c) 2007-2014 Joerg Wunsch

         System wide configuration file is "/usr/local/Cellar/avrdude/6.3_1/etc/avrdude.conf"
         User configuration file is "/Users/paulgallagher/.avrduderc"
         User configuration file does not exist or is not a regular file, skipping

         Using Port                    : /dev/cu.usbmodem14521
         Using Programmer              : stk500v1
         Overriding Baud Rate          : 19200
         AVR Part                      : ATtiny85
         Chip Erase delay              : 4500 us
         PAGEL                         : P00
         BS2                           : P00
         RESET disposition             : possible i/o
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
           eeprom        65     6     4    0 no        512    4      0  4000  4500 0xff 0xff
           flash         65     6    32    0 yes      8192   64    128  4500  4500 0xff 0xff
           signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00
           lock           0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
           lfuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
           hfuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
           efuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
           calibration    0     0     0    0 no          1    0      0     0     0 0x00 0x00

         Programmer Type : STK500
         Description     : Atmel STK500 Version 1.x firmware
         Hardware Version: 2
         Firmware Version: 1.18
         Topcard         : Unknown
         Vtarget         : 0.0 V
         Varef           : 0.0 V
         Oscillator      : Off
         SCK period      : 0.1 us

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.02s

avrdude: Device signature = 0x1e930b (probably t85)
avrdude: safemode: hfuse reads as DF
avrdude: safemode: efuse reads as FF
avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
         To disable this feature, specify the -D option.
avrdude: erasing chip
avrdude: reading input file "../TinyBlink/TinyBlink.ino.tiny8.hex"
avrdude: writing flash (676 bytes):

Writing | ################################################## | 100% 0.99s

avrdude: 676 bytes of flash written
avrdude: verifying flash memory against ../TinyBlink/TinyBlink.ino.tiny8.hex:
avrdude: load data flash data from input file ../TinyBlink/TinyBlink.ino.tiny8.hex:
avrdude: input file ../TinyBlink/TinyBlink.ino.tiny8.hex contains 676 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 0.50s

avrdude: verifying ...
avrdude: 676 bytes of flash verified

avrdude: safemode: hfuse reads as DF
avrdude: safemode: efuse reads as FF
avrdude: safemode: Fuses OK (E:FF, H:DF, L:62)

avrdude done.  Thank you.
```

### Construction

![The Breadboard](./assets/ProgrammingWithArduinoISP_bb.jpg?raw=true)

![The Schematic](./assets/ProgrammingWithArduinoISP_schematic.jpg?raw=true)

![Build](./assets/ProgrammingWithArduinoISP_build.jpg?raw=true)

NB: in the breadboard, pins 5 and 6 are wired LEDs. These are for a test scketch and not required for programming
(but neither do they interfere with buring the bootloader and uploading a sketch).

## Credits and References
* [LEAP#071 TinyBlink](../TinyBlink) - a simple ATtiny test sketch
* [LEAP#253 ProgrammingShield](../ProgrammingShield) - a programming shield version of this project
* [Atmel ATtiny85 Product Info](http://www.atmel.com/devices/ATTINY85.aspx)
* [ATtiny microcontroller support for the Arduino IDE](https://github.com/damellis/attiny)
* [Programming an ATtiny w/ Arduino 1.6 (or 1.0)](http://highlowtech.org/?p=1695)
* [Programming an ATtiny with Arduino ISP](http://scuola.arduino.cc/lesson/qX1117g/Programming_an_ATtiny_with_Arduino_ISP)
* [engbedded fusecalc](http://www.engbedded.com/fusecalc)
