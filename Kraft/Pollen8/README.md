# #441 Pollen8

Pollen8 is a freeform wire sculpture with LEDs driven by a light-sensitive 555/4017 counter circuit.

![Build](./assets/Pollen8_build.jpg?raw=true)

Here's a quick demo..

[![clip](./assets/Pollen8_build.gif?raw=true)](https://www.youtube.com/watch?v=VEAgmHIxWKI)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

"Pollen8" is an exploration of contrasts and patterns in a freeform wire circuit.

I was interest in playing with a design that avoided the harsh angularity of most electronic circuits,
instead using graceful lines that attempt to mimic a more organic structure.

The second goal was to achieve a chameleon-like LED display, where the visual effect depends on the
perspective of the viewer: random from some angles, but clearly sequenced from others.

I created this for the [Hackaday Circuit Sculpture Contest](https://hackaday.io/contest/162559-circuit-sculpture-contest).


## The Main Frame

The skeleton is made with 0.9mm and 0.55mm copper wire. The idea started as a very rough sketch in a notebook,
and improvised in 3D by eye.

![build_bare_structure](./assets/build_bare_structure.jpg?raw=true)


## The Beating Heart

At first I was thinking of embedding a microprocessor in the project, but eventually decided to keep it old school with
a classic 555 timer and CD4017 decade counter combo.

I was thinking along the lines of crafting and electronic "stamen" for the plant.
Building this itself became a pleasurable little side-project.

![build_timer_unit](./assets/build_timer_unit.jpg?raw=true)

![build_counter_unit](./assets/build_counter_unit.jpg?raw=true)

I liked the look of the "counter unit" so much, I went off on a little tangent for testing purposes.
You can probably tell I was thinking it looked like some kind of sci-fi planetary sensing outpost..

![counter_tower_tengent](./assets/counter_tower_tengent.jpg?raw=true)

## Base

The base is made from some copper PCB stock and 3 cork coasters.
It includes a CR2032 coin cell holder, switch and some external power connector pins.

![build_base_1](./assets/build_base_1.jpg?raw=true)

Middle cork coaster has a cut-out for the wiring:

![build_base_2](./assets/build_base_2.jpg?raw=true)

![build_base_3](./assets/build_base_3.jpg?raw=true)

The finished base:

![build_base_4](./assets/build_base_4.jpg?raw=true)


## Circuit Construction

A very simple variation of the classic CD4017 counter with a 555 astable clock course.
A light-dependent resistor provides some frequency variation depending on available light.
The LDR ranges from around 1kΩ when in light to 10kΩ when in darkness, corresponding to a clock frequency range of
perhaps [6.5Hz](https://visual555.tardate.com/?mode=astable&r1=2.2&r2=10&c=10) to [34Hz](https://visual555.tardate.com/?mode=astable&r1=2.2&r2=1&c=10).

The two CD4017 counters are wired in parallel - mainly for symmetry in the final design.
Up to 5 LEDs are chained from each counter output (not all pins are actually used in my final build).

![Breadboard](./assets/Pollen8_bb.jpg?raw=true)

![Schematic](./assets/Pollen8_schematic.jpg?raw=true)

![Pollen8_bb_build](./assets/Pollen8_bb_build.jpg?raw=true)


## Parts

The main electronic components:

| Item | Description                                |
|------|--------------------------------------------|
| U1   | 555 Timer                                  |
| U2,3 | CD4017 decade counter                      |
| C1   | 10µF electolytic capacitor                 |
| R1   | 2.2kΩ                                      |
| R2   | 10kΩ LDR                                   |
|      | ~ 25 yellow 0805 LEDs                      |
|      | ~ 35 red 0805 LEDs                         |
|      | lots of 0805 220Ω resistors - for each LED |


## Putting it all Together

The circuit works nicely on a 3.3V coin cell, but can also take power fromthe two pins at the rear.
It's quite efficient (seems to draw < 5mA at peak), but I've been conservative with the LED current-limiting resistors -
they are not driven very hard.

![Build](./assets/Pollen8_build.gif?raw=true)


## Credits and References
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [CD4017 datasheet](http://www.futurlec.com/4000Series/CD4017.shtml)
* [Hackaday Circuit Sculpture Contest](https://hackaday.io/contest/162559-circuit-sculpture-contest)
* [..as mentioned on my blog](https://blog.tardate.com/2018/12/leap441-pollen8.html)
