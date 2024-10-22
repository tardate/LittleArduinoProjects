# #633 USB to RJ45 Adapter

Building a USB to RJ45 adapter with the CH340G and MAX3232 chipsets.

![Build](./assets/UsbToRJ45_build.jpg?raw=true)

## Notes

Occasionally one will run into a device that uses an RJ45 serial connector instead of the old DE-9 connectors.
They are still carrying RS-232 serial

A RJ45 connector is a modular 8 position, 8 pin connector used for terminating Cat5e or Cat6 twisted pair cable.

RJ45 connectors used in this way are generally 8 position, 8 pin connector modular connectors used for terminating Cat5e or Cat6 twisted pair cable.
The wiring usually follows the T568A or T568B assignments that are defined in ANSI/TIA-568.

I am using RJ45 T568B cables in this mini project.

The EIA/TIA-561 standard describes the use of 8P8C connectors for RS-232 serial interfaces.

However it appears many vendors have their own proprietary wiring schemes, which would explain why cables dont always work as expected!
The table below shows the T568B wiring color scheme with EIA/TIA-561 pin assignments,
compared with
[SGI Onyx2](https://techpubs.jurassic.nl/manuals/linux/enduser/SGIconsole_HW_CG/sgi_html/apb.html) pin assignments,
and finally the pin assignments for the device I grabbed to test with (Nomadix AG2400).

| Pin | T568B color          | EIA/TIA-561 Serial | SGI Onyx2 | Nomadix AG2400 |
|-----|----------------------|--------------------|-----------|----------------|
| 1   | white/orange stripe  | RI                 | RTS       | RTS            |
| 2   | orange               | DCD                | DSR       | DTR            |
| 3   | white/green stripe   | DTR                | DCD       | TXD            |
| 4   | blue                 | SG                 | RXD       | SG             |
| 5   | white/blue stripe    | RXD                | TXD       | SG             |
| 6   | green                | TXD                | SG        | RXD            |
| 7   | white/brown stripe   | CTS                | DTR       | DSR            |
| 8   | brown                | RTS                | CTS       | CTS            |


![RJ45-Pinout-T568B](./assets/RJ45-Pinout-T568B.jpg?raw=true)

The connector on my cat5 cable:

![RJ45-T568B-connector](./assets/RJ45-T568B-connector.jpg?raw=true)

## Construction

The construction builds upon a previous project [LEAP#510 USB to RS-232 Adapter](../UsbToRs232), adding as RJ45 adapter
made from a spare length of Cat5 with RJ45M connector.
A strip of 10-wire IDC cable is used to connect the RJ45 adapater to the main USB to RS-232 Adapter subsystem.

![bb](./assets/UsbToRJ45_bb.jpg?raw=true)

![schematic](./assets/UsbToRJ45_schematic.jpg?raw=true)

## Connecting with Screen

NB: the CH340G may require drivers to be installed - see [LEAP#406 UsbUartCH340G] where I covered this in detail.

I'm using MacOSX, so (as with Linux) the most handy console utility is
[screen](http://www.noah.org/wiki/Screen_notes#using_screen_as_an_RS-232_.2F_general_serial_terminal).

The device I am connecting to for a test requires 9600 baud, with 8 data bits, no parity and 1 stop bit.
The CH340G adapter was connected on `/dev/tty.wchusbserial1410` device, so a screen session
is started with the command:

    $ screen /dev/tty.wchusbserial1410 9600,cs8,-parenb,-cstopb,-hupcl

...and communication is up and running without any problem:

![console_connected](./assets/console_connected.png?raw=true)

## Credits and References

* [LEAP#510 USB to RS-232 Adapter](../UsbToRs232)
* [RJ45M 8P8C](https://en.wikipedia.org/wiki/Modular_connector#8P8C) - wikipedia
* [AN-917 Popular Connector Pin Assignments for Data Communication](https://www.ti.com/lit/an/snla039/snla039.pdf) - TI Application Report
* [RJ45 Pinout](https://www.showmecables.com/blog/post/rj45-pinout)
* [SCSI Terminal Server (STS) and Etherlite Signal and Cable Pinout information](https://www.digi.com/support/knowledge-base/scsi-terminal-server-sts-and-etherlite-signal-and)  -some good general connector information for various DCE/DTE configurations
