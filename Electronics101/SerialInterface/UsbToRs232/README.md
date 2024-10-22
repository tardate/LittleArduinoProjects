# #510 USB to RS-232 Adapter

Building a USB to 3-wire RS-232 adapter with the CH340G and MAX3232 chipsets.

![Build](./assets/UsbToRs232_build.jpg?raw=true)

## Notes

This project implements a USB to 3-wire RS-232 adapter by combining two chips and their supporting components:

* CH340G USB to TTL UART
* MAX3232 TTL to RS-232

As a cheat, I'm using a [MAX3232 adapter module](https://www.aliexpress.com/item/32649292208.html) - widely availably from aliexpress/ebay sellers.
The module connects two TTL to RS-232 lines with all the supporting capacitors per the datasheet.

![MAX3232ESE_adapter](./assets/MAX3232ESE_adapter.jpg?raw=true)

I've sketched the actual layout of the module here. I didn't measure all the capacitors, but I assume they are 100nF or thereabouts.

![MAX3232ESE_adapter_layout](./assets/MAX3232ESE_adapter_layout.jpg?raw=true)

## Construction

![Breadboard](./assets/UsbToRs232_bb.jpg?raw=true)

![Schematic](./assets/UsbToRs232_schematic.jpg?raw=true)

For a prototype, I'm using a CH340G on a SOP-16 DIP adapter, and a MAX3232ESE adapter board.
Here's the protoboard layout I used:

![UsbToRs232_layout](./assets/UsbToRs232_layout.jpg?raw=true)

To complete the build, I've used a mini USB connector on one end, and a female DE-9 on a short IDC strip with connector to the board -
so I could for example, swap it with a male DE-9 or other connector.

![UsbToRs232_protoboard_build](./assets/UsbToRs232_protoboard_build.jpg?raw=true)

## Connecting with Screen

NB: the CH340G may require drivers to be installed - see [LEAP#406 UsbUartCH340G] where I covered this in detail.

I'm using MacOSX, so (as with Linux) the most handy console utility is
[screen](http://www.noah.org/wiki/Screen_notes#using_screen_as_an_RS-232_.2F_general_serial_terminal).

The device I am connecting to for a test requires 9600 baud, with 8 data bits, no parity and 1 stop bit.
The CH340G adapter was connected on `/dev/tty.wchusbserial1420` device, so a screen session
is started with the command:

    $ screen /dev/tty.wchusbserial1420 9600,cs8,-parenb,-cstopb,-hupcl

...and communication is up and running without any problem:

![console_connected](./assets/console_connected.png?raw=true)

## Credits and References

* [CH340G datasheet](http://androegg.de/wp-content/uploads/2016/07/CH340G_USB_TTL_Converter.pdf)
* [MAX3232 product info and datasheet](https://www.ti.com/product/MAX3232)
* [Mini RS232 to TTL Converter Adaptor Module Board MAX3232](https://www.aliexpress.com/item/32649292208.html) - aliexpress
* [screen notes](http://www.noah.org/wiki/Screen_notes)
* [DIY USB to RS232 Adapter](http://www.electronics-diy.com/electronic_schematic.php?id=1006) - another project, uses the CP2102 and MAX3243 chips
