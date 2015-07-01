# RingCounter

Test the classic CD4017 walking-ring counter

## Notes

This is a classic circuit, often marketed as hobby kits under various names like "water flow effect" or somesuch.
In fact, it is a straightforward demonstration of the basic operation of the CD4017:
* a 555 astable oscillator provides a clock pulse to the CD4017
* the CD4017 counts in the "1 of 10" cyclic manner
* the CD4017 outputs directly drive a series of LEDs
* so one LED will be on at a time

In this circuit, the variable resistor R1 gives control of the pulse frequency between
[11Hz](http://visual555.tardate.com/?mode=astable&r1=2.2&r2=60&c=1) and
[64Hz](http://visual555.tardate.com/?mode=astable&r1=2.2&r2=10&c=1).

The circuit can be powered over a wide range - from about 4.5V to 15V, depending on the ratings of the specific chips.
LED brightness will be affected by the supply voltage, and below 9V it might be desirable to replace the 1kΩ current-limiting resistors with a lower value.
When powered by 9V battery source, the maximum current drawn is around 11.2mA.

## Construction

![Breadboard](./assets/RingCounter_bb.jpg?raw=true)

![The Schematic](./assets/RingCounter_schematic.jpg?raw=true)

![The Build](./assets/RingCounter_build.jpg?raw=true)

## Credits and References
* [CD4017 datasheet](http://www.futurlec.com/4000Series/CD4017.shtml)
* [kit link](http://www.aliexpress.com/item/M89-Free-Shipping-New-1PC-New-NE555-CD4017-Light-Water-Flowing-Light-LED-Module-DIY-Kit/32259714112.html)

