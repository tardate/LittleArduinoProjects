# #664 Light Control Switch Kit

Building an LDR-controlled relay kit with hysteresis/delay for on and off transitions (LM393 comparator with RC-dampened inputs).

![Build](./assets/LightControlSwitchKit_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/vmtjgMmfmIM/0.jpg)](https://www.youtube.com/watch?v=vmtjgMmfmIM)

## Notes

Another cheap little kit from
[aliexpress](https://www.aliexpress.com/item/1005001714076544.html). I love'em!

This circuit demonstrates how to use a light-dependent resistor to switch a heavy lead (via a relay),
but with a dampening delay implemented with an RC circuit squashing the inputs to an LM393 comparator.

### The Kit

From [aliexpress](https://www.aliexpress.com/item/1005001714076544.html), but probably widely available with similar specs.

![kit_parts](./assets/kit_parts.jpg?raw=true)

![pcb](./assets/pcb.jpg?raw=true)

### Parts

| Ref    | Item                                            | Qty   |
|--------|-------------------------------------------------|-------|
| R1     | 4.7kΩ                                           | 1 |
| R4,6   | 10kΩ                                            | 2 |
| R3     | 10kΩ pot                                        | 1 |
| D3     | 1N4007                                          | 1 |
| Q1,2   | 805                                             | 2 |
| C1     | 104, 100nF                                      | 1 |
| C2     | 10µF                                            | 1 |
| J1,2   | 2 x 2pin headers                                | 4p |
| J4     | KF301-3P, 3pin terminal block (missing/not included in the kit) | 1 |
| R2     | 510kΩ                                           | 1 |
| R5,7   | 2.2kΩ                                           | 2 |
| D1     | Red LED 5mm                                     | 1 |
| D2     | Green LED 5mm                                   | 1 |
| U1     | LM393                                           | 1 |
| U1     | DIP8 socket                                     | 1 |
| J3     | DPDT switch                                     | 1 |
| K1     | relay                                           | 1 |
| J2     | LDR                                             | 1 |
|        | PCB                                             | 1 |

### Circuit Design

![LightControlSwitchKit_bb](./assets/LightControlSwitchKit_bb.jpg?raw=true)

![schematic](./assets/LightControlSwitchKit_schematic.jpg?raw=true)

## Credits and References

* [Light Control switch diy kit street lamp stair automatic control switch electronic welding circuit board student Laboratory](https://www.aliexpress.com/item/1005001714076544.html) - aliexpress
* [LM393](http://www.ti.com/product/LM393) Dual Differential Comparator
* [S8050 Datasheet](http://electronics.se-ed.com/magic/s8050.pdf) - NPN BJT
