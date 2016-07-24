# #228 TransistorCurveTracer

Simple NPN transistor curve tracer using a Stairstep generator circuit.

![The Build](./assets/TransistorCurveTracer_build.jpg?raw=true)

![curve_2N3904_50kRb](./assets/curve_2N3904_50kRb.gif?raw=true)

## Notes

This is a fascinating circuit, originally from the IEEE Engineering Sciences & Education Journal Vol 8 No 1 Feb 1999 pp25-26.
I'm working from a demonstration by w2aew in [#232: More Circuit Fun: Simple transistor curve tracer using Stairstep generator circuit](https://youtu.be/ZOLLoa2fH24).

It actually builds on the basic [StairStepGenerator](../StairStepGenerator) project and adapts it to perform
basic NPN BJT curve tracing (plotting collector currect to collector voltage for different base current values).

I first built up the circuit on a breadboard, but it proved too noisy to be of much use...
so I put the circuit on protoboard and obtained much better results.

I wouldn't necessarily trust these results for anything other than relative comparisons,
but it is interesting to see the theory play out IRL.

Regardless, it's great fun to fiddle with step frequency, reset freqeuncy and input voltage and see the effects in the X-Y plot.

### Stairstep Generator

I tried a few opamps in the circuit, but I settled on the TL074 as the best of the lot I have available.
It's not rail-to-rail, so I lose about a volt of the top of the output.

Here's a scope trace of the basic stairstep generator

* CH1 reset oscillator output
* CH2 clock signal from the 555
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


### Initial Tests with a 2N3904

For the initial test I had the base resistor for the DUT at 470Ω per the original design.
With this I was getting disappointing results when forward-biasing a 2N3904.
It appears to swing the DUT hard to saturation, so my curves are pretty one dimensional:

![curve_2N3904_470Rb](./assets/curve_2N3904_470Rb.gif?raw=true)

However, when reverse-biased (i.e. switch emitter and collector), and therefore a lower beta/hFE,
I get a much more pleasing result:

![curve_2N3904_reverse_470Rb](./assets/curve_2N3904_reverse_470Rb.gif?raw=true)

### Circuit Improvement and Re-testing a 2N3904

Time to check some calculations. Using a 2N3904 as my model DUT, the datasheet tells me the hFE can range from 40 to 300 for various Vce/Ic combinations.

With a 220Ω resistor on the current mirror and a 5V supply, the collector current could reach [22mA](http://www.wolframalpha.com/input/?i=5V%2F220%CE%A9). At 22mA, the 2N3904 hFE would be around 100 so requires a base current of [0.22mA](http://www.wolframalpha.com/input/?i=5V%2F220%CE%A9%2F100). So a base resistor of around [22kΩ](http://www.wolframalpha.com/input/?i=5V%2F(5V%2F220%CE%A9%2F100)) would be in order. That's a far cry from the 470Ω in the circuit, so no wonder I'm not getting good curves when forward biasing the DUT!

So to fix this and provide some flexibility, I added another 50kΩ trimmer in series with the 470Ω base resistor.
Now I can get some nice curves for a forward-biased DUT, and easily adapt to transistors with different characteristics

Here are the curves for a 2N3904 forward-biased (base resistance set close to 50kΩ):

![curve_2N3904_50kRb](./assets/curve_2N3904_50kRb.gif?raw=true)



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
