# #540 ESP-12 DIY Dev Board

Building a programming board for the ESP8266 07/12 variants.

![Build](./assets/DIYDevBoard_build.jpg?raw=true)

## Notes

I have some ESP8266 modules in the ESP-7 and [ESP-12E](https://www.aliexpress.com/item/32339917567.html) variants.
They both work with [adapter boards](https://www.aliexpress.com/item/32649040259.html) like this.

However, it turns out that programming them on a breadboard can be a bit flakey - mainly due to power/connection issues.

So I decided to try a quick build of a programming board to see if performance was more reliable.

The result - excellent. Very reliable programming.

## Circuit Design

The circuit implements the [recommended](https://tttapa.github.io/ESP8266/Chap02%20-%20Hardware.html) programming/runtime
circuit. Note that some of the pull-up resistors are actually on the
[adapter board](https://www.aliexpress.com/item/32649040259.html) - these are marked as "built-in" in the schematic.

![Breadboard](./assets/DIYDevBoard_bb.jpg?raw=true)

![Schematic](./assets/DIYDevBoard_schematic.jpg?raw=true)

## Protoboard Construction

I used a piece of 5x7cm protoboard, with the circuit layed out as follows:

![build_layout](./assets/build_layout.jpg?raw=true)

Some quick and dirty soldering..

![build_back](./assets/build_back.jpg?raw=true)

Final build, on a cardboard base:

![build_front](./assets/build_front.jpg?raw=true)

## Credits and References

* [ESP-12E](https://www.aliexpress.com/item/32339917567.html) - aliexpress seller
* [ESP-7/12 adapter boards](https://www.aliexpress.com/item/32649040259.html) - aliexpress seller
* [ESP8266 Arduino Core - boards doc](https://arduino-esp8266.readthedocs.io/en/2.6.3/boards.html)
* [ESP-01/07/12 Series Modules User's Manual](http://wiki.ai-thinker.com/_media/esp8266/esp8266_series_modules_user_manual_v1.1.pdf)
* [ESP8266 Hardware](https://tttapa.github.io/ESP8266/Chap02%20-%20Hardware.html) - A Beginner's Guide to the ESP8266
