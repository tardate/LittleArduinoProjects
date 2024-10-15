# #181 DC Voltmeter Modules

Testing a selection of 3-wire DC voltmeter modules.

![VoltmeterModule_build](./assets/VoltmeterModule_build.jpg)

## Notes

There are two and three wire DC voltmeter modules in the market.

Two-wire modules are the simplest (and generally cheapest).
For most applications where a simple readout of a power supply is required, they are most convenient
since a separate power supply connection is not required. It does mean of course that the meter
draws current from the circuit under test, and will only work down to a certain voltage (usually ~4.5V).

For more precision measurement, the three-wire
modules are better suited:

* they present relatively high input impedance (> 100kΩ)
* can measure voltages from 0V and up

Modules tested below:

* Module 1: DSN-DVM-368 v3.01. Screw mounted with no bezel, measures from 0-30V
* Module 2:

## Test Circuit

Schematics below are for a simple test of the meter using a 10kΩ pot to vary the input voltage and compare the reading with a multimeter.

NB: the Fritzing part used here is not quite right (it's actually a 4-wire ammeter) but does well enough for a simple schematic:

![Breadboard](./assets/VoltmeterModule_bb.jpg?raw=true)

![The Schematic](./assets/VoltmeterModule_schematic.jpg?raw=true)

### Module 1: DSN-DVM-368 v3.01

This is a common type of module that is screw mounted with no bezel and can measure from 0-30V.

I think I originally obtained this module as part of a kit, but they are widely available from parts sellers:

* [DSN-DVM-368L-3 3-Digit 0.36" LED Digital DC Voltmeter](http://www.dx.com/p/dsn-dvm-368l-3-3-digit-0-36-led-digital-dc-voltmeter-for-motorcycle-black-white-343750#.VrVc01N97XE) - example product listing on dx.com
* [Mini DC 0-100V Yellow LED 3-Digital Display Voltage Voltmeter](https://www.aliexpress.com/item/Mini-DC-0-100V-Yellow-LED-3-Digital-Display-Voltage-Voltmeter-0-28/32276796281.html) - example product listing on aliexpress

![front](./assets/module01_front.jpg?raw=true)
![rear](./assets/module01_rear.jpg?raw=true)

I can't find a specific datasheet for the module, but from product listings,
the specifications are as follows:

* Measuring range: 0~30V;
* Power supply: DC 4.5~30V;
* Max. input: DC 30V;
* Tolerance: +/-1%, +/-0.3V (>=10V), +/0.1 (<10V);
* Input impedance: >100KΩ;
* Working current: red: <23mA;
* Refresh rate: 300ms;
* Display: 3-digit 0.36" LED;
* Display color: red;
* Cable length: 15cm

These modules do not have any kind of digital output that could be used to integrate with a microprocessor,
but as a stand-alone meter, a useful device for power supply circuits.

Using my DMM as a reference, it appears accuracy is within 40mV, good enough for general purposes.

![module01_test](./assets/module01_test.jpg?raw=true)

### Module 2: 0.56" Panel Meter

This is a common panel mount module with 0.56" digits and can measure from 0-100V.
Other versions are available with different measurement ranges: 0-10V, 0-30V, 0-200V.

They are widely available from parts sellers, e.g.:

* [0.56" 3 Wire Digital LED Voltmeter Voltage Meter Panel with Reverse Protection DC0-100V (Red)](https://www.aliexpress.com/item/1005007129264878.html) - aliexpress

![module02](./assets/module02.jpg)

I can't find a specific datasheet for the module, but from product listings,
the specifications are as follows:

* Test voltage range: DC 0-100V
* Accuracy: 1%
* Display: 3 digits LED
* Working temperature: - 10 ~ + 65℃
* Measurement rate: 200mS/time
* Power: DC 3-30V
* Max. output: DC 100V (above 100V carries a risk of burning)
* Min. output: DC 0V (Below 0V, measurement inaccurate or not shown)
* Current consumption: <20mA
* LED color: Red/Blue/Green/Yellow (Optional)
* Weight: Approx.17g/0.6oz
* Size: Approx.4.8*2.9*1.9cm

Tests reasonably accurate:

![module02_test](./assets/module02_test.jpg)

## Credits and References

* [..as mentioned on my blog](https://blog.tardate.com/2016/02/littlearduinoprojects181-voltmeter.html)
