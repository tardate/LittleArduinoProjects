# #819 74LS161 Binary Counter

About the 74LS161 4-bit Binary Counter with Asynchronous Reset, illustrated with a simple counter demonstration.

![Build](./assets/BinaryCounter_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/sj4BRpH6dp4/0.jpg)](https://www.youtube.com/watch?v=sj4BRpH6dp4)

## Notes

The 74LS161 is a synchronous 4-bit binary counter from the Low-Power Schottky (LS) TTL family. It counts upward on each rising edge of the clock when enabled, with all flip-flops clocked simultaneously to ensure glitch-free operation. The device includes synchronous parallel load inputs, allowing a specific 4-bit value to be preset, as well as asynchronous clear to reset the counter to zero.

Operating from a 5 V supply, the 74LS161 offers fast switching speeds and predictable timing, making it suitable for high-speed counting, frequency division, and timing applications. It has been widely used in digital clocks, counters, state machines, and control logic in classic TTL-based systems. Its synchronous design provides cleaner and more reliable operation than older ripple counters, which is why it became a staple in both educational and industrial digital electronics.

### 74LS161 Pinout

![74ls161-pinout](../assets/74ls161-pinout.jpg)

### Circuit Design

This is a basic demonstration of the 74LS161. Key features of the circuit:

* clock pulse is provided by [LEAP#791 555 Breadboard Pulse Generator](../../555Timer/BreadboardPulseGen/)
* the 74LS161 is configure to provide a sequential BCD count
    * Master Reset is pulled high with a resistor (as recommended in the datasheet)

Designed with Fritzing: see [BcdCounter.fzz](./BcdCounter.fzz).

![bb](./assets/BinaryCounter_bb.jpg?raw=true)

![schematic](./assets/BinaryCounter_schematic.jpg?raw=true)

![bb_build](./assets/BinaryCounter_bb_build.jpg?raw=true)

## Credits and References

* [74LS161 datasheet](https://www.futurlec.com/74LS/74LS161.shtml) - 4-bit Binary Counter with Asynchronous Reset
