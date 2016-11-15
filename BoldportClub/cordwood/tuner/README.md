# cordwood/tuner

Use the Boldport Cuttle & Cordwood as a guitar tuner.

![Build](./assets/tuner_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The Cordwood has six LEDs. Six is one of my favourite numbers .. like the number of strings on a standard guitar.

So is it possible to use the Cordwood to detect (even tune) the six strings of a guitar?

I was thinking about doing a complete analogue solution with bandpass filters (probably active filters in order to get
very tight passband frequencies). Maybe later, but to start I wanted to try an Arduino-based approach
I'd seen in an [Instructables article](http://www.instructables.com/id/Arduino-Guitar-Tuner/?ALLSTEPS) by Nicole Grimwood.

I've modified the circuit to take an input from an electret so I can use it with acoustic instruments,
and adjusted the OpAmp configuration for simple single-supply operation using a basic LM386 audio amp.

the electret microphone is biased with a 10kΩ resistor and coupled to the amplifier with 100nF capacitor.

The LM386 uses a standard 200x gain configuration with a 10µF gain control and 10µF bypass capacitors.

On the output:

* 22kΩ voltage divider and 220µF capacitor biases the output to VCC/2
* a low-pass filter at a corner frequency of [723Hz](http://www.wolframalpha.com/input/?i=1%2F(2%CF%80+*+2.2k%CE%A9+*+100nF)) cuts out most of the high frequency harmonics and noise that just confused the tuning algorithms

## Arduino Sketch

The initial code is from the [Instructables article](http://www.instructables.com/id/Arduino-Guitar-Tuner/?ALLSTEPS) by Nicole Grimwood.

I think I'll be making some simplifications and improvements, but the initial commit is verbatim the original code shared on Instructables.

## Construction

![Breadboard](./assets/tuner_bb.jpg?raw=true)

![Schematic](./assets/tuner_schematic.jpg?raw=true)

![Build](./assets/tuner_build.jpg?raw=true)

## Credits and References
* [Arduino Guitar Tuner](http://www.instructables.com/id/Arduino-Guitar-Tuner/?ALLSTEPS) by nikoala3/Nicole Grimwood
* [Arduino Frequency Detection](http://www.instructables.com/id/Arduino-Frequency-Detection/?ALLSTEPS) by amandaghassaei
* [Guitar tunings](https://en.wikipedia.org/wiki/Guitar_tunings) - wikipedia
* [Passive Low Pass Filter](http://www.electronics-tutorials.ws/filter/filter_2.html)
* [Low Pass Filter Calculator](http://www.learningaboutelectronics.com/Articles/Low-pass-filter-calculator.php)
