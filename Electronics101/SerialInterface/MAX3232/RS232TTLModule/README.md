# #509 MAX3232 RS232 to TTL Module

Using a MAX3232 Module with CH340 adapter for USB to RS-232 serial communication, with examples using screen on MacOSX.

![Build](./assets/RS232TTLModule_build.jpg?raw=true)

## Notes

I want to talk to a device on an RS232 DE-9 serial port, and it seems I have modules on hand for that!

This is a quick exercise of combining two modules to allow RS232 serial communication over USB:

* a [MAX3232 RS232 to TTL Serial Module](https://www.aliexpress.com/item/4000055222836.html),
* with a [CH340G-based USB to TTL serial adapter](../../UsbUartCH340G)

See [LEAP#406](../../UsbUartCH340G) for details of the USB to TTL serial adapter.
Here I'm going to take a closer look at the MAX3232 module, which can be found for pennies on aliexpress or ebay:

![RS232TTLModule_module](./assets/RS232TTLModule_module.jpg?raw=true)

## RS-232

[RS-232](https://en.wikipedia.org/wiki/RS-232) is a vintage serial standard that used to be ubiquitous on PC equipment for
point-to-point peripheral communication, especially modems and mouses. It almost became extinct, but appears to have had a
but of the resurgence on the back of IoT/embedded systems.

RS-232 is a serial communication protocol, where a time-series of bits (data bits, optional parity bit, and a number of stop bits)
is encoded using differential voltage levels for '0' and '1'.
The RS-232 standard does not define the data encoding.

What makes RS-232 a little daunting to directly integrate with are the voltage levels on the line:

| Data      | Control     | Voltage     |
|-----------|-------------|-------------|
| 0 (space) | Asserted    | +3 to +15 V |
| 1 (mark)  | De-asserted | −15 to −3 V |

This is where RS-232 driver chips like the MAX3232 come into play: they handle all the voltage conversion and allow
control and communication at CMOS or TTL voltage levels.

## DE-9 Pinout

The RS-232 standard recommended [D-subminiature](https://en.wikipedia.org/wiki/D-subminiature) 25 pin connectors (DB-25),
but the 9-pin DE-9 became the most common for computer applications.

> pedantic side note: almost everyone refers to the 9-pin connectors as "DB-9", but I just learned from the wikipedia page
> they are officially "DE-9", with B/E referring to the different shell sizes.

[![de9_pinouts](./assets/de9_pinouts.png?raw=true)](https://www.db9-pinout.com/)

| Pin | SIG | Signal Name          | DTE (PC) |
|-----|-----|----------------------|----------|
| 1   | DCD | Data Carrier Detect  | in       |
| 2   | RXD | Receive Data         | in       |
| 3   | TXD | Transmit Data        | out      |
| 4   | DTR | Data Terminal Ready  | out      |
| 5   | GND | Signal Ground        | -        |
| 6   | DSR | Data Set Ready       | in       |
| 7   | RTS | Request to Send      | out      |
| 8   | CTS | Clear to Send        | in       |
| 9   | RI  | Ring Indicator       | in       |

## Flow Control

In modern applications, a minimal "3-wire" RS-232 (transmit, receive, ground) connection is often used.
This configuration does not use any hardware flow control.

A "5-wire" configuration adds hardware flow control with RTS and CTS lines.

## Null Modem

Usually when using RS-232 to connect to computers/microprocessors,
a [Null modem](https://en.wikipedia.org/wiki/Null_modem) (cross-over) connection is required.
This basically has transmit and receive crossed i.e. what one transmits, the other wants to receive.

NB: straight-through connections are for traditional uses with peripherals - e.g. a computer talking to a modem.

[![D9_Null_Modem_Wiring](./assets/D9_Null_Modem_Wiring.png?raw=true)](https://en.wikipedia.org/wiki/Null_modem)

## About the MAX3232

The MAX3232 provides level conversion for 2 lines in and 2 lines out, so it can support 3-wire or 5-wire RS-232.
It can operate with 3.0V to 5.5V TTL, with transmission speeds up to 1Mbps.

![MAX3232](./assets/MAX3232.png?raw=true)

### MAX3232 Module Construction

The MAX3232 module is a standard 3-wire configuration, with a DE-9 female connector.
Here's a quick transcription of the module circuit. It follows the recommended
examples provided in the datasheet:

![Breadboard](./assets/RS232TTLModule_bb.jpg?raw=true)

![Schematic](./assets/RS232TTLModule_schematic.jpg?raw=true)

## Connecting the USB Adapter

| CH340G USB Adapter Pinouts | MAX3232 Module Pins |
|----------------------------|---------------------|
| DTR                        | -                   |
| RXD                        | RXD                 |
| TXD                        | TXD                 |
| VCC (5V)                   | VCC                 |
| CTS                        | -                   |
| GND                        | GND                 |

## Connecting with Screen

I'm using MacOSX, so (as with Linux) the most handy console utility is
[screen](https://codingkata.tardate.com/tools/screen/).

The device I am connecting to for a test requires 9600 baud, with 8 data bits, no parity and 1 stop bit.
The CH340G adapter was connected on `/dev/tty.wchusbserial14210` device, so a screen session
is started with the command:

    screen /dev/tty.wchusbserial14210 9600,cs8,-parenb,-cstopb,-hupcl

...and communication is up and running without any problem:

![console_startup](./assets/console_startup.png?raw=true)

The USB adapter and MAX3232 module connected to the serial device:

![RS232TTLModule_testing](./assets/RS232TTLModule_testing.jpg?raw=true)

## Credits and References

* [MAX3232 RS232 to TTL Serial Port Converter Module DB9 Connector](https://www.aliexpress.com/item/4000055222836.html) - aliexpress seller
* [MAX3232 product info and datasheet](https://www.ti.com/product/MAX3232)
* [RS-232](https://en.wikipedia.org/wiki/RS-232) - wikipedia
* [D-sub 9 Connector Pinout](https://www.db9-pinout.com/)
* [Null modem](https://en.wikipedia.org/wiki/Null_modem) - wikipedia
* [screen notes](https://codingkata.tardate.com/tools/screen/)
* [Serial Communication – RS232 Basics](http://maxembedded.com/2013/09/serial-communication-rs232-basics/) - maxembedded
* [Beginning Embedded Electronics - 4 - UART and Serial Communication](https://www.sparkfun.com/tutorials/104) - sparkfun tutorial
