# #014 LED Array Async Effects

Demonstrates timer-interrupt triggering of addressable LED array effects using the [FlexiTimer2 library](https://github.com/wimleers/flexitimer2).

Here's a quick video of the demo:

[![AsyncLedStripEffects - using a timer interrupt to run effects on an LED array](https://img.youtube.com/vi/oE8yIUtl858/0.jpg)](https://www.youtube.com/watch?v=oE8yIUtl858)

## Notes

When running an animation sequence on an LED array, we don't want it upset by other processing on the Arduino.
This sketch uses the [FlexiTimer2 library](https://github.com/wimleers/flexitimer2) to drive the effect sequence from a timer interrupt.
That leaves the main loop() for doing other things.

See [LEAP#007 Programmable LED Arrays](../) for full description and circuit notes.

### Construction

Designed with Fritzing: see [LEDArrayDemos.fzz](../LEDArrayDemos.fzz).

![The Breadboard](.././assets/LEDArrayDemos_bb.jpg?raw=true)

![The Schematic](.././assets/LEDArrayDemos_schematic.jpg?raw=true)

![The Build](.././assets/LEDArrayDemos_build.jpg?raw=true)

### The Sketch

See [AsyncLedStripEffects.ino](./AsyncLedStripEffects.ino).

## Credits and References

* [LEAP#007 Programmable LED Arrays](../)
* [FastLED library](http://fastled.io)
* [FlexiTimer2 library](https://github.com/wimleers/flexitimer2)
* ["IP68 12mm WS2811 as WS2801 led pixel module,IP68 waterproof DC5V full color RGB 50pcs a string christmas LED light Addressable" (aliexpress seller listing)](https://www.aliexpress.com/item/1932649085.html)
    * Purchased for US$17.94 (Aug-2014)
    * No longer available from this seller
