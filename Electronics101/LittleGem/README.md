# LittleGem/A386

A basic Smokey-inspired LM386 guitar power amp.

## Notes

The "Little Gem" amplifier by [runoffgroove](http://www.runoffgroove.com/littlegem.html)
is one of numerous LM386-based amplifiers descending from the [original Smokey amp](http://www.smokeyamps.com/).
The "A386" is a "Little Gem" variant by [General Guitar Gadgets](http://www.generalguitargadgets.com/effects-projects/amps/a386-amp/)
that basically packages the circuit with a few more frills like a conventional pedal.

The Smokey is about as basic as you can get - [an LM386 and two caps](http://www.electrosmash.com/smokey-amp-analysis),
see [my Smokey build here](../Smokey).

Little Gem/A386 takes some of the [suggestions by Dave Stork](http://www.blueguitar.org/new/schem/_ss/smokey.txt) and
enhances the circuit in a few ways:

* adds variable gain control ranging from about [25](http://www.wolframalpha.com/input/?i=2*15000%CE%A9%2F%28150+%2B+1%CE%A9%2F%281%2F1350+%2B+1%2F5000%29%29) to [200](http://www.wolframalpha.com/input/?i=2*15k%CE%A9%2F%28150+%2B+0%CE%A9%29) (the original Smokey was fixed at 200)
* adds input AC coupling with a 10nF capacitor and removes the 47μF bypass capacitor
* adds output-side master volume control
* adds an output-compensating [Zobel Network](http://en.wikipedia.org/wiki/Zobel_network)
* increases the output coupling capacitor from 47μF to 220μF to improve low-end performance
* A386 modifications add a power indicator, power-source selection and reverse-current protection

I didn't have anything as small as a 25Ω rheostat for output volume control, so it uses a 22Ω resistor in parallel with a 500kΩ trimpot which gives
a [range of about 0-21Ω](http://toolbox.tardate.com/?formula=22%7C500#ResistorCalculator).

The breadboard build as described below is pretty temperamental due to interference and the possibility of dodgy connections.
But even on a breadboard it's good enough to say it "basically works":

* seems to lose the higher frequencies so the clean sound is pretty flat
* the overdrive is surprisingly warm but with the fizzle of electronic distortion
* it can't handle very high gain without farting out and oscillating heavily
* it drives some 6Ω speakers to surprisingly loud levels - enough for the neighbours to hear!

I might put the components on a PCB next to get a better gauge of the true performance.


## Construction

![Breadboard](./assets/LittleGem_bb.jpg?raw=true)

![The Schematic](./assets/LittleGem_schematic.jpg?raw=true)

![The Build](./assets/LittleGem_build.jpg?raw=true)

## Credits and References
* [my Smokey build](../Smokey)
* [Little Gem & Little Gem MkII](http://www.runoffgroove.com/littlegem.html)
* [General Guitar Gadgets A386 Amp](http://www.generalguitargadgets.com/effects-projects/amps/a386-amp/)
* [Smokey Amps](http://www.smokeyamps.com/) - official site
* [Smokey Amp Analysis](http://www.electrosmash.com/smokey-amp-analysis) - excellent circuit analysis of the original Smokey amp.
* [Observations on the Smokey circuit by Dave Stork](http://www.blueguitar.org/new/schem/_ss/smokey.txt)
* [LM386 datasheet](http://www.futurlec.com/Linear/LM386N-3.shtml)
