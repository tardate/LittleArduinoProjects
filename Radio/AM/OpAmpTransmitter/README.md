# #143 OpAmp AM Transmitter

Simple AM transmitter with OpAmp carrier/mixer.

Here's a quick demo of the transmitter in action:

[![clip](https://img.youtube.com/vi/X9KKxh5PliQ/0.jpg)](https://www.youtube.com/watch?v=X9KKxh5PliQ)

FYI, I'm "broadcasting"
[Go Marko Go by the Boban Marković Orkestar](http://www.amazon.com/gp/product/B008AZYPYY/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B008AZYPYY&linkCode=as2&tag=itsaprli-20&linkId=65VCNMDL6DCRUFVI).

## Notes

This project is inspired by Afrotechmods'
[Amplitude Modulation tutorial and AM radio transmitter circuit](https://youtu.be/3I_e7gIyfQg).

The circuit has two main stages:
* one op-amp is configured as a free-running square wave generator of the carrier wave
* a second op-amp configured as a non-inverting amplifier is the mixer

I've made two principal changes to the circuit presented by Afrotechmods:

1. I'm using an LF347N op-amp. For some reason (dodgy parts?), I'm not able to drive the TL072 chips I have available at high enough frequency.
See my [HighFrequencyOpAmpOscillators](../../../Electronics101/HighFrequencyOpAmpOscillators) project where I compare a few different op-amps and try to max out the oscillator with each. The LF347N does a grand job. In the demo, I'm tuned to around 1100kHz.

2. Following suggestions [on this EE.SE question](http://electronics.stackexchange.com/questions/74351/am-modulator-mixer-circuit),
I've modified the mixer to tap the audio input via a n-channel JFET and us this signal to modulate the carrier in a non-inverting amplifier configuration.
Note that I didn't take any particular care in designing or selecting component values, so while it works, it's likely far from optimal.

The end result is pretty decent! You can hear the result in [this video](https://www.youtube.com/watch?v=X9KKxh5PliQ).

This circuit is not designed for range: 10-15cm at most, with 20cm breadboard jumper as my aerial.
Where I live, all AM stations are long gone, and the spectrum given over to other purposes.
So my receiver doesn't need to move far away before other signals in the air overwhelm it with noise.

So is this really AM? Well, not quite I fear:

* the square wave carrier is a cheat, and I expect results in quite wideband transmission
* I think the mixer only produces a single-side band modulation

The Elsevier/Analog Devices
["Op Amp Applications Handbook"](http://www.analog.com/library/analogDialogue/archives/39-05/op_amp_applications_handbook.html)
has an interesting circuit in section 6-5 that uses an AD8037 Clamping Amplifier to modulate both the high and low side of the carrier.
Interesting.. play for another day!

## Construction

![Breadboard](./assets/OpAmpTransmitter_bb.jpg?raw=true)

![The Schematic](./assets/OpAmpTransmitter_schematic.jpg?raw=true)

![The Build](./assets/OpAmpTransmitter_build.jpg?raw=true)

## Credits and References

* [Amplitude Modulation tutorial and AM radio transmitter circuit](https://youtu.be/3I_e7gIyfQg) - another great Afrotechmods video
* [AM Modulator Mixer Circuit](http://electronics.stackexchange.com/questions/74351/am-modulator-mixer-circuit) - related question on EE.SE
* [LF347N datasheet](https://www.futurlec.com/Linear/LF347N.shtml)
* [J201 datasheet](https://www.futurlec.com/Transistors/J201.shtml)
* [AMFMRadioKit](../../AMFMRadioKit) - the AM radio kit I used to test reception
* [Op Amp Applications Handbook](http://www.analog.com/library/analogDialogue/archives/39-05/op_amp_applications_handbook.html) - Elsevier/Analog Devices
* [Go Marko Go by the Boban Marković Orkestar](http://www.amazon.com/gp/product/B008AZYPYY/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B008AZYPYY&linkCode=as2&tag=itsaprli-20&linkId=65VCNMDL6DCRUFVI)
