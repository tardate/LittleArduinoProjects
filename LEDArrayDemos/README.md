# Programmable LED Arrays

I bought some [WS2811-based LED Strips](http://www.aliexpress.com/item/IP68-12mm-WS2811-as-WS2801-led-pixel-module-IP68-waterproof-DC5V-full-color-RGB-50pcs-a/1932649085.html) with a specific project in mind. But first, need to get them working. Here are the first tests... all good so far!

* [RGBCalibrate](./RGBCalibrate) - quick test to make sure LEDs are correctly addressable and their color can be set correctly
* [StripTease](./StripTease) - demo a range of effects on the LED strip

## Notes


### Construction

![The Breadboard](./assets/LedArray_bb.jpg?raw=true)

![The Schematic](./assets/LedArray_schematic.jpg?raw=true)

![The Build](./assets/LedArray_build.jpg?raw=true)

## Credits and References
* [FastLED library](http://fastled.io)
* [WS2811-based LED array](http://www.aliexpress.com/item/IP68-12mm-WS2811-as-WS2801-led-pixel-module-IP68-waterproof-DC5V-full-color-RGB-50pcs-a/1932649085.html) - the particular LED array I have been using
* [Why do I see +1.5V on Din of a WS2811-based LED strip?](http://electronics.stackexchange.com/questions/141704/why-do-i-see-1-5v-on-din-of-a-ws2811-based-led-strip) - help from [geometrikal](http://electronics.stackexchange.com/users/6481/geometrikal) on [EE.SE](http://electronics.stackexchange.com/)
