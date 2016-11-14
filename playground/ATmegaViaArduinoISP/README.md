# #068 ATmegaViaArduinoISP

Programming an ATMEGA328P-PU on a breadboard with Arduino ISP


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The objective here is to setup an ATMEGA328P-PU chip on a breadboard, and program it via an Arduino operating as an in-system programmer.

See more links and references at the end, but these videos cover at all very well:
* [Arduino as ISP](https://youtu.be/muP1dp73Mdg)
* [Arduino on a Breadboard](https://youtu.be/ufQZnAAxZ7A)

Wire up according the schematics attached.
The [ATmega168/328-Arduino Pin Mapping](http://www.arduino.cc/en/Hacking/PinMapping168) page is a good reference for understanding how the chip pins relate to familiar Arduino functions.

Setup the Arduino ISP. Note in this case I'm using an Arduino Uno as the programmer:
* Select `Tools > Board > Arduino Uno`
* Select `Tools > Port > (correct port for Arduino Uno)`
* Upload Examples/ArduinoISP sketch to Arduino Uno
* Select `Programmer > Arduino as ISP`

Next burning the bootloader. A bootloader may already be present on the chip in which case this may not be necessary.
But if in doubt, burn it again:
* Select `Tools > Burn Bootloader`

Now the system is ready for uploading a sketch.
* Open desired sketch
* Select `File > Upload Using Programmer` (or shift-click the normal upload icon)

Crickey, it works.

### Construction

![The Breadboard](./assets/ATmegaViaArduinoISP_bb.jpg?raw=true)

![The Schematic](./assets/ATmegaViaArduinoISP_schematic.jpg?raw=true)

![The Build](./assets/ATmegaViaArduinoISP_build.jpg?raw=true)

NB: in the picture, digital pin 9 (chip pin 15) is wired to a LED for a test scketch

## Credits and References
* [Atmel ATmega328P Product Info](http://www.atmel.com/devices/ATMEGA328P.aspx)
* [ATmega168/328-Arduino Pin Mapping](http://www.arduino.cc/en/Hacking/PinMapping168)
* [Arduino as ISP](https://youtu.be/muP1dp73Mdg)
* [Arduino on a Breadboard](https://youtu.be/ufQZnAAxZ7A)
* [Building an Arduino on a Breadboard](http://www.arduino.cc/en/Main/Standalone)
* [Using an Arduino as an AVR ISP ](http://www.arduino.cc/en/Tutorial/ArduinoISP)
* [From Arduino to a Microcontroller on a Breadboard](http://www.arduino.cc/en/Tutorial/ArduinoToBreadboard)
* [1-Day Project: Build Your Own Arduino Uno for $5](https://www.youtube.com/watch?v=sNIMCdVOHOM)
