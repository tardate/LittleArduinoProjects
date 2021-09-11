# #605 ATtiny Analog Comparator

Testing sound-triggered interrupts with the ATtiny85 built-in analog comparator

![Build](./assets/AnalogComparator_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/2-oTDrHCTfA/0.jpg)](https://www.youtube.com/watch?v=2-oTDrHCTfA)

## Notes

The Analog Comparator is introduced in section 16 of the ATtiny datasheet:

> The Analog Comparator compares the input values on the positive pin AIN0 and negative pin AIN1. When the volt- age on the positive pin AIN0 is higher than the voltage on the negative pin AIN1, the Analog Comparator output, ACO, is set. The comparator can trigger a separate interrupt, exclusive to the Analog Comparator. The user can select Interrupt triggering on comparator output rise, fall or toggle.

The ACSR (Analog Comparator Control and Status Register) determines the behaviour of the Analog Comparator.

In the program setup, we:

* disable multiplexed input to the comparator, so AIN1 is used as negative input
* clear any existing comparator interrupts
* enable Analog Comparator interrupts
* select rising-edge interrupt

The code defines an interrupt service routine on [ANA_COMP_vect](http://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html).

Pins:

* AIN0 - PB0, pin 5 on ATtiny85 DIP8
* AIN1 - PB1, pin 6 on ATtiny85 DIP8

### The Test Circuit

This is simple test:

* a voltage divider (variable resistor) sets up a threshold reference on AIN1
* amplified electret signal is fed to AIN0
  - 10kΩ bias for the electret, AC-coupled input to the OpAmp
  - TL072 OpAmp configured as a high gain inverting amplifier
  - a 100nF cap on AIN0 provides some hold-time for spikey input signals
.

### Rising, Falling, Change Interrupts?

Setting ACIS1, ACIS0 bits select the interrupt to trigger:

| ACIS1 | ACIS0 | Trigger |
|-------|-------|---------|
|  0    | 0     | Toggle  |
|  1    | 0     | Falling |
|  1    | 1     | Rising  |


### So Does it Work?

Yes! The comparator interrupt is excellent, and beats any other approach for speed, processing overhead and lack of external circuitry.

Here is a trace of the behaviour:

* CH1 (yellow) - AIN0
* CH2 (blue) - AIN1

![scope](./assets/scope.gif?raw=true)

## Construction

![Breadboard](./assets/AnalogComparator_bb.jpg?raw=true)

![Schematic](./assets/AnalogComparator_schematic.jpg?raw=true)


## Credits and References

* [ATtiny85 datasheet](https://www.microchip.com/en-us/product/ATTINY85)
