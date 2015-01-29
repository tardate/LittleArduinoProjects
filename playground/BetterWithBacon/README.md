# Better with Bacon on an LCD

A simple "Hello World" test of a 16x2 LCD module.

![The Build](./assets/BetterWithBacon_build.jpg?raw=true)

## Notes


Demonstrates the use a 16x2 LCD display.  The LiquidCrystal library works with all LCD displays that are compatible with the Hitachi HD44780 driver. There are many of them out there, and you can usually tell them by the 16-pin interface.

A variable resistor is used to trim contrast, the the LCD backlight is powered from the 5V rail.

## Construction

![The Breadboard](./assets/BetterWithBacon_bb.jpg?raw=true)

![The Schematic](./assets/BetterWithBacon_schematic.jpg?raw=true)

![The Build](./assets/BetterWithBacon_build.jpg?raw=true)

### Parts

* [Arduino Uno R3](http://www.amazon.com/gp/product/B00F6JCV20/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B00F6JCV20&linkCode=as2&tag=itsaprli-20&linkId=O34GVKFAZ6FVDC6W) or similar
* breadboard
+ 50k potetiometer
* 16x2 LCD (I used a [QC1602A](./assets/LCD_QC1602A_datasheet.pdf?raw=true "QC1602A Datasheet"))

## Credits and references
* [QC1602A 16x2 LCD datasheet](./assets/LCD_QC1602A_datasheet.pdf?raw=true "QC1602A Datasheet"))
* Based on the [Arduino LiquidCrystal example](http://www.arduino.cc/en/Tutorial/LiquidCrystal)

