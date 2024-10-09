# #560 Dual Variable Mode Oscillator

Testing a 555 timer astable oscillator circuit that can be switched between variable duty cycle and variable frequency.

![Build](./assets/DualModeVariableFrequencyOrDuty_build.jpg?raw=true)

## Notes

This is a very effective circuit that I found
as an example in the
[Multisim](https://www.multisim.com/content/UEmDRQGfeRsAAFSEX8kQTE/555-timer-variable-frequency-50-duty-cycle-constant-frequency-variable-duty-cycle-astable-multivibrator/open/)
circuit simulator samples.
I've made a few modifications to the circuit, primarily to reduce the clock to a very low (visible) frequency.

The circuit can be manually switched between variable duty cycle and variable frequency, and it performs impressively:

* variable duty cycle mode gives almost full range control (4-96% in this build) with no significant impact on a fixed frequency
* in variable frequency mode, the duty cycle remains stable at around 50% for the entire frequency sweep

## Construction

I selected VR1 = 50kΩ, and C1 = 10µF for the build in order to keep down to very low frequencies so that the
output LED indicator can be followed by eye.

![Breadboard](./assets/DualModeVariableFrequencyOrDuty_bb.jpg?raw=true)

![Schematic](./assets/DualModeVariableFrequencyOrDuty_schematic.jpg?raw=true)

## Performance

With VR1 = 50kΩ, and C1 = 10µF, frequency can be adjusted between 1.2Hz and 32 Hz,
or duty between 4% and 96% at a fixed frequency of ~2 Hz. Here are the output scope traces
for the minimum and maximum VR1 setting for variable duty (upper) and variable frequency (lower)

![scope](./assets/scope.png?raw=true)

Some ranges I've measured with various VR1 component values:

| VR1   | f(min) | f(max) | duty(min) | duty(max) | f(fixed duty) |
|-------|--------|--------|-----------|-----------|---------------|
| 10kΩ  | 5Hz    | 35Hz   | 14%       | 86%       | ~6Hz          |
| 20kΩ  | 3Hz    | 34Hz   | 8%        | 92%       | ~5Hz          |
| 50kΩ  | 1.2Hz  | 32Hz   | 4%        | 96%       | ~2Hz          |
| 100kΩ | 2Hz    | 34Hz   | 2%        | 98%       | ~1Hz          |

NB: I should have switched C1 for a higher frequency range in order to capture more accurate measurements. Perhaps later?

## Multisim

I only had a brief look at [Multisim Live](https://www.multisim.com/), but it seems quite capable, and is very intuitive.

Here are the results and a glimpse of the user interface for the simulation of the circuit similar to the one shown here:

[![multisim](./assets/multisim.jpg?raw=true)](https://www.multisim.com/content/UEmDRQGfeRsAAFSEX8kQTE/555-timer-variable-frequency-50-duty-cycle-constant-frequency-variable-duty-cycle-astable-multivibrator/open/)
## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [555 Timer Variable Frequency, 50% Duty Cycle / Constant Frequency, Variable Duty Cycle Astable Multivibrator](https://www.multisim.com/content/UEmDRQGfeRsAAFSEX8kQTE/555-timer-variable-frequency-50-duty-cycle-constant-frequency-variable-duty-cycle-astable-multivibrator/open/) - Multisim simulation
* [Multisim Live](https://www.multisim.com/)
