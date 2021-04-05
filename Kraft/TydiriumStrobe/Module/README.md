# #591 Tydirium Strobe Module

Packaging the ATtiny85 Lambda-class shuttle "Tydirium" navigation strobe circuit as a small board that can be added to an existing lighting setup.

![Build](./assets/Module_build.jpg?raw=true)

## Notes

In [LEAP#589](../) I figured out the navigation strobe pattern for the Tydirium shuttle and demonstrated it with a freeform circuit.

This project describes a variation of the circuit on a small module/board that could be used to add the ELD flashing pattern to
existing LED wiring.

## Circuit

The ATtiny85 microprocessor does all the hard work, with some support circuitry:

* zener diode provides some basic over-voltage protection.
* a 2N7000 n-channel MOSFET for low-side LED control, instead of driving directly from the ATtiny85. This will allow it to switch up to 500mA of LED current.

Although the circuit is best powered with 3-5V, it can handle up to about 10V without complaint. A 9V battery will incur [150mW](https://www.wolframalpha.com/input/?i=%289V-5.1V%29%5E2%2F100%CE%A9) dropped across the 100Ω resistor.

![Breadboard](./assets/Module_bb.jpg?raw=true)

![Schematic](./assets/Module_schematic.jpg?raw=true)

![Breadboard Build](./assets/Module_bb_build.jpg?raw=true)

## Module Design

The module is designed to be easily fitted to existing circuits.

There are three connections required:

* positive power supply for the microcontroller. Ideally 3-5V, but can handle up to 9V.
* negative power supply for the microcontroller.
* the negative end of the LED(s) to be switched.

These connections can be made to either:

* the screw terminals on the board
* or soldered to the corresponding solder pads

![Module_usage_annotated](./assets/Module_usage_annotated.jpg?raw=true)

The LEDs may be separately powered from the microcontroller, provided both power supplies share a common ground.
For example:

* 2 x AAA/AA (3V) batteries could be used to power the microcontroller
* a 12V power pack is powering a LED array
* will work fine, as long as the negative of the 12V power pack is also connected to the negative of the battery pack

## Programming

The ATtiny85 is programmed with the [TydiriumStrobe.ino](../TydiriumStrobe.ino) sketch.

## Credits and References

* [LEAP#589 Tydirium Strobe](../)
* [Atmel ATtiny85 Product Info](http://www.atmel.com/devices/ATTINY85.aspx)
