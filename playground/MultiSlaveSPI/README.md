# #190 MultiSlaveSPI

Using SPI to control multiple devices (that support an SPI-ish interface)

Here's a quick video of the circuit in action:

[![MultiSlaveSPI](https://img.youtube.com/vi/t2ncYWxmPbo/0.jpg)](https://www.youtube.com/watch?v=t2ncYWxmPbo)

## Notes

The [ShiftDriveSPI](../LED7Segment/ShiftDriveSPI) project demonstrated how hardware SPI can be used to control a system with a 74HC595 interface. The proposed benefit was that SPI allows multiple devices to be controlled with a minimal (+1) extension to the number of pins required.

This project is a test of SPI to control multiple (2) devices that support an "SPI-like" interface.

It's interesting how far you can push the definition of "SPI-like". In this case I'm using two devices:

* a [7-segment LED module](../LED7Segment/ShiftDriveModule) with a 74HC595 interface
* a [CounterModule](../CounterModule) with a CD4017 interface

These modules are all connected to the SPI interface of an Arduino, with a separate latch (SS/slave select) for each.
The data to each module actually passes down the same wire (MOSI).

The demo sketch does two things:

* runs a 0-9 counter on the 7-segment LED module (with decimal point enabled for even numbers)
* runs a countdown counter that cycles for each change on the LED module

## Construction

![Breadboard](./assets/MultiSlaveSPI_bb.jpg?raw=true)

![The Schematic](./assets/MultiSlaveSPI_schematic.jpg?raw=true)

![The Build](./assets/MultiSlaveSPI_build.jpg?raw=true)

## Credits and References

* [7-segment LED module](../LED7Segment/ShiftDriveModule)
* [CounterModule](../CounterModule)
* [Arduino SPI library](https://www.arduino.cc/en/Reference/SPI)
* [SPI](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus) - wikipedia
* [74HC595 Datasheet](https://www.futurlec.com/74HC/74HC595.shtml)
* [Sharing Clock and Data for 74HC595 and CD4021B Shift Registers?](http://electronics.stackexchange.com/questions/122520/sharing-clock-and-data-for-74hc595-and-cd4021b-shift-registers) - electronics.stackexchange
* [Driving 595 Shift Registers](http://www.appelsiini.net/2012/driving-595-shift-registers) - good article with AVR implementation details
* [Using Serial Peripheral Interface (SPI) Master and Slave with Atmel AVR Microcontroller](http://www.ermicro.com/blog/?p=1050) - well explained code
