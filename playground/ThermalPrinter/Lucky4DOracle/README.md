# #524 Lucky 4D Printer

A "Lucky 4D" number generator, built a JP-QR701 Thermal Printer, including how to print Chinese (GB2312-80)

![Build](./assets/Lucky4DOracle_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/JpGXrXBNd1E/0.jpg)](https://www.youtube.com/watch?v=JpGXrXBNd1E)

## Notes

So now I've figured out the basics of using the JP-QR701 Thermal Printer (see [LEAP#523 Basics](../QR701Basics)),
time to do something a little more interesting(?)

Singapore has a ["4D" (four digit) lottery](https://online.singaporepools.com/en/lottery/how-play-4d)
that is especially popular during festivals like Chinese New Year.

This project generates "Lucky 4D" numbers at the press of a button.
It's a simple build, but I threw in an extra challenge - finding out how to get it to print Chinese characters.

## Printing Chinese (GB2312-80)

The JP-QR701 specifications indicate that it has GB2312 support.
I think this also applies to similar products that all seem to come from the same OEM or at least from the same design.

Most documentation - especially that found on English-language distributors - is however lacking
in any detail on how to use the Chinese language support.

After a bit of digging around, I eventually found some documentation on
the [OEM 厦门精普电子科技有限公司 Xiamen Jingpu Electronic Technology Co Ltd](http://www.xmjprt.com/) site
that revealed the trick - specifically the [QR701 Module Instruction Manual](http://jingpuprintercom86.s140.pc51.com/2151/701%E6%A8%A1%E7%BB%84BT-2%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E%E4%B9%A6.doc)

It doesn't use the standard character set / code page instructions, but rather uses two additional commands
to enable/disable Chinese language support. When Chinese language support is enabled,
2-byte GB2312-80 characters can be written to the printer.

* `FS &` - Set Chinese Character Mode
* `FS .` - Cancel Chinese Character Mode
* where FS is "Field Separator" chr(28)

Note: this is not a universal solution - it appears other printers may use other commands.
The Kashino Technology CSN-A2 - that I believe may be the OEM for the [AdaFruit Mini Thermal Receipt Printer (product ID 597)](https://www.adafruit.com/product/597) -
appears to uses an `ESC 9 n` "select Chinese code format" command.

## Encoding Some Chinese

I'm going to add 恭喜发财 to my 4D prediction for that extra dose of prosperity.
I need the GB2312-80 coding, which I got the hard way by looking it up in some
[GB Code Tables](http://www.khngai.com/chinese/charmap/tblgb.php):

| Character | Pinyin | GB code |
|-----------|--------|---------|
| 恭        | Gōng   | [0xB9A7](http://www.khngai.com/chinese/charmap/tblgb.php?page=1)
| 喜        | xǐ     | [0xCFB2](http://www.khngai.com/chinese/charmap/tblgb.php?page=2)
| 发        | fā     | [0xB7A2](http://www.khngai.com/chinese/charmap/tblgb.php?page=1)
| 财        | cái    | [0xB2C6](http://www.khngai.com/chinese/charmap/tblgb.php?page=1)

## Adapting the Printer Library

I'm using the [Adafruit Arduino Library for Small Thermal Printers](https://github.com/adafruit/Adafruit-Thermal-Printer-Library),
however this doesn't directly support the required commands, and unfortunately hides away the necessary
support functions inside the libraries private interface.

As a quick work-around, I've used a local copy of the `Adafruit_Thermal.cpp` and `Adafruit_Thermal.h`
files and made a single modification: moved the `writeBytes` methods to the public interface.

So now I can send some Chinese characters (printed with all current settings applied e.g. size, weight, justification) like this:

```
printer.writeBytes(28, '&'); // FS &; Set Chinese Character Mode
printer.writeBytes(0xB9, 0xA7); // gong
printer.writeBytes(0xCF, 0xB2); // xi
printer.writeBytes(0xB7, 0xA2); // fa
printer.writeBytes(0xB2, 0xC6); // cai
printer.println();
printer.writeBytes(28, '.'); // FS .; Cancel Chinese Character Mode
```

## Construction

The electronics are straight-forward:

* barrel jack for 5V 2A power supply
* power switch
* mounted the leads for the printer connection
* females headers for mounting an Arduino Nano
* jumper selects whether to power the Nano from the same supply as the printer, with a couple of bulk caps for the Nano supply to smooth out any power fluctuations caused by the printer.
* push-button connected to Arduino D2 (configured as INPUT_PULLUP)

![Breadboard](./assets/Lucky4DOracle_bb.jpg?raw=true)

![Schematic](./assets/Lucky4DOracle_schematic.jpg?raw=true)

I've mounted it all in an old Raffles Hotel mooncake box for that extra (though conflicting) festive feeling!

![wiring_up](./assets/wiring_up.jpg?raw=true)

All ready to play:

![Build](./assets/Lucky4DOracle_build.jpg?raw=true)

## Credits and References

* [this project on hackaday.io](https://hackaday.io/project/169208-lucky-4d-printer)
* [LEAP#523 JP-QR701 Thermal Printer Basics](../QR701Basics) - see this project for background on the printer
* [QR701 Module Instruction Manual](http://jingpuprintercom86.s140.pc51.com/2151/701%E6%A8%A1%E7%BB%84BT-2%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E%E4%B9%A6.doc)
* [GB Code Tables](http://www.khngai.com/chinese/charmap/tblgb.php)
* [How to Play: 4D](https://online.singaporepools.com/en/lottery/how-play-4d)
* [How can I get Chinese Characters on the Mini Thermal Printer](https://forums.adafruit.com/viewtopic.php?f=25&t=61551) - AdaFruit forum
