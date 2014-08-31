# 7-Segment Display Counter

Drives a 7-segment display, performing a countdown from 9 to 0.

## Parts for a breadboard build

* Arduino
* Breadboard
* 7-segment common cathode LED display (I used a unit similar to [SC56-11](./assets/SC56-11_datasheet.pdf?raw=true "SC56-11 Datasheet"))
* 2 x 220R (or higher to reduce the display brightness)
* ~10 jumper wires

## Notes

This circuit puts the resistors in series of the common cathode pins. Which is a bit of an approximation,
as current (brightness) will vary a little depending on how many LED strips are lit. The "correct"
way (and as recommended in other circuits I've seen) is to put a resistor on each pin. But this was
good enough for a simple test.

## Credits and references
* Original idea and source from http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
* http://makezine.com/projects/drive-a-7-segment-led-with-an-arduino/


![The Build](./assets/Simple7SegmentDisplay.jpg?raw=true =250x)
![The Breadboard SChematic](./assets/Simple7SegmentDisplay_bb.jpg?raw=true =250x)