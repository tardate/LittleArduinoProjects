# #542 PLL Ramp Generator

A simple CD4046 ramp generator circuit from a design by M.S. Nagaraj published in Elektor 7/1994.

![Build](./assets/RampGenerator_build.jpg?raw=true)

## Notes

The VCO in the DC4046 normally produces a triangular signal, but this circuit arrangement
generates a saw. The original circuit was by M.S. Nagaraj and
published in [Elektor Magazine 7/1994](https://www.elektormagazine.com/magazine/elektor-199407/33146/).

The saw tooth is achieved by significantly off-setting the rise and fall times of the VCO
by using C1a  capacitor value much greater than the C1b capacitor.
The capacitor(s) on C1a and C1b set the VCO frequency.

So - not a perfect saw tooth, but very close.

In the circuit I test here, C1a = 1nF, and C1b = 10pF, so a resulting frequency difference of 100:1.

## Constructionlished

![Breadboard](./assets/RampGenerator_bb.jpg?raw=true)

![Schematic](./assets/RampGenerator_schematic.jpg?raw=true)

![RampGenerator_bb_build](./assets/RampGenerator_bb_build.jpg?raw=true)

## Performance

With VR1 adjusted for minimum freuqency of ~3.5kHz:

![scope_min](./assets/scope_min.gif?raw=true)

With VR1 adjusted for maximum freuqency of ~128.9kHz:

![scope_max](./assets/scope_max.gif?raw=true)

## Credits and References

* [CD4046 Datasheet](https://www.futurlec.com/4000Series/CD4046.shtml)
* [PLL-controlled ramp generator](https://www.elektormagazine.com/magazine/elektor-199407/33146/) - published in Elektor Magazine 7/1994, page 102
