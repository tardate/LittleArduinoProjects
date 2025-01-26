# #459 Twin-Tee OpAmp Oscillator

A twin-tee sine wave oscillator using an TL072 Op-Amp, running in the audio spectrum.

![Build](./assets/TwinTeeOscillator_build.jpg?raw=true)

## Notes

A twin-tee filter in the feedback loop of an op-amp can be used to generate a sine wave.

* one tee comprises an R-C-R low-pass filter
* the other is a C-R-C high-pass filter.

Together, these circuits form a notch filter which is tuned at the desired frequency of oscillation.

## Design Guidelines

For oscillations to be sustained, x>=2, where:

    x = C2/C1 = R1/R2

And the frequency is then given as:

    frequency = 1/(2πRC)

## Breadboard Construction

I'm using a TL072:

* one op-amp unit is used to establish a buffered AC ground at VCC/2
* the other is for the oscillator

R2 is a pot so that it can be adjusted to be ~ R1/2 and thus allow the circuit to oscillate depending on the R1 values used.

![Breadboard](./assets/TwinTeeOscillator_bb.jpg?raw=true)

![Schematic](./assets/TwinTeeOscillator_schematic.jpg?raw=true)

![TwinTeeOscillator_bb_build](./assets/TwinTeeOscillator_bb_build.jpg?raw=true)

## Breadboard Results

With a 9V supply and R1 = 4.7kΩ, I get oscillation at about 3.238kHz:

![scope_bb_9v_4k7](./assets/scope_bb_9v_4k7.gif?raw=true)

## Protoboard Construction

For some more reliable measurements with various resistor values, I put the circuit on some protoboard.
Here's the basic layout I used. It includes:

* connections for substituting R1 values
* pins for output and capacitively coupled output (via 100nF capacitor)
* pins for ground and AC ground
* some capacitors for power supply smoothing (100nF and 100µF across the power supply)

![protoboard_layout](./assets/protoboard_layout.jpg?raw=true)

With a 5V supply and R1 = 4.7kΩ, I get oscillation at about 3.084kHz.
The wave is not a perfect sine wave, with two main distortions present:

* noticable cross-over distortion in both directions
* clipping at the top of the wave if R2 not adjusted correctly

![scope_pb_5v_4k7](./assets/scope_pb_5v_4k7.gif?raw=true)

Some measurements with a selection of R1 values:

| R1    | Expected Frequency | Actual Frequency |
|-------|--------------------|------------------|
| 3.3kΩ | [4.823kHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*3.3k%CE%A9*10nF)) | 4.503kHz |
| 4.7kΩ | [3.386kHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*4.7k%CE%A9*10nF)) | 3.084kHz |
| 10kΩ  | [1.592kHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*10k%CE%A9*10nF))  | 1.445kHz |

![Build](./assets/TwinTeeOscillator_build.jpg?raw=true)

## Credits and References

* [TL072 datasheet](https://www.futurlec.com/Linear/TL072CP.shtml)
* [Twin-T oscillator](https://en.wikipedia.org/wiki/RC_oscillator#Twin-T_oscillator) - wikipedia
* [Engineer's Mini-Notebook - Op Amp IC Circuits](https://www.goodreads.com/book/show/12287008-engineer-s-mini-notebook-op-amp-circuits) - p47 Sine Wave Oscillator
