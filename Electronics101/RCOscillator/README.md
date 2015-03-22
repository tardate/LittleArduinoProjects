# RCOscillator

Demonstrates a simple RC/transistor multistable vibrator

Here's a quick video of the circuit in action:

[![LDRStereoTripDetector demo](http://img.youtube.com/vi/OeX0hf5fvPA/0.jpg)](http://www.youtube.com/watch?v=OeX0hf5fvPA)

## Notes

This oscillator is based on coupled RC circuits with associated switching transistors.

The frequency of oscillation is given by

    f= 1/(ln(2) * ( R1 * C1 + R2 * C2))

Or in this case with 22kΩ and 22μF, that means about 1.5 Hz:

    f= 1/(ln(2) * ( 22000 * 22*10^-6 + 22000 * 22*10^-6))
    f= [1.49 Hz](http://www.wolframalpha.com/input/?i=%28ln%282%29+*+%28+22000+*+22*10%5E-6+%2B+22000+*+22*10%5E-6+%29%29%5E-1)


Note that for the oscillation to work correctly, the components need to be well matched.
The first two transistors I stuck in the circuit produced a significantly uneven oscillation.
Replacing the transistors fixed the problem, and to the human eye at least the circuit now runs completly balanced.

## Construction

![The Breadboard](./assets/RCOscillator_bb.jpg?raw=true)

![The Schematic](./assets/RCOscillator_schematic.jpg?raw=true)

![The Build](./assets/RCOscillator_build.jpg?raw=true)

## Credits and References
* [RC time constant](http://en.wikipedia.org/wiki/RC_time_constant)
* The [Sparkfun transistors](https://learn.sparkfun.com/tutorials/transistors) page - great tutorial and some nice simple circuit ideas