# #428 3x7/LRThreeDigitDemo

Driving the Boldport 3x7 display from a Cuttle (Arduino) and the LRThreeDigits library.

![Build](./assets/LRThreeDigitDemo_build.jpg?raw=true)

Here's a quick demo..

[![clip](http://img.youtube.com/vi/jZhk5e8Uii4/0.jpg)](http://www.youtube.com/watch?v=jZhk5e8Uii4)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

LuckResistor published the
[LRThreeDigits](https://github.com/LuckyResistor/LRThreeDigits)
library for driving the [Boldport 3x7](../) with an Arduino or compatible.

The [LRThreeDigitDemo.ino](./LRThreeDigitDemo.ino) sketch is just a
quick test drive of the library.

## Using the Library

The main things to note is that the library:

* uses Timer2 for display refresh
* mandates the pin connections per the following table


| Arduino Pin  | Project Pin       |
| ------------ | ----------------- |
| GND          | GND               |
| Pin 2        | Digit 1 Sink      |
| Pin 3        | Digit 2 Sink      |
| Pin 4        | Digit 3 Sink      |
| Pin 5        | Segment g         |
| Pin 6        | Segment f         |
| Pin 7        | Segment e         |
| Pin 8        | Segment d         |
| Pin 9        | Segment c         |
| Pin 10       | Segment b         |
| Pin 11       | Segment a         |


## Construction

![Breadboard](./assets/LRThreeDigitDemo_bb.jpg?raw=true)

![Schematic](./assets/LRThreeDigitDemo_schematic.jpg?raw=true)

![Build](./assets/LRThreeDigitDemo_build.jpg?raw=true)

## Credits and References
* [LEAP#425 Boldport 3x7](../)
* [LRThreeDigits](https://github.com/LuckyResistor/LRThreeDigits) library
