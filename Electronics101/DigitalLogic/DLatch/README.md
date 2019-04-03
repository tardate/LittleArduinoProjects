# #348 D Latch

Building a D Latch with NAND gates (74LS00).

Here's a quick demo of it in action..

[![Build](./assets/DLatch_build.jpg?raw=true)](https://youtu.be/qgyVF3U2MOU)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The Gated D latch:

* sets the complementary outputs (Q & ~Q) based on a single input bit ("D" i.e. data)
* out changes are synchronous i.e. no clocking required - they change immediately
* new data is only latched  when the enable input is set
* if enable input is not set, the outputs (Q & ~Q) remain latched at their last value

The gated D latch is a fundamental 1-bit memory unit, and is at the core of much digital logic design.

[![Gated_D_latch_symbol](https://upload.wikimedia.org/wikipedia/commons/c/cb/Gated_D_latch_symbol.png)](https://commons.wikimedia.org/wiki/File:Gated_D_latch_symbol.png)


### Truth Table

| E | D | Q(t+1) | ~Q(t+1) |
|---|---|--------|---------|
| 0 | 0 | Q(t)   | ~Q(t)   |
| 0 | 1 | Q(t)   | ~Q(t)   |
| 1 | 0 | 0      | 1       |
| 1 | 1 | 1      | 0       |


### Logic Design

There are various combinations of gates that can be used to construct a D latch.

I'm going to test a design based on an SR NAND latch, which means a single 74LS00 (quad two-input NAND):

[![D-Type_Transparent_Latch](https://upload.wikimedia.org/wikipedia/commons/2/2f/D-Type_Transparent_Latch.svg)](https://en.wikipedia.org/wiki/File:D-Type_Transparent_Latch.svg)

Alternatively this can be built based on an SR NOR latch:

[![D-type_Transparent_Latch_%28NOR%29](https://upload.wikimedia.org/wikipedia/commons/c/cb/D-type_Transparent_Latch_%28NOR%29.svg)](https://en.wikipedia.org/wiki/File:D-type_Transparent_Latch_(NOR).svg)


### Ben Eater's Tutorials

Great explanations of the D latch and D Flip-Flop..

[![D latch](https://img.youtube.com/vi/peCh_859q7Q/0.jpg)](https://www.youtube.com/watch?v=peCh_859q7Q)

[![D flip-flop](https://img.youtube.com/vi/YW-_GkUguMM/0.jpg)](https://www.youtube.com/watch?v=YW-_GkUguMM)


## Construction

I'm building this first on a breadboard using a single 74LS00 (quad two-input NAND), LED indicators and manual inputs.

* the enabled input uses one pole of a DPDT switch
* the data input uses a push-button with the default position low with a 1kΩ pull-down resistor

NB: the pull-down resistor can't be too stiff with the 74LS00. For example, a 10kΩ pull-down resistor allows the input to float a little too high and corrupt the input.


![Breadboard](./assets/DLatch_bb.jpg?raw=true)

![Schematic](./assets/DLatch_schematic.jpg?raw=true)

![Build](./assets/DLatch_build.jpg?raw=true)

## Credits and References
* [74LS00 datasheet](https://www.futurlec.com/74LS/74LS00.shtml)
* [The D Latch](https://www.allaboutcircuits.com/textbook/digital/chpt-10/d-latch/) - allaboutcircuits
* [Gated D latch](https://en.wikipedia.org/wiki/Flip-flop_(electronics)#Gated_D_latch) - wikipedia
* [The D Flip-Flop](http://hyperphysics.phy-astr.gsu.edu/hbase/Electronic/Dflipflop.html#c2)
* [D latch](https://www.youtube.com/watch?v=peCh_859q7Q&list=PLowKtXNTBypGqImE405J2565dvjafglHU&index=7) - Ben Eater
* [D flip-flop](https://www.youtube.com/watch?v=YW-_GkUguMM&list=PLowKtXNTBypGqImE405J2565dvjafglHU&index=8) - Ben Eater
* [7400 Series datasheets](http://www.skot9000.com/ttl/)
* [..as mentioend on my blog](https://blog.tardate.com/2017/10/leap348-d-latch-with-nand-gates.html)
