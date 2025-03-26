# #378 BJT Phase Splitter

Simple unity-gain phase splitter in a little breadboard-compatible package.

![Build](./assets/PhaseSplitter_build.jpg?raw=true)

## Notes

Section 2.08 in the The Art of Electronics describes a unity-gain phase splitter which generates an output signal and its inverse (180˚ out of phase).
This is achieved with a common emitter amplifier with emitter degeneration for a gain of -1 (~ 4.7kΩ/4.7kΩ)

With an input signal of 100kHz, the input coupling capacitor should be greater than [39pF](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*+100kHz+*+1%2F(1%2F150000%CE%A9+%2B+1%2F56000%CE%A9))) - I'm using 100nF here.

## Testing

In the following tests, the scope is connected as follows

* CH1 (yellow): SIGNAL input, DC coupled - 100kHz 1v peak-peak sine wave
* CH2 (blue): SIGNAL- inverted output, DC coupled, offset varies according to Vcc
* CH3 (red): SIGNAL+ non-inverted output, DC coupled

![PhaseSplitter_test](./assets/PhaseSplitter_test.jpg?raw=true)

### Vcc=5V

With VCC=5V, the quiescent point:

* non-inverting output centered around 0.8V
* inverting output centered around 4.3V

CH2 (blue) is offset -2V

![scope_100khz_5v](./assets/scope_100khz_5v.gif?raw=true)

### Vcc=9V

With VCC=9V, the quiescent point:

* non-inverting output centered around 1.9V
* inverting output centered around 7.2V

CH2 (blue) is offset -4v

![scope_100khz_9v](./assets/scope_100khz_9v.gif?raw=true)

### Vcc=15V

With VCC=15V, the quiescent point:

* non-inverting output centered around 3.0V
* inverting output centered around 7V

CH2 (blue) is offset -4v

![scope_100khz_15v](./assets/scope_100khz_15v.gif?raw=true)

## Construction

![Schematic](./assets/PhaseSplitter_schematic.jpg?raw=true)

Testing on a breadboard:

![Breadboard](./assets/PhaseSplitter_bb.jpg?raw=true)

![PhaseSplitter_bb_build](./assets/PhaseSplitter_bb_build.jpg?raw=true)

I put on a piece of protoboard in a breadboard-compatible layout:

![PhaseSplitter_build_layout](./assets/PhaseSplitter_build_layout.jpg?raw=true)

![Build](./assets/PhaseSplitter_build.jpg?raw=true)

## Credits and References

* [The Art of Electronics, 2nd Edition](../../../books/the-art-of-electronics/) - 2.08 Unity-gain phase splitter, p77.
* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2018/02/leap378-bjt-phase-splitter.html)
