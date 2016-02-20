# #178 LED7Segment/ShiftDriveModule

A custom 7-segment display module PCB with 74HC595 shift register interface.

![Build](./assets/ShiftDriveModule_build.jpg?raw=true)

## Notes

This is my version of project 2 from the
[KiCad like a Pro](http://txplore.tv/courses/kicad-pro)
course from Tech Explorations.

It is essentially the [LED7Segment/ShiftDrive](../ShiftDrive) project but as a custom PCB.
The PCB includes a single 7-Segment LED, current limiting resistors and 74HC595 shift register.

The PCB design was done with [KiCad](http://kicad-pcb.org/).

<a href="https://oshpark.com/shared_projects/gs9XjBpw"><img src="https://a800d827b6de8403a51e-6ffc2e718631809086ea40332b2055f7.ssl.cf1.rackcdn.com/assets/badge-5b7ec47045b78aef6eb9d83b3bac6b1920de805e9a0c227658eac6e19a045b9c.png" alt="Order from OSH Park"></img></a>

I sent these off for production at [OSH Park](https://oshpark.com/shared_projects/gs9XjBpw), and they arrived (in Singapore) a month later (Jan 17th -> Feb 17th). They turned out quite well, certainly no issues with the fab.

After examining the PCBs, I found a few things that could be improved in the design:
* doh! I got the data/latch labels around the wrong way (fixed in 1.1.0)
* pin header label was obscurred by R1 (fixed in 1.1.0)
* the orientation of the 74HC595 should probably be a clearer (like a notch in the footprint outline)

But it works a treat!

### Register-Pin Mapping

Here's a summary of how the bits in the shift register are mapped to LED segments:

| Bit | Segment                    |
|-----|----------------------------|
|  0  |  A - top horizontal        |
|  1  |  B - top right vertical    |
|  2  |  C - bottom right vertical |
|  3  |  D - bottom horizontal     |
|  4  |  E - bottom left vertical  |
|  5  |  F - top left vertical     |
|  6  |  G - center  horizontal    |
|  7  |  dp - decimal point        |

### Test Script

The [ShiftDriveModule.ino](./ShiftDriveModule.ino) sketch drives the module with a simple counter from 0-9, with the decimal point lit for even numbers.

The script manipulates the data/latch/clock output directly (no SPI), and assumes the following pin connections:

| Arduino Pin | Module Pin |
|-------------|------------|
| 5V          | Vcc        |
| GND         | GND        |
| 3           | DATA       |
| 4           | LATCH      |
| 5           | CLOCK      |

![Demo](./assets/ShiftDriveModule_demo.jpg?raw=true)

## Construction

See the [KiCad project](./kicad_project/sevensegment_led_display_module.pro) for all the details. Here's the result:

![The Schematic](./assets/ShiftDriveModule_schematic.png?raw=true)

![PCB](./assets/ShiftDriveModule_pcb.png?raw=true)

![PCB render](./assets/ShiftDriveModule_pcb_render.png?raw=true)

Here are the finished boards. For the one I've already soldered I first used male pins (to plug-in to a breadboard),
but if I do another I'll probably use female pin headers instead.

![Build](./assets/ShiftDriveModule_build.jpg?raw=true)

## Credits and References
* [LED7Segment/ShiftDrive](../ShiftDrive) - breadboard version of the circuit
* [KiCad like a Pro](http://txplore.tv/courses/kicad-pro) - course materials
* [KiCad](http://kicad-pcb.org/)
* [gerblook](http://gerblook.org/) - nice tool for testing a set of gerber files
* [OSH Park](https://oshpark.com/)
* [HARDWARE HANGOUT with James "Laen" Neal from OSH Park!](https://www.youtube.com/watch?v=XssjD97-xGM) - where I first learned of OSH Park

