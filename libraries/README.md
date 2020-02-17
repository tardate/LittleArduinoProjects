# Libraries

Some projects require additional libraries. For example:

* [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library) - dependency of AdaFruit display libraries
* [Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor) - Adafruit Unified Sensor Library
* [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306) - for monochrome OLED displays
* [Adafruit_VL53L0X](https://github.com/adafruit/Adafruit_VL53L0X)
* [Adafruit-PCD8544 Library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library)
* [Adafruit-Thermal-Printer-Library](https://github.com/adafruit/Adafruit-Thermal-Printer-Library) - for small thermal printers
* [Adafruit-TinyWireM](https://github.com/adafruit/TinyWireM) - I²C for the ATtiny
* [Arduino-INA226](https://github.com/jarzebski/Arduino-INA226) - INA226 Bi-directional Current/Power Monitor Arduino Library
* [ArduinoJson](https://github.com/bblanchon/ArduinoJson)
* [DHT Sensor Library]((https://github.com/adafruit/DHT-sensor-library)
* [DS3232RTC](https://github.com/JChristensen/DS3232RTC) - DS3232-based realtime clock module control
* [EnableInterrupt](https://github.com/GreyGnome/EnableInterrupt) - Flexible interrupt management
* [FastLED](http://fastled.io/) - used by LED array projects
* [FlexiTimer2](https://github.com/wimleers/flexitimer2) - generally used for precision timing
* [interactive-matter/HTTPClient](https://github.com/interactive-matter/HTTPClient) - EthernetShield projects
* [LedControl](https://github.com/wayoda/LedControl) - LED matrix control
* [LRAS1130](https://github.com/LuckyResistor/LRAS1130) - AMS AS1130 LED Driver control
* [MFRC522](https://github.com/miguelbalboa/rfid) - MFRC522 RFID library by miguelbalboa
* [OneWire](https://github.com/PaulStoffregen/OneWire) - 1-wire compatible components
* [PCM](https://github.com/damellis/PCM) - Playback of short audio samples.
* [Radio](http://www.mathertel.de/Arduino/RadioLibrary.aspx) - Arduino Radio Library
* [RadioHead](https://github.com/tardate/RadioHead) - Packet Radio e.g. 433MHz projects. RadioHead is a successor the the [VirtualWire](http://www.airspayce.com/mikem/arduino/VirtualWire/) library.
* [RF24](https://github.com/maniacbug/RF24) - used by nRF24L01+ projects
* [Rotary](https://github.com/brianlow/Rotary) - rotary Encoder input
* [SV-Zanshin/INA](https://github.com/SV-Zanshin/INA) - Combined Arduino library for reading multiple INA2xx power monitor devices
* [Tiny4kOLED](https://github.com/datacute/Tiny4kOLED) - OLED driver for ATtiny
* [u8glib](https://github.com/olikraus/U8glib_Arduino) - for monochrome displays
* [u8g2lib](https://github.com/olikraus/U8g2_Arduino) - v2 for monochrome displays
* [X113647Stepper](https://github.com/tardate/X113647Stepper) - used by some Stepper motor projects
* [LRThreeDigits](https://github.com/LuckyResistor/LRThreeDigits) - Boldport 3x7 driver by LuckyResistor

These libraries are included as submodules of this repository and can be installed with git.

For Arduino projects, I have the Arduino IDE sketchbook location (in preferences) set to the root of this repository.
This makes all the projects available to me in the IDE, and automatically includes libraries
that are linked as git submodules in this folder.

If you don't have the Arduino IDE setup this way, libraries can just be installed normally.
For information on installing libraries, see: http://arduino.cc/en/Guide/Libraries

## Install with Git

If you clone this repo, also update the submodules:

    $ git submodule update --init

To pull submodule updates later on:

    $ git submodule foreach git pull


## Pull updates for a specific library

e.g. to pull the latest X113647Stepper updates:

    $ git submodule update --remote libraries/X113647Stepper

## Adding a new module to the Repo

    $ git submodule add https://github.com/repo_path/name libraries/name
