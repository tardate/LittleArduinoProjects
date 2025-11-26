# #700 Laser Harp Kit

Build and test an 8051-based laser harp kit.

![Build](./assets/LaserHarpKit_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/pun0ajSLT4o/0.jpg)](https://www.youtube.com/watch?v=pun0ajSLT4o)

## Notes

There's a common C51-based "laser harp" kit that is available
in various packagings from sellers on
[aliexpress](https://www.aliexpress.com/item/1005004398932678.html),
[icstation](http://www.icstation.com/laser-harp-string-electronic-keyboard-module-electric-production-sensor-music-controller-p-13056.html)
and other market-places.

I picked up one of the kits from an aliexpress seller to check it out.
There are various build and demo videos out there, for example:

[![clip](https://img.youtube.com/vi/oxEwQ6zpCVA/0.jpg)](https://www.youtube.com/watch?v=oxEwQ6zpCVA)

### Parts

The kit comes with all the parts needed to build the harp, including USB power cable and speaker.
Note: in the final build, I replaced the speaker with a piezo buzzer - the sound quality is not much different!

| Item                 | Qty |  Ref             |
|----------------------|-----|------------------|
| 1kΩ                  | 11  |  R1-7, R16-19    |
| 10kΩ                 | 8   |  R8-15           |
| 30pF                 | 2   | C3-4             |
| 10µF                 | 2   | C5-6             |
| 12MHz crystal        | 1   | Y1               |
| 3mm blue LED         | 10  | D1-10            |
| STC89C52             | 1   | U1               |
| 50 pin DIP socket    | 1   | U1               |
| wire                 | 2   | U1               |
| 40mm copper pillar   | 2   | U1               |
| speaker              | 1   | SPK              |
| 5V laser             | 7   | JG1-7            |
| power jack           | 1   | DC002            |
| USB power cable      | 1   |                  |
| 8550  PNP            | 1   | Q1               |
| 5516 LDR             | 7   | GM1-7            |
| pushbutton           | 2   | K1-2             |
| small copper pillar  | 4   |                  |
| DPDT switch          | 1   | KG               |
| screw                | 4   |                  |

### Circuit Design

The circuit is quite straight-forward:

* 7 lasers are pointed at 7 LDRs monitored by 7 GPIO ports
* 2 switches are wired to GPIO ports
* the microcontroller polls/reads the LDR inputs and switches
* the microcontroller generates the appropriate sound output (square wave)

Here is a transcription of the circuit in Fritzing:

![bb](./assets/LaserHarpKit_bb.jpg?raw=true)

![schematic](./assets/LaserHarpKit_schematic.jpg?raw=true)

### Testing the Behaviour

The two buttons control the mode of the harp:

* K1: play a tune. Rotates between "Happy Birthday" and a Chinese nursery rhyme "世上只有妈妈好" (Mother is the Best)
* K2: selects between 3 note ranges octaves (low, medium, high)

The output frequencies:

| Note | Octave 1 | Octave 2 | Octave 2 |
|------|----------|----------|----------|
| 1    |      141 |      281 |      561 |
| 2    |      153 |      317 |      627 |
| 3    |      178 |      355 |      705 |
| 4    |      187 |      375 |      740 |
| 5    |      211 |      421 |      837 |
| 6    |      237 |      473 |      937 |
| 7    |      266 |      530 |     1047 |

Here are some sample scope traces of the lowest and highest notes in the first octave:

![scope-oct1_1](./assets/scope-oct1_1.gif?raw=true)

![scope-oct1_7](./assets/scope-oct1_7.gif?raw=true)

### Conclusion

After playing around for a few minutes, a couple of limitation are quite apparent:

* why 7 notes?? There are plenty of spare GPIO pins, so why not 8 for a full octave?
* tuning: I don't think the note frequencies match standard tuning
* button responsiveness: the code doesn't handle concurrently pressing the range button and playing a note, making it very hard to play a tune across multiple octaves
* "string" sensitivity: it does not appear very responsive to making/breaking contact with a laser

### Next Steps?

I haven't found the 8051 source code or tried to download it from the chip.
However given the problems with the laser harp - most of which can be solved in code - I don't think that's a big loss.

The obvious next step is to redo this project but with:

* 8 lasers/notes
* new code that is more responsive and handles concurrent button presses while playing a note. Maybe attempt this with 8051, or switch to an AVR/Arduino.

## Credits and References

* [DIY Kit C51 MCU Laser Harp Kit String DIY Keyboard Kit Electronic Parts 7 Strings Electronic DIY Kit Technology Piano Music Box](https://www.aliexpress.com/item/1005004398932678.html) - aliexpress
* [DIY Kit C51 MCU Laser Harp Kit String Electronic Keyboard Kit DIY Module Electric Production Sensor Music Controller](http://www.icstation.com/laser-harp-string-electronic-keyboard-module-electric-production-sensor-music-controller-p-13056.html) - same product from icstation
* [STC89Cxx series MCU Data Sheet](https://www.stcmicro.com/datasheet/STC89C51RC-en.pdf)
