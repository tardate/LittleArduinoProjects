# #607 XKT-511 Wireless LED Module

Investigating a wireless LED power module based on the XKT-511 chip.

![Build](./assets/WirelessLedModule_build.jpg?raw=true)

## Notes

I've seen a few wireless LED power modules for sale so decided to pick one up to find out how they have been designed.
I picked a
[DC Remote Micro Receiver Wireless Power Supply Module wireless power supply coil module](https://www.aliexpress.com/item/32944450041.html)
that uses the XKT-511 chip on the transmitter end and came with 3 LED modules.

![module_1](./assets/module_1.jpg?raw=true)

After examining the module, it is quite straight-forward:
the XKT-511 chip is fully integrated ASIC used to monitor and control the oscillation on the transmitting coil. It seems to only require 4 additional components:

* two capacitors (input and output side)
* two resistors forming a voltage divider for feedback control

The XKT-511 appears to be the latest generation of wireless power control technology from [深圳芯科泰半导体有限公司 Shenzhen Coretech Semiconductor Co., Ltd.](http://www.xktbdt.com/). While they haven't published the datasheet on their website, they have excellent customer service and provided me the full specs in response to an email.

![module_3](./assets/module_3.jpg?raw=true)

### Module Specs

From the [aliexpress vendor page](https://www.aliexpress.com/item/32944450041.html):

The combined kit (regulator, coil and LEDs) is designated the XKT515-09.
The chip on the module is marked XKT-511.

The main parameters:

* Transmitting voltage: 12V
* The transmitting coil: 75mm*1mm
* The receiving coil: 14.5mm
* Sending and receiving distance: 45mm

They also offer [additional LED modules](https://www.aliexpress.com/item/1005003633247348.html).

![module_2](./assets/module_2.jpg?raw=true)

### XKT-511

The main problem I ran into is that while the XKT-511 chip is available for sale, I wasn't able to find product information or a datasheet.
I was able to find the XKT-511 chips for sale in various places such as this [listing on taobao](https://world.taobao.com/item/628744807932.htm).

I figured it was produced by [深圳芯科泰半导体有限公司 Shenzhen Coretech Semiconductor Co., Ltd.](http://www.xktbdt.com/) who produce similar chips like the XKT-510.
Although their website does not list it, I was pleasantly surprised when a simple email to them produced a quick reply with a full set of datasheet.
Excellent service! They are in Chinese of course, but that is my problem;-)

Selected extracts from the datasheet:

#### Features

* Small size，Packaged as SOP-8
* High working frequency
* High integration，Few peripheral devices
* High output power
* Wide range of applications
* Control function can be designed freely
* Under special design，It can control the working state of the receiving part
* working voltage ：DC 3.3~18V
* working frequency ：1KHz~3.5MHz
* The coil can be printed PCB Board
* The optimum state of quiescent current can be designed to be lower than 5mA。

#### SOP8 Pin Configuration

| Pin | Label | Function |
|-----|-------|----------|
| 1   | R     | Frequency Modification Resistor |
| 2   | R     | Frequency Modification Resistor/Voltage Monitor Resistor |
| 3   | Drive GND | Digital drive low voltage power ground |
| 4   | Load GND  | Load ground (for function expansion use) |
| 5   | VIN   | Load source |
| 6   | TEST  | Working frequency test |
| 7   | VDD   | Power supply (0-18V) |
| 8   | N/F   | Control terminal, set high to work, set low to close output, can access custom control signals |

#### Example Circuit 1

This example from the datasheet is I think identical to the circuit used in the XKT515-09 package I have.

Notes on the circuit:

* designed for 5V power supply
* The emission quiescent current is 60mA±10mA, the output power of this circuit is relatively large, and the coil area and distance determine the actual output power.
* Transmitting circuit stability test method:
    * power on the transmitting part, record the static current parameters, normally it should be 60mA±20mA (the maximum limit value is not more than 100mA).
    * If the current deviation is not large, you can make fine adjustments by adjusting the number of coil turns.
    * PS: If you are worried about the high temperature after the transmitter chip is damaged, you can string a resettable fuse in the power supply part as a short circuit protection.

![example_circuit_1](./assets/example_circuit_1.jpg?raw=true)

### Similar Products

The XKT-511 information is not widely available on the internet as yet. A search will likely yield results for the following chips.
Be careful not to get confused - these chips are similar in function but quite different in the particulars:

* [XKT-412](http://www.xktbdt.com/page6?product_id=248) - much older product also for wireless power transmission, usually paired with T5336 chip and many external passives. Circuit and datasheet widely available. appears to be the 1st generation product before a 2nd generation of XKT-5xx chips.
* [XKT-510](http://www.xktbdt.com/page6?product_id=249) - appears to be a very similar, perhaps immediate precursor. Requires more external components and has a very different pinout than the XKT-511.
* [XKT-515](http://www.xktbdt.com/page6?product_id=259) - allegedly similar to the XKT-511, but I haven't seen the datasheet.
* [T3168 / XKT-3168](http://www.xktbdt.com/page6?product_id=250) is a general-purpose receiving integrated circuit for wireless charging. It could be used on the receiving end of the XKT-511 transmitter.
* [XKT-R2](http://www.xktbdt.com/page6?product_id=193) - appears to be the big broether of the XKT-511. DEsigned for high-voltage/high-current charging.

## Construction

Here is my rough redrawing of the XKT-511 transmitter module. Note:

* I haven't measured the values of C1, C2; I am assuming they follow the example circuit from the datasheet
* R2 measures about 75kΩ in-circuit, which matches the example circuit from the datasheet. The part appears to be labelled "098" (900MΩ?!!) but that doesn't seem right.

![bb](./assets/WirelessLedModule_bb.jpg?raw=true)

![schematic](./assets/WirelessLedModule_schematic.jpg?raw=true)

## Credits and References

* [DC Remote Micro Receiver Wireless Power Supply Module wireless power supply coil module](https://www.aliexpress.com/item/32944450041.html)
* [2PCS Receive LED lights for DC Remote Micro Receiver Wireless Power Supply Module wireless power supply coil module](https://www.aliexpress.com/item/1005003633247348.html)
* [Autonomous Wireless Self-Charging for Multi-Rotor Unmanned Aerial Vehicles](https://www.researchgate.net/figure/XKT-510-IC-based-wireless-charging-module_fig5_317584880)
* [XKT-510 High Power Wireless Charging Transmitter Chip Wireless Power Supply Chip](https://www.alibaba.com/product-detail/XKT-510-High-Power-Wireless-Charging_60746855788.html)
* [Taidacent DC 3.3V 4.2V 5V 12V 18V Wireless Power Supply Chip XKT-511 SOP8 Wireless Charger Charging Chip](https://www.alibaba.com/product-detail/Taidacent-DC-3-3V-4-2V_1600111627788.html?spm=a2700.galleryofferlist.normal_offer.d_title.6c717e7dOfLGVU)
* [High-precision Industrial-grade Wireless Charging Wireless Power Supply Chip Solution XKT-511](https://www.aliexpress.com/item/1005002983373593.html)
* [高精度工業級無線充電無線供電芯片方案XKT-511](https://world.taobao.com/item/628744807932.htm) - High-precision industrial-grade wireless charging wireless power supply chip solution XKT-511
