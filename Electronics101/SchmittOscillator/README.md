# Schmitt Oscillator

Use the 74LS14 Hex Inverter with Schmitt Trigger Inputs chip to generate an oscillating waveform. Plots the results with [Processing](https://www.processing.org).

Here's a quick video of the circuit in action:

[![Schmitt Oscillator](http://img.youtube.com/vi/-_85OFB7r08/0.jpg)](http://www.youtube.com/watch?v=-_85OFB7r08)

## Notes

One inverter unit of the 74LS14 chip is used as an oscillator. The input and output levels are read with analog input pins, and the values is echoed to the Arduino serial port for plotting.

All unused outputs on the 74LS14 are left open circuit. Unused inputs are grounded, as is recommended to avoid unstable operation.

The frequency of the oscillation is calculated (with f Hz, R in ohms, C in farads) as:

    f = 1 / (1.2 * R * C)
    f = 1 / (1.2 * 1000 * 0.00047)
    f = 1.77 Hz

[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) reads the data from the serial port and plots the input and output value over time, with some coloration effects thrown in for good measure. In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

Here's a sample trace. The lower trace is the input, and the upper trace is the output of the inverter:

![processing trace](./assets/processing_trace.png?raw=true)

It turns out the 74LS14 is not a great waveform generator! The duty cycle is about 33%, and levels not very stable.
This is particular to the LS (low-power Schottky) version of the 7414. To oscillate at all, R values must be kept between 100R and 1k, and C between 1nF and 1000uF.

Apparently 74HC14 has a duty cycle more like 50% and can handle higher values of R (but I don't have one handly to test).

See [Schmitt Waveform Generators](http://www.electronics-tutorials.ws/waveforms/generators.html) for more, and
[Circuit Properties of LS and HC Digital Logic](http://mysite.du.edu/~etuttle/electron/elect13.htm) for comparison of LS and HC characteristics.


### Construction

![The Breadboard](./assets/schmitt_oscillator_bb.jpg?raw=true)

![The Schematic](./assets/schmitt_oscillator_schematic.jpg?raw=true)

![The Build](./assets/schmitt_oscillator_build.jpg?raw=true)


## Credits and References
* [Download Processing](https://www.processing.org/download/)
* [74LS14 Datasheet](http://www.futurlec.com/74LS/74LS14.shtml)
* [Schmitt Trigger Oscillators?!](http://forum.arduino.cc/index.php?topic=147691.0) in the Arduino forums
* [Schmitt Waveform Generators](http://www.electronics-tutorials.ws/waveforms/generators.html) - very informative; compares LS14 with alternatives for waveform generation.
* [Circuit Properties of LS and HC Digital Logic](http://mysite.du.edu/~etuttle/electron/elect13.htm)




