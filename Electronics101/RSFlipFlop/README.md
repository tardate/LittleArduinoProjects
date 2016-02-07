# #060 RSFlipFlop

Reset/set flip flop with BJTs.

Here's a quick video of the circuit in action:

[![RSFlipFlop demo](http://img.youtube.com/vi/Df0gB0qHPFM/0.jpg)](http://www.youtube.com/watch?v=Df0gB0qHPFM)

## Notes

This is a classic Set-Reset [Flip-flop](http://en.wikipedia.org/wiki/Flip-flop_%28electronics%29)
See [RSFlipFlopFlipper](../RSFlipFlopFlipper) for a version of this circuit but with Arduino control and monitoring.

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

### Construction

![The Breadboard](./assets/RSFlipFlop_bb.jpg?raw=true)

![The Schematic](./assets/RSFlipFlop_schematic.jpg?raw=true)

![The Build](./assets/RSFlipFlop_build.jpg?raw=true)

## Credits and References
* [RSFlipFlopFlipper](../RSFlipFlopFlipper) - same project, but with Arduino control and monitoring
* [S9013 Datasheet](http://www.futurlec.com/Transistors/S9013.shtml)
* [Wikipedia: Flip-flop](http://en.wikipedia.org/wiki/Flip-flop_%28electronics%29)
* [PCB heaven](http://www.pcbheaven.com/userpages/basic_transistor_circuits/) - demo circuit used as the basis for this project