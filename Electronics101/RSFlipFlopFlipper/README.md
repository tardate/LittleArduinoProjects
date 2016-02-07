# #061 RSFlipFlopFlipper

Reset/set flip flop with BJTs, controlled and monitored by an Arduino.

Here's a quick video of the circuit in action:

[![RSFlipFlopFlipper demo](http://img.youtube.com/vi/KXwm6WrVOow/0.jpg)](http://www.youtube.com/watch?v=KXwm6WrVOow)

## Notes

This is a classic Set-Reset [Flip-flop](http://en.wikipedia.org/wiki/Flip-flop_%28electronics%29) under Arduino control.

See the [RSFlipFlop](../RSFlipFlop) project for the implementation details and design notes on the flip-flop.
RSFlipFlop uses manual switch entry to control the flip-flop.

This version of the circuit uses an Arduino to drive the set/reset inputs, and monitor the output state.
For simplicity, the flip-flop is powered from the Arduino's 5V regulated pin.
Output state is read with analog ports, and the data sent to the serial port for plotting with [PlotNValues (a simple Processing sketch)](../../processing/PlotNValues).

The processing trace below demonstrates the behaviour using 4 traces. From bottom to top:

* Lower plot: SET input
* Lower-middle plot: RESET input
* Upper-middle: Out1 ouput state Q
* Upper plot: Out2 inverted output state -Q

![processing trace](./assets/processing_trace.png?raw=true)

The plot demonstrates:

* how repeated triggers have no effect on the output
* SET sends Out1/Q high
* RESET sends Out1/Q low
* Out2/-Q is always the inverse of Out1/Q


### Construction

![The Breadboard](./assets/RSFlipFlopFlipper_bb.jpg?raw=true)

![The Schematic](./assets/RSFlipFlopFlipper_schematic.jpg?raw=true)

![The Build](./assets/RSFlipFlopFlipper_build.jpg?raw=true)

## Credits and References
* [RSFlipFlop](../RSFlipFlop) - same project, but with manual inputs rather than Arduino control
* [S9013 Datasheet](http://www.futurlec.com/Transistors/S9013.shtml)
* [Wikipedia: Flip-flop](http://en.wikipedia.org/wiki/Flip-flop_%28electronics%29)
* [PCB heaven](http://www.pcbheaven.com/userpages/basic_transistor_circuits/) - demo circuit used as the basis for this project