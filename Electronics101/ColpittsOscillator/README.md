# #180 ColpittsOscillator

Testing a basic Colpitts Oscillator circuit

## Notes

A Colpitts oscillator uses a combination of inductors (L) and capacitors (C) to produce an oscillation
at the resonant frequency of LC circuit.

The distinguishing feature of a Colpitts oscillator is that the feedback to gain device (here an NPN BJT)
is taken from the midpoint of the two capacitors.

With C1,C2=100nF and L1=1mH, I should expect oscillation at
[22.5kHz](http://www.wolframalpha.com/input/?i=1%2F%282%CF%80+*sqrt%281mH+*+100nF+*+100nF%2F%28100nF+%2B+100nF%29%29%29), however on my first breadboard build I'm getting around 33kHz:

![breadboard_ac_coupled](./assets/breadboard_ac_coupled.gif?raw=true)

So more experiments required..

### A Protoboard Build

![Protoboard Build](./assets/ColpittsOscillator_protoboard.jpg?raw=true)

Putting the circuit on a protoboard and using some better quality capacitors makes all the difference!

I'm seeing an almost perfect 22.9kHz compared to the theoretical [22.5kHz](http://www.wolframalpha.com/input/?i=1%2F%282%CF%80+*sqrt%281mH+*+100nF+*+100nF%2F%28100nF+%2B+100nF%29%29%29).

The frequency can be tuned (reduced) with a capacitor in parallel with the inductor, up to about 100nF when the oscillation will be lost.

Here's an AC plot showing Vout on CH1, and TP1 on CH2. Some things to note:
* there's some distortion at the lower end of the Vout cycle; I tried twaeking the transistor bias to eliminate this but to no effect
* an almost perfect sine at TP1 (midpoint of the capacitor bridge/transistor emitter)
* 4.2V swing on Vout - not bad for a 5v supply
* 2V swing on TP1

![protoboard_ac_coupled](./assets/protoboard_ac_coupled.gif?raw=true)

Here's the DC-coupled plot, with both channels shifted down -5V
* Vout is oscillating around 5V
* TP1 oscillates ~2.8V

![protoboard_dc_coupled](./assets/protoboard_dc_coupled.gif?raw=true)

## Construction

![Breadboard](./assets/ColpittsOscillator_bb.jpg?raw=true)

![The Schematic](./assets/ColpittsOscillator_schematic.jpg?raw=true)

![Breadboard Build](./assets/ColpittsOscillator_build.jpg?raw=true)

![Protoboard Build](./assets/ColpittsOscillator_protoboard.jpg?raw=true)

## Credits and References
* [Colpitts Oscillator](https://en.wikipedia.org/wiki/Colpitts_oscillator) - wikipedia
* [The Colpitts Oscillator](http://www.electronics-tutorials.ws/oscillator/colpitts.html) - ElectronicsTutorials
* [More Oscillators](http://www.talkingelectronics.com/projects/TheTransistorAmplifier/TheTransistorAmplifier-P2.html#MORE) - TE
* [..as mentioned on my blog](http://blog.tardate.com/2016/02/littlearduinoprojects180-colpitts.html)
