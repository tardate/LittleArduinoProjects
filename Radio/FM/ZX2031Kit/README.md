# #515 ZX2031 FM Radio Kit

Building an FM radio kit based on the Silan SC1088 FM receiver chip.

![Build](./assets/ZX2031Kit_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/gSm3-48d0xQ/0.jpg)](https://www.youtube.com/watch?v=gSm3-48d0xQ)

## Notes

I'm a sucker for radio kits. This time I've picked up a small FM kit that has an attractively small circuit board
with primarily SMD components.

Most of the heavy lifting is performed by a single chip - the SC1088 in a SOP-16 package.

## Parts

| Ref | Description            | checked | installed |
|-----|------------------------|---------|-----------|
| IC1 | SC1088                 | √       | √         |
| V3  | 9014                   | √       | √         |
| V4  | 9012                   | √       | √         |
| V1  | BB910                  | √       | √         |
| V2  | LED 3mm red            | √       | √         |
| L1  | inductor bead          | √       | √         |
| L2  | choke                  | √       | √         |
| L3  | 78nH, 8 turns air core | √       | √         |
| L4  | 70nH, 5 turns air core | √       | √         |
| EJ  | headset                | √       | √         |
| R1  | 153 15KΩ               | √       | √         |
| R2  | 154 150kΩ              | √       | √         |
| R3  | 122 1.2kΩ              | √       | √         |
| R4  | 562 5.6kΩ              | √       | √         |
| R5  | 681 680Ω TH            | √       | √         |
| RP  | 51K                    | √       | √         |
| C1  | 222                    | √       | √         |
| C2  | 104                    | √       | √         |
| C12 | 104                    | √       | √         |
| C16 | 104                    | √       | √         |
| C10 | 104                    | √       | √         |
| C3  | 221                    | √       | √         |
| C5  | 221                    | √       | √         |
| C4  | 331                    | √       | v         |
| C6  | 332                    | √       | v         |
| C7  | 181                    | √       | √         |
| C8  | 681                    | √       | √         |
| C9  | 683                    | √       | √         |
| C11 | 223                    | √       | √         |
| C13 | 471                    | √       | √         |
| C14 | 33                     | √       | √         |
| C15 | 82pF                   | √       | √         |
| C17 | 332 ceramic            | √       | √         |
| C18 | 100µF electrolytic     | √       | √         |
| C19 | 223 ceramic            | √       | √         |

![kit_parts](./assets/kit_parts.jpg?raw=true)

![kit_pcb_front](./assets/kit_pcb_front.jpg?raw=true)

![kit_pcb_back](./assets/kit_pcb_back.jpg?raw=true)

## SC1088

The heart of the circuit is the Silan SC1088 FM receiver chip.

| Pin | Function | Description                                            |
|-----|----------|--------------------------------------------------------|
| 1   | Mute     | Mute output. Pull down to mute?                        |
| 2   | Voaf     | Audio out                                              |
| 3   | Loop     | AF loop filter                                         |
| 4   | Vp       | Power 1.8-5.0V                                         |
| 5   | Osc      | VCO control input                                      |
| 6   | IF Fb    | IF feedback                                            |
| 7   | Clp1     | Low-pass capacitor of 1dB amplifier                    |
| 8   | Voif     | IF output to external coupling capacitor(high-pass)    |
| 9   | Vif      | IF input to limiter amplifier                          |
| 10  | Clp2     | Low-pass capacitor of IF limiter amplifier             |
| 11  | Virf     | signal input 1                                         |
| 12  | Virf     | signal input 2                                         |
| 13  | Cilm     | Limiter offset voltage capacitor                       |
| 14  | Gnd      | Ground                                                 |
| 16  | Cap      | All-pass filter capacitor. Pull-down for tuning search |
| 16  | Tune     | Electrical tuning/AFC. Pull-down to reset tuning       |

![SC1088_block_diagram](./assets/SC1088_block_diagram.jpg?raw=true)

## BB910

The BB910 is a varactor diode, supplied in TO92 package. I couldn't find a corresponding datasheet for that package,
but tests as follows:

* anode: pin on the left of flat front
* cathode: pin on the right of flat front

## Circuit

The circuit is very similar to "Fig. 4 Application circuit with AFC for mechanical tuning" from the SC1088 datasheet.

![Schematic](./assets/ZX2031Kit_schematic.jpg?raw=true)

![kit_pcb_layout](./assets/kit_pcb_layout.jpg?raw=true)

## Construction Process

![build_1](./assets/build_1.jpg?raw=true)

![Build](./assets/ZX2031Kit_build.jpg?raw=true)

![build_2](./assets/build_2.jpg?raw=true)

## Credits and References

* [Original source](https://item.taobao.com/item.htm?id=549629110893) - taobao
* [SC1088 datasheet](https://www.digchip.com/datasheets/parts/datasheet/433/SC1088-pdf.php)
* [BB910 datasheet](https://www.digchip.com/datasheets/parts/datasheet/364/BB910.php)
