# Libraries

Some projects require additional libraries. For example:

* The LED array projects use the [FastLED](http://fastled.io/) library
* Stepper motor projects use the [X113647Stepper](https://github.com/tardate/X113647Stepper) library
* EthernetShield projects use the [interactive-matter/HTTPClient](https://github.com/interactive-matter/HTTPClient) library
* For precision timing, projects generally use the [FlexiTimer2](https://github.com/wimleers/flexitimer2) library
* nRF24L01+ projects generally use the [RF24](https://github.com/maniacbug/RF24) library
* Packet Radio e.g. 433MHz projects generally use the [RadioHead](https://github.com/tardate/RadioHead) library. RadioHead is a successor the the [VirtualWire](http://www.airspayce.com/mikem/arduino/VirtualWire/) library.
* Monochrome OLED displays use the [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306) library
* Monochrome displays using the [u8glib](https://github.com/olikraus/U8glib_Arduino) library
* AdaFruit display libraries may use the [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library) library
* LED matrix control with the [LedControl](https://github.com/wayoda/LedControl) library
* Rotary Encoder input with the [Rotary](https://github.com/brianlow/Rotary) library
* DS3232-based realtime clock module control with the [DS3232RTC](https://github.com/JChristensen/DS3232RTC) library
* 1-wire compatible components use the [OneWire](https://github.com/PaulStoffregen/OneWire) library

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
