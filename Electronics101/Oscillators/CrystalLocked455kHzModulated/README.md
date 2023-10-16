# #484 Crystal-Locked 455 kHz AM Oscillator

A crystal-locked 455 kHz carrier oscillator with fixed-frequency audio tone amplitude modulation (AM) for IF alignment.

![Build](./assets/CrystalLocked455kHzModulated_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/o3_eylHBAME/0.jpg)](https://www.youtube.com/watch?v=o3_eylHBAME)

This shows alignment of the
[LEAP#462 HX108-2 AM kit](../../../Radio/AM/HX108-2).

## Notes

Transformers in AM radios are generally aligned to an intermediate frequency of 455kHz,
meaning that band-pass filters attempt to isolate the intermediate frequency carrier before extracting the signal.

A test signal at 455kHz modulated by an audio tone is therefore a useful bit of test equipment for audibly checking the alignment of the filters.

This project is a build of a very common modulated 455kHz design, and it works like a charm!
One of the many sources for the design is a Silicon Chip article from Jan 2008 -
[The Minispot 455kHz Modulated Oscillator](http://archive.siliconchip.com.au/cms/A_109838/article.html).

## Circuit Design

This is a simple circuit in two basic parts:

* a 455 kHz crystal-locked oscillator providing the carrier
* an RC astable multivibrator running at an audible frequency that is used to modulate the carrier

The circuit works across a wide voltage range (from about 3V and up).

![Schematic](./assets/CrystalLocked455kHzModulated_schematic.jpg?raw=true)

The frequency of the audio signal is determined by the values of R1, R2, C1 and C2 (making R1==R2, and C1==C2 maintains ~50% duty cycle).
With R1 = R2 = 33kHz, possible values of C1/C2 include:

| C1, C2 | Predicted Frequency | Measured Frequency | Note |
|--------|---------------------|--------------------|------|
| 47nF   | [465Hz](https://www.wolframalpha.com/input/?i=1%2F(ln(2)(+2+*+33k%CE%A9+*+47nF))) | 410Hz  | As used in the original and many derivative designs |
| 22nF   | [994Hz](https://www.wolframalpha.com/input/?i=1%2F(ln(2)(+2+*+33k%CE%A9+*+22nF))) | 1.0kHz | What I decided to use |

The predicted frequency is calculated by:

    f = 1/(ln(2) * ( R1 * C1 + R2 * C2))

See [LEAP#049](../BjtRcOscillator) for more on the RC oscillator design.

## Breadboard Build

I initially tested the circuit on a breadboard with a 5V power supply.

![CrystalLocked455kHzModulated_bb](./assets/CrystalLocked455kHzModulated_bb.jpg?raw=true)

![CrystalLocked455kHzModulated_bb_build](./assets/CrystalLocked455kHzModulated_bb_build.jpg?raw=true)

The following traces capture the audio oscillator signal.

With 47nF capacitors / 410Hz:

![signal_47nF](./assets/signal_47nF.gif?raw=true)

With 22nF capacitors / 1.0kHz:

![signal_22nF](./assets/signal_22nF.gif?raw=true)

The resulting modulated output (captured with peak function to demonstrate the modulation):

![signal_modulated](./assets/signal_modulated.gif?raw=true)

## Ugly Tubular Build!

I have (lots) of old solder tubes that I've been saving for a rainy day.
This seemed to be a good opportunity to try and put them to use.

First step was to build the "business end" ugly style in a for that would fit in the solder tube.
One thing I got a little off - I'd make the probe end longer next time, in order to get deep inside the guts of a radio.

![CrystalLocked455kHzModulated_build_business_end](./assets/CrystalLocked455kHzModulated_build_business_end.jpg?raw=true)

One tube for the electronics, and two tubes to hold 4 x AAA (they just fit nicely)

All joined together, the thing is a bit of a beast, but it works just fine.
The discoloration of the tube (and components inside) appears to be an unexpected CSI super-glue experiment!
I used super glue to join the tubes, and the fumes appear to have attached themselves to any specs of dust or oil - no latent fingerprints tho!

![Build](./assets/CrystalLocked455kHzModulated_build.jpg?raw=true)

## Credits and References

* [455kHz IF Signal Generator with AM Modulation](http://electronics-alfiemalfie.blogspot.com/p/455khz-intermediate-frequency-generator.html) - source project write-up
* [The Minispot 455kHz Modulated Oscillator](http://archive.siliconchip.com.au/cms/A_109838/article.html) - original Silicon Chip article, Jan 2008
* [LEAP#462 HX108-2 AM kit](../../../Radio/AM/HX108-2)
