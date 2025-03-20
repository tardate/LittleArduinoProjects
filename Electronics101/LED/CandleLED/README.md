# #715 Candle LED

A quick test and review of 5mm candle LEDs, that include a built-in candle flicker emulation.

![Build](./assets/CandleLED_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/wr0x2EaQKpM/0.jpg)](https://www.youtube.com/watch?v=wr0x2EaQKpM)

## Notes

Need to include some fake "candle flicker" in a display or decoration?
There are sophisticated ways of emulating candles,
but the simplest way is probably just to buy some of these 5mm LEDs that have a built-in candle flicker emulation.

They are widely available. For example, I obtained mine from this seller on aliexpress:
[100PCS 5mm LED Flicker Diodes Flashing Yellow Blinking Candle Light Emitting Diode](https://www.aliexpress.com/item/32782781815.html)

### Circuit Design

The Candle LEDs work fine from a 3V power supply, such as a CR2032 battery.
For higher voltages, a current limiting resistor should be added.

![bb](./assets/CandleLED_bb.jpg?raw=true)

![schematic](./assets/CandleLED_schematic.jpg?raw=true)

![bb_build](./assets/CandleLED_bb_build.jpg?raw=true)

## Credits and References

* [100PCS 5mm LED Flicker Diodes Flashing Yellow Blinking Candle Light Emitting Diode](https://www.aliexpress.com/item/32782781815.html) - a seller on aliexpress
