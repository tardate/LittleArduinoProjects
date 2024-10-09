# #563 4-bit Synchonous Counter

An example 4-bit synchronous counter with tri-state output, and controls for: count enable, output enable, number load, and clear.

![Build](./assets/4bitSynchonousCounter_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/jA2nFYgjZJw/0.jpg)](https://www.youtube.com/watch?v=jA2nFYgjZJw)

## Notes

This is a test of a 4-bit synchronous counter design as used by Ben Eater as the program counter for his 8-bit computer.

It is not useful on its own, but it does nicely demonstrate how a full-featured counter could be implemented in digital logic
using two core chips:

* 74LS161 - 4-bit Binary Counter: provides all the counter features
* 74LS245 - 3-state Octal Bus Transceiver: for tri-state output control

The specific features it demontrates:

* clock (CLK) - all actions performed on the rising edge of the clock pulse
* count enable (CE) - when high, the counter will increment on each clock pulse
* output enable (-CO, active low) - pulling this signal low will cause the counter output to appear on the output of the 74LS245 transceiver
* number load (-J, active low i.e "JUMP") - pulling this signal low will load the number appearing on P0-P3 on the next clock pulse
* clear (-CLR, active low) - pulling this signal low clears the counter

These are all the controls needed to implement a 4-bit address program counter.

### About the 74LS161

![74LS161](./assets/74LS161.jpg?raw=true)

### About the 74LS245

![74LS245](./assets/74LS245.jpg?raw=true)

## Construction

In the basic basic circuit:

* control signals are not connected to anything
* the bus (transceiver output) is not connected to anything externally, just feeds back as the P0-P3 connections for the counter
* only half the transceiver is used. How the counter output is mapped to the transceiver outputs is an arbitrary and application specific convention

![Breadboard](./assets/4bitSynchonousCounter_bb.jpg?raw=true)

![Schematic](./assets/4bitSynchonousCounter_schematic.jpg?raw=true)

For the actual build on the breadboard, I extended the circuit to make it manually testable:

* control signals conected to a series of DIP switches with pull-up resistor. This makes them manually controllable.
* P0-3 inputs simply tied to the 5V or GND rail as desired to indicated the value to be loaded into the counter
* LEDs with current limiting resistor are connected to the transciever output
* the clock input is replaced with the [LEAP#565 Single-Shot Trigger](../../BreadboardBling/SingleShotTrigger) so that clock pulses can be reliably manually generated

![4bitSynchonousCounter_bb_build](./assets/4bitSynchonousCounter_bb_build.jpg?raw=true)

## Credits and References

* [74LS161 datasheet](https://www.futurlec.com/74LS/74LS161.shtml) - 4-bit Binary Counter with Asynchronous Reset
* [74LS245 datasheet](https://www.futurlec.com/74LS/74LS245.shtml) - 3-state Octal Bus Transceiver
* [Program counter build](https://youtu.be/tNwU7pK_3tk) - Ben Eater's 8-bit Computer
