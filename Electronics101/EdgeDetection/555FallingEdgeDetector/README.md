# #489 555 Falling Edge Detector

Using the 555 timer, BJT inverter and AC-coupling to produce a fixed-width falling edge trigger pulse.

![Build](./assets/555FallingEdgeDetector_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/Y9l5AtJflks/0.jpg)](https://www.youtube.com/watch?v=Y9l5AtJflks)

## Notes

This demonstrates a circuit for generating a pulse on a falling edge.
It uses a 555 monostable circuit to generate a clean output pulse of fixed duration.
The output pulse is active-low logic, but this can be inverted in a following stage if required.

The input edge detection is achieved with a PNP inverter being AC-coupled (via capacitor C1) to the 555 timer's threshold input.
The threshold is normally pulled low (R3), and a diode (D1) is included to absorb much of the falling edge pulse.

## Behaviour

The scope trace below shows the pulse generated on the rising edge of the input.
The output pulse is around 250ms, close to the calculated [242ms](https://visual555.tardate.com/?mode=monostable&r1=22&c=10).

* CH1 (yellow) - input signal
* CH2 (blue) - RC filtered pulse
* CH3 (red) - output

![scope](./assets/scope.gif?raw=true)

## Construction

![Breadboard](./assets/555FallingEdgeDetector_bb.jpg?raw=true)

![Schematic](./assets/555FallingEdgeDetector_schematic.jpg?raw=true)

![Build](./assets/555FallingEdgeDetector_build.jpg?raw=true)

## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [Edge-Triggered 555 Monostable Multivibrator](https://www.electroschematics.com/11032/edge-triggered-555-monostable-multivibrator/)
