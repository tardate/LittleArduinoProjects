# #107 RingCounter

Test the classic CD4017 walking-ring counter


## Notes

This is a classic circuit, often marketed as a hobby kit under various names like "water flow effect" or somesuch.

In fact, it is a straight-forward demonstration of the basic operation of the CD4017 Decade Counter/Divider with 10 Decoded Outputs:
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

Note that since only a single LED should be on at a given time, the 10 x 1kΩ current-limiting resistors could be replaced by a single resistor
on a common cathode ground link for the LEDs. But it depends on the specific LED ratings, as this subjects all the "off" LEDs to a reverse voltage equal to the voltage drop across the resistor.

See [RingCounterController](../../playground/RingCounterController) for a variant of this project using an Arduino to control the 4017.

Interesting side-note: a very similar circuit is used in some SMD soldering training kits, such as
[this kit on aliexpress](https://www.aliexpress.com/item/SMD-components-welding-practice-board-Welding-practice-light-kit-Skills-Training-welding-competition-kit/32315250409.html):

![SMD kit](./assets/smd_trainer.jpg?raw=true)

## Construction

![Breadboard](./assets/RingCounter_bb.jpg?raw=true)

![The Schematic](./assets/RingCounter_schematic.jpg?raw=true)

![The Build](./assets/RingCounter_build.jpg?raw=true)

## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [CD4017 datasheet](https://www.futurlec.com/4000Series/CD4017.shtml)
* [RingCounterController](../../playground/RingCounterController) - same project but using an Arduino for control
* [kit link](https://www.aliexpress.com/item/M89-Free-Shipping-New-1PC-New-NE555-CD4017-Light-Water-Flowing-Light-LED-Module-DIY-Kit/32259714112.html) - example of the same circuit available as a kit from a seller on aliexpress
* [SMD training kit on aliexpress](https://www.aliexpress.com/item/SMD-components-welding-practice-board-Welding-practice-light-kit-Skills-Training-welding-competition-kit/32315250409.html)
