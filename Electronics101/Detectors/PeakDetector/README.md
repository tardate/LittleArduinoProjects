# #121 Peak Detector

OpAmp-based peak detector

## Notes

[w2aew](https://youtu.be/Fn5kHhNRsz0)
has a nice, clear video on youtube explaining peak detector circuits.

[![clip](https://img.youtube.com/vi/Fn5kHhNRsz0/0.jpg)](https://www.youtube.com/watch?v=Fn5kHhNRsz0)

See [LEAP#120 Simple Peak Detector](../SimplePeakDetector) for an example of the simplest diode-RC based peak detector.

This project adds an OpAmp (LM741) to eliminate the diode-forward voltage issue.
The 741 is not the best choice for this since I'm running it with a single supply,
but as long as the input signal is above ~VCC/2 it works well enough to demonstrate the improvement
over the basic diode-RC detector.

As with the basic circuit, the RC pair is responsible for holding the peak for a period governed by the [RC time constant (𝛕)](http://en.wikipedia.org/wiki/RC_time_constant).

Time to fully discharge is approximately 5𝛕, or in this case, about [5 seconds](https://www.wolframalpha.com/input/?i=5*10%C2%B5F*100k%CE%A9).
Appropriate values for the RC network depend on the signal frequency being sampled (higher frequencies
will be better served by a shorter time constant).

Feedback from the output node to the inverting OpAmp input will force the OpAmp to eliminate the diode voltage drop in the output (as best it can).

Here's a sample trace recorded using [LEAP#090 PlotNValues (a simple Processing sketch)](https://leap.tardate.com/playground/plotnvalues/)

* upper trace is the output of the peak detector
* lower trace is the signal input (a variable "triangle" wave in this test)

![processing trace](./assets/processing_trace.png?raw=true)

## Construction

![Breadboard](./assets/PeakDetector_bb.jpg?raw=true)

![The Schematic](./assets/PeakDetector_schematic.jpg?raw=true)

![The Build](./assets/PeakDetector_build.jpg?raw=true)

## Credits and References

* [LEAP#120 Simple Peak Detector](../SimplePeakDetector) - diode-RC based peak detector project
* [#77: Op Amp Peak Detector Tutorial, with peak detector basics](https://youtu.be/Fn5kHhNRsz0) - w2aew's coverage of the basic circuit, and the improved OpAmp-based circuit
