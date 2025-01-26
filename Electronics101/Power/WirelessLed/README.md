# #597 Simple Wireless Power LED

Researching wireless power transmission and building a simpel wirelessly-powered LED demonstration.

![Build](./assets/WirelessLed_build.jpg?raw=true)

## Notes

The Qi standard for mobile wireless charging was released in 2011 by the [Wireless Power Consortium](https://www.wirelesspowerconsortium.com/),
and since then wireless power has become pretty mainstream.

In al that time I've not paid much attention except increasingly as a user. But now I ahve the itch to try and incorporate wireless power in more projects.

So, this project is starting with the most basic demonstration - powering an LED wirelessly.

## Construction

The power transmitter consists of a self-governing flyback oscillator, similar to circuits used in the Joule Thief.
The two halves of the coil are wound in a continuous concentric circle - meaning that current flow is opposed in each half. Basic operation:

* on startup, current flows to the base of the transistor, turning it on
* as the transistor turns on, the current in the collector coild induces a field with opposes the flow of current in the coil to the base
* as the the base current reduces, the transistor turns off producing a large flyback voltage spike and the cycle repeats

The receiver is a simple coild that electromagnetically couples with the transmission coil.
A LED rectifies the current flow and lights up accordingly.

![Breadboard](./assets/WirelessLed_bb.jpg?raw=true)

![Schematic](./assets/WirelessLed_schematic.jpg?raw=true)

## Coil 1

The first coil tested, works fine to a range of about 3cm. Key dimensions:

* coil wire: 0.4mm insulated winding wire
* coil diameter: 45mm
* base coil: 15 turns
* collector coil: 15 turns
* receiver coil: 30 turns

![coil_01](./assets/coil_01.jpg?raw=true)

The transmitter is oscillating at around 392kHz, peaking at 27V.

![coil_01_scope](./assets/coil_01_scope.gif?raw=true)

## Coil 2

The second coil was a test to downsize a little: smaller coil and wire, compensated for with more windings. Also works fine to a range of 2-3cm:

* coil wire: 0.2mm insulated winding wire
* coil diameter: 10mm
* base coil: 30 turns
* collector coil: 30 turns
* receiver coil: 60 turns

![coil_02](./assets/coil_02.jpg?raw=true)

![coil_02_scope](./assets/coil_02_scope.gif?raw=true)

## Next Steps

This was very much a "suck it and see" experiment. It works, but the power transfered is very low.

Next I'd like to investigate increasing the power, range and efficiency:

* controlled oscillator
* optimal frequency and coil dimensions
* full-wave rectification on the receiver

Some references for inspiration:

* [Software-Based Wireless Power Transfer Platform for Various Power Control Experiments](https://www.researchgate.net/publication/269301485_Software-Based_Wireless_Power_Transfer_Platform_for_Various_Power_Control_Experiments)


## Credits and References

* [Simple Wireless Power Transmission Circuit to Glow an LED](https://circuitdigest.com/electronic-circuits/simple-wireless-power-transmission-circuit-diagram)
* [Software-Based Wireless Power Transfer Platform for Various Power Control Experiments](https://www.researchgate.net/publication/269301485_Software-Based_Wireless_Power_Transfer_Platform_for_Various_Power_Control_Experiments)
* [2N3904](http://parts.io/detail/5427230/2N3904)
* [Wireless Power Consortium](https://www.wirelesspowerconsortium.com/)
