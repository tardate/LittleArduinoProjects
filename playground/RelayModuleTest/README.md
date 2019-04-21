# #054 RelayModuleTest

Controlling a relay "module" with an Arduino. Here's a quick demo:

[![RelayModuleTest](https://img.youtube.com/vi/_8OyyQS27Gk/0.jpg)](https://www.youtube.com/watch?v=_8OyyQS27Gk)


## Notes

A quick test of a pretty common relay board, the [Keyes 5V Relay Module for Arduino](http://www.dx.com/p/arduino-5v-relay-module-blue-black-121354).

The relay board includes a transistor switching circuit (to minimise the current drain on the control signal) and diode shunt protection.

So using it is as simple as connecting 5V power and a control signal on one side, and then the relay-switch circuits on the other. The relay offers both normally opan and normally closed circuits. Either or both can be used.

In this case, I have a motor attached to the NO circuit, and an indicator LED on the NC circuit.

### Construction

![The Breadboard](./assets/RelayModuleTest_bb.jpg?raw=true)

![The Schematic](./assets/RelayModuleTest_schematic.jpg?raw=true)

![The Build](./assets/RelayModuleTest_build.jpg?raw=true)

## Credits and references
* [Keyes 5V Relay Module for Arduino](http://www.dx.com/p/arduino-5v-relay-module-blue-black-121354)
* [SRD-05VDC-SL-C datasheet](https://www.ghielectronics.com/downloads/man/20084141716341001RelayX1.pdf)
* Diagrams use the custom keyes-relay Fritzing part from https://github.com/rwaldron/fritzing-components
