# #189 LED7Segment/ShiftDriveSPI

Using SPI to control a 7-segment display via a 74HC595 shift register.


## Notes

In previous projects like [ShiftDrive](../ShiftDrive), the code has directly implemented the clock, latching and data transfer protocol expected by the 74HC595 shift register.

It's also possible to control the 74HC595 shift register using hardware SPI.
Although this doesn't simplify the code or necessarily affect performance much,
it does allow for expansion.

This sketch is a modification of [ShiftDrive](../ShiftDrive) to control the [ShiftDriveModule](../ShiftDriveModule) via SPI.

### SPI pin mapping

Here's how the 595 register pins relate to SPI. The Arduino pins are for an Uno -
see the [SPI](https://www.arduino.cc/en/Reference/SPI) reference page for details for other boards.

| 74HC595          | SPI  | Description         | Arduino Uno SPI Pin |
|------------------|------|---------------------|---------------------|
| DATA (DS, 14)    | MOSI | Master Out Slave In | 11                  |
| n/a              | MISO | Master In Slave Out | 12                  |
| CLOCK (SH_CP,11) | SCLK | Serial Clock        | 13                  |
| n/a              | SS   | Slave Select (in)   | 10                  |
| LATCH (ST_CP,12) | SS   | Slave Select (out)  | any free pin        |

### SPI Settings

Although default [SPI settings ](https://www.arduino.cc/en/Reference/SPISettings) may work, let's check. There are three factors:

* maximum speed
* bit order
* mode

#### SPI Max Speed

The [74HC595 Datasheet](https://www.futurlec.com/74HC/74HC595.shtml) indicates typical maximum clock frequency for the 74HC is 100MHz. OK, we'll never get near that with a 16MHz Arduino, so anything goes. There may be reasons to do with the specific circuit to throttle the clock, but in this case it's not a factor.

#### SPI Bit Order

Here's a summary of how the bits in the shift register are mapped to LED segments in my build:

| Bit | Segment                    |
|-----|----------------------------|
|  0  |  A - top horizontal        |
|  1  |  B - top right vertical    |
|  2  |  C - bottom right vertical |
|  3  |  D - bottom horizontal     |
|  4  |  E - bottom left vertical  |
|  5  |  F - top left vertical     |
|  6  |  G - center  horizontal    |
|  7  |  dp - decimal point        |

However the [code](./ShiftDriveSPI.ino) uses bytes to represent dp,G,F..A from MSB to LSB,
so I use MSBFIRST transfer.

#### SPI Mode

[SPI modes](https://www.arduino.cc/en/Reference/SPI) define the [clock polarity and phase](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus#Clock_polarity_and_phase).
The timing diagram in the [74HC595 Datasheet](https://www.futurlec.com/74HC/74HC595.shtml)
shows:

* base clock polarity is 0 (CPOL=0)
* data captured on the clock's falling edge and data is output on a rising edge (CPHA=1)

This is "mode 0", aka SPI_MODE0.

## Construction

![Breadboard](./assets/ShiftDriveSPI_bb.jpg?raw=true)

![The Schematic](./assets/ShiftDriveSPI_schematic.jpg?raw=true)

![The Build](./assets/ShiftDriveSPI_build.jpg?raw=true)

## Credits and References

* [Arduino SPI library](https://www.arduino.cc/en/Reference/SPI)
* [SPI Clock polarity and phase](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus#Clock_polarity_and_phase) - wikipedia
* [74HC595 Datasheet](https://www.futurlec.com/74HC/74HC595.shtml)
* [Sharing Clock and Data for 74HC595 and CD4021B Shift Registers?](http://electronics.stackexchange.com/questions/122520/sharing-clock-and-data-for-74hc595-and-cd4021b-shift-registers) - electronics.stackexchange
* [Driving 595 Shift Registers](http://www.appelsiini.net/2012/driving-595-shift-registers) - good article with AVR implementation details
* [Using Serial Peripheral Interface (SPI) Master and Slave with Atmel AVR Microcontroller](http://www.ermicro.com/blog/?p=1050) - well explained code
