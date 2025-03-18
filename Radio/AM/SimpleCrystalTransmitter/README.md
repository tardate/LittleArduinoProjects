# #470 Simple Crystal AM Transmitter

Building a classic crystal-locked AM transmitter with a 1MHz MCO-1510A CMOS crystal oscillator.

![Build](./assets/SimpleCrystalTransmitter_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/0uDsgkrx91g/0.jpg)](https://www.youtube.com/watch?v=0uDsgkrx91g)

## Notes

This is perhaps **the** classic AM transmitter - a self-oscillating crystal with
amplitude modulated by transformer coupling between signal (audio) source and voltage driving the oscillator.

Since it is "rock-locked", this transmitter has no frequency agility!
It only operates on the frequency of the crystal (1MHz in this case).

One of the best demonstrations is covered in
"How to Make AM Radio Transmitter" by RimstarOrg:

[![clip](https://img.youtube.com/vi/_4-Sx-T6VBc/0.jpg)](https://www.youtube.com/watch?v=_4-Sx-T6VBc)

## Circuit Design

The final circuit includes an output filter network (C1, C2, C3 and L1) as shown in the schematic.

The transformer winding ratio is not particularly important, though it does directly affect
the depth of modulation. Most designs specify a 1000Ω:8Ω audio transformer,
but in the final build I used a 600Ω:600Ω audio transformer without problem.

![Breadboard](./assets/SimpleCrystalTransmitter_bb.jpg?raw=true)

![Schematic](./assets/SimpleCrystalTransmitter_schematic.jpg?raw=true)

## Initial Breadboard Build

The most basic build just required the CMOS oscillator and transformer.
For a first test, I just grabbed a 220V : 24V power transformer.
Note: 220V winding on the power control side, 24V winding on the audio input side
(the reverse will "work" but the modulation depth will be very, very small).

![SimpleCrystalTransmitter_bb_build](./assets/SimpleCrystalTransmitter_bb_build.jpg?raw=true)

With audio input, the following scope trace gives an indication of the depth
of modulation, but also makes it very clear that we're still broadcasting
a horrible square wave carrier.

While it is easy to pickup with an AM receiver, the sound quality is understandably quite poor.

![scope_unfiltered_modulated_audio](./assets/scope_unfiltered_modulated_audio.gif?raw=true)

## Adding Output Filtering

After AC coupling the output with C1, I added a T-filter comprising C2, L1 and C3.

With no modulating input connected, this has turned the square wave output from the oscillator
into a nice clean sine wave - the 1MHz carrier:

![scope_carrier](./assets/scope_carrier.gif?raw=true)

Connecting a 1kHz sine wave (amplitude 500mV) to the audio input,
the modulation can be seen quite clearly in this peak trace:

![scope_1khz_am](./assets/scope_1khz_am.gif?raw=true)

![SimpleCrystalTransmitter_bb_build2](./assets/SimpleCrystalTransmitter_bb_build2.jpg?raw=true)

## Putting it on Protoboard

To snapshot the circuit for my project archive, I transferred the circuit to protoboard
with the following layout:

![protoboard_layout](./assets/protoboard_layout.jpg?raw=true)

Testing it with a commercial receiver. At this range the little wire antenna is not necessary.
Range is quite short - measured in feet, not miles!

![SimpleCrystalTransmitter_test](./assets/SimpleCrystalTransmitter_test.jpg?raw=true)

## Credits and References

* [Building a very simple AM voice transmitter](http://sci-toys.com/scitoys/scitoys/radio/am_transmitter.html)
* [MCO-1510A datasheet](http://mklec.com/pdf/MCO-1510A.pdf)
