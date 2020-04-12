# #078 SingleShift

Driving a 4-digit 7-segment display with a shift register and a few BJTs


## Notes

See [Led4Digit7Segment](../) for general discussion of 4-digit 7-segment displays,
how to drive them, and the details of the specific SMA420564 unit used in this test.

While you can wire up each segment pin to a digital out on the Arduino, it soon becomes pretty wasteful of pins.
This project uses an 8-bit shift register to feed segment values and some BJTs to control digit selection.

A 74HC595 is used to shift out the segment values in a block, requiring only 3 pins.

S9013 NPN BJTs are used to switch the sinking of each digit's common cathode connection.
In this circuit, the BJTs are directly controlled with an additional 4 pins.
The S9013 is selected for no other reason than it's a nice reliable small-signal transistor, and some were on hand.
Pretty much any NPN transistor would do.

This circuit puts the current-limiting resistors in series of the common cathode pins.
Which is a bit of an approximation, as current (brightness) varies a little depending on how many LED segments are on.
The better way is to put a resistor on each segment pin. But this was good enough for a simple test.

### Construction

![The Breadboard](./assets/SingleShift_bb.jpg?raw=true)

![The Schematic](./assets/SingleShift_schematic.jpg?raw=true)

![The Build](./assets/SingleShift_build.jpg?raw=true)

## Credits and References

* [74HC595 Datasheet](https://www.futurlec.com/74HC/74HC595.shtml)
* [S9013 Datasheet](https://www.futurlec.com/Transistors/S9013.shtml)
* [KW4-561 Datasheet](http://www.sme.com.hk/globetec/LED%20Displays/Four%20Digit%20Display/KW4-561.pdf) - not matching the part I have, but a pretty stanrd example
* a good [How to.. question at EE.SE](http://electronics.stackexchange.com/questions/34815/using-4-digit-7-segment-led)
