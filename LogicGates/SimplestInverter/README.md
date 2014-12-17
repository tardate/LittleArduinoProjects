# Fundamental Logic Gates - Simple Inverter

Use an Arduino to demonstrate the most most basic single-transistor inverter, and plot the results with [Processing](https://www.processing.org).

Here's a quick video of the circuit in action:

[![Fundamental Logic Gates - Simple Inverter](http://img.youtube.com/vi/JQzt-ZaF9fw/0.jpg)](http://www.youtube.com/watch?v=JQzt-ZaF9fw)

## Notes

The circuit uses a digital output pin as the input to the inverter. The output is tapped at the collector of the transistor. The output voltage is read with an analog input pin, and the value is echoed to the Arduino serial port.

[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) reads the data from the serial port and plots the input and output value over time, with some coloration effects thrown in for good measure. In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

Here's a sample trace. The lower trace is the signal input, and the upper trace is the output of the inverter.

![processing trace](./assets/processing_trace.png?raw=true)

We clearly lose significant voltage at the output because of the current-limiting resistors. There is also noticable noise in the output, mainly because the circuit is so simple it lacks any attempt at smoothing the source voltage or output. These would be significant issues when cascading the inverter output to subsequent logic blocks.

### Construction

![The Breadboard](./assets/SimplestInverter_bb.jpg?raw=true)

![The Schematic](./assets/SimplestInverter_schematic.jpg?raw=true)

![The Build](./assets/SimplestInverter_build.jpg?raw=true)


## Credits and References
* [Download Processing](https://www.processing.org/download/)
* [Logic NOT Gate Tutorial](http://www.electronics-tutorials.ws/logic/logic_4.html) - explains of the basic circuit used here.
* [The NOT gate](http://www.allaboutcircuits.com/vol_4/chpt_3/2.html) - describes a practical implementation of a "real" inverter circuit
* [Logic Gates using Transistors](https://electrosome.com/logic-gates-using-transistors/)