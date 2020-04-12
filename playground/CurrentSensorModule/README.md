# #168 CurrentSensorModule

Test an ACS712 current sensor module with display on a 5110 LCD

![The Build](./assets/CurrentSensorModule_build.jpg?raw=true)

## Notes

This is a quick test of a
[current sensor module](https://www.aliexpress.com/item/NEW-5A-Hall-Current-Sensor-Module-ACS712-model-5A-In-stock-high-quality/1778579838.html)
I picked up recently. It is rated for 5A (but other modules are available for different current scales).

![Module](./assets/module.jpg?raw=true)

The circuit simply measures a variable current (manually controlled wiper on a pot) and displays the result on a 5110 LCD.
Minimum resistance of the load circuit is 10Ω, so +/-50V maximum input voltage to keep within the +/-5A tolerance of the module.

For test purposes with a 5V source and 0.25W resistors, I have R2 is set at 100Ω to prevent an overload.
That means my test source only ranges from 0-50mA, so not a real power test.

In an alternative configuration, I have a 9V source pumping ~700mA through the current sensor.

At first my resultswere terrible, like+/-0.7A measuring as +/-0.2A.
These readings are coincidentally quite consistent with a +/-20A scale.
When I change to +/-20A sensitivity then suddenly my readings are very close to what my multimeter says.

Although the chip on my module is clearly marked ACS712ELC-05B (+/-5A sensitivity according to the datasheet),
I'm guessing it is really an ACS712ELC-20A (+/-20A).
Perhaps wrong markings in a QA reject batch?
Perhaps also why it shows up in a 70 cent module from China!!

![The Build 700mA](./assets/CurrentSensorModule_build_700mA.jpg?raw=true)

### Module Specifications

* the current sensor chips: ACS712ELC-05B
* pin 5V power supply, on-board power indicator
* the module can be measured plus or minus 5 amps, corresponding to the analog output of 185 mV / A
* there is no the detection current through, the output voltage is VCC / 2

Given the +/-5A range and taking a reading through the analog point (0-1023), then the
actual current will equal the `analog input / 1023 * 2 * 5 - 5`.

That's a resolution of around 10mA, so not very sensitive, but perhaps good enough for gross current monitoring.

### Module Connections

| Pin/Terminal | Description         |
|--------------|---------------------|
| +            | Sensor power 3.3/5V |
| -            | Sensor ground       |
| s            | Sensor output       |
| VCC          | Input positive DC   |
| GND          | Input ground        |

### Module Construction

The module is basically connectors and a few supporting components around an ACS712 surface mount chip that does the hard work.

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

![Breadboard](./assets/CurrentSensorModule_bb.jpg?raw=true)

![The Schematic](./assets/CurrentSensorModule_schematic.jpg?raw=true)

![The Build](./assets/CurrentSensorModule_build.jpg?raw=true)

## Credits and References

* [ACS712 current sensor module](https://www.aliexpress.com/item/NEW-5A-Hall-Current-Sensor-Module-ACS712-model-5A-In-stock-high-quality/1778579838.html) from a seller on aliexpress
* [ACS712 datasheet](https://www.sparkfun.com/datasheets/BreakoutBoards/0712.pdf)
* [ACS712 Current Sensor Module](../../FritzingParts/ACS712CurrentSensorModule) fritzing part
