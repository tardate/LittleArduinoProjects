# #044 SimpleChime

Play a sound for a fixed duration when a button is pressed - a poor man's door bell!


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This is a build of a simple "door bell" circuit published by [Circuitstoday](http://www.circuitstoday.com/door-bell-circuit-using-ne555).

It operates by using one 555 timer in monostable to trigger an astable signal on a second 555 for a defined period.

The duration of the "chime" is determined by the values of R4 and C1 which set the monostable high cycle for the first 55 timer.
With [10kΩ and 33μF this is about 363ms](http://visual555.tardate.com/?mode=monostable&r1=10&c=33).

When the output of the first 555 goes high (pin 3), this pulls the reset pin 4 high on the second 555.

The astable signal of the second 555 is governed by R3, R5 and C3.
With [R3=1kΩ, R5=22kΩ and C3=100nF this runs at about 320Hz with a 51% duty cycle](http://visual555.tardate.com/?mode=astable&r1=1&r2=22&c=0.1). The schematic indicates using variable resistor for R5, but this
can be replaced with a resistor if a fixed frequency is acceptable.

### Construction

![The Breadboard](./assets/SimpleChime_bb.jpg?raw=true)

![The Schematic](./assets/SimpleChime_schematic.jpg?raw=true)

![Breadboard Build](./assets/SimpleChime_build.jpg?raw=true)

## Credits and references
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [Visual 555 Calculator](http://visual555.tardate.com)
* [Door bell circuit using NE555](http://www.circuitstoday.com/door-bell-circuit-using-ne555) - original circuit from Circuitstoday

