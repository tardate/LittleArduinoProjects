# #218 MPU6050/AccelGyroTest

First test of an Invensense MPU-6050 3-Axes Accelerometer Gyroscope Module.

![AccelGyroTest_module](./assets/AccelGyroTest_module.jpg?raw=true)



[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

### Module Specs

I have this [mpu-6050 module](http://www.aliexpress.com/item/3-Axes-Accelerometer-Gyroscope-Module-For-MPU-6050-Top-Sale/32579065183.html)  from an aliexpress seller. It is [similar to this module from sparkfun](https://www.sparkfun.com/products/11028).

It is based on the Invensense MPU-6050, but packaged in a module that operates on 3-5V.
These are the specs according to the seller:

* 3-Axes Accelerometer Gyroscope Module For Arduino MPU 6050
* Use chip: MPU-6050
* The power supply: 3-5 v (internal low voltage difference voltage stabilizing)
* Communication: standard IIC communication agreement
* Chip built-in 16 bit AD converter, 16 bits of data output
* The gyroscope range: + 250 500 1000 2000 ° /s
* Acceleration range: ± 2 ± 4 ± 8 ± 16 g
* Pin Pitch 2.54 mm
* Size: approx. 20*15*1.2 mm(max)

### Pin Connections

| Pin | Function                       | Arduino Pin Connection |
|-----|--------------------------------|-------------|
| Vcc | 3-5V                           | 5V          |
| Gnd | Ground                         | GND         |
| SCL | I²C clock                      | A5          |
| SDA | I²C data                       | A4          |
| XDA | I²C data for external compass  | n/a         |
| XCL | I²C clock for external compass | n/a         |
| AD0 | selects I²C address 0x68 (low) and 0x69 (high) | n/a         |
| INT | Interrupt out                  | optional    |


### Basic Example

The [AccelGyroTest.ino](./AccelGyroTest.ino) sketch is a basic demonstration of reading raw values from the MPU-6050
using the Arduino Wire library. It is based on a sample from the [Arduino playground MPU-6050 page](http://playground.arduino.cc/Main/MPU-6050).

It sends the readings out the serial connection:

![AccelGyroTest_demo](./assets/AccelGyroTest_demo.png?raw=true)


## Construction

![Breadboard](./assets/AccelGyroTest_bb.jpg?raw=true)

![The Schematic](./assets/AccelGyroTest_schematic.jpg?raw=true)

![The Build](./assets/AccelGyroTest_build.jpg?raw=true)

## Credits and References
* [MPU-6050 module](http://www.aliexpress.com/item/3-Axes-Accelerometer-Gyroscope-Module-For-MPU-6050-Top-Sale/32579065183.html) - from aliexpress seller
* [similar module from sparkfun](https://www.sparkfun.com/products/11028)
* [MPU-6050](https://www.invensense.com/products/motion-tracking/6-axis/mpu-6050/) - Invensense product page
* [MPU-6050 datasheet](https://www.cdiweb.com/datasheets/invensense/MPU-6050_DataSheet_V3%204.pdf)
* [Arduino playground MPU-6050 page](http://playground.arduino.cc/Main/MPU-6050)
* [Arduino Wire Library](https://www.arduino.cc/en/Reference/Wire)
* [I²C](https://en.wikipedia.org/wiki/I%C2%B2C) - wikipedia
* [Gy521-Dev-Kit](https://github.com/janaka/Gy521-Dev-Kit) - tools and examples for Gy521-compatible modules
* [i2cdevlib](https://github.com/jrowberg/i2cdevlib) - general I²C library, supports MPU-6050
* [..as mentioned on my blog](https://blog.tardate.com/2016/07/littlearduinoprojects218-mpu-6050-3.html)
