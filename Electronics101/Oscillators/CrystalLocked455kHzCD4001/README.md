# #624 Crystal-locked 455kHz Oscillator

Testing a 455kHz crystal-locked Pierce oscillator using CD4001 CMOS NOR gates.

![Build](./assets/CrystalLocked455kHzCD4001_build.jpg?raw=true)

## Notes

This circuit is a variation on the theme from
[LEAP#656 Crystal-Locked Schmitt Oscillator](../SchmittCrystalLockedOscillator)
using NOR gates and a 4MHz crystal.

### Circuit Design

Key design notes:

* Instead of simple inverters, the design uses NOR gates from a CD4001 chip. The NOR gate may either be wired:
    * both inputs tied together, so the output is always the inverse of the input
    * one input tied to ground, so the output is always the inverse of the other input
* With a 455kHHz crystal, relatively large stabilization capacitors are required to maintain oscilation (in this case >=300pF). The mis-matched stabilization capacitors help ensure oscillation starts.
* A feedback resistor is not essential and has been left out as the frequency is relatively low.

![bb](./assets/CrystalLocked455kHzCD4001_bb.jpg?raw=true)

![schematic](./assets/CrystalLocked455kHzCD4001_schematic.jpg?raw=true)

![bb_build](./assets/CrystalLocked455kHzCD4001_bb_build.jpg?raw=true)

### Test Results

Measuring 452.3kHz, with scope connections as follows:

* CH1 Yellow: buffered oscillator output
* CH2 Blue: oscillator output

At this frequency, the buffered output is a nice square wave.

![scope](./assets/scope.gif?raw=true)

## Credits and References

* [LEAP#656 Crystal-Locked Schmitt Oscillator](../SchmittCrystalLockedOscillator)
* [CD4001 datasheet](https://www.futurlec.com/4000Series/CD4001.shtml)
* [Pierce-Gate Crystal Oscillator, a Revisit](https://www.mpdigest.com/2018/04/23/pierce-gate-crystal-oscillator-a-revisit/)
* [Pierce Oscillator](https://en.wikipedia.org/wiki/Pierce_oscillator) - wikipedia
