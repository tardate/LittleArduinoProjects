# #049 BJT RC Oscillator

Demonstrates a simple RC/transistor astable multivibrator

![The Build](./assets/BjtRcOscillator_build.jpg?raw=true)

Here's a quick video of the circuit in action:

[![BjtRcOscillator](https://img.youtube.com/vi/OeX0hf5fvPA/0.jpg)](https://www.youtube.com/watch?v=OeX0hf5fvPA)

## Notes

This oscillator is based on coupled RC circuits with associated switching transistors.

The frequency of oscillation is given by

    f = 1/(ln(2) * ( R1 * C1 + R2 * C2))

Or in this case with 22kΩ and 22μF, that means about
[1.5 Hz](https://www.wolframalpha.com/input/?i=%28ln%282%29+*+%28+22000+*+22*10%5E-6+%2B+22000+*+22*10%5E-6+%29%29%5E-1).

Note that for the oscillation to work correctly, the components need to be well matched.
The first two transistors I stuck in the circuit produced a significantly uneven oscillation.
Replacing the transistors with some newish S9013 NPN transistors fixed the problem,
and to the human eye at least the circuit now runs completely balanced.

NB: I'm using S9013 but any small-signal NPN transistors will do.

## Construction

![The Breadboard](./assets/BjtRcOscillator_bb.jpg?raw=true)

![The Schematic](./assets/BjtRcOscillator_schematic.jpg?raw=true)

## Credits and References

* [S9013 Datasheet](https://www.futurlec.com/Transistors/S9013.shtml)
* [RC time constant](http://en.wikipedia.org/wiki/RC_time_constant)
* The [Sparkfun transistors](https://learn.sparkfun.com/tutorials/transistors) page - great tutorial and some nice simple circuit ideas
* [Basic Astable Multivibrator Circuit](https://www.electronics-tutorials.ws/waveforms/astable.html) - good write-up of the circuit
* [Astable Multivibrator circuit](https://www.pcbheaven.com/userpages/basic_transistor_circuits/) - another example.
