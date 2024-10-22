# #561 Aguhajsu 1S/3A BMS

Reviewing and testing the Aguhajsu 1S 3A battery protection module for a single 18650 lithium-ion cell.

![Build](./assets/Aguhajsu1S3A_build.jpg?raw=true)

## Notes

Aguhajsu 1S 3A BMS is a tiny PCB. The smarts are provided by two ICs:

* [DW01 Plus battery protection IC](https://www.digchip.com/datasheets/parts/datasheet/922/DW01.php)
* [FS8205A Dual N-Channel Enhancement Mode Power MOSFET](https://www.ic-fortune.com/upload/Download/FS8205A-DS-12_EN.pdf)

The DW01 provides four basic protection functions:

* over-charge
* over-discharge
* over-current
* short-circuit

The FS8205A provides the power MOSFETs that are controlled by the DW01 to cut/enable power as required.

The module provides **protection only**. It does not manage the charging profile (i.e. constant current control) - this must be handled separately.

The form factor of the module (a long thin strip) perhaps makes this module most suitable for adding protection to "pillow pack" lithium batteries.

Andreas Spiess has a good video explaining how similar battery protection circuits work:

[![clip](https://img.youtube.com/vi/1rg3ZWxBNUE/0.jpg)](https://www.youtube.com/watch?v=1rg3ZWxBNUE)

## Module Specifications

Product blurb from the seller/manufacturer:

> The main IC uses the original Fujing imported components. With overcharge, over discharge, over current, short circuit and other protection functions, for a variety of shapes of various shapes 3.7V lithium battery. It adopts rich crystal protection IC, high quality MOSFET such as VISHAY, AOS and IR, FR-4 low temperature coefficient plate, excellent design, fine workmanship and comprehensive test. It is small in size and suitable for many applications requiring high integration and low cost. It can meet various performance requirements and ensure the absolute safety and reliability of the battery pack.

Technical Parameters:

* Overcharge detection voltage: 4.25 ± 0.05V
* Overcharge release voltage: 4.23 ± 0.05V
* Overdischarge detection voltage: 2.54 ± 0.1V
* Overcurrent detection current: 1-3A

Wiring instructions:

* B+ is connected to the positive battery.
* B- connect the battery negative.
* P+ is the power input/output positive
* P- is the power input/output negative

## Construction

I've drawn the schematic for the module circuit [here (EasyEDA)](https://easyeda.com/tardate/aguhajsu1s3a).
The circuit used in the module is literally exactly as depicted in the DW01 datasheet.

![Schematic](./assets/Aguhajsu1S3A_schematic.jpg?raw=true)

For testing purposes, I've included an additional indicator LED that can be disabled with a jumper, and mounted
the module on some protoboard with connectors for power and some test points.

![Build](./assets/Aguhajsu1S3A_build.jpg?raw=true)

### About the DW01

| Pin | Symbol | Description |
|-----|-----|---------------------------------------------------|
| 1   | OD  | MOSFET gate connection pin for discharge control  |
| 2   | CS  | Input pin for current sense, charger detect       |
| 3   | OC  | MOSFET gate connection pin for charge control     |
| 4   | TD  | Test pin for reduce delay time                    |
| 5   | VCC/VDD | Power supply, through a resistor (R1)             |
| 6   | GND/VSS | Ground pin                                        |

![DW01](./assets/DW01.jpg?raw=true)

### About the FS8205A

![FS8205A](./assets/FS8205A.jpg?raw=true)

## Testing a Charge

I'm testing a charge cycle with an old 1300mAh battery.
A good rule of thumb is to charge at a maximum current of arround 0.5C (650mA),
so I set my bench power supply for 5V with 500mA current limit for this charge test.
This is a very crude constant current charge profile.

The over-charge protection kicks in as expected at around 4.3V:

![power_cycle](./assets/power_cycle.jpg?raw=true)

## Credits and References

* [1S 3.7V 3A li-ion BMS PCM battery protection board pcm for 18650 lithium ion li battery](https://www.aliexpress.com/item/33038857265.html)
* [DW01 Plus battery protection IC](https://www.digchip.com/datasheets/parts/datasheet/922/DW01.php)
* [FS8205A Dual N-Channel Enhancement Mode Power MOSFET](https://www.ic-fortune.com/upload/Download/FS8205A-DS-12_EN.pdf)
