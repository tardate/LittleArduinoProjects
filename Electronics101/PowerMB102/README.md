# #028 Power Supply - 3.3/5V MB102 Breadboard Power Supply

Demonstrates an 3.3/5V MB102 Breadboard Power Supply, using an Arduino to measure the voltage supply and plot the results with [Processing](https://www.processing.org).

![MB102 unit](./assets/MB102_product_image.jpg?raw=true)

## Notes

Various 3.3/5V MB102 Breadboard Power Supplies are a widely available for providing regulated 3.3V and 5V for projects on a breadboard.
For example, a [search on aliexpress](https://www.aliexpress.com/) will find many sellers, and prices can be lower than $1USD a unit.

It has some nice features (aside from the price!):

* master on/off switch and status LED
* power via 2.1mm plug or USB
* power to each breadboard rail independently selectable as off, 3.3V, or 5V.

The test circuit simply drives 3.3V on one rail and 5V on the other, both powering LEDs.
The Arduino measures the voltage of each rail through voltage dividers.

Measurement results:

| Selected voltage | Vout (DMM) | Vout (Arduino) |
|:----------------:|-----------:|---------------:|
| 3.3V             | 3.33       | 3.31
| 5V               | 5.00       | 4.99

Here's a sample trace of the two voltage rails as measured by the Arduino:

![processing trace](./assets/processing_trace.png?raw=true)

### Measure Voltage with an Arduino

Reading voltages with analog pins presents two challenges:

* The internal ADC has 10 bit resolution (0 - 1023) with 2 bit precision, so the accuracy is 0.25%
* The internal reference voltage (i.e. what 1023 will equal in volts) is nominally 5V but in practice is not very accurate (the board used for this test runs at about 4.93V)

For our purposes here, the ADC accuracy is not a big problem.
To overcome the reference voltage accuracy issue, the sketch scales the voltage reading according to the actual reference voltage of the board.
This must be measured with a multimeter and the `vref_mv` constant changed to this value (in mV).

For more detail, John Errington's Experiments with an Arduino includes an excellent study of [Precise voltage measurement with the Arduino](http://www.skillbank.co.uk/arduino/measure.htm).

### Construction

The Arduino only acts as a measurement device in this circuit.
Analog pins are used to read Vout via voltage dividers (Rd1/Rd2 and Rd3/Rd4).
The voltage dividers are to ensure that the Arduino never sees more than half the battery voltage (4.5V) on the analog pin.

[LEAP#090 PlotNValues (a simple Processing sketch)](../../playground/PlotNValues) reads the data from the serial port and plots the input and output value over time, with some coloration effects thrown in for good measure. In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

![The Breadboard](./assets/PowerMB102_bb.jpg?raw=true)

![The Schematic](./assets/PowerMB102_schematic.jpg?raw=true)

![The Build](./assets/PowerMB102_build.jpg?raw=true)

## Credits and References

* [Example MB201 power supply seller on aliexpress](https://www.aliexpress.com/item/3-3V-5V-MB102-Breadboard-Power-Supply-Module-For-for-Ar-Board/1859102523.html) - as at time of writing. Seller details may change so you'll need to do your own search.
* [Precise voltage measurement with the Arduino](http://www.skillbank.co.uk/arduino/measure.htm) from John Errington's Experiments with an Arduino
* [Download Processing](https://www.processing.org/download/)
