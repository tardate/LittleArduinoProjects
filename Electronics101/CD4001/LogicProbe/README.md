# #606 CD4001 Logic Probe

A simple logic probe using NOR gates.

![Build](./assets/LogicProbe_build.jpg?raw=true)

## Notes

This logic probe design can detect and indicate:

* logic high (red LED on)
* logic low (green LED on)
* oscillating signal (yellow LED on)

### About the CD4001

The CD4001BC is a Quad 2-Input NOR Buffered B Series Gate. Key features:

* operating range (VDD): 3-15V
* monolithic CMOS
* low power TTL compatibility
* all inputs protected by standard CMOS protection circuit; voltage at any pin −0.5V to VDD+0.5V

See the [CD4001 datasheet](https://www.futurlec.com/4000Series/CD4001.shtml) for more.

### Construction

The first NOR gate is used as an inverting buffer of the input signal.

When LOW input:

* first NOR gate output will be high
* with high output, D2 (green) on, D1 (red) off
* a fixed high signal will stall the oscillator on the 2nd and 3rd NOR gates
* R4 pulls the 3rd NOR gate input high, thus final NOT gate output will also be high, thus D3 (yellow) off

When HIGH input:

* first NOR gate output will be low
* with low output, D2 (green) off, D1 (red) on
* a fixed low signal will stall the oscillator on the 2nd and 3rd NOR gates
* R4 pulls the 3rd NOR gate input high, thus final NOT gate output will also be high, thus D3 (yellow) off

When input is oscillating:

* D2 (green), D1 (red) will flicker based on instantaneous input state
* oscillating input to the 2nd NOR gate will enable the oscillator on 2nd and 3rd NOR gates
* final NOR gate output will oscillate, causing D3 (yellow) to light up

Note:

* R4, R5 values are not critical. High values such as 1MΩ are satisfactory
* R5 is optional - it prevents oscillation when input is high Z/not connected.
* the link/short between the anode of D1 and cathode of D2 is used to inhibit D1/D2 when there is no strong input signal high or low
  * this is optional; the circuit works without it.
  * removing it will reduce power consumption of the circuit but D1/D2 will tend to be on when there is no strong input signal

![bb](./assets/LogicProbe_bb.jpg?raw=true)

![schematic](./assets/LogicProbe_schematic.jpg?raw=true)

Breadboard test, with logic high input:

![LogicProbe_bb_build_high](./assets/LogicProbe_bb_build_high.jpg?raw=true)

Breadboard test, with logic low input:

![LogicProbe_bb_build_low](./assets/LogicProbe_bb_build_low.jpg?raw=true)

Breadboard test, with oscillating input (10kHz square wave from FY3200S signal generator):

![LogicProbe_bb_build_osc](./assets/LogicProbe_bb_build_osc.jpg?raw=true)

### Protoboard Build

I transferred the design to a piece of protoboard to capture the circuit for future use. A quick sketch of the layout:

![protoboard_layout](./assets/protoboard_layout.jpg?raw=true)

Protoboard test, with logic high input:

![protoboard_high](./assets/protoboard_high.jpg?raw=true)

Protoboard test, with logic low input:

![protoboard_low](./assets/protoboard_low.jpg?raw=true)

Protoboard test, with oscillating input (10kHz square wave from FY3200S signal generator):

![protoboard_osc](./assets/protoboard_osc.jpg?raw=true)

## Credits and References

* [CD4001 datasheet](https://www.futurlec.com/4000Series/CD4001.shtml)
* [Logic probe circuit using CD4001 IC](https://electronicsarea.com/logic-probe-circuit-cd4001/)
