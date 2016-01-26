# #178 LED7Segment/ShiftDriveModule

A custom 7-segment display module PCB with 74HC595 shift register interface.

## Notes

This is my version of project 2 from the
[KiCad like a Pro](http://txplore.tv/courses/kicad-pro)
course from Tech Explorations.

It is essentially the [LED7Segment/ShiftDrive](../ShiftDrive) project but as a custom PCB.
The PCB includes a single 7-Segment LED, current limiting resistors and 74HC595 shift register.

The PCB design was done with [KiCad](http://kicad-pcb.org/).

I've sent these off for production, will update and share the OSH Park project when they're back and tested.

## Construction

See the [KiCad project](./kicad_project/sevensegment_led_display_module.pro) for all the details. Here's the result:

![The Schematic](./assets/ShiftDriveModule_schematic.png?raw=true)

![PCB](./assets/ShiftDriveModule_pcb.png?raw=true)

![PCB render](./assets/ShiftDriveModule_pcb_render.png?raw=true)

## Credits and References
* [LED7Segment/ShiftDrive](../ShiftDrive) - breadboard version of the circuit
* [KiCad like a Pro](http://txplore.tv/courses/kicad-pro) - course materials
* [KiCad](http://kicad-pcb.org/)
* [gerblook](http://gerblook.org/) - nice tool for testing a set of gerber files
* [OSH Park](https://oshpark.com/)
* [HARDWARE HANGOUT with James "Laen" Neal from OSH Park!](https://www.youtube.com/watch?v=XssjD97-xGM) - where I first learned of OSH Park

