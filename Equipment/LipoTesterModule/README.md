# #518 Lipo Tester Module

Just a quick look at a 1S to 8S battery tester and alarm module.

![Build](./assets/LipoTesterModule_build.jpg?raw=true)

## Notes

I picked up a [1-8S voltage monitor and alarm](https://www.aliexpress.com/item/32847601843.html) from an aliexpress seller

* for 1-8s Lipo/Li-ion/LiMn/Li-Fe
* Voltage detection precision: 0.01V.
* Unit voltage display range: 0.5V-4.5V.
* Total voltage display range: 0.5V-36V.
* 1S test mode voltage range: 3.7v-30v.
* Low voltage alarm mode for 2-8S.
* Alarm set value range: OFF-2.7V-3.8V, preset value 3.3V. Pushbutton (top) can change the voltage settings and save.
* When the voltage is below the set value, it will buzzer with red LED light.

![module_back](./assets/module_back.jpg?raw=true)

![module_front](./assets/module_front.jpg?raw=true)

## Construction

Taking a closer look but cutting off the heat-shrink protector.
I found the 3-digit LED display also still had it's protective plastic attached (which I took the opportunity to remove).

![cu1](./assets/cu1.jpg?raw=true)

It seems power is tapped from the 1S unit to drive the alarm,
and voltage dividers are used to scale the voltage of each battery cell to a level that can be read by a microprocessor's ADC.

![cu2](./assets/cu2.jpg?raw=true)

I haven't desoldered the LED display (yet), but if I did it looks like I'll find a PIC or other brand of microprocessor underneath..

![cu3](./assets/cu3.jpg?raw=true)

## Credits and References

* [Voltage monitor 1-8S Lipo/Li-ion/Fe Battery Voltage 2IN1 Tester Low Voltage Buzzer Alarm 3.7-30V](https://www.aliexpress.com/item/32847601843.html) - from an aliexpress seller
