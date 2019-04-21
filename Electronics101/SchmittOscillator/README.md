# #022 SchmittOscillator

Use a 74LS14 to generate an oscillating waveform and plot the results.

Here's a quick video of the circuit in action:

[![Schmitt Oscillator](https://img.youtube.com/vi/QV99ATHP2Xs/0.jpg)](https://www.youtube.com/watch?v=QV99ATHP2Xs)


## Notes

One inverter unit of the 74LS14 Hex Inverter with Schmitt Trigger Inputs is used as an oscillator.
The input and output levels are read with analog input pins, and the values is echoed to the Arduino serial port for plotting.

All unused outputs on the 74LS14 are left open circuit. Unused inputs are grounded, as is recommended to avoid unstable operation.

The frequency of the oscillation is calculated as:

    f = 1 / (1.2 * R * C)
    f = 1 / (1.2 * 1kΩ * 470µF)
    f = 1.77 Hz

The oscillating output from the inverter is used to drive the base of a general-purpose NPN transistor, switching a LED on and off in turn.
The transistor is used to isolate the 74LS14 from the load, as it is not designed to directly handle any significant current.

Here's a sample trace recorded using [PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) to
read the data collected by the [SchmittOscillator.ino](./SchmittOscillator.ino) program.
The lower trace is the input, and the upper trace is the output of the inverter:

![processing trace](./assets/processing_trace.png?raw=true)

Schmitt inverters produce a non-symmetrical waveform. The duty cycle is about 33%, and levels not very stable.
This is particular to the LS (low-power Schottky) version of the 7414.
To oscillate at all, R values must be kept between 100Ω and 1kΩ, and C between 1nF and 1000µF.

Apparently 74HC14 has a duty cycle more like 50% and can handle higher values of R (but I don't have one handly to test).

See [Schmitt Waveform Generators](http://www.electronics-tutorials.ws/waveforms/generators.html) for more, and
[Circuit Properties of LS and HC Digital Logic](http://mysite.du.edu/~etuttle/electron/elect13.htm) for comparison of LS and HC characteristics.

See the [RingOscillator](../RingOscillator) project for a related application of inverters in waveform generation.

### Construction

![The Breadboard](./assets/SchmittOscillator_bb.jpg?raw=true)

![The Schematic](./assets/SchmittOscillator_schematic.jpg?raw=true)

![The Build](./assets/SchmittOscillator_build.jpg?raw=true)

## Credits and References
* [74LS14 Datasheet](https://www.futurlec.com/74LS/74LS14.shtml)
* [Schmitt Trigger Oscillators?!](http://forum.arduino.cc/index.php?topic=147691.0) in the Arduino forums
* [Schmitt Waveform Generators](http://www.electronics-tutorials.ws/waveforms/generators.html) - very informative; compares LS14 with alternatives for waveform generation.
* [Circuit Properties of LS and HC Digital Logic](http://mysite.du.edu/~etuttle/electron/elect13.htm)
* [Schmitt Trigger Oscillator](http://electronics-course.com/schmitt-trigger-oscillator)