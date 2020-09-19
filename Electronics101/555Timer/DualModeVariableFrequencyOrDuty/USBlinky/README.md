# #564 USB Blinky Toy

A curiously hypnotic USB blinky demonstration of a variable frequency/variable duty 555 timer circuit.

![Build](./assets/USBlinky_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/rZ7JHcP_zrk/0.jpg)](https://www.youtube.com/watch?v=rZ7JHcP_zrk)

## Notes

This is a quick demonstrator for the [LEAP#563 Dual Variable Mode Oscillator](../) just for fun.

I'm using the shell of an old [USB Webmail Notifier](http://www.usbgeek.com/products/usb-webmail-notifier) device for mounting the circuit.

It is curiously hypnotic to play with:

* switch between variable frequency/fixed duty and variable duty/fixed frequency mode
* use the variable resistor to adjust the frequencvy or duty (depending on mode)

Four strawhat blue LEDs provide enough illumination for the shell, with fairly low current limiting resistors (100Ω).
The 2N7000 has just enough current handling capability (200mA continuous) for the 4 LEDs.

## Construction

the circuit extends the [Dual Variable Mode Oscillator](../) circuit with a N-channel FET low-side controlled array of 4 LEDs.

![Breadboard](./assets/USBlinky_bb.jpg?raw=true)

![Schematic](./assets/USBlinky_schematic.jpg?raw=true)

## Putting it in the shell

I opted for a freeform construction of the circuit rather than squeeze a PCB into the box.
Only the power lines of the USB connector are used.

![build_1](./assets/build_1.jpg?raw=true)

![build_2](./assets/build_2.jpg?raw=true)

## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [2N7000 datasheet](https://www.futurlec.com/Transistors/2N7000.shtml)
* [LEAP#563 Dual Variable Mode Oscillator](../)
