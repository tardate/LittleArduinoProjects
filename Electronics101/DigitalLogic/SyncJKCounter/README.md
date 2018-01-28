# #320 DigitalLogic/SyncJKCounter

A synchronous 8-bit counter built with JK Flip-Flops.

Here's a quick video of the circuit in action:

[![SynchJKCounter](http://img.youtube.com/vi/HGunGdTaNFQ/0.jpg)](http://www.youtube.com/watch?v=HGunGdTaNFQ)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

A synchronous counter changes its output bits simultaneously, with no ripple.
This contrasts with an asynchronous counter that changes its output bits in a ripple,
as demonstrated by [LEAP#186 AsyncJKCounter](../AsyncJKCounter).

This project implements a classic synchronous counter design using JK flip-flops and AND gates.

## How it Works

As with the asynchronous counter, the mechanism relies on the fact that
in a binary sequence, the next highest bit transitions high when the previous lower bit transitions low:

| q2 | q1 | q0 | Note                                |
|----|----|----|-------------------------------------|
|  0 |  0 |  0 | q0 is directly toggled by the clock |
|  0 |  0 |  1 | q0 is directly toggled by the clock |
|  0 |  1 |  0 | q1 goes high when q0 goes low       |
|  0 |  1 |  1 |                                     |
|  1 |  0 |  0 | q2 goes high when q1 goes low       |

The circuit comprises chained 74LS73 Dual JK Flip-Flops with Clear and 74LS08 Quad 2-input AND gates.

As all the J-K inputs are ganged together, with clear inputs pinned high, only two states of the truth table apply:

| CLR |    CLK | J | K | Q  | Q'  | Note           |
|-----|--------|---|---|----|-----|----------------|
| 1   | 1 -> 0 | 0 | 0 | Qo | Qo' | i.e. unchanged |
| 1   | 1 -> 0 | 1 | 1 | Qo'| Qo  | i.e. toggle    |

The cascading of the change is achieved with the AND gate which combines the input and output of the previous JK flip-flop
to set the input to the next JK flip-flop.

* this sets the input to the next JK flip-flop high when the previous two "bits" are high
* when the clock ticks, this causes the output of the next JK flip-flop to toggle


## Construction

![Breadboard](./assets/SyncJKCounter_bb.jpg?raw=true)

![Schematic](./assets/SyncJKCounter_schematic.jpg?raw=true)

Breadboard build:

![Build](./assets/SyncJKCounter_bb_build.jpg?raw=true)

Breadboard test:

[![SynchJKCounter](http://img.youtube.com/vi/4oMr_x22kUU/0.jpg)](http://www.youtube.com/watch?v=4oMr_x22kUU)

Protoboard build:

![Build](./assets/SyncJKCounter_protoboard_layout.jpg?raw=true)

![Build](./assets/SyncJKCounter_build.jpg?raw=true)

## Credits and References
* [74LS73 Datasheet](http://www.futurlec.com/74LS/74LS73.shtml)
* [74LS08 Datasheet](http://www.futurlec.com/74LS/74LS08.shtml)
* [LEAP#186 AsyncJKCounter](../AsyncJKCounter) - asynchronous 4-bit counter using JK Flip-Flops
* [Synchronous Counter](https://en.wikipedia.org/wiki/Counter_(digital)#Synchronous_counter) - wikipedia
* [Synchronous Counters](https://www.allaboutcircuits.com/textbook/digital/chpt-11/synchronous-counters/)
* [BCD or Decade Counter](http://hyperphysics.phy-astr.gsu.edu/hbase/Electronic/bincount.html#c2)
* [BCD Counter Circuit](http://www.electronics-tutorials.ws/counter/bcd-counter-circuit.html)
* [Synchronous Counters - Final Report](https://www.doc.ic.ac.uk/~nd/surprise_96/journal/vol4/cwl3/report.html)
* [Digital Counters](http://www.learnabout-electronics.org/Digital/dig56.php)
* [..as mentioned on my blog](https://blog.tardate.com/2017/06/leap320-synchronous-jk-counter.html)
