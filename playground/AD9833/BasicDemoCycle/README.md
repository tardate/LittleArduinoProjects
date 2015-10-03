# AD9833/BasicDemoCycle

Run a basic waveform demo with an AD9833 module

## Notes

I bought an
[AD9833 module from a seller on aliexpress](http://www.aliexpress.com/item/E74-Free-Shipping-Programmable-Microprocessors-AD9833-Sine-Square-Wave-DDS-Signal-Generator-Module/32436878279.html)
with the intention of using it to build a function generator to add to my collection of test gear.

This project is a first test to explore:
* the SPI protocol it supports
* different waveforms it can produce
* controlling the frequency

Conclusion:
* once you get the SPI configuration correct, it works extremely well, and is very easy to control.
* accuracy at frequencies under 1MHz or so is very good
* accuracy over 1MHz inconclusive .. I need to do some more testing

### Module Interface

Here's the module, with pins attached:

![processing trace](./assets/module_front.png?raw=true)

![processing trace](./assets/module_rear.png?raw=true)

The labeling of the pins is a bit unusual. Here's the pin definition, and how they connect to an Arduino Uno for hardware SPI:

| Pin    | Usage                 | Arduino SPI Pin |
|--------|-----------------------|-----------------|
| VCC    | 2.3V to 5.5V          |                 |
| DGND   | digital ground        |                 |
| SDATA  | SPI data (MOSI)       | 11 MOSI         |
| SCLK   | SPI clock             | 13 SCK          |
| FSYNC  | SPI slave select (SS) | 10 SS           |
| AGND   | analog ground         |                 |
| OUT    | output signal         |                 |

NB: the "analog ground" is internally linked to "digital ground" according to the circuit giagram for the module.

### SPI Specifics

The module operates in SPI_MODE2 with MSBFIRST:
* data shifted on falling edge
* FSYNC pin is active low,
* accepts the most significant bit (MSB) of each transfer first.
* The SCLK pin is also specified to be kept high when not in use


### Waveform demo

The [BasicDemoCycle.ino](./BasicDemoCycle.ino) script is a simple non-interactive demo that runs through the different waveforms.

It uses the new SPI.beginTransaction/SPI.endTransaction syntax, although since the script only works with one SPI device,
it is redundant to wrap each command sequence in a transaction. But it is a good test of the "right way to do it".
NB: many other scripts found on the net pre-date this syntax.

It is running at very low frequencies in order to produce a visual demo. It sends the measure waveform to the serial port.
[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) reads the data from the serial port and plots the output value over time, with some coloration effects thrown in for good measure.

Here's a sample trace:

![processing trace](./assets/processing_trace.png?raw=true)

### Frequency Accuracy?

A few quick measurements with a frequency counter gave very good results under a few MHz.
But when I started pushing into the 6-12.5MHz realm, accuracy appeared to drop off markedly.
The might be a measurement issues; I'll have to take a closer look at that with some better test equipment.

## Construction

![Breadboard](./assets/BasicDemoCycle_bb.jpg?raw=true)

![The Schematic](./assets/BasicDemoCycle_schematic.jpg?raw=true)

Running at 300kHz, pretty accurate!

![The Build](./assets/BasicDemoCycle_build.jpg?raw=true)

## Credits and References
* [Module from a seller on aliexpress](http://www.aliexpress.com/item/E74-Free-Shipping-Programmable-Microprocessors-AD9833-Sine-Square-Wave-DDS-Signal-Generator-Module/32436878279.html)
* [AD9833 datasheet](http://www.analog.com/en/products/rf-microwave/direct-digital-synthesis-modulators/ad9833.html)
* [Sending out the right signals](https://gr33nonline.wordpress.com/2015/08/04/making-the-right-signals/) - informative round-up of various signal generator modules
* [Julian's Postbag: #41 - AD9833 Waveform Generator](https://youtu.be/y-q_ibWneSo) - my inspiration to try the unit!
