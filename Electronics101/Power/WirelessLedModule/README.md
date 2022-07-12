# #643 XKT-511 Wireless LED Module

Investigating a wireless LED power module based on the XKT-511 chip.

![Build](./assets/WirelessLedModule_build.jpg?raw=true)

## Notes

I've seen a few wireless LED power modules for sale so decided to pick one up to find out how they have been designed.
I picked a
[DC Remote Micro Receiver Wireless Power Supply Module wireless power supply coil module](https://www.aliexpress.com/item/32944450041.html)
that uses the XKT-511 chip on the transmitter end and came with 3 LED modules.

![module_1](./assets/module_1.jpg?raw=true)

After examining the module, it is quite straight-forward:
the XKT-511 chip is fully integrated ASIC to monitor and control the oscillation on the transmitting coil. It seems to only require 4 additional components:

* two capacitors (input and output side)
* two resistors forming a voltage divider for feedback control

![module_3](./assets/module_3.jpg?raw=true)

### Module Specs

From the [vendor page](https://www.aliexpress.com/item/32944450041.html):

Claims to use a "XKT-515 DC long-distance chip to design", but the chip on the module is labelled XKT-511.

The main parameters:

* Transmitting voltage: 12V
* The transmitting coil: 75mm*1mm
* The receiving coil: 14.5mm
* Sending and receiving distance: 45mm

They also offer [additional LED modules](https://www.aliexpress.com/item/1005003633247348.html).

![module_2](./assets/module_2.jpg?raw=true)

### XKT-511

The main problem I ran into is that while the XKT-511 chip is available for sale, I've yet to find a specific datasheet for it.
It appears to come from [深圳芯科泰半导体有限公司 Shenzhen Coretech Semiconductor Co., Ltd.](http://www.xktbdt.com/) who produce similar chips like the XKT-510.

I found the XKT-511 chips for sale in various places. For example, the following specification is form a listing on
[taobao](https://world.taobao.com/item/628744807932.htm):

深圳芯科泰半导体有限公司 Shenzhen Coretech Semiconductor Co., Ltd.

XKT-511 The chip is a new wireless charging solution launched by Shenzhen xinketai semiconductor，The working voltage is 3.3V to 18V，In special
Under demand，It can be used directly 4.2V The lithium battery provides power for the transmitting part directly。Chip uses SOP-8 encapsulation，The dimensions are further compressed
shrink。A lot of optimization has also been done on the peripheral devices，Further reduce the size of the finished product，The production process and cost were further optimized。Chip designer
The working frequency range is 1KHz-3.5MKHz，So that the chip has more frequency choice in the circuit design。Its high frequency output can be used PCB Printed coil
Alternative winding coil，And realize high power output，It can greatly simplify the production process。The chip has reserved a high sensitivity control pin（8 foot）Set high
To open，Set low as off，In engineering design，The control signal can be applied to achieve the special requirements of low power consumption。It can also be subject to lower than working pressure
Frequency control signal，To control the working state of the working end of the receiving part。Make the back-end function design more diversity and freedom。
two、characteristic

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

### Similar Products

* [XKT-412](http://www.xktbdt.com/page6?product_id=248) - much older product also for wireless power transmission, usually paired with T5336 chip and many external passives. Circuit and datahseet widely available.
* [XKT-510](http://www.xktbdt.com/page6?product_id=249) - appears to be a very similar, perhaps immediate precursor. Requires more external components and has a very different pinout than the XKT-511.
* [XKT-515](http://www.xktbdt.com/page6?product_id=259) - allegedly simialr to the XKT-511, but also no datasheet available.

I'm still trying tyo source a datasheet for the XKT-511, but my interpretation of what I've found so far:
XKT-412 was the first gen product. XKT-510 was 2nd gen, but has been refined in XKT-511,515 perhaps under specific supply contract.

## Construction

Here is my rough redrawing of the XKT-511 transmitter module. Note:

* don't know the values of C1, C2
* R2 value is questionable. Part labelled "098" i.e 900MΩ, but measures about 75kΩ in-circuit.

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
