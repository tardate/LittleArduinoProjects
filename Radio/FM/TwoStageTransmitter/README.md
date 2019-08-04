# #467 Two-stage FM Transmitter

Build and test a simple two-stage FM transmitter.

![The Build](./assets/TwoStageTransmitter_build.jpg?raw=true)

## Notes

There are many similar circuits floating around the internet for a simple 2-transistor FM transmitter.
It seems they all follow the same principles but with slightly different component values and minor changes in the schematic.

I first saw saw this circuit in [this video by TechBuilder](https://youtu.be/joFourugXvs), and
later discovered it was based on an
[original circuit by Art Swan](http://www.angelfire.com/art2/artswan/fmtrans1.jpg).

### How It Works

The first transistor Q1 is an audio amplifier for the electret microphone.

The LC tank circuit (C4, L1) provides the base carrier oscillator.
C5 modulates the carrier frequency, but it is subject to bypass by the second transistor Q2.
The degree of bypsass will depend on the voltage current applied to the base of Q2.
Thus audio voltage controls the frequency of the oscillator i.e. we have FM!

### Component Selection and Results

The inductor I finally selected is a hand-wound aircoil made form 0.55mm copper wire.
Coil dimensions: 10mm long, 3.5mm diameter, 8 turns. Measured inductance: 0.11µH.
Note: larger coils with higher resistance but similar inductance don't work so well (from my testing).

I tried a few fixed capacitors C4 to see how well experimental results match theory.

With C4=40pF, expected frequency [75.9 MHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*sqrt(0.11%C2%B5H*40pF))).
In actual fact, I can tune in on 76.4 MHz, but there are also mirror images on multiple frequencies: 78.9 MHz, 84.4 MHz.

With C4=20pF, expected frequency [107 MHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*sqrt(0.11%C2%B5H+*+20pF))),
and I can actually tune in at 107.1 MHz.

In the final build, I put a 10-30pF trimmer cap in as C4.

## Construction

I actually did the build direct to copper PCB stock ugly-style.
A breadboard build should work, although component values may need to be adjusted to compensate for capacitance injected by the breadboard.

![Breadboard](./assets/TwoStageTransmitter_bb.jpg?raw=true)

![The Schematic](./assets/TwoStageTransmitter_schematic.jpg?raw=true)

## Credits and References

* [Build A Long Range FM Transmitter (Spybug)](https://youtu.be/joFourugXvs) - by TechBuilder
* [The Ultimate FM Transmitter (Long Range Spybug)](http://www.instructables.com/id/The-Ultimate-FM-Transmitter/) - instructables version
* [Simple FM Voice Transmitter #1](http://www.angelfire.com/art2/artswan/fmtrans1.jpg) - original circuit by Art Swan
* [Simple FM Voice Transmitter #2](http://www.angelfire.com/art2/artswan/fmtrans2.jpg) - similar circuit by Art Swan
* [Build your own FM transmitter with no special parts needed](https://youtu.be/1tKvykFS60k) - similar circuit by dazaro3
* [Resonant Frequency Calculator](http://www.1728.org/resfreq.htm)
* [Transistor Electronics](https://archive.org/details/transistorelectr00gerr) page 290 - FM transmitter design
