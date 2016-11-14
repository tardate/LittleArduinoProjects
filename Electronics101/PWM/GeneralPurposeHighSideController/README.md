# #233 PWM/GeneralPurposeHighSideController

Build and test a general-purpose high-side PWM controller

![GeneralPurposeHighSideController_build](./assets/GeneralPurposeHighSideController_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

This circuit cobines a variable-duty cycle PWM generator with a high-side p-channel MOSFET driver circuit,
making it suitable for controlling loads up to 15V/23A.

### PWM Generator

The PWM signal is generated with a modified 555 Timer astable oscillator.

Steering diodes are used to isolate the 100kΩ pot so that it primarily adjusts duty cycle with little change to the frequency.

A switch allows selection of 1nF & 10nF capacitors, selecting a base PWM frequency of:

* 10nF - 1.25kHz
* 1nF - 12.6kHz


### High-side Driver

The PWM output switches an n-channel MOSFET which in turn controls the high-side p-channel Power MOSFET.

The shunt resistor R4 limits the bypass current when the n-channel MOSFET is on.
At 1kΩ, it wastes up to 15mA (at 15V) but in return allows fast switching of the Power FET.
A higher value of R4 (10kΩ, 100kΩ) saves power, but switching time is affected.

A pair of capacitors (220µF, 100nF) provide some smoothing of the power supply to the Power FET and decouple the PWM and FET loads.


### Performance - 10kΩ Resistive Load at 1.25kHz PWM

At 50% duty cycle:

![lo_f_mid_duty](./assets/lo_f_mid_duty.gif?raw=true)

At minimum duty cycle (~1.25%):

![lo_f_low_duty](./assets/lo_f_low_duty.gif?raw=true)

At maximum duty cycle, the output approaches 99.9% fully on.


### Performance - 10kΩ Resistive Load at 12.6kHz PWM

At 50% duty cycle:

![hi_f_mid_duty](./assets/hi_f_mid_duty.gif?raw=true)

At minimum duty cycle (~1.25%):

![hi_f_low_duty](./assets/hi_f_low_duty.gif?raw=true)

At maximum duty cycle, the output approaches 100% fully on.


## Construction

![Breadboard](./assets/GeneralPurposeHighSideController_bb.jpg?raw=true)

![The Schematic](./assets/GeneralPurposeHighSideController_schematic.jpg?raw=true)

![GeneralPurposeHighSideController_breadboard_build](./assets/GeneralPurposeHighSideController_breadboard_build.jpg?raw=true)

Protoboard/boxed construction:

![GeneralPurposeHighSideController_protoboard_layout](./assets/GeneralPurposeHighSideController_protoboard_layout.jpg?raw=true)

![GeneralPurposeHighSideController_wip_1](./assets/GeneralPurposeHighSideController_wip_1.jpg?raw=true)

![GeneralPurposeHighSideController_wip_2](./assets/GeneralPurposeHighSideController_wip_2.jpg?raw=true)

![GeneralPurposeHighSideController_build](./assets/GeneralPurposeHighSideController_build.jpg?raw=true)

## Credits and References
* [MOSFET as a switch?](http://electronics.stackexchange.com/questions/67343/mosfet-as-a-switch) - EE.SO
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [2N7000 datasheet](http://www.futurlec.com/Transistors/2N7000.shtml)
* [IRF9540 datasheet](http://www.futurlec.com/Transistors/IRF9540.shtml)
