# #489 555 Rising Edge Detector

Using the 555 timer and AC-coupling to produce a fixed-width rising edge trigger pulse.

![Build](./assets/555RisingEdgeDetector_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/UjDWfYYWZe8/0.jpg)](https://www.youtube.com/watch?v=UjDWfYYWZe8)

## Notes

This demonstrates a circuit for generating a pulse on a rising edge.
It uses a 555 monostable circuit to generate a clean output pulse of fixed duration.
The output pulse is active-low logic, but this can be inverted in a following stage if required.

The input edge detection is achieved by AC-coupling the input (with capacitor C1) feeding the 555 timer's threshold input.
The threshold is normally pulled low (R3), and a diode (D1) is included to absorb much of the falling edge pulse.

## Behaviour

The scope trace below shows the pulse generated on the rising edge of the input.
The output pulse is around 250ms, close to the calculated [242ms](https://visual555.tardate.com/?mode=monostable&r1=22&c=10).

* CH1 (yellow) - input signal
* CH2 (blue) - RC filtered pulse
* CH3 (red) - output

![scope](./assets/scope.gif?raw=true)

## Construction

![Breadboard](./assets/555RisingEdgeDetector_bb.jpg?raw=true)

![Schematic](./assets/555RisingEdgeDetector_schematic.jpg?raw=true)

![Build](./assets/555RisingEdgeDetector_build.jpg?raw=true)

## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [Edge-Triggered 555 Monostable Multivibrator](https://www.electroschematics.com/11032/edge-triggered-555-monostable-multivibrator/)
