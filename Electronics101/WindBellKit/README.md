# #639 Wobbly Wind Bell Kit

Building the Wobbly Wind Bell demonstrating a simple RC oscillator circuit. Available as a cheap project kit from many online sellers.

![Build](./assets/WindBellKit_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/CoDeYtJtk-c/0.jpg)](https://www.youtube.com/watch?v=CoDeYtJtk-c)

## Notes

### The Kit

The [Wobbly Wind Bell Kit](https://www.aliexpress.com/item/4001116940559.html) is available from many sellers on aliexpress

![kit_parts](./assets/kit_parts.jpg)

### Packing List

| Qty | Refs   | Description                             |
|-----|--------|-----------------------------------------|
| 80  |        | Blue LED 3mm |
| 5   |        | Green LED 3mm |
| 10  |        | Red LED 3mm |
| 25  |        | 50Ω resistor |
| 3   |        | 150kΩ resistor |
| 2   |        | 10µF electrolytic capacitor |
| 2   |        | S9013 NPN Transistor |
| 1   |        | STDP switch |
| 1   |        | 3.5mm power jack |
| 1   |        | USB to 3.5mm power cable |
| 1   |        | PCB |

### Circuit Design

The circuit uses a simple oscillator to switch between two banks of LEDs.
The circuit is similar to that demonstrated in
[LEAP#049 BJT RC Oscillator](./../Oscillators/BjtRcOscillator/).

PCB layout:

![kit_pcb](./assets/kit_pcb.jpg)

Here's a quick redraw of the circuit in Fritzing:

![bb](./assets/WindBellKit_bb.jpg?raw=true)

![schematic](./assets/WindBellKit_schematic.jpg?raw=true)

### Build Log

After initial construction, quite a number of the LEDs failed.
It seems that the components provided in the kit were not good quality.

![test01a](./assets/test01a.jpg)
![test01b](./assets/test01b.jpg)

After replacing the failed LEDs with components from stock, all is working correctly:

![build02a](./assets/build02a.jpg?raw=true)
![build02b](./assets/build02b.jpg?raw=true)

The completed board:

![build01a](./assets/build01a.jpg?raw=true)

## Credits and References

* [laboratory Swing bells Wobbly Windbell Fun Electronic DIY Kit Wring 95 LEDs Wind bell 5V 9V](https://www.aliexpress.com/item/4001116940559.html) - one of many sellers on aliexpress
* [S9013 NPN Transistor](https://www.futurlec.com/Transistors/S9013.shtml)
* [LEAP#049 BJT RC Oscillator](./../Oscillators/BjtRcOscillator/)
