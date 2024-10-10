# #618 LDR Differential Comparator

Using a differential amplifier to extract a clean trigger signal from a light dependent resistor (LDR).

![Build](./assets/DifferentialComparator_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/3DnNSI1Qrdo/0.jpg)](https://www.youtube.com/watch?v=3DnNSI1Qrdo)

## Notes

[LEAP#034 LDR Comparator](../Comparator) used a [Wheatstone Bridge](http://en.wikipedia.org/wiki/Wheatstone_bridge)
to measure changes in ambient light and provide a signal that could be used as a low/high light trigger.
While the Wheatstone Bridge allows the output signal offset to be independently set, it is a sensitive signal and prone to "bounce" if used as a trigger.

The circuit I'm testing here filters out much of the noise by measuring the first order derivative of the LDR.
It comprises:

* first op-amp stage configured as a differential amplifier
* seconds op-amp stage configured as a comparator, to exclude changes below a preset threshold

The circuit is based on electronut.in's notes: [Designing an Op-Amp Circuit to Detect LDR Pulses](https://electronut.in/designing-an-op-amp-circuit-to-detect-ldr-pulses/)

### Circuit Design

I'm using LDR 5528 which is specified as dark: 1MΩ, light: 8-20kΩ.

![bb](./assets/DifferentialComparator_bb.jpg?raw=true)

![schematic](./assets/DifferentialComparator_schematic.jpg?raw=true)

### Test Results

![bb_build](./assets/DifferentialComparator_bb_build.jpg?raw=true)

For the scope trace below:

* CH1 (yellow): measuring the voltage at the base of the LDR
* CH2 (blue): differential amplifier output
* CH3 (red): comparator output

A nice solid pulse when the LDR is initially obscured.

![scope](./assets/scope.gif?raw=true)

## Credits and References

* [Designing an Op-Amp Circuit to Detect LDR Pulses](https://electronut.in/designing-an-op-amp-circuit-to-detect-ldr-pulses/)
* [The Differentiator Amplifier](https://www.electronics-tutorials.ws/opamp/opamp_7.html)
* [LM358N Datasheet](https://www.futurlec.com/Linear/LM358N.shtml)
