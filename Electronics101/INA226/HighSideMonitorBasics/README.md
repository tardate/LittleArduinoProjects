# #504 INA226 High-side Monitor Basics

How to design for the INA226 current and power monitor and test with an Arduino and various libraries including raw wire I²C.

![Build](./assets/HighSideMonitorBasics_build.jpg?raw=true)

## Notes

I heard about the [INA226](http://www.ti.com/product/INA226) on the (sadly now defunct) [SparkGap Podcast#33](https://web.archive.org/web/20160806070203/http://thesparkgap.net/post/119477320543/the-spark-gap-podcast-episode-33).

The INA226 is a "36V, Bi-Directional, High Accuracy, Low-/High-Side, I²C Out Current/Power Monitor w/Alert".
It can monitor current accross a shunt resistor and also bus voltage, allowing it to also calculate power consumption.
It is a successor to the [INA219](http://www.ti.com/product/INA219), which is quie widely used in the microcontroller community.

It comes in a tiny VSSOP package with 0.5mm pitch pins. I put one on a DIP adapter for testing:

![ina226_insitu](./assets/ina226_insitu.jpg?raw=true)

### About the INA226

The INA226 operates only as an I²C or SMBus slave device:

* supports fast mode (1 kHz to 400 kHz)
* supports high-speed mode (1 kHz to 2.94 MHz).
* All data bytes are transmitted most significant bit first.

#### Address

The A0 and A1 pins allow one of 16 addresses to be selected for the chip.
Pulling both to ground sets the default address of 0x40.

#### Registers

| Address | Default | Access | Name                     | Purpose |
|---------|---------|--------|--------------------------|---------|
| 00h     |  4127h  |    R/W | Configuration Register   | All-register reset, shunt voltage and bus voltage ADC conversion times and averaging, operating mode |
| 01h     |  0000h  |    R   | Shunt Voltage Register   | Shunt voltage measurement data |
| 02h     |  0000h  |    R   | Bus Voltage Register     | Bus voltage measurement data |
| 03h     |  0000h  |    R   | Power Register           | Contains the value of the calculated power being delivered to the load |
| 04h     |  0000h  |    R   | Current Register         | Contains the value of the calculated current flowing through the shunt resistor |
| 05h     |  0000h  |    R/W | Calibration Register     | Sets full-scale range and LSB of current and power measurements. Overall system calibration |
| 06h     |  0000h  |    R/W | Mask/Enable Register     | Alert configuration and Conversion Ready flag |
| 07h     |  0000h  |    R/W | Alert Limit Register     | limit value to compare to the selected Alert function |
| FEh     |  5449h  |    R   | Manufacturer ID Register | unique manufacturer identification number |
| FFh     |  2260h  |    R   | Die ID Register          | unique die identification number |

#### Configuration

The Configuration Register is used to set operating modes:

| Bit  | Name   | Function |
|------|--------|----------|
| 15   | Reset  | Setting this bit to '1' generates a system reset
| 9-11 | AVG    | Sets averaging mode. Default = 0h (average over 1 sample. i.e. no averaging!) |
| 6-8  | VBUSCT | Bus Voltage Conversion Time. Default 1.1ms |
| 3-5  | VSHCT  | Shunt Voltage Conversion Time. Default 1.1ms |
| 0-2  | MODE   | Operating mode. Default: Shunt and Bus, Continuous |

#### Calibration

The Calibration Register is critical for accurate current and power measurements.
It is explained (not very clearly!) in 7.5/7.5.1 of the data sheet.

It essentially outlines a procedure for calculating the calibration factor
that will be used within the chip to perform current and power calculations.
The calibration factor is a function of two variables:

* Current_LSB - scaled by the user to ensure appropriate current resolution for the application
* Rshunt - the shunt resistance

![calibration](./assets/calibration.png?raw=true)

The calibration factor can be calculated on paper and fixed in code,
but it seems that most libraries try to calculate the calibration factor for you.
Note that to caclulate the calibration factor successfully it is important to account for the scale and order of operations,
lest the calculation under/over-flow.

#### Reading Results

To read current:

* multiply the value in the Current Register by `current_LSB`

To read power:

* multiply the value in the Power Register by `25 * current_LSB`
* the power LSB has a fixed ratio to the Current_LSB of 25

To read bus voltage:

* read the Bus Voltage Register and multiple by 1.25 mV
* The Bus Voltage Register stores the most recent bus voltage reading, averaged if averaging is enabled
* Full-scale range = 40.96 V (0x7FFF); LSB = 1.25 mV

To read shunt voltage:

* read the Shunt Voltage Register and multiple by 2.5 μV
* Negative numbers are represented in two's complement format
* Full-scale range = 81.92 mV (0x7FFF); LSB: 2.5 μV


### Designing for Low Power Test Load

For a breadboard test, I want to keep things under control so I'm designing for a peak of
9V @ 200mA load - [1.8W](https://www.wolframalpha.com/input/?i=200mA+*+9V).

The shunt resistance limit is dictated by the 81.92 mV full scale range of the shunt voltage register.
So for 200mA, that means a shunt resistor no larger than [0.4Ω](https://www.wolframalpha.com/input/?i=81.92mV%2F200mA).

Under these conditions, the 0.4Ω shunt resistor will only draw [16mW](https://www.wolframalpha.com/input/?i=%28200mA%29%5E2+*+0.4%CE%A9),
so 1/4W resistors are OK, however I've used a 0.22Ω 2W resistor as it is much more thermally stable and accurate than the cheap 1/4Ws I have on hand.

To keep the current within design limits, the minimum load resistance is [45Ω](https://www.wolframalpha.com/input/?i=9V%2F200mA).
I've chosen a 50Ω 5W resistor as fixed load, so actual current limit is [180mA](https://www.wolframalpha.com/input/?i=9V%2F50%CE%A9).
A 5W 10kΩ variable resistor is in series with the fixed load to allow the current to me adjusted all the way down to [about 0.9mA](https://www.wolframalpha.com/input/?i=9V%2F10050%CE%A9).

Here's the test circuit:

![Breadboard](./assets/HighSideMonitorBasics_bb.jpg?raw=true)

![Schematic](./assets/HighSideMonitorBasics_schematic.jpg?raw=true)

#### Manual Calibration Calculation

I'm going to do this in code, but a first pass by hand...

Given a maximum current of 200mA:

* current_LSB = [6.104µA](https://www.wolframalpha.com/input/?i=200mA%2F%282%5E15%29).

With a 0.22Ω resistor, this yields a calibration factor of:

* CAL = [3813](https://www.wolframalpha.com/input/?i=0.00512%2F%286.104%C2%B5A*0.22%CE%A9%29)

But maybe choose to calibrate for resolution of 8µA/bit (a nice binary number):

* CAL = [2909](https://www.wolframalpha.com/input/?i=0.00512%2F%288%C2%B5A*0.22%CE%A9%29)


### Code - Using the Wire Library

The [WithRawWire.ino](./WithRawWire/WithRawWire.ino) sketch is a simple monitor implentation that controlls the INA226
directly with the [Wire library](https://www.arduino.cc/en/reference/wire).

It demonstrates calibration and logging data to the console.

With the nominal shunt resistance it reports calibration in line with the hand calculations above:

    INA226 High-side Monitor
    Manufacturer ID : 5449
    Die ID          : 2260
    Calibrating for shunt resistance of 0.22Ω and maximum current of 0.200A
      * current_LSB : 0.006104mA
      * power_LSB   : 0.152593mW
      * CAL         : 3812

![build_calibration](./assets/build_calibration.jpg?raw=true)

Now because I am running this on a breadboard and allowing for component variations,
I don't expect the actual shunt resistance to be exactly 0.22Ω.
The first current measurements confirm there's a problem:

* INA226 reading: 6.055mA
* DMM measurement: 3.35mA

Using the ratio to calculate the actual shunt resistance: [0.398Ω](https://www.wolframalpha.com/input/?i=0.22%CE%A9+*+6.055mA%2F3.35mA).

With that value plugged into the sketch, the measurements from the INA226 are remarkably good, especially considering this is just a loosey-goosey breadboard build:

![console_calibrated](./assets/console_calibrated.png?raw=true)

Swinging the pot full scale, measurements are within a few mV of what I'm reading on my DMM:

![console_full_scale](./assets/console_full_scale.png?raw=true)

So far so good - using the INA226 with the Wire Library is pretty straight-forward.
Let's now try a couple of Arduino libraries I found...

### Using the Arduino-INA226 Library

The [WithIna226Lib.ino](./WithIna226Lib/WithIna226Lib.ino) sketch is a demonstration using the [Arduino-INA226](https://github.com/jarzebski/Arduino-INA226) library.

The Arduino-INA226 Library is a nice simple wrapper for the INA266 capabilities.
Easy to use, but seems we've lost precision on the current and power calculations.
The library does some extra rounding of the calibration factor that make it unable to handle sub-mA or mW values accurately.
Fine if you are working with multi-amp loads though:

![console_ina226](./assets/console_ina226.png?raw=true)

### Using the INA Library

The [WithInaLib.ino](./WithInaLib/WithInaLib.ino) sketch is a demonstration using the [INA](https://github.com/SV-Zanshin/INA) library.

The INA Library is an ambitious attempt to combine support for multiple INA2xx power monitor devices.

Work very well, although it expects the maximum current to start from 1A, so not ideal for low-current applications.

![console_ina](./assets/console_ina.png?raw=true)


## Credits and References

* [INA226 product info and datasheet](http://www.ti.com/product/INA226)
* [INA219 product info and datasheet](http://www.ti.com/product/INA219)
* [Wire library](https://www.arduino.cc/en/reference/wire)
* [Arduino-INA226](https://github.com/jarzebski/Arduino-INA226) - INA226 Bi-directional Current/Power Monitor Arduino Library
* [SV-Zanshin/INA](https://github.com/SV-Zanshin/INA) - Combined Arduino library for reading multiple INA2xx power monitor devices
* [SparkGap Podcast#33](https://web.archive.org/web/20160806070203/http://thesparkgap.net/post/119477320543/the-spark-gap-podcast-episode-33)
* [SMBus](https://en.wikipedia.org/wiki/System_Management_Bus)
