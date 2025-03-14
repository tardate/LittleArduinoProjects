# #374 LT1019 Precision Reference

Exploring the LT1019 precision reference, tested with an Arduino as an external voltage reference.

![Build](./assets/LT1019_build.jpg?raw=true)

## Notes

The Linear Technology (now Analog Devices) [LT1019](https://www.analog.com/en/products/lt1019.html) is a precision voltage reference designed for high stability and low drift, available in fixed output voltages such as 2.5V, 4.5V, 5V, and 10V. It features exceptionally low temperature coefficient and long-term stability, making it ideal for precision measurement, data acquisition, and calibration applications. The device operates with low power consumption and provides excellent line and load regulation, ensuring reliable performance in demanding analog and mixed-signal circuits. Compared to standard Zener-based references, the LT1019 offers superior accuracy, noise performance, and thermal stability.

For this test, I am using a 2.5V LT1019-2.5 in a DIP8 package.

### Stabilising the Reference Output

The datasheet recommends for the best transient load response to add a bypass RC filter on the output:

* 2-5Ω + 2µF tantalum

Although my test setup is not really prone to such transient issues, I've added the bypass but with 2x10Ω resistors in parallel and a 2.2µF electrolytic.

As expected, the voltage reference performs just fine, expecially within the 10-bit resolution of of the ATmega328.

### Test Circuit

In this example, the LT1019 is used to provide a 2.5V reference for an Arduino (AREF).
This requires the external reference to be enabled `analogReference(EXTERNAL)`

A voltage divider comprising a 10kΩ pot in series with a 10kΩ resistor across the 5V supply provides a test input with a range of roughly 0 to 2.5V.
This test signal is read on the Ardunio A0 analog input.

Since AREF is enabled (`analogReference(EXTERNAL)`), analog readings are all with respect the the 2.5V reference voltage.

A Nokia 5110 display provides a realtime reading of the analog input and the derived voltage reading.

### Code

The [LT1019.ino](./LT1019.ino) sketch drives the demo.

It uses the [Adafruit-PCD8544 Library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library)
to drive the 5110 display with hardware [SPI](https://www.arduino.cc/en/Reference/SPI).

## Construction

![Breadboard](./assets/LT1019_bb.jpg?raw=true)

![Schematic](./assets/LT1019_schematic.jpg?raw=true)

![Build](./assets/LT1019_build.jpg?raw=true)

## Credits and References

* [LT1019 info and datasheet](https://www.analog.com/en/products/lt1019.html)
* [analogReference()](https://www.arduino.cc/reference/en/language/functions/analog-io/analogreference/)
* [Adafruit-PCD8544 Library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library) - GitHub
* [..as mentioned on my blog](https://blog.tardate.com/2018/01/leap374-lt1019-voltage-reference.html)
