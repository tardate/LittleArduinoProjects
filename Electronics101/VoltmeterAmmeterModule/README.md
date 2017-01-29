# #289 VoltmeterAmmeterModule

Test and calibrate a DC Voltmeter/Ammeter panel module.

![Build](./assets/VoltmeterAmmeterModule_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

I got [this DC 0-100V 10A Digital Voltmeter/Ammeter module](https://www.aliexpress.com/item/0-28-Red-Blue-LED-DC-0-100V-10A-Dual-display-Meter-Digital-Voltmeter-Ammeter-Panel/32310008404.html) from a seller on aliexpress at a nice price. But is it any good?

This project is a quick test of the unit.

### Specifications

* Display color: Red (voltage) & Blue (current) LED dual display.
* Display: 0.28" LED digital.
* Operating voltage: DC 4.5 ~ 30V (for power supply to the module)
* Operating Current: <20mA.
* Measure voltage: DC 0 ~ 100V.
* Minimum resolution (V): 0.1V.
* Measure current: 10A (direct measurement, built-in shunt).
* Minimum resolution (A): 0.01A.
* Measure accuracy: 1% (± 1 digit).
* Refresh rate: ≥500ms / times.
* Operating temperature: -10 to 65°c.
* Operating Humidity: 10 to 80% (non-condensing).
* Size: 48mm x 29mm x 21mm.
* Mounting cutout: 45.5mm x 26.5mm.

Here is the module, fromt and rear. Unfortunately it is not possible to determine what kind
of processor is used, as the main IC has no markings

![module_front](./assets/module_front.jpg?raw=true)

![module_rear](./assets/module_rear.jpg?raw=true)

### Module Power Supply

The module takes a separate power supply to drive the unit and LED display. This is good,
as it avoids confounding measurements of the circuit being monitored with the units own pwer requirements,
and allows voltage measurement below the minimum 4.5V required to power the unit.

It's important to note two things however:

1. the module power supply shares a common ground with the circuit under test, so care is required with the arrangement of external circuitry to avoid a ground short

2. the 2-pin JST power connector has the opposite polarity from what is commonly seen in JST power conenctions.
There is no actual standard, so this is not a problem per se, and the supplied connector lead is correctly colour coded.
But if other power connectors are used, it is important to double-check polarity


### External Circuit Wiring

Connecting the module in-circuit simpley requires:

* parallel connection to the positive voltage supply (red wire)
* series connection on the low-side of the load to ground (blue, black wires)

![VoltmeterAmmeterModule_connections](./assets/VoltmeterAmmeterModule_connections.png?raw=true)


## Test Load

To run some tests, and in the absence of anything better, I mocked up a dummy load:

* 12V, 1.5A, 18W DC power supply
* an arrangement of parallel 50Ω 5W resistors. I connected between 1 and 5 of these for different static resistive loads.
* I powered the module from a separate 9V battery

![load_layout](./assets/load_layout.jpg?raw=true)

### Initial Test Results

It works nice enough, but is not quite as accurate as the claimed 1% (± 1 digit) resolution (i.e. the last digit can be off by one).
The unit is obviously not suitable if you need accurate mV and mA readings.


| Load      | Nom Voltage | Nom Current                                                    | Nom Power | Measured Voltage | Measured Current |
|-----------|-------------|----------------------------------------------------------------|-----------|------------------|------------------|
|   50Ω (1) |         12V | [240mA](http://www.wolframalpha.com/input/?i=12V%2F50%CE%A9)   |     2.88W |              n/a |            n/a   |
|   25Ω (2) |         12V | [480mA](http://www.wolframalpha.com/input/?i=12V%2F25%CE%A9)   |     5.76W |              n/a |            n/a   |
| 16.7Ω (3) |         12V | [719mA](http://www.wolframalpha.com/input/?i=12V%2F16.7%CE%A9) |     8.62W |            12.5V |          0.69A   |
| 12.5Ω (4) |         12V | [960mA](http://www.wolframalpha.com/input/?i=12V%2F12.5%CE%A9) |    11.52W |            12.5V |          0.93A   |
|   10Ω (5) |         12V | [1.2A](http://www.wolframalpha.com/input/?i=12V%2F10%CE%A9)    |    14.40W |            12.5V |          1.17A   |

Note:
* I didn't take measurements for the 1 and 2 resistor gangs
* nominal power per resistor is 2.88W, that's why I'm using 5W resistors here.
* according to my multimeter, the power supply delivering about 12.3V over 50Ω down to 12.05V over 10Ω. Still, readings not quite within 1% resolution.
* resistors are quite close to their 50Ω rating. Five in parallel measure at 10.3Ω according to my multimeter.

### So Does it Just need Calibrating?

There are two trimpots on the circuit board. Although not documented, it's highly likely they are
fine adjustment for voltage and current measurements. And indeed they are:

![module_calibration](./assets/module_calibration.jpg?raw=true)

With a bit of adjustment, I'm now getting results within the 1% (± 1 digit) range. Here it is with a 10Ω load over 12.13V:

![test_5x_calibrated](./assets/test_5x_calibrated.jpg?raw=true)


### Construction

![Schematic](./assets/VoltmeterAmmeterModule_bb.jpg?raw=true)

![Schematic](./assets/VoltmeterAmmeterModule_schematic.jpg?raw=true)

![Build](./assets/VoltmeterAmmeterModule_build.jpg?raw=true)

## Credits and References
* [DC 0-100V 10A Digital Voltmeter Ammeter Dual Display Voltage Detector Current Meter Panel Amp Volt Gauge 0.28" Red Blue LED](https://www.aliexpress.com/item/0-28-Red-Blue-LED-DC-0-100V-10A-Dual-display-Meter-Digital-Voltmeter-Ammeter-Panel/32310008404.html) - from a seller on aliexpress
* [LEAP#181 VoltmeterModule](../VoltmeterModule)
* [name](url)

