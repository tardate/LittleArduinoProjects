# #419 lite2sound-bc

Building Lite2Sound Boldport Club Project #26.

![Build](./assets/lite2sound-bc_build.jpg?raw=true)

Here's a quick demo..

[![clip](http://img.youtube.com/vi/video_id/0.jpg)](http://www.youtube.com/watch?v=video_id)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

Lite2Sound BC is the 26th Boldport project, and is a collaboration with [Rare Waves LLC](http://rarewaves.net/).

It uses a photodiode to detect audio-frequencies from light, which are amplified and piped to an audio jack (or optionally to direct line-out).

Best of all - it comes in an Altoids-sized can!

See the [LEAP#420 CuttleTalk](./CuttleTalk) project for a full demo of the finished thing.

## The Kit

| Qty | Ref      | Item                                                     |
|-----|----------|----------------------------------------------------------|
| x3  | C1,3,4   | 10µF electrolytic capacitors, Nichicon UWX1C100MCL2GB    |
| x2  | C9,11    | 220µF electrolytic capacitors,Multicomp MCVVT016M221EA6L |
| x2  | C5,6     | 220pF C0G ceramic capacitors, Multicomp MC1206N221J500CT |
| x3  | C2,7,10  | 100nF ceramic capacitors, Kemet C1206S104K5RACTU         |
| x3  | R7       | 10Ω resistors, Walsin WR12X10R0FTL                       |
| x3  | R3,4     | 220Ω resistors, Walsin WR12X2200FTL                      |
| x3  | R1,2,9   | 20KΩ resistors, Walsin WR12X2002FTL                      |
| x3  | R5,6     | 2MΩ resistors, Walsin WR12W2004FTL                       |
| x1  | D2       | Schottky diode, Diodes 1N5819HW-7-F                      |
| x1  |          | Photodiode, On Semi QSD2030F                             |
| x1  | D1       | Photodiode, On Semi QSD2030                              |
| x1  | IC1      | Low noise op-amp, Diodes TL072SG-13                      |
| x1  | IC2      | Power amplifier, TI LM386MX-1/NOPB                       |
| x1  |          | 3.5mm stereo socket, TruConnect PJ-301DM                 |
| x1  | VR1      | 50kΩ pot, Suntan TSR3386F-EY5-503-TR                     |
| x2  | SW1,SW2  | Switch, C&K JS202011SCQN                                 |
| x1  |          | Battery contact positive, MPD BSPCF                      |
| x1  |          | Battery contact negative, MPD BSPCM                      |
| x3  |          | 12.7mm self-adhesive feet, RVFM PD.2125                  |
| x1  |          | Lovely PCB                                               |
| x1  |          | Metal enclosure with a hole                              |
| x1  |          | Light blocking sticker for tin                           |

Note: some resistors are provided in extra quantity than is required, and there are
two versions of the photodiode.


![kit_parts](./assets/kit_parts.jpg?raw=true)

As uaual, a beautiful PCB designed by Boldport:

![kit_pcb_front](./assets/kit_pcb_front.jpg?raw=true)
![kit_pcb_rear](./assets/kit_pcb_rear.jpg?raw=true)


### Two Photodiodes?

The kits comes with a choice of two photodiodes: QSD2030 and QSD2030F.
These are basically identical, but the QSD2030F is in black epoxy which provides a daylight filter.
A daylight filter is intended to attenuate the effect of outdoor/sunlight and prevent it overwhelming
other signals (from reports: [YMMV](https://www.electronicspoint.com/threads/photodiode-daylight-elimination.259609/))

QSD2030

* Wide reception angle: 40°
* Package material and color: clear epoxy
* High sensitivity
* Peak sensitivity λ = 880nm

QSD2030F

* Wide reception angle: 40°
* Daylight Filter
* Package material and color: Black Epoxy
* High Sensitivity
* Peak sensitivity λ = 880nm

I'm not planning extensive outdoor usage, so I built the kit with the standard QSD2030 without daylight filter.



## Construction Tips from BC Slack!

> …oh, the feet go on the _tin_. This sense makes (@kpreid)

.. saved me doing something stupid.


> the board with this kit seemed to absorb _a lot_ of heat when I hit it with hot air. took some time to heat up (@kbx81)

.. I used hot air for the SMD assembly, but didn't have similar issues.


## Circuit

As provided by Boldport. Note: it doesn't show SW1 (on/off), which is positioned after
the reverse-poliarity protection diode D2.

![Schematic](https://static1.squarespace.com/static/539604e8e4b0d1f9ffe9ff0b/t/5b17a53570a6ad549b443918/1530529918270/Lite2Sound_BC_schematic.png?format=2500w)

I used hot-air for SMD soldering, and an iron with my favourite 2% Ag solfer for through-hole components and wires.

![build_top](./assets/build_top.jpg?raw=true)
![build_bottom](./assets/build_bottom.jpg?raw=true)

With stickers attached to the case:

![build_case_top](./assets/build_case_top.jpg?raw=true)
![build_case_bottom](./assets/build_case_bottom.jpg?raw=true)


## Credits and References
* [Lite2Sound BC](https://www.boldport.com/products/lite2sound-bc) - product page
* [Photodiode Daylight elimination](https://www.electronicspoint.com/threads/photodiode-daylight-elimination.259609/)
* [..as mentioned on my blog](https://blog.tardate.com/2018/10/leap419-boldport-lite2sound.html)
