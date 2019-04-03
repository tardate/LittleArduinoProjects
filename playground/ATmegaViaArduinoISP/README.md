# #068 ATmegaViaArduinoISP

Programming an ATMEGA328P-PU on a breadboard with Arduino ISP

![The Build](./assets/ATmegaViaArduinoISP_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The objective here is to setup an ATMEGA328P-PU chip on a breadboard, and program it via an Arduino operating as an in-system programmer.
I subsequently built a DIY shield version of this project in [LEAP#099 ATmegaISPShield](../ATmegaISPShield).

See more links and references at the end, but these videos cover at all very well:

Arduino as ISP

[![clip](https://img.youtube.com/vi/muP1dp73Mdg/0.jpg)](https://www.youtube.com/watch?v=muP1dp73Mdg)

Arduino on a Breadboard

[![clip](https://img.youtube.com/vi/ufQZnAAxZ7A/0.jpg)](https://www.youtube.com/watch?v=ufQZnAAxZ7A)

Julian's Ardutorials: Arduino as an ISP

[![clip](https://img.youtube.com/vi/c8andV3OWr8/0.jpg)](https://www.youtube.com/watch?v=c8andV3OWr8)


### Programming Procedure

Wire up according the schematics attached.
The [ATmega168/328-Arduino Pin Mapping](http://www.arduino.cc/en/Hacking/PinMapping168) page is a good reference for understanding how the chip pins relate to familiar Arduino functions.

Setup the Arduino ISP. In this case I'm using an Arduino Uno as the programmer:
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


### Programming in-circuit via ICSP header

This approach can also be used to program chips on a board with an ICSP header.

The conventional arrangement of the ICSP pins is as follows. Although the pin numbering approach may vary,
the functions should be in these positions:

![icsp_header](./assets/icsp_header.png?raw=true)

The 5V power pin should only be connected if one wants to power the target board via the header.
If the board is already powered, it should not be connected.

Whether the target host can or should be powered via the header depends largely on the design of target circuit.

Here's a circuit (actually [LEAP#368 GranularSynth](../GranularSynth)) being programmed via an ICSP header:

![programming_via_icsp](./assets/programming_via_icsp.jpg?raw=true)


## Credits and References
* [LEAP#099 ATmegaISPShield](../ATmegaISPShield) - a DIY shield version of this project
* [Atmel ATmega328P Product Info](http://www.atmel.com/devices/ATMEGA328P.aspx)
* [ATmega168/328-Arduino Pin Mapping](http://www.arduino.cc/en/Hacking/PinMapping168)
* [Arduino as ISP](https://youtu.be/muP1dp73Mdg)
* [Arduino on a Breadboard](https://youtu.be/ufQZnAAxZ7A)
* [Building an Arduino on a Breadboard](http://www.arduino.cc/en/Main/Standalone)
* Nick Gammon's [How to make an Arduino-compatible minimal board](http://www.gammon.com.au/breadboard)
* [Using an Arduino as an AVR ISP](http://www.arduino.cc/en/Tutorial/ArduinoISP)
* [From Arduino to a Microcontroller on a Breadboard](http://www.arduino.cc/en/Tutorial/ArduinoToBreadboard)
* [AVR Programming](http://hackaday.com/2010/10/23/avr-programming-introduction/) - great little guide to avr ISP
* [1-Day Project: Build Your Own Arduino Uno for $5](https://www.youtube.com/watch?v=sNIMCdVOHOM)
