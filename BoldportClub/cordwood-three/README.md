# #411 cordwood-three

Custom build of the Boldport Club Cordwood Puzzle III, Project #25, May 2018, with an archway layout and a spring-loaded LED trigger machanism.

![Build](./assets/cordwood-three_build.jpg?raw=true)

Here's a quick demo of the build on a custom test jig "LED Blinky Machine"..

[![clip](http://img.youtube.com/vi/ol5FfNbUmC8/0.jpg)](http://www.youtube.com/watch?v=ol5FfNbUmC8)

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
* [2N7000 datasheet](http://www.futurlec.com/Transistors/2N7000.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2018/08/leap411-cordwood-iii-archway-trigger-mod.html)
