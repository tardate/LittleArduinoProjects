# #209 LedPanelDisplay72R02

Test 7-digit & 7-status indicator LED display

[![LedPanelDisplay72R02](http://img.youtube.com/vi/dPpyn7SVoBo/0.jpg)](http://www.youtube.com/watch?v=dPpyn7SVoBo)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

I found this interesting LED display at Sim Lim Tower at SGD$3 each, and grabbed one to test.
It seems there's at least one seller on aliexpress where you can get them in bulk at USD$0.52 each.

It is marked as "72R02PHIL T9717". I have no idea what that means(!), and of course there's no sign of a datasheet on the net,
so pinouts needed a bit of reverse-engineering.

![72R02_front](./assets/72R02_front.jpg?raw=true)

The LED unit combines 7 x 7-segment display (no decimal points) and 7 indicator LEDs (Red-Green-Yellow).

All in all, an interesting display unit for a combination of numerical and status display.

### 72R02 Pin Definitions

Counting pins from the conventional bottom-left, here's how it works.

The LED digits are common cathod configuration with seven individual segments.
I'll label the segments conventionally as follows:

    +- A -+
    F     B
    +- G -+
    E     C
    +- D -+

I'll reference the seven digits from right to left as D1, D2 to D7.
Each digit has a common cathode pin for all segments in the digit.

The 7 digits are all controlled with the top row of 14 pins: 7 segment anodes and 7 digit cathodes (though not in a neat order like that).

Standard multiplexing is required e.g. pull the cathode for the digit low and pull desired segments high. Repeat for each digit faster than the eye can see.

The status indicators are interesting. Its actual three pairs and one solo LED, all individually controlled with their own anode/cathode pins.

From the left, I've designated the LED status indicators as follows:

| Label | Colour |
|-------|--------|
| Db    | Yellow |
| Da    | Yellow |
| Cb    | Red    |
| Ca    | Red    |
| Bb    | Green  |
| Ba    | Green  |
| Aa    | Green  |

So rolling it all together, here's my pin function mapping:

| Pin | Digit Cathode | Segment Anode | Status Anode | Status Cathode |
|-----|---------------|---------------|--------------|----------------|
|  1  |               |               |              |  Db            |
|  2  |               |               |  Db          |                |
|  3  |               |               |              |  Da            |
|  4  |               |               |  Da          |                |
|  5  |               |               |              |  Cb            |
|  6  |               |               |  Cb          |                |
|  7  |               |               |              |  Ca            |
|  8  |               |               |  Ca          |                |
|  9  |               |               |              |  Bb            |
|  10 |               |               |  Bb          |                |
|  11 |               |               |              |  Ba            |
|  12 |               |               |  Ba          |                |
|  13 |               |               |              |  Aa            |
|  14 |               |               |  Aa          |                |
|  15 |               | D             |              |                |
|  16 |               | E             |              |                |
|  17 | D1            |               |              |                |
|  18 |               | F             |              |                |
|  19 | D2            |               |              |                |
|  20 |               | B             |              |                |
|  21 | D3            |               |              |                |
|  22 | D4            |               |              |                |
|  23 | D5            |               |              |                |
|  24 |               | A             |              |                |
|  25 | D6            |               |              |                |
|  26 |               | G             |              |                |
|  27 | D7            |               |              |                |
|  28 |               | C             |              |                |


#### SPI Bit Order

Here's a summary of how the bits in the shift register are mapped to LED segments in my build.
This sequencing is quite arbitrary of course. I selected this mapping primarily to make breadboard wiring a bit easier.

| Register | Bit | Function       |
|----------|-----|----------------|
| 1        |  0  | Aa enable HIGH |
| 1        |  1  | Ba enable HIGH |
| 1        |  2  | Bb enable HIGH |
| 1        |  3  | Ca enable HIGH |
| 1        |  4  | Cb enable HIGH |
| 1        |  5  | Da enable HIGH |
| 1        |  6  | Db enable HIGH |
| 1        |  7  | unused         |
| 1        |  0  | unused         |
| 1        |  1  | A enable HIGH  |
| 1        |  2  | B enable HIGH  |
| 1        |  3  | C enable HIGH  |
| 1        |  4  | D enable HIGH  |
| 1        |  5  | E enable HIGH  |
| 1        |  6  | F enable HIGH  |
| 1        |  7  | G enable HIGH  |
| 2        |  0  | unused         |
| 2        |  1  | D1 enable LOW  |
| 2        |  2  | D2 enable LOW  |
| 2        |  3  | D3 enable LOW  |
| 2        |  4  | D4 enable LOW  |
| 2        |  5  | D5 enable LOW  |
| 2        |  6  | D6 enable LOW  |
| 2        |  7  | D7 enable LOW  |


### Demo Code

Control of the unit is encapsulated in the [Display72R02](./display_72R02.h) class, with functions to set the status indicators and individual digits.

The [LedPanelDisplay72R02.ino](./LedPanelDisplay72R02.ino) sketch runs a series of demos.

## Construction

![Breadboard](./assets/LedPanelDisplay72R02_bb.jpg?raw=true)

![The Schematic](./assets/LedPanelDisplay72R02_schematic.jpg?raw=true)

![The Build](./assets/LedPanelDisplay72R02_build.jpg?raw=true)

## Credits and References
* [72R02 units available from a seller on aliexpress](http://www.aliexpress.com/item/Free-shipping-72R02PHIL-72R02-SMD28-new-imported-genuine-price-of-consultation/32518312413.html?spm=2114.01010208.3.2.iJ0ewF&ws_ab_test=searchweb201556_0,searchweb201602_3_10034_507_10032_10020_10017_10005_10006_10021_10022_10009_10008_10018_10019,searchweb201603_1&btsid=b0fc14c4-1c12-4987-9f61-bf519154bbb4)
* [Arduino SPI library](https://www.arduino.cc/en/Reference/SPI)
* [SPI Clock polarity and phase](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus#Clock_polarity_and_phase) - wikipedia
* [74HC595 Datasheet](https://www.nxp.com/documents/data_sheet/74HC_HCT595.pdf) - NXP
* [..as mentioned on my blog](http://blog.tardate.com/2016/07/littlearduinoprojects209-funky-little.html)
