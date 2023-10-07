# #660 WarHawk 40K

Taking the Airfix 1:72 Curtiss Warhawk in a slightly unusual direction, with LED effects driven by a CD4060 ripple counter.

![Build](./assets/WarHawk40K_build.jpg?raw=true)

Here's a quick demo..

[![clip](./assets/demo-cover.jpg?raw=true)](https://www.instagram.com/reel/CjF6VCdhZmM/)

## Notes

I enjoyed the [Airfix P-40B Flying Tiger in 1:72 (LEAP#648)](../FlyingTigers) so much
that I got another (but A01003B instead of the A01003 kit).

Aside from the engineering, the lines of the craft really made me see the "hawk",
and so this flight of fancy was born.

### Circuit Design

There are a range of LEDs on the model (cockpit, nose, crown/head, controller).
I first thought of driving them with an AtTiny or PIC, but eventually settled on a simple
RC-oscillator drive CD4060 ripple counter.

![bb](./assets/WarHawk40K_bb.jpg?raw=true)

![schematic](./assets/WarHawk40K_schematic.jpg?raw=true)

Testing the circuit on a breadboard:

![bb_build](./assets/WarHawk40K_bb_build.jpg?raw=true)

Verifying the LED installation from a breadboard. After this, I transferred the circuit to a small piece of protoboard.

![bb_test](./assets/WarHawk40K_bb_test.jpg?raw=true)

### LED resistor Values

| LED# | Name                | Resistor# | 5V Breadboard | 5V Model |
|------|---------------------|-----------|---------------|----------|
| LRr  | Cockpit Red (right) | RR        | 1kΩ           | 1kΩ      |
| LRl  | Cockpit Red (left)  | RR        | 1kΩ           | 1kΩ      |
| LY   | Nose Yellow         | RY        | 220Ω          | 100Ω     |
| LG   | Controller Green    | RG        | 220Ω          | 10kΩ     |
| LBc  | Head Blue (center)  | RBc       | 1kΩ           | 1kΩ      |
| LBl  | Head Blue (left)    | RBlr      | 1kΩ           | 470Ω     |
| LBr  | Head Blue (right)   | RBrr      | 1kΩ           | 470Ω     |

### Model Build

Test fitting the kit before starting the mods. I really like the engineering of this series of P40s from Airfix.

![build01a](./assets/build01a.jpg?raw=true)

Mocking up the basic design of my "transformer".

![build01b](./assets/build01b.jpg?raw=true)

Basic paint scheme complete

![build02a](./assets/build02a.jpg?raw=true)

![build02b](./assets/build02b.jpg?raw=true)

My first trial of the AK Light Rust wash and I like the result!

![build02c](./assets/build02c.jpg?raw=true)

The base is just some high density foam offcuts stuck together, carved and lathered with tiling grout.

![build03a](./assets/build03a.jpg?raw=true)

All the electronics fit on a small piece of protoboard that got hot-glued into the base.

![build04a](./assets/build04a.jpg?raw=true)

#### Completed (Without Power)

Some shots of the model after completing the assembly and finishing, but not powered on.

![build05a](./assets/build05a.jpg?raw=true)
![build05b](./assets/build05b.jpg?raw=true)
![build05c](./assets/build05c.jpg?raw=true)
![build05d](./assets/build05d.jpg?raw=true)

#### Completed (With Power)

With power applied, the LEDs all strobe at different rates for a pseudo-random effect.

![build06a](./assets/build06a.jpg?raw=true)
![build06b](./assets/build06b.jpg?raw=true)
![build06c](./assets/build06c.jpg?raw=true)
![build06d](./assets/build06d.jpg?raw=true)
![build06e](./assets/build06e.jpg?raw=true)
![build06f](./assets/build06f.jpg?raw=true)
![build06g](./assets/build06g.jpg?raw=true)
![build06h](./assets/build06h.jpg?raw=true)
![build06i](./assets/build06i.jpg?raw=true)

![build07a](./assets/build07a.jpg?raw=true)

## Credits and References

* [this project on scalemates](https://www.scalemates.com/profiles/mate.php?id=74137&p=projects&project=132125)
* [Curtiss P-40B Warhawk Airfix, No. A01003B 1:72](https://www.scalemates.com/kits/airfix-a01003b-curtiss-p-40b-warhawk--1260859)
* [Curtiss P-40 Warhawk](https://en.wikipedia.org/wiki/Curtiss_P-40_Warhawk)
* [CD4060 datasheet](https://www.futurlec.com/4000Series/CD4060.shtml)
