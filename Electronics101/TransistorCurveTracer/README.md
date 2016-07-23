# #228 TransistorCurveTracer

Simple NPN transistor curve tracer using a Stairstep generator circuit.

![The Build](./assets/TransistorCurveTracer_build.jpg?raw=true)

![curve_2N3904_reverse](./assets/curve_2N3904_reverse.gif?raw=true)

## Notes

This is a fascinating circuit, originally from the IEEE Engineering Sciences & Education Journal Vol 8 No 1 Feb 1999 pp25-26.
I'm working from a demonstration by w2aew [#232: More Circuit Fun: Simple transistor curve tracer using Stairstep generator circuit](https://youtu.be/ZOLLoa2fH24).

It actually builds on the basic [StairStepGenerator](../StairStepGenerator) project and adapts it to perform
basic NPN BJT curve tracing (plotting collector currect to collector voltage for different base current values).

I first built up the circuit on a breadboard, but it proved too noisy to be of much use...
so I put the circuit on protoboard and obtained much better results.

### Stairstep Generator

I tried a few opamps in the circuit, but I settled on the TL074 as the best of the lot I have available.
It's not rail-to-rail, so I loose about a volt of the top of the output.

Here's a scope trace of the basic stairstep generator

* CH1 reset oscillator output
* CH2 clock signal form the 555
* CH3 stairstep output

![stairstep](./assets/stairstep.gif?raw=true)

### Driving the Device Under Test

The stairstep generator is extended quite cleverly in order to perform the curve tracing:

* the stairstep output drives the base of the transistor via a resistor so it approximates a current source.
So each step represents one base current curve.

* the 555 clock signal resets a simple R-C circuit, generating a sawtooth curve which is buffered and amplified with an opamp. This signal sweeps the collector current for each "step"

* the collector current is mirrored with a simple PNP current-mirror. One signal drives the collector of the device under test,
and the voltage measurement is the collector voltage (the X value for the curve trace). The other signal drives a fixed resistor,
and the voltage measurement here is analogous to the collector current (the Y value for the curve trace).

Here is a scope trace of the driver signals (without a device under test):

* CH1 - stairstep signal
* CH2 - collector sweep signal

![step_and_driver_signals](./assets/step_and_driver_signals.gif?raw=true)

### Running the Tests

Here's my setup while running some tests.

* I'm using a 5V supply. For this particular circuit configuration, I get pretty good results from 5-7V.
* without a DUT, the curcuit draws around 5mA
* with a DUT, the circuit draws anywhere from 25 to 40mA depending on the particular NPN BJT being tested

![TransistorCurveTracer_demo](./assets/TransistorCurveTracer_demo.jpg?raw=true)


### Testing a 2N3904

For the values I've used in the circuit, I'm getting disappointing results when forward-biasing a 2N3904.
It appears to swing hard to saturation, so my curves are pretty one dimensional:

![curve_2N3904](./assets/curve_2N3904.gif?raw=true)

However, when reverse-biased (i.e. switch emitter and collector), and therefore presumably a lower beta/hFE,
I get a much more pleasing result:

![curve_2N3904_reverse](./assets/curve_2N3904_reverse.gif?raw=true)

I wouldn't necessarily trust these results for anything, but it is interesting to see the theory play out IRL.
Regardless, it's great fun to fiddle with step frequency, reset freqeuncy and input voltage and see the effects in the X-Y plot.


## Construction

![The Schematic](./assets/TransistorCurveTracer_schematic.jpg?raw=true)

I first built up the circuit on a breadboard. Although it proved the basic function,
it proved too noisy to get any decent results...

![Breadboard](./assets/TransistorCurveTracer_bb.jpg?raw=true)

![TransistorCurveTracer_breadboard_build](./assets/TransistorCurveTracer_breadboard_build.jpg?raw=true)

So I laid it out on a protoboard:

![TransistorCurveTracer_protoboard_layout](./assets/TransistorCurveTracer_protoboard_layout.jpg?raw=true)

Final protoboard build:

![The Build](./assets/TransistorCurveTracer_build.jpg?raw=true)

## Credits and References
* [StairStepGenerator](../StairStepGenerator) project
* [#232: More Circuit Fun: Simple transistor curve tracer using Stairstep generator circuit](https://youtu.be/ZOLLoa2fH24)
* [w2aew's circuit](http://www.qsl.net/w2aew//youtube/curvetracer.pdf)
* Original circuit based on IEE Engineering Sciences & Education Journal Vol 8 No 1 Feb 1999 pp25-26.
* [TL074CN datasheet](http://www.futurlec.com/Linear/TL074CN.shtml)
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [2N3904 datasheet](http://www.futurlec.com/Transistors/2N3904.shtml)
* [2N3906 datasheet](http://www.futurlec.com/Transistors/2N3906.shtml)
* [BJT in Reverse Active Mode of Operation](http://electronics.stackexchange.com/questions/29756/bjt-in-reverse-active-mode-of-operation) - EE.SE
