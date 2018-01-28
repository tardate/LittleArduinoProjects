# #014 AsyncLedStripEffects

Demonstrates timer-interrupt triggering of addressable LED array effects using the [FlexiTimer2 library](https://github.com/wimleers/flexitimer2).

Here's a quick video of the demo:

[![AsyncLedStripEffects - using a timer interrupt to run effects on an LED array](http://img.youtube.com/vi/oE8yIUtl858/0.jpg)](http://www.youtube.com/watch?v=oE8yIUtl858)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

When running an animation sequence on an LED array, we don't want it upset by other processing on the Arduino.
This sketch uses the [FlexiTimer2 library](https://github.com/wimleers/flexitimer2) to drive the effect sequence from a timer interrupt.
That leaves the main loop() for doing other things.

### Construction

![The Breadboard](.././assets/LEDArrayDemos_bb.jpg?raw=true)

![The Schematic](.././assets/LEDArrayDemos_schematic.jpg?raw=true)

![The Build](.././assets/LEDArrayDemos_build.jpg?raw=true)

## Credits and References
* [FastLED library](http://fastled.io)
* [FlexiTimer2 library](https://github.com/wimleers/flexitimer2)
* [WS2811-based LED array](http://www.aliexpress.com/item/IP68-12mm-WS2811-as-WS2801-led-pixel-module-IP68-waterproof-DC5V-full-color-RGB-50pcs-a/1932649085.html) - the particular LED array I have been using
