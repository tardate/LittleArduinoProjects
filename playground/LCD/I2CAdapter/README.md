# #397 LCD/I2CAdapter

Using an I²C adapter to reduce the Arduino pins needed to drive an LCD.

![Build](./assets/I2CAdapter_build.jpg?raw=true)

## Notes

LCDs based on the Hitachi HD44780 or a compatible chipset are a popular display option for Arduino project.
Common form factors are 1602 (16 column, 2 row) and 2004 (20 column, 4 row).

The basic LCDs require at least 6 Arduino pins to drive,
and the standard [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal) library is available for this.


To save pins and simplify wiring, there are I²C adapters available - either separately or packaged with an LCD.
These board basically use some form of Remote 8-Bit I/O Expander chip, such as the
[TI PCF8574](http://www.ti.com/product/PCF8574).

Another [product that is very common on aliexpress](https://www.aliexpress.com/item/32656254948.html) and eBay users a part apparently from Philips, but I haven't found d datasheet for it yet.

![module](./assets/module.jpg?raw=true)

## I²C Addressing

The default address for my module turns out to be 0x3F (other common default addresses appear to include 0x27),
although I had to scan the address space to discover this!

There are 3 unsoldered address pads on the module which I presume will allow adjusting the unit address.


## Code and Libraries

I²C is not supported by the standard LiquidCrystal library.
When I searched for I²C LCD libraries:

* it seems there is no clear leader
* there are many independent forks of common source code
* it's a bit of a mess!

Never-the-less, I picked a reletively recent one:
[LiquidCrystal_I2C](https://github.com/marcoschwartz/LiquidCrystal_I2C)
and it is working just fine.

The [I2CAdapter.ino](./I2CAdapter.ino) sketch is a simple test of the library.

## Construction

![Breadboard](./assets/I2CAdapter_bb.jpg?raw=true)

![Schematic](./assets/I2CAdapter_schematic.jpg?raw=true)

![Build](./assets/I2CAdapter_build.jpg?raw=true)

## Credits and References

* [5pcs 1602 2004 LCD Adapter Plate IIC I2C / Interface lcd1602 I2C LCD Adapter for new](https://www.aliexpress.com/item/32656254948.html) - aliexpress
* [1pcs LCD1602 LCD monitor 1602 5V blue screen](https://www.aliexpress.com/item/32663355189.html) - aliexpress
* [LiquidCrystal_I2C](https://github.com/marcoschwartz/LiquidCrystal_I2C) - library I am using
* Standard [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal) library
* [TI PCF8574](http://www.ti.com/product/PCF8574)

