# #346 DigitalLogic/SRLatchWithNandGates

Set-Reset latch implemented with NAND gates.

Here's a quick demo of it in action..

[![Build](./assets/SRLatchWithNandGates_build.jpg?raw=true)](http://www.youtube.com/watch?v=CC7LnUj8XIc)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

This circuit is another implementation of a Set-Reset flip-flip, this time using NAND gates.
A 74LS00 is used to provide the two NAND gates required.

Other implementations:

* [LEAP#061 SRLatch](../SRLatch) - using BJTs
* [LEAP#077 SRLatchWithNorGates](../SRLatchWithNorGates) - using NOR gates

The NAND gate implementatation has an undefined state with both inputs high,
whereas a NOR gate implementatation has an undefined state with both inputs low.

Consequently NOR gates are typically used for active-high SR latches and NAND gates for active-low SR latches.
A good example of this is the application in touch sensors, where active low makes sense.
See the Boldport Club
[tap](../../../BoldportClub/tap) and
[mostap](../../../BoldportClub/mostap) projects for examples of this.


## Truth Table

| Set(t) | Reset(t) | Output Q(t+1)  |
|--------|----------|----------------|
|      0 |        0 | invalid state  |
|      0 |        1 | 1              |
|      1 |        0 | 0              |
|      1 |        1 | Q(t) no change |

![sr-latch-nand](./assets/sr-latch-nand.png?raw=true)


## Construction

Here's a quick breadboard build using a 74LS00 quad two-input NAND gate, with some switches and LEDs to indicate S, R, Q and `Q:

![Breadboard](./assets/SRLatchWithNandGates_bb.jpg?raw=true)

![Schematic](./assets/SRLatchWithNandGates_schematic.jpg?raw=true)

![Build](./assets/SRLatchWithNandGates_build.jpg?raw=true)

## Credits and References
* [74LS00 datasheet](http://www.futurlec.com/74LS/74LS00.shtml)
* [NAND-gate Latch](http://hyperphysics.phy-astr.gsu.edu/hbase/Electronic/nandlatch.html)
* [SR Flip-Flop: NOR or NAND?](https://electronics.stackexchange.com/questions/163164/sr-flip-flop-nor-or-nand) - stackexchange
* [LEAP#061 SRLatch](../SRLatch) - implementation using BJTs
* [LEAP#077 SRLatchWithNorGates](../SRLatchWithNorGates) - implementation with NOR gates
* [..as mentioned on my blog](http://blog.tardate.com/2017/10/leap346-sr-latch-with-nand-gates.html)
