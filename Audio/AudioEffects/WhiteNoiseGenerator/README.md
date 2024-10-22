# #474 BJT White Noise Generator

Building a common white noise generator circuit and optimising it for 9V operation with BC337 transistors.

![Build](./assets/WhiteNoiseGenerator_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/f4c5FJrZLs8/0.jpg)](https://www.youtube.com/watch?v=f4c5FJrZLs8)

## Notes

Reverse-biased diodes and transistor base-emitter junctions exhibit a Zener effect when they breakdown and produce
["shot noise"](https://en.wikipedia.org/wiki/Noise_generator).

There's a very common circuit using S9014 transistors as a white noise generator.
One transistor produces the noise, and a few amplification and buffer stages are added to provide line and headphone output.

It shows up in kits like the EQKit "White Noise Generator".
This is widely available, for example from [a seller on aliexpress](https://www.aliexpress.com/item/White-Noise-Signal-Generator-DIY-Kit-Electronic-Kit-2-Channel-Output-for-Burn-in-Test-Therapy/32922270112.html).
Martyn Davies has a very good construction tutorial on Youtube:

[![clip](https://img.youtube.com/vi/7oDUU85V-Wk/0.jpg)](https://www.youtube.com/watch?v=7oDUU85V-Wk)

I started off simply testing the circuit on a breadboard - it works very well!
However it does require 11-12V to get the noise started,
so I set out to see if there are ways of producing the effect at lower voltages.

Performance is very particular to the transistor model, but I was able to ultimately
discover that the BC337 NPN produces a noise effect as good as the S9014 but running at 9V.

## S9014 Circuit Performance

The circuit has an intermediate buffer stage to support a line out,
followed by a headphone output with volume control.

![WhiteNoiseGeneratorS9014_schematic](./assets/WhiteNoiseGeneratorS9014_schematic.jpg?raw=true)

![WhiteNoiseGeneratorS9014_bb](./assets/WhiteNoiseGeneratorS9014_bb.jpg?raw=true)

Running on a breadboard:

![WhiteNoiseGeneratorS9014_bb_build](./assets/WhiteNoiseGeneratorS9014_bb_build.jpg?raw=true)

It produces a flat frequency response in the audio range; in other words good white noise:

![scope_S9014_12V_fft](./assets/scope_S9014_12V_fft.gif?raw=true)

## Evaluating a Range of Transistors

Reverse biasing the S9014 to produce shot noise requires at least an 11V.
To run the entire circuit on a lower voltage, I tested a range of
other transistors. My Results are summarised in the following table:


| Transistor | Performance                           |
|------------|---------------------------------------|
| S9014      | very good > 11V                       |
| BC337      | very good at 9V                       |
| 2N3904     | works but smaller noise signal; >11V  |
| S8050      | similar to S9014, but >=12V  required |
| C1815      | response is peaky; >9V                |
| C945       | response not flat; 9V                 |
| A42        | squeaks and squarks                   |
| A42        | squeaks and squarks                   |
| S9013      | squeaks and squarks                   |
| S9018      | no noise at 12V                       |
| 2N5551     | no noise at 12V                       |
| TIP122     | squeaks and squarks                   |
| D882       | squeaks and squarks                   |

When I state response is not flat or peaky, I mean the response is not flat across the audio
spectrum. For example, here's the FFT for C945, showing a valley and peak < 1kHz.

![scope_C945_9V_fft](./assets/scope_C945_9V_fft.gif?raw=true)

## Final BC337 Build

To my ears, the BC337 produces white noise just as well as the S9014.
The BC337's I have a category 25, with a ß typically 160-400.

I dropped the line output and intermediate buffer stages for this build, reducing the circuit to three stages:

* noise generator
* [collector-feedback biased](https://en.wikipedia.org/wiki/Bipolar_transistor_biasing#Collector_feedback_bias) amplifier
* volume control and headphone driver

![Schematic](./assets/WhiteNoiseGenerator_schematic.jpg?raw=true)

![Breadboard](./assets/WhiteNoiseGenerator_bb.jpg?raw=true)

Running on a breadboard:

![WhiteNoiseGenerator_bb_build](./assets/WhiteNoiseGenerator_bb_build.jpg?raw=true)

I then decided to transfer to a little project box with power in one end and noise out the other,
and ugly freeform wiring in between:

![Build](./assets/WhiteNoiseGenerator_build.jpg?raw=true)

Hooked up for a final test:

![WhiteNoiseGenerator_final_test](./assets/WhiteNoiseGenerator_final_test.jpg?raw=true)


## Performance

While replacing the S9014 transistors with BC337-25 allows the circuit to run at a nominal 9V with only a 8mA,
if the voltage drops much below 8.9V, it does not generate noise. This makes operation from 9V batteries a bit problemmatic
unless they are brand new.

The noise generate has very flat response across the audio spectrum (measured at the audio output):

![scope_BC337_9V_fft](./assets/scope_BC337_9V_fft.gif?raw=true)

And this is what it looks like in the time domain:

![scope_BC337_9V](./assets/scope_BC337_9V.gif?raw=true)


## Credits and References

* [S9014 datasheet](https://www.futurlec.com/Transistors/S9014.shtml)
* [BC337 datasheet](https://www.futurlec.com/Transistors/BC337.shtml)
* [Noise generator](https://en.wikipedia.org/wiki/Noise_generator) - wikipedia
* [White Noise Signal Generator DIY Kit](https://www.aliexpress.com/item/White-Noise-Signal-Generator-DIY-Kit-Electronic-Kit-2-Channel-Output-for-Burn-in-Test-Therapy/32922270112.html) - kit from a seller on aliexpress
* [Banggood's Construction Guide for the EQKit version](https://files.banggood.com/2017/18.01/SG-10-Noise-signal-generator-kit.pdf)
* [collector-feedback biasing](https://en.wikipedia.org/wiki/Bipolar_transistor_biasing#Collector_feedback_bias) - wikipedia
