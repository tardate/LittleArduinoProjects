# #599 IR Dumper

Reverse-engineering infrared protocols using the Arduino-IRremote library.

![Build](./assets/Dumper_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/video_id/0.jpg)](https://www.youtube.com/watch?v=video_id)

## Notes

__notes__

## IR Receiver

I'm using a CHO 1838 - compatible with the [TSOP1838](http://www.alldatasheet.com/datasheet-pdf/pdf/26604/VISHAY/TSOP1838.html)

| pin | function |
|-----|----------|
|  1  | data out |
|  2  | GND      |
|  3  | VCC (5V) |


## Construction

Just need the IR receiver connected to the Arduino Uno..

![bb](./assets/Dumper_bb.jpg?raw=true)

![schematic](./assets/Dumper_schematic.jpg?raw=true)

## Code

The [Dumper.ino](./Dumper.ino)
sketch is based on the ReceiveDump.cpp demo from the [Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote) library.

Point a remote control at the receiver and press a button. The full dump of the pack is echoed to the console:

![console](./assets/console.jpg?raw=true)


Arduino-IRremote library supported protocols:
Denon / Sharp, JVC, LG, NEC / Onkyo / Apple, Panasonic / Kaseikyo, RC5, RC6, Samsung, Sony, (Pronto), BoseWave, Lego, Whynter and optional MagiQuest.

## Credits and References

* [TSOP1838 datasheet](http://www.alldatasheet.com/datasheet-pdf/pdf/26604/VISHAY/TSOP1838.html) - one of many similar IR sensors
* [Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote) library
