# #291 CD4060/MusicLightKit

Learning how to use the CD4060 14-Stage Ripple Carry Binary Counter by building a music/LED-effects kit.

Here's a quick demo of the LED sequence in action..

[![Build](./assets/MusicLightKit_build.jpg?raw=true)](http://www.youtube.com/watch?v=oUgnn1maLc8)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This is a pretty common kit widely available from sellers on [aliexpress](https://www.aliexpress.com/item/CD4060-Dream-Music-Light-DIY-Kit-Birthday-Gift-Suite-Electronic-Production-of-DIY-Parts/32748833397.html), ebay and other outlets.
It comes in a few variations, but essentially all the same circuit.

It is an interesting demonstration of the CD4060 14-Stage Ripple Carry Binary Counter.

The kit includes a potted sound chip that plays "Happy Birthday". The music circuit runs completely independently of the CD4060-driven LED circuit.


### Julian Ilett's Build

This is the same kit covered by Julian Ilett:

[![Kit Build](http://img.youtube.com/vi/AJFLz_hQsjo/0.jpg)](http://www.youtube.com/watch?v=AJFLz_hQsjo)


### CD4060 Ripple Counter

The CD4060 is a 14 stage ripple counter constructed of RS flip-flop units - see the functional diagram from the datasheet:

![CD4060_functional](../assets/CD4060_functional.png?raw=true)

The CD4060 in this circuit is configured as a free-running counter, driven by an RC oscillator.
I investigated this technique in more detail in [LEAP#293 CD4060/RCOscillator](../RCOscillator).

As the oscillator triggers the CD4060, the outputs cycle/ripple. The circuit only uses three significant outputs: Q5, Q6, Q7.
These are steered with diodes to drive the three LED combinations. Q7 also triggers reset on the CD4060 to restart the sequence.

### Music Effects Chip

The music chip included in my kit is marked "H823" and plays "Happy Birthday". This appears to be a different chip
from the one included in [Julian Ilett's build](http://www.youtube.com/watch?v=AJFLz_hQsjo),
and doesn't suffer from the same problem of needing an extra base resistor for the transistor output.

However the piezzo speaker included in the kit sounds terrible; it works much better with a speaker.
But since there is no room on the board for a speaker, I decided not to build the music circuit in this kit.

Instead I've tested the H823 chip in a separate project -
[LEAP#292: AudioEffectsChips/H823](../../AudioEffectsChips/H823).

## Parts

| Ref     | Item                  | Qty |
|---------|-----------------------|-----|
| IC2     | CD4060                |   1 |
| LED1-4  | Red 5mm LED           |   4 |
| LED5-8  | Yellow 5mm LED        |   4 |
| LED9-12 | Green 5mm LED         |   4 |
| D2,3,4  | 1N4148                |   3 |
| Q2,3,4  | S9012 PNP Transistors |   3 |
| R5-15   | 200Ω                  |  12 |
| R3      | 200kΩ linear pot      |   1 |
| R4      | 220kΩ                 |   1 |
| R2      | 10kΩ                  |   1 |
| R1      | 1.5MΩ                 |   1 |
| C1      | 1µF electrolytic      |   1 |
|         | Piezzo Buzzer         |   1 |
|         | H823 Music Chip       |   1 |
|         | DPDT Switch           |   1 |
|         | mini USB socket       |   1 |
|         | XH2.54 2 pin socket   |   1 |
|         | C1815 NPN             |   1 |

![kit_parts](./assets/kit_parts.jpg?raw=true)

![kit_pcb_front](./assets/kit_pcb_front.jpg?raw=true)

![kit_pcb_rear](./assets/kit_pcb_rear.jpg?raw=true)

## Schematic

This is the schematic available from most vendors:

![vendor_schematic](./assets/vendor_schematic.jpg?raw=true)

## Construction

![Breadboard](./assets/MusicLightKit_bb.jpg?raw=true)

![Schematic](./assets/MusicLightKit_schematic.jpg?raw=true)

![Build](./assets/MusicLightKit_build.jpg?raw=true)

## Credits and References
* [CD4060 Dream Music Light DIY Kit](https://www.aliexpress.com/item/CD4060-Dream-Music-Light-DIY-Kit-Birthday-Gift-Suite-Electronic-Production-of-DIY-Parts/32748833397.html) - from a seller on aliexpress
* [C1815 datasheet](http://www.futurlec.com/Transistors/C1815.shtml)
* [S9012 datasheet](http://www.futurlec.com/Transistors/S9012.shtml)
* [CD4060 datasheet](http://www.futurlec.com/4000Series/CD4060.shtml)
* [1N4148 datasheet](http://www.futurlec.com/Diodes/1N4148.shtml)
* [LEAP#292 AudioEffectsChips/H823](../../AudioEffectsChips/H823) - testing the music chip that came with this kit
* [LEAP#293 CD4060/RCOscillator](../RCOscillator) - testing an CD4060 driven by an RC oscillator
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap291-cd4060-music-light-kit.html)
