# #353 DigitalLogic/DFlipFlop

Building a clocked D Flip-flop with 74LS00 NAND gates.

![Build](./assets/DFlipFlop_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The [LEAP#348 DLatch](../DLatch) project demonstrated how to build a "data latch" with NAND gates.
It's operation is asynchronous however - meaning while enabled, the output changes as inputs change.

For digital logic circuits however, it is often preferred to have synchronous changes - meaning the outputs only change on a definitve part of a clock cycle.
These are usually referred to as flip-flops, to distinguish them from asynchronous "latches".

[![D-Type_Flip-flop](https://upload.wikimedia.org/wikipedia/commons/8/8c/D-Type_Flip-flop.svg)](https://en.wikipedia.org/wiki/File:D-Type_Flip-flop.svg)

The D flip-flop circuit here is only slightly modified from the latch circuit:

* same NAND-gate construction
* but the enable input is tied to a clock source, with an RC circuit to acta as a rising-edge detector

As a result, output changes only occur on the rising edge of the clock.

As a clock source, I've wired up a simple 74LS14 [Schmitt oscillator](../../SchmittOscillator), with a pretty slow frequency of around
[1.77Hz](http://www.wolframalpha.com/input/?i=1%2F(1.2+*+1k%CE%A9+*+470%C2%B5F)).

The edge detector is an RC integrator with a time constant of
[0.1ms](http://www.wolframalpha.com/input/?i=1k%CE%A9*100nF).

To demonstrate the flip-flop behaviour, an Arduino is feeding a data signal at around 10Hz ([100ms](http://www.wolframalpha.com/input/?i=1%2F10Hz) period).
This is not synchronised with the clock (enable) input, so results are somewhat randomised, allowing for all combinations of inputs to be tested.

### Ben Eater's Tutorials

Great explanations of the D latch and D Flip-Flop..

[![D latch](http://img.youtube.com/vi/peCh_859q7Q/0.jpg)](http://www.youtube.com/watch?v=peCh_859q7Q)

[![D flip-flop](http://img.youtube.com/vi/YW-_GkUguMM/0.jpg)](http://www.youtube.com/watch?v=YW-_GkUguMM)


## Performance

Channel connections for the following traces:

* CH1 (Yellow) - Q output
* CH2 (Blue) - clock/enable oscillator (unfiltered)
* CH3 (Red) - clock/enable trigger (filtered)
* CH4 (Green) - D input (from Arduino)

This first trace shows output Q transitioning from low to high. Note:

* occurs on the leading edge of the clock/enable pulse
* when data input is high
* does not reset on the falling edge of the clock
* does not reset when data input falls

![scope_transition_on](./assets/scope_transition_on.gif?raw=true)

This second trace shows output Q transitioning from high to low. Note:

* occurs on the leading edge of the clock/enable pulse
* when data input is low
* does not reset on the falling edge of the clock
* does not reset when data input rises

![scope_transition_off](./assets/scope_transition_off.gif?raw=true)

## Construction

![Breadboard](./assets/DFlipFlop_bb.jpg?raw=true)

![Schematic](./assets/DFlipFlop_schematic.jpg?raw=true)

![Build](./assets/DFlipFlop_build.jpg?raw=true)

## Credits and References
* [74LS00 datasheet](http://www.futurlec.com/74LS/74LS00.shtml)
* [74LS14 datasheet](http://www.futurlec.com/74LS/74LS14.shtml)
* [D flip-flop](https://en.wikipedia.org/wiki/Flip-flop_(electronics)#D_flip-flop) - wikipedia
* [RC time constant](https://en.wikipedia.org/wiki/RC_time_constant) - wikipedia
* [..as mentioned on my blog](http://blog.tardate.com/2017/10/leap353-d-flipflop-with-nand-gates.html)
