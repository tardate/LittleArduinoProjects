# #181 VoltmeterModule

Test a 3-wire voltmeter module


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I obtained a 3-wire voltmeter module as part of a kit, so a chance to test one out!

![front](./assets/VoltmeterModule_front.jpg?raw=true)
![rear](./assets/VoltmeterModule_rear.jpg?raw=true)

There are two and three wire modules in the market.

Two-wire modules are the simplest (and generally cheapest).
For most applications where a simple readout of a power supply is required, they are most convenient
since a separate power supply connection is not required. It does mean of course that the meter
draws current from the circuit under test, and will only work down to a certain voltage (usually ~4.5V).

For more precision measurement, the three-wire
modules are better suited:
* they present relatively high input impedance (> 100kΩ)
* can measure voltages from 0V and up

I can't find a specific datasheet for the 3-wire module, but from product listings,
the specifications are as follows:

* Measuring range: 0~30V;
* Power supply: DC 4.5~30V;
* Max. input: DC 30V;
* Tolerance: +/-1%, +/-0.3V (>=10V), +/0.1 (<10V);
* Input impedance: >100Kohm;
* Working current: red: <23mA;
* Refresh rate: 300ms;
* Display: 3-digit 0.36" LED;
* Display color: red;
* Cable length: 15cm

These modules do not have any kind of digital output that could be used to integrate with a microprocessor,
but as a stand-alone meter, a useful device for power supply circuits.

## Test Circuit

Schematics below are for a simple test of the meter using a 10kΩ pot to vary the input voltage and compare the reading with a multimeter.

Using my DMM as a reference, it appears accuracy is within 40mV, good enough for general purposes.

## Construction

NB: the Fritzing part used here is not quite right (it's actually a 4-wire ammeter) but does well enough for a simple schematic:

![Breadboard](./assets/VoltmeterModule_bb.jpg?raw=true)

![The Schematic](./assets/VoltmeterModule_schematic.jpg?raw=true)

![The Build](./assets/VoltmeterModule_build.jpg?raw=true)

## Credits and References
* [DSN-DVM-368L-3 3-Digit 0.36" LED Digital DC Voltmeter](http://www.dx.com/p/dsn-dvm-368l-3-3-digit-0-36-led-digital-dc-voltmeter-for-motorcycle-black-white-343750#.VrVc01N97XE) - example product listing on dx.com
* [Mini DC 0-100V Yellow LED 3-Digital Display Voltage Voltmeter](https://www.aliexpress.com/item/Mini-DC-0-100V-Yellow-LED-3-Digital-Display-Voltage-Voltmeter-0-28/32276796281.html) - example product listing on aliexpress
* [..as mentioned on my blog](https://blog.tardate.com/2016/02/littlearduinoprojects181-voltmeter.html)
