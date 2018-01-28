# #284 TheGent

The Gent is Boldport Club Project #10 - a simple circuit on a beautiful board

![Build](./assets/TheGent_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes


### Unboxing and Parts


| Ref    | Item                                                | Count |
|--------|-----------------------------------------------------|-------|
| S1     | DPDT slide switch, C&K JS202011SCQN                 |    x1 |
| D1     | 5mm phototransistor, Kingbright PT333-3C            |    x1 |
| L1,3,5 | Green 5mm LED, Kingbright L-9294CGCK                |    x3 |
| L2,4   | Orange 5mm LED, Kingbright L-9294SECK               |    x2 |
|        | CR2032 battery clip, Multicomp BC-2001              |    x1 |
| Q1     | N-channel MOSFET, Fairchild 2N7000                  |    x1 |
| R1-8   | 390Ω through-hole resistor, Multicomp MCF 0.25W 10K |    x8 |
| R9     | 820Ω through-hole resistor, Multicomp MF25 820R     |    x1 |
| R10    | 10KΩ through-hole resistor, Multicomp MF25 390R     |    x1 |

![kit_unboxing](./assets/kit_unboxing.jpg?raw=true)

The five clear LEDs are actually two colours: a perfect time to whip out the
[LIGEMDIO](../ligemdio) project for some LED testing:

![kit_testing_leds_with_ligemdio](./assets/kit_testing_leds_with_ligemdio.jpg?raw=true)


### Phototransistor Connections

Note that the [PT333-3C Phototransistor](https://www.rapidonline.com/pdf/156408-da-02-en.pdf)
uses a familiar 5mm LED packaging, but the collector/emitter pins are the reverse of what you might
intuit. The short leg and flat edge are actually the collector and is connected to the positive supply side.

![PT333-3C](./assets/PT333-3C.png?raw=true)


### Completed Build


![kit_complete](./assets/kit_complete.jpg?raw=true)


![Build](./assets/TheGent_build.jpg?raw=true)


### Schematic

![Breadboard](./assets/TheGent_bb.jpg?raw=true)

![Schematic](./assets/TheGent_schematic.jpg?raw=true)


## Credits and References
* [TheGent](http://www.boldport.club/shop/product/584348507) - in the Boldport shop
* [TheGent](https://www.boldport.com/gent) - Boldport project page
* [TheGent](https://github.com/boldport/thegent) - OSH files on GitHub
* [TheGent](http://community.boldport.club/projects/p10-thegent/) - club community site, packed with resources for the project
* [Eurocircuits](http://www.eurocircuits.com/) - manufactured the board
* [PT333-3C datasheet](https://www.rapidonline.com/pdf/156408-da-02-en.pdf)
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap284-the-boldport-gent.html)
