# #675 LDR Data Slicer Trigger

Using a data slicer to extract a clean trigger signal from a light dependent resistor (LDR).

![Build](./assets/DataSlicer_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/N8BFajxKo-w/0.jpg)](https://www.youtube.com/watch?v=N8BFajxKo-w)

## Notes

[LEAP#674 LDR Differential Comparator](../DifferentialComparator) used a differential amplifier
to extract a trigger signal from a light-dependent resistor.

There is a simpler way that just uses a single op-amp unit: a technique called a "data slicer".
It is described in [PIC® MCU Comparator Tips ‘n Tricks](http://ww1.microchip.com/downloads/en/DeviceDoc/41215c.pdf).

The circuit is based on electronut.in's notes: [Designing an Op-Amp Circuit to Detect LDR Pulses](https://electronut.in/designing-an-op-amp-circuit-to-detect-ldr-pulses/)

### Circuit Design

I'm using LDR 5528 which is specified as dark: 1MΩ, light: 8-20kΩ.

The essential idea:

* the op-amp is configured as a comparator between the input signal and a sliding reference derived from the input signal
* the "sliding reference" is just the input signal passed through an RC low-pass filter (R3 + C1)
* R4+R5 bias the reference low (a single resistor would have been fine - the pot just makes it convenient to experiment with adjustments)

![bb](./assets/DataSlicer_bb.jpg?raw=true)

![schematic](./assets/DataSlicer_schematic.jpg?raw=true)

### Test Results

![bb_build](./assets/DataSlicer_bb_build.jpg?raw=true)

For the scope trace below:

* CH1 (yellow): measuring the voltage at the base of the LDR
* CH2 (blue): sliding reference
* CH3 (red): output

A very nice solid pulse when the LDR is initially obscured.

![scope](./assets/scope.gif?raw=true)

## Credits and References

* [Designing an Op-Amp Circuit to Detect LDR Pulses](https://electronut.in/designing-an-op-amp-circuit-to-detect-ldr-pulses/)
* [LM358N Datasheet](https://www.futurlec.com/Linear/LM358N.shtml)
* [PIC® MCU Comparator Tips ‘n Tricks](http://ww1.microchip.com/downloads/en/DeviceDoc/41215c.pdf)
