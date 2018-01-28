# #135 555Timer/TouchSwitch

Test a touch switch circuit based on a 555 timer


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This is basically a 555 timer monostable, but triggered by touch pad on pin 2 (trigger).
I'm using a 100kΩ/10µF configuration which gives an output pulse of [1100ms](http://visual555.tardate.com/?mode=monostable&r1=100&c=10) when triggering occurs. The R/C values can be adjusted to change the pulse duration.

The circuit takes advantage of the fact that the trigger input is quite sensitive since it is essentially the
input to a PNP darlington-pair.
Trigger occurs upon application of a negative trigger pulse of less than 1/3 VCC, which sets the internal flip-flip.
The flip-flip is reset at the end of its cycle, ready to receive another trigger input.

In practice, a finger touch to the flying lead attached to pin 2 may be enough to trigger the 555.
If the body is holding too much charge, it may be necessary to press across the two flying leads (pin 2, ground)
in order to pull down pin 2 sufficiently.

Other circuits include a pull-up resistor of 10MΩ or so on pin 2. But doesn't work for me at all.

To improve the sensitivity, pin 2 could be pulled down via a transistor, with the touch applied to the BJT base as
[described here](http://www.555-timer-circuits.com/touch-switch.html).

## Construction

![Breadboard](./assets/TouchSwitch_bb.jpg?raw=true)

![The Schematic](./assets/TouchSwitch_schematic.jpg?raw=true)

![The Build](./assets/TouchSwitch_build.jpg?raw=true)

## Credits and References
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [Touch Switch variants](http://www.555-timer-circuits.com/touch-switch.html) - touch, touch on-off, touch with BJT amplification
* [Touch Sensor Switch Circuit with 555 timer](http://www.electroschematics.com/8433/touch-sensor-switch-circuit-with-555-timer/) - similar circuit
* [Touch Switch](http://english.cxem.net/guard/guard46.php) - another circuit but using a pull-up resistor on pin 2
