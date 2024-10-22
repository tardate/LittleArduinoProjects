# #392 whiteboard

Building the Whiteboard - Boldport Club project #22 - a breadboard enhancer featuring power supply and prototyping areas.

![Build](./assets/whiteboard_build.jpg?raw=true)

Here's a quick demo running a CD4060 ripple counter on the breadboard..

[![clip](https://img.youtube.com/vi/eiEX9SPuRhI/0.jpg)](https://www.youtube.com/watch?v=eiEX9SPuRhI)

## Notes

The whiteboard is a neat little "breadboard enhancer". It includes:

* a prototyping shroud for a mini breadboard, including 4 LEDs and various pads for other components and connections
* a variable power supply unit, based on the LM317
* a CR2032 coin cell power supply unit
* a 6-pin DIP adapter for 3 x 0805/1206 SMD components (e.g. LEDs, diodes or passives) or 2 x SOT23 SMD components (e.g. transistors/FETs)


## Kit Components

The project includes the following components

| Qty | Component                                              |
|-----|--------------------------------------------------------|
| 1x  | 170-point breadboard, Pro-Signal PSG-BB-170W           |
| 1x  | Adjustable regulator, TI LM317KCS                      |
| 1x  | 2032 battery holder, Multicomp BC-2001                 |
| 1x  | 6-way socket, TruConnect DS1023-1*6 S01                |
| 1x  | 5-way header, Multicomp MC34739                        |
| 1x  | 2.1mm power socket, TruConnect, 20-0970                |
| 1x  | 2KΩ trimmer, TE Connectivity 416XA202P                 |
| 1x  | Resettable 100mA fuse, Multicomp MC33169               |
| 2x  | 10µF electrolytic capacitors, Multicomp MCMR35V106M4X7 |
| 1x  | 100nF ceramic capacitor , Suntan TS15001E104MSBFBOR    |
| 3x  | 1A diode, Diodes 1N4001-T                              |
| 4x  | 3mm white LEDs, Valcon VDIFFLED-3MM-W                  |
| 1x  | 220Ω resistor, Multicomp MCF 0.25W 220R                |

![kit_parts](./assets/kit_parts.jpg?raw=true)

Also included is a sheet of **StickerCAD** icons.
I used them on my laptop case - including a rebus if you look carefully;-)

![join_the_resistors](./assets/join_the_resistors.jpg?raw=true)

## Construction

I've yet to decide what component(s) I'll put on the DIP adapter. But power supply boards
are complete and working perfectly.

![whiteboard_build_complete](./assets/whiteboard_build_complete.jpg?raw=true)

As a quick demonstration and test, I put a simple 4-stage CD4060 ripple counter
running at a base frequency of around [10 Hz](https://www.wolframalpha.com/input/?i=1%2F(2*5*(1%C2%B5F*10k%CE%A9))).
on the breadboard, with outputs driving the LEDs on the shroud (essentially a 4-digit binary counter).

![Breadboard](./assets/whiteboard_bb.jpg?raw=true)

![Schematic](./assets/whiteboard_schematic.jpg?raw=true)

![Build](./assets/whiteboard_build.jpg?raw=true)

## Credits and References

* [Whiteboard](http://www.boldport.club/shop/product/1296464803) - in the Boldport Club shop
* [Whiteboard](http://www.boldport.com/whiteboard) - Boldport Club page
* [LM317 datasheet](https://www.futurlec.com/Linear/LM317T.shtml)
* [CD4060 datasheet](https://www.futurlec.com/4000Series/CD4060.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2018/05/leap392-boldportclub-whiteboard.html)
