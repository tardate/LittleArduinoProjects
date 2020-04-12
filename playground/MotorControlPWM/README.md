# #046 MotorControlPWM

Tests PWM speed control of a DC motor.

Here's a quick video of the circuit in action:

[![MotorControlPWM demo](https://img.youtube.com/vi/CYKtJfKv5ug/0.jpg)](https://www.youtube.com/watch?v=CYKtJfKv5ug)


## Notes

Demonstrates using a PWM signal to control the current driving a DC motor, hence its speed.

The small PWM signal is amplied with an NPN transistor.
An S9013 transistor is used in this case, primarily because:

* it has relative high hfe(β); for class H it typically ranges 144-202
* supports a decent continuous collector current (Ic) of 500mA (the motor I'm using is rated at 150mA)

A [fly-back diode](http://en.wikipedia.org/wiki/Flyback_diode) is placed across
the motor to drain any voltage spike as the motor load is switched.


### Construction

![The Breadboard](./assets/MotorControlPWM_bb.jpg?raw=true)

![The Schematic](./assets/MotorControlPWM_schematic.jpg?raw=true)

![Breadboard Build](./assets/MotorControlPWM_build.jpg?raw=true)

## Credits and References

* [S9013 Datasheet](https://www.futurlec.com/Transistors/S9013.shtml)
* [brushed DC motors](http://en.wikipedia.org/wiki/Brushed_DC_electric_motor)
