# R2RDAC

Test a 16-bit R2R digital to analog converter with shift register interface

Here's a quick video of the circuit in action:

[![R2RDAC demo](http://img.youtube.com/vi/7upWKor84-4/0.jpg)](http://www.youtube.com/watch?v=7upWKor84-4)

## Notes

[Resistor ladders](https://en.wikipedia.org/wiki/Resistor_ladder) are a simple and effective technique
for digital to analog conversion. I was inspired to experiment with them by
[w2aew's video on the basics of R2R Resistor Networks](https://www.youtube.com/watch?v=AulX1OM7RwE) - by far
the clearest explanation of the analysis of resistor ladders I've seen.

This circuit sets up a 16 bit resistor ladder with 1kΩ as the resistor unit. It demonstrates a few interesting techniques:
* the R2R resistor ladder
* cascaded shift registers
* wave table generation
* data in program memory

Two 74HC595 shift registers are used to drive the ladder. This means the whole thing can be connected
to an Arduino using just 3 digital GPIO pins. The latching behaviour of the shift register results in
an instantaneous output voltage change, with all inputs to the ladder changing at the same time.

The [R2RDAC.ino](./R2RDAC.ino) sketch drives the DAC with a set of sample waveforms: square, sawtooth, sine, and "hump" (rectified sine). It uses standard `digitalWrite` and `shiftOut` functions and these are fine at the
relatively low frequencies I'm testing (because I want to be able to see the waves).
To run at higher frequencies, I'd definitely switch to [direct port register manipulation](https://www.arduino.cc/en/Reference/PortManipulation).

Here's a sample trace showing two cycles of each waveform:

![processing trace](./assets/processing_trace.png?raw=true)

The trace was captured with a second Arduino running the [PlotNValues](..//PlotNValues) sketch.
A second arduino was used so that the data capture did not interfere with waveform generation
by the first Arduino.

Note: when capturing analogue input across Arduinos, slight differences in reference voltage
can skew the results. This can be eliminated by pegging the
[AREF](https://www.arduino.cc/en/Reference/AnalogReference) of one to the AREF of the other.
You don't see me doing this in the schematics because the difference was negligible, although
I did add another 10kΩ resistor between output and ground to reduce the output amplitude so
it wasn't clipped in my plots.

### Wave Table Generation

The demo drives the DAC with a set of sample waveforms: square, sawtooth, sine, and "hump" (rectified sine).

Rather than calculate these on the fly, it uses values from pre-calculated wave tables.
This ensures constant-time performance and reduce the processing overhead.
To minimise dynamic memory consumption, the tables are loaded in program memory (code space).

The [wavetable_generator.rb](./wavetable_generator.rb) ruby script is used to generate the wave tables.


## Construction

![Breadboard](./assets/R2RDAC_bb.jpg?raw=true)

![The Schematic](./assets/R2RDAC_schematic.jpg?raw=true)

![The Build](./assets/R2RDAC_build.jpg?raw=true)

## Credits and References
* [Resistor ladder](https://en.wikipedia.org/wiki/Resistor_ladder) - wikipedia
* [#85: Basics of R2R Resistor Networks Digital Analog Conversion, Tutorial DAC Thevenin Superposition](https://www.youtube.com/watch?v=AulX1OM7RwE) - another great video by w2aew
* [74HC595 datasheet](http://www.futurlec.com/74HC/74HC595.shtml)
* [List of periodic functions](https://en.wikipedia.org/wiki/List_of_periodic_functions) - wikipedia summary of various wave forms

