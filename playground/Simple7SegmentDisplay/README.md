# 7-Segment Display Counter

Drives a 7-segment display, performing a countdown from 9 to 0.

## Notes

This circuit puts the resistors in series of the common cathode pins. Which is a bit of an approximation,
as current (brightness) will vary a little depending on how many LED strips are lit. The "correct"
way (and as recommended in other circuits I've seen) is to put a resistor on each pin. But this was
good enough for a simple test.


## Parts for a breadboard build

* [Arduino Uno R3](http://www.amazon.com/gp/product/B00F6JCV20/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B00F6JCV20&linkCode=as2&tag=itsaprli-20&linkId=O34GVKFAZ6FVDC6W) or similar
* Breadboard
* 7-segment common cathode LED display (I used a unit similar to [SC56-11](./assets/SC56-11_datasheet.pdf?raw=true "SC56-11 Datasheet"))
* 2 x 220R (or higher to reduce the display brightness)
* ~10 jumper wires

### Construction

![The Breadboard](./assets/Simple7SegmentDisplay_bb.jpg?raw=true)

![The Schematic](./assets/Simple7SegmentDisplay_schematic.jpg?raw=true)

![The Build](./assets/Simple7SegmentDisplay.jpg?raw=true)

## Credits and references
* Original idea and source from http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
* http://makezine.com/projects/drive-a-7-segment-led-with-an-arduino/

