# #499 HS088 Low-voltage Amplifier

Adding a low-voltage BJT class A amplifier for the HS088 Audio Effects Chip.

![Build](./assets/Amplified_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/tW9xAA9nvXE/0.jpg)](https://www.youtube.com/watch?v=tW9xAA9nvXE)

## Notes

The [HS088](../) audio effects chip encodes a "ding dong" wave, but like many effects chips it cannot drive a speaker particularly well
in its default circuit configuration.

Adding an LM386 is a very simply way to provide amplification, but that requires a power supply of 4-5 volts.
But I was interested to explore circuit ideas for providing decent amplification at lower voltages - specifically
with a 3V CR2032 coin cell.

There are other amplifier-on-a-chip options that work at these voltage levels (such as the TDA2822), but
first I decided to try a descrete BJT design.

My first test was with a simple single-stage common-emitter design (R1=6.8kΩ, R2=4.7kΩ, Rc=50Ω, Re=10Ω with 47µF bypass - designed for Icq=40mA).
Unloaded, it achieved excellent amplification, but proved to be very poor at power transfer to the speaker.

Adding a push-pull output stage started to produce some more decent results with an 8Ω speaker.
The final circuit described below is an adaptation of a
[design from deeptronic](https://www.deeptronic.com/electronic-circuit-design/small-audio-power-amplifier-using-3-transistors/)
that was in turn inspired by a [design from Bowden's](http://www.bowdenshobbycircuits.info/page8.htm).

## Circuit Design

![Schematic](./assets/Amplified_schematic.jpg?raw=true)

![Breadboard](./assets/Amplified_bb.jpg?raw=true)

Testing on a breadboard:

![Amplified_bb_test](./assets/Amplified_bb_test.jpg?raw=true)

## Building an Amplifier Module

After verifying component values on a breadboard, I but the amplifier circuit on a small piece of protoboard.

![Amplified_protoboard](./assets/Amplified_protoboard.jpg?raw=true)

I've taking some measurements of the amplifier performance with a 1kHz sine wave and 3V power supply.

### Test 1: Adjusted for minimum distortion

Adjusting the input attenuation for the sweet spot for minimum distortion,
gain is around [19](https://www.wolframalpha.com/input/?i=475mV%2F25mV&assumption=%7B%22C%22%2C+%22mV%22%7D+-%3E+%7B%22Unit%22%7D).

* CH1 (yellow) : 400mV input signal (before attenuation)
* CH2 (blue) : unloaded output (~475mV)
* CH3 (red) : ~25mV input signal (after attenuation)

![scope_25mV](./assets/scope_25mV.gif?raw=true)

### Test 2: Maximum Input Without Clipping

About 40mV is the largest input signal that can be handed before the output starts clipping.
The output is quite distorted at this point though.

* CH1 (yellow) : 400mV input signal (before attenuation)
* CH2 (blue) : unloaded output (~1000mV)
* CH3 (red) : ~40mV input signal (after attenuation)

![scope_40mV](./assets/scope_40mV.gif?raw=true)

### Test 3: Overdrive!

The circuit is completely overdriven with a 400mV input. The output is essentially a square wave at this point!

* CH1 (yellow) : 400mV input signal
* CH2 (blue) : ~2V unloaded output

![scope_400mV](./assets/scope_400mV.gif?raw=true)

### Final Build

Finally, putting it all together. First, as always, verify on a breadboard:

![Amplified_protoboard_bb_test](./assets/Amplified_protoboard_bb_test.jpg?raw=true)

I used another strip of protoboard as the mainboard to mount the:

* HS088 chip and supporting components (trigger switch, output transistor)
* volume control
* CR2032 battery holder
* 3.5mm phone jack
* amp module mounting

![Amplified_protoboard_modules](./assets/Amplified_protoboard_modules.jpg?raw=true)

The final build, with volume adjusted for maximum output without distortion procudes an amplified
output that is perhaps 3x the apparent volume of the unamplified HS088 module.
I don't have an [SPL meter](https://en.wikipedia.org/wiki/Sound_level_meter) to verify this with a measurement (yet).

![Build](./assets/Amplified_build.jpg?raw=true)

## Credits and References

* [LEAP#359 HS088 Audio Effects Chip](../)
* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml)
* [2N3906 datasheet](https://www.futurlec.com/Transistors/2N3906.shtml)
* [LM386 datasheet](https://www.futurlec.com/Linear/LM386N-3.shtml)
* [TDA2822 datasheet](https://www.futurlec.com/Philips/TDA2822.shtml)
* [Small Audio Power Amplifier Using 3 Transistors](https://www.deeptronic.com/electronic-circuit-design/small-audio-power-amplifier-using-3-transistors/) - deeptronic design use in this project
* [3 Transistor Audio Amp (50 milliwatt)](http://www.bowdenshobbycircuits.info/page8.htm) - inspiration for the deeptronic design
