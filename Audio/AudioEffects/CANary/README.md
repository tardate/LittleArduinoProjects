# #459 The CANary

Playing with a popular 74HC14 bird chirp effect by Wilf Rigter and making a CANary sculpture.

![Build](./assets/CANary_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/QLl-OWAFiy0/0.jpg)](https://www.youtube.com/watch?v=QLl-OWAFiy0)

## Notes

[Wilf's Bird](http://solarbotics.net/library/circuits/misc_sound_wilfbird.html) is a pretty famous "bird chirp" sound effect by Wilf Rigter.
I last saw it used in Kelly Heaton's wonderful [bird sculpture](https://hackaday.io/project/163201-electronic-sculpture),
a Hackaday Circuit Sculpture contest winner.

## Circuit Design

The effect is produced by the missing of a couple of Schmitt oscillators running on a 74HC14.

* the primary oscillator is modulated by an LDR
* a secondary oscillator mixes the signal for a piezo speaker

Note that the "HC" series 74HC14 Hex Inverter with Schmitt Trigger Inputs is really required.
A 74HC04 without Schmitt Trigger inputs can just about work but is hard to stabilise, and
an LS series 74LS14 will not work.

The circuit is optimised for around 3.3V supply. At higher voltages, oscillation can fail.

## Breadboard Build

A quick breadboard build to verify behaviour..

![Breadboard](./assets/CANary_bb.jpg?raw=true)

![Schematic](./assets/CANary_schematic.jpg?raw=true)

![CANary_bb_build](./assets/CANary_bb_build.jpg?raw=true)

Here's a test on the breadboard..

[![clip](https://img.youtube.com/vi/led9se_wN30/0.jpg)](https://www.youtube.com/watch?v=led9se_wN30)

## CANary build

Wiring it all up on a an old coke can, here is the CANary:

![Build](./assets/CANary_build.jpg?raw=true)

## Credits and References

* [74HC14 datasheet](https://www.futurlec.com/74HC/74HC14.shtml)
* [74HC04 datasheet](https://www.futurlec.com/74HC/74HC04.shtml)
* [74LS14 datasheet](https://www.futurlec.com/74LS/74LS14.shtml)
* [Circuit Properties of LS and HC Digital Logic](http://mysite.du.edu/~etuttle/electron/elect13.htm)
* [Wilf's Bird](http://solarbotics.net/library/circuits/misc_sound_wilfbird.html) - original schematic posted to solarbotics
* [Modified Wilf's bird sound generator](http://electro-music.com/forum/post-409778.html)
* [..as mentioned on my blog](https://blog.tardate.com/2019/03/leap460-the-canary.html)
