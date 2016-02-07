# #167 VoltageSensorModule

Test a 25V voltage sensor module

## Notes

This is a quick test of a
[25V voltage sensor](http://www.aliexpress.com/item/Standard-Voltage-Sensor-Module-Test-Electronic-Bricks-For-Robot-For-Arduino/32265558651.html)
I picked up recently.

![Module](./assets/module.jpg?raw=true)

The circuit simply measures a variable voltage (manually controlled wiper on a pot) and displays the result on a 5110 LCD.


### Module Specifications

* Voltage input range : 0 - 25V DC
* Voltage detection range : 0.02445 - 25V DC
* Voltage analog resolution : 0.00489 V

Given the 25V range and taking a reading through the analog point (0-1023), then the
actual voltage will equal the `analog input / 1023 * 25`.

### Module Connections

| Pin/Terminal | Description         |
|--------------|---------------------|
| +            | Sensor power 3.3/5V |
| -            | Sensor ground       |
| s            | Sensor output       |
| VCC          | Input positive DC   |
| GND          | Input ground        |

### Module Construction

Well taking a closer examination, there's nothing much too it. As you might expect,
it turns out to be nothing more than a voltage divider.

The sensor power pin is bogative - it's not connected to anything.
The module is not isolated - the input ground is common with the sensor ground.

The input voltage is applied across two resistors in series, with the sensor output tapped at the midpoint.
The resistors are 0805 surface mount "precision" (4-digit code) resistors of values:
* 3002 (30kΩ)
* 7501 (7.5kΩ)

Hence the sensor output will read as [7.5/37.5 or 20%](http://www.wolframalpha.com/input/?i=7.5k%CE%A9%2F37.5k%CE%A9)
of the input voltage. Hence the 25V maximum voltage rating on the unit, since
[20% is 5V](http://www.wolframalpha.com/input/?i=7.5k%CE%A9%2F37.5k%CE%A9+*+25V), the input limit for a 5V Arduino.


### 5110 LCD SPI Configuration

The [u8glib](https://github.com/olikraus/u8glib) takes advantage of hardware SPI, which means
pin connections are dictated for at least MOSI and SCK.

Here's the mapping from the terminology used by my particular 5110 module and pins on an Arduino Uno.

| Pin    | Usage                 | Arduino Uno Pin |
|--------|-----------------------|-----------------|
| RST    | reset                 | 8               |
| CE/SCE | chip enable           | 10 SPI SS       |
| DC     | address line 0        | 9               |
| DIN    | data in               | 11 SPI MOSI     |
| CLK    | clock                 | 13 SPI SCK      |
| VCC    | power                 |                 |
| BL     | Backlight on when GND |                 |
| GND    | Ground                |                 |


## Construction

![Breadboard](./assets/VoltageSensorModule_bb.jpg?raw=true)

![The Schematic](./assets/VoltageSensorModule_schematic.jpg?raw=true)

![The Build](./assets/VoltageSensorModule_build.jpg?raw=true)

## Credits and References
* [Voltage Sensor Module](http://www.aliexpress.com/item/Standard-Voltage-Sensor-Module-Test-Electronic-Bricks-For-Robot-For-Arduino/32265558651.html) - from seller on aliexpress
* [Voltage Sensor Module](../../FritzingParts/VoltageSensorModule) fritzing part
* [SMD resistor code calculator](http://www.hobby-hour.com/electronics/smdcalc.php)
