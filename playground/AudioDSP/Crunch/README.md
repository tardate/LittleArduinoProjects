# #238 AudioDSP/Crunch

AudioDSP crunchy distortion effect based on the pedalSHIELD.

![waveform](./assets/Crunch_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

[Crunch.ino](./Crunch.ino) is a crunchy distortion effect from the pedalSHIELD examples.
The pushbuttons control the volume of the output signal.

Core algorithm:

* distortion is derived from an asymmetrical clipping system based on Schetzen formula

### Performance

Not so great. The asymmetrical algorithm results in a fat bottom end but some annoying high-frequency distortion.

See [SuperCrunch](../SuperCrunch) for the symmetrical version, which is much more pleasing.

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
* [..as mentioned on my blog](http://blog.tardate.com/2017/01/leap236-9-audiodsp-effects.html)
