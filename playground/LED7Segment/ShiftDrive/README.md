# #177 LED7Segment/ShiftDrive

Test control of a 7-segment display via a 74HC595 shift register.

Here's a quick video of the circuit in action:

[![LED7Segment/ShiftDrive](http://img.youtube.com/vi/vD6ldmaypiE/0.jpg)](http://www.youtube.com/watch?v=vD6ldmaypiE)

## Notes

While you can wire up each segment pin to a digital out on the Arduino as in the
[LED7Segment/DirectDrive](../DirectDrive) project, it soon becomes pretty wasteful of pins.
This project uses a 74HC595 8-bit shift register to feed segment values, requiring only 3 pins.

Since the 74HC595 has latched outputs, it also means all segment changes are simulataneous.

## Construction

![Breadboard](./assets/ShiftDrive_bb.jpg?raw=true)

![The Schematic](./assets/ShiftDrive_schematic.jpg?raw=true)

![The Build](./assets/ShiftDrive_build.jpg?raw=true)

## Credits and References
* [LED7Segment/DirectDrive](../DirectDrive) - similar circuit but with direct control
* [74HC595 Datasheet](http://www.futurlec.com/74HC/74HC595.shtml)
* [SC56-11 Datasheet](../assets/SC56-11_datasheet.pdf?raw=true)
* [Drive a 7-Segment LED with an Arduino](http://makezine.com/projects/drive-a-7-segment-led-with-an-arduino/)
