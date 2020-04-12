# #432 ULN2003A Stepper Driver Modules

Investigating the common ULN2003A modules provided for unipolar stepper motor control - this one is identified as X113647

![Build](./assets/ULN2003Module_build.jpg?raw=true)

## Notes

Unipolar stepper motors are commonly used with microcontrollers.
One the one hand they are simple to drive - no polarity reversal required.
But on the other hand, the current/power requirements of the motors usually exceed
the capability of the microcontroller (e.g. Arduino) board to supply directly.

The most common solution for this is to employ the ULN2003A Darlington transistor array chip.
It can be dropped on a breadboard with no additional components in a moment,
but it is also common to find ULN2003A modules offered with some additional features, such as:

* LEDs for activity indication on each stepper coil connection
* bypass capacitor on the motor power line

While ULN2003A modules can literally be used for any purpose, they are typically
aimed at stepper motor use, as they connect up only 4 of the Darlinton pairs,
and include a 5-pin connector commonly used with stepper motor drives.

### The X113647 Driver Board

There are any number of versionss of the ULN2003A module.
I have one identfiied as X113647 and is commonly supplied with the 28BYJ-48 stepper motor.

In addition to LEDs and a smotthing capacitor, this module includes a jumper that
disconnects the positive motor supply from the connector to the motor -
though I can't think of a really good reason why this might be useful.

![Build](./assets/ULN2003Module_build.jpg?raw=true)

When used with the 28BYJ-48, the connections are as follows:

| Controller-side  | Stepper-side | 28BYJ-48 |
|------------------|--------------|----------|
| IN1              | OUT1         | Blue     |
| IN2              | OUT2         | Pink     |
| IN3              | OUT3         | Yellow   |
| IN4              | OUT4         | Orange   |
| -                | COM: 5-12V   | Red      |
| GND              | GND          | -        |


## Construction

![Breadboard](./assets/ULN2003Module_bb.jpg?raw=true)

![Schematic](./assets/ULN2003Module_schematic.jpg?raw=true)

## Credits and References

* [ULN2003A datasheet](https://www.futurlec.com/Linear/ULN2003A.shtml)
