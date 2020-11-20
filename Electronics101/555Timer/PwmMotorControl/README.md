# #573 555 PWM Motor Control

Testing small DC motor control with a 555 time PWM signal

![Build](./assets/PwmMotorControl_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/e2mwX65UjqU/0.jpg)](https://www.youtube.com/watch?v=e2mwX65UjqU)

## Notes

Pulse-width Modulation (PWM) is a common method for controlling the speed of DC motors.

The PWM duty cycle controls the nett power being provided to the motor,
but by maintaining a constant "on" voltage, the torque is not greatly affected by speed.

The PWM frequency is not so important, however there will be a "sweet spot" for a particular motor:

* too high, and low speed control can be affected (not enough power delivered in each "on" cycle to move the motor)
* too low, and vibration and "chugging" can be a problem
* need to avoid resonant frequencies of the mechanical assembly

A 555 timer makes a simple controller. Here I've used a "diode-steered" variable duty cycle configuration,
with PWM duty cycle controlled with a 100kΩ variable resistor.

The motor I'm testing with is a small DC motor, with a [fly-back diode](http://en.wikipedia.org/wiki/Flyback_diode) to dissipate
the voltage spike as the motor load is switched.

## Construction

![Breadboard](./assets/PwmMotorControl_bb.jpg?raw=true)

![Schematic](./assets/PwmMotorControl_schematic.jpg?raw=true)

![Breadboard Build](./assets/PwmMotorControl_bb_build.jpg?raw=true)

## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [How To Make a PWM DC Motor Speed Controller using the 555 Timer IC](https://howtomechatronics.com/how-it-works/electronics/how-to-make-pwm-dc-motor-speed-controller-using-555-timer-ic/)
* [MOTOR PWM Circuit](http://www.555-timer-circuits.com/motor-pwm.html)
