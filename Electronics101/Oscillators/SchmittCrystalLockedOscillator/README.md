# #612 Crystal-Locked Schmitt Oscillator

Testing a basic crystal-locked Schmitt oscillator using a 74HC14.

![Build](./assets/SchmittCrystalLockedOscillator_build.jpg?raw=true)

## Notes

I tested the basic Schmitt Oscillator a very long time ago in [LEAP#022](../SchmittOscillator).
I was prompted to try the crystal-locked variation after seeing CD40106 aka 74C14 covered in IMSAI Guy's chip of the day:

[![clip](https://img.youtube.com/vi/FExN8ZaufCI/0.jpg)](https://www.youtube.com/watch?v=FExN8ZaufCI)

Oscillators of this topology are variously known as
[Pierce Oscillators](https://en.wikipedia.org/wiki/Pierce_oscillator),
[Pierce-Gate Crystal Oscillators ](https://www.mpdigest.com/2018/04/23/pierce-gate-crystal-oscillator-a-revisit/)
or [CMOS Crystal Oscillators](https://www.electronics-tutorials.ws/oscillator/crystal.html).

An alternative design using NOR Gates:

[![clip](https://img.youtube.com/vi/2Dg_GYXs4Ss/0.jpg)](https://www.youtube.com/watch?v=2Dg_GYXs4Ss)

### Circuit Design

The slowest crystal I have to hand is 4MHz, so I needed to add 20pF stabilization capacitors to maintain oscilation.
The second inverter buffers the output and the 51kΩ feedback resistor ensure's the oscillator is kicked into action.

![bb](./assets/SchmittCrystalLockedOscillator_bb.jpg?raw=true)

![schematic](./assets/SchmittCrystalLockedOscillator_schematic.jpg?raw=true)

![Build](./assets/SchmittCrystalLockedOscillator_build.jpg?raw=true)

### Test Results

4.00019MHz according to my scope:

![scope](./assets/scope.gif?raw=true)

## Credits and References

* [74HC14 Datasheet](https://www.futurlec.com/74HC/74HC14.shtml)
* [LEAP#022](../SchmittOscillator)
* [Pierce-Gate Crystal Oscillator, a Revisit](https://www.mpdigest.com/2018/04/23/pierce-gate-crystal-oscillator-a-revisit/)
* [Pierce Oscillator](https://en.wikipedia.org/wiki/Pierce_oscillator) - wikipedia
* [CMOS Crystal Oscillators](https://www.electronics-tutorials.ws/oscillator/crystal.html)
* [IMSAI Guy #1254 CD40106 aka 74C14](https://www.youtube.com/watch?v=FExN8ZaufCI)
* [NOR Gate Pierce Crystal Oscillator](https://www.youtube.com/watch?v=2Dg_GYXs4Ss)
