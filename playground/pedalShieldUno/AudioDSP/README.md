# #250 pedalShieldUno/AudioDSP

Test and develop the AudioDSP library for programming the pedalSHIELD Uno.

## Notes

When I built the [AudioDSP](../../AudioDSP) pedalSHIELD UNO clone to investigate it's operation,
I started collecting my code in a class library [AudioDspDriver](../../../libraries/AudioDspDriver).

I'm liking the encapsulation and reuse it provides over just hacking sketches based on
the pedalSHIELD examples, but I wouldn't say it's ready to be raised in status as a published library yet.

So this project is an exercise in putting the (private) [AudioDspDriver](../../../libraries/AudioDspDriver) library
though it's paces by first testing how it can be used to implement the equivalent of all the
pedalSHIELD UNO examples.

The scope traces below are all captured with a 600mV 1kHz input signal on CH1.
CH2 is the output.


### bit_crusher

This effect boosts the signal into overdrive (level determined by the pushbuttons).
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![bit_crusher_psu](./assets/bit_crusher_psu.gif?raw=true)

AudioDSP version:
![bit_crusher_adsp](./assets/bit_crusher_adsp.gif?raw=true)


### booster

A simple volume boost (level determined by the pushbuttons).
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![booster_psu](./assets/booster_psu.gif?raw=true)

AudioDSP version:
![booster_adsp](./assets/booster_adsp.gif?raw=true)


### clean

A simple identity transformation. Input == output.
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![clean_psu](./assets/clean_psu.gif?raw=true)

AudioDSP version:
![clean_adsp](./assets/clean_adsp.gif?raw=true)


### daft_punk_octaver

Effectively downsamples the input (level determined by the pushbuttons).
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![daft_punk_octaver_psu](./assets/daft_punk_octaver_psu.gif?raw=true)

AudioDSP version:
![daft_punk_octaver_adsp](./assets/daft_punk_octaver_adsp.gif?raw=true)


### delay

Mixes a delayed signal with the input in equal proportions (delay depth determined by the pushbuttons).
The implementation is a little different to the pedalSHIELD example (which appears a little broken).

Because of memory limitations in the Uno, the delay depth is pretty short, so the effect is more like a light reverb.

pedalSHIELD UNO example:
![delay_psu](./assets/delay_psu.gif?raw=true)

AudioDSP version:
![delay_adsp](./assets/delay_adsp.gif?raw=true)


### distortion

Performs an asymmetrical clipping (top-side) to a level determined by the pushbuttons.
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![distortion_psu](./assets/distortion_psu.gif?raw=true)

AudioDSP version:
![distortion_adsp](./assets/distortion_adsp.gif?raw=true)


### fuzz

Performs a symmetrical clipping and boost to a level determined by the pushbuttons -
signals above the threshold are thrown to the upper/lower rail.
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![fuzz_psu](./assets/fuzz_psu.gif?raw=true)

AudioDSP version:
![fuzz_adsp](./assets/fuzz_adsp.gif?raw=true)


### metronome

Generates a metronome tone, at a frequency determined by the pushbuttons.
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![metronome_psu](./assets/metronome_psu.gif?raw=true)

AudioDSP version:
![metronome_adsp](./assets/metronome_adsp.gif?raw=true)


### monitor

Performs a clean transform of the guitar signal, and logs the settings to the serial port.
The implementation here varies from the pedalSHIELD example, in the logging to serial is not done inside the interrupt routine.
this ensures that the guitar sounds gets through to the interrupt, but at the expense of not logging every sample.

AudioDSP version:
![monitor_adsp](./assets/monitor_adsp.png?raw=true)


### signal_generator

Generates a tone described in a provided dataset.
The implementation here is pretty much identical to the pedalSHIELD example.

pedalSHIELD UNO example:
![signal_generator_psu](./assets/signal_generator_psu.gif?raw=true)

AudioDSP version:
![signal_generator_adsp](./assets/signal_generator_adsp.gif?raw=true)


### tremelo

Modulates the signal volume at a speed governed by the pushbutton setting.
The implementation here is similar to the pedalSHIELD example.

pedalSHIELD UNO example:
![tremelo_psu](./assets/tremelo_psu.gif?raw=true)

AudioDSP version:
![tremelo_adsp](./assets/tremelo_adsp.gif?raw=true)


## Credits and References
* [pedalShieldUno](../pedalShieldUno) - project
* [AudioDSP](../../AudioDSP) - project
