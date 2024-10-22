# #501 Single-cell Lithium Charger

How to charge a single 18650 lithium-ion cell with a TP4056-based charging kit, with comparison to ETA9635/ETA9638-based modules.

![Build](./assets/SingleCellLithiumCharger_build.jpg?raw=true)

## Notes

Lithium Ion/Polymer batteries are all around us these days, but they are also have a deserved reputation for
being a bit dangerous if not treated properly, in particular:

* over-current/short-circuit output (same situation can be created if the package is punctured)
* over-discharge - increases battery resistance and hence heat/fire risk during recharge
* over-charge - stresses the battery and compromises safety

Get anything wrong, and there's heat & fire risk, maybe violent enough to be explosive. Great news for youtubers like [Big Clive](https://youtu.be/0tGK1nqXr28)!

Charging is where things can most commonly go wrong. A little bit of knowledge can go a long way, especially if buying "cheap" chargers or going the DIY route.

There is an optimal charging profile for li-ion batteries:

* pre-qualification stage - a low constant-current charge to bring deeply-discharged cells back to a nominal voltage (usually 3V for 3.7V li-ion)
* constant-current fast chage - usually 0.5C until battery approaches fully charged voltage
* constant voltage saturation charge - until charge current falls below 3-5% percent of the rated current.

This sensitivity to charging conditions is why li-ion cells are ideally charged individually, or with a balanced charging circuit when multiple cells are in an array.

NB:
* Charging rates are specified in terms of `C`, where 1 C equals the maximum current the battery can supply for one hour.
* li-ion with the traditional cathode materials of cobalt, nickel, manganese and aluminum typically charge to 4.20V/cell. The tolerance is +/–50mV/cell.
* some nickel-based varieties charge to 4.10V/cell;
* high capacity Li-ion may go to 4.30V/cell and higher.


Some guides to lithium battery charging:

