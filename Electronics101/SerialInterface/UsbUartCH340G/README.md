# #406 SerialInterface/UsbUartCH340G

Build a USB to TTL serial interface on a breadboard using the CH340G interface chip, and use it to program Arduino sketches on an ATmega328P.

![Build](./assets/UsbUartCH340G_build.jpg?raw=true)

## Notes

The CH340G is a USB to UART Interface chip. It is often used as a cheap alternative to
more established brands and products such as the FTDI FT232RL.
The CH340G is commonly found in:

* Arduino Nano clones
* USB to Serial adapters

In this project, I'd like to see how easy it is to build a USB to Serial interface
on a breadboard. To test it out, I'll use it program Arduino sketches on an ATmega328P.

## CH340G Key Specs

CH340 is produced by [WCH 江苏沁恒股份有限公司 (Jiangsu Yuheng Co., Ltd.)](http://www.wch.cn/).
It is a series of USB adapters - with variants providing serial, parallel or IrDA interfaces.
The CH340G supports serial with common flow control signals.

Key features:

* USB 2.0
* Supports common flow control signals RTS, DTR, DCD, RI, DSR and CTS.
* Supports RS232, RS422 and RS485 with external level shifting components.
* Baud rate range from 50bps to 2Mbps.
* 5V and 3.3V operation.

Pinout:

| Pin | Name | Description                                             |
|-----|------|---------------------------------------------------------|
| 1   | GND  | Ground. Connect to the ground pin of USB bus            |
| 2   | TXD  | UART Data Transmit output                               |
| 3   | RXD  | UART Data Receive input                                 |
| 4   | V3   | Internal 3.3V reference for USB physical layer          |
| 5   | UD+  | USB D+ signal                                           |
| 6   | UD-  | USB D- signal                                           |
| 7   | XI   | Crystal oscillator input                                |
| 8   | XO   | Crystal oscillator output                               |
| 9   | CTS# | UART flow control: Clear to Send                        |
| 10  | DSR# | UART flow control: Data Set Ready                       |
| 11  | RI#  | UART flow control: Ring In                              |
| 12  | DCD# | UART flow control: Data Carrier Detect                  |
| 13  | DTR# | UART flow control: Data Terminal Ready                  |
| 14  | RTS# | UART flow control: Request to Send                      |
| 15  | R232 | Auxiliary RS232 enable. Active high, internal pull down |
| 16  | VCC  | Supply rail for the chip                                |

Notes:
* V3: Decouple with a 4.7-20nF capacitor when in 5V operation, or tie to VCC when in 3.3V operation.

## Chips and DIPs

I have some CH340G chips in SOP-16 package (from a seller on aliexpress).
I've mounted one on a DIP adapter, and found a micro-USB breakout:

![ch340g_chips_and_dips](./assets/ch340g_chips_and_dips.jpg?raw=true)

## Examining a Commercial CH340 USB-Serial Adapter

I have a CH340G USB adapter that I
[got along with an Arduino mini](https://www.aliexpress.com/item/A96-Free-Shipping-USB2-0-To-TTL-6Pin-CH340G-Converter-Pro-Mini-Atmega328-5V-16M-For/1887601992.html),
so I took a closer look to see if it usde the CH340G chip in any unexpected ways.

Tracing the circuit, it turns out to be very straight-forward. A few things to note:

* the 3.3V/5V selector actually just enables/disables a 662K 3.3V regulator to supply the outbound pwer rail. It does not switch the operating voltage of the CH340G itself (or the data levels)
* includes a power indicator LED, and a transmit indicator LED
* has 1kΩ resistors inline the RX/TX lines; not particularly sure why (not mentioned in the CH340G data sheet)
* lots of ceramic bypass capacitors. I'm not sure of the actual capacitance values.

![ch340g_adapter](./assets/ch340g_adapter.jpg?raw=true)

![ch340g_adapter_schematic](./assets/ch340g_adapter_schematic.jpg?raw=true)

## Building the CH340G Interface on a Breadboard

On one breadboard, I have a basic 5V CH340G setup:

* RX and TX LEDs; Power LED
* DTR, TXD and RXD connected on the serial side

On another breadboard, I have an ATmega328 (with Arduino bootloader) wired up for programming.
See [LEAP#405 ATmegaSerialProgrammer](../../../playground/ATmegaSerialProgrammer) for more on programming over serial.

![Breadboard](./assets/UsbUartCH340G_bb.jpg?raw=true)

![Schematic](./assets/UsbUartCH340G_schematic.jpg?raw=true)

![Build](./assets/UsbUartCH340G_build.jpg?raw=true)

Here's a quick demo (uploading a sketch).
I'm programming the ATmega328 with the [UsbUartCH340G.ino](./UsbUartCH340G.ino) sketch - a simple blink
variant that also sends bursts of serial output (to exercise the RX LED).

[![clip](https://img.youtube.com/vi/SSdThKPhHV4/0.jpg)](https://www.youtube.com/watch?v=SSdThKPhHV4)

## Credits and References
* [CH340G datasheet](http://androegg.de/wp-content/uploads/2016/07/CH340G_USB_TTL_Converter.pdf)
* [FTDI FT232RL](http://www.ftdichip.com/Products/ICs/FT232R.htm)
* [2TY S8550 PNP transistor datasheet](https://dirtypcbs.com/assets/datasheets/S8550-2TY.pdf)
* [662k voltage regulator datasheet](https://www.sunrom.com/p/xc6206p332mr-662k)
* [RS-232](https://en.wikipedia.org/wiki/RS-232) - wikipedia
* [Serial port](https://en.wikipedia.org/wiki/Serial_port) - wikipedia
* [..as mentioned on my blog](https://blog.tardate.com/2018/07/leap406-ch340g-usb-to-serial-on-a-breadboard.html)
