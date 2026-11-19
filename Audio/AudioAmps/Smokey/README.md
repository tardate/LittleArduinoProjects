# #096 Smokey

Testing the original Smokey LM386 guitar power amp design, with a classic case to hit you straight between the eyes!

![The Build](./assets/Smokey_build.jpg?raw=true)

## Notes

The [Smokey](https://www.smokeyamps.com/) is pretty much the grandfather of a range of LM386-based guitar amps,
like the "Little Gem"/A386 variant by [General Guitar Gadgets](http://www.generalguitargadgets.com/effects-projects/amps/a386-amp/) -
see [LEAP#095 Little Gem](../LittleGem/).
I thought I'd see what the original Smokey really sounds like.

The Smokey Amp can drive any 4, 8 or 16Ω speaker cabinet, including 4x12s, and can even be used on the input of another amp as a fuzz box or booster.

There are no controls on the amp, just one input, and one output, meaning that everything is controlled by the guitar volume and tone knobs.

### The LM386

The LM386 is a low-voltage, low-power audio power amplifier integrated circuit, originally developed by National Semiconductor in the mid-1970s. It operates from a single power supply, typically between 4V and 12V, and requires very few external components to produce an audio amplifier with a typical output power of up to 0.5W. Its internally configured voltage gain is 20 (26dB). The chip incorporates internal biasing, thermal protection and a bypass pin for reducing power-supply and bias-related noise. With its low component count, small size and ease of use, the LM386 is widely used in battery-powered audio devices, small radios, intercoms, portable speakers and simple guitar practice amplifiers.

![lm386-ref](../../../Electronics101/LM386/assets/lm386-ref.jpg)

## Circuit Design

Designed with Fritzing: see [Smokey.fzz](./Smokey.fzz).

The circuit uses the details from
[this analysis](https://web.archive.org/web/20260518123756/https://electrosmash.com/smokey-amp-analysis). It features:

* fixed 200x gain
* 47µF bypass cap to improve bass response. This has little effect on built-in speaker, but can improve performance with an external speaker.

![breadboard](./assets/Smokey_bb.jpg?raw=true)

![schematic](./assets/Smokey_schematic.jpg?raw=true)

Testing on a breadboard:

![bb_build](./assets/Smokey_bb_build.jpg?raw=true)

## Classic Smokey Build

I believe the amp got its name from originally being built into a cigarette packet. I actually saved an empty pack from my smoking days just for this purpose! Time to put it to work...

For the final build, I've made some modifications to the input and output wiring, not shown on the schematic:

* Mono 6.35mm input jack is wired to power-up the amp when an instrument is plugged in.
* I've added an auxiliary speaker jack. It by-passes the built-in speaker when connected.

Transferred to a small protoboard:

![build01a](./assets/build01a.jpg?raw=true)

Mounted inside the cigarette packet:

![build01b](./assets/build01b.jpg?raw=true)

![build01c](./assets/build01c.jpg?raw=true)

![build01d](./assets/build01d.jpg?raw=true)

## How Does it Perform?

Very Poorly!

* The circuit is highly prone to noise and uncontrolled oscillation, given the 200x gain, without any of the mitigations recommended in the LM386 datasheet.
    * This is highly dependent on the instrument input and output speaker characteristics.
    * For example, with an external 8Ω hi-hi speaker I used in testing, it behaved itself pretty well.
* The 200x gain means it is not really possible to dial in a clean tone except at very low volumes
* The lack of any power supply filtering makes it most suitable for battery use only.

Many improvements to the Smokey have been suggested.
These appear in later designs, such as

* [LEAP#095 Little Gem](../LittleGem/)
* [LEAP#104 Ruby Guitar Amp](../Ruby/)

The most useful modification for the Smokey circuit itself would be to use a switch between pins 1-8 to allow switching between 20x and 200x gain, depending on specific inputs, outputs, and desired effect.

## Credits and References

* [LEAP#095 Little Gem](../LittleGem/)
* [LEAP#104 Ruby Guitar Amp](../Ruby/)
* [Smokey Amps](https://www.smokeyamps.com/) - official site
* [Smokey Amp Analysis](https://web.archive.org/web/20260518123756/https://electrosmash.com/smokey-amp-analysis) - excellent circuit analysis of the original Smokey amp.
* [Observations on the Smokey circuit by Dave Stork](https://web.archive.org/web/20061014131022/http://www.blueguitar.org/new/schem/_ss/smokey.txt)
* [LM386 Product Info - TI](https://www.ti.com/product/LM386)
* [LM386 datasheet](https://www.futurlec.com/Linear/LM386N-3.shtml)
