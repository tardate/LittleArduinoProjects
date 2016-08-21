# #237 AudioDSP/Distortion

AudioDSP distortion effect based on the pedalSHIELD.

## Notes

[Distortion.ino](./Distortion.ino) is a simple distortion effect from the pedalSHIELD examples.
The pushbuttons control the distorion level up and down.

Core algorithm:

* input value is clipped by the distortion level read/set by the push-buttons


### AudioDspDriver Library

This example uses a private [AudioDspDriver](../../../libraries/AudioDspDriver) library
that contains my refactoring of the core algorithms for driving the board.
I may split this out as a stand-alone library at some point.


## Construction

![Breadboard](../assets/AudioDSP_bb.jpg?raw=true)

![The Schematic](../assets/AudioDSP_schematic.jpg?raw=true)

![The Build](./assets/Distortion_build.jpg?raw=true)

## Credits and References
* see the main [AudioDSP](../) project
