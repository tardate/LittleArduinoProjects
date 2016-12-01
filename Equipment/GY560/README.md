# #403 GY560 Frequency Counter

Checking out the GY560 Frequency Counter.

![Build](./assets/GY560_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The GY560 Frequency Counter is an incredibly cheap but pretty effective bit of test gear, most useful for detecting radio frequency emissions
with a measure of frequency and signal strength.


I think I first saw this in one of dazaro3's videos like How to build a 2 transistor FM transmitter:

[![clip](http://img.youtube.com/vi/py5BD9UcTFA/0.jpg)](https://youtu.be/py5BD9UcTFA?t=974)


## Specifications


- Frequency step : 200K (digital radio signal), 1K, 100Hz.
- Testing distance : UHF : 8m, VHF : 5m.
- Testing range : 50 MHz ~ 2.4 GHz
- Antenna : pulling out antenna
- Battery : 9V 6F22
- Auto power off time : 1 mins. (except for the digital signal gear)
- Operation : the only one button with all functions


## Operation

The only one button with all functions.

* Power on: short press
* Power on and set step: hold button down on power on, will cycle through 1kHz, 200kHz, 100Hz. Release button on desired step.
  - This mode will be remembered after restart.
  - 200kHz mode recommended for digital radio
  - 1kHz mode recommended for faster testing
  - 100Hz mode recommended for accurate testing
* Hold: short press while on with hold/release display
* Power Down: long press


## Internals

Quick peek inside. Not much to it - just a microcontroller with input signal and display. Although the chip is unmarked, I wouldn't mind betting that's just a PIC.

![GY560_internals](./assets/GY560_internals.jpg?raw=true)


## Credits and References
* [GY560 Frequency Counter](https://www.aliexpress.com/item/GY560-Frequency-Counter-Mini-Handhold-Meter-for-Two-Way-Radio-Transceiver-GSM-50-MHz-2-4/32676085952.html) - from seller on aliexpress
