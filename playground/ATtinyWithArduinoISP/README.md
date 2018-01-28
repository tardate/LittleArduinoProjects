# #070 ATtinyWithArduinoISP

Programming an ATTINY85-20PU on a breadboard with Arduino ISP

Here's a quick video of it in action:

[![ATtinyWithArduinoISP](http://img.youtube.com/vi/eILb11BE6pY/0.jpg)](http://www.youtube.com/watch?v=eILb11BE6pY)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

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



### Construction

![The Breadboard](./assets/ATtinyWithArduinoISP_bb.jpg?raw=true)

![The Schematic](./assets/ATtinyWithArduinoISP_schematic.jpg?raw=true)

![Build](./assets/ATtinyWithArduinoISP_build.jpg?raw=true)

NB: in the breadboard, pins 5 and 6 are wired LEDs. These are for a test scketch and not required for programming
(but neither do they interfere with buring the bootloader and uploading a sketch).

## Credits and References
* LEAP: [TinyBlink](../TinyBlink) - a simple ATtiny test sketch
* LEAP: [ATtinyProgrammingShield](../ATtinyProgrammingShield) - a programming shield version of this project
* [Atmel ATtiny85 Product Info](http://www.atmel.com/devices/ATTINY85.aspx)
* [ATtiny microcontroller support for the Arduino IDE](https://github.com/damellis/attiny)
* [Programming an ATtiny w/ Arduino 1.6 (or 1.0)](http://highlowtech.org/?p=1695)
* [Programming an ATtiny with Arduino ISP](http://scuola.arduino.cc/lesson/qX1117g/Programming_an_ATtiny_with_Arduino_ISP)
* [engbedded fusecalc](http://www.engbedded.com/fusecalc)
