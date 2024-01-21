# #737 NTP Client Demo

Simple demonstration of NTP client requests using an Arduino Ethernet Shield.

![Build](./assets/NtpClientDemo_build.jpg?raw=true)

## Notes

If an Arduino needs accurate time details, the most basic technique is to use an NTP server, as most computers will do.
NTP: [Network Time Protocol](https://en.wikipedia.org/wiki/Network_Time_Protocol).

The sketch demonstrates requesting and parsing an NTP request from `time.nist.gov` using an Ethernet Shield on an Arduino Uno.

The Simple Network Time Protocol is better described  with practical examples in [NTP with Ruby](https://codingkata.tardate.com/ruby/ntp/)

### Circuit Design

Nothing to it - just add the ethernet shield to an Arduino Uno board and plug it in..

![bb](./assets/NtpClientDemo_bb.jpg?raw=true)

![schematic](./assets/NtpClientDemo_schematic.jpg?raw=true)

### Testing

The script [NtpClientDemo.ino](./NtpClientDemo.ino) is based on the example [Arduino tutorial](https://docs.arduino.cc/tutorials/ethernet-shield-rev2/udp-ntp-client/).
I've refactored it a bit to be clearer.

The script can be compiled and uploaded from the IDE, with the output examined using the built-in serial monitor set for 115200 baud:

![ide](./assets/ide.png?raw=true)

Typical transcript...

    Ethernet started...
    Seconds since Jan 1 1900 = 3914801468
    Unix time = 1705812668
    The UTC time is 4:51:08
    Seconds since Jan 1 1900 = 3914801480
    Unix time = 1705812680
    The UTC time is 4:51:20
    Seconds since Jan 1 1900 = 3914801491
    Unix time = 1705812691
    The UTC time is 4:51:31
    Seconds since Jan 1 1900 = 3914801502
    Unix time = 1705812702
    The UTC time is 4:51:42

Another way getting connected on macOS is to use screen:

    screen /dev/cu.usbmodem24201 115200

![screen](./assets/screen.png?raw=true)

## Credits and References

* [udp-ntp-client example](https://docs.arduino.cc/tutorials/ethernet-shield-rev2/udp-ntp-client/)
* [name](https://github.com/arduino-libraries/NTPClient)
* [Arduino Uno R3](http://www.amazon.com/gp/product/B00F6JCV20/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B00F6JCV20&linkCode=as2&tag=itsaprli-20&linkId=O34GVKFAZ6FVDC6W) or similar
* [Arduino Ethernet Shield](http://www.amazon.com/gp/product/B00EU7447Y/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B00EU7447Y&linkCode=as2&tag=itsaprli-20&linkId=QJYL7QLWFGQVGUF5)
* [Simple Network Time Protocol - NTP with Ruby](https://codingkata.tardate.com/ruby/ntp/)
* [Network Time Protocol](https://en.wikipedia.org/wiki/Network_Time_Protocol) - wikipedia