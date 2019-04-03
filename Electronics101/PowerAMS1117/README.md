# #153 PowerAMS1117

Test an AMS1117 3.3V linear regulator


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The LD1117 is a low drop fixed and adjustable voltage regulator, available from a number of manufacturers including UTC and ST.

The component I have
(obtained from [a seller on aliexpress](https://www.aliexpress.com/item/1-Set-10Pcs-Useful-3-3V-1A-AMS1117-LM1117-1117-Voltage-Regulator-SR2985-Free-Shipping/32313333110.html))
is marked: AMS1117-3.3 H1518 in a SOT-223 package.

As given in the datasheet:
* dropout voltage (Vin - Vout): 1.1V typical, 1.3V max
* Vin max: 15V
* current limit: 1.1A typical, 1.5A max
* pin out (from left front): ground, Vout, Vin

Circuit recommendations:
* 22µF tantalum output capacitor

Some DMM measurements, with a 10kΩ output load:

| Vin   | Iin    | Vout  | Iout  | Pin:Pout        |
|-------|--------|-------|-------|-----------------|
| 5.09V | 2.68mA | 3.29V | 333µA | 13.64mW : 1.1mW |

The inefficiency of a linear regulator is clear to see - we're dissipating 12.74mW in the 1117, far more power than is actually delivered to the load.
But they're convenient!

## Construction

NB: these diagrams use the [custom AMS1117 module fritzing part](../../FritzingParts/AMS1117)

![Breadboard](./assets/PowerAMS1117_bb.jpg?raw=true)

![The Schematic](./assets/PowerAMS1117_schematic.jpg?raw=true)

![The Build](./assets/PowerAMS1117_build.jpg?raw=true)

## Credits and References
* [AMS1117 datasheet](http://www.advanced-monolithic.com/pdf/ds1117.pdf)
* [Linear Regulator](https://en.wikipedia.org/wiki/Linear_regulator) - wikipedia
* [item from aliexpress seller](https://www.aliexpress.com/item/1-Set-10Pcs-Useful-3-3V-1A-AMS1117-LM1117-1117-Voltage-Regulator-SR2985-Free-Shipping/32313333110.html)
