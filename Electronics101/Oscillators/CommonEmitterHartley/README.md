# #418 Common Emitter Hartley Oscillator

Build and test a BJT common-emitter Hartley oscillator.

![Build](./assets/CommonEmitterHartley_build.jpg?raw=true)

## Notes

The Hartley oscillator was invented in 1915 by American engineer Ralph Hartley.
It is distinguished by a tapped inductor to provide feedback (the Colpitts oscillator uses capacitors).

There are many variations in design possible.
In this case I'm using one of the most straight-forward designs based on a
project described on [http://www.learnabout-electronics.org](http://www.learnabout-electronics.org/Oscillators/osc22.php).


Main benefits of a Hartley oscillator:

* wide tuning range more easily realised than with Colpitts
* generally good quality sine waves in the RF range (30kHz to 30MHz)

Main issues with Hartley oscillators:

* at the higher limits of this range and above, The Colpitts oscillator is usually preferred


## Theoretical Frequency

Given by:

    f = 1/ 2π sqrt(LC)

Where L = L1 + L2. If significant mutual inductance is present (e.g. when inductors share a common core) this may need to be added for accuracy.

In the tests that follow, experimental results are quite wide of the mark (except around 1.4MHz).
This may largely be due to component tolerances(?)


## Schematic

The tank circuit comprises:

* L1 = 2µH (actually I user 2 x 1µH in series)
* L2 = 10µH
* C1 = 1nF, but also tested with 100pF and 10nF alternatives

I used 1/4W RF chokes for the inductors and ceramic capacitors

![Schematic](./assets/CommonEmitterHartley_schematic.jpg?raw=true)


## Breadbaord Construction

First testing with a breadboard build..

![Breadboard](./assets/CommonEmitterHartley_bb.jpg?raw=true)

![Build](./assets/CommonEmitterHartley_bb_build.jpg?raw=true)

Various C1 values do oscillate, however peak-peak voltage is quite low in the breadboard build..

| C1    | Freq    | Vp-p  | Frequency (theoretical)                                                                |
|-------|---------|-------|----------------------------------------------------------------------------------------|
| 10nF  | 656kHz  | 0.8V  | [459kHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*sqrt(12%C2%B5H+*+10nF)))   |
| 1nF   | 1.45MHz | 2.94V | [1.45MHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*sqrt(12%C2%B5H+*+1nF)))   |
| 100pF | 3.10MHz | 4.6V  | [4.59MHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*sqrt(12%C2%B5H+*+100pF))) |

Scope trace for C1=100pF:

![scope_bb_100pF](./assets/scope_bb_100pF.gif?raw=true)

FFT for C1=100pF. In all cases, significant harmonic content is apparent in the output:

![scope_bb_100pF](./assets/scope_bb_100pF_fft.gif?raw=true)


## Protoboard Construction

Now putting the circuit on a piece of protoboard, with C1 values selected with a jumper:

![CommonEmitterHartley_pb_layout](./assets/CommonEmitterHartley_pb_layout.jpg?raw=true)

![CommonEmitterHartley_pb_build](./assets/CommonEmitterHartley_pb_build.jpg?raw=true)

![CommonEmitterHartley_pb_build_rear](./assets/CommonEmitterHartley_pb_build_rear.jpg?raw=true)

Very strong oscillation achieved, with significantly higher peak-peak voltage output than in the breadboard build,
however this does cost more distortion in the signal (I suspect the transistor bias needs adjusting).

| C1    | Freq    | Vp-p  | Frequency (theoretical)                                                                |
|-------|---------|-------|----------------------------------------------------------------------------------------|
| 10nF  | 608kHz  | 12V   | [459kHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*sqrt(12%C2%B5H+*+10nF)))   |
| 1nF   | 1.42MHz | 6.5V  | [1.45MHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*sqrt(12%C2%B5H+*+1nF)))   |
| 100pF | 3.29MHz | 22.5V | [4.59MHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*sqrt(12%C2%B5H+*+100pF))) |

Scope trace for C1=10nF:

![scope_pb_10nF](./assets/scope_pb_10nF.gif?raw=true)

Scope trace for C1=1nF:

![scope_pb_1nF](./assets/scope_pb_1nF.gif?raw=true)

Scope trace for C1=100pF:

![scope_pb_100pF](./assets/scope_pb_100pF.gif?raw=true)


## Improving the Waveform


Reducing R3 to [17Ω](https://toolbox.tardate.com/?formula=22%7C68#ResistorCalculator) (put putting a 68Ω resistor in parallel)
eliminates the worst (clipping) distortion especially at higher frequencies. Some revised results with this configuration:

| C1    | Freq    | Vp-p  | Frequency (theoretical)                                                                |
|-------|---------|-------|----------------------------------------------------------------------------------------|
| 10nF  | 645kHz  | 16V   | [459kHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*sqrt(12%C2%B5H+*+10nF)))   |
| 1nF   | 1.42MHz | 8V    | [1.45MHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*sqrt(12%C2%B5H+*+1nF)))   |
| 100pF | 3.12MHz | 12.5V | [4.59MHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*sqrt(12%C2%B5H+*+100pF))) |

Scope trace for C1=10nF, R3=17Ω:

![scope_pb_v2_10nF](./assets/scope_pb_v2_10nF.gif?raw=true)

Scope trace for C1=1nF, R3=17Ω:

![scope_pb_v2_1nF](./assets/scope_pb_v2_1nF.gif?raw=true)

Scope trace for C1=100pF, R3=17Ω:

![scope_pb_v2_100pF](./assets/scope_pb_v2_100pF.gif?raw=true)


## Credits and References
* [The Hartley Oscillator](http://www.learnabout-electronics.org/Oscillators/osc21.php) - www.learnabout-electronics.org
* [Hartley Oscillator](https://en.wikipedia.org/wiki/Hartley_oscillator) - wikipedia
* [Experimental Methods in RF Design](https://www.goodreads.com/book/show/2386153.Experimental_Methods_in_RF_Design) - section 4.2
* [Hartley Oscillator - Working, Design using Op-Amp](https://www.electronicshub.org/hartley-oscillator/)
* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2018/10/leap418-hartley-oscillator.html)
