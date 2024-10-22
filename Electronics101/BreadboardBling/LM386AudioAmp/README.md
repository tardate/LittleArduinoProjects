# #469 LM386 Audio Amp

A basic LM386 audio amplifier with volume and gain control on a breadboard-compatbile mounting.

![Build](./assets/LM386AudioAmp_build.jpg?raw=true)

## Notes

Often I'll want to monitor an audio signal as part of a breadboard circuit.
One could plug into an external amplifier, or build an amplifier circuit on the breadboard.

Since I do this quite often, I decided to put a standard LM386 audio circuit on to some perfboard,
with pins arranged so that it can be plugged directly into a breadboard.


## Circuit Design

The circuit is based on examples that are documented in the "Typcial Applications" section of the datasheet.

Specifically, I have chosen to include:

* a volume control pot
* variable gain (20x to 200x) configuration of capacitor and variable resistor
* 3.5mm socket for speaker or line out

I decided not include capacitive coupling on the audio input - assuming this and any impedance matching
would be taken care of by the audio source.

![Schematic](./assets/LM386AudioAmp_schematic.jpg?raw=true)

First tested the circuit directly on a breadboard, with a 1kHz sine wave from a function generator:

![Breadboard](./assets/LM386AudioAmp_bb.jpg?raw=true)

![LM386AudioAmp_bb_build](./assets/LM386AudioAmp_bb_build.jpg?raw=true)

## Protoboard Layout and Final Build

Some notes on the protoboard layout I used. NB: an important decision to make is which way around
you prefer to orient a breadboard and it's power rails. I prefer as illustrated:

![LM386AudioAmp_protoboard_layout](./assets/LM386AudioAmp_protoboard_layout.jpg?raw=true)

![LM386AudioAmp_build](./assets/LM386AudioAmp_build.jpg?raw=true)

## Credits and References

* [LM386 datasheet](https://www.futurlec.com/Linear/LM386N-3.shtml)
