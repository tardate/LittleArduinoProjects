# DS3231RTC/TimeDemo

Prints the system time synced from the RTC to the serial output


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

This is the most basic test an DS3231 RTC used to sync the Arduino system time.
During setup, the clock is set from the RTC (`setSyncProvider(RTC.get);`).
The rest of the sketch is just a simpe routine to send the date/time to the serial port.

Since the RTC is only used during setup, the RTC clock can actually be powered down or disconnected once the sketch is running.

All the required libraries may be installed from the Arduino IDE "Manage Libraries" or installed separately.

The [RTC module I'm using](http://www.aliexpress.com/item/B39-hot-sale-DS3231-AT24C32-IIC-Precision-RTC-Real-Time-Clock-Memory-Module-For-Arduino-Free/32217889168.html) is based on the DS3231 chip. It uses I²C for communications (analog pins 4 and 5).

This sketch is only using the very basic DS1307-compatible time functions, but the DS3231 has some interesting extra functions to explore:
* digital temperatur sensor
* two time-of-day alarms
* programmable square-wave output

## Construction

![Breadboard](./assets/TimeDemo_bb.jpg?raw=true)

![The Schematic](./assets/TimeDemo_schematic.jpg?raw=true)

![The Build](./assets/TimeDemo_build.jpg?raw=true)

## Credits and References
* [DS3231 datasheet](https://www.maximintegrated.com/en/products/digital/real-time-clocks/DS3231.html)
* [DS3232RTC library](https://github.com/JChristensen/DS3232RTC)
* [Arduino Time library](http://playground.arduino.cc/Code/Time)
* [Arduino Wire library](http://arduino.cc/en/Reference/Wire)
* [adding printf support](http://playground.arduino.cc/Main/Printf)
* [DS3231 module](http://www.aliexpress.com/item/B39-hot-sale-DS3231-AT24C32-IIC-Precision-RTC-Real-Time-Clock-Memory-Module-For-Arduino-Free/32217889168.html) - from aliexpress seller