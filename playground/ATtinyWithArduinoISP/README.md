# #069 ATtinyWithArduinoISP

Programming an ATTINY85-20PU on a breadboard with Arduino ISP

Here's a quick video of it in action:

[![ATtinyWithArduinoISP](http://img.youtube.com/vi/eILb11BE6pY/0.jpg)](http://www.youtube.com/watch?v=eILb11BE6pY)

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

### Construction

![The Breadboard](./assets/ATtinyWithArduinoISP_bb.jpg?raw=true)

![The Schematic](./assets/ATtinyWithArduinoISP_schematic.jpg?raw=true)

![The Build](./assets/ATtinyWithArduinoISP_build.jpg?raw=true)

NB: in the picture, pins 5 and 6 are wired LEDs. These are for a test scketch and not required for programming
(but neither do they interfere with buring the bootloader and uploading a sketch).

## Credits and References
* [Atmel ATtiny85 Product Info](http://www.atmel.com/devices/ATTINY85.aspx)
* [ATtiny microcontroller support for the Arduino IDE](https://github.com/damellis/attiny)
* [Programming an ATtiny w/ Arduino 1.6 (or 1.0)](http://highlowtech.org/?p=1695)
* [Programming an ATtiny with Arduino ISP](http://scuola.arduino.cc/lesson/qX1117g/Programming_an_ATtiny_with_Arduino_ISP)
