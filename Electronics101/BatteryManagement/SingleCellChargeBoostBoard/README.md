# #538 Single-cell Charge/Boost Board

An 18650 single-cell battery module with integrated TP4056 5V/USB charge controller and MT3608 5V output boost converter.

![Build](./assets/SingleCellChargeBoostBoard_build.jpg?raw=true)

## Notes

This is a board/kit often listed with a description such as:
[5V/12V 18650 Lithium Battery Boost Step Up Module Charge Discharge the Same Time UPS Protection Board Charger Circuit Li-ion](https://www.aliexpress.com/item/33032221967.html)

It's quite a neat module:

* powered from a single 18650 lithium battery
* BMS/charging circuit with micro USB or direct 5V connection
* output boost converter - available for 5V or 12V output

![kit_parts](./assets/kit_parts.jpg?raw=true)

Charge-controller functions:

* Lithium battery charging
* Lithium battery protection (short circuit  protection, over voltage protection, under voltage  protection)
* charging is automatically stopped
* equipped with universal Micro USB connector and direct 5V input pads
* LED charging status indicators
* charges with 5V at up to 1A
* uses the TP4056 constant-current/constant-voltage charge controller

Boost converter:

* boost module requires an external switch to be attached, or pads shorted for "always on" (what the vender specs refer to as "UPS" mode)
* during the operation, it is possible that the board will enter the protection state and turn off output
* uses the MT3608 boost controller (chip marking: B628)

## Board Connections

![kit_annotated_board](./assets/kit_annotated_board.jpg?raw=true)

## Usage

Output boost converter on; no charger connected:

![operating_power_on](./assets/operating_power_on.jpg?raw=true)

Charging with 5V USB power; output boost converter off:

![operating_charging_power_off](./assets/operating_charging_power_off.jpg?raw=true)

Charging with 5V USB power; output boost converter on:

![operating_charging_power_on](./assets/operating_charging_power_on.jpg?raw=true)

## Credits and References

* [5V/12V 18650 Lithium Battery Boost Step Up Module Charge Discharge the Same Time UPS Protection Board Charger Circuit Li-ion](https://www.aliexpress.com/item/33032221967.html)
* [TP4056A](http://www.tpwic.com/index.php?m=content&c=index&a=show&catid=173&id=52) constant-current/constant-voltage charge controller
* [MT3608 datasheet](https://www.olimex.com/Products/Breadboarding/BB-PWR-3608/resources/MT3608.pdf)
