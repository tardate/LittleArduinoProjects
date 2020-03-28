# #120 Simple Peak Detector

The basic diode-RC peak detector.

## Notes

[Afrotechmods](https://youtu.be/ic_yEUV7Y3c)
and
[w2aew](https://youtu.be/Fn5kHhNRsz0)
both have some nice, clear videos on youtube explaining peak detector circuits.

[![clip](https://img.youtube.com/vi/ic_yEUV7Y3c/0.jpg)](https://www.youtube.com/watch?v=ic_yEUV7Y3c)

[![clip](https://img.youtube.com/vi/Fn5kHhNRsz0/0.jpg)](https://www.youtube.com/watch?v=Fn5kHhNRsz0)

The most basic circuit uses a diode to rectify an incoming AC signal, and a capacitor to charge and hold
the peak value. The RC pair holds the peak for a period governed by the [RC time constant (𝛕)](http://en.wikipedia.org/wiki/RC_time_constant).

Time to fully discharge is approximately 5𝛕, or in this case, about [5 seconds](https://www.wolframalpha.com/input/?i=5*10%C2%B5F*100k%CE%A9).

Appropriate values for the RC network depend on the signal frequency being sampled (higher frequencies
will be better served by a shorter time constant).

The main problem with this circuit is the fact we lose the diode forward voltage from the output, resulting in offset measurements and an equivalent minimum input voltage sensitivity.

Here's a sample trace recorded using [PlotNValues (a simple Processing sketch)](../../../processing/PlotNValues)

* upper trace is the output of the peak detector
* lower trace is the signal input (a rough triangle wave source in this test)

![processing trace](./assets/processing_trace.png?raw=true)

## Construction

![Breadboard](./assets/SimplePeakDetector_bb.jpg?raw=true)

![The Schematic](./assets/SimplePeakDetector_schematic.jpg?raw=true)

![The Build](./assets/SimplePeakDetector_build.jpg?raw=true)

## Credits and References

* [LEAP#121 PeakDetector](../PeakDetector) - OpAmp-based peak detector project
* [Peak detector circuits!](https://youtu.be/ic_yEUV7Y3c) - Afrotechmods
* [#77: Op Amp Peak Detector Tutorial, with peak detector basics](https://youtu.be/Fn5kHhNRsz0) - w2aew's coverage of the basic circuit, and the improved OpAmp-based circuit
