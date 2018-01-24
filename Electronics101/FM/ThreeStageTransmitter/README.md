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
The microphone is very sensitive, and the pre-amp is fairly high gain. Loud sounds close to the microphone
can be quite distorted/clipped.

## Construction

Layout is derived from [LEAP#280 BreadboardTransmitter](../BreadboardTransmitter) design:

![ThreeStageTransmitter_layout](./assets/ThreeStageTransmitter_layout.jpg?raw=true)

A strip of copper PCB is the positive rail anchoring the circuit:

![build_01](./assets/build_01.jpg?raw=true)

Lots of space in the can for battery compartment, switch/LED/microphone attachments and the circuit itself.
The case provides the ground plane:

![build_02](./assets/build_02.jpg?raw=true)

![Breadboard](./assets/ThreeStageTransmitter_bb.jpg?raw=true)

![Schematic](./assets/ThreeStageTransmitter_schematic.jpg?raw=true)

![Build](./assets/ThreeStageTransmitter_build.jpg?raw=true)

## The Real Deal

So after hacking away on [dazaro3's designs](https://www.youtube.com/channel/UCU5ca_ymxbKi9GqVH7BMxbg) I thought
I should get a "real" one as a way of saying thanks.

It just turned up, and works great. Happily I see the performance is very similar
to the builds I've done already. Here are some pictures:

![fmtuk-unboxed](./assets/fmtuk-unboxed.jpg?raw=true)

![fmtuk-front](./assets/fmtuk-front.jpg?raw=true)

![fmtuk-back](./assets/fmtuk-back.jpg?raw=true)


## Credits and References
* [LEAP#280 FM/BreadboardTransmitter](../BreadboardTransmitter)
* [A Breadboard FM Transmitter Bug](https://www.youtube.com/watch?v=lUpujUAa2ZQ) - dazaro3
* [dazaro3 channel](https://www.youtube.com/channel/UCU5ca_ymxbKi9GqVH7BMxbg)
* [www.bug-transmitter.com/](http://www.bug-transmitter.com/) - sells kits by dazaro3
* [2N3904 datasheet](http://www.futurlec.com/Transistors/2N3904.shtml)
* [air coil calculator](http://www.qsl.net/in3otd/indcalc.html)
* [LC resonance calculator](http://www.daycounter.com/Calculators/LC-Resonance-Calculator.phtml)
* [..as mentioned on my blog](https://blog.tardate.com/2017/04/leap281-three-stage-fm-transmitter.html)
