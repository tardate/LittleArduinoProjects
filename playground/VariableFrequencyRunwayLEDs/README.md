# #276 VariableFrequencyRunwayLEDs

A PWM-controlled variable frequency LED "runway lights" effect using the LM331 and CD4011

![Build](./assets/VariableFrequencyRunwayLEDs_build.jpg?raw=true)

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

The solution I've selected is to introduced a PWM signal from the microcontroller to "bleed" C1 (contributor to the LM331 RC constant) proportional to the PWM duty cycle. This produces the desired effet (variable frequency), but does affect frequency stability in doing so. However, for the effect I am after, these issues are negligible.

Another approach is direct PWM frequency manipulation, but this is hampered by the more complex coding required, and the fact that PWM frequencies cannot be finely controlled in the low-Hz range. So the current approach seems to do the job pretty well.

I may write more on this later, but for now I can at least present experimental proof that it works!

The [VariableFrequencyRunwayLEDs.ino](./VariableFrequencyRunwayLEDs.ino) sketch demonstrates how setting the PWM output level for an Arduino pin
controls the frequency of the LED effect. As long as no change to the LED effect is required, the microcontroller is free to attend to other matters.


### Subsystem Construction

See the schematic below for details. The circuit can be thought of in thress sections:

* A basic LM331 voltage-to-frequency circuit running as an oscillator at ~7Hz,outputting a "clock" signal
* A CD4011 driving a series of LEDs, and triggered by the LM331 "clock" signal
* An Arduino PWM output that modifies the base frequency of the LM331 circuit, from it's base (high) frequency of 7Hz down to around 1Hz

### Performance

The base voltage-to-frequency circuit (before introducing the PWM control signal) is a ~7Hz pulse:

![scope_f_max](./assets/scope_f_max.gif?raw=true)

With extremely low PWM duty cycle, this is reduced to ~1Hz:

![scope_f_min](./assets/scope_f_min.gif?raw=true)

## Construction

![Breadboard](./assets/VariableFrequencyRunwayLEDs_bb.jpg?raw=true)

![Schematic](./assets/VariableFrequencyRunwayLEDs_schematic.jpg?raw=true)

![Build](./assets/VariableFrequencyRunwayLEDs_build.jpg?raw=true)

## Credits and References
* [LM331 Datasheet](http://www.ti.com/lit/ds/symlink/lm331.pdf)
* [CD4011 datasheet](http://www.futurlec.com/4000Series/CD4011.shtml)
* LEAP#256 [BoldportClub Pease](../../BoldportClub/Pease)
