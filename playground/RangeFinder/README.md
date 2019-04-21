# #035 RangeFinder

Use an Arduino to measure range with HC-SR04 module and output to 16x2 LCD.


## Notes

The HC-SR04 ultrasonic ranging module provides 2cm-400cm non-contact measurement.
It is a 5V unit and can be powered from the Arduino 5V pin.

When triggered, the echo pin goes high until the pulse is returned.
Reading the high pulse duration with the `pulseIn` function thus returns the round-trip time in microseconds.
The distance is calculated based on speed of sound, and divided by 2 to eliminate the return trip component.

    distance = high pulse duration × speed of sound  / 2

In practice, I found I had to calibrate the calculation to account for local conditions and variations in unit accuracy.
Once calibrated however, the distance measurement accuracy is pretty good, although I don't think quite the 3mm as advertised.

### LCD Output

Output is sent to an 16x2 LCD display.
The LiquidCrystal library works with all LCD displays that are compatible with the Hitachi HD44780 driver.
There are many of them out there, and you can usually tell them by the 16-pin interface.

A variable resistor is used to trim contrast, and the LCD backlight is powered from the 5V rail.

## Construction

NB: schematics use non-standard [HC-SR04 Fritzing Part](../../FritzingParts)

![The Breadboard](./assets/RangeFinder_bb.jpg?raw=true)

![The Schematic](./assets/RangeFinder_schematic.jpg?raw=true)

![The Build](./assets/RangeFinder_build.jpg?raw=true)

## Credits and references
* [HC-SR04 datasheet](http://www.micropik.com/PDF/HCSR04.pdf)
* [HC-SR04 Project](http://fritzing.org/projects/hc-sr04-project) - example on the Fritzing site
