# #454 ADR4540 Voltage Reference

Exploring the ADR4540 precision reference, tested with an Arduino as an external voltage reference.

![Build](./assets/ADR4540_build.jpg?raw=true)

## Notes

The Analog Devices ADR4540 is an "Ultralow Noise, High Accuracy Voltage Reference" with a 4.096V output voltage.
Other parts in the series are available for reference voltages of 2.048, 2.5, 3.0, 3.3, and 5.0V.

### Input and Output Stabilisation

The datasheet recommends capacitors on the input to improve transient response and reduce noise:

* 1 μF to 10 μF electrolytic or ceramic capacitor (transient response)
* An additional 100nF ceramic capacitor (reduce supply noise)

An output capacitor is required for stability and to filter out low level voltage noise.
For the ADR4540, the data sheet recommends minimum 100nF.

### Test Circuit

In this example, the ADR4540 is used to provide a 4.096V reference for an Arduino (AREF).

A voltage divider comprising a 10kΩ pot across the 5V supply provides a test input with a range of 0 to 5V.
This test signal is read on the Ardunio A0 analog input.

Since AREF is enabled (`analogReference(EXTERNAL)`), analog readings are all with respect the the 4.096V reference voltage.

A Nokia 5110 display provides a realtime reading of the analog input and the derived voltage reading.

### Code

The [ADR4540.ino](./ADR4540.ino) sketch drives the demo.

It uses the [Adafruit-PCD8544 Library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library)
to drive the 5110 display with hardware [SPI](https://www.arduino.cc/en/Reference/SPI).

## Construction

![Breadboard](./assets/ADR4540_bb.jpg?raw=true)

![Schematic](./assets/ADR4540_schematic.jpg?raw=true)

![ADR4540_module](./assets/ADR4540_module.jpg?raw=true)

## Credits and References

* [ADR4540 Product Info and Datasheet](https://www.analog.com/en/products/adr4540.html)
* [analogReference()](https://www.arduino.cc/reference/en/language/functions/analog-io/analogreference/)
* [Adafruit-PCD8544 Library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library) - GitHub
