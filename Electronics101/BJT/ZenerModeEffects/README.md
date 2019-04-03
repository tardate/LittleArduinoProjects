# #140 BJT Zener-Mode Effects

Playing around with some zener-mode sound effects.

Here's a quick video of the circuit in action. It also shows what happens when you remove the BJT noise generator:

[![BJTZenerModeEffects](https://img.youtube.com/vi/YW7aQzy5-SY/0.jpg)](https://www.youtube.com/watch?v=YW7aQzy5-SY)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I've
[been reading](http://electronics.stackexchange.com/questions/156561/bjt-in-reverse-avalanche-mode)
about BJT behaviour in reverse breakdown, aka "zener mode".
This is not a conventional operating mode, but appears to be commonly exploited as a noise generator.

The classic application is for steam engine sound effects.
In fact, I discovered this patent from 1975: [Sound Simulator for Model Steam Engine US Patent 3,913,097](http://www.google.com/patents/US3913097)
It's a patent for the steam engine simulator, not zener breakdown per se:

    ... Thus a current I passes through the current limiting resistor 45 to the emitter of the transistor Q4.
    There is a breakdown from emitter to base of the transistor Q4 resulting in the current flow to ground.
    It is well-known that such an occurrence will cause a white noise signal to be generated which signal is
    transmitted through the capacitor 46 ...

I started off with a circuit based on this
[Steam Engine Simulator](http://www.talkingelectronics.com/projects/TheTransistorAmplifier/TheTransistorAmplifier-P2.html#MORE)
circuit. Note that the "chuffing" is not inherent - it uses a mechanical switch (connected to wheels or drive train) to provide the "chuffing" oscillation.
If you really want to build a steam engine sim, take a look at some of these improved/modified circuits:
* [Stock Bachmann Sound Board](http://girr.org/girr/tips/tips1/big_hauler_tips.html)
* [Better Bachmann Sound For Under A Buck](http://girr.org/girr/tips/tips4/bachmann_sound_tips.html)

Since I don't really need a steam engine sound generator(!), I started to swap components to see how the circuit behaved.

The final circuit (as documented here) is perhaps not much use for anything.
To my ears it sounds like an RC plane fly-by at a few hundred feet!
To hear the difference the noise makes, short out/replace the Q1 transistor and the sound produced immediately goes clean.

Things learned along the way:

The transistor used for Q1  really matters, as we are exploiting the noise generated in a non-standard mode.
A BC547 is commonly found in such circuits and is nice and noisy. I tried some others:
* S9013 is no good (too good!?), generates no audible noise. Or perhaps I hadn't pushed it to fully breakdown yet.
* 2N3904 is not bad - reasonably noisy in this circuit
* A42 is very similar to BC547, hence what I used in this circuit, since I had a few around.

It's not just the model that matters: the noise profile is quite variable from component to component, so if one component doesn't work well, try another.

For true "steam" effects you want the high frequencies, so a high speed diode D2 works best, like a 1N4148.
But I tried some standard rectifier diodes, and a good old 1N4001 does a decent job here.

## Construction

![Breadboard](./assets/ZenerModeEffects_bb.jpg?raw=true)

![The Schematic](./assets/ZenerModeEffects_schematic.jpg?raw=true)

![The Build](./assets/ZenerModeEffects_build.jpg?raw=true)

## Credits and References
* [Steam Engine Simulator](http://www.talkingelectronics.com/projects/TheTransistorAmplifier/TheTransistorAmplifier-P2.html#MORE)
* [Sound Simulator for Model Steam Engine US Patent 3,913,097](http://www.google.com/patents/US3913097)
* [Stock Bachmann Sound Board](http://girr.org/girr/tips/tips1/big_hauler_tips.html)
* [Better Bachmann Sound For Under A Buck](http://girr.org/girr/tips/tips4/bachmann_sound_tips.html)
* [BC547 datasheet](https://www.futurlec.com/Transistors/BC547.shtml)
* [A42 datasheet](http://www.alldatasheet.com/datasheet-pdf/pdf/138719/JIANGSU/A42.html)
* [A92 datasheet](http://www.alldatasheet.com/datasheet-pdf/pdf/138721/JIANGSU/A92.html)
