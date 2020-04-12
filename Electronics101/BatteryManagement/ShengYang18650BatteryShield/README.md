# #544 ShengYang 18650 Battery Shield

Checking out the ShengYang 18650 Battery Shield V3 - single cell with USB charge controller and three regulated outputs - 3V, 5V and switchable USB Type A.

![Build](./assets/ShengYang18650BatteryShield_build.jpg?raw=true)

## Notes

I purchased my unit from a [seller on aliexpress](https://www.aliexpress.com/item/32986331265.html).

Specifications:

* charging:
  - micro USB input
  - 0.5A current charging
  - 5-8V Input Voltage
  - LED indicators:
    - Green: full (L1)
    - Red: charging (L2)
* battery protection:
  - Over charge
  - Over discharge)
* output:
  - Type-A USB Output (with switch)
  - 3V 1A (3 sets of connection pads)
  - 5V 2A(3 sets of connection pads)
* board Size: 9.8x2.9cm/3.86x1.14inch

## Construction

Core components:

* TP4056 constant-current/constant-voltage charge controller
* FP6298 Low-Noise 4.5A Step-Up Current Mode PWM Converter

![module_construction](./assets/module_construction.jpg?raw=true)

## Use

Charging:

![charging](./assets/charging.jpg?raw=true)

Charged:

![charged](./assets/charged.jpg?raw=true)

Measuring 3.2V and 5V output:

![ShengYang18650BatteryShield_build](./assets/ShengYang18650BatteryShield_build.jpg?raw=true)

## Credits and References

* [ESP32 ESP32S For Wemos For Raspberry Pi 18650 Battery Charge Shield Board V3 Micro USB Port Type-A USB 0.5A For Arduino Charge](https://www.aliexpress.com/item/32986331265.html) - from seller on aliexpress
* [TP4056A](http://www.tpwic.com/index.php?m=content&c=index&a=show&catid=173&id=52) constant-current/constant-voltage charge controller
* [FP6298 product info and datasheet](http://www.feeling-tech.com.tw/km-master/front/bin/ptdetail.phtml?Part=PA-30)
