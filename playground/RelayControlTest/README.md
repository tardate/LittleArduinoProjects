# RelayControlTest

## Notes

An equivalent test to [RelayModuleTest](../RelayModuleTest),
however this demonstrates direct control of a Songle SRD-05VDC-SL-C relay (without the benefit of a relay module board).

This uses a simple NPN switching circuit.
A [flyback diode](http://en.wikipedia.org/wiki/Flyback_diode) is added to protect the transistor from back EMF.

### Construction

![The Breadboard](./assets/RelayControlTest_bb.jpg?raw=true)

![The Schematic](./assets/RelayControlTest_schematic.jpg?raw=true)

![The Build](./assets/RelayControlTest_build.jpg?raw=true)

## Credits and references
* [SRD-05VDC-SL-C datasheet](https://www.ghielectronics.com/downloads/man/20084141716341001RelayX1.pdf)
* [Relay Switching Circuits](http://www.electronics-tutorials.ws/blog/relay-switch-circuit.html)