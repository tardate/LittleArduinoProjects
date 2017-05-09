# #250 pedalShieldUno/AudioDSP

Test and develop the AudioDSP library for programming the pedalSHIELD Uno.

![AudioDSP_build](./assets/AudioDSP_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

When I built the [AudioDSP](../../AudioDSP) pedalSHIELD UNO clone to investigate its operation,
I started collecting my code in a class library [AudioDspDriver](../../../libraries/AudioDspDriver).

I'm liking the encapsulation and reuse it provides over just hacking sketches based on
the pedalSHIELD examples, but I wouldn't say it's ready to be raised in status as a published library yet.

So this project is an exercise in putting the (private) [AudioDspDriver](../../../libraries/AudioDspDriver) library
though its paces by first testing how it can be used to implement the equivalent of all the
pedalSHIELD UNO examples.

The scope traces below are all captured with a 600mV 1kHz input signal on CH1.
CH2 is the output.


### bit_crusher

Sketch: [bit_crusher.ino](./bit_crusher/bit_crusher.ino)

This effect boosts the signal into overdrive (level determined by the pushbuttons).
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![bit_crusher_psu](./assets/bit_crusher_psu.gif?raw=true)

AudioDSP version:
![bit_crusher_adsp](./assets/bit_crusher_adsp.gif?raw=true)


### booster

Sketch: [booster.ino](./booster/booster.ino)

A simple volume boost (level determined by the pushbuttons).
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![booster_psu](./assets/booster_psu.gif?raw=true)

AudioDSP version:
![booster_adsp](./assets/booster_adsp.gif?raw=true)


### clean

Sketch: [clean.ino](./clean/clean.ino)

A simple identity transformation. Input == output.
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![clean_psu](./assets/clean_psu.gif?raw=true)

AudioDSP version:
![clean_adsp](./assets/clean_adsp.gif?raw=true)


### daft_punk_octaver

Sketch: [daft_punk_octaver.ino](./daft_punk_octaver/daft_punk_octaver.ino)

Effectively downsamples the input (level determined by the pushbuttons).
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![daft_punk_octaver_psu](./assets/daft_punk_octaver_psu.gif?raw=true)

AudioDSP version:
![daft_punk_octaver_adsp](./assets/daft_punk_octaver_adsp.gif?raw=true)


### delay

Sketch: [delay.ino](./delay/delay.ino)

Mixes a delayed signal with the input in equal proportions (delay depth determined by the pushbuttons).
The implementation is a little different to the pedalSHIELD example (which appears a little broken).

Because of memory limitations in the Uno, the delay depth is pretty short, so the effect is more like a light reverb.


### distortion

Sketch: [distortion.ino](./distortion/distortion.ino)

Performs an asymmetrical clipping (top-side) to a level determined by the pushbuttons.
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![distortion_psu](./assets/distortion_psu.gif?raw=true)

AudioDSP version:
![distortion_adsp](./assets/distortion_adsp.gif?raw=true)


### fuzz

Sketch: [fuzz.ino](./fuzz/fuzz.ino)

Performs a symmetrical clipping and boost to a level determined by the pushbuttons -
signals above the threshold are thrown to the upper/lower rail.
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![fuzz_psu](./assets/fuzz_psu.gif?raw=true)

AudioDSP version:
![fuzz_adsp](./assets/fuzz_adsp.gif?raw=true)


### metronome

Sketch: [metronome.ino](./metronome/metronome.ino)

Generates a metronome tone, at a frequency determined by the pushbuttons.
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![metronome_psu](./assets/metronome_psu.gif?raw=true)


### monitor

Sketch: [monitor.ino](./monitor/monitor.ino)

Performs a clean transform of the guitar signal, and logs the settings to the serial port.
The implementation here varies from the pedalSHIELD example, in the logging to serial is not done inside the interrupt routine.
this ensures that the guitar sounds gets through to the interrupt, but at the expense of not logging every sample.

AudioDSP version:
![monitor_adsp](./assets/monitor_adsp.png?raw=true)


### signal_generator

Sketch: [signal_generator.ino](./signal_generator/signal_generator.ino)

Generates a tone described in a provided dataset.
The implementation here is pretty much identical to the pedalSHIELD example.


### tremelo

Sketch: [tremelo.ino](./tremelo/tremelo.ino)

Modulates the signal volume at a speed governed by the pushbutton setting.
The implementation here is similar to the pedalSHIELD example.



## Credits and References
* [pedalShieldUno](../pedalShieldUno) - project
* [AudioDSP](../../AudioDSP) - project
* [..as mentioned on my blog](http://blog.tardate.com/2017/02/leap250-audiodsp-library-for-the-pedalshield-uno.html)
