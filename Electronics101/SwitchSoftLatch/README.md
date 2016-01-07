# SwitchSoftLatch

Test a soft-latching power switching circuit.

Here's a quick video of the circuit in action:

[![SwitchSoftLatch demo](http://img.youtube.com/vi/9lX_sPDjzDE/0.jpg)](http://www.youtube.com/watch?v=9lX_sPDjzDE)

## Notes

This is a neat circuit with low component count that provides an on/off toggle with a momentary push-button.
It would be suitable for switching a power supply for a circuit.

Dave Jones explains it best in [EEVblog #262 - World's Simplest Soft Latching Power Switch Circuit](https://www.youtube.com/watch?v=Foc9R0dC2iI),
but the essence of the circuit is this:

When Q1 (power) MOSFET is off:
* pressing the switch pulls up the base of Q2 NPN
* Q2 turns on
* Q2 in turn pulls down Q1 gate and Q1 turns on
* Q2 kept on via R2

When Q1 (power) MOSFET is on:
* Q3 NPN turns on once C1 is charged (per R4, C1 time constant)
* with Q3 on, pressing the switch pulls down the base of Q2 NPN
* Q2 turns off
* Q1 gate pulls high via R1 and turns off

### Component Selection

The R4/C1 time constant can be adjusted to debounce the switch and/or enforce a minimum "on time" before it is possible to turn the circuit off.

I have a BS250P p-channel MOSFET on hand; it's not really for power applications but I'm using it here as Q1 just for demonstration purposes.

### Performance

What this circuit does well:

* when off, load current cust clean to 0mA (perhaps fractional µA at most)
* the R/C network does effective button de-bouncing

A couple of things that could probably be improved:

* the component values used here work OK at 5V, but not at higher input voltages like 9V (can't turn off)
* the capacitor holds its charge long after the circuit is powered down (slow to discharge through Q3 base)
* the circuit starts up "ON", though theoretically it shouldn't. I suspect this is due to residual capacitance in C1.

So perhaps I'll need to try some improvements or test some alternative circuits like
[this one from Talking Electronics](http://www.talkingelectronics.com/projects/200TrCcts/101-200TrCcts.html#20a)

## Construction

![Breadboard](./assets/SwitchSoftLatch_bb.jpg?raw=true)

![The Schematic](./assets/SwitchSoftLatch_schematic.jpg?raw=true)

![The Build](./assets/SwitchSoftLatch_build.jpg?raw=true)

## Credits and References
* [EEVblog #262 - World's Simplest Soft Latching Power Switch Circuit](https://www.youtube.com/watch?v=Foc9R0dC2iI) - original version of this circuit
* [BS250 datasheet](http://www.futurlec.com/Transistors/BS250.shtml)
* [2N3904 datasheet](http://www.futurlec.com/Transistors/2N3904.shtml)
* [Push On - Push Off Transistor Switch](https://www.youtube.com/watch?v=I70H5xQ6MT0) - at a glance, I think a very similar circuit but with slight variations and higher parts count. Original circuit is from [Talking Electronics](http://www.talkingelectronics.com/projects/200TrCcts/101-200TrCcts.html#20a)
