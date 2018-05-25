# #372 MilliVoltmeterDIY

An ATmega328-based millivolt meter based on a design by Scullcom Hobby Electronics. Uses an LTC2400 ADC and LT1019 voltage reference.

See [CustomBoardAndEnclosure](./CustomBoardAndEnclosure) for details of the custom PCB and enclosure I made for the project.

![Build](./assets/MilliVoltmeterDIY_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This project is based on the excellent build tutorial by Scullcom Hobby Electronics #44 - Millivolt Meter MK2

[![clip](http://img.youtube.com/vi/CiTPUmqE3Yg/0.jpg)](https://www.youtube.com/watch?v=CiTPUmqE3Yg)

A few changes I've made:

* LT1019 2.5V voltage reference instead of the ADR4540BRZ
* direct LCD control instead of I2C (because it is what I had available)
* some of the buttons moved to analog pins (digital mode) since the LCD uses a few too many pins
* adjust the controls to a three-button command set.
* discarded the op-amp buffer, as I found it skewed the reading at the top and bottom of the range
* altered the calibration method, so the only fixed value in the code is the reference voltage.


### Button Functions

I used normally-open pushbuttons on the breadboard, but for the final build I have some normally-closed pushbuttons.
The `#define BUTTON_LOGIC_ACTIVE_STATE` is used to select between HIGH or LOW button logic.
Internal pull-ups are enabled so there are no additional external components required other than the push-buttons themselves.

All the necessary functions are implemented with a three-button command set:

* button 1: calibrate
* button 2: change the number of digits (precision)
* button 3: change the second-line function between 3 modes:
    - bar graph
    - hold value
    - raw ADC output


### Buffering the Input Voltage

The input signal is tapped from a voltage-divider to provide around 10x attenuation, and therefore support a wider voltage range.

The values used in the voltage-divider are not critical. They just need to be in a suitable proportion to
scale back the intended input voltage range to a maximum limit of the reference voltage,
and large enough to provide a high-impedence input to the voltage under test.

In my design, I'm using 100kΩ and 1MΩ which support a full-range of around [27.5V](https://www.wolframalpha.com/input/?i=(100k%CE%A9+%2B+1000k%CE%A9)%2F100k%CE%A9*2.5V)

Ideally the reading should be buffered to further reduce coupling with the circuit-under-test, as in the original Scullcom project.
I tested buffering with an LMC6482 op-amp, but although it is "rail-to-rail" I found it performed quite poorly at the top and bottom of the range
e.g. 0V input still producted a 40mV output on the buffer. I decided to discard the buffer, and just rely on a stiff voltage divider.
Note that the Scullcom project used a AD8628ARZ, so perhaps that performs better as a buffer (I will have to get some to try).

I also planned to add a 1N4733 5.1V zener diode to provide some over-voltage input protection (across the lower half of the voltage-divider).
However the leakage current introduced a minor non-linearity in the readings. So again, I discarded this idea in favour of the most accurate reading possible.

### Using the LTC2400

10kΩ pull-ups are added on the CS and SCK pins to ensure the chip does not go into internal oscillator mode on startup.

The LTC2400 provides a 24-bit measurement with respect to the reference voltage (Vref = x00FFFFFF).
This ias received in a 32-bit serial stream:

* 4 high bits provide status
* 4 low bits are "sub LSB" and can be discarded without affecting accuracy
* the 24 bits in between are the actual reading

The status bits help decode the reading correctly:
* SIG indicates if reading is positive or negative
* EXR indicates if the reading exceeds the reference range (above or below)


### Voltage Reference and Calibration

I'm using an LT1019 2.5V reference (because it is what I had available).
This means that the LTC2400 ADC output is all calculated with respect to the 2.5V standard.

I have adapted the code so that the unit performs an automatic calibration with respect to the reference voltage.
The only hardcoded value is the reference voltage. How this works:

* the reference voltage is exposed on a "calibration" test point
* the +ve input is connected to the "calibration" test point
* press the "calibration" botton
* the calibration adjustment factor is calculated to ensure an accurate reading of the reference voltage
* the calibration adjustment factor is also stored in EEPROM as the default on startup

As a result - as long as the reference voltage is accurate(!) - this approach is agnostic with regards to any
input attenutation set in the input voltage divider.


## Code

[MilliVoltmeterDIY.ino](./MilliVoltmeterDIY.ino) is my version of the code, based on the original
[Millivolt_Meter_MK2_ver33.ino](http://www.scullcom.com/Millivolt_Meter_MK2_ver33.ino).

Libraries used:

* [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal)
* [EEPROM](https://www.arduino.cc/en/Reference/EEPROM)
* [SPI](https://www.arduino.cc/en/Reference/SPI)


## Breadboard Construction

I initially built this on a breadboard and controlled with an Arduino Uno to verify and refine the circuit.

![Breadboard](./assets/MilliVoltmeterDIY_bb.jpg?raw=true)

![Schematic](./assets/MilliVoltmeterDIY_schematic.jpg?raw=true)

![Build](./assets/MilliVoltmeterDIY_build.jpg?raw=true)


## Credits and References
* [Scullcom Hobby Electronics #44 - Millivolt Meter MK2](https://www.youtube.com/watch?v=CiTPUmqE3Yg) - YouTube
* [Millivolt Meter MK2](http://www.scullcom.uk/millivolt-meter-mk2/) - more info on on www.scullcom.uk
* [Millivolt_Meter_MK2_ver33.ino](http://www.scullcom.com/Millivolt_Meter_MK2_ver33.ino) - original source
* [LTC2400 info and datasheet](http://www.linear.com/product/LTC2400)
* [LT1019 info and datasheet](http://www.linear.com/product/LT1019)
