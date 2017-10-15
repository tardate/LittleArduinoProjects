# #323 stringy

Building and playing (mainly playing) the Boldport Club Stringy (Project #14, June 2017).

Here's a quick video showing it in action..

[![Build](./assets/stringy_build.jpg?raw=true)](http://www.youtube.com/watch?v=pLeL9CwuKVM)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

Stringy synthesizes guitar sounds on a PIC microcontroller using MadLab's implementation of the
[Karplus–Strong](https://en.wikipedia.org/wiki/Karplus%E2%80%93Strong_string_synthesis)
string plucking algorithm.
It can play notes over five octaves.

Stringy is a remix of MadLab's 'Funky guitar'. The code is open source, so I think next up I'll attempt to compile and upload.

But for now, I'm too distracted just playing tunes;-)

### Parts and Unboxing


| Ref         | Part                                                        | Qty  |
|-------------|-------------------------------------------------------------|------|
| IC2         | PIC microcontroller, Microchip 12F1840-I/P                  | x1   |
| IC1         | 5V linear regulator, Taiwan Semiconductor TS78L05CT A3G     | x1   |
| Q1          | BJT npn transistor, Diotec BC547B                           | x1   |
| LED1        | 5mm blue LED, Kingbright L-9294QBC-D                        | x1   |
| S1,S2       | Tactile switch, TE Connectivity FSM4JRT                     | x2   |
| R1,2,4,6-18 | 1KΩ resistor, Multicomp MF25 1K                             | x17  |
| R5          | 47Ω resistor, Multicomp MF25 47R                            | x1   |
| R3          | 1MΩ resistor, Multicomp MF25 1M                             | x1   |
| C3          | 220µF electrolytic capacitor, Multicomp MCGPR16V227M6.3X11  | x1   |
| C1,C2       | 10µF electrolytic capacitor, Multicomp MCMR35V106M4X7       | x2   |
| C4,C5       | 0.1µF ceramic capacitor, Multicomp MC0805Y104M500A2.54MM    | x2   |
| J1          | 3.5mm jack socket, TruConnect 20-0137                       | x1   |
|             | Battery contact positive, TruPower 18-0596                  | x1   |
|             | Battery contact negative, TruPower 18-0597                  | x1   |
|             | 8-pin DIL socket, TruPower DS1009-08                        | x1   |
|             | piece of 20AWG hookup wire                                  | x1   |
|             | PCB                                                         | x1   |

![kit_parts](./assets/kit_parts.jpg?raw=true)


#### PIC12F1840 Specs

The [microchip PIC12F1840](http://www.microchip.com/wwwproducts/en/PIC12F1840) site has plenty of info and datasheets for the processor. The core specs:

* 7kb flash memory
* 256 bytes RAM
* 256 bytes EEPROM
* 5 I/O Pins and 1 Input-Only Pin
* 4 channels ADC (10-bit)
* 1 comparator
* 2 x 8-bit, 1 x 16-bit timers
* Internal 32MHz oscillator

![PIC12F1840_pinout](./assets/PIC12F1840_pinout.png?raw=true)

## Construction

![assembled_front](./assets/assembled_front.jpg?raw=true)

![assembled_rear](./assets/assembled_rear.jpg?raw=true)

![Build](./assets/stringy_build.jpg?raw=true)

## Schematic

![Schematic](./assets/stringy_schematic.jpg?raw=true)

## Credits and References
* [stringy](https://www.boldport.com/products/stringy/) - Boldport Product Page
* [stringy](http://community.boldport.club/projects/p14-stringy/) - on the community site
* [stringy software](https://github.com/boldport/stringy/tree/master/software)
* [Microchip PIC12F1840](http://www.microchip.com/wwwproducts/en/PIC12F1840) - product info and datasheet
* [MadLab's 'Funky guitar'](http://www.madlab.org/kits/guitar.html)
* [Karplus–Strong](https://en.wikipedia.org/wiki/Karplus%E2%80%93Strong_string_synthesis)
* [..as mentioned on my blog](http://blog.tardate.com/2017/06/leap323-boldport-club-stringy.html)
