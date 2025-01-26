# #426 Boldport 3x7 RippleTester

Using some 4000 series counters (CD4017, CD4060) to exercise the digits and segments of the Boldport 3x7.

![Build](./assets/RippleTester_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/wn-WYp7O15c/0.jpg)](https://www.youtube.com/watch?v=wn-WYp7O15c)

## Notes

After building the [Boldport 3x7](../) I thought it would be nice to have a simple way
to demonstrate that all the segments and digit controls are working correctly -
without having to do it by hand or resort to plugging in a microcontroller.

So I whipped up this circuit on a breadboard using a CD4017 and CD4060:

* the CD4060 is configured with an RC oscillator resulting in a first counter stage (Q4) frequency of about 6 Hz
* seven CD4060 counter stages (Q4-Q10) feed the 3x7 segment pins a-g
* the next CD4060 counter stage (Q12) is hooked to reset, and also provides the clock pulse to the CD4017
* the CD4017 steps through output 0,1,2 and then resets it's count
* the CD4017 outputs 0,1,2 feed the 3x7 digit pins A, B, C

The result is a simple pattern that runs through all combinations of segments on each digit in turn.


Note: because the CD4060 does not expose Q11 counter stage, the pattern of segments actually runs twice on each digit before moving to the next.


## Construction

![Breadboard](./assets/RippleTester_bb.jpg?raw=true)

![Schematic](./assets/RippleTester_schematic.jpg?raw=true)

![Build](./assets/RippleTester_build.jpg?raw=true)

## Credits and References

* [LEAP#425 The Boldport 3x7](../)
* [CD4017 datasheet](https://www.futurlec.com/4000Series/CD4017SMD.shtml)
* [CD4060 datasheet](https://www.futurlec.com/4000Series/CD4060.shtml)
