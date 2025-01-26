# #523 JP-QR701 Thermal Printer Basics

Learning how to use the JP-QR701 thermal printer module with an Arduino, including QR codes generated with Python.

![Build](./assets/QR701Basics_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/U1RVI4zR9CQ/0.jpg)](https://www.youtube.com/watch?v=U1RVI4zR9CQ)

## Notes

I've wanted to play around with a thermal printer for a while, now I finally have the chance
since I snagged a [GOOJPRT QR701 Mini 58mm Embedded Receipt Thermal Printer](https://www.aliexpress.com/item/32890205918.html)
on aliexpress.

After a bit of investigation, I discovered the OEM is [厦门精普电子科技有限公司 Xiamen Jingpu Electronic Technology Co Ltd](http://www.xmjprt.com/),
and they specialise in a wide range of thermal printing products.
The JP-QR701 is a very similar (idential OEM?) to products available from AdaFruit, Sparkfun and other retailers.

![QR701_kit](./assets/QR701_kit.jpg?raw=true)

## JP-QR701 Specs

JP-QR701 58mm embedded miniature thermal printer

* small size, light weight, fully functional
* simple, easy connection
* high-speed, high-quality, stylish
* standard GB2312 large font
* Printing method: Thermal dot line printing
* RS232 / TTL interfaces, voltage 5-9V / 12V


| Feature               | Sepcification                                                                           |
|-----------------------|-----------------------------------------------------------------------------------------|
| printing method       | Thermal line                                                                            |
| Print width           | 48 mm                                                                                   |
| Dot density           | 384 points / line                                                                       |
| printing speed        | 90 mm / s                                                                               |
| Interface Type        | RS232 / TTL                                                                             |
| Paper roll diameter   | ≦ 40mm                                                                                  |
| Paper thickness       | 0.06-0.08mm                                                                             |
| Paper roll            |  Width: 57.5 ± 0.5 mm                                                                   |
| Character size        | ANK character, Font A: 12 × 24 dots, Font B: 9 × 17 dots                                |
| Barcode Hard font     | GB2312 font                                                                             |
| Barcode type          | UPC-A / UPC-E / JAN13 (EAN13) / JAN8 (EAN8) / CODE39 / ITF / CODABAR / CODE93 / CODE128 |
| Input buffer          | 32k bytes                                                                               |
| NV Flash              | 64k bytes                                                                               |
| Printer input voltage | DC 5V / 2A                                                                              |
| Cash drawer control   | DC 5V / 1A                                                                              |
| weight                | 0.183 kg                                                                                |
| dimension             | 109 × 94 × 66mm (depth × width × height)                                                |
| working environment   | Temperature: 0 ~ 45 °C, Humidity: 10 ~ 80%                                              |
| Storage environment   | Temperature: -10 ~ 60 °C, humidity: 10 ~ 90%                                            |
| Print head life       | 50 km                                                                                   |

![QR701_rear](./assets/QR701_rear.jpg?raw=true)

## Self-test

Hold down the button on the top of the printer (or on the control board) while plugging in the power.
A diagnostic is printed. This worked for me without issue (using a 5V 2A power supply).

[![clip](https://img.youtube.com/vi/RProFcxC7iY/0.jpg)](https://www.youtube.com/watch?v=RProFcxC7iY)

## Construction

I have the TTL version of the JP-QR701, so driving it from an Arduino presents no problems.

I put together a simple protoboard test base for a Nano, power supply and printer connections:

* barrel jack for 5V 2A power supply
* mounted the leads for the printer connection
* females headers for mounting an Arduino Nano
* jumper selects whether to power the Nano from the same supply as the printer, with a couple of bulk caps for the Nano supply to smooth out any power fluctuations caused by the printer.

![Breadboard](./assets/QR701Basics_bb.jpg?raw=true)

![Schematic](./assets/QR701Basics_schematic.jpg?raw=true)

## Example Code

The [QR701Basics.ino](./QR701Basics.ino) sketch is a simple test of the printer, based on an example from the
[Adafruit Arduino Library for Small Thermal Printers](https://github.com/adafruit/Adafruit-Thermal-Printer-Library).

I've customised it a bit:

* prints the test page on a button press (instead of at startup)
* add my own QR code

The QR code data in [qrcode.h](./qrcode.h) was generated with a python script from [here](https://codingkata.tardate.com/python/qrcodes/).
I think I need to fiddle with the `ESC 7` Setting Control Parameter Command and/or
`DC2 #` printing density settings, because so far while the printer generates a
recognizable QR code, I can't scan it with my phone without first colouring it in with a black pen!

![Build](./assets/QR701Basics_build.jpg?raw=true)

## Credits and References

* [Original GOOJPRT QR701 Mini 58mm Embedded Receipt Thermal Printer RS232/ TTL Mini Embedded Receipt Thermal Printer ESC/POS Print](https://www.aliexpress.com/item/32890205918.html) - my source on aliexpress
* [JP-QR701 Product Info](http://www.xmjprt.com/bbx/2457738-2457758.html?id=52829&pid=2284264)
* [CSN A2 Micro panel thermal printer manual](https://cdn-shop.adafruit.com/datasheets/CSN-A2+User+Manual.pdf) - adafruit; similar/same product? contains full command code doc
* [A2 Micro panel thermal printer manual](https://www.sparkfun.com/datasheets/Components/General/A2-user%20manual-1.pdf) - sparkfun; similar/same product?
* [厦门精普电子科技有限公司 Xiamen Jingpu Electronic Technology Co Ltd](http://www.xmjprt.com/) - OEM
* [Mini Thermal Receipt Printer](https://www.adafruit.com/product/597) - AdaFruit product ID 597
* [Mini Thermal Receipt Printer tutorial](https://learn.adafruit.com/mini-thermal-receipt-printer?view=all) - adafruit
* [Adafruit Arduino Library for Small Thermal Printers](https://github.com/adafruit/Adafruit-Thermal-Printer-Library)
* [Arduino Nano](https://store.arduino.cc/usa/arduino-nano)
* [Interrupt problem with Nano](https://forum.arduino.cc/index.php?topic=526497.0)
