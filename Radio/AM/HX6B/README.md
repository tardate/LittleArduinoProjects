# #123 HX-6B AM Receiver Kit

Build and analyse the HX-6B superheterodyne AM MW radio receiver kit.

![The Build](./assets/HX6B_build.jpg?raw=true)

## Notes

Just my notes on a build of [a HX-6B kit from a seller on aliexpress](https://www.aliexpress.com/item/DIY-Kits-Superheterodyne-Radio-Receiver-6-Transistor-sch-case-w-Speaker/32367150788.html).

A superheterodyne receiver (often shortened to superhet) uses frequency mixing to convert a received signal
(at a variable frequency)
to a fixed intermediate frequency (IF) which can be more conveniently processed with known gain and selectivity.

## Tutorials and Resources

Building and Aligning HX 6B AM Kit Radio by shango066

[![clip](https://img.youtube.com/vi/6rNbZj3tpOs/0.jpg)](https://www.youtube.com/watch?v=6rNbZj3tpOs)

## Parts

| Ref     | Part                        | Notes           |
|---------|-----------------------------|-----------------|
| V1,2,3  | 9018                        | NPN transistor  |
| V4      | 9014                        | NPN transistor  |
| V5,6    | 9013H                       | NPN transistor  |
| LED     | 3mm LED                     |   |
| T1      | transformer                 |   |
| T2,3,4  | transformer                 |   |
| T5      | transformer                 |   |
| BL      | 8Ω speaker                  |   |
| R6,8,10 | 100Ω resistor               |   |
| R7,9    | 120Ω resistor               |   |
| R11     | 330Ω resistor               |   |
| R2      | 1.8kΩ resistor              |   |
| R4      | 30kΩ resistor               |   |
| R5      | 100kΩ resistor              |   |
| R3      | 120kΩ resistor              |   |
| R1      | 200kΩ resistor              |   |
| RP      | 5kΩ pot                     |   |
| C6      | 0.47µF electrolytic cap     |   |
| C3      | 10µF  electrolytic cap      |   |
| C8,9,10 | 100µF electrolytic cap      |   |
| C2      | 682 6.8nF ceramic cap       |   |
| C1      | 103 10nF ceramic cap        |   |
| C4,5,7,11 | 223 22nF ceramic cap      |   |
| Ca,Cb   | CBM-223P variable capacitor |   |

![HX6B_unboxed](./assets/HX6B_unboxed.jpg?raw=true)

![HX6B_pcb_front](./assets/HX6B_pcb_front.jpg?raw=true)

![HX6B_pcb_back](./assets/HX6B_pcb_back.jpg?raw=true)

## Circuit Design

The HX6B is a superheterodyne design with a single IF stage. The design basically maps out as follows:

* RF Filter: T1, Ca antenna tuner
* RF amp: V1
* Local oscillator and Mixer: T2, Cb
* IF Filter and Amp: T3, V2
* Demodulator: T4, V3
* Audio amp: T5, V5, V6 push-pull class B

![The Schematic](./assets/HX6B_schematic.jpg?raw=true)

## Credits and References

* [the kit from a seller on aliexpress](https://www.aliexpress.com/item/DIY-Kits-Superheterodyne-Radio-Receiver-6-Transistor-sch-case-w-Speaker/32367150788.html)
* [Superheterodyne Receiver](https://en.wikipedia.org/wiki/Superheterodyne_receiver) - wikipedia
* [Introduction to the Superheterodyne Receiver](http://users.tpg.com.au/users/ldbutler/Superhet.htm) - by Lloyd Butler VK5BR
* [Block Diagram of Superheterodyne Receiver Radio](http://www.radio-electronics.com/info/rf-technology-design/superheterodyne-radio-receiver/block-diagram.php) - Ian Pool. A good description of the modules.
* [Radio Receivers Book - Chapter 4  Superheterodyne Radio Receivers](http://www.mikroe.com/old/books/rrbook/chapter4/chapter4a.htm) - Miomir Filipovic
* [Superheterodyne: BJT AM receiver](https://sites.google.com/site/linuxdigitallab/rf-ham-radio/superheterodyne-am-receiver-use-discrete-transistor) - fascinating project notes by He Yong Li
