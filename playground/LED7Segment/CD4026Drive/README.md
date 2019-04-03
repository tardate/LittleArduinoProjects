# #196 LED7Segment/CD4026Drive

Driving a 7-segment display with CD4026 Counter


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

Here's yet another way to drive a 7-segment single-digit display unit - using a CD4026.

The CD4026 is a 5-stage Johnson decade counter with decoded 7-segment display outputs and display enable.
With RESET and CLOCK INHIBIT low, and DISPLAY ENABLE IN high, the 7-segment display outputs progress through the 0-9 sequence
on the rising edge of the CLOCK pulse.

The chip has a CARRY OUT that triggers every 10 clock input cycles, so it can be used to chain the units for multi-LED displays.
However, it has no explicit support for controlling the decimal-point if present in the 7-segment display unit.

![CD4026Drive_chip - ST HCF4026BE](./assets/CD4026Drive_chip.jpg?raw=true)

I can't find much in the way of history of the chip (except that it appears to have originated at TI),
and of course it is now quite obsolete anywhere near a microcontroller.

It's an interesting alternative to using shift register for driving a 7-segment LED (as in the
[ShiftDrive](../ShiftDrive) project).
While a latched shift register provides random addressing and clean transitions to any digit,
it requires the 7-segment display outputs to be decoded externally (like in code).
On the other hand, the CD4026 takes care of the decoding, and external circuits just need to send a counter pulse.

The 7-segment single-digit display unit I'm using is a common cathode unit, similar to the [SC56-11](../assets/SC56-11_datasheet.pdf?raw=true).
A common anode (or common cathode unit with different pinouts) just requires minor modification to the circuit.

### Sample Code

The Arduino is nothing more than a pulse generator in this circuit.
I could have used a 555 timer or any other source of a trigger pulse.

But the Arduino is handy in that it can also power the circuit -
total current in this configuration peaks at ~11mA.

[CD4026Drive.ino](./CD4026Drive.ino) is a simple program that clears the counter on startup,
then sends a pulse per second to the CD4026 - so a simple monotonic second counter.

## Construction

![Breadboard](./assets/CD4026Drive_bb.jpg?raw=true)

![The Schematic](./assets/CD4026Drive_schematic.jpg?raw=true)

![The Build](./assets/CD4026Drive_build.jpg?raw=true)

## Credits and References
* [CD4026 Datasheet](https://www.futurlec.com/4000Series/CD4026.shtml)
* [ST HCF4026B Datasheet](http://www.digchip.com/datasheets/parts/datasheet/456/HCF4026-pdf.php) - closest I could find to the actual chip I have. Functionally identical to the CD4026.
* [SC56-11 Datasheet](../assets/SC56-11_datasheet.pdf?raw=true)
* [..as mentioned on my blog](https://blog.tardate.com/2016/03/littlearduinoprojects196-driving-7.html)
