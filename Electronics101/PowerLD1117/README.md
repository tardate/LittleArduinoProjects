# PowerLD1117

Test an LD1117 3.3V linear regulator

## Notes
The LD1117 is a low drop fixed and adjustable voltage regulator, available from a number of manufacturers including UTC and ST.

The component I have is marked: UTC LD1117AL 33D010HT5

Although I can't find a datasheet that matches these markings exactly, I figure:
* A = 1A
* L = lead free
* 33 = 3.3V
* D? = pin out is (from left front): Vin, Ground, Vout

Some measurements, with a 10kΩ output load:

| Vin   | Vout  |
|-------|-------|
| 5.10V | 3.30V |

## Construction

![Breadboard](./assets/PowerLD1117_bb.jpg?raw=true)

![The Schematic](./assets/PowerLD1117_schematic.jpg?raw=true)

![The Build](./assets/PowerLD1117_build.jpg?raw=true)

## Credits and References
* [LD1117 datahseet](http://pdf1.alldatasheet.com/datasheet-pdf/view/173710/UTC/LD1117AL-15-TA3-A-R.html)
* [Linear Regulator](https://en.wikipedia.org/wiki/Linear_regulator) - wikipedia

