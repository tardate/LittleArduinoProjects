# Simple7SegmentDisplay

Drives a 7-segment display, performing a countdown from 9 to 0.

## Notes

The 7-segment display unit I have is stamped "SMA42056". It appears to be fairly common, however I've yet to find a datasheet for it.
From inspection hwoever, it's clearly a common cathode unit, and similar to the
the [SC56-11](./assets/SC56-11_datasheet.pdf?raw=true)

This circuit puts the resistors in series of the common cathode pins. Which is a bit of an approximation,
as current (brightness) will vary a little depending on how many LED segments are lit. The "correct"
way (and as recommended in other circuits I've seen) is to put a resistor on each pin. But this was
good enough for a simple test.

### Construction

![The Breadboard](./assets/Simple7SegmentDisplay_bb.jpg?raw=true)

![The Schematic](./assets/Simple7SegmentDisplay_schematic.jpg?raw=true)

![The Build](./assets/Simple7SegmentDisplay_build.jpg?raw=true)

## Credits and references
* [SC56-11 Datasheet](./assets/SC56-11_datasheet.pdf?raw=true)
* [Arduino and 7 Segment LED](http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html) - original idea and source code
* [Drive a 7-Segment LED with an Arduino](http://makezine.com/projects/drive-a-7-segment-led-with-an-arduino/)
