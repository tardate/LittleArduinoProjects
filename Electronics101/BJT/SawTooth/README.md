# #105 BJT SawTooth

Testing a simple BJT saw-tooth oscillator.

![The Build](./assets/SawTooth_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This circuit examines a simple method for generating a simple sawtooth oscillation using only NPN and PNP transistors.
I'm cribbing from [the tutorial posted by w2aew](https://youtu.be/2a1I1X3RV0g).

Here's the principle of operation:
* R1/R2 bias Q1 as a constant current source
* Q1 charges C1 at constant rate (Ic/C)
* Q2 base is set with the R3/R4 voltage divider
* Q2 is initially in cut-off as Ve (0v) < Vb (4.5v) > Vc (~0.7v)
* As C1 charge exceeds Q2 base, Q2 becomes forward biased, which in turn forward biases Q3
* C1 discharges through Q2 + Q3
* discharge continues until Q2 collector falls low-enough to force cut-off, and the cycle repeats

The standard guidelines for NPN/PNP operation (from
[BJT page on wikipedia](https://en.wikipedia.org/wiki/Bipolar_junction_transistor)
) help understand the behaviour:

| Voltage Relation | NPN            | PNP            |
|------------------|----------------|----------------|
| E < B < C        | forward-active | reverse-active |
| E < B > C        | saturation     | cut-off        |
| E > B < C        | cut-off        | saturation     |
| E > B > C        | reverse-active | forward-active |


### Not Oscillating?

The trick seems to be to ensure that the Q2/Q3 pair effectively cut-off.
The original circuit set R3 at 10kΩ. Depending on transistor characteristics, this may not pull the voltage high enough to ensure oscillation occurs.
If not, the typical behaviour is to see one oscillation, and then C1 peg at about 1 diode-drop.

Reducing the value of R3 seems to overcome the problem (here I'm using 4.7kΩ with 2N3904/2N3906 transistors).
As a side-effect, this also increases the amplitude of the wave.

### Changing Frequency

The capacitance of C1 affects the slope of the charge. Since we are using a constant current, charge time in V/sec = Ic/C.
So higher capacitor values will slow down the wave frequency and vice versa.
Here I'm using a 10µF electrolytic to give a very slow wave, visible to the eye.

Here's a sample trace recorded using [PlotNValues (a simple Processing sketch)](../../../processing/PlotNValues) to
read the data collected by the [SawTooth.ino](./SawTooth.ino) program:

![processing trace](./assets/processing_trace.png?raw=true)

### Code
The [SawTooth.ino](./SawTooth.ino) sketch is a simple data capture and reporting interface.
It uses the [FlexiTimer2](https://github.com/wimleers/flexitimer2) library to provide data capture on an accurate and stable time base.

## Construction

![Breadboard](./assets/SawTooth_bb.jpg?raw=true)

![The Schematic](./assets/SawTooth_schematic.jpg?raw=true)

## Credits and References
* [Simple 3 transistor sawtooth generator / oscillator](https://youtu.be/2a1I1X3RV0g) - excellent tutorial from w2aew; the basis for this project.
* [BJT page on wikipedia](https://en.wikipedia.org/wiki/Bipolar_junction_transistor)
* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml)
* [2N3906 datasheet](https://www.futurlec.com/Transistors/2N3906.shtml)
