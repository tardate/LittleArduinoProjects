# #466 VC3165

All about the Victor VC3165 frequency counter.

![Build](./assets/VC3165_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I've been using the Victor VC3165 frequency counter for some time, and it's proven a very reliable
bit of kit. I've used it mainly for signals from DC to a few hundred MHz, though it's range does
extend to 2.4GHz.

I purchased mine from [Instruments World Store on aliexpress](https://www.aliexpress.com/store/product/New-Style-Top-Quality-0-01Hz-2-4GHz-Precision-Frequency-Meter-Frequency-Counter-VC3165/1393846_32332771334.html).

What follows is an overview of the operation and a bit of a look at the internals of the unit.

## Enclosure

The instrument uses a standard enclosure.
Front and rear panels are well layed out, although the gate control knob below the channel inputs
can be inconvenient to get to with leads attached.

The unit I received had some button labels only in Chinese, so I've stuck on my own labels in English.
A manual is available electronically in English which helped!

![VC3165_front](./assets/VC3165_front.jpg?raw=true)

![VC3165_rear](./assets/VC3165_rear.jpg?raw=true)

A look inside the case:

![VC3165_internals](./assets/VC3165_internals.jpg?raw=true)

## Function and Counter Modes

The function key selects between 3 modes. The input channel used depends on the mode:

| Function | Coupling | Freq. Range  | Gate time min | Gate time max. | Channel |
|----------|----------|--------------|---------------|----------------|---------|
| 1        | AC       | 1GHz-2.4GHz  | 1kHz          | 100Hz          | B       |
| 1        | AC       | 50MHz-1GHz   | 1kHz          | 10Hz           | B       |
| 2        | AC       | 2MHz-50MHz   | 1kHz          | 10Hz           | A       |
| 3        | AC       | 100Hz-2MHz   | 10Hz          | 0.1Hz          | A       |
| 3        | DC       | 0.01Hz-100Hz | 0.001Hz       | 0.001Hz        | A       |

### AC/DC Switch

In mode 3, the AC/DC switch selects between low frequency AC signals
and verl low frequncy DC signals (DC measurement is required for anything under 100Hz).

### Gate Control

The gate control knob adjusts the gate time (range depends on the mode).
This can be important for correctly locking on to a signal with the required accuracy.

* short gate time: faster measurement, but resolution is lower
* longer gate time: slower measurement, but higher resolution

## Power Supply

The VC3165 has a low noise linear power supply.
Mains power is stepped-down with a transformer with primary windings switchable for 220V/110V.

The approximately 9V AC is regulated to 5V with a KA78R05 low-dropout voltage regulator.

### Main Board

I haven't traced out the circuit, but interesting to note that it appears
to be a version of a conventional CMOS counter design, with an AT89C4051 microprocessor in control.

The main clock source is in a shielded housing. This may even be a temperature-controlled "crystal oven" but I'm not sure.
There's been some thought put to providing good shielding:

* top cover is lined with a ground plane
* each input front end circuit is in it's own shielded housing

IC listing:

* [AT89C4051](https://www.microchip.com/wwwproducts/en/AT89C4051) CMOS 8-bit microcontroller with 4KB of flash
* [74F74PC](https://www.futurlec.com/74F/74F74.shtml) dual D positive edge triggered flip-flop, asynchronous preset and clear
* [74LS373N](https://www.futurlec.com/74LS/74LS373.shtml) octal transparent latch
* [74HC393N](https://www.futurlec.com/74HC/74HC393.shtml) dual 4-bit binary counter
* [74HC153N](https://www.futurlec.com/74HC/74HC153.shtml) dual 4-line to 1-line data selector/multiplexer, non-inverting outputs
* [7555](https://www.futurlec.com/Linear/LM555CN.shtml) CMOS 555 timer
* [LM393](http://www.ti.com/product/LM393) Dual Differential Comparator
* [KA78R05](http://product.ic114.com/PDF/K/KA78R05.pdf) 5V low-dropout voltage regulator

![VC3165_main_board](./assets/VC3165_main_board.jpg?raw=true)

The front display board has a Microchip CF775-04/P (I think a PIC variant) specialised for display control.

## Credits and References

* [110V/220V New Style Top Quality 0.01Hz - 2.4GHz Precision Frequency Meter Frequency Counter VC3165](https://www.aliexpress.com/store/product/New-Style-Top-Quality-0-01Hz-2-4GHz-Precision-Frequency-Meter-Frequency-Counter-VC3165/1393846_32332771334.html) - from Instruments World Store on aliexpress
