# #584 HPDL-1414

Test driving a retro HPDL-1414 4-digit GaAsP display with an Arduino.

![Build](./assets/HPDL1414_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/AvIznKRom1c/0.jpg)](https://www.youtube.com/watch?v=AvIznKRom1c)

## Notes

The HPDL-1414 is a smart, four character, sixteen-segment, red GaAsP display.
The on-board CMOS IC contains memory, ASCII decoder, multiplexing circuitry and drivers.

* Supply Voltage : 4.5-5.5V
* Macimum current: 90mA
* Character height: 2.85 mm (0.112").

The real beauty of this "old fashioned" display is the immersion lens that magnifies the red GaAsP segments nicely.

### Module Connection

| Function | HPDL1414 Pin | Arduino Pin |
|----------|--------------|-------------|
| D5       | 1            |        D7   |
| D4       | 2            |        D6   |
| !WE      | 3            |        A0   |
| A1       | 4            |        A2   |
| A0       | 5            |        A1   |
| Vcc      | 6            |        5V   |
| GND      | 7            |       GND   |
| D0       | 8            |        D2   |
| D1       | 9            |        D3   |
| D2       | 10           |        D4   |
| D3       | 11           |        D5   |
| D6       | 12           |        D8   |

![module_pins](./assets/module_pins.jpg?raw=true)

## Construction

![Breadboard](./assets/HPDL1414_bb.jpg?raw=true)

![Schematic](./assets/HPDL1414_schematic.jpg?raw=true)

## Programming

Using the [HPDL1414 Arduino Library](https://github.com/marecl/HPDL1414).

The character set is quite limited, and custom glyphs are not supproted

![charset](./assets/charset.jpg?raw=true)

## Credits and References

* [HPDL1414 datasheet](http://www.farnell.com/datasheets/76528.pdf) (farnell)
* [100pcs X HPDL-1414 HPDL1414 Four character smart digital display. Digital Tube](https://www.aliexpress.com/item/32920650954.html)
* [HPDL1414 Arduino Library](https://github.com/marecl/HPDL1414)
* [Using Ancient Litronix DL-1414 LED Displays With an Arduin](https://softsolder.com/2009/08/05/arduino-using-ancient-litronix-dl-1414-led-displays/)
