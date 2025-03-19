# #295 Frequency Counter Kit

Build and test a common PIC-based frequency counter kit.

![Build](./assets/FrequencyCounterKit_build.jpg?raw=true)

## Notes

I picked up a kit [similar to this one](https://www.aliexpress.com/item/CNIM-Hot-50-MHz-Crystal-Oscillator-Frequency-counter-Testers-DIY-Kit-5-Resolution-Digital-Red/32772551581.html) after watching [Julian Ilett's videos on the kit build](https://www.youtube.com/watch?v=Nhb0MjQBvNo).

Not that I really need another frequency counter, but it is interesting to see how this one is constructed.

Julian's investigation of the circuit was thorough, including the discovery that the kits available are derivative
from original work by Wolfgang "Wolf" Büscher, DL4YHF, in his [Frequency counter with a PIC and minimum hardware](http://www.qsl.net/dl4yhf/freq_counter/freq_counter.html).

### Specifications

From seller product information pages:

* Color: Red, Simple Construction , compact design, easy to install and debug. Designed to measure the frequency of oscillation of most crystal oscillators. Based on PIC microcontroller can measure the frequency of 1 Hz to 50 MHz. Five digits of precision, for example kHz x.xxxx, MHz or xx.xxx x.xxxx MHz. General for feeding USB interface can be used for power supply, AC adapter or a battery of 9 V can be used too, it is used. Color: Red, Simple Construction , compact design, easy to install and debug.
* Designed to measure the frequency of oscillation of most crystal oscillators.
* Based on PIC microcontroller can measure the frequency of 1 Hz to 50 MHz.
* Five digits of precision, for example kHz x.xxxx, MHz or xx.xxx x.xxxx MHz.
* General for feeding USB interface can be used for power supply, AC adapter or a battery of 9 V can be used too, it is used.
* Optional mode of power saving: can automatically convert the display if the frequency does not change significantly in 15 seconds
* Very small number of components: a PIC16F628, 5, 7-segment LED screens, a 20 MHz crystal and some resistors
* Frequency range: 1 Hz-50 MHz
* Glass Test Range: 4 KHz-48 KHz
* Built Item Size: 8 *5.5* 0.7 cm / 3.2 *2.2* 0.3 inches

### Parts

| Ref    | Item                                 | Qty   |
|--------|--------------------------------------|-------|
| IC1    | PIC16F628                            | 1     |
| IC2    | 7550A-1 5V regulator                 | 1     |
| LED1-5 | 5161AS 7-segment LED, common-cathode | 5     |
| D1-4   | 1N4148 diode                         | 4     |
| XTAL1  | 20MHz crystal                        | 1     |
| C1,3,4 | 22pF capacitor                       | 3     |
| C2     | 10-40pF variable capacitor           | 1     |
| C5     | 102 1nF capacitor                    | 1     |
| C6     | 104 100nF capacitor                  | 1     |
| Q1     | S9014 NPN transistor                 | 1     |
| Q2     | S9018 transistor                     | 1     |
| R1,2   | 10kΩ resistor                        | 2     |
| R3-11  | 1kΩ resistor                         | 9     |
| R12    | 100kΩ resistor                       | 1     |
| J3     | barrel jack                          | 1     |
| J1,2   | 3-pin headers                        | 2     |
| S1     | pushbutton switch                    | 1     |
|        | DIP socket                           | 1     |
|        | PCB                                  | 1     |

![kit-parts](./assets/kit-parts.jpg?raw=true)

The PCB is a nice 2-layer layout:

![kit-pcb-front](./assets/kit-pcb-front.jpg?raw=true)

![kit-pcb-rear](./assets/kit-pcb-rear.jpg?raw=true)

## Construction

The circuit in this kit is based on
[Construction - Variant 2](http://www.qsl.net/dl4yhf/freq_counter/freq_counter.html#construction_v2) by Wolfgang "Wolf" Büscher, DL4YHF.
Modifications:

* addition of the crystal tester circuit
* variable capacitor on one leg of the crystal
* 5V regulator on the power supply

Here is my redrawing of the schematic used in the actual kit:

![Schematic](./assets/FrequencyCounterKit_schematic.jpg?raw=true)

![Build](./assets/FrequencyCounterKit_build.jpg?raw=true)

![FrequencyCounterKit_build_rear](./assets/FrequencyCounterKit_build_rear.jpg?raw=true)

## Performance

Julian and others have reported issues with the frequency counter (temperature effects; failure to register).
However in my tests I didn't see any of these problems. I tested crystals from 4MHz to 16MHz and got quite accurate results
in all cases. Here's an example of a 7MHz crystal under test:

![test-crystal-7mhz](./assets/test-crystal-7mhz.jpg?raw=true)

With a function generator, I also got accurate readings from 1kHz to 24MHz (the upper limit of the function generator).
The input signal is a 0V to 5V square wave:

![test-fgen-1khz](./assets/test-fgen-1khz.jpg?raw=true)

![test-fgen-24mhz](./assets/test-fgen-24mhz.jpg?raw=true)

## Configuration

The press-button is used to access a control menu for the device. To get good results, I had to make two changes:

* "Zero" - resets the frequency offset. When I first tried the device, it had a 5MHz offset which needed clearing.
* "PSave" - enables/disables power save feature. When I first tried the device, power save was enabled, which causes the device to keep turning off (may be misleading and make you think it is not working).

## Input Connections

Input connections are not fully documented. Here's how they seem to work.
The connector and pin identifications refer to the schematic:

| Connector | Pin | Purpose                                       |
|-----------|-----|-----------------------------------------------|
| J1        | 1   |  crystal leg 1; ground                        |
| J1        | 2   |  no connection                                |
| J1        | 3   |  crystal leg 2                                |
| J2        | 1   |  frequency input; direct connect to PIC pin 3 |
| J2        | 2   |  VIN / bypass power                           |
| J2        | 3   |  ground / bypass power                        |
| J3        | 1   |  VIN / power jack                             |
| J3        | 3   |  ground / power jack                          |
| J3        | 4   |  ground / bypass power                        |

J2 and J3 and configured to allow by-pass power supply. J3 is the barrel jack - when power is plugged in here,
it by-passes any power supply connected on J2. For my tests, I just had power connected on J2.

## Next Steps and Improvements

One of the issues with the counter is that it requires an input signal that registers across 0-5V as it is fed as a direct input
to the PIC. This can be problematic:

* no over-voltage protection
* unable to read small signals
* AC-coupled signals may not have sufficient high-side amplitude

The [preamplifier](http://www.qsl.net/dl4yhf/freq_counter/freq_counter.html#preamp) described by DL4YHF looks like an interesting
addition.

So perhaps next things I'll do with this kit:

* add a pre-amplified stage, perhaps with over-voltage protection
* mount in a case with a BNC connector for input frequency
* add a switch and battery connected on J2 (so can be mounted with a battery in a case, with external power bypass on J3)

## Credits and References

* [Frequency counter with a PIC and minimum hardware](http://www.qsl.net/dl4yhf/freq_counter/freq_counter.html) - original circuit design and description by Wolfgang "Wolf" Büscher, DL4YHF
* [50 MHz Crystal Oscillator Frequency counter Testers DIY Kit](https://www.aliexpress.com/item/CNIM-Hot-50-MHz-Crystal-Oscillator-Frequency-counter-Testers-DIY-Kit-5-Resolution-Digital-Red/32772551581.html) - similar product from an aliexpress seller
* [Fairly Easy - Frequency Counter - Electronic Kit Build (part 1)](https://www.youtube.com/watch?v=Nhb0MjQBvNo)
* [Fairly Easy - Frequency Counter - Electronic Kit Build (part 2)](https://www.youtube.com/watch?v=z7Fv9QqiqZ0)
* [Fairly Easy - Frequency Counter - Electronic Kit Build (part 3)](https://www.youtube.com/watch?v=q31unvowJe4)
* [PIC16F628 datasheet](https://parts.io/detail/1375756/PIC16F628A-I%2FSS)
* [SC56-11 Datasheet](./assets/SC56-11_datasheet.pdf?raw=true) - similar LED 7-segment display
* [S9014 datasheet](https://www.futurlec.com/Transistors/S9014.shtml)
* [S9018 datasheet](http://parts.io/detail/178104407/S9018) - parts.io
* [HT7550A-1 datasheet](http://www.e-ele.net/DataSheet/HT75XX-1.pdf)
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap295-frequency-counter-kit.html)
