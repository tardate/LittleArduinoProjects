# Simple4Digit7SegmentDisplay

Drives a 4-digit 7-segment display.

## Notes

There are a number of similar 4-digit 7-segment LED displays in the market.
Although basically the same, they vary in critical ways:
* common anode or common cathode configuration
* number and assignment of pins

The basic unit will have 12 pins, and each "digit" will comprise 7 LED segments plus a decimal point.
Units are also available with 14 or 16 pins.
The additional pins are used to control punctuation and other effects such as the colon typically used
in 12/24 hour clock displays.

Although pin assignments vary, they all operate in a similar manner:
* a pin is common to a specific LED segment that is repeated across all digits e.g. pin 8 = "top bar of the digit"
* another pin is common to all elements in a given digit e.g. pin 6 = "all elements in the first digit"
* creating (powering) a circuit across the two pins will light the selected segment in the selected digit
* the "common anode"/"common cathode" terminology basically indicates the polarity of the circuit. Common cathode means

### SMA420564
So much for theory; the hardest thing tends to be finding the right datasheet!
I was unable to find a datasheet matching the part I have - stamped as an "SMA420564" -
but figuring it out just takes a little poking around with a 5V + resistor probe.
Here's my 'reverse-engineered' datasheet:

It's a 4-digit common cathode unit, with the common cathode for each digit on pins 7,10,11,6.

The anode connections for each segment are mapped in the folliwng table.
The LED segments are labelled clockwise from A (top bar) to F (top left bar); G is the centre bar; and 'dp' is the decimal point segment after the digit:

|Digit: | D1| D2| D3| D4|
|pin +\-| 7 | 10| 11| 6 |
|-------|---|---|---|---|
| 1     | E | E | E | E |
| 2     | D | D | D | D |
| 3     | dp| dp| dp| dp|
| 4     | C | C | C | C |
| 5     | G | G | G | G |
| 8     | A | A | A | A |
| 9     | F | F | F | F |
| 12    | B | B | B | B |

### Test Circuit

While you can wire up each segment pin to a digital out on the Arduino, it soon becomes pretty wasteful of pins.
A 74HC595 is used to shift out the segment values in a block, requiring only 3 pins.

NPN BJTs are used to switch the sinking of each digit's common cathode connection.
In this circuit, the BJTs are directly controlled with an additional 4 pins.

This circuit puts the resistors in series of the common cathode pins. Which is a bit of an approximation,
as current (brightness) varies a little depending on how many LED segments are on.
The better way is to put a resistor on each segment pin. But this was good enough for a simple test.


### Construction

![The Breadboard](./assets/Simple7SegmentDisplay_bb.jpg?raw=true)

![The Schematic](./assets/Simple7SegmentDisplay_schematic.jpg?raw=true)

![The Build](./assets/Simple7SegmentDisplay.jpg?raw=true)

## Credits and references
* [KW4-561 Datasheet](http://www.sme.com.hk/globetec/LED%20Displays/Four%20Digit%20Display/KW4-561.pdf) - not matching the part I have, but a pretty stanrd example
* a good [How to.. question at EE.SE](http://electronics.stackexchange.com/questions/34815/using-4-digit-7-segment-led)


http://www.instructables.com/id/4-Digit-7-Segment-LED-Display-Arduino/
http://www.adafruit.com/datasheets/BL-Q39A-42.PDF
http://www.hobbytronics.co.uk/arduino-4digit-7segment




