# #204 TemperatureLoggerTypeK

Simple high-temperature monitor using Type K (differential) and LM35 (cold-junction) sensors.

![The Build](./assets/TemperatureLoggerTypeK_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This is an experiment in reading high temperatures on an Arduino - above those typically supported with semiconductor sensors
or thermistors.

Here I'm using a K Type thermocouple that's rated up to 700°C.
Since thermocouples only measure a differential temperature, I'm using an LM35 to provide the cold-junction baseline.
The temperature measurement is displayed on a 5110 LCD.


### High Temperature Thermocouple Type K Probe

[The Type K probes I have are from an aliexpress seller](http://www.aliexpress.com/store/product/5PCS-2M-K-Type-Temperature-Thermocouple-Sensor-Probe-From-50C-to-700C/109396_32633620107.html) with the following specifications:

* Operating Temperature: -50-700°C
* Probe Diameter: 0.66mm /0.026 inch
* Probe Length: 8.15mm /0.321 inch
* Cable Length: 2m
* Cable Internal Insulation: Fiberglass
* Connector: K Type Mini-Connector


### Thermocouples and the Seebeck Voltage

A thermocouple loop is made from two dissimilar metals.
When subjected to a temperature differential, the metals have different affinity for electrons.
This develops an open-circuit voltage (Seebeck voltage) that is proportional to the difference in temperature.

Various types of thermocouples are differentiated by their materials and their Seebeck voltages.
Votlages vary as a function of temperature and are not linear. Three techniques are possible for converting the thermocouple
voltage to a temperature differential:

* use the standard tables available for each type of thermocouple
* use the characteristic polynomial equation that may be available
* use a linear approxmation. This is common when using Type K, since the Seebeck voltage is roughly linear above room temperature

Since thermocouples only measure the temperature differential, it is necessary to independently establish the baseline
aka the "Cold Reference Junction".


### Measuring the Type K Thermocouple Temperature

The Thermocouple voltage difference is amplified with an LM358 in non-inverting amplifier configuration.
It is configured for significant gain in order to get the µV reading into the 0-5V scale readable with an Arduino analog input.

The second op amp in the LM358 is used to buffer the reading - really unnecessary in this configuration as the
Arduino analog input presents a fairly high impedence load.

A 100nF capacitor is used to filter high-frequency jitter from the signal.

While this works pretty well, there are limitations:

* since the LM358 is not rail-to-rail, we're not able to use the full resolution of the Arduino ADC
* the gain and zero-point of the amplifier need to be selected with the temperature reading range in mind. For example, higher resolution but limit to say 200°C, or lower resolution but able to reach higher temperatures.

Since I'm interested in temperatures above room temperature and into the 300-700°C range.
I'm using the 41µV/°C Type K linear approximation.

For the configuration demonstrated here, I'm using R1=1kΩ and R2=330kΩ in the amplifier configuration
for a gain of 331:

    Vout = (1 + R2/R1) * Vin
    gain = 1 + 330/1

Since the upper output limit of the LM358 is V+ - 1.5V per the datasheet, in this case 3.5V, then the maximum Vin before clipping is:
[3.5V/331 = 10.6mV](http://www.wolframalpha.com/input/?i=3.5V%2F331)

This represents a temperature range of [10.6mV/41µV/°C = 258.5°C](http://www.wolframalpha.com/input/?i=10.6mV%2F41%C2%B5V%2F%C2%B0C).
That's far below the limits of the probe, but enough for a test.

To measure higher ranges, the gain can be increased accordingly and perhaps use a rail-to-rail op amp.

### Cold Reference Junction

Three basic techniques for measuring the temperature of the reference junction:

1. Use a thermistor or semiconductor temperature sensor
2. Hold the reference junction at a fixed and known temperature e.g. ice bath
3. Use a cold junction compensation IC such as the Analog Devices AD594 or Linear Technology LT1025


### Measuring the Cold Reference Junction Temperature

This circuit uses an LM35 Precision Centigrade Temperature Sensor to measure the cold-junction reference temperature.

The LM35 is incredibly easy to use, especially for working in centigrade.
It provides a linear 10.0 mV/degree output for an operating range of -55°C to 150°C.
So for example, 250mV is 25°C.

The LM35 output is read with an analog input which has an analog to digital resolution of only 1024 levels (0-1023).
So with the default 5V reference voltage that means [4.88mV](http://www.wolframalpha.com/input/?i=5000%2F1024)
per step. The LM35 therefore only has a resolution of 0.5°C.

That's OK here when compared to the resolution from the Type K reading.

See [LedTemperatureDisplay](../LedTemperatureDisplay) for more on using the LM35.


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


### Next Steps/Improvements

So far so good, but I'd like to take this further as a I have a high-temperature measurement application in mind.

Firstly, I like a more flexible way to measure across the full temperature range supported by the Type K Probes with
good resolution:

* perhaps buffer the thermocouple voltage into a number of amplifiers setup with different gain products
* the microcontroller could auto-range across 3 or 4 amplifiers
* perhaps switch to 1.1V internal ADC reference to avoid needing to pulling the op amps near the upper or lower rail limits

Secondly, this needs mounting properly. In particular to provide a good isothermal terminal block
for the type K probe so a good cold reference junction measurement is possible.

Finally, it needs some calibration tests. It seems to be doing the right thing, but I haven't checked the accuracy of the readings I'm getting (how hot is a tea candle flame??)


## Construction

![Breadboard](./assets/TemperatureLoggerTypeK_bb.jpg?raw=true)

![The Schematic](./assets/TemperatureLoggerTypeK_schematic.jpg?raw=true)

![The Build](./assets/TemperatureLoggerTypeK_build.jpg?raw=true)

## Credits and References
* [LedTemperatureDisplay](../LedTemperatureDisplay) - project using LM35 to measure temperature
* [Thermocouple#Type_K](https://en.wikipedia.org/wiki/Thermocouple#Type_K) - wikipedia
* [EEVblog #419 - Thermocouple Tutorial](https://www.youtube.com/watch?v=AYblSfpKRUk)
* [The Basics of Thermocouples](http://circuitcellar.com/cc-blog/the-basics-of-thermocouples/) - concise summary
* [Build a Thermocouple Amplifier](http://www.bristolwatch.com/ele/thermalcouple_amplifier.htm)
* [Thermocouple - Lets use the Seebeck effect!](https://learn.adafruit.com/thermocouple/) - Adafruit tutorial that focuses on using the MAX6675 K-thermocouple interface chip
* [A thermocouple datalogger based on the Arduino platform](http://lukemiller.org/index.php/2010/08/a-thermocouple-datalogger-based-on-the-arduino-platform/) - very nice write-up of a complete project using AD595 amplifier/ADG407 multiplexer to interface with Type K thermocouples
* [Lessons In Electric Circuits - Op Amp Bias Current](https://www.ibiblio.org/kuphaldt/electricCircuits/Semi/SEMI_8.html#xtocid1097415)
* [Two Ways to Measure Temperature Using Thermocouples](http://www.analog.com/library/analogDialogue/archives/44-10/thermocouple.pdf) - compares AD8495 amplifier and reference junction compensation techniques
* [5PCS 2M K Type Temperature Thermocouple Sensor Probe From -50C to 700C](http://www.aliexpress.com/store/product/5PCS-2M-K-Type-Temperature-Thermocouple-Sensor-Probe-From-50C-to-700C/109396_32633620107.html) - from aliexpress seller
* [..as mentioned on my blog](https://blog.tardate.com/2016/06/littlearduinoprojects204-type-k.html)