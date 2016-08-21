# #235 AudioDSP

Build and test an arduino DSP circuit based on the pedalSHIELD by electrosmash.

![The Build](./assets/AudioDSP_build.jpg?raw=true)

## Notes

I've wanted to try some digital signal processing on the Arduino/AVR for a while.
When I found the pedalSHIELD by electrosmash, it seemed like an excellent way to bootstrap some experimentation.

This project is a breadboard-build of a circuit based on the pedalSHIELD, tested with a simple boost/volume control
circuit based on the pedalSHIELD examples.


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


### Output Processing

Little changed from the original pedalSHIELD design at this point.


### Code

[AudioDSP.ino](./AudioDSP.ino) is a simple clean boost/volume control example from the pedalSHIELD examples.
The pushbuttons control the output volume up and down.

Core algorithm:

* the main loop sets the effect on/off indicator (LED on pin 13)
* input read/output write is handled in the Timer 1 interrupt service routine


### Performance

Bottom line:

* it works! It's pretty amazing to jam away in the knowledge that the singal from the guitar is passing through an Arduino before getting to the amp
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


## Construction

![Breadboard](./assets/AudioDSP_bb.jpg?raw=true)

![The Schematic](./assets/AudioDSP_schematic.jpg?raw=true)

![AudioDSP_bb_build](./assets/AudioDSP_bb_build.jpg?raw=true)

### Protoboard Construction

To test the circuit properly, I built it on a protoboard as a makeshift "shield". The circuit has a few modifications:

* no footswitch
* input, output, and ground signals are broken out on 3 pin headers

![AudioDSP_protoboard_layout](./assets/AudioDSP_protoboard_layout.jpg?raw=true)

![The Build](./assets/AudioDSP_build.jpg?raw=true)

## Credits and References
* [pedalSHIELD UNO Arduino Guitar Pedal](http://www.electrosmash.com/pedalshield-uno)
* [pedalSHIELD UNO @ arduino.cc](https://create.arduino.cc/projecthub/electrosmash/arduino-uno-guitar-pedal-b2ba96)
* [LMC6482 datasheet](http://www.futurlec.com/Linear/LMC6482IN.shtml)
* [Configure Arduino UNO PWM outputs to play audio](http://www.electrosmash.com/forum/pedalshield-uno/111-configure-arduino-uno-pwm-outputs-to-play-audio?lang=en)
* [PWM Distortion Analysis](http://www.openmusiclabs.com/learning/digital/pwm-dac/pwm-distortion-analysis/index.html)
