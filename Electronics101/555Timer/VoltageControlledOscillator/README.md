# #327 555Timer/VoltageControlledOscillator

A voltage-controlled oscillator (VCO) using the 555 timer.

![Build](./assets/VoltageControlledOscillator_build.jpg?raw=true)

## Notes

Conventional [astable oscillator configurations](../AstableOscillator) of the 555 timer allow frequency (and duty cycle)
variation with a variable resistor.

A [voltage-controlled oscillator (VCO)](https://en.wikipedia.org/wiki/Voltage-controlled_oscillator) on the other hand is one - obviously -
where the output frequency is proportional to some voltage input, making it ideal for electronic control.

Is it possible with a 555 timer? Yes, it turns out there are a few ways in fact.

The simplest, which I am testing here, is directly indicated in most 555 datasheets:

> The threshold and trigger levels normally are two-thirds and one-third, respectively, of VCC. These levels can be altered by use of the control-voltage  terminal.

The simplified schematic of the 555 shows the control terminal directly connected to the upper threshold of the internal three-way voltage divider:

![555_schematic](./assets/555_schematic.png?raw=true)


### Test Circuit

I'm using a standard 555 astable tuned for [320Hz @ 51% duty cycle](http://visual555.tardate.com/?mode=astable&r1=1&r2=22&c=0.1).
That's too fast for the eye, but just enough for a good scope trace.

To keep things simple, I'm using a simple voltage divider to allow easy measurement at different levels.

In the following scope traces, the three channels are connected as follows

| Channel | Colour | Connection                    |
|---------|--------|-------------------------------|
| CH1     | Yellow | timer output (pin 3)          |
| CH2     | Blue   | threshold/trigger (pin 2 & 6) |
| CH3     | Red    | control voltage (pin 5)       |


#### Basic Astable Operation

Well, it is meant to be running at a theoretical 320Hz. No doubt due to part tolerances and breadboard losses,
I have the circuit running hot at 553Hz (50.3% duty cycle) when put on a scope.

This is the trace of the standard circuit with the control voltage disconnected

![scope_basic_astable](./assets/scope_basic_astable.gif?raw=true)


#### Attaching the Control Voltage

After attaching the voltage-divider to the control terminal, and before even starting to make measurements,
I noticed some severe oscillation on the rising edge of the output:

![scope_vco_unfiltered](./assets/scope_vco_unfiltered.gif?raw=true)

I tried some ferrite beads to no great benefit. But adding a 10nF capacitor (C3) on the power rail solved the problem nicely:

![scope_vco_filtered](./assets/scope_vco_filtered.gif?raw=true)

#### Voltage-controlled Oscillator Samples

Here is a tabulation of a sampling of results for different control voltages.
Note that I'm using a nominal 9V supply (batteries).


| Control Voltage | Output Frequency | Duty Cycle |
|-----------------|------------------|------------|
| 0.70 V          |      -           |    0%      |
| 0.80 V          |      411 Hz      |    7%      |
| 2.40 V          |      670 Hz      |   17%      |
| 3.52 V          |      620 Hz      |   29%      |
| 8.32 V          |      364 Hz      |   74%      |
| 8.60 V          |       -          |  100%      |

Conclusions:

* oscillation breaks down at the upper and lower voltage ranges
* at the upper limits, it swings to full "on"
* at the lower limits, it swings to full "off". It begins to tailoff below about 2.4V
* there's good control of frequencies between 361 Hz (8.52V) and 670 Hz (2.4V)
* but the effect on duty cycle is even more pronounced

#### 3.52 V, 620 Hz, 29% Duty

![scope_620](./assets/scope_620.gif?raw=true)

#### 8.32 V, 364 Hz, 74% Duty

![scope_364](./assets/scope_364.gif?raw=true)


## Construction

![Breadboard](./assets/VoltageControlledOscillator_bb.jpg?raw=true)

![Schematic](./assets/VoltageControlledOscillator_schematic.jpg?raw=true)

![Build](./assets/VoltageControlledOscillator_build.jpg?raw=true)

## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [Voltage-controlled oscillator](https://en.wikipedia.org/wiki/Voltage-controlled_oscillator) - wikipedia
* [How to Build a Voltage Controlled Oscillator (VCO) with a 555 Timer Chip](http://www.learningaboutelectronics.com/Articles/Voltage-controlled-oscillator-VCO-circuit-with-a-555-timer.php) - learningaboutelectronics
* [LEAP#016 AstableOscillator](../AstableOscillator)
* [..as mentioned on my blog](https://blog.tardate.com/2017/08/leap328-555-timer-vco.html)
