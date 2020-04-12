# #148 AD9833/BasicDemoCycle

Run a basic waveform demo with an AD9833 module

## Notes

I bought an
[AD9833 module from a seller on aliexpress](https://www.aliexpress.com/item/E74-Free-Shipping-Programmable-Microprocessors-AD9833-Sine-Square-Wave-DDS-Signal-Generator-Module/32436878279.html)
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

Here's the module, with pins attached (with my imperfect soldering, so don't blame the manufacturer!):

![module front](./assets/module_front.jpg?raw=true)

![module rear](./assets/module_rear.jpg?raw=true)

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

NB: the "analog ground" is internally linked to "digital ground" according to the circuit diagram for the module.

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
[PlotNValues (a simple Processing sketch)](../../../processing/PlotNValues) reads the data from the serial port and plots the output value over time, with some coloration effects thrown in for good measure.

Here's a sample trace. It shows a few cycles of each waveform. From the left:
* sine wave
* square wave (normal cycle time)
* triangle wave
* square wave (halved cycle time i.e. twice as fast)
* output off

Note that square waves are rail-to-rail, since they bypass the DAC. Other waveforms peak at 0.65V per the datasheet.

![processing trace](./assets/processing_trace.png?raw=true)

### Frequency Accuracy?

A few quick measurements with a frequency counter gave very good results under a few MHz.
But when I started pushing into the 6-12.5MHz realm, accuracy appeared to drop off markedly.

This may simply be the influence of running the module on a breadboard. I should try it on a PCB.

For now, here are some results (AC-coupled scope traces) with a sinusoid waveform in the breadboard layout.

At 1MHz, still a decent output:

![scope_1MHz trace](./assets/scope_1MHz.gif?raw=true)

By 8MHz, the waveform is quite distorted and unstable but still on frequency:

![scope_8MHz trace](./assets/scope_8MHz.gif?raw=true)

By 12MHz, it has devolved to a heavily-modulated mess:

![scope_12MHz trace](./assets/scope_12MHz.gif?raw=true)


## Construction

NB: I created a
[custom Fritzing Part available here](../../../FritzingParts/AD9833_Module) for these diagrams.

![Breadboard](./assets/BasicDemoCycle_bb.jpg?raw=true)

![The Schematic](./assets/BasicDemoCycle_schematic.jpg?raw=true)

Running at 300kHz, pretty accurate!

![The Build](./assets/BasicDemoCycle_build.jpg?raw=true)

## Credits and References

* Thanks to Michaël via email for the idea of an "off" step in the demo cycle
* [Module from a seller on aliexpress](https://www.aliexpress.com/item/E74-Free-Shipping-Programmable-Microprocessors-AD9833-Sine-Square-Wave-DDS-Signal-Generator-Module/32436878279.html)
* [AD9833 datasheet](http://www.analog.com/en/products/rf-microwave/direct-digital-synthesis-modulators/ad9833.html)
* [Arduino SPI Reference](https://www.arduino.cc/en/Reference/SPI)
* [Sending out the right signals](https://gr33nonline.wordpress.com/2015/08/04/making-the-right-signals/) - informative round-up of various signal generator modules
* [Julian's Postbag: #41 - AD9833 Waveform Generator](https://youtu.be/y-q_ibWneSo) - my inspiration to try the unit!
* [AD9833 Waveform Generator](http://www.vwlowen.co.uk/arduino/AD9833-waveform-generator/AD9833-waveform-generator.htm) - good project write-up
* [Waveform Generation with AD9833, and SPI](http://hades.mech.northwestern.edu/index.php/Waveform_Generation_with_AD9833,_and_SPI) - some more good details
