# #422 VL53L0X/LaserTapeMeasure

Using a VL53L0X ranging sensor to make a short-range laser tape measure with an Arduino and Nokia 5110 display.

![Build](./assets/LaserTapeMeasure_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The [VL53L0X](https://www.st.com/en/imaging-and-photonics-solutions/vl53l0x.html)
is a very small Time-of-Flight (ToF) ranging sensor.

It is quite widely available as a module, including from Adafruit - see their [information page](https://learn.adafruit.com/adafruit-vl53l0x-micro-lidar-distance-sensor-breakout/downloads).

For this project I'm taking the module for a test drive and building a short-range tape measure with an Arduino and Nokia 5110 display.

Robojax has a nice video on YouTube that gives a good introduction to the chip and module:

[![clip](http://img.youtube.com/vi/0GxFoq_zPt4/0.jpg)](http://www.youtube.com/watch?v=0GxFoq_zPt4)

There are a few board designs around, this is quite common. It squeezes everything including regulator into a very small form factor:

![module_front](./assets/module_front.jpg?raw=true)
![module_back](./assets/module_back.jpg?raw=true)

## Construction

The VL53L0X module just needs power and I²C connections. Because the module has an onboard regulator, it can take either 3.3V or 5V from the Arduino.

![Breadboard](./assets/LaserTapeMeasure_bb.jpg?raw=true)

![Schematic](./assets/LaserTapeMeasure_schematic.jpg?raw=true)


## Code

The [LaserTapeMeasure.ino](./LaserTapeMeasure.ino) sketch implements a simple tape measure with measurements displayed on a Nokia 5110 LCD.

Libraries used:

* [Adafruit_VL53L0X](https://github.com/adafruit/Adafruit_VL53L0X)
* [u8glib](https://github.com/olikraus/U8glib_Arduino) - for LCD control

Note: I first tried to use the Adafruit PCD8544 and GFX libraries, but that proved just too much for the mighty memory of the Atmega328.

### Library Hack

[Adafruit_VL53L0X_Customised.h](./Adafruit_VL53L0X_Customised.h) is a slightly customised version
of `Adafruit_VL53L0X.h` from the Adafruit library.
The change simply makes the `DeviceInfo` instance variable public so I can use that data in the splash screen.


## Test Drive

The startup screen actually prints the device name and version as reported by the VL53L0X chip itself:

![LaserTapeMeasure_startup](./assets/LaserTapeMeasure_startup.jpg?raw=true)

Range-finding in action:

![Build](./assets/LaserTapeMeasure_build.jpg?raw=true)

The effective range I'm seeing (with default settings) is from about 2cm to 50cm.

The device supports 4 different ranging profiles, including high accuracy and long range (up to 2m).
I haven't investigated those yet - and they don't appear to be directly supported by the
Adafruit_VL53L0X C++ interface class (requires going under the hood of the API).


## Credits and References
* [VL53L0X Product Info](https://www.st.com/en/imaging-and-photonics-solutions/vl53l0x.html)
* [VL53L0X Datasheet](https://www.st.com/resource/en/datasheet/vl53l0x.pdf)
* [Adafruit VL53L0X module and information page](https://learn.adafruit.com/adafruit-vl53l0x-micro-lidar-distance-sensor-breakout/downloads)
* [..as mentioned on my blog](https://blog.tardate.com/2018/10/leap422-vl53l0x-laser-tape-measure.html)
