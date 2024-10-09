# #555 555 SR Latch

Set/Reset latch with a 555 timer.

![Build](./assets/SRLatch_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/EvETU3D4btE/0.jpg)](https://www.youtube.com/watch?v=EvETU3D4btE)

## Notes

A Set/Reset latch is one of the fundamental building blocks in digital logic: essentially a 1-bit memory device
(set high with a "set" input, and remaining high until a "reset" input is received; repeated pulses cause no change to the output).

The behaviour is summarised here:

| S  | R  | Action      | Q (next) |
|:--:|:--:|-------------|:--------:|
| 0  | 0  | Hold State  | ~        |
| 1  | 0  | Set         | 1        |
| 0  | 1  | Reset       | 0        |
| 1  | 1  | Invalid, n/a| ~        |

The 555 timer has an SR Latch as one of its internal building blocks, so it should be no surprise that it
is possible to build an SR Latch with the chip.

The trick is to essentially by-pass the "5-5-5" stacked comparators:

* threshold (4) is pulled to ground, thus it can never activate and reset in the internal SR Latch
* trigger (2) is the "set" input - normally pulled high, but when triggered (pulled low) will immediately set the internal SR Latch
* reset (4) directly triggers the internal SR Latch reset when pulled low

![555_simplified_schematic](./assets/555_simplified_schematic.png?raw=true)

## Construction

![Breadboard](./assets/SRLatch_bb.jpg?raw=true)

![Schematic](./assets/SRLatch_schematic.jpg?raw=true)

![Build](./assets/SRLatch_build.jpg?raw=true)

## Credits and References

* [LM555 datasheet](https://www.futurlec.com/Linear/LM555CM.shtml)
* [FLIP FLOP and MEMORY CELL](http://www.talkingelectronics.com/projects/50%20-%20555%20Circuits/50%20-%20555%20Circuits.html#15) - talkingelectronics
* [SR latch](https://en.wikibooks.org/wiki/Digital_Circuits/Latches#SR_latch) - wikibooks
* [Flip-flop](http://en.wikipedia.org/wiki/Flip-flop_%28electronics%29) - wikipedia
