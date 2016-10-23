# #261 DigitalPots/MCP4017

Control the MCP4017 single 7-Bit I²C digital potentiometer with an Arduino.


![Build](./assets/MCP4017_build.jpg?raw=true)

## Notes

I'm trying out some digital potentiometers for an application. This is a test of the MCP4017T-104E/LT (100kΩ rheostat version).

The MCP4017 acts as a rheostat - it sets the resistance between the Wiper and B pins, independent of VDD/VSS (i.e. the potentioneter is not grounded or tied to power).

Conclusion? Probably not the chip I'd choose for the job in mind. Key observations:

* does not support hardware I²C address bits (and so far I think there's no way set the address over I²C)
* the 2.5mA current rating means it can probably only be used connected to a high impedance load, else it requires some form of buffer circuit.
* SC70 - dang that's a small package! Managed to hand solder to a 2.54mm DIP adapter without too much trouble (with the aid of a magnifying glass)


### I²C Protocol Support

The MCP4017/18/19 come with a fixed bus address `0b0101111`. So only one can be controlled on the same bus at the same time.

It has a very basic read/write I²C implementation, with no commands defined. Just read and write the wiper value.

| Wiper Setting | Properties         |
|---------------|--------------------|
|          07Fh | Full Scale (W = A) |
|          07Eh | - 040h W = N       |
|          03Fh | W = N (Mid Scale)  |
|          03Eh | - 001h W = N       |
|          000h | Zero Scale (W = B) |


### Test Script and Performance

Measuring the actual resistance I see a full scale of 0Ω - 81.3kΩ (for the '100kΩ'' chip). That is within spec - note
the resistance rating of the chip is ±20%.

The [MCP4017.ino](./MCP4017.ino) sketch is a simple exercise of the chip. It steps from 0Ω to full scale with a 2µs delay between steps.

Note the trace looks logarithmic, but this is expected for a linear change in resistance,
as I am measuring the resistance in a voltage divider - [x/(x+10kΩ)](http://www.wolframalpha.com/input/?i=%7Bx%2F(x%2B10),+x%3D0+to+80%7D).
The voltage divider is in the test circuit to avoid pumping more than the rated ±2.5 mA through the chip.

![scope_full_scale_2us_per](./assets/scope_full_scale_2us_per.gif?raw=true)


## Construction

![Breadboard](./assets/MCP4017_bb.jpg?raw=true)

![Schematic](./assets/MCP4017_schematic.jpg?raw=true)

![MCP4017_test](./assets/MCP4017_test.jpg?raw=true)

## Credits and References
* [MCP4017T-104E/LT info and datasheet](http://parts.io/detail/2900767/MCP4017T-104E%2FLT) - parts.io
* [AD5171 Digital Potentiometer](https://www.arduino.cc/en/Tutorial/DigitalPotentiometer) - tutorial
* [MCP4017](http://www.microchip.com/wwwproducts/en/MCP4017) - Microchip product page
