# RGBLedModule

Demo an RGB LED module

Here's a quick video of the module in action:

[![RGBLedModule Demo](http://img.youtube.com/vi/69Q7RoGBJaE/0.jpg)](http://www.youtube.com/watch?v=69Q7RoGBJaE)

## Notes

The RGB LED module is a convenience since it builds-in 150Ω current-limiting resistors for the reg, green and blue anodes
of a standard 5mm round RGB LED.

![Module](./assets/module.jpg?raw=true)

The demonstration program uses PWM to run a series of effects on the module.

NB: on my module, the red and blue pins are incorrectly labeled (swapped around).

## Construction

![Breadboard](./assets/RGBLedModule_bb.jpg?raw=true)

![The Schematic](./assets/RGBLedModule_schematic.jpg?raw=true)

![The Build](./assets/RGBLedModule_build.jpg?raw=true)

## Credits and References
* [Red-Green-Blue 5mm Round LED datasheet](http://www.futurlec.com/LED/RGB5LED.shtml)
* [Arduino, Lesson 3. RGB LEDs](https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/overview) - adafruit tutorial
* [Arduino Lesson 7. Make an RGB LED Fader](https://learn.adafruit.com/adafruit-arduino-lesson-7-make-an-rgb-led-fader/overview) - adafruit tutorial
* [KEYES KY-009 RGB 3 Color Full Color LED SMD Module](http://www.aliexpress.com/item/KEYES-KY-009-RGB-3-Color-Full-Color-LED-SMD-Module-For-Arduino-AVR-PIC/32365890192.html) - similar to the module I'm tsting (except uses a surface mount LED)
