# #253 ProgrammingShield

A custom ATtiny programming shield for use with Arduino ISP

![Build](./assets/ProgrammingShield_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I covered programming an ATtiny with the Arduino ISP in the [ProgrammingWithArduinoISP](../ProgrammingWithArduinoISP) project.

Since I've been programming a few more ATtiny processors, and simplify the processing of
programming an ATtiny with ArduinoISP, I wired up a strip of protoboard
to serve as a custom programming shield. This is the layout I chose:

![ProgrammingShield_layout](./assets/ProgrammingShield_layout.jpg?raw=true)

It's designed to be snapped onto an Arduino UNO, lined up with GPIO digital pins 8-13.

It includes two LEDs on PB0 and PB1, which can be used for debugging/testing a program loaded on the ATtiny.

## Construction

![Breadboard](./assets/ProgrammingShield_bb.jpg?raw=true)

![Schematic](./assets/ProgrammingShield_schematic.jpg?raw=true)

![ProgrammingShield_layout](./assets/ProgrammingShield_layout.jpg?raw=true)

![ProgrammingShield_layout2](./assets/ProgrammingShield_layout2.jpg?raw=true)

## Credits and References
* [LEAP#070 ProgrammingWithArduinoISP](../ProgrammingWithArduinoISP) - programming an ATtiny with the Arduino ISP
* [LEAP#071 TinyBlink](../TinyBlink) - a simple ATtiny test sketch
* [Atmel ATtiny85 Product Info](http://www.atmel.com/devices/ATTINY85.aspx)
* [ATtiny microcontroller support for the Arduino IDE](https://github.com/damellis/attiny)
* [Programming an ATtiny w/ Arduino 1.6 (or 1.0)](http://highlowtech.org/?p=1695)
* [Programming an ATtiny with Arduino ISP](http://scuola.arduino.cc/lesson/qX1117g/Programming_an_ATtiny_with_Arduino_ISP)
* [..as mentioned on my blog](https://blog.tardate.com/2017/02/leap253-attiny-programming-shield.html)
