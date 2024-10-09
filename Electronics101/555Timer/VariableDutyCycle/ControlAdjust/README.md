# #444 555Timer/VariableDutyCycle/ControlAdjust

Using the control pin to adjust duty cycle of a 555 Timer astable oscillator.

![Build](./assets/ControlAdjust_build.jpg?raw=true)

## Notes

The standard 555 astable configuration uses a built-in 2/3 x VCC upper threshold reference.

Given R1 = 4.7kΩ, R2 = 47kΩ and C1 = 1µF this produces an oscillation at
[14.590 Hz](https://visual555.tardate.com/?mode=astable&r1=4.7&r2=47&c=1) with a 52.38% duty cycle.

The control pin (5) provides the opportunity to adjust the upper threshold,
allowing the duty cycle to be vary above and below 50%.

While this provides access to duty cycles below 50% (unlike the standard astable configuration),
the disadvantage of this approach is that both duty cycle and frequency are affected.


## Construction

The circuit is essentially the standard astable, but with the addition of adjustable control reference voltage.

![Breadboard](./assets/ControlAdjust_bb.jpg?raw=true)

![Schematic](./assets/ControlAdjust_schematic.jpg?raw=true)

![Build](./assets/ControlAdjust_build.jpg?raw=true)


## Test Results

When adjusted to 52.3% duty cycle, the actual frequency is 14.4 Hz - very close to the predicted value. This is essentially the same as having the control pin bypassed/disconnected in the standard astable configuration.

![scope_mid](./assets/scope_mid.gif?raw=true)

The minimum duty cycle possible with this astable configuration is 34.4%, at a frequency of 19.92 Hz:

![scope_34pc](./assets/scope_34pc.gif?raw=true)

The minimum duty cycle possible with this astable configuration is 62.1%, at a frequency of 11.42 Hz:

![scope_62pc](./assets/scope_62pc.gif?raw=true)


| Duty | Frequency | Note           |
|------|-----------|----------------|
| 34.4% | 19.92 Hz | Min duty cycle |
| 52.3% | 14.4 Hz  |                |
| 62.1% | 11.42 Hz | Max duty cycle |

## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [Designing 555 Astables](http://www.learnabout-electronics.org/Oscillators/osc44.php) - learnabout-electronics
