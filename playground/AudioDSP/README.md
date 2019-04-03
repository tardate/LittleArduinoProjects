# #235 AudioDSP

Build and test an arduino DSP circuit based on the pedalSHIELD by electrosmash.

![The Build](./assets/AudioDSP_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I've wanted to try some digital signal processing on the Arduino/AVR for a while.
When I found the pedalSHIELD by electrosmash, it seemed like an excellent way to bootstrap some experimentation.


This project was initially a breadboard-build of a circuit based on the pedalSHIELD, tested with a simple boost/volume control
circuit based on the pedalSHIELD examples. I wanted to see if it was even half-way decent.
When that worked out, I put it on protoboard and did a bit more work on the software.

I also purchased the genuine article from electrosmash as a way of supporting the creators and also
getting a standard unit for comparison - see [LEAP#247 pedalShieldUno](../pedalShieldUno) for more on that.


### Input Processing

I first built the circuit according to the pedalSHIELD schematics, but found that the input chain was prone to
clipping and distorting a guitar input signal. I'd prefer a clean signal in, so that any effects are due
to the DSP algorithms and later stages, so I made a few modifications:

* adjusted to ~50kΩ input impedance
* biased the signal to a DC offset of ~ VCC/2
* removed the 6.8nF capacitor/filter
* changed R4 from 4.7kΩ to 10kΩ to avoid clipping at minimum attenuation (RV1)


### Input/Output Gain Stage

The most suitable OpAmp I had on hand was an LMC6482 CMOS Dual Rail-To-Rail Input and Output Operational Amplifier.
This prove to work just fine, and with very low power consumption too - all the external circuitry to the Arduino is
only drawing about 0.5mA in full operation.


### DAC Output Processing

Since the Arduino lacks a precision digital-to-analog output, the output audio waveforms
are generated using a neat trick with PWM and RC filter.

It's possible to use one of more PWM signals, but I'm using two as in the pedalSHIELD design.
Basically the two PWM ouputs are set to the high and low bytes of the desired frequency, then mixed with
an RC ladder/filter. This reconstitutes (approximately) the desired analog waveform.

Details and more links are available in the article: [Configure Arduino UNO PWM outputs to play audio](http://www.electrosmash.com/forum/pedalshield-uno/111-configure-arduino-uno-pwm-outputs-to-play-audio?lang=en).

For two PWM signals, the resistor selection is
R10=4.7kΩ, and [R11 = 1.2MΩ](https://www.wolframalpha.com/input/?i=2%5E8+*+4.7k%CE%A9) (2^n * R10)

With C7=10nF, corner frequency is around [3.38kHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80+*+4.7k%CE%A9+*+10nF)).
This might explain why I'm seeing performance radically drop off over 4kHz (see next section on Performance).


### Performance

Bottom line:

* it works! It's pretty amazing to jam away in the knowledge that the signal from the guitar is passing through an Arduino before getting to the amp
* performance starts to drops off significantly from about 4kHz and by 8kHz it is down in the noise.

I'd like to think it is possible to get better higher frequency performance from the circuit - ideally up to 20kHz -
but that needs a bit more investigation. The processor should be capable, but I think the limitation is in the
PWM signal generation and mixing/filtering in the output stage.

In the following scope traces:

* CH1 - the input signal (FX in)
* CH2 - the final output signal (FX out)

Here's a trace of a 1kHz 200mV signal at minimum input attenuation and default (mid-point) volume boost:

![sine_1k](./assets/sine_1k.gif?raw=true)

And in the FFT of the output there's a strong fundamental:

![sine_1k_fft](./assets/sine_1k_fft.gif?raw=true)

At 2kHz the signal is attenuated:

![sine_2k](./assets/sine_2k.gif?raw=true)

And the 2kHz output FFT shows more noise and harmonics

![sine_2k_fft](./assets/sine_2k_fft.gif?raw=true)

At 4kHz the signal is significantly attenuated:

![sine_4k](./assets/sine_4k.gif?raw=true)

And the 4kHz output FFT shows more noise and harmonics

![sine_4k_fft](./assets/sine_4k_fft.gif?raw=true)

By 8kHz the signal is pretty much destroyed:

![sine_8k](./assets/sine_8k.gif?raw=true)

And the 8kHz output FFT shows the signal pretty much drowned by noise and harmonics

![sine_8k_fft](./assets/sine_8k_fft.gif?raw=true)

#### Attempting to improve the Frequency Response

With C7=10nF, corner frequency is around [3.38kHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80+*+4.7k%CE%A9+*+10nF)).
This might explain why I'm seeing performance radically drop off over 4kHz (see next section on Performance).

At 4kHz, the signal looks like this:

![sine_4khz_103](./assets/sine_4khz_103.gif?raw=true)

With C7=1nF, the corner frequency is around [33.86kHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80+*+4.7k%CE%A9+*+1nF)),
so I was hoping for a better response.

But at 4kHz, the signal shows somewhat less attenuation, but at the expense of an increase in noise:

![sine_4khz_102](./assets/sine_4khz_102.gif?raw=true)

So no magic bullet. I replaced C7=10nF for the remainder of my tests (I actually put some pin headers on the board so I can swap C7 at will).

### Code

I've refactored the core routines into a private [AudioDspDriver](../../libraries/AudioDspDriver) library,
so it can be shared amongst some examples. I may split this out as a stand-alone library at some point.

See the following for the examples I've tested so far:

* [Boost](./Boost) is a simple clean boost/volume control
* [Distortion](./Distortion) is a simple clipping distortion effect
* [Crunch](./Crunch) is a distortion effect using asymmetrical clipping based on Schetzen formula
* [SuperCrunch](./SuperCrunch) is a distortion effect using symmetrical clipping based on Schetzen formula


## Construction

![Breadboard](./assets/AudioDSP_bb.jpg?raw=true)

![The Schematic](./assets/AudioDSP_schematic.jpg?raw=true)

![AudioDSP_bb_build](./assets/AudioDSP_bb_build.jpg?raw=true)

### Protoboard Construction

To test the circuit properly, I built it on a protoboard as a makeshift "shield". The circuit has a few modifications:

* no footswitch
* input, output, and ground signals are broken out on 3 pin headers

In my first build (and the diagram below) I got the pushbuttons flipped (compared to the standard pedalSHIELD layout).

The correct orientation is:

* Right: SW3, connects to A4
* Left: SW4, connects to A5

![AudioDSP_protoboard_layout](./assets/AudioDSP_protoboard_layout.jpg?raw=true)

![The Build](./assets/AudioDSP_build.jpg?raw=true)

## Credits and References
* [LEAP#247 pedalShieldUno](../pedalShieldUno) - my build of the genuine kit
* [pedalSHIELD UNO Arduino Guitar Pedal](http://www.electrosmash.com/pedalshield-uno)
* [pedalSHIELD UNO @ arduino.cc](https://create.arduino.cc/projecthub/electrosmash/arduino-uno-guitar-pedal-b2ba96)
* [LMC6482 datasheet](https://www.futurlec.com/Linear/LMC6482IN.shtml)
* [Configure Arduino UNO PWM outputs to play audio](http://www.electrosmash.com/forum/pedalshield-uno/111-configure-arduino-uno-pwm-outputs-to-play-audio?lang=en)
* [PWM Distortion Analysis](http://www.openmusiclabs.com/learning/digital/pwm-dac/pwm-distortion-analysis/index.html)
* [Arduino Audio Input](https://www.instructables.com/id/Arduino-Audio-Input/?ALLSTEPS) - TL072 front-end project
* [ArduinoDSP](https://github.com/telamon/ArduinoDSP) - another DSP project for Arduino
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/leap235-audiodsp-diy-shield-for-arduino.html)
