# #424 VL53L0X/TheToneRanger

A simple modification of the basic VL53L0X example to add audio indication of range.

Here's a quick demo..

[![clip](https://img.youtube.com/vi/XjAN2eW-bek/0.jpg)](https://www.youtube.com/watch?v=XjAN2eW-bek)

## Notes

The [VL53L0X](https://www.st.com/en/imaging-and-photonics-solutions/vl53l0x.html)
is a very small Time-of-Flight (ToF) ranging sensor.
It can be used for measurement up to 2m (in long distance mode).


This is a simple modification of the
[vl53l0x.ino](https://github.com/adafruit/Adafruit_VL53L0X/blob/master/examples/vl53l0x/vl53l0x.ino)
example from the
[Adafruit_VL53L0X](https://github.com/adafruit/Adafruit_VL53L0X) library.

It adds a tone output at a frequency that is inversely proportional to the distance.

In VL53L0X default mode, this results in a frequency range of about 1000Hz (about half a meter away) to 1480Hz (close in).
The actual range can be adjusted by changing the calculation that converts distance into frequency.


## Construction

![Breadboard](./assets/TheToneRanger_bb.jpg?raw=true)

![Schematic](./assets/TheToneRanger_schematic.jpg?raw=true)


I've actually used a [Maker UNO](../../MakerUno) board for this demo, as it has the
piezo buzzer built-in:

![TheToneRanger_module](./assets/TheToneRanger_module.jpg?raw=true)


![Build](./assets/TheToneRanger_build.jpg?raw=true)

## Credits and References

* [VL53L0X Product Info](https://www.st.com/en/imaging-and-photonics-solutions/vl53l0x.html)
* [VL53L0X Datasheet](https://www.st.com/resource/en/datasheet/vl53l0x.pdf)
* [Adafruit_VL53L0X](https://github.com/adafruit/Adafruit_VL53L0X) library
* [Adafruit VL53L0X module and information page](https://learn.adafruit.com/adafruit-vl53l0x-micro-lidar-distance-sensor-breakout/downloads)
* [Using VL53L0X Laser Distance meter in Arduino](http://robojax.com/learn/arduino/?vid=robojax-VL53L0X) - Robojax
