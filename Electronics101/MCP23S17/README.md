# #313 MCP23S17

Investigate and test the MCP23S17 16-Bit I/O Expander with serial interface.

Here's a quick video of the demo in action..

[![Build](./assets/MCP23S17_build.jpg?raw=true)](https://www.youtube.com/watch?v=CuNJYUojNe0)

## Notes

The Microchip MCP23S17 is a 16-bit port expender:

* 16 GPIO ports
* Configurable interrupt output pins
* SPI interface at up to 10 MHz (MCP23017 is the I²C variant)
* Three hardware address pins to allow up to eight devices on the bus
* Operating voltage 1.8V to 5.5V
* Maximum source/sink current per pin: 25mA
* VSS max current: 150 mA
* VDD max current: 125 mA

Note the current limit gotcha: `16 x 25ma >> 125mA`, so care is required not to have too many pins fully loaded at once, or pins should only be used to switch larger currents (not provide power themselves).

### Key Commands

#### SPI Write

* lower CS
* send control byte (R/W bit cleared)
* send register address byte
* send at least one data byte
* raise CS

#### SPI Read

* lower CS
* send control byte (R/W bit set)
* send register address byte
* read at least one data byte
* raise CS

#### SPI Sequential Write/Read

For sequential read/write,  instead of deselecting the device after read/write by raising CS, the master clocks the next byte(s)
until finally raising CS.

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


### Test Program

There are a number of libraries already available for the MCP23S17 (see links in references), but I wanted to start with a directly programmed example.

The [MCP23S17.ino](./MCP23S17.ino) uses the standard Arduino SPI library to exercise the MCP23S17. The example does a few things:

* toggles an output pin on each port to control two LEDs (they oscillate on and off)
* configures an interrupt on one of the ports and routes it to one of the Arduino hardware interrupts
* when the interrupt is triggered, toggles the state of a third LED

It exercises pretty much all of the MCP23S17 capabilities:

* register writes
* register reads
* sequentential write operations
* interrupt handling
* input and output port configurations


#### Interrupt Handling

A pushbutton connected to GPA1 is used to trigger the interrupt. It uses an external pull-up, so the default input is high, and the interrupt should trigger on the falling edge.

The interrupt handling is configured:

* per IOCON register: Active-low; Active driver output; INTA is associated with PortA.
* per INTCONA: configured to trigger when input is different from DEFVALA value
* per DEFVALA: expected in put is high
* per GPINTENA: interrupts enabled for GPA1

Thus, the interrupt is triggered when the GPA1 (normally pulled high) falls to low.

The INTA output is fed to pin 2 of the Arduino, which has a falling-edge interrupt handler attached.

The result:

* INTA output is normally high
* INTA goes low when GPA1 goes low

An important point to note, is that the INTA stays low (raised - active low) until the port register is read.
i.e. to rest interrupts, you must read the registers (even if you don't need the values).


#### Latching

One thing not explained clearly in the datasheet is how updates to multiple GPIO ports are latched.
There are latch regiseters (OLATA/B) bu their operation is not explained (or even included in the functional block diagram).

The example program uses two methods of writing the GPIO registers:

* if the current value is high, then it writes GPIOA followed by GPIOB in two SPI operations.
* if the current value is low, then it performs a sequential write of both GPIOA and GPIOB one operation.

The LEDs in the example are attached one to each GPIO port, specifically to look at the latching behaviour.

The following scope traces seem to indicate that latching is definitely not synchronised,
but the lapsed time between port changes can be minimised by using sequential write operations.


First, a trace of the register-by-register update. There is a ~14µs delay between the update of the GPIOA and GPIOB outputs:

![scope-register-by-register](./assets/scope-register-by-register.gif?raw=true)

Second, a trace of the sequential write update. The register updates are still not synchronised, but the delay has been reduced to under 1µs:

![scope-sequential-write](./assets/scope-sequential-write.gif?raw=true)


## Construction

![Breadboard](./assets/MCP23S17_bb.jpg?raw=true)

![Schematic](./assets/MCP23S17_schematic.jpg?raw=true)

![Build](./assets/MCP23S17_build.jpg?raw=true)

## Credits and References

* [MCP23S17 datasheet and info](http://parts.io/detail/1371552/MCP23S17-E%2FSS) - parts.io
* [MCP23S17 library](https://github.com/MajenkoLibraries/MCP23S17) - MajenkoLibraries - looks like an interesting library to try out
* [MCP23S17 library](http://playground.arduino.cc/Main/MCP23S17) - n0mjs710 - another libary
* [Arduino SPI](https://www.arduino.cc/en/reference/SPI)
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap313-mcp23s17-port-expander.html)
