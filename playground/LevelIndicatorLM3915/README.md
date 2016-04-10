# #065 LevelIndicatorLM3915

Drive a 10-segment display with a single Arduino pin.

Here's a quick video of the circuit in action:

[![LevelIndicatorLM3915 demo](http://img.youtube.com/vi/00BBIDRA13Y/0.jpg)](http://www.youtube.com/watch?v=00BBIDRA13Y)

## Notes

The LM3915 is a 10-segment Dot/Bar Display Driver.

It is primarily intended for audio level indicator applications, as it divides the 10 segments along a log scale of 3 dB/step.

But that doesn't mean it can't be used for other purposes.
This project is a demonstration of driving the display directly with a single PWM pin.

A second digital pin is used to toggle the dot/bar display mode:

* "dot" mode is where a single element lights to display the peak value
* "bar" mode is where all elements light up in bar-graph fashion

Although when driving the PWM, the dot mode is not particularly useful without further processing of the
PWM output to provide a more constant input voltage.

As per the datasheet, there are various ways of setting the voltage reference.
Here I'm using R1=1kΩ and R2=1kΩ, which sets the voltage reference at
[2.58V](http://www.wolframalpha.com/input/?i=1.25V%281+%2B+1k%CE%A9%2F1k%CE%A9%29+%2B+80%CE%BCA*1k%CE%A9).

In effect this means that when input signal reaches 2.58V, that is enough for the final LED to light.
NB: according to my multimeter the actual voltage required is 2.53V, no doubt due to small variations in component values within normal tolerances.

Hooking up and Arduino to drive the display with a PWM output requires some smoothing of the output
to achieve a stable reference voltage. The C3/R6 RC filter performs this function - at least enough for bar display, but not sufficient for a crisp dot display.

It's interesting to note that the SIGNAL input draws no current (verified with in-circuit measurement),
as according to the datasheet block diagram, the SIGNAL input is used to drive an OpAmp buffer circuit.

Total current drawn by the circuit with all LEDs on is 34.4mA, well within the specs for the Arduino 5V pin, hence why
the circuit does not require a dedicated power supply.

## Construction

![The Breadboard](./assets/LevelIndicatorLM3915_bb.jpg?raw=true)

![The Schematic](./assets/LevelIndicatorLM3915_schematic.jpg?raw=true)

![The Build](./assets/LevelIndicatorLM3915_build.jpg?raw=true)

## Credits and references
* [LM3915 datasheet](http://www.futurlec.com/Linear/LM3915N.shtml)
* [AudioLevelIndicatorKit](../../Electronics101/AudioLevelIndicatorKit) - project using the LM3915 in an audio level kit build
