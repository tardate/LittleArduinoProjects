# #236 AudioDSP/Boost

AudioDSP boost effect based on the pedalSHIELD.

![waveform](./assets/Boost_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

[Boost.ino](./Boost.ino) is a simple clean boost/volume control example from the pedalSHIELD examples.
The pushbuttons control the output volume up and down.

Core algorithm:

* the main loop sets the effect on/off indicator (LED on pin 13)
* input read/output write is handled in the Timer 1 interrupt service routine


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
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/leap236-9-audiodsp-effects.html)
