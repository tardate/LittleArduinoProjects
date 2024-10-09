# #482 WyLed!

.. when you allow an exploration of a chip (TM1638) to get a little out of hand! The WyLed free-form sculpture reacts to sound and blinks a 4-digit LED display.
An ATTiny85 provides a little brain, and the TM1638 handles all input and output.

![Build](./assets/WyLed_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/nnLa_BCAwtQ/0.jpg)](https://www.youtube.com/watch?v=nnLa_BCAwtQ)

## Notes

I checked out the basic operation of the TM1638 in
[LEAP#481](https://leap.tardate.com/playground/led7segment/tm1638/).
This project tries to do something a little more interesting with the chip.

One thing led to another ... and I ended up with a freeform sculpture that got a little out of hand!

### Sound Detector

Sound input is detected with a circuit borrowed from
[LEAP#482 Electret Sound-level Trigger](https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/Electret/SoundLevelTrigger).

It provides a binary signal based on a preset threshold (adjustable with a pot).
This is presented to the TM1638 as a "key" input via a 2N7000 mosfet.

### LED Display

A 4-digit LED 7-segment display is used as a pair of "eyes".
For the display unit I have, the pin connections are as follows:


| LED Module pin | Function | TM1638 pin |
|----------------|----------|------------|
| 1              | E        | SEG5/9     |
| 2              | D        | SEG4/8     |
| 3              | dp       | SEG8/12    |
| 4              | C        | SEG3/7     |
| 5              | G        | SEG7/11    |
| 6              | D4       | GRID1/24   |
| 7              | B        | SEG2/6     |
| 8              | D3       | GRID2/23   |
| 9              | D2       | GRID3/22   |
| 10             | F        | SEG6/10    |
| 11             | A        | SEG1/5     |
| 12             | D1       | GRID4/21   |


Note: numbering the digits is pretty arbitrary - just need to follow a convention. In my case:

* pins on the LED module are labelled D1-D4 from left to right
* I have mapped these so that GRID1-GRID4 operate from right to left

### Programming the ATtiny85

The [WyLed.ino](./WyLed.ino) has some supporting classes [TM1638.h](./TM1638.h) and [KeyController.h](./KeyController.h)
for interfacing with the TM1638, but does not require any additional libraries.

I used an ATtiny85 for the final build,
and programmed it using the Arduino ISP.

See my notes on
[LEAP#070](https://leap.tardate.com/playground/attiny/programmingwitharduinoisp/)
for how this is done.


## Construction

![Breadboard](./assets/WyLed_bb.jpg?raw=true)

![Schematic](./assets/WyLed_schematic.jpg?raw=true)

### Breadboard Build

Especially for moderately complex freeform builds, validation of a breadboard is a smart first step!
Note that I switched the SPI pin connections for the final ATtiny build (more convenient for construction).

![WyLed_bb_build](./assets/WyLed_bb_build.jpg?raw=true)

### Freeform Build

Came together in separately tested modules. First the electret input..

![build01_electrect_module](./assets/build01_electrect_module.jpg?raw=true)

I've got some SMD TM1638 so I used a bit of perfboard to make wiring them up a little easier..

![build02_electrect_and_TM1638_modules](./assets/build02_electrect_and_TM1638_modules.jpg?raw=true)

Bending the display module to shape..

![build03_display_module](./assets/build03_display_module.jpg?raw=true)

Rabbit Ears? Why ... beacause!

![build04_rabbit_ears](./assets/build04_rabbit_ears.jpg?raw=true)

Adding a little more bling to the base..

![build05_rabbit_ears_lit](./assets/build05_rabbit_ears_lit.jpg?raw=true)

Final build...

![Build](./assets/WyLed_build.jpg?raw=true)

## Credits and References

* [Titam TM1638](http://www.titanmec.com/index.php/en/product/view/id/303.html) - info from the original manufacturer, Shenzhen Titan Micro Electronics Co., Ltd. (深圳市天微电子股份有限公司)
* [WyLed on hackaday.io](https://hackaday.io/project/167034-wyled)
