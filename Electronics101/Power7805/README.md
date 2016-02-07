# #027 Power Supply - LM7805 Stable 5V Source

Demonstrates the LM7805 5V regulator, using an Arduino to measure the voltage supply and plot the results with [Processing](https://www.processing.org).

## Notes

The LM7805 provides regulated 5V, ideal when current requirements are moderate (up to 1A with heatsink).
Note that other chips in the LM78xx range are available to provide other voltages.

For the chip under test, we get a stable voltage just a tad under 5V, as measure with a multimeter and the Arduino:

| Vout  | Derivation
|-------|---------------
| 4.98  | actual (DMM)
| 4.982 | actual (Arduino)

Here's a sample trace of the voltage as measured by the Arduino:

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
Analog pin is used to read Vout via a voltage divider (Rd1/Rd2). The voltage divider is to ensure that the Arduino never sees more than half the battery voltage (4.5V) on the analog pin.

[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) reads the data from the serial port and plots the input and output value over time, with some coloration effects thrown in for good measure. In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

![The Breadboard](./assets/Power7805_bb.jpg?raw=true)

![The Schematic](./assets/Power7805_schematic.jpg?raw=true)

![The Build](./assets/Power7805_build.jpg?raw=true)

## Credits and References
* [LM7805 datasheet](http://www.futurlec.com/Linear/7805T.shtml)
* [Precise voltage measurement with the Arduino](http://www.skillbank.co.uk/arduino/measure.htm) from John Errington's Experiments with an Arduino
* [Download Processing](https://www.processing.org/download/)
