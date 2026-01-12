# #134 Bidirectional Level Shifter Module

Test a bi-directional 5/3.3V level shifter module.

![The Modules](./assets/BidirectionalLevelShifterModule_module.jpg?raw=true)

## Notes

3.3/5V level-shifting modules are quite common, as the need to interface 5V microcontrollers with 3.3V devices/sensors (or vice versa) is pretty common. Often these are billed for
[I²C](https://en.wikipedia.org/wiki/I%C2%B2C)
or [SPI](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus),
although they are non-specific and can be used for level-shifting any kind of digital signal.
Note: yes, digital high/low signals only; they do not provide an analog scaling of voltages.

I got some of these [modules from a seller on aliexpress](https://www.aliexpress.com/item/10PCS-Two-Channel-IIC-I2C-Logic-Level-Converter-Bi-Directional-Module-5V-to-3-3V/32213240585.html)

The modules have two pairs of "transmit" and "receive" lines. It turns out that transmit and receive are handled differently:

* TXD/TXI uses a standard MOSFET level shifting circuit, so is usable in either direction with accurate levels
* RXD/RXI uses a simple voltage divider. This is OK for signals from high side to low side, but not in the reverse direction.

![module_internal_schematic](./assets/module_internal_schematic.jpg?raw=true)

## Construction

This circuit is a quick test of their behaviour: a switch in the 5V circuit controlling a load (LED + resistor) in the 3.3V circuit.

This is identical to the test circuit used in the [BidirectionalLevelShifter](../BidirectionalLevelShifter) project,
which demonstrates the basic FET trick used by these modules.

All good! Now to put them to work...

![Breadboard](./assets/BidirectionalLevelShifterModule_bb.jpg?raw=true)

![The Schematic](./assets/BidirectionalLevelShifterModule_schematic.jpg?raw=true)

![The Build](./assets/BidirectionalLevelShifterModule_build.jpg?raw=true)

## Credits and References

* [BidirectionalLevelShifter](../BidirectionalLevelShifter) - project testing the basic level-shifting FET trick
* ["10PCS Two Channel IIC I2C Logic Level Converter Bi-Directional Module 5V to 3.3V" (aliexpress seller listing)](https://www.aliexpress.com/item/32213240585.html)
    * Originally purchased in a pack of 10 for US$3.39/lot (Jul-2015), but no longer available from this seller.
* ["5/10/50pcs 4channel 2 channel IIC I2C Logic Level Converter Bi-Directional Module 5V to 3.3V For Arduino" (aliexpress seller listing)](https://www.aliexpress.com/item/1005006255186878.html)
    * Similar product (2-channel) currently listing in a pack of 10 for SG$2.90/lot
    * Also offer a 4-channel version currently listing in a pack of 10 for SG$2.80/lot
* [I²C](https://en.wikipedia.org/wiki/I%C2%B2C) - wikipedia
* [SPI](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus) - wikipedia
* [Philips Application Note AN97055](http://cdn.sparkfun.com/tutorialimages/BD-LogicLevelConverter/an97055.pdf)
* [Bi-Directional Logic Level Converter Hookup Guide](https://learn.sparkfun.com/tutorials/bi-directional-logic-level-converter-hookup-guide) - excellent resource from sparkfun
