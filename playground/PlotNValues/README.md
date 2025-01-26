# #090 PlotNValues

Sample up to 6 analog inputs and stream the data to serial in ASCII format - for plotting with Processing for example.

![The Build](./assets/PlotNValues_build.jpg?raw=true)

## Notes

This is a generic program for sampling up to 6 analog values on a fixed time base,
and streaming the data to the serial port in ASCII, comma-separated format.

[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues/PlotNValues.pde) can be used to read the data from the serial port
and plot the values over time, with some coloration effects thrown in for good measure.

In other words, we're using Arduino and Processing as a basic oscilloscope or waveform plotter.
And it kind of works, as long as the sampling frequency is kept relatively low (10ms/100Hz by default).

The number of traces is fixed with the TRACE_COUNT defined in the sketch.
The values are read from analog pins A0,A1,..A5 respectively.

Here's an example 2-input trace:

![processing trace](./assets/processing_trace_2.png?raw=true)

Here's an example 6-input trace:

![processing trace](./assets/processing_trace_6.png?raw=true)

## Construction

![The Breadboard](./assets/PlotNValues_bb.jpg?raw=true)

![The Schematic](./assets/PlotNValues_schematic.jpg?raw=true)

![The Build](./assets/PlotNValues_build.jpg?raw=true)

## Credits and References

* [FlexiTimer2](https://github.com/wimleers/flexitimer2) library
* [PlotNValues](../../processing/PlotNValues/PlotNValues.pde) Processing sketch
