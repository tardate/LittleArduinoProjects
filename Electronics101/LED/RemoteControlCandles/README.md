# #598 Remote Control Candles

Examining some intrared-controlled LED candles, reverse-engineering the control protocol, and making them dance to the tune of an Arduino.

![Build](./assets/RemoteControlCandles_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/6QYByzEzOsU/0.jpg)](https://www.youtube.com/watch?v=6QYByzEzOsU)

## Notes

Flickering LED candles are popping up all over the place.

I found a
[relatively cheap pack of 6 candles with infrared control](https://www.aliexpress.com/item/33050772893.html)
on aliexpress to play with.

After taking one apart to find how they tick, I was able to very easily capture the IR protocol
and so make a simple demonstration of how to control these candles with an Arduino.

## The Candles

The kit comes with multiple candles and an infrared control.
They are all powered by CR2032 batteries (included!). So far it seems that the battery life isn't great if you leave the candle on.

![kit_candles](./assets/kit_candles.jpg?raw=true)

The smarts of the candle are all in an 8-pin package - presumably a standard MCU of some description,
although in the volumes that these candles seem to be produced in, perhaps an ASIC could have been justified?

It is quite simple:

* an infrared receiver
* LED for candle effect
* a coil to repel the magnet in the "flame"

![kit_functional](./assets/kit_functional.jpg?raw=true)

## Reverse Engineering the IR Protocol

I used the ReceiveDump example from the
[Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote)
library, with a CHO 1838 intra-red receiver to capture the payload sent
for each buttin on the remote control.

The raw captures are in [protocol_decode.txt](./protocol_decode.txt).

This confirmed that the NEC protocol was being used with a series of 10 commands.
An empty (0x0) address is used, which makes sense as this is intended to "broadcast to all tea candles"!

The commands are as follows:

| Function | Address | Command | Raw Data 32 bits LSB first |
|----------|---------|---------|----------------------------|
| ON       | 0x0     | 0x0     | 0xFF00FF00 |
| OFF      | 0x0     | 0x2     | 0xFD02FF00 |
| Mode: Candle  | 0x0     | 0xC     | 0xF30CFF00 |
| Mode: Light   | 0x0     | 0xE     | 0xF10EFF00 |
| Dim (-)       | 0x0     | 0x10     | 0xEF10FF00 |
| Dim (+)       | 0x0     | 0x12     | 0xED12FF00 |
| Timer (2h)       | 0x0     | 0x4     | 0xFB04FF00 |
| Timer (4h)       | 0x0     | 0x6     | 0xF906FF00 |
| Timer (6h)       | 0x0     | 0x8     | 0xF708FF00 |
| Timer (8h)       | 0x0     | 0xA     | 0xF50AFF00 |


## Controlling with an Arduino

The protocol is very trivial - just 10 commands transmitted with the NEC protocol.
The
[Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote)
library can be used to send these commands from any MCO the library supports.
In this case I've just grabbed the nearest to hand - an Arduino Uno.

### Demo Scketch

The
[RemoteControlCandles.ino](./RemoteControlCandles.ino)
sketch is just a very simple sequence that demonstrates some of the basic commands - on, off, mode, dim.

It uses the
[Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote)
library to send comands in the correct NEC protocol format.

### Construction

We just need an infrared transmitter connected to a GPIO pin of the Arduino:

![bb](./assets/RemoteControlCandles_bb.jpg?raw=true)

![schematic](./assets/RemoteControlCandles_schematic.jpg?raw=true)

## Credits and References

* [Pack of 6 or 12 Remote or Not Remote Flameless Battery Candles,Realistic and Bright Flickering Fake Dancing Flame Tea lights](https://www.aliexpress.com/item/33050772893.html) - aliexpress
* [50pairs 3mm 940nm LEDs infrared emitter and IR receiver diodes](https://www.aliexpress.com/item/32837187714.html) - aliexpress
* [Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote) library
* [TSOP1838 datasheet](http://www.alldatasheet.com/datasheet-pdf/pdf/26604/VISHAY/TSOP1838.html) - one of many similar IR sensors
