# #162 LM2577S/LM2596S Boost/Buck Converter Module

A quick test of an LM2577S/LM2596S Boost/Buck Converter Module, with a fresh look in 2026 to verify its current control behaviour and mount it in a laser-cut case.

![BoostBuckConverterModule_build](./assets/BoostBuckConverterModule_build.jpg?raw=true)

## Notes

I purchased the
["New Arrive LM2577S LM2596S DC-DC Step Up Down Boost Buck Voltage Power Converter Module" (aliexpress seller listing)](https://www.aliexpress.com/item/32358637220.html)
for US$3.07 (Oct-2015).
I wanted to see if it might be any good as a current-limited power supply for prototyping,
and also to investigate the buck/boost circuit it uses in more detail.

It has a handy output voltage range of 1.25-25V and constant current control between 0-2A.

Since the voltage/current/charging indicators and trimmers are on the PCB, and because there is no integrated display of voltage or current,
it may be fine for applications where the voltage/current settings need only a one-time adjustment.
Or with a bit of modding it could be the core of an adjustable power supply unit.

As a bit of a half-way proposition, I've mounted the unit in a laser cut project box with voltmeter, but I still need to use the trimmers to make any adjustments.

### Module Overview

Here's the module annotated with connections, controls and indictors:

* Power In 4-35V
    * 输入正极 Input Positive terminal
    * 输入负极 Input Negative terminal
* Power Out 1.25-25V
    * 输出正极 Output Positive terminal
    * 输出负极 Output Negative terminal
* Adjustment Controls
    * 恒压调节 Constant Voltage Regulation
    * 充满转灯 电流调节 Full Charged Setting
    * 恒流调节 Constant Current Regulation
* Indicator LEDs
    * 恒流指示灯（红色）Constant current indicator light (red)
    * 充电指示灯（红色）Charging indicator light (red)
    * 电源指示灯（蓝色）Charge complete indicator light (blue)

![module_annotated](./assets/module_annotated.jpg?raw=true)

### Product Specifications

Per seller listing... (take these with a grain of salt)

> Module Properties: non-isolated step-down constant current, constant voltage module (CC CV) charging module
>
> Specifications:
>
> * Input Voltage: 4-35V
> * Output voltage: Continuously adjustable (1.25-25V unload adjust)
> * Output current: 3A Max (if more than 15W, please install the heat sink)
> * CC range : 0-2A (adjustable)
> * Revolving light current: CC value * (1%-100%), default is 0.1 times
> * Minimum voltage difference: 2V
> * Output power: natural cooling 15W
> * Conversion efficiency: 80% (the higher the output voltage, the higher the efficiency)
> * Operating Temperature: Industrial (-40˚C to +85˚C) (ambient temperature more than 40˚C, lower power use, or add heat sink)
> * Full load temperature rise: 45˚C
> * Indicator:
>     * CC indicator is Red
>     * charging indicator is Red
>     * charging completed the indicator is Blue.
> * Output short circuit protection: Yes, constant current.
> * Connect method: Can solder on the PCB with wire directly
> * Input: IN+ input Positive is, IN- input negative
> * Output: OUT+ output is positive, OUT- output negative
> * Module Size: 50 x 37 x 13mm
> * Some application:
>     * High-power LED constant current driver
>     * Lithium batteries (including ferroelectric), 4V, 6V, 12V, 14V, 24V battery charging, nickel-cadmium nickel-metal hydride batteries (battery) charge.
>     * Solar panels, wind generator voltage regulator circuit board power supply, such as automatic buck regulator circuit.
>
> #### Application: Battery charging
>
> * Make sure of the voltage and current of the battery you need to charge
> * Adjust the constant voltage potentiometer to make sure the output Voltage is about 5V.
> * Use the multimeter in 10A current scale to measure output short-circuit current, and adjust the current potentiometer to make sure the output current to the expected charging current value
> * The charge current of transfer lamp is default 0.1 times of the charging current (constant current value)
> * Adjust the constant voltage potentiometer to make sure the output Voltage is up to floating Voltage.
> * Connected to the battery and try to charging (for previous 5 steps, module input terminal is connected to power source, output load is NOT connected to batteries).
>
> #### Application: LED Constant Current Driver Use
>
> * Make sure operating current and Max operating Voltage of the LED you need to drive.
> * Adjust the constant voltage potentiometer to make sure the output Voltage is 5V(about).
> * Use the multimeter in 10A current scale to measure output short-circuit current, and adjust the current potentiometer. To make sure the output current to the expected LED operating current.
> * Adjust the constant voltage potentiometer to make sure the output Voltage is up to LED Max operating Voltage.
> * Join LED, test (For the above 3 steps, module input terminal is connected to power source, output load is NOT connected to LED)

### Test Circuit Design

For testing, I've wired up the module with the addition of a 3-wire voltmeter (powered from the input voltage, measuring the output voltage). I'll test various loads on a breadboard.

Designed with Fritzing: see [BoostBuckConverterModule.fzz](./BoostBuckConverterModule.fzz).

![bb](./assets/BoostBuckConverterModule_bb.jpg?raw=true)

![schematic](./assets/BoostBuckConverterModule_schematic.jpg?raw=true)

Setup on a breadboard...

![bb_build](./assets/BoostBuckConverterModule_bb_build.jpg?raw=true)

### Constant Voltage Control

With an input voltage of 12V, I measure that actual output voltage range as from 1.24V to 26.6V (no load).
The selected output voltage range appears to remain very stable under load.

The left-most trimmer is used to set the output voltage.

Under constant voltage control (i.e no current limit or full charge state),
the centre charging indicator red LED is on:

![test02-cv](./assets/test02-cv.jpg?raw=true)

### Constant Current Control

The right-most trimmer is used to adjust the constant current control.

When current is being limited,
the upped constant current indicator red LED is on, and output voltage will drop accordingly:

![test02-cc](./assets/test03-cc.jpg?raw=true)

BEWARE: I discovered there is one situation where the constant-current setting is bypassed:

* if power is applied to the module with an ammeter connected across the output for short-circuit current test, the constant current setting is ignored and the module will try to deliver max current
* BUT if there is a load on the output, the constant current setting is honored on power-on

### Full Charge Control

The centre trimmer is used for the "fully charged" adjustment.
This is basically the current below which the load is deemed "charged".
This reflects the typical battery charging scenario where current drawn by the battery will drop as it approaches the fully-charged state.

When the "charged" state is reached (simulated here with a high resistance and low current), the lower blue LED will be on:

![test01-fc](./assets/test01-fc.jpg?raw=true)

### Project Box

Let's mount the module in a more practical way.

I used [MakerCase](https://en.makercase.com/) to generate a simple parametric design, with an open top so the trimmers and LEDs remain accessible.

![basic-box](./assets/basic-box.png?raw=true)

* material thickness: 3mm
* inside dimensions:
    * width: 140mm
    * height: 40mm
    * depth:  85mm
* open box
* edge joints: finger
* panel labels: enabled (to be excluded from cutting)
* cut line width: 1mm
* kerf: 0.2mm
* panel layout: separate, single file
* exported as [basic-box.svg](./assets/basic-box.svg)
* refined in Affinity Designer: [box.afdesign](./assets/box.afdesign)
* export as [box.svg](./assets/box.svg)
* loaded into xTool Creative Space for cutting, where I also added an engraved label: [box.xcs](./assets/box.xcs)

I cut the box on a [xTool S1 Laser Cutter at the library](../../../../Equipment/NLB/xToolS1/).

![box](./assets/box.svg?raw=true)

The cut box pieces:

![box01](./assets/box01.jpg?raw=true)

The assembled box:

![box02](./assets/box02.jpg?raw=true)

![box03](./assets/box03.jpg?raw=true)

#### A 5V 100mA Power Supply Setup

For now, I've just mounted the unit as a 5V 100mA voltage and current-limited supply.
Handy for prototyping, while protecting me from mistakes that might try to draw > 100mA and smoke some components.

Perhaps I should have replaced the voltage and current trimmers with panel-mounted pots .. maybe a job for another day.

With LED and current-limiting resistor, the unit is in constant voltage state,
delivering the full 5V, at 14mA in this case:

![build02](./assets/build02.jpg?raw=true)

With a 33Ω 2W resistor as load, the constant current mode kicks in,
delivering the maximum 100mA 5V:

![build01](./assets/build01.jpg?raw=true)

## Credits and References

* ["New Arrive LM2577S LM2596S DC-DC Step Up Down Boost Buck Voltage Power Converter Module" (aliexpress seller listing)](https://www.aliexpress.com/item/32358637220.html)
    * purchased for US $3.07 (Oct-2015)
    * no longer available from this seller
* ["LM2577S LM2596S XL6009 DC Adjustable Step Up Down Boost Buck CC CV Voltage Converter Module LED Driver Power Supply Voltage Reg" (aliexpress seller listing)](https://www.aliexpress.com/item/1005002667619541.html)
    * same product from another seller
    * currently listed for SG$3.88 (Jan-2026)
* [LM2577 product info](http://www.ti.com/product/lm2577)
* [LM2596 product info](http://www.ti.com/product/lm2596)
* [Build your own Variable Lab Bench Power Supply](https://youtu.be/wI-KYRdmx-E) - inspiration from GreatScott!
