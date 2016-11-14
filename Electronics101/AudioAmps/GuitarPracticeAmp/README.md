# #249 AudioAmps/GuitarPracticeAmp

Single-channel 10W guitar practice amplifier based on the TDA2050

![The Build](./assets/GuitarPracticeAmp_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

This is a 10W guitar practice amplifier circuit and was designed for the
[Fundamentals of Audio and Music Engineering: Part 1 Musical Sound & Electronics](https://www.coursera.org/learn/audio-engineering)
course offered by University of Rochester on Coursera.

The amplifier itself is designed to teach about simple tone and distortion circuitry.


### Parts

| ID           | Qty | Value               |
|--------------|-----|---------------------|
| R1 R3 R4     | 3   | 1 MΩ                |
| R2           | 1   | 5.6 kΩ              |
| R5           | 1   | 1 kΩ                |
| R7 R14 R16   | 1   | 22 kΩ               |
| R6           | 1   | 4.7 kΩ              |
| R15          | 1   | 2.2 kΩ              |
| R9           | 1   | 100 kΩ              |
| R8           | 1   | 10 kΩ               |
| R13          | 1   | 1 Ω                 |
| R10          | 1   | B50KΩ pot           |
| R11          | 1   | B10KΩ pot           |
| R12          | 1   | A10KΩ pot           |
| C2           | 1   | 47nF 473            |
| C10          | 1   | 100nF 104           |
| C3           | 1   | 10nF 103            |
| C7           | 1   | 220nF 224           |
| C9           | 1   | 100µF electrolytic  |
|￼C8           | 1   | 1000µF electrolytic |
|￼C1 C4 C5 C11 | 4   | 1µF electrolytic    |
| C6           | 1   | 10µF electrolytic   |
| U1           | 1   | TL072 DIP8          |￼￼￼
| U2           | 1   | TDA2030             |￼￼￼
| D1 D2        | 2   | 1N4001              |
| LED1         | 1   | 3mm Red LED         |
| SPKR1        | 1   | 4Ω 10W              |
| S1           | 1   | SPDT switch         |
| J1           | 1   | 12V power connector |
| J2           | 1   | 6.35mm mono socket  |

Hardware and other parts:

*￼DIP8 IC socket (for the TL072)
* SPDT power switch
* 2.1mm power jack
* 12V DC power supply
* 1⁄4” Phono plug
* speaker
* perfboard/PCB

### Cabinet Design - TODO

Some reasonable dimensions:

1. A well rounded frequency response translates to a cabinet volume of roughly 5832 cm^3, or interior dimensions of 18 cm x 18 cm x 18 cm.
2. For a bass heavy amplifier, a cabinet volume of roughly 2754 cm^3 will work better. This corresponds to interior dimensions of 18cm x 18cm x 8.5cm.

Styrofoam board can be used for a quick build, but a wooden case will sound slightly better.


### Performance

Sample oscilloscope trace:

* 12V power
* CH1: input (1kHz, 20mV sine)
* CH2: output, minimum gain & tone

![scope_1khz_20mv](./assets/scope_1khz_20mv.gif?raw=true)

## Construction

![Breadboard](./assets/GuitarPracticeAmp_bb.jpg?raw=true)

![Schematic](./assets/GuitarPracticeAmp_schematic.jpg?raw=true)

![GuitarPracticeAmp_protoboard_layout](./assets/GuitarPracticeAmp_protoboard_layout.jpg?raw=true)

![Build](./assets/GuitarPracticeAmp_build.jpg?raw=true)

## Credits and References
* [Fundamentals of Audio and Music Engineering: Part 1 Musical Sound & Electronics](https://www.coursera.org/learn/audio-engineering)
* [TDA2050 datasheet](http://parts.io/detail/1583208/TDA2050V)
* [TL072 datasheet](http://parts.io/detail/12204535/TL072)
