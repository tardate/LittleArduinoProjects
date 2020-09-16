# #562 1-bit Register

Building a basic manually controlled 1-bit register that demonstrates the key features of a digital register.

![Build](./assets/1bitRegister_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/QItWfNkyWDw/0.jpg)](https://www.youtube.com/watch?v=QItWfNkyWDw)

## Notes

Another micro-project inspired by Ben Eater's descent into digital logic.
This is a quick build of a basic 1-bit register using 7000-series CMOS logic that demostrates
the key features we require in a functional digital register:

* input loaded only when a "load enable" signal is present
* latching of the value read into the register
* tri-state output control: high, low, or high-impedence (high Z)

The ideas demonstrated here are covered in depth in one of Ben Eater's videos from his 8-bit computer series,
"Designing and building a 1-bit register - 8 bit register - Part 3":

[![clip](https://img.youtube.com/vi/-arYx_oVIj8/0.jpg)](https://www.youtube.com/watch?v=-arYx_oVIj8)

## Logic Design

The basic concepts:

* A D latch provides the central storage of current state
* The load signal is combined with the data signal (with inverter, AND and Or gates) such that:
  * when load is low, the current output is fed back as the current input (no change in output state)
  * when load is high, the data value is presented as the input data for the D latch
* a tri-state output ensures:
  * the D latch output (Q) is only present on the final output when output is enabled
  * when output is disabled, the output is high impedence

![logic_design](./assets/logic_design.jpg?raw=true)

NB: I sketched this in [logic.ly](https://logic.ly/demo) (unsaved - still looking for a good online digital logic editor)


## Truth Table

| Load | Data | Output Enable | Clock | Output (Q) |
|------|------|---------------|-------|------------|
| 0    | 0    | 1             | ↑     | Z          |
| 0    | 1    | 1             | ↑     | Z          |
| 1    | 0    | 1             | ↑     | Z          |
| 1    | 1    | 1             | ↑     | Z          |
| 0    | 0    | 0             | ↑     | Q₀         |
| 0    | 1    | 0             | ↑     | Q₀         |
| 1    | 0    | 0             | ↑     | 0          |
| 1    | 1    | 0             | ↑     | 1          |

Legend/Notes:

* 0 - logical 0 (low)
* 0 - logical 1 (high)
* Q₀ - output stays the same
* ↑ - rising edge
* Z - high impedence
* Output Enable is active low

## Construction

The design can be realised with fundamental building blocks from the 7000-series CMOS series:

* 74LS04 - provides the inverter (only 1 or 8 used)
* 74LS08 - provides the AND gates (only 2 of 4 used)
* 74LS32 - provides the OR gates (only 1 of 4 used)
* 74LS374 - provides the D lath and tri-state output (only 1 of 8 used)

![Schematic](./assets/1bitRegister_schematic.jpg?raw=true)

I built the circuit on a bread board, with additional components for manual control:

* a 3 switch DIP switch unit implements Data, Load, and Output Enable. Each has an associated pull-down resistor and LED indicator
* a push-button with pull-down resistor provides a manual clock input
* the final output is wired to 2 LEDs with current-limiting resistors:
  * when output HIGH, the green LED is lit
  * when output LOW, the red LED is lit
  * when output is high Z, both red and green LEDs are lit, but a little dimly

![Build](./assets/1bitRegister_build.jpg?raw=true)

## Credits and References

* [74LS04 Datasheet](https://www.futurlec.com/74LS/74LS04.shtml) - Hex Inverting Gates
* [74LS08 Datasheet](https://www.futurlec.com/74LS/74LS08.shtml) - Quad 2-Input AND Gates
* [74LS32 Datasheet](https://www.futurlec.com/74LS/74LS32.shtml) - Quad 2-Input OR Gate
* [74LS374 Datasheet](https://www.futurlec.com/74LS/74LS374.shtml) - 3-STATE Octal D-Type Edge-Triggered Flip-Flops
