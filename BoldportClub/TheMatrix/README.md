# #299 TheMatrix

Building The Matrix (Boldport Club project #11) is an I²C-controlled 24x5 LED matrix display, powered by an AMS AS1130 LED driver.

![Build](./assets/TheMatrix_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The Matrix is an I²C-controlled 24x5 LED matrix display, powered by an AMS AS1130 LED driver. It's made of 0.2mm thick circuit board so it can slightly bend. A few can be chained together for a larger display.

The project was made possible by the kind support of AMS who donated the LED drivers, and Eurocircuits who subsidised the cost of the PCBs.

Now I have one built, time to test it out. So far

* [LedTest](./LedTest) - first check under Arduino control
* [Firecracker](./Firecracker) - a firecracker simulacrum running on the Matrix
* [GameOfLife](./GameOfLife) - Conway's Game of Life running on the Matrix
* [KeypadControl](./KeypadControl) - use a 20-button keypad to write a scrolling message on the Matrix


### Parts

| Ref      | Item                                                                       |  Qty |
|----------|----------------------------------------------------------------------------|------|
| IC1      | AS1130 LED matrix driver IC, AMS AS1130                                    |   x1 |
|  C1      | 0.1µF 0805 SMD ceramic capacitor, Multicomp MC0805B104K500CT               |   x1 |
|  C2      | 10µF 0805 SMD ceramic capacitor, Multicomp MC0805X106K160CT (clear casing) |   x1 |
| R1-4     | 4.7KΩ 0805 SMD resistor, Multicomp 2446989                                 |   x4 |
|  J1      | 8 contacts 1 row 2.54 mm SMD header, Samtec TSM-108-01-T-SH                |   x1 |
| LED1-120 | red 0805 LEDs, Kingbright KPT-2012EC                                       | x121 (1 spare) |

![kit_unboxing](./assets/kit_unboxing.jpg?raw=true)

## Construction

The Matrix is laid out in a 5x24 matrix as described in the datasheet (Figure 54).
This allows for using the AS1130 scrolling feature for scrolling without the need of communication with a microprocessor.

![Schematic](./assets/TheMatrix_schematic.jpg?raw=true)


### Assembly

I used the [Matrix stencil](https://www.oshstencils.com/#projects/b0f4128d644cff5424abcb2829a05980179f08fc) from OSHStencils
and a hot-air gun for the assembly.

![kit_stencil](./assets/kit_stencil.jpg?raw=true)

I first did the LEDs on one side then the AMS1130 and supporting components on the reverse side with hot air.
Then finally hand-soldered the pin connector.

![kit_assembly_start](./assets/kit_assembly_start.jpg?raw=true)

![kit_assembly_led_placement](./assets/kit_assembly_led_placement.jpg?raw=true)

![kit_assembly_connector](./assets/kit_assembly_connector.jpg?raw=true)

After an initial inspection, I only had a couple of manual fixups required:

* two LEDs not connected properly after reflow
* a solder bridge between two pins on the AMS1130 that wouldn't clear under hot air



![Build](./assets/TheMatrix_build.jpg?raw=true)

## Credits and References
* [The Matrix](http://www.boldport.club/shop/product/687424508) - in the Boldport shop
* [The Matrix](http://boldport.com/matrix) - project page
* [The Matrix](https://github.com/boldport/thematrix) - OSH files on GitHub
* [The Matrix](http://community.boldport.club/projects/p11-thematrix/) - club community site, packed with resources for the project
* [AS1130 datasheet and info](http://ams.com/eng/Products/Power-Management/LED-Drivers/AS1130)
* [The Matrix stencil](https://www.oshstencils.com/#projects/b0f4128d644cff5424abcb2829a05980179f08fc) - from OSHStencils
* [..as mentioned on my blog](http://blog.tardate.com/2017/05/leap299-the-boldport-club-matrix.html)
