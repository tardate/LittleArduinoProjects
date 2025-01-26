# #598 LM335 Temperature Sensor

Reading ambient temperature with the LM335 and an Arduino without output display on a Nokia 5110 LCD.

![Build](./assets/LM335_build.jpg?raw=true)

## Notes

This circuit uses an LM335 Precision Kelvin Temperature Sensor to measure ambient temperature,
and display the result on a Nokia 5110 comptible LCD.

The LM35 is part of a series of easy to use temperature sensors:

| Sensor | Output Voltage                                 | Linearity |
|--------|------------------------------------------------|-----------|
| LM34   | proportional to temperature in Fahrenheit (ºF) | 10mV/ºF   |
| LM35   | proportional to temperature in Celsius (ºC)    | 10mV/ºC   |
| LM335  | proportional to temperature in Kelvin (ºK)     | 10mV/ºK   |

Specifications for the LM335:

* Directly calibrated in  ̊Kelvin
* 1 ̊C initial accuracy available
* Operates from 400 μA to 5 mA
* Less than 1Ω dynamic impedance
* Easily calibrated
* LM335 operates from −40 ̊C to +100 ̊C.


NB: I'm testing with an LM335 sourced from [element14](https://sg.element14.com/),
and it works fine. I had a number of LM335 components ordered from aliexpress sellers which were all bad (either failed open, or had fixed 0.7B drop regardless of temperature).

## Construction

Unlike the LM34 and LM35, the LM335 requires an external pull-up resistor on the anode, sized such that sufficient current can flow and enable the device. I'm using 4.7kΩ

![Breadboard](./assets/LM335_bb.jpg?raw=true)

![Schematic](./assets/LM335_schematic.jpg?raw=true)

## Code

See [LM335.ino](./LM335.ino) for the sketch.

Reading temperature is straight-forward:

* LM35 output voltage is read with analog input
* scaled to 10mV/ºK

Libraries used:

* [u8glib](https://github.com/olikraus/U8glib_Arduino) library used for driving the LCD

## Testing

with 2.2kΩ current-limiting resistor

with 1st batch - LM335Z chips

acts like open circuit

analog_reading: 1023.00
kelvin: 500.25


with 2nd batch - LM335AZ chips

analog_reading: 142.00
kelvin: 69.20

interesting - same result if reversed. this is reading about 0.7V - 1 diode drop



## Credits and References

* [LM335 datasheet](https://www.st.com/resource/en/datasheet/lm335.pdf)
* [Introducing LM35, LM335 and LM34 Temperature Sensors](https://randomnerdtutorials.com/arduino-lm35-lm335-lm34-temperature-sensor/)
* [The LM335 Temperature Sensor](http://web.mit.edu/rec/www/workshop/lm335.html)
* Troubleshooting:
  * [LM335 Not Accurate](https://forum.arduino.cc/t/lm335-not-accurate/68029/3)
  * [LM335 Troubleshooting](https://eddiesoft.id.au/LM335%20Troubleshooting.html)
