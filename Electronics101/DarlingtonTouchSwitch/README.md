# DarlingtonTouchSwitch

Test a Darlington-pair touch switch.

## Notes

A Darlington pair refers to a couple of bipolar transistors connected so that the amplified emmitter signal of one is used to drive the second. This results a multiplication of the gain, so the circuit is hyper-sensitive to any input signal.

An ideal applications is a touch switch - the classic demonstration case.

The load in this circuit is just an LED with a current-limiting resistor.
Two NPN transistors form the Darlington-pair.
The circuit works over a wide-range of voltages - basically constrained by the specific transistors used
and the size of the current-limiting resistor (to avoid blowing the LED).

The touch switch control comprises two leads:
* to the base of the Darlington-pair
* to positive power

A 100kΩ resistor is included to protect against bad things happening if the touch switch is completely shorted.

It doesn't take much to activate the switch:
* touch the base lead only will turn on the Darlington-pair to a degree
* a single finger pressing across the base and power lead will turn the switch hard on
* touch one lead with one hand, and the other lead with the other hand (using your body as the conductor) will also turn the switch hard on


## Construction

![Breadboard](./assets/DarlingtonTouchSwitch_bb.jpg?raw=true)

![The Schematic](./assets/DarlingtonTouchSwitch_schematic.jpg?raw=true)

![The Build](./assets/DarlingtonTouchSwitch_build.jpg?raw=true)

## Credits and References
* [Darlington transistor/pair](https://en.wikipedia.org/wiki/Darlington_transistor) - wikipedia
* [The Darlington pair](http://www.pcbheaven.com/userpages/basic_transistor_circuits/) - describes the touch switch circuit
* [Touch switch with a darlington pair](https://youtu.be/XArtEkeSkt4) - video demo
