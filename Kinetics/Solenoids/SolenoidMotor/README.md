# #200 Solenoid Motor

A single-cylinder mini-solenoid engine.

![The Build](./assets/SolenoidMotor_build.jpg?raw=true)

Here's a quick video of the circuit in action:

[![SolenoidMotor](https://img.youtube.com/vi/b7wmZLSBpzk/0.jpg)](https://www.youtube.com/watch?v=b7wmZLSBpzk)

## Notes

Solenoid motors are an interesting curiosity. They are quite impractical, as there are much more efficient
mechanisms for converting electrical potential to kinetic energy.

But that doesn't stop people building some impressive models like this [V8 Solenoid Engine](https://www.youtube.com/watch?v=uhYEdD94vH0).

What I have here is much more modest - a "single cylinder" engine powering an
impromptu-wire-art drive train. The mini-solenoid used here has a very small effective stroke - about 8mm -
which necessarily constrains the gearing.

I was inspired by [30GB's similar credit-card mounted model](https://www.youtube.com/watch?v=8EaCermGrwM) for the layout.

### Switching Circuit

The switching circuit is completed by a ~135˚ extra rim on one of the flywheels.
It makes contact with a free-standing wire during the "pull" cycle.
The flywheels, axle and engine mount are all copper, so the base of the engine mount is grounded to complete the circuit.

The switch controls the power to the whole circuit:

* 12V battery (at the upper end of the solenoid's voltage range for max power)
* mini solenoid with 1N4001 flyback diode
* an LED indicator with current limiting resistor

## Construction

![Breadboard](./assets/SolenoidMotor_bb.jpg?raw=true)

![The Schematic](./assets/SolenoidMotor_schematic.jpg?raw=true)

![The Build](./assets/SolenoidMotor_build.jpg?raw=true)

## Credits and References

* [Tiny Solenoid Motor on a Credit Card](https://www.youtube.com/watch?v=8EaCermGrwM) - inspiration for this build
* [Mini push-pull solenoids on aliexpress](https://www.aliexpress.com/item/5pcs-mini-DC3-12V-Push-Pull-Type-Solenoid-Electromagnet-DC-Micro-Solenoid-Free-shipping/32309067252.html) - 3-12V
* [1N4001-1N4007 datasheet](https://www.futurlec.com/Diodes/1N4001.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2016/04/littlearduinoprojects200-mini-solenoid.html)
