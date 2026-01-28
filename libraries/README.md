# Libraries

Some projects require additional libraries. For example:

* [Adafruit_BMP280_Library](https://github.com/adafruit/Adafruit_BMP280_Library)
* [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library) - dependency of AdaFruit display libraries
* [Adafruit-PCD8544 Library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library)
* [Adafruit-Thermal-Printer-Library](https://github.com/adafruit/Adafruit-Thermal-Printer-Library) - for small thermal printers
* [Adafruit-TinyWireM](https://github.com/adafruit/TinyWireM) - I²C for the ATtiny
* [Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor) - Adafruit Unified Sensor Library
* [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306) - for monochrome OLED displays
* [Adafruit_VL53L0X](https://github.com/adafruit/Adafruit_VL53L0X)
* [Arduino-INA226](https://github.com/jarzebski/Arduino-INA226) - INA226 Bi-directional Current/Power Monitor Arduino Library
* [Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote)
* [Arduino-Temperature-Control-Library](https://github.com/milesburton/Arduino-Temperature-Control-Library)
* [ArduinoJson](https://github.com/bblanchon/ArduinoJson)
* [DHT Sensor Library]((<https://github.com/adafruit/DHT-sensor-library>)
* [DS3232RTC](https://github.com/JChristensen/DS3232RTC) - DS3232-based realtime clock module control
* [EnableInterrupt](https://github.com/GreyGnome/EnableInterrupt) - Flexible interrupt management
* [FastLED](http://fastled.io/) - used by LED array projects
* [FlexiTimer2](https://github.com/wimleers/flexitimer2) - generally used for precision timing
* [HPDL1414](https://github.com/marecl/HPDL1414) - used for driving HPDL1414 displays
* [interactive-matter/HTTPClient](https://github.com/interactive-matter/HTTPClient) - EthernetShield projects
* [LedControl](https://github.com/wayoda/LedControl) - LED matrix control
* [LiquidCrystal_I2C](https://github.com/marcoschwartz/LiquidCrystal_I2C) - LCD over I²C
* [LRAS1130](https://github.com/LuckyResistor/LRAS1130) - AMS AS1130 LED Driver control
* [LRThreeDigits](https://github.com/LuckyResistor/LRThreeDigits) - Boldport 3x7 driver by LuckyResistor
* [MFRC522](https://github.com/miguelbalboa/rfid) - MFRC522 RFID library by miguelbalboa
* [NewPing](https://github.com/tardate/arduino-new-ping) original source is in bitbucket: [NewPing](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home)
* [NtpServer](https://github.com/mgi2212/NtpServer) - NtpServer implementation
* [OneWire](https://github.com/PaulStoffregen/OneWire) - 1-wire compatible components
* [PCM](https://github.com/damellis/PCM) - Playback of short audio samples.
* [PrecisionServo](https://github.com/ElizabethTeaches/PrecisionServo) - cloned here, as the repo is not setup correctly to be imported directly as a module
* [Radio](http://www.mathertel.de/Arduino/RadioLibrary.aspx) - Arduino Radio Library
* [RadioHead](https://github.com/tardate/RadioHead) - Packet Radio e.g. 433MHz projects. RadioHead is a successor the the [VirtualWire](http://www.airspayce.com/mikem/arduino/VirtualWire/) library.
* [RF24](https://github.com/maniacbug/RF24) - used by nRF24L01+ projects
* [Rotary](https://github.com/brianlow/Rotary) - rotary Encoder input
* [Servo8Bit](https://github.com/fri000/Servo8Bit) - servo control with 8-bit timers (e.g ATTiny)
* [SoftwareServo](https://github.com/ttseng/SoftwareServo) - cloned here, as the repo is not setup correctly to be imported directly as a module
* [SV-Zanshin/INA](https://github.com/SV-Zanshin/INA) - Combined Arduino library for reading multiple INA2xx power monitor devices
* [Tiny4kOLED](https://github.com/datacute/Tiny4kOLED) - OLED driver for ATtiny
* [TMRpcm](https://github.com/TMRh20/TMRpcm) - asynchronous playback of PCM/WAV files direct from SD card
* [u8g2lib](https://github.com/olikraus/U8g2_Arduino) - v2 for monochrome displays
* [u8glib](https://github.com/olikraus/U8glib_Arduino) - for monochrome displays
* [X113647Stepper](https://github.com/tardate/X113647Stepper) - used by some Stepper motor projects

These libraries are included as submodules of this repository and can be installed with git.

For Arduino projects, I have the Arduino IDE sketchbook location (in preferences) set to the root of this repository.
This makes all the projects available to me in the IDE, and automatically includes libraries
that are linked as git submodules in this folder.

If you don't have the Arduino IDE setup this way, libraries can just be installed normally.
For information on installing libraries, see: <http://arduino.cc/en/Guide/Libraries>

## Install with Git

If you clone this repo, also update the submodules:

    git submodule update --init

To pull submodule updates later on:

    git submodule foreach git pull

## Pull updates for a specific library

e.g. to pull the latest X113647Stepper updates:

    git submodule update --remote libraries/X113647Stepper

## Adding a new module to the Repo

    git submodule add https://github.com/repo_path/name libraries/name
