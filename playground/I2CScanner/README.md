# #397 I²C Scanner

Scanning for I²C devices with an Arduino.

![Build](./assets/I2CScanner_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This is a simple sketch, inspired by
[i2c_scanner](http://playground.arduino.cc/Main/I2cScanner)
that simply scans for the presence of addresses in the full 7-bit address space.

This can be very helpful when trying to use I²C modules where the default address is not documented.

## About I²C


I²C (Inter-Integrated Circuit) is a communications bus specification invented in 1982 by Philips Semiconductor.
Patents on I²C have now lapsed and trademark protection only remains for the logo.

I²C is now generally supported by many manufacturers, but it is also known as TWI (Two-Wire Interface) or TWSI (Two-Wire Serial Interface)
Note: in some cases, the term "two-wire interface" may hint at incomplete implementation of the I²C specification.

I²C provides bi-directional communication for many devices in a master-slave configuration over two wires.

I²C addresses are used to select between devices on a single bus. There are 7-bit and 10-bit address modes:

* 7-bit addresses are most commonly used in microcontroller peripherals
* 10-bit addresses are not yet widely used, and support is limited
* the sketch here only looks for 7-bit addresses


## Code

The [I2CScanner](./I2CScanner.ino) sketch runs an address scan every 5 seconds and prints
the address of any found devices over the serial port.


![console](./assets/console.png?raw=true)

It uses the standard [Wire Library](https://www.arduino.cc/en/Reference/Wire)
to attempt to begin a (null) transmission to each device address.
The [Wire.endTransmission()](https://www.arduino.cc/en/Reference/WireEndTransmission)
return code indicates the status of the transmission:

* 0:success
* 1:data too long to fit in transmit buffer
* 2:received NACK on transmit of address
* 3:received NACK on transmit of data
* 4:other error

Any device that returns 0 is reported as a valid address.

## Construction

Pull-up resistors may need to be provided if they are not already present on the I²C two-wire bus.

![Breadboard](./assets/I2CScanner_bb.jpg?raw=true)

![Schematic](./assets/I2CScanner_schematic.jpg?raw=true)

![Build](./assets/I2CScanner_build.jpg?raw=true)

## Credits and References
* [i2c_scanner](http://playground.arduino.cc/Main/I2cScanner) - Frode Grimstad Bang
* [I²C](https://en.wikipedia.org/wiki/I%C2%B2C) - wikipedia
* Standard [Wire Library](https://www.arduino.cc/en/Reference/Wire)
* [..as mentioned on my blog](https://blog.tardate.com/2018/07/leap397-i2c-scanner.html)
