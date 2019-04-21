# #101 MaxRawDemo

Drive an 8x8 LED Matrix with a MAX7219 chip an raw SPI commands


## Notes

This is a first test of an
[8x8 LED module kit from a seller on aliexpress](https://www.aliexpress.com/item/free-shipping-MAX7219-Dot-matrix-module-display-module-DIY-kit-SCM-control-module-for-Arduino-microcontroller/2011910501.html). This is a pretty common device available from many sources, either as prefab module or parts kit.

The kit includes a "1088AS" 8x8 LED module, which is single colour (red) with row pins cathode and column pins anode.

Although it is possible to drive an LED matrix directly, it quickly becomes wasteful of GPIO pins.
This kit minimises the pins required by including a MAX7219 Serial-Interfaced LED Display Driver chip.
The microcontroller the just needs 3 pins to drive the MAX7219 using and SPI protocol.

There are libraries available to talk to the MAX7219, such as the [LedControl](https://github.com/wayoda/LedControl) library.
However this project uses raw SPI just for the sake of developing some familiarity with the operation of the MAX7219.
See the [LedControlDemo](../LedControlDemo) project for a test driving with the LedControl library.

The LED module is connected to the Arduino with three pins as follows (in addition to +5V power and ground).

| Connection | Pin |
|------------|-----|
| MOSI/DIN   | 10  |
| CS         | 11  |
| SCK/CLK    | 12  |

Turns out that talking to the array via the MAX7219 is pretty simple!
We just shift out a 16-bit command which is latched on the rising edge of the CS clock select pin.
Each 16 bits comprises an 8-bit register address and 8 bits of data, which is well described in the datasheet.

See code in the [MaxRawDemo.ino](./MaxRawDemo.ino) sketch demonostrates the bare minimum required to start writing to the display.
Next up, I guess I need to get it to display something interesting!

## Construction

![Breadboard](./assets/MaxRawDemo_bb.jpg?raw=true)

![The Schematic](./assets/MaxRawDemo_schematic.jpg?raw=true)

![The Build](./assets/MaxRawDemo_build.jpg?raw=true)

### The Kit

![Kit Parts](./assets/MaxRawDemo_kit_parts.jpg?raw=true)

![PCB Front](./assets/MaxRawDemo_pcb_front.jpg?raw=true)

![PCB Back](./assets/MaxRawDemo_pcb_back.jpg?raw=true)

![Kit Completed](./assets/MaxRawDemo_kit_complete.jpg?raw=true)


## Credits and References
* [LED Matrix kit for sale on aliexpress](https://www.aliexpress.com/item/free-shipping-MAX7219-Dot-matrix-module-display-module-DIY-kit-SCM-control-module-for-Arduino-microcontroller/2011910501.html)
* [MAX7219 datasheet](https://www.futurlec.com/Maxim/MAX7219.shtml)
* [1088AS datasheet](http://megtestesules.info/hobbielektronika/adatlapok/LED8x8_1088AS.pdf)
* [MAX72XX Hardware](http://playground.arduino.cc/Main/MAX72XXHardware) page on the Arduino playground
* [LEDMatrix](http://playground.arduino.cc/Main/LEDMatrix) - excellent overview on driving LED matrix units with an Arduino
* [LedControl](https://github.com/wayoda/LedControl) library at GitHub
* [LedControlDemo](../LedControlDemo) project - test driving with the LedControl library

