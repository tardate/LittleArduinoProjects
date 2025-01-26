# #480 7-Segment LED Displays

All about LED 7-segment displays...

![Build](./assets/LED7Segment_build.jpg?raw=true)

## Notes

There is a huge range of 7-segment LED displays in the market.
Although basically the same, they vary in critical ways:

* common anode or common cathode configuration
* arrangement of pins
* size, LED colour and forward voltage

The basic unit will have 10 pins, and comprise 7 LED segments plus a decimal point and a common anode or cathode.

Although pin assignments vary, they all operate in a similar manner:

* the "common anode"/"common cathode" terminology basically indicates the polarity of the circuit. Common cathode means all the LED segments share a common cathode (negative pole) and are switched on by pulling segment pins high.


### LED 7-Segment Components

The 7-segment components I have are similar to the [SC56-11](./assets/SC56-11_datasheet.pdf?raw=true).

![SC56-11_mechanical](./assets/SC56-11_mechanical.jpg?raw=true)

| Segment  | SC56-11 pin |
|----------|-------------|
| a        | 7           |
| b        | 6           |
| c        | 4           |
| d        | 2           |
| e        | 1           |
| f        | 9           |
| g        | 10          |
| dp       | 5           |

## Credits and references

* [SC56-11 Datasheet](../../assets/SC56-11_datasheet.pdf?raw=true)
