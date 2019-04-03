# #096 Smokey

A quick build of a Smokey-like LM386 guitar power amp.

Here's a quick demo of the circuit in action:

[![Smokey](https://img.youtube.com/vi/1Fk-NTBetNM/0.jpg)](https://www.youtube.com/watch?v=1Fk-NTBetNM)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The [Smokey](http://www.smokeyamps.com/) is pretty much the grandfather of a range of LM386-based guitar amps,
like the "Little Gem"/A386 variant by [General Guitar Gadgets](http://www.generalguitargadgets.com/effects-projects/amps/a386-amp/) ..
see [my build here](../LittleGem).

So I thought I'd see what the Smokey really sounds like. This circuit uses the details from
[this analysis](http://www.electrosmash.com/smokey-amp-analysis)
to do the build. The 47μF C1 is required to correctly bias the input since we have a direct connection from guitar to the op-amp input.

I had to make a couple of variations to get it to work properly:

* I had to remove the short from pins 1-8 of the LM386 because it couldn't handle the gain. Without the short, the amp runs at the default 20x.
* adding 100μF C3 filters noise from the power supply. This is essential with a switch-mode 9V adapter, not required with a battery.


## Construction

![Breadboard](./assets/Smokey_bb.jpg?raw=true)

![The Schematic](./assets/Smokey_schematic.jpg?raw=true)

![The Build](./assets/Smokey_build.jpg?raw=true)

## Credits and References
* [my LittleGem/A386 build](../LittleGem)
* [Smokey Amps](http://www.smokeyamps.com/) - official site
* [Smokey Amp Analysis](http://www.electrosmash.com/smokey-amp-analysis) - excellent circuit analysis of the original Smokey amp.
* [Observations on the Smokey circuit by Dave Stork](http://www.blueguitar.org/new/schem/_ss/smokey.txt)
* [LM386 datasheet](https://www.futurlec.com/Linear/LM386N-3.shtml)
