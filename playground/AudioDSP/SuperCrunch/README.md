# #239 AudioDSP/SuperCrunch

AudioDSP crunchy symmetrical Schetzen distortion effect based on the pedalSHIELD.

![waveform](./assets/SuperCrunch_build.jpg?raw=true)



[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

[SuperCrunch.ino](./SuperCrunch.ino) is a crunchy distortion effect from the pedalSHIELD examples.
The pushbuttons control the volume of the output signal.

Core algorithm:

* distortion is derived on a symmetrical clipping system based on Schetzen formula

Schetzen Formula for symmetrical soft clipping is as follows:

```
         { 2*x                for  0  <= |x| <= 1/3  }
f(x) =   { (3-(2-3*x)^3)/3    for 1/3 <= |x| <= 2/3 }
         { 1                  for 2/3 <= |x| <= 1   }
```

### Performance

A vast improvement on the asymmetrical [Crunch](../Crunch),
and a much warmer fuzz than the simple clipping of [Distortion](../Distortion).

Delivers quite a warm crunch with pretty good frequency response, although the upper registers of the guitar
are a bit beyond the capability of the Arduino.


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
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/leap236-9-audiodsp-effects.html)
