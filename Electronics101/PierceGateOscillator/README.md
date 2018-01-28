# #248 PierceGateOscillator

Build and test a 4.27 MHz Pierce Gate Oscillator circuit using a 74LS14 schmitt inverter.

![Build](./assets/PierceGateOscillator_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The Pierce oscillator is named for its inventor, George W. Pierce (1872-1956). It is a derivative of the Colpitts oscillator,
and can be implemented using a minimum of components, typically: a digital inverter, one resistor, two capacitors, and a quartz crystal.

The term "Pierce Gate Oscillator" generally refers to circuits where the digital inverter is implemented as a CMOS gate (inverter or NOR). This is a very common arrangement, and is used with microcontroller chips to provide the external clock source.

I have a 4.273MHz crystal resonator, and 74LS14 schmitt inverter on hand, so my objective here is to make a Pierce Gate Oscillator with them.

### Component Selection - Theory

The [Pierce-Gate Crystal Oscillator, an introduction](http://www.crystek.com/documents/appnotes/Pierce-GateIntroduction.pdf)
application note provides thorough explaination of the theory.

* C1, C2, and Rs define the gain of the inverter loop. Gain must be >=1 at the desired frequency
    - reducing C1, C2 Rs produce higher gain
    - reducing Rs produces higher gain

At 4.273MHz, and C1=C2=33pF, Rs should be around [1/2πfC = 1.1kΩ](http://www.wolframalpha.com/input/?i=1%2F(2%CF%80+*+4.273MHz+*+33pF))

The feedback resistor Rf is there to linearize the CMOS inverter. For 4.273MHz, an Rf in the order of 1-5MΩ would be expected.

### Component Selection - Practice

So I wired that all up on a breadboard .. and no oscillation, even with moderate changes in the component values.
I'm blaming the 74LS14, as other examples I've seen documented use the better performing 74HC14.

After much experimentation, I was able to get it to perform - but only once I'd reduced the feedback resistor
all the way down to 2.2kΩ. At this level, the circuit is operating more like a classic SchmittOscillator,
which would have an expected frequency of around [5.7MHz](http://www.wolframalpha.com/input/?i=1%2F(1.2+*+2.2k%CE%A9+*+66pF)).

However, the crystal is doing its job, locking in the oscillation at the resonant frequency of bang on 4.273MHz.

Here's a scope trace:

![scope](./assets/scope.gif?raw=true)


## Construction

![Breadboard](./assets/PierceGateOscillator_bb.jpg?raw=true)

![Schematic](./assets/PierceGateOscillator_schematic.jpg?raw=true)

The circuit worked on a breadboard - where I selected component values - then I put on protoboard for a more stable signal:

![PierceGateOscillator_protoboard_layout](./assets/PierceGateOscillator_protoboard_layout.jpg?raw=true)

Under test...

![PierceGateOscillator_test](./assets/PierceGateOscillator_test.jpg?raw=true)

## Credits and References
* LEAP: [SchmittOscillator](../SchmittOscillator)
* [Pierce oscillator](https://en.wikipedia.org/wiki/Pierce_oscillator) - wikipedia
* [Building Pierce Gate Oscillator for 455kHz IF Alignment](https://www.youtube.com/watch?v=A73bUivWu60) - xraytonyb, a really informative
walkthrough of all the electrical design decisions
* [74LS14 Datasheet](http://www.futurlec.com/74LS/74LS14.shtml)
* [Simple Tester Provides Readout of Crystal Frequency](http://electronicdesign.com/test-measurement/simple-tester-provides-readout-crystal-frequency) - article from electronicdesign
* [Quartz Crystal Oscillators](http://www.electronics-tutorials.ws/oscillator/crystal.html)
* [CIRCUIT COLLECTION : OSCILLATORS](http://www.changpuak.ch/electronics/Oscillators.php)
* [Pierce-Gate Crystal Oscillator, an introduction](http://www.crystek.com/documents/appnotes/Pierce-GateIntroduction.pdf)
* [..as mentioned on my blog](https://blog.tardate.com/2017/02/leap248-pierce-gate-oscillator.html)
