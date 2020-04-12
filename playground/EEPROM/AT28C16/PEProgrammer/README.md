# #314 EEPROM/AT28C16/PEProgrammer

Programming an AT28C16 EEPROM with an Arduino and MCP23S17 16-bit port expander.

![Build](./assets/PEProgrammer_build.jpg?raw=true)

## Notes

The AT28C16 is an old-school 2k x 8-bit parallel EEPROM. Since it has parallel addressing and data lines,
it opens a whole range of possibilities with discrete logic circuits (i.e. no SPI or I²C in sight).
I was inspired to explore more by [Ben Eater's use of EEPROMs for his 8-bit computer build](https://youtu.be/K88pgWhEb1M).

This project is a first attempt at an Arduino-driven programmer (for read and write).

Now parallel means many lines to control - 22 in total (11 address, 8 data, 3 control signals).
That's more than a humble Arduino Uno provides. Possibilities for handling that many signals:

* use a Mega or other variant with many more GPIOs
* use shift registers to expand the bus. This is the technique that Ben Eater used.
* use a port expander

In this case, I'm going to use a single MCP23S17 16-bit port expander.
That still means I'm short 6 pins, but I'll drive those directly from the Arduino. I could have used two port expanders to handle all the I/O -
perhaps I'll try that variation later. See [LEAP#313](../../../../Electronics101/MCP23S17) for more on the MCP23S17.


### About the AT28C16

![AT28C16_block_diagram](../assets/AT28C16_block_diagram.png?raw=true)

![AT28C16_pin_configuration](../assets/AT28C16_pin_configuration.png?raw=true)

#### Addressing

Memory is addressed with pins A0-A10 (11 bits), representing a range of 0 to 0x7FF (2047).
Hence the 16k capacity (2048 x 8 bits)

#### Read Operation

The AT28C16 is accessed like static RAM.
When CE and OE are low and WE is high, the data stored at the memory location determined by the address pins is asserted on the outputs.

| Pin    | State                |
|--------|----------------------|
| CE     | low                  |
| OE     | low                  |
| WE     | high                 |
| A0-10  | memory address input |
| IO0-7  | data output          |

The outputs are put in a high impedance state whenever CE or OE is high.

#### Write Operation

Writing data is triggered when OE is high and either WE or CE pulse low (with the other set low).
I'll be using WE, so that means CE does not need to change state between read and write.

| Pin    | State                                                       |
|--------|-------------------------------------------------------------|
| CE     | low                                                         |
| OE     | high                                                        |
| WE     | pulse high->low->high                                       |
| A0-10  | memory address input latched on the last falling edge of WE |
| IO0-7  | data input latched on the first rising edge of WE           |

Internally, the device performs a self-clear before write. Once a byte write has been started, it will automatically time itself to completion.

#### Device Identification

The chip provides 32 bytes of device identification memory between addresses 0x7E0 to 0x7FF.

I haven't tried reading or writing the device info yet, but this is how I believe it works:

To read or write these addresses, A9 needs to be raised to 12 ± 0.5V. Note that only the OE and A9 pins are tolerant of voltages to 13.5V.
All other pins have maximum ratings of -0.6V to +6.25V with respect to ground.

If A9 is raised to normal voltages (to +6.25V), then the normal memory between 0x7E0 to 0x7FF is accessed for read and write.


### PEProgrammer Sketch

The [PEProgrammer.ino](./PEProgrammer.ino) sketch is controlled via the serial port. It can:

* read and echo selected memory ranges
* write data to a specified address
* fill a memory range with a specified value

Here's an example session reading and writing selected data:

![console_read_write_fill_example](./assets/console_read_write_fill_example.png?raw=true)


## Construction

![Breadboard](./assets/PEProgrammer_bb.jpg?raw=true)

![Schematic](./assets/PEProgrammer_schematic.jpg?raw=true)

![Build](./assets/PEProgrammer_build.jpg?raw=true)

## Credits and References

* [AT28C16 datasheet](http://www.atmel.com/images/doc0540.pdf)
* [MCP23S17 datasheet and info](http://parts.io/detail/1371552/MCP23S17-E%2FSS) - parts.io
* [Build an Arduino EEPROM programmer](https://youtu.be/K88pgWhEb1M) - Ben Eater; similar circuit but using shift registers
* [beneater/eeprom-programmer](https://github.com/beneater/eeprom-programmer)
* [LEAP#313 MCP23S17](../../../../Electronics101/MCP23S17) - using the MCP23S17 port expander
* [Arduino Serial Reference](https://www.arduino.cc/en/Reference/Serial)
* [AVR <stdio.h>: Standard IO facilities](http://www.nongnu.org/avr-libc/user-manual/group__avr__stdio.html)
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap314-at28c-eeprom-programmer-with-port-expander.html)
