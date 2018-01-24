# #237 AudioDSP/Distortion

AudioDSP simple distortion effect based on the pedalSHIELD.

Here's an example of the effect on a 1kHz 200mV signal at about mid-level clipping:

![waveform](./assets/Distortion_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

[Distortion.ino](./Distortion.ino) is a simple distortion effect from the pedalSHIELD examples.
The pushbuttons control the distortion clipping level up and down.

Core algorithm:

* input value is simply clipped by the distortion level set by the push-buttons


### Performance

Not bad, but a fairly crude fuzz effect. There's a bit too much high frequency buzz in the result
due to the hard clipping. See [SuperCrunch](../SuperCrunch) for what I think is a bettery fuzz.


### AudioDspDriver Library

This example uses a private [AudioDspDriver](../../../libraries/AudioDspDriver) library
that contains my refactoring of the core algorithms for driving the board.
I may split this out as a stand-alone library at some point.


## Construction

![Breadboard](../assets/AudioDSP_bb.jpg?raw=true)

![The Schematic](../assets/AudioDSP_schematic.jpg?raw=true)

![The Build](../assets/AudioDSP_build.jpg?raw=true)

## Credits and References
* see the main [AudioDSP](../) project
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/leap236-9-audiodsp-effects.html)
