# #098 GuitarHeadphoneAmp

An LM386 fixed-gain guitar headphone amp.

![GuitarHeadphoneAmp_protoboard](./assets/GuitarHeadphoneAmp_protoboard.jpg?raw=true)


## Notes

Yet another LM386-based audio amplifier
similar to the [LittleGem/A386/Smokey](../LittleGem) series,
this time adapted as a guitar headphone amp.

There are various "headphone amp" circuits based on the LM386.
After trying many of the variations, I found that going back to basics performed just about the best
(per the reference circuits in the datasheet).

Features of the circuit:
* default 20x gain (no extra components required)
* simple capacitive-coupling with ~50k impedence matching for a guitar input
* ring of the 6.35mm connector is used to switch power - use with a standard mono cable
* mono output is sent to left and right channels of the headphone socket

How it performs:
* clean signal with a slight warm overdrive at maximum guitar ouput
* performance can be a bit temperamental on a broadboard, but when I put it on a protoboard it performs quite well.

## Construction

![Breadboard](./assets/GuitarHeadphoneAmp_bb.jpg?raw=true)

![The Schematic](./assets/GuitarHeadphoneAmp_schematic.jpg?raw=true)

![The Build](./assets/GuitarHeadphoneAmp_build.jpg?raw=true)

![GuitarHeadphoneAmp_protoboard](./assets/GuitarHeadphoneAmp_protoboard.jpg?raw=true)

## Credits and References

* [LM386 datasheet](https://www.futurlec.com/Linear/LM386N-3.shtml)
* Based on "Project 07 - Guitar Headphone Amplifier" from [Beginning Analog Electronics through Projects](http://www.amazon.com/gp/product/0750672838/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=0750672838&linkCode=as2&tag=itsaprli-20&linkId=QUZ3GKIDBEXGNSG7)
* [my LittleGem/A386 build](../LittleGem)
* [MXR™ Headphone Amp](http://www.generalguitargadgets.com/effects-projects/boosters/headphone-amp/) - circuit details of an alternative unit
