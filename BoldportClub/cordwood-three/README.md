# #411 cordwood-three

Custom build of the Boldport Club Cordwood Puzzle III, Project #25, May 2018, with an archway layout and a spring-loaded LED trigger machanism.

![Build](./assets/cordwood-three_build.jpg?raw=true)

Here's a quick demo of the build on a custom test jig "LED Blinky Machine"..

[![clip](https://img.youtube.com/vi/ol5FfNbUmC8/0.jpg)](https://www.youtube.com/watch?v=ol5FfNbUmC8)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This is the third Boldport Club project in the Cordwood series.
See my build of the [first](../cordwood) and [second](../cordwood-too).
Here they are all together:

![cordwood_series](./assets/cordwood_series.jpg?raw=true)

## The Kit

The kit arrrived in the familar brown paper

![kit_arrival](./assets/kit_arrival.jpg?raw=true)

![kit_parts](./assets/kit_parts.jpg?raw=true)

If you want to build this kit, the easiest way is to join the club and order the [BoldportClub kit](https://www.boldport.com/products/cordwood-puzzle-three).
But you could do it without the kit:
the [PCB design is open source](https://github.com/boldport/cordwood-three) so it is relatively easy to make an identical (or similar) set of boards,
and the parts are relatively easy to obtain:

| Qty | Original Part                                                                        | Mouser Equivalent |
|-----|--------------------------------------------------------------------------------------|-----------------------|
| x6  | 220Ω 2W resistor, [Multicomp MCF 2W 220R](http://uk.farnell.com/9338152)             | [603-RSF2WSJR-52-220R](https://www.mouser.com/ProductDetail/Yageo/RSF2WSJR-52-220R?qs=sGAEpiMZZMtlubZbdhIBIFynSgUwx%2fG%2fVcNTMKWkBVc%3d) |
| x6  | 10KΩ 2W resistor, [Multicomp MCF 2W 10K](http://uk.farnell.com/9338063)              | [588-OY-10K-E](https://www.mouser.com/ProductDetail/Ohmite/OY103KE?qs=sGAEpiMZZMtlubZbdhIBIENcR%2f1aUFb0kWRlpIpjQPo%3d) |
| x6  | MOSFET n-channel transistor, [Fairchild 2N7000_D26Z](http://uk.farnell.com/1467958)  | [512-2N7000](https://www.mouser.com/ProductDetail/ON-Semiconductor/2N7000?qs=sGAEpiMZZMshyDBzk1%2fWi9bHELEahoDnY1fyKF6A6Ko%3d) |
| x1  | 1µF ceramic capacitor, [AVX SA305E105MARC](http://uk.farnell.com/1100420)            | [80-C440C105Z5U-TR](https://www.mouser.com/ProductDetail/KEMET/C440C105Z5U5TA7200?qs=sGAEpiMZZMt3KoXD5rJ2N1KrDHDg1VQtN0J20Zv5eAs%3d) |
| x6  | 10mm green LEDs, [Kingbright L-813GD](http://uk.farnell.com/1142462)                 | [696-SSLLX100133SGD](https://www.mouser.com/ProductDetail/Lumex/SSL-LX100133SGD?qs=sGAEpiMZZMvHYEB9WUp7ElLqM0HAvqw0twtzB6l130A%3d) |
| x1  | 25mm M3 female-female standoff, [ETTINGER 05.03.251](http://uk.farnell.com/1466783)  | [761-M1272-3005-SS](https://www.mouser.com/ProductDetail/RAF-Electronic-Hardware/M1272-3005-SS?qs=sGAEpiMZZMtrde5aJd3qwxLSm3K1%252btbtQheXQAV4RR4%3d) |
| x1  | 25mm M3 female-male standoff, [ETTINGER 05.13.251](http://uk.farnell.com/1466786)    | [761-M2120-3005-SS](https://www.mouser.com/ProductDetail/RAF-Electronic-Hardware/M2120-3005-SS?qs=sGAEpiMZZMtrde5aJd3qwxLSm3K1%252btbtlmbMF%2f0uUho%3d) |
| x2  | M3 screws, [DURATOOL M38 CSSTMCZ100-](http://uk.farnell.com/1419786)                 | |
| x1  | 10-pin 2.54mm header, [Multicomp MC34739](http://uk.farnell.com/1593423)             | [710-61301011121](https://www.mouser.com/ProductDetail/Wurth-Electronics/61301011121?qs=sGAEpiMZZMs%252bGHln7q6pm%252bxnWLfLL2%2f91bcOqZDLfIg%3d) |
| x5  | 6cm of 20AWG wire                                                                    | |


## Schematic

The circuit is similar to the other cordword projects: essentially an array of
LEDs with low-side NFET switches. By default, the LEDs are on with a pull-up resistor on the MOSFET gates.
The gate is exposed via pin header so it can be pulled low (turning off the LED).

![Schematic](./assets/cordwood-three_schematic.jpg?raw=true)

## Construction

The conventional construction is a vertical stack. The Boldport guide outlines the construction:

[![conventional_layout](./assets/conventional_layout.jpg?raw=true)](https://www.boldport.com/products/cordwood-puzzle-three)

I played around for a bit looking for alternatives, and settled upon an archway style which I found quite appealing;-)

![build-side](./assets/build-side.jpg?raw=true)

So that's working fine - I can toggle the LEDs by pulling any of the 6 gate pins low.

![build-powered](./assets/build-powered.jpg?raw=true)

Here are my working notes for re-arranging the connections...

![custom_layout](./assets/custom_layout.jpg?raw=true)


## A Custom Test Jig - LED Trigger Machine

So without getting too fancy, I wanted a nicer way of mounting and testing the project.
One thing lead to another, and soon I had a completely pointless LED blinking machine:

* I used the box from [The Boldport Gent](../TheGent) project as a base
* 4 x AAA in the box
* power switch
* and a spring-loaded trigger mechanism for blinking the LEDs

![Build](./assets/cordwood-three_build.jpg?raw=true)

Close up on the trigger machnism - a bit of ad-hoc wire craft and a spring:

![cordwood-three_build-trigger](./assets/cordwood-three_build-trigger.jpg?raw=true)

Power and switch connections inside the box:

![cordwood-three_build-power](./assets/cordwood-three_build-power.jpg?raw=true)

Side view..

![cordwood-three_build-side](./assets/cordwood-three_build-side.jpg?raw=true)

## Credits and References
* [Cordwood Puzzle Three](https://www.boldport.com/products/cordwood-puzzle-three) - Boldport Product Page
* [2N7000 datasheet](https://www.futurlec.com/Transistors/2N7000.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2018/08/leap411-cordwood-iii-archway-trigger-mod.html)
* [..as posted on hackady.io](https://hackaday.io/project/160666-cordwood-iii-led-blinking-machine)
