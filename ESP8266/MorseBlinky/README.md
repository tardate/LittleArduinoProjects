# #342 MorseBlinky

Building code for an ESP-01 with the ESP8266 core for Arduino and demonstrate with a simple morse code blinker.

Here's a quick video showing it in action..

[![Build](./assets/MorseBlinky_build.jpg?raw=true)](https://www.youtube.com/watch?v=WVuntJtxVK0)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The [ESP8266 core for Arduino](https://github.com/esp8266/Arduino)
brings support for ESP8266 chip to the Arduino IDE.

That means being able to write C++ sketches for the ESP8266 as easy as developing for an Arduino.

This project is a quick test to see how it all works. Objectives are minimalist:

* using the most basic ESP8266 board: an ESP-01
* just blink the built-in LED with a morse code message

The [MorseBlinky.ino](./MorseBlinky.ino) sketch blinks a Morse code message on the built-in LED.

The sketch can be compiled unmodified for either an ESP8266 board or an Arduino.

There may be one difference required depending on the specific board: whether the built-in LED
uses active-high or active-low logic. Tthe specific ESP-01 board I have uses active-low logic,
whereas most Arduino boards I've seen use active-high.
This can be controlled with the `ACTIVE_LOW_LED_LOGIC` setting in the sketch.


### Programming Setup

I'm using a [LEAP#194 DIYDevBoard](../DIYDevBoard) to host the ESP-01 module,
and a cheap [CH340G-based USB to UART adapter](https://www.aliexpress.com/item/CH340-module-USB-to-TTL-CH340G-upgrade-download-a-small-wire-brush-plate-STC-microcontroller-board/32354359382.html).
With the
[correct drivers installed](../../notebook/arduino.md#arduinos-using-the-ch340g-serial-chip),
it shows up in the Arduino IDE ports list.


### Uploading a Sketch


Selecting the Generic ESP8266 board and correct port:

![board_settings](./assets/board_settings.png?raw=true)

The ESP8266 needs to be put into flash mode to accept the program upload:

* connect usb to dev board
* set flash mode dip switch
* power on the esp-01 (or toggle reset dip switch)
* arduino ide - click upload sketch

Note: this will of course wipe whatever image is already on the chip.

Here's the transcript of the programming step, performed by the [esptool.py](https://github.com/themadinventor/esptool) that is integrated in the [ESP8266 core for Arduino](https://github.com/esp8266/Arduino)

```
Sketch uses 222161 bytes (51%) of program storage space. Maximum is 434160 bytes.
Global variables use 31528 bytes (38%) of dynamic memory, leaving 50392 bytes for local variables. Maximum is 81920 bytes.
/Users/paulgallagher/Library/Arduino15/packages/esp8266/tools/esptool/0.4.9/esptool -vv -cd ck -cb 115200 -cp /dev/cu.wchusbserial14530 -ca 0x00000 -cf /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_533772/Blink.ino.bin
esptool v0.4.9 - (c) 2014 Ch. Klippel <ck@atelier-klippel.de>
  setting board to ck
  setting baudrate from 115200 to 115200
  setting port from /dev/tty.usbserial to /dev/cu.wchusbserial14530
  setting address from 0x00000000 to 0x00000000
  espcomm_upload_file
  espcomm_upload_mem
opening port /dev/cu.wchusbserial14530 at 115200
  tcgetattr
  tcsetattr
  serial open
opening bootloader
resetting board
trying to connect
  espcomm_send_command: sending command header
  espcomm_send_command: sending command payload
trying to connect
  espcomm_send_command: sending command header
  espcomm_send_command: sending command payload
  espcomm_send_command: receiving 2 bytes of data
  espcomm_send_command: receiving 2 bytes of data
  espcomm_send_command: receiving 2 bytes of data
  espcomm_send_command: receiving 2 bytes of data
  espcomm_send_command: receiving 2 bytes of data
  espcomm_send_command: receiving 2 bytes of data
  espcomm_send_command: receiving 2 bytes of data
  espcomm_send_command: receiving 2 bytes of data
Uploading 226304 bytes from /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_533772/Blink.ino.bin to flash at 0x00000000
  erasing flash
  size: 037400 address: 000000
  first_sector_index: 0
  total_sector_count: 56
  head_sector_count: 16
  adjusted_sector_count: 40
  erase_size: 028000
  espcomm_send_command: sending command header
  espcomm_send_command: sending command payload
  setting timeout 15000
  setting timeout 100
  espcomm_send_command: receiving 2 bytes of data
  writing flash
................................................................................ [ 36% ]
................................................................................ [ 72% ]
.............................................................                    [ 100% ]
starting app without reboot
  espcomm_send_command: sending command header
  espcomm_send_command: sending command payload
  espcomm_send_command: receiving 2 bytes of data
closing bootloader
```

## Construction

![Breadboard](./assets/MorseBlinky_bb.jpg?raw=true)

![Schematic](./assets/MorseBlinky_schematic.jpg?raw=true)

![Build](./assets/MorseBlinky_build.jpg?raw=true)

## Credits and References
* [ESP8266 core for Arduino](https://github.com/esp8266/Arduino)
* [esptool.py](https://github.com/themadinventor/esptool) - used under the covers by the ESP8266 core for Arduino
* [LEAP#194 DIYDevBoard](../DIYDevBoard) - the dev board I'm using to host the ESP-01
* [How To Program ESP8266 With Arduino IDE](https://www.youtube.com/watch?v=48JUh8Vlea4) - youtube
* [Morse Code Translator](https://morsecode.scphillips.com/translator.html)
* [Morse Code](https://en.wikipedia.org/wiki/Morse_code) - wikipedia
* [..as mentioned on my blog](http://blo.tardate.com/2017/09/leap342-esp8266-morse-blinky.html)
