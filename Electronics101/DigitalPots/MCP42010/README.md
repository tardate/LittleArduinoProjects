# #264 DigitalPots/MCP42010

Control the MCP42010 dual 10kΩ digital potentiometer with an Arduino and hardware SPI.

![Build](./assets/MCP42010_build.jpg?raw=true)


## Notes

I'm trying out some digital potentiometers for an application.
This is a test of the MCP42010 - the dual 10kΩ version of the MCP41XXX/MCP42XXX.

This is a pretty nice chip:

* independant control of the two wipers via standard SPI
* can be daisy-chained
* 8-bit resolution for the wiper setting
* polarity of the A/B pot connections does not matter
* reset pin (sets wiper to middle position)
* hardware/software shutdown control

Typical Applications:

* Programmable gain circuits
* Programmable differential input amplifier


### SPI

It is possible to operate the device in SPI_MODE0 and SPI_MODE3

* SPI_MODE0: Clock Polarity=0, Clock Phase=0
* SPI_MODE3: Clock Polarity=1, Clock Phase=1

It supports a basic command + data byte structure, per the timing diagram from the datasheet:

![spi_timing](./assets/spi_timing.png?raw=true)

Unfortunately it appears the MCP42010 cannot handle two commands in a single SPI transaction,
hence if A and B wiper settings are different they need to be sent separately.
If A and B wiper settings are the same, they can be sent in one command.

### Test Program

The [MCP42010.ino](./MCP42010.ino) sketch is a simple test that drives the two wiper outputs with complementary triangle waves.
This is what it looks like on a scope:

![scope](./assets/scope.gif?raw=true)


## Construction

I have the MCP42010 in a 14-Lead SOIC package, so I loaded it on an adapter for breadboard tests..

![Build](./assets/MCP42010_build.jpg?raw=true)

![Breadboard](./assets/MCP42010_bb.jpg?raw=true)

![Schematic](./assets/MCP42010_schematic.jpg?raw=true)

![MCP42010_breadboard](./assets/MCP42010_breadboard.jpg?raw=true)


## Credits and References

* [MCP42010 datasheet](http://parts.io/detail/1372149/MCP42010-I%2FSL) - parts.io
* [Arduino SPI library](https://www.arduino.cc/en/Reference/SPI)
* [SPI](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus) - wikipedia
* [..as mentioned on my blog](https://blog.tardate.com/2017/04/leap264-mcp42010-digital-pot.html)
