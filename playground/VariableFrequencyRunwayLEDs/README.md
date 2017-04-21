# #276 VariableFrequencyRunwayLEDs

A PWM-controlled variable frequency LED "runway lights" effect using the LM331 and CD4017

Here's a quick demo video of the circuit in action:

[![Build](./assets/VariableFrequencyRunwayLEDs_build.jpg?raw=true)](http://www.youtube.com/watch?v=qnxnlBLyGxo)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The idea for this circuit came from a desire to have an LED effects loop that could be
controlled by an Arduino (or other microcontroller) without requiring any processing
overhead on the microcontroller.

The LED effect I was after is two strips of LEDs that light in sequence like "runway lights" at an airport.
The frequency is variable but is in a very low range, say 1-10Hz,
and it does not need to be very accurate or stable for this application.

I wanted the microcontroller to set the frequency, but not have to burn CPU cycles or service an interrupt
to maintain control.

There are many ways to achieve this, but the approach I've take was influenced by my recent
experience with the LM331 when building the [BoldportClub Pease](../../BoldportClub/Pease).

### Circuit Overview

The LM331 voltage-to-frequency circuit is pretty much cribbed from the datasheet and the [BoldportClub Pease](../../BoldportClub/Pease) project.

This provides a stable voltage-to-frequency conversion, and can be calibrated back to the visible frequency range I am after.

I've chosen a PWM Arduino output as the controlling reference here because it can be maintained without processor supervision.
The problem is that an Arduino PWM output is by default variable duty cycle, not variable frequency (without poking the registers directly).

The solution I've selected is to introduce a PWM signal from the microcontroller to "bleed"/"feed" C1 (contributor to the LM331 RC constant) proportional to the PWM duty cycle. This produces the desired effect (variable frequency), but does affect frequency stability a little in doing so. However, for the effect I am after, these issues are negligible.

Another approaches?

* direct PWM frequency manipulation, but this is hampered by the more complex coding required, and the fact that PWM frequencies cannot be finely controlled in the low-Hz range.
* a "traditional" approach of directly generating the required clock signal on the microcontroller (digitalWrite), but this ties up the processor.

So all things considered, the current approach seems to do the job pretty well.

I may write more on this later, but for now I can at least present experimental proof that it works!

The [VariableFrequencyRunwayLEDs.ino](./VariableFrequencyRunwayLEDs.ino) sketch demonstrates how setting the PWM output level for an Arduino pin
controls the frequency of the LED effect. As long as no change to the LED effect is required, the microcontroller is free to attend to other matters.

### Subsystem Composition

See the schematic below for details. The circuit can be thought of in three parts:

* A basic LM331 voltage-to-frequency circuit running as an oscillator at a base frequency of ~5Hz. This is the "clock" signal output.
* A CD4017 driving a series of LEDs, and triggered by the LM331 "clock" signal
* An Arduino PWM output that modifies the base frequency of the LM331 circuit, from a high of 8Hz down to around 1Hz


### Performance

With the component selection as details in the schematic below, and built on a breadboard, I'm getting an output frequency that can be controlled in the 1-8Hz range.

The base performance of the circuit with no PWM signal connected is running at 5Hz.

The oscilloscope trace of the R/C signal (pin 5 of the LM331) is a 5Hz charge curve like this:

![scope_5hz](./assets/scope_5hz.gif?raw=true)

When the PWM input is connected, the RC charge curve is modified proportional to the duty cycle.
The PWM signal is running at the AVR default frequency of 468Hz.

With a PWM setting of 205 (80% duty), the nett effect is a reduction of the effective resistance, hence faster charge.
In this case, the frequency rises to 7Hz and the RC signal looks like this:

![scope_7Hz](./assets/scope_7Hz.gif?raw=true)

The resulting CLK signal feeding the CD4017 is a 7Hz pulse/square wave:

![scope_fout_7Hz](./assets/scope_fout_7Hz.gif?raw=true)

The specific PWM settings (255=100% duty cycle) and the corresponding output frequencies achieved are as follows:

| PWM level (0-255) | Frequency |
|-------------------|-----------|
| 4                 | 1Hz       |
| 5                 | 2Hz       |
| 15                | 3Hz       |
| 25                | 4Hz       |
| 45                | 5Hz       |
| 155               | 6Hz       |
| 205               | 7Hz       |
| 250               | 8Hz       |


## Construction

![Breadboard](./assets/VariableFrequencyRunwayLEDs_bb.jpg?raw=true)

![Schematic](./assets/VariableFrequencyRunwayLEDs_schematic.jpg?raw=true)

![Build](./assets/VariableFrequencyRunwayLEDs_build.jpg?raw=true)

## Credits and References
* [LM331 Datasheet](http://www.ti.com/lit/ds/symlink/lm331.pdf)
* [CD4017 datasheet](http://www.futurlec.com/4000Series/CD4017SMD.shtml)
* [LEAP#256 BoldportClub Pease](../../BoldportClub/Pease)
* [..as mentioned on my blog](http://blog.tardate.com/2017/04/leap276-variable-frequency-runway-leds.html)
