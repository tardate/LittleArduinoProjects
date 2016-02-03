# #180 ColpittsOscillator

Testing a basic Colpitts Oscillator circuit

## Notes

A Colpitts oscillator uses a combination of inductors (L) and capacitors (C) to produce an oscillation
at the resonant frequency of LC circuit.

The distinguishing feature of a Colpitts oscillator is that the feedback to gain device (here an NPN BJT)
is taken from the midpoint of the two capacitors.

With C1,C2=100nF and L1=1mH, I should expect oscillation at around
[22.5kHz](http://www.wolframalpha.com/input/?i=1%2F%282%CF%80+*sqrt%281mH+*+100nF+*+100nF%2F%28100nF+%2B+100nF%29%29%29), however on my first breadboard build I'm getting around 33kHz:

![scope_1](./assets/scope_1.gif?raw=true)

So more experiements required .. I think next I'll put this on a protoboard and use some better quality capacitors.

## Construction

![Breadboard](./assets/ColpittsOscillator_bb.jpg?raw=true)

![The Schematic](./assets/ColpittsOscillator_schematic.jpg?raw=true)

![The Build](./assets/ColpittsOscillator_build.jpg?raw=true)

## Credits and References
* [Colpitts Oscillator](https://en.wikipedia.org/wiki/Colpitts_oscillator) - wikipedia
* [The Colpitts Oscillator](http://www.electronics-tutorials.ws/oscillator/colpitts.html) - ElectronicsTutorials

