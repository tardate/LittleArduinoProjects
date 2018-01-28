# #332 Oscillators/RCPhaseShiftBJT

Testing an RC phase-shift oscillator using a BJT amplifier.

![Build](./assets/RCPhaseShiftBJT_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

Given an inverting amplifier (180˚ phase shift),
with output fed back into a network that adds another 180˚ phase shift,
and provided the amplifier gain is sufficient to provide overall positive feedback gain of 1 ... then we have the basis of an oscillotor.

The RC phase-shift oscillator with BJT amplifier is one of the simplest realisations of this, requiring no special components:

* an NPN BJT in a common-emitter configuration is the inverting amplifier
* a cascade of RC high-pass filters provide the additional 180˚ phase shift
* the amplifier provides enough gain to overcome losses in the RC network

The basic BJT/RC phase shift oscillator is good for low(er) frequency sine wave generation. Main drawbacks:

* performance is very component-specific. Actual frequency may be far of theoretical.
* variable frequency control is non-trivial enhancement

### RC High-pass Filter Phase Shift

[![High_pass_filter](https://upload.wikimedia.org/wikipedia/commons/f/fe/High_pass_filter.svg)](https://en.wikipedia.org/wiki/File:High_pass_filter.svg)

* Capacitive Reactance: `Xc = 1/2πfC`
* Impedance: `Z = √(R² + Xc²)`
* phase angle: `ø = arctan(Xc/R)`

A single filter output leads by at most approaching 90˚, therefore three filters in series are required to achieve ≥ 180˚.
More stages could be used, but this adds more error and variation.

The frequency of the filter network is predicted based on the -3dB cut-off: `f = 1/(2πRC√(2N))`, where N is the number of filter stages.

The total phase shift is then: `ø = N.arctan(1/(2πfRC))`

So in the basic R=10kΩ, C=10nF configuration I'm using here, we'd expect
frequency of [650Hz](http://www.wolframalpha.com/input/?i=1%2F(2%CF%80+*+10k%CE%A9+*+10nF+*+sqrt(6)))
with a phase shift for each stage of [67˚](http://www.wolframalpha.com/input/?i=arctan(1%2F(2%CF%80+*+10nF+*+10k%CE%A9+*+650Hz)+)),
for a total phase shift of 201˚ - safely over the 180˚ minimum required.


### Biasing the BJT

The circuit I'm using is probably the canonical demonstration. The BJT is in a Class A common-emitter amplifier configuration with:

* voltage divider bias
* emitter resistor Re. Higher Re stabilises emitter current, making it more independent of the transisitor ß/hFE.
* a bypass capacitor in parallel with Re improves AC gain. Set Xc≤0.10RE for lowest frequency.


### Results on a Breadboard

![RCPhaseShiftBJT_bb_build](./assets/RCPhaseShiftBJT_bb_build.jpg?raw=true)

Notes and modifications I've made after the initial schematic design:

* add C5 (10nF) to smooth the power supply; this helped stabilise the oscillator significantly
* had to play around with the value of Re to ensure the transistor stayed in the linear region. Settled on 360Ω.
* for this biasing arrangement, requires a minimum of 8.5V supply for the oscillator to get started


#### R=10kΩ, C=10nF

Produced a 746 Hz oscillation in practice, 14% above predicted. Not very surprised - especially on a breadboard.
The phase shift per pole of the filter should be around [64˚](http://www.wolframalpha.com/input/?i=arctan(1%2F(2%CF%80+*+10nF+*+10k%CE%A9+*+743Hz)+))

With a 9V supply, it produces a very nice sine wave at 3.66V peak-to-peak.

![scope_bb_10nF_td](./assets/scope_bb_10nF_td.gif?raw=true)

![scope_bb_10nF_fft](./assets/scope_bb_10nF_fft.gif?raw=true)

#### R=10kΩ, C=100nF

I randomly switch the capacitors to 100nF and it slows things down to a very nice sine wave at 103Hz.

But this is curious: the phase shift per pole would presumably be [57˚](http://www.wolframalpha.com/input/?i=arctan(1%2F(2%CF%80+*+100nF+*+10k%CE%A9+*+103Hz)+)),
and one would think the oscillation couldn't be maintained.

Since I know these ceramic 100nF caps tend to err significantly low (sometimes down to ~90nF), I suspect this is only working for me accidentally doe to parts tolerance.

![scope_bb_100nF_td](./assets/scope_bb_100nF_td.gif?raw=true)


### Results on a Copper PCB

![RCPhaseShiftBJT_pcb](./assets/RCPhaseShiftBJT_pcb.jpg?raw=true)

Results with an ugly-style construction on a copper PCB are much closer to theory:

* measured frequency is 690Hz - just 6% above theoretical frequency
* at 9V VCC, output sine wave is a strong 4.2V peak-to-peak

![scope_10nF_td](./assets/scope_10nF_td.gif?raw=true)

![scope_10nF_fft](./assets/scope_10nF_fft.gif?raw=true)

## Construction

![Breadboard](./assets/RCPhaseShiftBJT_bb.jpg?raw=true)

![Schematic](./assets/RCPhaseShiftBJT_schematic.jpg?raw=true)

![Build](./assets/RCPhaseShiftBJT_build.jpg?raw=true)

## Credits and References
* [RC Oscillator](https://en.wikipedia.org/wiki/RC_oscillator) - wikipedia
* [High-pass Filter](https://en.wikipedia.org/wiki/High-pass_filter) - wikipedia
* [Phase Shift Oscillators](http://www.learnabout-electronics.org/Oscillators/osc31.php)
* [The RC Oscillator Circuit](http://www.electronics-tutorials.ws/oscillator/rc_oscillator.html) - electronics-tutorials
* [RC High-pass Filter](http://www.electronics-tutorials.ws/filter/filter_3.html)
* [RC Phase Shift Oscillator Circuit Working and Applications](https://www.elprocus.com/rc-phase-shift-oscillator-circuit-working-and-applications/) - elprocus
* [RC Oscillator-using Op-Amp,BJT](http://www.electronicshub.org/rc-oscillator/) - electronicshub
* [Class A Amplifier](http://www.electronics-tutorials.ws/amplifier/amp_5.html)
* [2N3904 datasheet](http://www.futurlec.com/Transistors/2N3904.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2017/08/leap332-rc-phase-shift-oscillator.html)
