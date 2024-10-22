# #591 Tydirium Strobe Module

Packaging the ATtiny85 Lambda-class shuttle "Tydirium" navigation strobe circuit as a small board that can be added to an existing lighting setup.

![Build](./assets/Module_build.jpg?raw=true)

## Notes

In [LEAP#589](../) I figured out the navigation strobe pattern for the Tydirium shuttle and demonstrated it with a freeform circuit.

This project describes a variation of the circuit on a small module/board that could be used to add the LED flashing pattern to
existing LED wiring.

## Circuit

The ATtiny85 microprocessor does all the hard work, with some support circuitry:

* zener diode provides some basic over-voltage protection.
* a 2N7000 n-channel MOSFET for low-side LED control, instead of driving directly from the ATtiny85. This allows it to switch pulses of up to 500mA current through the LEDs.

Although the circuit is best powered with 3-5V, it can handle up to 9V without complaint. A 9V battery will incur [150mW](https://www.wolframalpha.com/input/?i=%289V-5.1V%29%5E2%2F100%CE%A9) dropped across the 100Ω resistor.

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

### For LED Power Supplies 3-9V

If the existing LED circuit is powered with between 3V and 9V, the module does not need a separate power supply.
Connections

* LED power supply positive connected to module positive (POWER+)
* LED power supply negative connected to module negative (POWER-)
* the negative end of the LED(s) to be switched connected to the module LED negative (LED-).

![single_ps_schematic](./assets/single_ps_schematic.jpg?raw=true)

### For LED Power Supplies over 9V

If the existing LED circuit is powered with over 9V, the module will need a seperate power, ideally 3-5V.

The easiest way of doing this is to add a separate battery pack for the module.
This will work fine, as long as the negative connections of the two power supplies and the module all share a common connection.

For example:

* a 12V power pack powering a LED array
* 2 x AAA/AA (3V) batteries to power the microcontroller

![separate_ps_schematic](./assets/separate_ps_schematic.jpg?raw=true)

### Using Existing LED Wiring

For power supply voltages over 3V, LEDs will generally require current limiting resistors to prevent them from being overloaded and burning out.

Existing (non-blinking) LED wiring would have already taken this into account,
and current limiting resistors only need to be considered if adding new LEDs to the circuit.

## Demonstration

Here's a quick test with a 3V (2xAAA) battery pack. At this voltage, an LED doesn't really need a curret limiting resistor,
so in this example, an LED is just directly connected between POWER+ and the LED- control terminal.

![Module_test](./assets/Module_test.jpg?raw=true)

## Programming

The ATtiny85 is programmed with the [TydiriumStrobe.ino](../TydiriumStrobe.ino) sketch.

## Credits and References

* [LEAP#589 Tydirium Strobe](../)
* [Atmel ATtiny85 Product Info](http://www.atmel.com/devices/ATTINY85.aspx)
