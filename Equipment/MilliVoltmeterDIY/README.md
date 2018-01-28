# #372 MilliVoltmeterDIY

An ATmega328-based millivolt meter based on a design by Scullcom Hobby Electronics. Uses an LTC2400 ADC and LT1019 voltage reference.

![Build](./assets/MilliVoltmeterDIY_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This project is based on the excellent build turorial by Scullcom Hobby Electronics #44 - Millivolt Meter MK2

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

## PCB and Enclosure Construction

Now that I have the breadboard prototype working just fine, I'm planning to put it in a case.
Originally I was thinking of just mounting the various modules on protoboard, but now I think I'll design a
PCB and put the project in an enclosure.

I'm going to drop an ATmega328P-AU TQFP on the board, rather than use an Arduino module. So let's get some pin mapping stright first:

| Arduino Pin | Connection                     | ATmega pin |
|-------------|--------------------------------|------------|
| D2          | DB7 serial LCD                 | 32, PD2    |
| D3          | DB6 serial LCD                 | 1, PD3     |
| D4          | DB5 serial LCD                 | 2, PD4     |
| D5          | DB4 serial LCD                 | 9, PD5     |
| D6          | E serial LCD enable            | 10, PD6    |
| D7          | RS serial LCD                  | 11, PD7    |
| D8          | BTN_2_FUNCTION function button | 12, PB0    |
| D9          | BTN_PRECISION precision button | 13, PB1    |
| D10         | CS - ADC SPI select            | 14, PB2    |
| D10         | MOSI - ICSP header             | 15, PB3    |
| D12         | MISO - ADC SPI SDA, ICSP       | 16, PB4    |
| D13         | SCK - ADC SPI clock, ICSP      | 17, PB5    |
| A0          | BTN_CAL calibration button     | 23, PC0    |
| A1          | VBATT_SENSE battery sensor     | 24, PC1    |
| A4          | SDA optional I2C screen        | 27, PC4    |
| A5          | SCL optional I2C screen        | 28, PC5    |
| RESET       | ICSP header                    | 29, PC6    |
|             | VCC                            | 4, 6       |
|             | GND                            | 3, 5, 21   |
|             | AVCC                           | 18         |
|             | XTAL                           | 7, PB6     |
|             | XTAL                           | 8, PB7     |

I decided to provision pin connections for either serial or I2C LCD displays.

After finding that KiCad didn't have footprints for half the components I wanted to use in the standard library,
I decided to try EasyEDA for PCB production:

* the component library is very complete (I didn't need to create any custom components)
* but the PCB designer is not quite as advanced as KiCad. Workable though.

The [EasyEDA project is available here](https://easyeda.com/tardate/MilliVoltmeterDIY-8553e43370c2483c926e832323425b5b),
and I've sent the board off to [OSHpark](https://oshpark.com/).
Note: I haven't built this board yet, so if you are looking at this, treat it as "unverified" for now.

TBA!

![MilliVoltmeterDIY_pcb_schematic](./assets/MilliVoltmeterDIY_pcb_schematic.png?raw=true)

![MilliVoltmeterDIY_pcb_render_front](./assets/MilliVoltmeterDIY_pcb_render_front.png?raw=true)

![MilliVoltmeterDIY_pcb_render_rear](./assets/MilliVoltmeterDIY_pcb_render_rear.png?raw=true)


## Credits and References
* [Scullcom Hobby Electronics #44 - Millivolt Meter MK2](https://www.youtube.com/watch?v=CiTPUmqE3Yg)
* [Millivolt_Meter_MK2_ver33.ino](http://www.scullcom.com/Millivolt_Meter_MK2_ver33.ino) - original source
* [LTC2400 info and datasheet](http://www.linear.com/product/LTC2400)
* [LT1019 info and datasheet](http://www.linear.com/product/LT1019)
