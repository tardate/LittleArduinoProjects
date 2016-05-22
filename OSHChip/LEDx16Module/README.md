# #216 LEDx16Module

Driving an SPI LED module with the OSHChip.

![LEDx16Module_build](./assets/LEDx16Module_build.jpg?raw=true)

## Notes

How easy is SPI with the OSHChip? I thought I'd find out by first controlling a
module that has a very basic SPI-ish slave interface.

I'm using the [LEDx16Module](../playground/LEDx16Module) that I designed in the
[KiCad like a Pro](http://txplore.tv/courses/kicad-pro)
course from Tech Explorations. It has dual 74HC595 shift registers that can be driven with SPI
to control 16 onboard LEDs.

### SPI Driver Options

It seems there's at least three options:

* use the [SPI](https://developer.mbed.org/handbook/SPI) class that is part of the mbed standard library
* go direct to registers for SPI control
* pick one of the other SPI libraries out there, for example [SPI_Demo_Nano](https://developer.mbed.org/teams/RedBearLab/code/SPI_Demo_Nano/) that implements an SPI class very similar to the Arduino SPI library.

I'm going to code this one with the [mbed online compiler](https://developer.mbed.org), so I'll start with the first option.

### Configuring and Using SPI

I'll probably publish my project on mbed, but for now the [source is all here](./source).
The demo code is largely copied from the [LEDx16Module](../playground/LEDx16Module) demo.

It sets SPI for an 8 bit data frame, spi mode 0, 1MHz clock rate:

```
// Setup spi: 8 bit data frame, spi mode 0, 1MHz clock rate
spi.format(8, 0);
spi.frequency(1000000);
```

And 16-bits worth of data (for the two shift registers) is sent in two write operations:

```
led_module_cs = 0;
spi.write(data);
spi.write(data >> 8);
led_module_cs = 1;
```

Two quirks that I still don't fully understand:
* I thought IO should be able to set a 16-bit frame with `format(16, 0)` but I couldn't get it to work.
*  even though SPI.write takes an "int", it still only sends the 8 lower bits, hence the transfer in two calls

Also note I haven't resorted to bulk transfers using the `transfer` method in this case,
since I'm not sending large quantities of data, and not expecting any reply.

## Construction

There's not much to the build. Basically hook together three modules:

* the [OSHChip](http://oshchip.org/)
* the [LEDx16Module](../playground/LEDx16Module)
* 3.3V power supply - I'm using a [Buck Converter Module](https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/BuckConverterModules#module-2)

![LEDx16Module_bb](./assets/LEDx16Module_bb.jpg?raw=true)

![LEDx16Module_schematic](./assets/LEDx16Module_schematic.jpg?raw=true)

![LEDx16Module_build](./assets/LEDx16Module_build.jpg?raw=true)

## Credits and References
* [OSHChip](http://oshchip.org/)
* [LEDx16Module](../playground/LEDx16Module)
* [Buck Converter Module](https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/BuckConverterModules#module-2)
* [SPI](https://developer.mbed.org/handbook/SPI) - mbed handbook
* [KiCad like a Pro](http://txplore.tv/courses/kicad-pro) - course materials
