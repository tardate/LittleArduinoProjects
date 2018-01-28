# #230 MinimalLCOscillator

Test an LC oscillator of just 5 components


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I borrowed this idea and circuit design from stoneslice's
[1MHz Oscillator](https://www.youtube.com/watch?v=1IJ284kV6zY) video.

I'm not sure how the circuit fits into the taxonomy of oscillator circuits, but it is similar to a
Colpitts oscillator circuit - but one capacitor is replaced with a resistor.

I tried a range of component values on a breadboard.
To sustain the oscillation, I found I had to increase the value of the resistor - 4.7kΩ proved good for all cases.

| L     | C    | frequency |
|-------|------|-----------|
| 470µH | 47pF | 1.6MHz    |
| 150µH | 47pF | 2.9MHz    |
| 470µH | 68pF | 1.5MHz    |
| 150µH | 68pF | 2.7MHz    |


The effect of the resistor seems to alter the resonant frequency of the "impure" tank circuit.
For example, I'd expect with 150µH/47pF the frequency to be
[1.89MHz](http://www.wolframalpha.com/input/?i=1%2F(2%CF%80*sqrt(150%C2%B5H*47pF)))
when in fact I measure 2.819MHz.

Nevertheless, an interesting self-oscillating circuit.

Soldered on a PCB with 150µH/47pF and a J201 n-FET, there are no issues sustaining an oscillation, however the frequency
is not particularly stable and there's a distinct second harmonic.

![scope](./assets/scope.gif?raw=true)

![fft](./assets/fft.gif?raw=true)

## Construction

![Breadboard](./assets/MinimalLCOscillator_bb.jpg?raw=true)

![The Schematic](./assets/MinimalLCOscillator_schematic.jpg?raw=true)

![The Build](./assets/MinimalLCOscillator_build.jpg?raw=true)

## Credits and References
* [1MHz Oscillator](https://www.youtube.com/watch?v=1IJ284kV6zY) - stoneslice
* [Colpitts oscillator](https://en.wikipedia.org/wiki/Colpitts_oscillator) - wikipedia
* [J201 datasheet](http://www.futurlec.com/Transistors/J201.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/leap230-minimal-lc-oscillator.html)
