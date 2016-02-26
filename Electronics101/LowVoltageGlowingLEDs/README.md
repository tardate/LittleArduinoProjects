# #191 LowVoltageGlowingLEDs

A dual-LED glowing oscillator from a 1.5V supply

## Notes

So for another project I wanted some "glowing" LEDs, ideally powered from a single 1.5V AA or AAA battery.
That seemed like an interesting challenge, especially when the forward voltage of the LEDs I'm using is about 2.1V.

I had a feeling I could cobble together a couple of other ideas from other projects to get something going:
* [RelaxationJouleThief](../RelaxationJouleThief) uses an inductor to pump an LED-driving voltage from a 1.5 cell
* [RCOscillator](../RCOscillator) demonstrates the basic BJT-RC astable oscillator

And it works! I've made a couple of modifications to the circuit along the way to get the result I wanted:
* a diode and capacitor to couple the output of the voltage boost circuit and provide a stiffer though still load-dependent supply
* some additional capacitors in the oscillator to smooth out the oscillation so I get more of a glow effect rather than a square-wave oscillation

### Boost Power Supply

This is based on the [RelaxationJouleThief](../RelaxationJouleThief) circuit.

I've added a diode on the output to prevent any of the negative voltage swings possing through.
I used a 1N5819 because it has very low forward voltage drop. A 1N4148 also works.
A small 100nF capacitor provides some high frequency smoothing.
Putting too large a capacitor on the output actually interferes with the oscillator that follows.

The circuit exhibits quite a bit of instabiity on a breadboard, no doubt due to all the stray capacitance, inductance and just plain dodgy connections.

But on a PCB or protoboard and with a fixed load, the circuit delivers a beautifully stable ramp-wave.
Of course what the supply can deliver varies completely with load.

With 10kΩ fixed load, the signal averages 3.3V with a 1.4V peak-peak 3.2kHz wave. Here's the AC-coupled trace:

![RelaxationBoostPS_ac_10kload](./assets/RelaxationBoostPS_ac_10kload.gif?raw=true)

With 100kΩ fixed load, the signal boosts to an average of 6.1V with a 0.54V peak-peak 2.3kHz wave. Here's the AC-coupled trace:

![RelaxationBoostPS_ac_100kload](./assets/RelaxationBoostPS_ac_100kload.gif?raw=true)

Here's the power supply as built on a protoboard:

![RelaxationBoostPS_build2](./assets/RelaxationBoostPS_build2.jpg?raw=true)

### "Glowing" Oscillator

The [RCOscillator](../RCOscillator) circuit oscillates between two LED outputs. But it is a harsh transition.
I really wanted two LEDS that oscillated in a much gentler fashion - "glowing" on and off.

First step was just to get the basic oscillator working with the boost supply. Parts are a little bit critical.

The transistors need to be reasonable well matched to get the oscillation going and balanced. S9013 were the first I grabbed that worked. Note these are different than the 2N3904's I used in the power stage, but I did go back and verify that some 2N3904's also worked in the oscillator.

R3/R4 and C3/C4 determine the basic oscillator frequency, but the theoretical frequency is counfounded by the load-dependent power supply. So I needed to just play around with some values

Eventually I settled on R3/R4=100kΩ and C3/C4=100μF, for a theoretical frequency of
[0.02 Hz](http://www.wolframalpha.com/input/?i=%28ln%282%29+*+%28+100000+*+100*10^-6+%2B+100000+*+100*10^-6+%29%29^-1). However in practice its more like [0.5 Hz](http://www.wolframalpha.com/input/?i=1%2F%289*0.2s%29) as you can estimte from the scope traces below.

Here's the scope trace of the basic oscillator without C5/C6 installed.
* CH1: Vg (power input)
* CH2: TP1, base of Q3
* CH3: TP2, collector of Q3
* all channels DC-coupled and shifted down 500mV

Things to note:
* that power supply gets noise under a variable load!
* hard edges on the transistor switching

![LowVoltageGlowingLEDs_scope_no_smoothing](./assets/LowVoltageGlowingLEDs_scope_no_smoothing.gif?raw=true)

After a bit of experiementation, I came up with a configuration of 22µF capacitors C5/C6 across the base-collector of the transistors. This drammatically smooths out the oscillator transitions.

![LowVoltageGlowingLEDs_scope_with_smoothing](./assets/LowVoltageGlowingLEDs_scope_with_smoothing.gif?raw=true)

Note the orientation of the capacitors in the oscillator. I'm using electrolytics, and these orientations are correct in this configuration to ensure they are driven with correct polatiry.

Now I'm quite happy with the result, I'll transfer the oscillator from breadboard to protoboard for the project I really wanted this for in the first place!


## Construction

![Breadboard](./assets/LowVoltageGlowingLEDs_bb.jpg?raw=true)

![The Schematic](./assets/LowVoltageGlowingLEDs_schematic.jpg?raw=true)

![The Build](./assets/LowVoltageGlowingLEDs_build.jpg?raw=true)

## Credits and References
* [1N5819 Datasheet](http://www.futurlec.com/Diodes/1N5819.shtml)
* [S9013 Datasheet](http://www.futurlec.com/Transistors/S9013.shtml)
* [2N3904 datasheet](http://www.futurlec.com/Transistors/2N3904.shtml)
* [RCOscillator](../RCOscillator) project
* [RelaxationJouleThief](../RelaxationJouleThief) project

