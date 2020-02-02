# #529 ATtiny Pin Change Interrupts

How to use pin change interrupts with the ATtiny85

![Build](./assets/PinChangeInterrupts_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/JwgccoQ1pn0/0.jpg)](https://www.youtube.com/watch?v=JwgccoQ1pn0)

## Notes

The ATtiny only has one hardware interrupt pin (PB0) but since this is often used for other purposes (like I²C),
handling interrupts on other pins needs to be done using the pinc change interrupt
(see 9.2 External Interrupts in the datasheet).

This example demonstrates pin change interrupts being used to detect and debounce a pushbutton.
On every change, and LED is toggled.

### Setting up Pin Change Interrupts

Two steps required:

1. The relevant bits of the Pin Change Mask Register (PCMSK) register are set to enable interrupts for pins PCINT0 to PCINT5

2. Enable Pin Change Interrupt by setting bit PCIE in the General Interrupt Mask Register (GIMSK) register

The ATtiny hardware support for the Arduino IDE includes a number of macros to help generalise the register control, including:

* `digitalPinToPCMSKbit` for setting PCMSK register
* `digitalPinToPCICRbit` for setting GIMSK register

Pin definitions, with specific reference to the 8-pin PDIP8 ATtiny85:

| Interrupt pin | Port bit | PDIP8 Pin |
|---------------|----------|-----------|
| PCINT0        | PB0      | 5         |
| PCINT1        | PB1      | 6         |
| PCINT2        | PB2      | 7         |
| PCINT3        | PB3      | 2         |
| PCINT4        | PB4      | 3         |
| PCINT5        | PB5      | 1         |

## Example Sketch

The [PinChangeInterrupts.ino](./PinChangeInterrupts.ino?raw=true) sketch is a simple demonstration of
pin change interrupts. It uses the ATtiny register macros to setup the registers accordingly.

The ATtiny85 is programmed using the Arduino ISP sketch running on an Arduino Uno.
See [LEAP#070 ProgrammingWithArduinoISP](../ProgrammingWithArduinoISP) for more info.

## Construction

![Breadboard](./assets/PinChangeInterrupts_bb.jpg?raw=true)

![Schematic](./assets/PinChangeInterrupts_schematic.jpg?raw=true)

![Build](./assets/PinChangeInterrupts_build.jpg?raw=true)

## Credits and References

* [Atmel ATtiny85 Product Info](http://www.atmel.com/devices/ATTINY85.aspx)
* [PinChangeInterrupt-0001.zip](https://code.google.com/archive/p/arduino-tiny/downloads?page=2) - library source (not used here)
* [ATtiny85 Interrupt Barebones Example](https://www.instructables.com/id/ATtiny85-Interrupt-Barebones-Example/)
