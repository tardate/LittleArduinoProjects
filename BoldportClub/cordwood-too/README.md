# #321 cordwood-too

The Cordwood Puzzle returns! Boldport Club Project #13, May 2017

![Build](./assets/cordwood-too_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The original [Cordwood Puzzle](../cordwood) became an instant classic with club members, and the concept returns this year with a brand new puzzle.
The cordwoods evoke an era of stuffing massive components into small spaces. This is real hardware!

As before, it really is a puzzle, so if you don't want any spoilers - read no further.

---

## Unboxing and Parts Count

![kit1](./assets/kit1.jpg?raw=true)

| Ref                  | Part                                         | Qty |
|----------------------|----------------------------------------------|-----|
| R2,4,6,8,10,12,14,16 | 10KΩ 2W resistor, Multicomp MCMF02WJJ103A10  |  8  |
| R1,3,5,7,9,11,13,15  | 220Ω 2W resistor, Multicomp MCF 2W 220R      |  8  |
| C1                   | 1uF ceramic capacitor, AVX SA305E105MAR      |  1  |
| Q1-8                 | n-channel MOSFET transistor, Fairchild 2N7000|  8  |
|                      | 10-pin through-hole header, Multicomp MC34739|  1  |
|                      | 10mm yellow LED, Kingbright L-813YD          |  4  |
|                      | 10mm green LED, Kingbright L-813GD           |  4  |
|                      | 25mm M3 standoff, ETTINGER 05.03.251         |  1  |
|                      | M3 screws                                    |  2  |
|                      | PCBs                                         |  2  |
|                      | Piece of 0.84mm diameter 20AWG hookup wire   |  1  |

![kit2](./assets/kit2.jpg?raw=true)

## Power

The LEDs are rated for 20 mA with forward voltage of 2.V (yellow) and 2.2V (green).
Therefore, with the current-limiting resistor of 220Ω, the maximum supply voltage is around
[6.5V](http://www.wolframalpha.com/input/?i=2.1V+%2B+20mA+*+220%CE%A9).

## How It Works

Each LED is switched by a corresponding MOSFET.
The MOSFET gate is pulled high by default with a 10kΩ resistor, so the defualt LED state is ON.

Each gate is also connected to a pin. If these are pulled to ground, the corresponding LED turns off.

## Construction

![Schematic](./assets/cordwood-too_schematic.jpg?raw=true)

![Build](./assets/cordwood-too_build.jpg?raw=true)

With it's twin, the [original Cordwood](../cordwood)..

![cordwood-too_twins](./assets/cordwood-too_twins.jpg?raw=true)

## Credits and References
* [Cordwood Too](https://www.boldport.com/products/cordwood-puzzle-too/) - Boldport Product Page
* [Cordwood Too](http://community.boldport.club/projects/p13-cordwood-too/) - on the community site
* [2N7000 datasheet](http://www.futurlec.com/Transistors/2N7000.shtml)
* [10mm yellow LED, Kingbright L-813YD data](http://uk.farnell.com/1142474)
* [10mm green LED, Kingbright L-813GD data](http://uk.farnell.com/1142462)
* [LEAP#269 cordwood](../cordwood) - the original Cordwood project
