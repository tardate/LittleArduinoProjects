# #152 LD1117 Regulator

Test an LD1117 3.3V linear regulator

![The Build](./assets/LD1117_build.jpg?raw=true)

## Notes

The LD1117 is a low drop fixed and adjustable voltage regulator, available from a number of manufacturers including UTC and ST.
Parts are available for a range of output voltages, including: 1.2V, 1.5V, 1.8V, 2.5V, 2.85V, 3.0V, 3.3V, 3.6V, 5.0V, and ADJ.

The component I have is marked: UTC LD1117AL 33D010HT5

Although I can't find a datasheet that matches these markings exactly, I figure:

* A = 1A
* L = lead free
* 33 = 3.3V
* D? = pin out is (from left front): Vin, Ground, Vout

Note that the LD1117A by ST has a different pin configuration for the TO220 package.
From pin 1 left front: Ground, Vout, Vin.

Some DMM measurements, with a 10kΩ output load:

| Vin   | Iin    | Vout  | Iout  | Pin:Pout        |
|-------|--------|-------|-------|-----------------|
| 5.10V | 2.47mA | 3.30V | 329µA | 12.6mW : 1.09mW |

The inefficiency of a linear regulator is clear to see - we're dissipating 11.51mW in the 1117, far more power than is actually delivered to the load.
But they're convenient!

## Construction

![Breadboard](./assets/LD1117_bb.jpg?raw=true)

![The Schematic](./assets/LD1117_schematic.jpg?raw=true)

![The Build](./assets/LD1117_build.jpg?raw=true)

## Credits and References

* [LD1117 datasheet](http://pdf1.alldatasheet.com/datasheet-pdf/view/173710/UTC/LD1117AL-15-TA3-A-R.html)
* [Linear Regulator](https://en.wikipedia.org/wiki/Linear_regulator) - wikipedia
