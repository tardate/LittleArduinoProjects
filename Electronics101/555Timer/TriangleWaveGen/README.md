# 555 Timer - Triangle Wave Generator

Uses an Arduino to monitor a 555 timer/RC integrator triangle wave generator and plot the results with [Processing](https://www.processing.org).

## Notes

Triangle waves can be a useful test signal, even taken to approximate a sine wave.

The circuit uses a standard 555 timer astable to pump a square wave into an RC integrator,
which results in the triangle waveform.

To make the circuit easy to monitor and test visually, it is designed for a very low operating frequency of around 1Hz.

The square wave is obtained with [R1=1kΩ, R2=22kΩ and C1=33uF](http://visual555.tardate.com/?mode=astable&r1=1&r2=22&c=33).
This generates a signal with a frequency just under 1Hz; the period is actually 1029ms, and 51% duty cycle.

    cycle time = 0.693 x (R1 + 2 x R2) x C1
    cycle time = 1029ms

The square wave issues from pin 3 of the 555 timer, and is injected into an RC integrator.
An RC integrator is a low-pass filter that converts a square wave input signal into a triangular waveform output.

To get the best triangle wave from this, we want the RC integrator to have a
[time constant (𝛕)](http://en.wikipedia.org/wiki/RC_time_constant)
such that the capacitor can approach full charge within the period of the square wave.

The charge at time t is:

    v(t) = v(0)x[1 - e^(-t/𝛕)]

So if we aim for a cycle time of about 5𝛕, that translates to 99.3% of full charge, and 91.8% at half cycle (2.5𝛕).

Given 𝛕 = 1/rc, we therefore want the RC integrator to fit as follows:

    5𝛕 = 5 /(R3 x C3) -> approaching 1029ms

Playing around with a few alternatives for R3 and C3, I've selected R3 = 14.7kΩ and C3 = 330uF:

    5 / (14.7kΩ x 330uF) = 1031ms

Here's a sample trace of the resulting waveforms as measured by the Arduino.
The lower trace is the square wave at pin 3 of the 555 timer,
the upper trace is the triangular wave at the output of the RC integrator:

![processing trace](./assets/processing_trace.png?raw=true)

### Construction

The Arduino only acts as a measurement device in this circuit.

[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) reads the data from the serial port and plots the input and output value over time, with some coloration effects thrown in for good measure. In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

![The Breadboard](./assets/TriangleWaveGen_bb.jpg?raw=true)

![The Schematic](./assets/TriangleWaveGen_schematic.jpg?raw=true)

![The Build](./assets/TriangleWaveGen_build.jpg?raw=true)

NB: the schematic describes the circuit being driven from the Arduino 5V pin.
That works fine, although the build picture shows the 555/RC integrator being driven using a separate 5V breadboard power supply.
That also works fine! (It's just important to ensure there is a common ground connection).

## Credits and References
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [Visual 555 Calculator](http://visual555.tardate.com)
* [RC Time Constant](http://en.wikipedia.org/wiki/RC_time_constant)
* [Download Processing](https://www.processing.org/download/)