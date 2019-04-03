# #080 DoubleShift

Driving a 4-Digit 7-Segment display with only 3 pins, using two 74HC595 shift registers and some NPN BJTs


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

See [Led4Digit7Segment](../) for general discussion of 4-digit 7-segment displays,
how to drive them, and the details of the specific SMA420564 unit used in this test.

The [SingleShift](../SingleShift) experiment demonstrated how to use a 74HC595 shift register and some NPN BJTs
to save Arduino pins. But it still needed 7 pins (3 for the 74HC595, 4 for the BJTs).

This circuit is a variation that uses two registers and means we reduce the number of Arduino pins required to 3.

It works by chaining the 74HC595 shift registers: each data update pushes two bytes down the pipe.
The first byte encodes the selection of which digit(s) to enable,
and the second byte endodes the selection of which LED segments to enable.

The LED segments and BJTs are wired to the shift register outputs accordingly. So then it is just a matter of pushing
the right bytes out to the shift registers and latch the result.

As before, the circuit puts the current-limiting resistors in series of the common cathode pins.
Which is a bit of an approximation, as current (brightness) varies a little depending on how many LED segments are on.
The better way is to put a resistor on each segment pin. But this was good enough for a simple test.

When fully on (e.g. displaying 8888), it appears the display and associated components on the breadboard are drawing
an average of about 2.87mA.
A direct replacement of the S9013 BJTs with n-channel FETs - see [Led4Digit7Segment/DoubleShiftWithFETs](../DoubleShiftWithFETs) -
results in an average current of 2.47mA).

### Construction

![The Breadboard](./assets/DoubleShift_bb.jpg?raw=true)

![The Schematic](./assets/DoubleShift_schematic.jpg?raw=true)

![The Build](./assets/DoubleShift_build.jpg?raw=true)

## Credits and references
* [74HC595 Datasheet](https://www.futurlec.com/74HC/74HC595.shtml)
* [S9013 Datasheet](https://www.futurlec.com/Transistors/S9013.shtml)
* [KW4-561 Datasheet](http://www.sme.com.hk/globetec/LED%20Displays/Four%20Digit%20Display/KW4-561.pdf) - not matching the part I have, but a pretty stanrd example
* a good [How to.. question at EE.SE](http://electronics.stackexchange.com/questions/34815/using-4-digit-7-segment-led)
* [2 Shift Registers 74HC595 Cascading with LED Display](https://www.youtube.com/watch?v=dS6AHRavEkc)
