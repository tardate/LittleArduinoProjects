# #409 Conehead

The Conehead is the fourth in a series of beautiful electronic bug boards from the Boldport Club, Project #24 April 2018.
This one chirps in response to light.

Here's a quick demo..

[![clip](https://img.youtube.com/vi/hKurYsvKQZk/0.jpg)](https://www.youtube.com/watch?v=hKurYsvKQZk)


![Build](./assets/conehead_build.jpg?raw=true)

## Notes

Conocephalus is a genus of bush-crickets, known as coneheads:

[![clip](https://img.youtube.com/vi/AAgqkgFo2wE/0.jpg)](https://www.youtube.com/watch?v=AAgqkgFo2wE)

Now I have one beautifully rendered in 3D by Boldport. And unlike the live video above, it chirps in response to light.

## The Kit

![conehead_kit](./assets/conehead_kit.jpg?raw=true)

| Qty  |  Item |
|------|-------|
| 1x   |  1W 8Ω 13mm speaker, Multicomp MCKP1330SP1-4723           |
| 1x   |  Phototransistor, Everlight PT333-3C                      |
| 1x   |  Hex Schmitt trigger inverter, ON Semi MC74HC14ADR2G      |
| 1x   |  47µF electrolytic capacitor, Multicomp MCUMR6V3476M4X5   |
| 1x   |  1µF ceramic capacitor, Suntan TS170R1H105MSBFA0R         |
| 2    |  0.1µF ceramic capacitor, Multicomp MC0805B104K500A2.54MM |
| 1x   |  0.01µF ceramic capacitor, Suntan TS170R2A103KSBBA0R      |
| 12   |  x 4.7KΩ resistor, Multicomp MCF 0.25W 4K7                |
| 1x   |  220Ω resistor, Multicomp  MCRE000029                     |
| 1x   |  2032 battery holder, Linx BAT-HLD-001                    |
| 1x   |  Small signal diode, Diotech 1N4148                       |
| 1x   |  SPST switch, Apem IKD0103101                             |
| 16cm |  20AWG wire                                               |

I really appreciate the care and attention that obviously goes into selecting parts.
In this kit, the speaker is particularly impressive - it even has an adhesive outer ring for securing to the PCB.

![conehead_kit_parts](./assets/conehead_kit_parts.jpg?raw=true)

## Chirp Circuit

Full details are available [Boldport Conehead page](https://www.boldport.com/products/conehead),
but I redrew the circuit to get a better understanding of how it works ...

![Schematic](./assets/conehead_schematic.jpg?raw=true)

We basically have three oscillators comprising an RC circuit and Schmitt trigger inverter. These contribute three components to the "chirp":

* low-frequency on/off gate
* audible frequency carrier
* modulation frequency to add "texture"

This is not pure FM synthesis, as the carrier and modulation circuits do interact.
Boldport made this simulation of the circuit:

[![falstad_simulation](./assets/falstad_simulation.png?raw=true)](http://www.falstad.com/circuit/circuitjs.html?cct=$+1+0.000015625+40.34287934927352+50+5+50%0A182+176+208+256+208+0+0.5+1.66+3.33%0Aw+176+144+176+208+0%0Ar+176+144+304+144+0+1000%0Ac+176+208+176+288+0+0.00009999999999999999+2.5761190439520147%0Ag+176+288+176+320+0%0AI+256+208+304+208+0+0.5+5%0Aw+304+208+304+144+0%0Aw+496+208+496+144+0%0AI+448+208+496+208+0+0.5+5%0Ag+368+288+368+320+0%0Ac+368+208+368+288+0+0.000009999999999999999+4.455932268830388%0Ar+368+144+496+144+0+1000%0Aw+368+144+368+208+0%0A182+368+208+448+208+0+0.5+1.66+3.33%0Ar+176+144+176+64+0+1000%0Aw+368+64+368+144+0%0Aw+368+64+176+64+0%0Aw+368+-80+368+-144+0%0AI+320+-80+368+-80+0+0.5+5%0Ag+240+0+240+32+0%0Ac+240+-80+240+0+0+0.00047+1.7759441355301764%0Ar+240+-144+368+-144+0+1000%0Aw+240+-144+240+-80+0%0A182+240+-80+320+-80+0+0.5+1.66+3.33%0Ad+368+-80+368+64+1+0.805904783%0Ao+16+64+0+4098+10+0.003125+0+2+16+3%0Ao+7+64+0+4098+5+0.0125+1+2+7+3%0Ao+10+64+0+4098+10+0.0125+2+2+10+3%0A)


## Pure Data Chirp Model

Boldport projects never fail to inspire some new learning. In the case it introduced me to
[Pure Data](https://puredata.info/) - a pretty amazing open source visual programming language for multimedia.

I reproduced the [chirp.pd](./chirp.pd) model and added a few more controls to make it easier to play around with.
Here's a quick example of the sounds produced with different settings:

[![clip](https://img.youtube.com/vi/-YGf8M41W-s/0.jpg)](https://www.youtube.com/watch?v=-YGf8M41W-s)

Here are some settings that simulate the Conehead chirp:

* 428 gate frequency
* 8000 carrier frequency
* 110 modulation frequency
* 714 modulation amount

![pd_chirp_model](./assets/pd_chirp_model.png?raw=true)

## The Build

![conehead_build_left](./assets/conehead_build_left.jpg?raw=true)

![conehead_build_right](./assets/conehead_build_right.jpg?raw=true)

![conehead_build_detail](./assets/conehead_build_detail.jpg?raw=true)

![Build](./assets/conehead_build.jpg?raw=true)

## Credits and References

* [Conocephalus (wikipedia)](https://en.wikipedia.org/wiki/Conocephalus)  - a genus of bush-crickets, known as coneheads
* [Conehead](https://www.boldport.com/products/conehead) - Boldport product information
* [Conehead](https://www.boldport.club/shop/product/1432915792) - in the Boldport shop
* [Conehead](https://github.com/boldport/conehead) - OSH files on GitHub
* [74HC14 Datasheet](https://www.futurlec.com/74HC/74HC14SMD.shtml)
* [Pure Data](https://puredata.info/) - used for simulating the sound synthesis
* [..as mentioned on my blog](https://blog.tardate.com/2018/08/leap409-boldport-bugs-conehead.html)
