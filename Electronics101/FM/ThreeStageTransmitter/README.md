# #281 FM/ThreeStageTransmitter

Build an "ugly-style in a can" version of dazaro3's 3-stage FM transmitter circuit.

![Build](./assets/ThreeStageTransmitter_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

I got such good results with [LEAP#280 BreadboardTransmitter](../BreadboardTransmitter)
that I decided to make something more permanent than a breadboard.

Since I have some Altoids tins collecting dust for just such an occasion, I'm doing this "ugly-style in a can".


### Performance

In the initial circuit I have 33pF C4 in the tank circuit.
This produced a transmission frequency of 97.4MHz, which happens to be quite busy in my area.
After adding another 33pF C9 in parallel (effectively 66pF), I moved the transmission to a much clearer 79.8MHz.

Output power is very good - easily transmits around my house.
The microphoneis very sensitive, and the pre-amp is fairly high gain. Loud sounds close to the microphone
can be quite distorted/clipped.

## Construction

A strip of copper PCB is the positive rail that the circuit is anchored to:

![build_01](./assets/build_01.jpg?raw=true)

Lots of space in the can for battery compartment, switch/LED/microphone attachments and the circuit itself.
The case provides the ground plane:

![build_02](./assets/build_02.jpg?raw=true)

![Breadboard](./assets/ThreeStageTransmitter_bb.jpg?raw=true)

![Schematic](./assets/ThreeStageTransmitter_schematic.jpg?raw=true)

![Build](./assets/ThreeStageTransmitter_build.jpg?raw=true)

## Credits and References
* [LEAP#280 FM/BreadboardTransmitter](../BreadboardTransmitter)
