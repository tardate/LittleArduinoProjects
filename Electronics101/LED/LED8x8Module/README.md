# #557 LED 8x8 Module

Building and using an 8x8 LED matrix with MAX7219 driver module.

![Build](./assets/LED8x8Module_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/aVieg4loAUo/0.jpg)](https://www.youtube.com/watch?v=aVieg4loAUo)

## Notes

These [MAX7219 8x8 LED dot matrix modules](https://www.aliexpress.com/item/32798846993.html) are very common and quite cheap.
Usually they come assembled, but one can find sellers offering them as a "DIY" kit. The DIY option is
not necessarily cheaper, but they are a nice quick little soldering project and may be more convenient if
the plan is to daisy-chain multiple modules.

The kit is basically just the 1088AS LED matrix and a PCB for the MAX7219, pin headers, a pull-up resistor and decoupling capacitor.

![kit](./assets/kit.jpg?raw=true)

### 8x8 LED Matrix

* Part Number: 1088AS
* Face Color: Black
* Type: Row Cathode Column Anode
* Wavelength : 625 ~ 630nm
* Emitted Colour: Red
* Forward Voltage : 2.1V ~ 2.5V
* Forward Current: 20mA
* Dimesions: 32mm x 32mm x 8.0mm

![1088AS_module](./assets/1088AS_module.jpg?raw=true)
![1088AS_schematic](./assets/1088AS_schematic.jpg?raw=true)

## Construction

![Breadboard](./assets/LED8x8Module_bb.jpg?raw=true)

![Schematic](./assets/LED8x8Module_schematic.jpg?raw=true)

![Build](./assets/LED8x8Module_build.jpg?raw=true)

## Example Sketch

[LED8x8Module.ino](./LED8x8Module.ino) is a simple Arduino sketch that uses the LedControl library
to sequence through all rows and columns to verify that addressing is correct and that all LEDs
are functioning correctly.

## Credits and References

* [1PCS MAX7219 dot matrix module microcontroller module DIY KIT](https://www.aliexpress.com/item/32798846993.html)
* [MAX7219 product info and datasheet](https://www.maximintegrated.com/en/products/power/display-power-control/MAX7219.html)
* [How to Use the MAX7219 to drive an 8x8 LED display](https://www.best-microcontroller-projects.com/max7219.html)
