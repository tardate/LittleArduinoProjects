# #340 IxpandO

IxpandO is an input/output expansion board based on Microchip's MCP23017, BoldportClub Project #16.
Demo program covers digital output and interrupt-driven input.

Here's a quick demo of it in action..

[![IxpandO_build](./assets/IxpandO_build.jpg?raw=true)](http://www.youtube.com/watch?v=hQaYeF7REU8)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

IxpandO is an input/output expansion board based on Microchip's MCP23017, BoldportClub Project #16.

The board design leaves the door open for various configurations.
I decided to go initially with the default setup of 8 inputs (switches) and 8 outputs (LEDs),
with an Arduino sketch to demonstrate digital output and interrupt-driven input.

The MCP23017 is the I²C variant of the chip.
See [LEAP#313](../../Electronics101/MCP23S17) for a similar demonstration of the MCP23S17 SPI variant.

## Parts and Unboxing

| Qty | Description                                                 |
|-----|-------------------------------------------------------------|
|  x1 | 16bit I²C IO expansion IC, Microchip MCP23017T-E/SO         |
|  x1 | 10µF 0805 SMD ceramic capacitor, Multicomp MC0805X106K160CT |
|  x1 | 1µF 0805 SMD ceramic capacitor, Multicomp MC0805F105Z160CT  |
|  x5 | 4.7KΩ 0805 SMD resistor, Multicomp MCWR08X4701FTL           |
|  x8 | red 0805 LEDs, Kingbright KPT-2012EC                        |
|  x8 | 1KΩ 0805 SMD resistor, Multicomp MCWR08X1001FTL             |
|  x1 | 8-wide DIP/SIP switch, Multicomp MCEMR-08-T                 |
|  x2 | 20-pin through-hole header, Multicomp MC34739               |
|  x2 | PCB                                                         |

![IxpandO_unboxing](./assets/IxpandO_unboxing.jpg?raw=true)


## Construction

The [IxpandO GitHub repository](https://github.com/boldport/ixpando) contains the full design of the Boldport board.
The following schematic is a transcription that includes:

* optional controller (in this case, an Arduino-compatible Cuttle)
* optional LEDs connected to bank B (GPB)
* optional DIP switches connected to bank A (GPA)

![IxpandO_soldered](./assets/IxpandO_soldered.jpg?raw=true)

![Schematic](./assets/IxpandO_schematic.jpg?raw=true)

![Schematic](./assets/IxpandO_bb.jpg?raw=true)


## About the MCP23017

The Microchip MCP23017 is a 16-bit port expender:

* 16 GPIO ports
* Configurable interrupt output pins
* High-speed I²C interface at up to 1.7 MHz (MCP23S17 is the SPI variant)
* Three hardware address pins to allow up to eight devices on the bus
* Operating voltage 1.8V to 5.5V
* Maximum source/sink current per pin: 25mA
* VSS max current: 150 mA
* VDD max current: 125 mA

Note the current limit gotcha: `16 x 25ma >> 125mA`, so care is required not to have too many pins fully loaded at once, or pins should only be used to switch larger currents (not provide power themselves).

### Key Commands

#### I²C Write

* send control byte including the Start condition and ACK (R/W bit cleared)
* send register address byte
* send at least one data byte
* send stop or restart condition

#### I²C Read

* send control byte including the Start condition and ACK (R/W bit set)
* send register address byte
* read at least one data byte
* send stop or restart condition

#### I²C Sequential Write/Read

For sequential read/write, instead of transmitting a Stop or Restart condition,
the master clocks the next byte(s) until finally sending a Stop or Restart condition.

The address used for sequential bytes depends on whether Byte and Sequential Mode is enabled.

### Byte and Sequential Modes

Byte Mode: internal address counter remains the same after each byte transfer.
Useful for polling the GPIO register or for continually writing to the output latches.

Sequential Mode: internal address counter remains the same after each byte transfer.
Useful for bulk writes without needing control bytes to set the address for each.

### Registers

There are 21 registers. Of these, 10 replicated in two banks, and one `IOCON` register is shared.


| Register   | Purpose                                                                                                   |
|------------|-----------------------------------------------------------------------------------------------------------|
| IOCON      | Device configuration register                                                                             |
| IODIRA/B   | Input configuration. Default: input                                                                       |
| IPOLA/B    | Input polarity. Default: same logic state as the pin itself                                               |
| GPINTENA/B | Configure Interrupt-on-change. Default: disabled.                                                         |
| DEFVALA/B  | Default values compare register.                                                                          |
| INTCONA/B  | Interrupt-on-change comparison configuration, sets compare to DEFVAL. Default: compare to previous value. |
| GPPUA/B    | Control pull-up settings. Default: Pull-up disabled                                                       |
| INTFA/B    | Interrupt flag register; shows interrupt status: Default: 0                                               |
| INTCAPA/B  | Interrupt capture register. contains value as captured at interrupt. Default: undefined                   |
| GPIOA/B    | Port register, reflects the value on the port. Default 0                                                  |
| OLATA/B    | Access to output latches                                                                                  |


## Test Program

The [IxpandO.ino](./IxpandO.ino) sketch demonstrates

* digital output to LEDs on bank B (GPB)
* interrupt-driven input for the DIP switch on bank A (GPA)

It uses the [Wire Library](https://www.arduino.cc/en/Reference/Wire) to directly control the MCP23017,
via standard I²C connections on PC5 (SCL), PC4 (SDA).

Changing any DIP switch position triggers INTA.
The sketch attaches a hardware interrupt handler for this input, which sets a flag on change.

When the flag is set, the sketch reads all the switch positions and acts accordingly.

The demo program has a very simple behaviour:

* when all switch positions are off, it runs a demo cycle on the LEDs
* if any switches are on, it lights the corresponding LED for all switch positions.


![IxpandO_build2](./assets/IxpandO_build2.jpg?raw=true)

## Credits and References
* [LEAP#313 MCP23S17](../../Electronics101/MCP23S17) - similar demonstration of the MCP23S17 SPI variant
* [Boldport IxpandO](https://www.boldport.com/products/ixpando) - official product page
* [MCP23017T-E/SO info and datasheet](http://www.microchip.com/wwwproducts/en/MCP23017)
* [Wire Library](https://www.arduino.cc/en/Reference/Wire)
* [..as mentioned on my blog](https://blog.tardate.com/2017/09/leap340-boldport-club-ixpando.html)

