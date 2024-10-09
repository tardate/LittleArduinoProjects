# #481 Electret Sound-level Trigger

A simple circuit using a TL072 op-amp and 74LS14 inverter for getting a clear digital trigger signal based on the sound level detected by an electret microphone.

![Build](./assets/SoundLevelTrigger_build.jpg?raw=true)

## Notes

The purpose of this circuit is to get a clear digital signal (as close to rail-rail as possible)
based on the sound level picked up by an electret microphone. It is not intended to amplify the audio input,
but to provide a trigger once a variable threshold is reached.

I put this circuit together in four basic stages:

* the electret input is amplified with a high-gain inverting amplifier
* an op-amp configured as a variable comparator turns the analog input to a binary output
* an RC filter with a time constant of araound [47ms](https://www.wolframalpha.com/input/?i=4.7k%CE%A9*10%C2%B5F) provides some "de-bouncing" and extends the minimum duration of any triggered input
* a series of inverters pull the signal to as-near rail-rail as possible, and allow tapping the output with the desired polarity (active-low or active high)

## Construction

![Breadboard](./assets/SoundLevelTrigger_bb.jpg?raw=true)

![Schematic](./assets/SoundLevelTrigger_schematic.jpg?raw=true)

![Build](./assets/SoundLevelTrigger_build.jpg?raw=true)

## Performance

Here's a scope trace of a sound triggering the output.

* CH1 (yellow) is the interter output
* CH2 (blue) op-amp output
* CH3 (red) electret output (note the 200mV scale)

![scope](./assets/scope.jpg?raw=true)

## Credits and References

* [TL072 datasheet](http://parts.io/detail/12204535/TL072)
* [74LS14 datasheet](https://www.futurlec.com/74LS/74LS14.shtml)
