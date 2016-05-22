# #179 LEDx16Module

A custom 16 LED SMD PCB with 74HC595 shift register interface.

Here's a quick video of the module running the demo code:

[![LEDx16Module](http://img.youtube.com/vi/FVDoArFkKH8/0.jpg)](http://www.youtube.com/watch?v=FVDoArFkKH8)


## Notes

This is my version of project 3 from the
[KiCad like a Pro](http://txplore.tv/courses/kicad-pro)
course from Tech Explorations.

The board exposes a dual 74HC595 shift register interface for microcontroller control
of an array of 16 LEDs with current-limiting resistors.

The PCB design was done with [KiCad](http://kicad-pcb.org/).

I haven't sent the boards for production yet - first sourcing and verifying the SMD components.
When I've built and tested the board, I'll update and share the OSH Park project and Arduino code.

I sent these off for production at [OSH Park](https://oshpark.com/shared_projects/E2aHiqP5), and they turned out quite well.
I think I could have picked a footprint for the SOP16 ships with longer pads to make them easier to solder by hand.

One variation I've made in the circuit from the KiCad like a Pro course:
I've explicitly grounded pin 13 (output enable - active low).
If left floating, I've found the circuit to be unreliable depending on power conditions (output enable floats high).

## Construction

See the [KiCad project](./kicad_project/LEDx16Module.pro) for all the details. Here's the result:

![The Schematic](./assets/LEDx16Module_schematic.png?raw=true)

![PCB](./assets/LEDx16Module_pcb.png?raw=true)

![PCB render](./assets/LEDx16Module_pcb_render.png?raw=true)

### Example Parts Sources on Aliexpress
* [74HC595 SOP16](http://www.aliexpress.com/item/Free-shipping-100pcs-74HC595D-74HC595-SOP16/905837111.html)
* [220Ω 0805](http://www.aliexpress.com/item/0805-SMD-Resistors-220R-220-ohm-1-8W-5-0805-SMD-Resistors-0805-Chip-resistor-500pcs/851490480.html)
* [220µF 16V 6x7mm SMD](http://www.aliexpress.com/item/Free-shiping-10pcs-16V-220UF-SMD-6x7mm-chip-Aluminum-Electrolytic-Capacitor/1173598774.html)
* [0805 LEDs (5 colours)](http://www.aliexpress.com/item/Free-Shipping-100PCS-0805-Ultra-Bright-SMD-R-G-B-W-Y-LEDs-yellow-blue-White/859788444.html)

## Demo

The [LEDx16Module.ino](./LEDx16Module.ino) sketch runs a simple demo sequence on the board from an Aurduino using hardware SPI.

![LEDx16Module_demo_bb](./assets/LEDx16Module_demo_bb.jpg?raw=true)

![LEDx16Module_demo_schematic](./assets/LEDx16Module_demo_schematic.jpg?raw=true)

![LEDx16Module_build](./assets/LEDx16Module_build.jpg?raw=true)

## Credits and References
* [KiCad like a Pro](http://txplore.tv/courses/kicad-pro) - course materials
* [KiCad](http://kicad-pcb.org/)
* [gerblook](http://gerblook.org/) - nice tool for testing a set of gerber files
* [OSH Park](https://oshpark.com/)
* [HARDWARE HANGOUT with James "Laen" Neal from OSH Park!](https://www.youtube.com/watch?v=XssjD97-xGM) - where I first learned of OSH Park
