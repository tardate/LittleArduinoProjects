# #103 8x8 LED Matrix LedControl

Test driving and LED matrix with the LedControl library

Here's a demo of the matrix in action:

[![LedControlDemo](https://img.youtube.com/vi/z4q6lpOBHL0/0.jpg)](https://www.youtube.com/watch?v=z4q6lpOBHL0)

## Notes

This is a test of the [LedControl library](https://github.com/wayoda/LedControl) to drive a 1088AS LED matrix with a MAX7219 Serial-Interfaced LED Display Driver chip.

See the [MaxRawDemo](../MaxRawDemo) project for details of the hardware and setup, and a test of driving the hardware directly with SPI.

## Construction

![Breadboard](./assets/LedControlDemo_bb.jpg?raw=true)

![The Schematic](./assets/LedControlDemo_schematic.jpg?raw=true)

![The Build](./assets/LedControlDemo_build.jpg?raw=true)

## Credits and References

* [LED Matrix kit for sale on aliexpress](https://www.aliexpress.com/item/free-shipping-MAX7219-Dot-matrix-module-display-module-DIY-kit-SCM-control-module-for-Arduino-microcontroller/2011910501.html)
* [LedControl](https://github.com/wayoda/LedControl) library at GitHub
* [LedControl Overview](http://playground.arduino.cc/Main/LedControl) on the arduino playground
* [MAX7219 datasheet](https://www.futurlec.com/Maxim/MAX7219.shtml)
* [1088AS datasheet](http://megtestesules.info/hobbielektronika/adatlapok/LED8x8_1088AS.pdf)
* [MAX72XX Hardware](http://playground.arduino.cc/Main/MAX72XXHardware) page on the Arduino playground
* [Lab 15: scrolling test message on an LED dot-matrix display](http://embedded-lab.com/blog/lab-15-scrolling-text-message-on-an-led-dot-matrix-display/)
