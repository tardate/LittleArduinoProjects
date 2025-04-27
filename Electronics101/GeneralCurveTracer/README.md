# #245 General Curve Tracer

Test a DC-powered general curve tracer circuit.

![GeneralCurveTracer_protoboard_build](./assets/GeneralCurveTracer_protoboard_build.jpg?raw=true)

## Notes

I've borrowed this general curve tracing circuit from [stoneslice's prototype and video](https://www.youtube.com/watch?v=_WQi8oKzsD8).
Rather than rely on an AC power supply, this uses a simple DC-powered oscillator to drive a test signal across the device under test.
It features a DPDT switch to toggle and compare two devices under test.

X-Y signals are plotted on an oscilloscope to visualise the characteristic curve for the component.

* X is the ground-referenced voltage at the anode of the DUT
* Y is the voltage across the resistor at the cathode of the DUT, which is proportional to the current flowing through the DUT.

NB: see w2aew's [#49: Simple Component Tester using Oscilloscope - Octopus Curve Tracer](https://www.youtube.com/watch?v=Gwo3pEH7hUE) for an example of a classic AC-powered curve tracer.

### 100nF Capacitor

The charge-discharge cycles result in an oval pattern:

![curve_capacitor](./assets/curve_capacitor.gif?raw=true)

### 10kΩ Resistor

Response is predictably linear:

![curve_resistor](./assets/curve_resistor.gif?raw=true)

### 1N4730 3.9V Zener Diode

The curve clearly illustrates characteristic Zener diode behaviour:

* Forward-biased, it behaves like a normal diode rectifier
* Relatively low reverse breakdown (Zener) voltage

![curve_1n4730](./assets/curve_1n4730.gif?raw=true)

### Testing Rectifier Diodes

If a single rectifier diode is placed under test, this circuit generally fails to produce the characteristic forward voltage drop curve.
I believe this is because at low voltages (when powered by 9V battery), it never hits reverse breakdown and the 1µF C4 never gets to cycle.
The result is that the test signal ends up getting pushed just below the forward voltage threshold.

My fix for this is to test rectifier diode in a back-to-back pair. This allows C4 to cycle and a nice forward-voltage curve to be generated.
the downside is that the reverse voltage curve is simply the inverse mirror of the forward-biased curve.

### 1N5819 Schottky Barrier Diode

Schottky Barrier Diodes exhibit extremely low forward voltage drop.
NB: this curve is of two 1N5819's back-to-back - see note above.

![curve_1n5819](./assets/curve_1n5819.gif?raw=true)

### 1N4148 High-speed Diode

A common rectifier diode.
NB: this curve is of two 1N4148's back-to-back - see note above.

![curve_1n4148](./assets/curve_1n4148.gif?raw=true)

## Construction

![Breadboard](./assets/GeneralCurveTracer_bb.jpg?raw=true)

![The Schematic](./assets/GeneralCurveTracer_schematic.jpg?raw=true)

![GeneralCurveTracer_protoboard_build](./assets/GeneralCurveTracer_protoboard_build.jpg?raw=true)

![GeneralCurveTracer_protoboard_layout](./assets/GeneralCurveTracer_protoboard_layout.jpg?raw=true)

## Credits and References

* [Simple Component Tester](https://www.youtube.com/watch?v=_WQi8oKzsD8) - stoneslice
* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml)
* [#49: Simple Component Tester using Oscilloscope - Octopus Curve Tracer](https://www.youtube.com/watch?v=Gwo3pEH7hUE) - w2aew demonstrating the classic AC version
* [1N4730 datasheet](https://www.futurlec.com/Diodes/1N4730.shtml)
* [1N5819 datasheet](https://www.futurlec.com/Diodes/1N5819.shtml)
* [1N4148 datasheet](https://www.futurlec.com/Diodes/1N4148.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/leap245-generic-curve-tracer.html)
