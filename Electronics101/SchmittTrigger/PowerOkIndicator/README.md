# #536 Power OK Indicator

Testing a simple Schmitt Trigger power OK indicator using a 74HC14.

![Build](./assets/PowerOkIndicator_build.jpg?raw=true)

## Notes

A practical "power OK" indicator is a signal that ideally:

* provides a clear "ON" signal a short time after power is available (to allow for startup fluctuations etc)
* immediately asserts an "OFF" signal once power is removed

The circuit demonstrated here is based on Experiment #125 from
[ARRL's Hands-On Radio Experiments Volume 3](../../../books/arrl-hands-on-radio-experiments-vol3/).

Features of the circuit:

* the time constant of the R2=1MΩ, C1=1µF RC circuit provide the startup delay. These values are very large so that the effect is quite obvious.
* The hysteresis of a Schmitt Trigger is used here to provide a clear de-bounced startup signal
* The switch in the circuit is used to simulate power on/off.
* The LED and current-limiting resistor simulate a load

Is this circuit suitable for real use as-is? No - it is just a demonstration of some core principles
and has a number of simplifications that wouldn't match a practical application:

* power loss may not cause the the positive power rail to be grounded. In this situation, there's no path for rapid discharge.
* the 74HC14 always has power in this circuit, whereas in reality it would probably also lose power. A power reservoir for the 74HC14 would allow the the inverter to assert a positive low signal for some time after main power is lost.

## Construction

![Breadboard](./assets/PowerOkIndicator_bb.jpg?raw=true)

![Schematic](./assets/PowerOkIndicator_schematic.jpg?raw=true)

## Behaviour

The on-off cycle is captured in the following scope trace where

* CH1 (Yellow) - switch output
* CH2 (Blue) - inverter input
* CH3 (Red) - output

![scope](./assets/scope.gif?raw=true)

![Build](./assets/PowerOkIndicator_build.jpg?raw=true)

## Credits and References

* [ARRL's Hands-On Radio Experiments Volume 3](../../../books/arrl-hands-on-radio-experiments-vol3/) Experiment #125
* [74HC14 Datasheet](https://www.futurlec.com/74HC/74HC14SMD.shtml)
