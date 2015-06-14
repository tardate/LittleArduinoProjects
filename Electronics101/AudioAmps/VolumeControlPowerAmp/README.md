# VolumeControlPowerAmp

An LM386 fixed-gain audio power amp with volume control.

## Notes

This variant in the line of LM386-based amplifiers is based on a design in [Beginning Analog Electronics through Projects](http://www.amazon.com/gp/product/0750672838/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=0750672838&linkCode=as2&tag=itsaprli-20&linkId=QUZ3GKIDBEXGNSG7).

It is similar the [Little Gem/A386](../LittleGem), but with a few differences:

* The LM386 gain is actually fixed at 200x with 10μF C5, with volume control on the input provided by R1.
* it adds a small RF-bypass capacitor C2 to prevent RF-breakthough of radio signals
* the output coupling capacitor is slightly smaller at 10μF
* additional 100nF low-pass filter on the power supply

How it performs:
* the input volume control works perfectly
* the RF-bypass capacitor does appear to give a cleaner signal
* the lack of gain control means the overdrive level is fixed. It's a pretty nice and warm effect though.

## Construction

![Breadboard](./assets/VolumeControlPowerAmp_bb.jpg?raw=true)

![The Schematic](./assets/VolumeControlPowerAmp_schematic.jpg?raw=true)

![The Build](./assets/VolumeControlPowerAmp_build.jpg?raw=true)

## Credits and References
* Based on "Project 05 - Variable-Gain Audio Power Amplifier" from [Beginning Analog Electronics through Projects](http://www.amazon.com/gp/product/0750672838/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=0750672838&linkCode=as2&tag=itsaprli-20&linkId=QUZ3GKIDBEXGNSG7)
* [my LittleGem/A386 build](../LittleGem)
* [Smokey Amps](http://www.smokeyamps.com/) - official site
* [Smokey Amp Analysis](http://www.electrosmash.com/smokey-amp-analysis) - excellent circuit analysis of the original Smokey amp.
* [Observations on the Smokey circuit by Dave Stork](http://www.blueguitar.org/new/schem/_ss/smokey.txt)
* [LM386 datasheet](http://www.futurlec.com/Linear/LM386N-3.shtml)

