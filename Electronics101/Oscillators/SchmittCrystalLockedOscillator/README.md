# #656 Crystal-Locked Schmitt Oscillator

Testing a basic crystal-locked Schmitt oscillator using a 74HC14.

![Build](./assets/SchmittCrystalLockedOscillator_build.jpg?raw=true)

## Notes

I tested the basic SchmittOscillator a very long time ago in [LEAP#022](../SchmittOscillator).
I was prompted to try the crystal-locked variation after seeing CD40106 aka 74C14 covered in IMSAI Guy's chip of the day:

[![clip](https://img.youtube.com/vi/FExN8ZaufCI/0.jpg)](https://www.youtube.com/watch?v=FExN8ZaufCI)

### Circuit Design

the slowest crystal I have to hand is 4MHz, so I needed to add 20pF stabilization capacitors to maintain oscilation.
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
