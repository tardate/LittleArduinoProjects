# #379 AS3935

Using the AMS AS3935 Franklin Lightning Sensor with an Arduino over I²C with the Wire library.

![Build](./assets/AS3935_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I first heard about the AMS AS3935 Franklin Lightning Sensor in
[Arduino for Ham Radio](https://www.goodreads.com/book/show/23432504-arduino-for-ham-radio).
They are available as modules with built-in tuned antenna, but are relatively expensive/rare. I finally got my hands on one to experiment with.

The AS3935 detects the presence and approach of potentially hazardous lightning activity in the vicinity and provides an estimation on the distance to the head of the storm.
The embedded hard-wired distance estimation algorithm of the AS3935 issues an interrupt on the IRQ pin every time lightning is detected.

As a first step, I'm figuring out how to best use it with an [Arduino with a 5110 LCD display](../Lcd5110/DIYShield) for output.

Since [Singapore is one of the lightning capitals of the world](https://mothership.sg/2016/05/singapore-is-the-lightning-capital-of-the-world/),
I should be able to get some good use out of this!
There are between 171 and 186 lightning days on average a year, and each square kilometer of land in Singapore can be struck up to 16 times annually.

So far so good ... the module appears to work quite well, and I'm having no trouble programming it with the standard Wire library.

Next steps, and two more projects for my list...

* package this up as a complete project. Perhaps with external data logging, and maybe GPS for location and time reference.
* I wonder what it would take to construct a lightning detector from first principles?


## Module Features

I found a "CJMCU" version of the module, which conveniently exposes most of the AS3935 pins.

From the vendor description: Based on the AMS reference design, this is the AS3935 digital sensor breakout board. This innovative sensor features a specially tuned antenna, SPI or I²C interface, and a standard operating range of 2.4V to 5.5V, designed to interface with most current development systems and boards. The splitter uses an inductor (antenna) designed specifically for this application, and the board is fully calibrated. Features:

* Detects cloud-to-cloud and cloud-to-cloud flashes
* The estimated strike is between 14 and 40 kilometers
* Embedded "artificial" interference suppression algorithm
* Thunder and detection threshold is programmable (such as outdoor to indoor)
* Wide supply voltage range: 2.4V - 5.5V
* SPI and I²C operations are supported by default, I²C Address 0x03


## Module Pins

| Module Pin | Description                                                   |
|------------|---------------------------------------------------------------|
| VCC/VDD    | Positive supply voltage                                       |
| GND        | Ground                                                        |
| SCL        | I²C clock bus or SPI clock bus (according to SI setting)      |
| MOSI       | I²C data bus or SPI data input bus (according to SI setting)  |
| MISO       | SPI data output bus                                           |
| CS         | Chip Select (active low)                                      |
| SI         | Select Interface (GND → SPI or VDD → I²C)                     |
| IRQ        | Interrupt (out)                                               |
| EN_V       | Voltage Regulator Enable                                      |
| A0         | I²C address selection LSB                                     |
| A1         | I²C address selection MSB                                     |


Some pictures of the module prior to assembly:

![AS3935_module_front](./assets/AS3935_module_front.jpg?raw=true)

![AS3935_module_rear](./assets/AS3935_module_rear.jpg?raw=true)

## AS3935 Programming Interface

The AS3935 supports both SPI and I²C interfaces. A number of libraries/examples exist in the wild:

* [AS3935_Wire](https://github.com/THP-JOE/AS3935_Wire) - THP-JOE
    - uses the standard Wire library
* [AS3935 lightning sensor library](https://github.com/stevemarple/AS3935) - stevemarple
    - published in [arduinolibraries](https://www.arduinolibraries.info/libraries/as3935)
    - uses SoftWire library for I²C
* [AS3935-Arduino-Library](https://github.com/raivisr/AS3935-Arduino-Library) - raivisr
    - SPI only
* [Arduino for Ham Radio - Chapter 23 Lightning Detector](http://www.w5obm.us/Arduino/Arduino%20for%20Ham%20Radio%20Book/23%20Lightning%20Detector/)
    - uses a modified version of AS3935-Arduino-Library: adds I²C support with the I2C library

For this test, I'm not using any of the AS3935-specific libraries. I wanted to see first how far I could get with the standard
Wire library.


### I²C Specifics

Addressing: the module exposes two address pins.
By default these are not connected (address "0" which is invalid according to I²C specs ... but still appears to work).
Here I pull both high for an address of 3.


## Internal Voltage Regulator

The internal voltage regulator can be enabled by connecting EN_VREG to VDD.

| voltage regulator | VDD         |
|-------------------|-------------|
| ON                | 2/4 - 5.5 V |
| OFF               | 2/4 - 3.6 V |


## Register Map

There are 11 8-bit registers available for read/write, summarised here:

![AS3935_register_map](./assets/AS3935_register_map.png?raw=true)

## Interpreting Lightening Strike Data

When IRQ signal goes high, interrupt type is available to read from register 0x03 (after 2ms).

| Interrupt Name | Value | Description          |
|----------------|-------|----------------------|
| INT_NH         |  0001 | Noise level too high |
| INT_D          |  0100 | Disturber detected   |
| INT_L          |  1000 | Lightning            |

The estimated distance is directly represented in km in register 0x07 (binary encoded).
Full scale value of 111111b (63 decimal) indicates "out of range".

The result of the energy calculation is stored in registers 0x05, 0x06 and 0x07.
The value is just a pure number and has no physical meaning.


## Example Code

The [AS3935.ino](./AS3935.ino) sketch and supporting classes demonstrate the basic operation
of the AS3935 module without using any special libraries.

Basic operation:

* register details displayed on the LCD at startup
* lightning strikes displayed on the LCD
* full register details dumped to Serial debug on startup and all interrupts

It uses the default AS3935 indoor configuration:

| Register   | Default  | Note                                            |
|------------|----------|-------------------------------------------------|
| AFE_GB:    |  10010   | Indoor                                          |
| PWD:       |      0   |                                                 |
| NF_LEV:    |    010   | 62 μVrms  Continuous Input Noise Level (Indoor) |
| WDTH:      |   0010   |                                                 |
| MIN_LIGH:  |     00   |                                                 |
| SREJ:      |   0010   |                                                 |
| LCO_FDIV:  |     00   |                                                 |
| MASK_DIST: |      0   |                                                 |
| DISP_LCO:  |      0   |                                                 |
| DISP_SRCO: |      0   |                                                 |
| DISP_TRCO: |      0   |                                                 |
| TUN_CAP:   |   0000   |                                                 |



### Libraries

* [Arduino Wire](https://www.arduino.cc/en/Reference/Wire) - for AS3935 interface
* [Arduino SPI](https://www.arduino.cc/en/Reference/SPI) - for controlling the display
* [Adafruit-PCD8544 Library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library) - display driver


## Construction and Testing

There's a little lightning in the distance right now, so let's see how it runs.

Wired up with an LCD shield and the AS3935 on a breadboard:

![AS3935_breadboard](./assets/AS3935_breadboard.jpg?raw=true)


![Breadboard](./assets/AS3935_bb.jpg?raw=true)

![Schematic](./assets/AS3935_schematic.jpg?raw=true)


Serial debugging appears on the console:

![trial_1_console](./assets/trial_1_console.png?raw=true)

Yes, it does get quite a bit hairy here, but I need to wait for another storm to capture some accurate measurements
and compare to the data available from Singapore's [Lightning Alert Information System](http://www.weather.gov.sg/lightning/lightning/lightningalertinformationsystem.jsp).

![lightning-sg-2](./assets/lightning-sg-2.png?raw=true)


### Capturing a Storm

Didn't have to wait too long - today's afternoon rain came with significant lightning activity

![2018-04-14_lightning-sg](./assets/2018-04-14_lightning-sg.png?raw=true)

The AS3935 provided a steady stream of reports that corresponded nicely with the official record.
I do note however that the range is quite limited - it appears I'm only detecting strikes within ~15km.
This is using the indoor mode and default tuning.

![2018-04-14_console](./assets/2018-04-14_console.png?raw=true)


## Credits and References
* [LEAP#377 Nokia 5110 Shield](../Lcd5110/DIYShield)
* [AS3935 Digital Sensor Breakout Board Module SPI I²C Interface Strikes Thunder Rainstorm Storm Distance Detection 2.4V to 5.5V](https://www.aliexpress.com/item/AS3935-Digital-Sensor-Breakout-Board-Module-SPI-I²C-Interface-Strikes-Thunder-Rainstorm-Storm-Distance-Detection-2/32841367748.html)
* [AMS AS3935 Franklin Lightning Sensor](http://ams.com/eng/Products/Wireless-Connectivity/Wireless-Sensor-Connectivity/AS3935) - product page
* [Arduino for Ham Radio](https://www.goodreads.com/book/show/23432504-arduino-for-ham-radio) - Chapter 23: Lightening Detector
* [Arduino for Ham Radio](http://www.w5obm.us/arduino/) - project files
* [Lightning Alert Information System](http://www.weather.gov.sg/lightning/lightning/lightningalertinformationsystem.jsp) - Meteorological Service Singapore
* [..as mentioned on my blog](https://blog.tardate.com/2018/04/leap379-as3935-lightning-sensor.html)
