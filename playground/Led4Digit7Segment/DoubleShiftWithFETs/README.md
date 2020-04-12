# #081 DoubleShiftWithFETs

Driving a 4-Digit 7-Segment display with only 3 pins, using two 74HC595 shift registers and some n-channel FETs


## Notes

This circuit is a variation of the [DoubleShift](../DoubleShift) experiment that
demonstrated how to use two 74HC595 shift registers and some NPN BJTs to drive a 4-digit 7-segment display with
only 3 Arduino GPIO pins.

The only difference here is that the S9013 NPN BJTs are replaced with 2N7000 n-channel FETs.

When fully on (e.g. displaying 8888), it appears the display and associated components on the breadboard are drawing
an average of about 2.47mA (compared to 2.87mA with BJTs).

### Construction

![The Breadboard](./assets/DoubleShiftWithFETs_bb.jpg?raw=true)

![The Schematic](./assets/DoubleShiftWithFETs_schematic.jpg?raw=true)

![The Build](./assets/DoubleShiftWithFETs_build.jpg?raw=true)

## Credits and References

* [74HC595 Datasheet](https://www.futurlec.com/74HC/74HC595.shtml)
* [2N7000 Datasheet](https://www.futurlec.com/Transistors/2N7000.shtml)
* [KW4-561 Datasheet](http://www.sme.com.hk/globetec/LED%20Displays/Four%20Digit%20Display/KW4-561.pdf) - not matching the part I have, but a pretty stanrd example
* a good [How to.. question at EE.SE](http://electronics.stackexchange.com/questions/34815/using-4-digit-7-segment-led)
* [2 Shift Registers 74HC595 Cascading with LED Display](https://www.youtube.com/watch?v=dS6AHRavEkc)
