# #554 Jet Engine Startup Effect

Fine tuning an analog jet engine startup sound simulation, using a zener noise generator and CD4046 VCO.

![Build](./assets/JetEngine_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/XU06NOCgH_g/0.jpg)](https://www.youtube.com/watch?v=XU06NOCgH_g)

## Notes

I'm planning an upcoming project where I would like a "jet engine startup" sound effect.
Of course, these days just playing back an audio recording from an SD card is cheap, easy,
and just like the real thing.

But where's the challenge in that! Surely a reasonable simulation could be achieved with some simple electronics?
My web searches didn't turn up much in the way of prior art however, with
[many circuits](http://www.circuitstoday.com/jet-engine-sound-generator)
actually turning out to be various applications of the
[Holtek](https://www.holtek.com/producthome) HT2844P sound effect chip (that included a jet engine sound).
Holtek is an interesting Taiwanese IC design house that still produces a line of flash and MCU-based voice and music effects
chips, but the HT2844P appears to even pre-date their [EOL notification list](https://www.holtek.com/en/eol_notification_expired_products).
I can't even find the HT2844P in the refurb markets.

### Design Concept

I had a feeling I could get a reasonable simulation of a jet engine by mixing a noise source with a carrier wave,
with the frequency of the carrier rising to give a feeling of the engine spinning up to speed.

For the noise source, I'm using a reverse biased NPN transistor in zener mode breakdown -
based on the same idea I tested in [LEAP#140 ZenerModeEffects](../ZenerModeEffects).

For the carrier, I'm using the VCO from a CD4046,  similar to my tests in [LEAP#382 CD4046 VCO](../../../Electronics101/CD4046/VCO).

I played around with this on a breadboard for a while to get a result I'm pretty happy with.
I also tried a little simulation of the sound effect with [Pure Data](https://puredata.info/): see [engine_simulation.pd](./engine_simulation.pd),
though this is too clean as it is.

Some of the key decisions I made as a result of experimentation:

* adding an LC tank to zener-mode NPN seems to amplify and enhance the noise source
* I spent quite a bit of time choosing the min/max freuqncies for the VCO eventually settling on [425 Hz](https://www.wolframalpha.com/input/?i=2%2F%28100nF+*47k%CE%A9%29) rising to [4680 Hz](https://www.wolframalpha.com/input/?i=2%2F%28100nF+*1%2F%281%2F47k%CE%A9%2B1%2F4.7k%CE%A9%29%29)
* the rising VCO frequency is achieved with a simple RC circuit with a time constant (𝛕) of [4.7s](https://www.wolframalpha.com/input/?i=100k%CE%A9*47%C2%B5F)
* also, quite a bit of time deciding on the mix-levels for the noise and carrier
* I started with a two-stage common-emitter amplifier but eventually switched to an LM386 in order to get decent gain in a small package.

I was prepared to add some more distortion effects either to the final signal, or to the carrier before mixing,
but I don't think this is necessary. The fact I'm using a piezo buzzer instead of an audio speaker adds enough
"desirable" distortion already. I did actually start with an 8Ω speaker, but switched to the piezo speaker
because in the final application, I expect to squeeze this circuit into the smallest possible space.

To set the min and max frequencies of the CD4046 VCO, a "rule of thumb" estimate is 2 x time constant:

    fmin = 2/(C6.R5)
    fmax = 2/(C6(R6||R5))

Selecting R6=4.7kΩ, R5=47kΩ, C6=100nF produces estimated range of
[425 Hz](https://www.wolframalpha.com/input/?i=2%2F%28100nF+*47k%CE%A9%29) -
[4680 Hz](https://www.wolframalpha.com/input/?i=2%2F%28100nF+*1%2F%281%2F47k%CE%A9%2B1%2F4.7k%CE%A9%29%29)

### Power

The noise generator requires a minimum of 9V to trigger the breakdown. It seems most happy and produced the best results from 9-9.5V,
and the complete circuit only consumes about 21mA i.e. [~190mW](https://www.wolframalpha.com/input/?i=21mA*9V)

## Construction

Some points to note about the schematic:

* the biasing tank circuit comprising L1, C1, C2 controls the type and quality of noise generated.
* Q2 collector-feedback biased pre-amp for the noise output
* R4 controls the relative mix of noise v VCO in the output (I had a variable resistor here for testing, settled on final value of 680kΩ)
* R5 R6 C6 control the min/max frequencies on the VCO
* J1 piezeo speaker is ideal for a "grungy" output

![Breadboard](./assets/JetEngine_bb.jpg?raw=true)

![Schematic](./assets/JetEngine_schematic.jpg?raw=true)

Running on a breadboard:

![Build](./assets/JetEngine_build.jpg?raw=true)

## Credits and References

* [CD4046 Datasheet](https://www.futurlec.com/4000Series/CD4046.shtml)
* [LM386 datasheet](https://www.futurlec.com/Linear/LM386N-3.shtml)
* [Holtek](https://www.holtek.com/producthome)
* [Holtek](https://en.wikipedia.org/wiki/Holtek) - wikipedia
* [Jet Engine Sound Generator circuit using the HT2844P](http://www.circuitstoday.com/jet-engine-sound-generator)
