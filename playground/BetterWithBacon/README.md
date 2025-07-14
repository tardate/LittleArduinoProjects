# #006 Better with Bacon on an LCD

A simple "Hello World" test of a 16x2 LCD module.

![The Build](./assets/BetterWithBacon_build.jpg?raw=true)

## Notes

Demonstrates the use a 16x2 LCD display.  The LiquidCrystal library works with all LCD displays that are compatible with the Hitachi HD44780 driver.
There are many of them out there, and you can usually tell them by the 16-pin interface.

A variable resistor is used to trim contrast, and the LCD backlight is powered from the 5V rail.

## Construction

![The Breadboard](./assets/BetterWithBacon_bb.jpg?raw=true)

![The Schematic](./assets/BetterWithBacon_schematic.jpg?raw=true)

![The Build](./assets/BetterWithBacon_build.jpg?raw=true)

## Credits and References

* [LEAP#749 HD44780-based LCD Modules (e.g. QC1602A)](../../Electronics101/HD44780/)
* Based on the [Arduino LiquidCrystal example](http://www.arduino.cc/en/Tutorial/LiquidCrystal)
