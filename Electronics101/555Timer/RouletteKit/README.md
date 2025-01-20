# #084 Roulette Kit

Build and examine the workings of a commercial 555 Roulette kit

![The Build](./assets/RouletteKit_build.jpg?raw=true)

Here's a quick video of it in action:

[![RouletteKit demo](https://img.youtube.com/vi/sRrmW6ToDyQ/0.jpg)](https://www.youtube.com/watch?v=sRrmW6ToDyQ)

## Notes

Julian Ilett really does excellent videos on YouTube, even when he's just building a dinky electronic kit
like this [555 Roulette wheel](https://youtu.be/zgfJeZ20nhc).

So I got myself one of the kits too - mine was all of USD1.11 with free shipping from [aliexpress](https://www.aliexpress.com/item/1Pcs-Electronic-Lucky-Rotary-Suite-DIY-Kits-Production-Parts-And-Components-New/32319812188.html). Dang, now it is only USD1.05!!

And surprise, surprise - mine also came with surface mount components despite the product info online that clearly details DIPs and through-the-hole parts.
Never mind, a chance to steady my hand for a bit of surface-mount soldering.
The IC pin pitch is not too fine, but you definitely need tweezers to deal with the [MELFs](http://en.wikipedia.org/wiki/MELF_electronic_components).

I must say I was also a little surprised when the unit worked first go - I was sure there would be at least one dry solder joint or bridged connection somewhere.

So how does it work? Basically like this I think:

* pressing the switch charges the R1/C1 network and turns on the Q1 NPN
* Q1 will remain on while C1 discharges through R1 with time constant (𝛕) of [22s](https://www.wolframalpha.com/input/?i=470k%CE%A9+*+47%CE%BCF).
* Q1 activates the 555 in astable configuration, with a decaying frequency governed by the discharge of C2 through R3 when Q1 turns off.
* pulse stream from 555 pin 3 feeds the CD4017 pin 14 clock signal
* the CD4017 will enable its 10 output pins in sequence, lighting the attached LED, until the pulse stream stops

Note: this is the same basic "ROULETTE Circuit" as found in many 555 circuit references, such as
<https://www.555-timer-circuits.com/roulette.html>

## Construction

![The Breadboard](./assets/RouletteKit_bb.jpg?raw=true)

![The Schematic](./assets/RouletteKit_schematic.jpg?raw=true)

![The Build](./assets/RouletteKit_build.jpg?raw=true)

## Credits and References

* [Basic Electronics: Surface Mount Components Kit - 555 Roulette](https://youtu.be/zgfJeZ20nhc) - excellent tutorial by Julian Ilett building the same kit
* [1Pcs Electronic Lucky Rotary Suite DIY Kits Production Parts And Components New](https://www.aliexpress.com/item/1Pcs-Electronic-Lucky-Rotary-Suite-DIY-Kits-Production-Parts-And-Components-New/32319812188.html) - seller page on aliexpress
* [ROULETTE Circuit](https://www.555-timer-circuits.com/roulette.html) - similar design
* [CD4017 datasheet](https://www.futurlec.com/4000Series/CD4017SMD.shtml)
* [LM555 datasheet](https://www.futurlec.com/Linear/LM555CM.shtml)
