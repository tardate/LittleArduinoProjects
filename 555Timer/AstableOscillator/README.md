# 555 Timer - A-Stable Oscillator

Use an Arduino to demonstrate the most most basic a-stable oscillator, and plot the results with [Processing](https://www.processing.org).

Here's a quick video of the circuit in action:

[![555 Timer - A-Stable Oscillator](http://img.youtube.com/vi/1vZiGZan2ok/0.jpg)](http://www.youtube.com/watch?v=1vZiGZan2ok)

## Notes

The output is tapped at the anode of the LED, read with an analog input pin and echoed to the Arduino serial port.

[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) reads the data from the serial port and plots the output value over time, with some coloration effects thrown in for good measure. In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

Here's a sample trace:

![processing trace](./assets/processing_trace.png?raw=true)


### Construction

![The Breadboard](./assets/AstableOscillator_bb.jpg?raw=true)

![The Schematic](./assets/AstableOscillator_schematic.jpg?raw=true)

![The Build](./assets/AstableOscillator_build.jpg?raw=true)


## Credits and References
* [Download Processing](https://www.processing.org/download/)
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
