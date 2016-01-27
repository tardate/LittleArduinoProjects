# #179 LEDx16Module

A custom 16 LED SMD PCB with 74HC595 shift register interface.

## Notes

This is my version of project 3 from the
[KiCad like a Pro](http://txplore.tv/courses/kicad-pro)
course from Tech Explorations.

The board exposes a dual 74HC595 shift register interface for microcontroller control
of an array of 16 LEDs with current-limiting resistors.

The PCB design was done with [KiCad](http://kicad-pcb.org/).

I haven;t sent the boards for production yet - first sourcing and verifying the SMD components.
When I've built and tested the board, I'll update and share the OSH Park project and Arduino code.

## Construction

See the [KiCad project](./kicad_project/LEDx16Module.pro) for all the details. Here's the result:

![The Schematic](./assets/LEDx16Module_schematic.png?raw=true)

![PCB](./assets/LEDx16Module_pcb.png?raw=true)

![PCB render](./assets/LEDx16Module_pcb_render.png?raw=true)

## Credits and References
* [KiCad like a Pro](http://txplore.tv/courses/kicad-pro) - course materials
* [KiCad](http://kicad-pcb.org/)
* [gerblook](http://gerblook.org/) - nice tool for testing a set of gerber files
* [OSH Park](https://oshpark.com/)
* [HARDWARE HANGOUT with James "Laen" Neal from OSH Park!](https://www.youtube.com/watch?v=XssjD97-xGM) - where I first learned of OSH Park


