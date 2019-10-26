# #133 BidirectionalLevelShifter

Test a basic bi-directional 5/3.3V level shifter circuit


## Notes

Voltage level-shifting is commonly accomplished with this n-channel MOSFET trick.
It is the basis of level-modules and interface circuits. Here I'm interfacing 3.3V and 5V circuits.

[Sparkfun have a great page describing the technique](https://learn.sparkfun.com/tutorials/bi-directional-logic-level-converter-hookup-guide), and [Philips Application Note AN97055](http://cdn.sparkfun.com/tutorialimages/BD-LogicLevelConverter/an97055.pdf)
goes into the mechanics.

This is essentially how the bi-directional switching of voltage levels occurs:
* When neither side is pulling down the input, the gate voltage is pulled up to the low-side voltage .. 3.3V in this case. The FET is not conducting, since gate and source voltages are equal. So both source and rain are at their respective high voltages: source: 3.3V, drain: 5V.
* When low-side (source) is pulled down low, the source voltage is less than the gate so the FET turns on, and so high-side drain is also pulled low.
* When high-side (drain) is pulled down low, the drain-substrate diode causes the source to also pull low.

Note that "high" voltages are only nominally the 3.3V/5V rails ... these change as soon as other circuit elements are connected. Buffer circuits could be included to isolate and preserve full rail-to-rail swings on either side.

This circuit is a simple demonstration of a switch in the 5V circuit controlling a load (LED + resistor) in the 3.3V circuit. The circuit could be mirrored to demonstrate the bi-directional switching.

## Construction

![Breadboard](./assets/BidirectionalLevelShifter_bb.jpg?raw=true)

![The Schematic](./assets/BidirectionalLevelShifter_schematic.jpg?raw=true)

![The Build](./assets/BidirectionalLevelShifter_build.jpg?raw=true)

## Credits and References
* [BidirectionalLevelShifterModule](../BidirectionalLevelShifterModule) - similar project, but using a level-shift module
* [Philips Application Note AN97055](http://cdn.sparkfun.com/tutorialimages/BD-LogicLevelConverter/an97055.pdf)
* [Bi-Directional Logic Level Converter Hookup Guide](https://learn.sparkfun.com/tutorials/bi-directional-logic-level-converter-hookup-guide) - excellent resource from sparkfun
* [2N7000 datasheet](https://www.futurlec.com/Transistors/2N7000.shtml)
* [I²C bi-directional level shifter](http://playground.arduino.cc/Main/I2CBi-directionalLevelShifter) - some good Arduino-oriented notes
