# #436 Vivian

A BEAM Vibrobot using a classic solar-powered FLED circuit enhanced with a QX5252/YX805 solar LED driver.

![Build](./assets/Vivian_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/KKEdPk3T3Iw/0.jpg)](https://www.youtube.com/watch?v=KKEdPk3T3Iw)

## Notes

A solar-powered vibrobot is one of the more common BEAM designs: essentially using a photovoltaic cell
as a power source, periodically spinning a vibrating motor (usually scavenged from a mobile phone).
The motor jiggles the contraption, moving itself around a surface.

I've called my build **Vivian**, and it uses a classic FLED-based driver circuit,
but I've added a joule thief IC to squeeze a bit more efficiency from the solar panel.

It features two flashing LED (FLED) "eyes", and a vibrating motor from an old Nokia phone.
In BEAM terminology, I guess this would be considered a Vibrobot Jumper.

NB: see also the [BEAM](../) project page where I've collected much of the BEAM-related research I've done.

### FLED Driver Circuit

[FLED-based solar engines](http://solarbotics.net/library/circuits/se_t1_fled.html) are a popular
technique for driving a motor from a low-power photovoltaic source.

The flashing LED provides the oscillation necessary to allow a capacitor bank to charge to a level
that is able to drive the motor.

Alternatives to the FLED circuit include those that use zener diodes or the 1381 voltage detector IC.

Vivian uses the basic FLED circuit. I have not shielded the FLEDs (they are photo-sensitive),
since with the horizontal arrangement incident light affecting the FLED performance does not appear to be a major issue.

### Solar LED Driver

Most designs power the FLED circuit directly from a photovoltaic cell.
Since I wanted to use the smallest cell possible in the build, I wanted to get the best efficiency from it.

The 30.5x58.5 cell I have is not particularly impressive in terms of voltage and power output, so it needed a little help.

I have some interesting QX5252 "solar LED driver" ICs in a TO-94 package (YX805 is a common equivalent product).
These are designed to drive solar-powered lights:

* incorporate a switching circuit for voltage boost from 0.9-1.5V to the 2-3V required to drive an LED (similar to a joule thief circuit)
* accommodate a solor cell and rechargeable battery
* have some over-discharge protection

For the Vivian circuit, I'm using the chip in a slightly unorthodox way:
the solar cell is connected in place of the rechargeable battery (there is no rechargeable battery),
and takes advantage of the switching boost converter.
The output of the boost converter is fed to the capacitor bank via a 1N5711 (low voltage drop) diode to prevent discharge via the converter.

Here's a scope trace of the performance using a 330µH inductor. The effectiveness of the boost circuit is quite apparent.

* CH1 (Yellow) - voltage at LX (output from the boost converter)
* CH2 (Blue) - solar cell input voltage
* CH3 (Red) - voltage on the capacitor bank

![scope_330uH](./assets/scope_330uH.gif?raw=true)

There is quite a bit of useless oscillation, which can be dampened by switching up to a 2.2mH inductor (as used in the final build).
In this trace:

* CH1 (Yellow) - voltage at LX (output from the boost converter)
* CH2 (Blue) - voltage on the capacitor bank

![scope_2200uH](./assets/scope_2200uH.gif?raw=true)


### Defeating the Over-discharge Protection

I noticed a strange behaviour after a solar cell voltage drop-out (like when moving from heavy shade to the light):
the boost circuit oscillation would not restart.

I suspect this is the chip's over-discharge protection kicking in, but have yet to find an elegant way to defeat it.
What does work to restart the boost circuit:

* disconnect and re-connect the solar cell, or
* temporarily short the solar cell

I have a small wire protruding from the side of Vivian - this is the "reset switch".
It is connected to ground, and a light touch will short the solar cell causing the boost circuit to restart.


## Breadboard Construction

First, figuring out how to combine the FELD and QX5252 boost circuits on a breadboard..

![Breadboard](./assets/Vivian_bb.jpg?raw=true)

![Schematic](./assets/Vivian_schematic.jpg?raw=true)

![Vivian_bb_build](./assets/Vivian_bb_build.jpg?raw=true)


### Parts

| Item    | Description                                             | Source |
|---------|---------------------------------------------------------|--------|
| IC1     | QX5252 (or YX805)                                       | [aliexpress](https://www.aliexpress.com/item/50pcs-lot-New-QX5252F-QX5252-5252F-TO-94-LED-driver-chip/32774035651.html) |
| PVC1    | 2V 0.18W 90mAh Polycrystalline solar panel 30.5 x 58.5  | |
| M1      | 74F1 V1.3 DC vibration motor                            | from an old Nokia mobile phone |
| D1      | 1N5711                                                  | |
| L1      | 2.2mH power inductor                                    | |
| C1-3    | 3300µF 6.3V electrolytic capacitor                      | |
| R1      | 2.2kΩ 1/4W resistor                                     | |
| Q1      | 2N3906 PNP transistor                                   | |
| Q2      | 2N3904 NPN transistor                                   | |
| FLED1,2 | 5mm Red LED slow flash                                  | [aliexpress](https://www.aliexpress.com/item/100pcs-5mm-Red-Light-Emitting-Diode-Automatic-Flashing-LED-Flash-Control-Blinking-5-mm-Blink-LED/32751061551.html) |


## Real Dead Bug Construction

Now for the fun part - some real "dead bug" construction. I started with only a general idea of the layout
and fine-tuned this while building the main circuit elements:

* QX5252 and inductor power circuit mounted directly on the solar cell terminals
* surrounded by a radial capacitor bank
* linked to the head/brain - the FLED circuit and motor


The main aspect not particularly obvious from the pictures is the arrangement of the FLED circuit - here's my working sketch for how that is all connected:

![fled_circuit_layout](./assets/fled_circuit_layout.jpg?raw=true)

![build_1](./assets/build_1.jpg?raw=true)

![build_2](./assets/build_2.jpg?raw=true)

![build_3](./assets/build_3.jpg?raw=true)

![build_4](./assets/build_4.jpg?raw=true)


## Conclusion

This worked out quite well. I was concerned that my super-cheap solar cell was not going to be up to the job
but with the QX5252 boost it performs quite well:

* even quite low-light conditions (like an overcast day) are enough to get the "eyes" to flash
* and a little indirect sunshine (such as indoors when the sun is out) will start to trigger the motor


## Credits and References
* [FLED-based solar engines](http://solarbotics.net/library/circuits/se_t1_fled.html)
* [QX5252 product info](http://www.qxmd.com.cn/en/?product/QX5252.html)
* [1N5711 datasheet](https://www.futurlec.com/Diodes/1N5711.shtml)
* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml)
* [2N3906 datasheet](https://www.futurlec.com/Transistors/2N3906.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2018/11/leap436-vivian-the-vibrating-beam-bot.html)
