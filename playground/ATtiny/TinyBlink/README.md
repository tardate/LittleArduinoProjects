# #071 TinyBlink

A simple LED blinking demonstration with an ATTINY85-20PU on a breadboard.

![The Build](./assets/TinyBlink_build.jpg?raw=true)

Here's a quick video of it in action:

[![ProgrammingWithArduinoISP](https://img.youtube.com/vi/eILb11BE6pY/0.jpg)](https://www.youtube.com/watch?v=eILb11BE6pY)

## Notes

The objective here is to demonstrate an ATTINY85-20PU chip running independently on a breadboard.

### Construction

Designed with Fritzing: see [TinyBlink.fzz](./TinyBlink.fzz).

The ATtiny85 is configured to use an internal clock, so no external connections are required except power and ground.

LEDs are attached to pin PB0 and PB1 simply to show "signs of life".

![The Breadboard](./assets/TinyBlink_bb.jpg?raw=true)

![The Schematic](./assets/TinyBlink_schematic.jpg?raw=true)

### The Sketch

See [TinyBlink.ino](./TinyBlink.ino).

The ATtiny85 is programmed using an Arduino Uno as described in [LEAP#070 Programming an ATtiny With ArduinoISP](../ProgrammingWithArduinoISP).

## Credits and References

* [LEAP#070 Programming an ATtiny With ArduinoISP](../ProgrammingWithArduinoISP)
* [ATtiny85 datasheet](https://www.microchip.com/en-us/product/ATTINY85)
* [ATtiny microcontroller support for the Arduino IDE](https://github.com/damellis/attiny)
