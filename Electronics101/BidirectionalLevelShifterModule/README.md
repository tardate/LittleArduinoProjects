# #134 BidirectionalLevelShifterModule

Test a bi-directional 5/3.3V level shifter module.

![The Modules](./assets/BidirectionalLevelShifterModule_module.jpg?raw=true)

## Notes

3.3/5V level-shifting modules are quite common, as the need to interface 5V microcontrollers with 3.3V devices/sensors (or vice versa) is pretty common. Often these are billed for
[I²C](https://en.wikipedia.org/wiki/I%C2%B2C)
or [SPI](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus),
although they are non-specific and can be used for level-shifting any kind of digital signal.
Note: yes, digital high/low signals only; they do not provide an analog scaling of voltages.

I got some of these [modules from a seller on aliexpress](http://www.aliexpress.com/item/10PCS-Two-Channel-IIC-I2C-Logic-Level-Converter-Bi-Directional-Module-5V-to-3-3V/32213240585.html)

This circuit is a quick test of their behaviour: a switch in the 5V circuit controlling a load (LED + resistor) in the 3.3V circuit.

This is identical to the test circuit used in the [BidirectionalLevelShifter](../BidirectionalLevelShifter) project,
which demonstrates the basic FET trick used by these modules.

All good! Now to put them to work...

## Construction

![Breadboard](./assets/BidirectionalLevelShifterModule_bb.jpg?raw=true)

![The Schematic](./assets/BidirectionalLevelShifterModule_schematic.jpg?raw=true)

![The Build](./assets/BidirectionalLevelShifterModule_build.jpg?raw=true)

## Credits and References
* [BidirectionalLevelShifter](../BidirectionalLevelShifter) - project testing the basic level-shifting FET trick
* [modules from a seller on aliexpress](http://www.aliexpress.com/item/10PCS-Two-Channel-IIC-I2C-Logic-Level-Converter-Bi-Directional-Module-5V-to-3-3V/32213240585.html)
* [I²C](https://en.wikipedia.org/wiki/I%C2%B2C) - wikipedia
* [SPI](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus) - wikipedia
* [Philips Application Note AN97055](http://cdn.sparkfun.com/tutorialimages/BD-LogicLevelConverter/an97055.pdf)
* [Bi-Directional Logic Level Converter Hookup Guide](https://learn.sparkfun.com/tutorials/bi-directional-logic-level-converter-hookup-guide) - excellent resource from sparkfun
