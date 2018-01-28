# #001 LED7Segment/DirectDrive

Test direct control of a 7-segment display, performing a countdown from 9 to 0.

Here's a quick video of the circuit in action:

[![LED7Segment/DirectDrive](http://img.youtube.com/vi/R90zCCvA7_M/0.jpg)](http://www.youtube.com/watch?v=R90zCCvA7_M)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The 7-segment display unit I have is stamped "SMA42056". It appears to be fairly common, however I've yet to find a datasheet for it.
From inspection hwoever, it's clearly a common cathode unit, and similar to the
the [SC56-11](../assets/SC56-11_datasheet.pdf?raw=true)

There are two common cathode pins, but since these are internally connected there is no need to connect both to ground.
Lighting a segment simply means providing a driving voltage to the corresponding anode pin.

This circuit puts the resistors in series of the anode pins. This ensures a consistent brightness no matter how many segments are on. Note that it is possible to put the current-limiting resistor on the common cathode;
this is a bit of an approximation and will lead to varying LED brightness but may be "good enough" depending on your application.

### Pin-Segment Mapping

Here's a summary of how the Arduino pins are mapped to LED segments:

| Pin | Segment                    |
|-----|----------------------------|
|  2  |  A - top horizontal        |
|  3  |  B - top right vertical    |
|  4  |  C - bottom right vertical |
|  5  |  D - bottom horizontal     |
|  6  |  E - bottom left vertical  |
|  7  |  F - top left vertical     |
|  8  |  G - center  horizontal    |
|  9  |  dp - decimal point        |

### Construction

![The Breadboard](./assets/DirectDrive_bb.jpg?raw=true)

![The Schematic](./assets/DirectDrive_schematic.jpg?raw=true)

![The Build](./assets/DirectDrive_build.jpg?raw=true)

## Credits and references
* [SC56-11 Datasheet](../assets/SC56-11_datasheet.pdf?raw=true)
* [Arduino and 7 Segment LED](http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html) - original idea and source code
* [Drive a 7-Segment LED with an Arduino](http://makezine.com/projects/drive-a-7-segment-led-with-an-arduino/)
* [..as mentioned on my blog](https://blog.tardate.com/2016/02/littlearduinoprojects001-basics-of-7.html)
