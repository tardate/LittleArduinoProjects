# #569 PowerMeter

A voltage, current and power meter using the INA226, with an ATtiny85 driving the process and displaying measurements to a 128X32 OLED display.

![Build](./assets/PowerMeter_build.jpg?raw=true)

## Notes

I played around with INA226 high-side power monitoring in [LEAP#504](../../Electronics101/INA226/HighSideMonitorBasics).
It is a great little chip with an I²C interface.

This project puts it together with an ATtiny85 and 128X32 OLED display to act as an inline power meter.

### Designing for Load Power

The INA226 is programmed with a calibration factor (`CAL`), a function of the shunt resistance and the current register LSB (`Current_LSB`).

The current range that can be handled is fundamentally determined by the
full-scale range of the shunt voltage register: ±81.92 mV (2s complement FFFF-7FFF) i.e. LSB representing 2.5 μV.
Having this fixed resolution of 2^15 parts means of course that the higher the current we design for, the lower the resolution.

For this build I'm going to design for a relatively modest maximum current of 500mA,
which would mean using a shunt resistor of
[0.16Ω](https://www.wolframalpha.com/input/?i=81.92mV%2F500mA) for full scale deflection.
If I replace that with a standard 0.2Ω value, it reduces the full scale current range to
[409mA](https://www.wolframalpha.com/input/?i=0.08192V%2F0.2%CE%A9), but with a resolution of
[12.5µA](https://www.wolframalpha.com/input/?i=0.08192V%2F0.2%CE%A9%2F2%5E15).

At maximum current, the shunt resistor would only dissipate
[33mW](https://www.wolframalpha.com/input/?i=%28409mA%29%5E2*0.2%CE%A9), so 1/4 watt resistors are fine.

The shunt resistance and the maximum design current are configured in the [PowerMeter.ino](./PowerMeter.ino) sketch,
for the calibration factor (`CAL`) to be automatically calculated.

Two things are obvious and important:

* handling a different current range means re-compiling the source (this could be avoided by adding a range selector input to the project)
* the actual value of the shunt resitance really maters! Either measured with a very accurate mΩ meter, or calibrated in-circuit. Especially for breadboard tests, I calibrated in-circuit, as by the time breadboard traces, mounting pins etc are taken into account, an R020 0.02Ω resistor was actually more like 0.19Ω in total.

When run with an Arduino Uno, the internal settings are reporting over the serial port, for example:

```
INA226 Power Meter
Manufacturer ID : 5449
Die ID          : 2260
Calibrating for shunt resistance of 0.200Ω and maximum current of 0.500A
  * current_LSB : 0.006554mA
  * power_LSB   : 0.163838mW
  * CAL         : 3906
```

## Arduino Breadboard Prototype

To verify the basics, I first setup the project on a breadboard, and ran it with an Arduino Uno.

When compiled for an Uno, the [PowerMeter.ino](./PowerMeter.ino) sketch uses the
standard [Wire](https://www.arduino.cc/en/reference/wire) library for communications with the INA226 and OLED,
and the [u8g2lib](https://github.com/olikraus/U8g2_Arduino) library for driving the OLED display.

![Breadboard](./assets/PowerMeterArduino_bb.jpg?raw=true)

![Schematic](./assets/PowerMeterArduino_schematic.jpg?raw=true)

Running the Arduino prototype on a breadboard:

![PowerMeterArduino_bb_build](./assets/PowerMeterArduino_bb_build.jpg?raw=true)

## ATtiny85 Breadboard Prototype

For the final build, I was keen to see if an ATtiny85 would be perfectly capable of controlling the project. And it is!

When compiled for an ATtiny85, the [PowerMeter.ino](./PowerMeter.ino) sketch uses the
[Adafruit-TinyWireM](https://github.com/adafruit/TinyWireM) library for communications with the INA226 and OLED,
and the [Tiny4kOLED](https://github.com/datacute/Tiny4kOLED) library for driving the OLED display.

![Breadboard](./assets/PowerMeterATTiny_bb.jpg?raw=true)

![Schematic](./assets/PowerMeterATTiny_schematic.jpg?raw=true)

Running the ATtiny85 prototype on a breadboard (with an Arduino UNO for programming with the Arduino ISP sketch):

![PowerMeterATTiny_bb_build](./assets/PowerMeterATTiny_bb_build.jpg?raw=true)

Checking that it can ever run from a coin cell:

![PowerMeterATTiny_bb_build2](./assets/PowerMeterATTiny_bb_build2.jpg?raw=true)


## Power Switching for the Project

The power meter is independently powered. While it would be possible to tap the power supply under test,
this approach introduces additional constraints and easiest to avoid.

I'm using a 3V CR2032 cell for powering the circuit - *just* enough jiuce it seems for the ATtiny, OLED and INA226.

So how to switch the power to the INA226 monitoring circuit? Three options:

* just add a switch!
* find a DC switched jack with a normally open ("make") 3rd pin - so that plugging in the load supply would also switch on the INA226.
* use a DC switched jack with a normally closed ("break") 3rd pin, with a FET switch to invert the switching logic.

I like the idea of avoiding a manual switch. The best solution would be DC switched jack with a normally open 3rd pin,
but while these are theoretically a thing, I've not been able to find any.

Considering a DC switched jack with a normally closed 3rd pin (this is ~100% of commonly available DC barrel jacks)...
It is not ideal however: since I'm already operating at 3V, there's not much headroom for any additional voltage drop across a FET, so a very low Rds(on) is essential.
With a normally-closed switch, a low-side n-channel MOSFET switch configuration makes sense, but even with a high value pullup (1MΩ works)
there will be a small but continuous current draw of [3µA](https://www.wolframalpha.com/input/?i=3V%2F1M%CE%A9) to accept.
There is perhaps a bigger issue that the low-side FET switch adds an "unknowable" voltage drop that means that bus voltage sensing
will always be off.

I did try this on the breadboard and it does work:

* n-channel MOSFET connected with drain on the low-side of the IN226 power meter and source to ground.
* FET gate pulled down by the nomally closed DC jack 3rd pin
* a 1MΩ pull-up resistor on the gate to ensure the FET switches on when a plug is inserted and breaks the 3rd pin connection to ground
* tested a few FETS that work: 2N7000 (barely), IRFZ44N, and AO3400.

![PowerMeterATTinyLoSideAutoSwitch_bb](./assets/PowerMeterATTinyLoSideAutoSwitch_bb.jpg?raw=true)

![PowerMeterATTinyLoSideAutoSwitch_schematic](./assets/PowerMeterATTinyLoSideAutoSwitch_schematic.jpg?raw=true)

![PowerMeterATTinyLoSideAutoSwitch_bb_build](./assets/PowerMeterATTinyLoSideAutoSwitch_bb_build.jpg?raw=true)

So while the low-side auto-switching does work, I'm not particularly happy with it.

## ATtiny85 Version in a Project Box

Until I can find a DC switched jack with a normally open 3rd pin, I think I'm back to just using a manual switch!

If this works out, I might make a PCB, but for now I'm mounting some SMD components on protoboard for a prototype build.
Here's a sketch of the layout:

![protoboard_layout](./assets/protoboard_layout.jpg?raw=true)

And all installed in a small project box:

![PowerMeterATTiny_build_internals](./assets/PowerMeterATTiny_build_internals.jpg?raw=true)

![PowerMeterATTiny_build_startup](./assets/PowerMeterATTiny_build_startup.jpg?raw=true)

## Next Steps - Improvements?

A few ideas:

* add auto-ranging (adjust the calibration when readings are heading under/over range)
* design a PCB for the circiut
* find a DC switched jack with a normally open 3rd pin?

## Credits and References

* [LEAP#504 INA226 High-side Monitor Basics](../../Electronics101/INA226/HighSideMonitorBasics)
* [INA226 product info and datasheet](http://www.ti.com/product/INA226)
* [Wire library](https://www.arduino.cc/en/reference/wire)
* [u8g2lib](https://github.com/olikraus/U8g2_Arduino) - v2 for monochrome displays
* [Adafruit-TinyWireM](https://github.com/adafruit/TinyWireM) - I²C for the ATtiny
* [Tiny4kOLED](https://github.com/datacute/Tiny4kOLED) - OLED driver for ATtiny
