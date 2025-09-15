# #xxx 555 Breadboard PWM Generator

A simple PWM generator circuit using the 555 timer IC designed for use on a breadboard.

![Build](./assets/BreadboardPWMGen_build.jpg?raw=true)

## Notes

It's often useful to have a PWM square wave generator to use on a breadboard circuit, without having to deploy a full function generator.

This project adapts the basic [LEAP#573 555 PWM Motor Control](../PwmMotorControl/) circuit and puts it on a small protoboard designed to plug into a breadboard.

### Circuit Design

Designed with Fritzing: see [BreadboardPWMGen.fzz](./BreadboardPWMGen.fzz).

![bb](./assets/BreadboardPWMGen_bb.jpg?raw=true)

![schematic](./assets/BreadboardPWMGen_schematic.jpg?raw=true)

![bb_build](./assets/BreadboardPWMGen_bb_build.jpg?raw=true)

![bb_test](./assets/BreadboardPWMGen_bb_test.jpg?raw=true)

### Protoboard Build

Transferring the circuit to a small piece of protoboard:

![protoboard_layout](assets/protoboard_layout.jpg)

![protoboard_build](assets/protoboard_build.jpg)

Testing the breadboard adapter:

![protoboard_test](assets/protoboard_test.jpg)

Minimum duty cycle:

![min](assets/scope_min.gif)

Mid-point duty cycle:

![mean](assets/scope_mean.gif)

Maximum duty cycle:

![max](assets/scope_max.gif)

## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
