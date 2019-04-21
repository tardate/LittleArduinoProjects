# #361 TFT/Color128x128

Testing a 128x128 colour TFT LCD with a couple of different Arduino libraries.

![Build](./assets/Color128x128_build.jpg?raw=true)

## Notes

I dug out a [1.44 inch Serial 128*128 SPI Color TFT LCD Module](https://www.aliexpress.com/item/5PCS-1-44-inch-TFT-LCD-module-SPI-serial-module-LCD-color-screen-only-4-IO/32805698103.html) from my parts drawer as a possible display for a project I'm working on. First .. put it to the test.

It appears to be an ILI9163C type display, as covered in
[this excellent tutorial](http://henrysbench.capnfatz.com/henrys-bench/arduino-displays/arduino-1-44-in-spi-tft-display-tutorial/)
from Henry's Bench. That's done properly with 5v-3.3V level shifters but here I cheated to see if it would actually work without blowing up on 5V.

Although it does appear to work just fine on 5V, it is probaby not a good idea for long-term operation.
Although I cannot find any specifications for the TFT screen I have, it is a good bet that it is specified for 3.3V.

![Color128x128_screen_front](./assets/Color128x128_screen_front.jpg?raw=true)
![Color128x128_screen_rear](./assets/Color128x128_screen_rear.jpg?raw=true)

### Demo Programs

I'm testing a couple of libraries using a simple text display program that does three things:

* sets the background color
* writes some text at specific positions
* updates a counter at a fixed position every 500ms

Here's a quick demo of the two examples in action:

[![cWvAZ91qQys](https://img.youtube.com/vi/cWvAZ91qQys/0.jpg)](https://www.youtube.com/watch?v=cWvAZ91qQys)


#### [ArduinoTFTDemo.ino](./ArduinoTFTDemo/ArduinoTFTDemo.ino)

The standard Arduino TFT library compiles down to some fairly compact images, but it does
require a bit of wrangling to output numbers.

```
Sketch uses 7936 bytes (24%) of program storage space. Maximum is 32256 bytes.
Global variables use 134 bytes (6%) of dynamic memory, leaving 1914 bytes for local variables. Maximum is 2048 bytes.
```

#### [TFT_ILI9163C_Demo.ino](./TFT_ILI9163C_Demo/TFT_ILI9163C_Demo.ino)

The TFT_ILI9163C library appears to have some nice features for this specific type of display, but it does generate a program
image that is a little larger.

```
Sketch uses 8306 bytes (25%) of program storage space. Maximum is 32256 bytes.
Global variables use 163 bytes (7%) of dynamic memory, leaving 1885 bytes for local variables. Maximum is 2048 bytes.
```

### Construction

![Breadboard](./assets/Color128x128_bb.jpg?raw=true)

![Schematic](./assets/Color128x128_schematic.jpg?raw=true)

![Build](./assets/Color128x128_build.jpg?raw=true)

## Credits and References
* [1.44 inch Serial 128*128 SPI Color TFT LCD Module](https://www.aliexpress.com/item/5PCS-1-44-inch-TFT-LCD-module-SPI-serial-module-LCD-color-screen-only-4-IO/32805698103.html) - example from aliexpress seller
* [Arduino TFT](https://www.arduino.cc/en/Guide/TFT)
* [Arduino 1.44 in SPI TFT Display Tutorial](http://henrysbench.capnfatz.com/henrys-bench/arduino-displays/arduino-1-44-in-spi-tft-display-tutorial/)
* [TFT_ILI9163C Library](https://github.com/sumotoy/TFT_ILI9163C)
* [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library)
* [Arduino TFT Library Guide](https://www.arduino.cc/en/Guide/TFT)
* [Arduino TFT Library](https://www.arduino.cc/en/Reference/TFTLibrary)
* [..as mentioned on my blog](https://blog.tardate.com/2017/12/leap361-128x128-tft-lcds.html)