* [A Designer's Guide to Lithium (Li-ion) Battery Charging](https://www.digikey.sg/en/articles/techzone/2016/sep/a-designer-guide-fast-lithium-ion-battery-charging)
* [BU-409: Charging Lithium-ion](https://batteryuniversity.com/learn/article/charging_lithium_ion_batteries) - Battery University
* [EEVblog #176](https://www.youtube.com/watch?v=A6mKd5_-abk) Lithium Ion/Polymer Battery Charging Tutorial:

[![clip](https://img.youtube.com/vi/A6mKd5_-abk/0.jpg)](https://www.youtube.com/watch?v=A6mKd5_-abk)


#### TP4056

The [TP4056](http://www.tpwic.com/index.php?m=content&c=index&a=show&catid=173&id=52) is made by NanJing Top Power ASIC Corp.
It is a complete constant-current/constant-voltage linear charger for single cell lithium-ion batteries,
described as: 1A Standalone Linear Li-lon Battery Charger with Thermal Regulation.

The charging charge profile is designed for 3.7V li-ion batteries, featuring:

* constant-current/constant-voltage
* Preset 4.2V Charge Voltage with 1.5% Accuracy
* C/10 Charge Termination
* 2.9V Trickle Charge Threshold
* Thermal Regulation

![TP4056_charge_profile](./assets/TP4056_charge_profile.jpg?raw=true)

Typicall application circuit:

![TP4056_typical_application](./assets/TP4056_typical_application.jpg?raw=true)

Julian Ilett did a very good detailed review and test of the common TP4056 modules:

[![clip](https://img.youtube.com/vi/Qw4psECqpwI/0.jpg)](https://www.youtube.com/watch?v=Qw4psECqpwI)

### TP4056 Charger Kit

I picked up an 18650 charging & power pack kit from an aliexpress seller:
[DIY Kit Micro USB 5V 1A 18650 TP4056 Lithium Battery Charger Module +600MA SB Mobile Power Boost Board +18650 Battery Box Case](https://www.aliexpress.com/item/32631921696.html). It basically includes a battery holder and two modules: a TP4056 charging module, and a boost converter for a 5V output.

![kit_parts](./assets/kit_parts.jpg?raw=true)

The TP4056 charging module uses three main chips in addition to support passives and indicator LEDs:

* [TP4056A](http://www.tpwic.com/index.php?m=content&c=index&a=show&catid=173&id=52) for constant-current/constant-voltage charge control
* [DW01](https://www.digchip.com/datasheets/parts/datasheet/922/DW01.php) battery protection IC
* [8205A Dual N-Channel MOSFET](https://www.datasheet4u.com/datasheet-pdf/RZCMicroelectronics/8205A/pdf.php?id=847696) provides load switching - apparently from [RZC Microelectronics](http://www.rzcsemi.com/) but not listed on their current web site. OR it could be [ML8205A](https://www.evelta.com/content/datasheets/130-ML8205A.pdf) by [Mei Lai 美莱创新](http://www.szmeilai.com/)

![kit_TP4056_module](./assets/kit_TP4056_module.jpg?raw=true)

The boost module is a standard switching circuit using a switching regulator marked E50D.
Although [some listings](https://www.sunrom.com/p/5v-dc-dc-boost-step-up) identify this as a CE8301 regulator, the package marking don't seem quite correct
(appears more like a SOT-89-3 CE8301A which I would expect to be marked "A50P"). Regardless, this is the simplest form of fixed output converter without frills such as auto-shutdown.

Rprog/R3 is populated as 1.2kΩ, which corresponds to programmed charge current of 1000mA.

![kit_boost_module](./assets/kit_boost_module.jpg?raw=true)

The recommended configuration matching the parts in the kit is a simple wiring together of the modules:

![Build](./assets/SingleCellLithiumCharger_schematic.jpg?raw=true)

However, since neither the charge or boost module include any auto-shutdown capability, this means an "always on" configuration.
I added a [switch](https://www.aliexpress.com/item/32799198160.html) to the battery leads so that I can leave a battery in the holder
without it being continually discharged.

Charging:

![Build](./assets/SingleCellLithiumCharger_build.jpg?raw=true)

Full charged:

![kit_fully_charged](./assets/kit_fully_charged.jpg?raw=true)


### TZT Single-cell Power Bank

As a comparison for the TP4056-based circuits, I opened up a
[TZT 18650 USB Power Bank](https://www.aliexpress.com/item/32975739982.html) I had kicking around.

![kit2_build](./assets/kit2_build.jpg?raw=true)

![kit2_parts](./assets/kit2_parts.jpg?raw=true)

It turns out this is using the [ETA9635](http://www.etasolution.com/w-cn/prod_det.html?id=18) which is an integrated charger and boost converter from ETA solutions.
NB: The ETA9635 appears to have been superseded by the [ETA9638](http://www.etasolution.com/w-cn/prod_det.html?id=19).

This obviously allows for a much more compact product:

![kit2_board](./assets/kit2_board.jpg?raw=true)

The ETA9635 features:

* 2 in 1: integrated synchronous boost plus charger without external load switching
* Short-circuit Protection
* Reverse current Protection
* Up to 1A Charging, 5W output
* 50µA of quiescent current during no load

## Credits and References

* [DIY Kit Micro USB 5V 1A 18650 TP4056 Lithium Battery Charger Module +600MA SB Mobile Power Boost Board +18650 Battery Box Case](https://www.aliexpress.com/item/32631921696.html) - example from an aliexpress seller
* [TP4056 info and datasheet](http://www.tpwic.com/index.php?m=content&c=index&a=show&catid=173&id=52) - original source NanJing Top Power ASIC Corp (chinese datasheet)
* [TP4056 info and datasheet](https://www.sunrom.com/p/tp4056-li-on-battery-charger-ic-1a) - English version from sunrom.com
* [DW01 Plus battery protection IC](https://www.digchip.com/datasheets/parts/datasheet/922/DW01.php)
* [LTC4056-4.2](https://www.analog.com/en/products/ltc4056-4.2.html) - similar but not to be confused with the TP4056
* [8205A Dual N-Channel MOSFET](https://www.datasheet4u.com/datasheet-pdf/RZCMicroelectronics/8205A/pdf.php?id=847696)
* [ML8205A](https://www.evelta.com/content/datasheets/130-ML8205A.pdf) by [Mei Lai 美莱创新](http://www.szmeilai.com/)
* [Dual mosfet 8205A - lithium battery protection circuit](https://electronics.stackexchange.com/questions/203463/dual-mosfet-8205a-lithium-battery-protection-circuit) - discussed on electronics.stackexchange
* [CE8301 regulator](https://www.sunrom.com/p/5v-dc-dc-boost-step-up)
* [Restoring/Recharging Over-discharged LiPo (Lithium Polymer) Batteries](https://www.electricrcaircraftguy.com/2014/10/restoring-over-discharged-LiPos.html)
* [SS12D00G3 Toggle Switch 2 Position SPDT](https://www.aliexpress.com/item/32799198160.html)
* [TZT USB Power Bank Case Kit 18650 Battery Charger DIY Box Shell Kit Black For Arduino](https://www.aliexpress.com/item/32975739982.html) - example from an aliexpress seller
* [ETA9635 datasheet](http://www.etasolution.com/w-cn/prod_det.html?id=18) from ETA solutions, appears to have been superseded by the [ETA9638](http://www.etasolution.com/w-cn/prod_det.html?id=19)
