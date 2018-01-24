# #359 AudioEffectsChips/HS088

Figuring out the HS-088 "Ding Dong" audio effects chip.

![Build](./assets/HS088_build.jpg?raw=true)

Here's a quick demo...

[![Build](http://img.youtube.com/vi/3f8TGjILb_U/0.jpg)](http://www.youtube.com/watch?v=3f8TGjILb_U)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The HS-088 chip produces a typical electronic doorbell "ding-dong", which repeats three times when triggered.
It is very similar to - and not any more pleasant! - than the kind of effect you can get with common 555 circuits
like [LEAP#059 TwoToneDoorbell](../../555Timer/TwoToneDoorbell).

![HS088_chip](./assets/HS088_chip.jpg?raw=true)

## Circuit

The chip requires a few external components:

* 3-4.5 V power supply
* a small signal NPN transistor such as the S8050
* 8Ω speaker
* switch
* a 100nF capacitor (104)
* a pull-down-resistor e.g. 10kΩ

A few things to note:

* most schematics available around the web do not include the pull-down resistor. I found that without this, the effect could be triggered only once and would not reset.
* the output volume is very low. It seems it would need additional amplification to be useful

![Schematic](./assets/HS088_schematic.jpg?raw=true)

![Build](./assets/HS088_build.jpg?raw=true)

## Credits and References
* [10pcs Dingdong Tone Doorbell Music Voice Module Board IC Sound Chip For DIY/Toy](https://www.aliexpress.com/item/10pcs-Dingdong-Tone-Doorbell-Music-Voice-Module-Board-IC-Chip-For-DIY-Toy/32661936820.html) - aliexpress seller
* [S8050 Datasheet](http://electronics.se-ed.com/magic/s8050.pdf) - NPN BJT
* [LEAP#059 TwoToneDoorbell](../../555Timer/TwoToneDoorbell)
* [..as mentioned on my blog](https://blog.tardate.com/2017/12/leap359-hs-088-effects-chip.html)
