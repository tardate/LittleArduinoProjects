# #238 AudioDSP/Crunch

AudioDSP crunchy distortion effect based on the pedalSHIELD.

![waveform](./assets/Crunch_build.jpg?raw=true)

## Notes

[Crunch.ino](./Crunch.ino) is a crunchy distortion effect from the pedalSHIELD examples.
The pushbuttons control the mixing of the original and distorted signal.

Core algorithm:

* distortion is derived from an asymmetrical clipping system based on Schetzen formula


### AudioDspDriver Library

This example uses a private [AudioDspDriver](../../../libraries/AudioDspDriver) library
that contains my refactoring of the core algorithms for driving the board.
I may split this out as a stand-alone library at some point.


## Construction

![Breadboard](../assets/AudioDSP_bb.jpg?raw=true)

![The Schematic](../assets/AudioDSP_schematic.jpg?raw=true)

![Build](../assets/AudioDSP_build.jpg?raw=true)


## Credits and References
* see the main [AudioDSP](../) project
* [Several Codes based on PedalSHIELD Library](http://www.electrosmash.com/forum/software-pedalshield/133-several-codes-based-on-pedalshield-library?lang=en)
