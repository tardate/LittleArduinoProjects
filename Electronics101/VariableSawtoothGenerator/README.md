# #163 VariableSawtoothGenerator

Test a variable-geometry, fixed-amplitude sawtooth wave generator circuit


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This is an interesting sawtooth wave generator that's described in an excellent [w2aew tutorial](https://youtu.be/ibnz5UjQ4u0).

It uses two independently-controlled BJT current sources to sequentially charge and discharge a capacitor -
generating the rising and falling slopes of the wave.

A comparator with hysteresis is used to switch the current sources.

### Components and Limitations

I'm using an LM324 op-amp for the comparator and buffer circuits. This is just borderline acceptable,
since it is not rail-to-rail and so the resulting votage differential in the hysteresis cycle is only about 1V.
It also seems to be contributing some degree of crossover distortion.

1N4148 diodes are recommended, but I did try replacing them all with standard 1N4007 rectifers.
While the circuit still functioned, with 1N4007 diodes there was more distortion of the waveform - I think primarily because of the lower switching speed.

### Results - LM324

The following trace is with a 5V supply. It's a bit hard to read because I crammed 4 measurements in one.
The inputs are all DC coupled with no offset to the centre 0V line.
 comparator output swings from ~0.7V to ~3.7V (showing how far from rail-rail the LM324 is!)
*

![5v trace LM324](./assets/VariableSawtoothGenerator_scope_LM324_5v.gif?raw=true)

| Channel | Colour | Probe Point | Measurement                              |
|---------|--------|-------------|------------------------------------------|
| CH1     | yellow | SAWOUT      | saw output                               |
| CH2     | blue   | SQUAREOUT   | comparator output / left of diode bridge, swinging from ~0.7V to ~3.7V |
| CH3     | red    | P3          | charging current source                  |
| CH4     | green  | P4          | comparator voltage threshold             |

## LF347N

Replacing the LM324 with LF347N, circuit loses dynamic range but still produced a relatively undistorted wave.

![5v trace LF347N](./assets/VariableSawtoothGenerator_scope_LF347N_5v.gif?raw=true)

## TL074CN

Replacing the LM324 with TL074CN, circuit loses some dynamic range and has significant crossover distortion.

![5v trace TL074CN](./assets/VariableSawtoothGenerator_scope_TL074CN_5v.gif?raw=true)

## Construction

![Breadboard](./assets/VariableSawtoothGenerator_bb.jpg?raw=true)

![The Schematic](./assets/VariableSawtoothGenerator_schematic.jpg?raw=true)

![The Build](./assets/VariableSawtoothGenerator_build.jpg?raw=true)

## Credits and References
* [#104: Circuit tutorial: sawtooth generator w/ current sources, diode switches, hysteresis comparator](https://youtu.be/ibnz5UjQ4u0) - w2aew
* [Transistor current source with diode compensation](https://en.wikipedia.org/wiki/Current_source) - wikipedia
* [Comparator Hysteresis](https://en.wikipedia.org/wiki/Comparator#Hysteresis) - wikipedia
* [LM324N Datasheet](https://www.futurlec.com/Linear/LM324N.shtml)
* [LF347N datasheet](https://www.futurlec.com/Linear/LF347N.shtml)
* [TL074CN datasheet](https://www.futurlec.com/Linear/TL074CN.shtml)
