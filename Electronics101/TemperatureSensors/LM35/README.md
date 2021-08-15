# #595 LM35 Temperature Sensor

Reading ambient temperature with the LM35 and an Arduino without output display on a Nokia 5110 LCD.

![Build](./assets/LM35_build.jpg?raw=true)

## Notes

This circuit uses an LM35 Precision Centigrade Temperature Sensor to measure ambient temperature,
and display the result on a Nokia 5110 comptible LCD.

The LM35 is part of a series of easy to use temperature sensors:

|Sensor           | Output Voltage                                 | Linearity |
|-----------------|------------------------------------------------|-----------|
|LM35 (LM35DZ)    | proportional to temperature in Celsius (ºC)    | 10mV/ºC   |
|LM335            | proportional to temperature in Kelvin (ºK)     | 10mV/ºK   |
|LM34             | proportional to temperature in Fahrenheit (ºF) | 10mV/ºF   |

Specifications for the LM35:

* Directly calibrated in ̊Celsius (Centigrade)
* 0.5̊C accuracy
* Less than 60 μA current drain
* Low impedance output, 0.1 Ω for 1 mA load
* Rated for full −55̊ to +150 ̊C range


## Construction

![Breadboard](./assets/LM35_bb.jpg?raw=true)

![Schematic](./assets/LM35_schematic.jpg?raw=true)

## Code

See [LM35.ino](./LM35.ino) for the sketch.

Reading temperature is straight-forward:

* LM35 output voltage is read with analog input
* scaled to 10mV/ºC

Libraries used:

* [u8glib](https://github.com/olikraus/U8glib_Arduino) library used for driving the LCD

## Credits and References

* [LM35 datasheet](https://www.futurlec.com/Linear/LM35DZ.shtml)
* [Introducing LM35, LM335 and LM34 Temperature Sensors](https://randomnerdtutorials.com/arduino-lm35-lm335-lm34-temperature-sensor/)
