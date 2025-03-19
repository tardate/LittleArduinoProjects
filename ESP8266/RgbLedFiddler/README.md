# #586 RGB LED Fiddler

Using an HTML5 color picker on a web page hosted from an ESP8266 module (ESP12) to fine tune the color settings for an RGB LED.

![Build](./assets/RgbLedFiddler_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/m-5TxikA3sQ/0.jpg)](https://www.youtube.com/watch?v=m-5TxikA3sQ)

## Notes

RGB LEDs contain individually driven red, green and blue LEDs in one diffuser package.
The can be driven very easily with PWM to produce a range of colors.

Plain red, green and blue are easy, but when trying to mix colors the exact color produced for a given combinations of red, green and blue
does not always follow what one might expect!

If the exact mixed color produced is important in an application
then the best way to "calibrate" the LED is to try it!

This project is a simple device based on an ESP8266 (ESP12 variant) that allows interactive control of the LED
using an HTML5 color picker on a web page.

NB: the reason why I built this was to figure out the best approximation of "brown" - the answer that works best for me is rgb(22,8,0). Not what standard color theory would have predicted (something more like rgb(170,121,65)).

## Construction

Since the RGB LED elements have differing forward voltages, varying the current limiting resistors is the first step to mixing colors with relatively equal intensity. BAsed on suggestions I've seen online, and from some trial and error, I've settled on the following combination as a good default:

* Red: 1.5kΩ
* Green: 1.2kΩ
* Blue: 680Ω

Since I'm using a common anode RGB LED, the controlling PWM pins will actually be "sinking" current. PWM duty cycle calculations in code take this into account by inverting the period i.e. intending to have the LED 75% "on" requires a PWM duty cycle of 25%.

The maximum current that can be drawn from a single GPIO pin is 12mA. Even when fully on, the worst case we should expect to draw is [4.9mA](https://www.wolframalpha.com/input/?i=3.3V%2F680%CE%A9), so there is no problem driving the LED directly from the ESP GPIO pins i..e no need to switch via a MOSFET or BJT.

The circuit itself is very simple:

* regulated 3.3V power supply - here I'm using an LD1117 with some smoothing capacitors so I can easily drive from battery or random DC power supply
* RGB LED connections to selected GPIO pins
* a pull-up resistor for the RESET line
* the ESP12 adapter board already provides "boot from SD card" GPIO15 pull down, and chip enable pull-up resistors

![Breadboard](./assets/RgbLedFiddler_bb.jpg?raw=true)

![Schematic](./assets/RgbLedFiddler_schematic.jpg?raw=true)

![Breadboard Build](./assets/RgbLedFiddler_bb_build.jpg?raw=true)

### Programming the ESP8266

I'm using the ESP8266 core for Arduino and the Arduino IDE to program the ESP-12 module.
Programming is done on the [LEAP#540 DIY Dev Board](../ESP12/DIYDevBoard).

To compile the sources, two things to remember:

* Before compiling, use the `update_index_page.rb` script to regenerate the index page content if `page_design.html` has been modified
* Copy `settings.h.template` to `settings.h` and fill in the WiFi access credentials before compiling (`settings.h` is excluded from the repository and is not shared).

## The Web Page

I used a stand-along web page - [page_design.html](./page_design.html) - for mocking up the web page, styling and Javascript.
When I have it "just right", the page content is copied into [index_page.h](./index_page.h) for compilation.

NB: I used the [update_index_page.rb](./update_index_page.rb) script to reformat `page_design.html` and generate `index_page.h` automatically.

```sh
$ ./update_index_page.rb
Generating index_page.h from page_design.html...
...done!
```

## Running the RGB Fiddler

The ESP8266 using mDNS to register itself on the local network. Simply browsing to [http://rgb-fiddler.local/](http://rgb-fiddler.local/)
will load the web page from the device, and then one can start controlling the LED:

![demo](./assets/demo.jpg?raw=true)

The Javascript events triggered by the HTML5 color picker are intercepted, and the new values posted to the ESP8266 on each change.

## Credits and References

* [ESP-12E ESP8266 module](https://www.aliexpress.com/item/32339917567.html) - from an aliexpress seller
* [ESP-12E adapter board](https://www.aliexpress.com/item/32649040259.html) - from an aliexpress seller
* [RGB LED Common anode](https://www.aliexpress.com/item/1895398667.html) - example from an aliexpress seller
* [LD1117 datasheet](http://pdf1.alldatasheet.com/datasheet-pdf/view/173710/UTC/LD1117AL-15-TA3-A-R.html)
