# #688 Crystal-locked 4MHz Oscillator

Testing a 4MHz crystal-locked Pierce oscillator using CD4001 CMOS NOR gates.

![Build](./assets/CrystalLocked4MHzCD4001_build.jpg?raw=true)

## Notes

This circuit is a variation on the theme from
[LEAP#656 Crystal-Locked Schmitt Oscillator](../SchmittCrystalLockedOscillator)
using NOR gates and a 4MHz crystal.

### Circuit Design

Key design notes:

* Instead of simple inverters, the design uses NOR gates from a CD4001 chip. The NOR gate may either be wired:
    * both inputs tied together, so the output is always the inverse of the input
    * one input tied to ground, so the output is always the inverse of the other input
* With a 4MHz crystal, so I needed to add small stabilization capacitors to maintain oscilation (in this case 30pF)
* R1 is a feedback resistor uses the gate output to ensure sufficient charge on the gate input to oscillate. Values are not critical but as a rule : the higher the frequency, the lower resistance required. 4.7MΩ works fine in this case.

![bb](./assets/CrystalLocked4MHzCD4001_bb.jpg?raw=true)

![schematic](./assets/CrystalLocked4MHzCD4001_schematic.jpg?raw=true)

![bb_build](./assets/CrystalLocked4MHzCD4001_bb_build.jpg?raw=true)

### Test Results

Measuring 3.99991MHz, with scope connections as follows:

* CH1 Yellow: buffered oscillator output
* CH2 Blue: oscillator output

At 4MHz, waveforms are far from perfect square waves. Aside from breadboard inefficiencies, this is mainly because
the oscillator is running in the region of the CD4001's max propagation delay of 250ns i.e [4MHz](https://www.wolframalpha.com/input?i=1%2F%28250ns%29)

![scope](./assets/scope.gif?raw=true)

## Credits and References

* [LEAP#656 Crystal-Locked Schmitt Oscillator](../SchmittCrystalLockedOscillator)
* [CD4001 datasheet](https://www.futurlec.com/4000Series/CD4001.shtml)
* [Pierce-Gate Crystal Oscillator, a Revisit](https://www.mpdigest.com/2018/04/23/pierce-gate-crystal-oscillator-a-revisit/)
* [Pierce Oscillator](https://en.wikipedia.org/wiki/Pierce_oscillator) - wikipedia
