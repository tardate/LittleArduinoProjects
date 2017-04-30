# #061 SRLatch

Set/Reset latch with BJTs.

Here's a quick video of the circuit in action:

[![RSFlipFlop demo](http://img.youtube.com/vi/Df0gB0qHPFM/0.jpg)](http://www.youtube.com/watch?v=Df0gB0qHPFM)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

This is a classic Set-Reset latch.
See [LEAP#062 SRLatchFlipper](../SRLatchFlipper) for a version of this circuit but with Arduino control and monitoring.

In this circuit:

* Switch S1 acts as "Set" (S)
* Switch S2 acts as "Reset" (R)
* Out1 is output state Q
* Out2 is inverted output state -Q

The behaviour is summarised here:

| S  | R  | Action      | Q  | Q next |
|:--:|:--:|-------------|:--:|:------:|
| 0  | 0  | Hold State  | ~  | ~      |
| 1  | 0  | Set         | 0  | 1      |
| 0  | 1  | Reset       | 1  | 0      |
| 1  | 1  | Invalid, n/a| ~  | ~      |

Set/reset are edge-triggering pulses, and pulses only need to be long enough for the transistors to react.
Repeated pulses cause no change to the output.

A power supply from 5-9V is fine.

Here's a great animation of the circuit from wikibooks:

![Transistor_Bistable_interactive_animated_EN](https://upload.wikimedia.org/wikipedia/commons/1/14/Transistor_Bistable_interactive_animated_EN.svg)

Ben Eater has a great video explaining SR latch behaviour:

[![KM0DdEaY5sY](http://img.youtube.com/vi/KM0DdEaY5sY/0.jpg)](http://www.youtube.com/watch?v=KM0DdEaY5sY)


### Latch of Flip-flop?

Although terms are often used interchangeably, this circuit is strictly speaking a "latch".

* a latch is asynchronous, and the outputs can change as soon as the inputs do
* a flip-flop, on the other hand, is edge-triggered and only changes state when a control signal transitions high to low or low to high


### Construction

![The Breadboard](./assets/SRLatch_bb.jpg?raw=true)

![The Schematic](./assets/SRLatch_schematic.jpg?raw=true)

![The Build](./assets/SRLatch_build.jpg?raw=true)

## Credits and References
* [LEAP#062 SRLatchFlipper](../SRLatchFlipper) - same project, but with Arduino control and monitoring
* [S9013 Datasheet](http://www.futurlec.com/Transistors/S9013.shtml)
* [SR latch](https://en.wikibooks.org/wiki/Digital_Circuits/Latches#SR_latch) - wikibooks
* [Flip-flop](http://en.wikipedia.org/wiki/Flip-flop_%28electronics%29) - wikipedia
* [PCB heaven](http://www.pcbheaven.com/userpages/basic_transistor_circuits/) - demo circuit used as the basis for this project
