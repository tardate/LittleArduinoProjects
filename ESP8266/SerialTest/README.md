# #154 ESP8266/SerialTest

First test of an ESP8266 module - serial communication to the SoC


## Notes

The ESP8266 wifi SoC and derivative modules on offer caused a bit of a flurry in the IoT community (it seems).

That was last year. As usual, I'm late to the party! But I do have an ESP8266 module that I bought a while back for USD3.09 and have not really put to the test.
These days you can get them for
[USD2.40 or less](https://www.aliexpress.com/item/Free-shipping-ESP8266-serial-WIFI-wireless-module-wireless-transceiver/2044444348.html?spm=2114.01020208.3.12.kit3o3&ws_ab_test=searchweb201556_8,searchweb201527_3_71_72_73_74_75,searchweb201560_1).

This project is a first test of the basics: communicating with the default firmware and hopefully connecting to an access point in my area.

My objective is to use a serial console on a computer (MacOSX),
to talk to the ESP8266,
using serial communications,
via a USB-serial adapter.

### ESP8266 Pin Layout and Usage

For my module (ESP-01), with the pins front and centre, the pin assignments are as follows:

| Left | -     | -     | Right|
|------|-------|-------|------|
| GND  | GPIO2 | GPIO0 | URXD |
| UTXD | CH_PD | RST   | VCC  |

![pinout](./assets/esp8266_pinout.png?raw=true)

Pin usage:

| Pin   | Usage/notes |
|-------|-------------|
| VCC   | 3.3V at up to 215mA |
| GND   | Ground |
| UTXD  | serial transmit |
| URXD  | serial receive |
| CH_PD | chip select, required to be pulled high |
| RST   | pull low to reset |
| GPIO0 | pull low to enter flash mode. There are [reported issues](https://github.com/esp8266/Arduino/issues/244) if not pulled high with e.g 10kΩ |
| GPIO2 | other I/O port given a module pinout (the chip itself has more GPIO pins) |



My first job was to bodge together a breadboard adapter for the ESP8266 module -
its interface is 2 rows of 4 pins at 2.54mm pitch; not something you can plug directly into a breadboard.

![module](./assets/SerialTest_module.jpg?raw=true)

### USB-Serial

I'm using a CH340G USB adapter that I
[got along with an Arduino mini](https://www.aliexpress.com/item/A96-Free-Shipping-USB2-0-To-TTL-6Pin-CH340G-Converter-Pro-Mini-Atmega328-5V-16M-For/1887601992.html).
It's pretty neat in that it has a 5V/3.3V selector on the adapter, however I discovered that this switches VCC from 5V/3.3V. It *does not* level shift the data lines - they will still be 5V.


When connecting the USB-Serial thru to to the ESP8266 module, we need to cross-over connections of course:

| USB-Serial | ESP8266   |
|------------|-----------|
| RXD        | UTXD      |
| TXD        | URXD      |



### Power

The ESP8266 is a 3.3V device, but it can draw a great deal of current - up to 215mA according to the datasheet, and in operation
it's usual to see it fluctuating up to 130mA. WiFi needs power!

There are many stories on the net of people having trouble with behaviour of the ESP8266 - constant rebooting in particular - and most
appear to be caused by insufficient power.

I ran some tests trying to drive the ESP8266 with power directly from the CH340G USB adapter (switched to 3.3V)
and while it did work, it was unreliable. So the final circuit I'm using here has a separate 3.3V supply using an LM1117
that can provide ample power.

### To level-shift or not? That is a good question..

While the ESP8266 is a 3.3V circuit, it does seem to work fine with 5V TX/RX signals.
However in the final circuit I'm using here, I decided to not take any chances, so I'm level-shifting the
5V signals from the CH340G USB adapter to 3.3V for the ESP8266 module.

## First Tests

Powering up:
* connect the CH340G USB adapter
* fire up a terminal program set for 9600 baud with CR/LF (I'm using the serial console in the Arduino IDE)
* turn on the 3.3V external power supply to the ESP8266
* watch for a "ready" in the console window; pull the ESP8266 RST pin low to force a reset and try again (I seem to be doing this quite a bit)

NB: depending on the firmware that the ESP8266 module has already installed, baud rate may be higher.
I have noted that while it wants to connect at 9600 to accept console commands, debug info will often come out at 115200 baud.

I'm mainly using the
[nurdspace](https://nurdspace.nl/ESP8266#AT_Commands)
and [esp8266-wiki](https://github.com/esp8266/esp8266-wiki/wiki/at_0.9.1)
AT command references for the following tests..

### Hello!

(AT), reset (AT+RST) and show software and SDK version (AT+GMR)..
```
[Vendor:www.ai-thinker.com Version:0.9.2.4]

ready
AT

OK
AT+RST

[Vendor:www.ai-thinker.com Version:0.9.2.4]

ready

AT+GMR

0018000902-AI03

OK
```

### Connect to an Access Point..
..list the access points we can see (AT+CWLAP), and join (AT+CWJAP).
Test to see if we are still joined after a reset: yes.

```
AT+CWLAP
+CWLAP:(3,"saiaadya",-91,"54:be:f7:70:1e:9f",1)
+CWLAP:(4,"SINGTEL-41AC",-88,"00:26:75:f1:41:ad",1)
+CWLAP:(4,"SINGTEL-3D7B",-90,"e0:8e:3c:05:3d:7c",1)
+CWLAP:(4,"d09cfc",-90,"0c:54:a5:f5:cb:de",1)
+CWLAP:(4,"SINGTEL-22BB",-93,"00:26:75:fc:22:bc",1)
+CWLAP:(4,"dlink-E614",-82,"e8:cc:18:f7:e6:14",11)
+CWLAP:(4,"Singtel7002-78BB",-90,"00:26:75:a3:78:bc",11)
+CWLAP:(3,"Sunshine",-78,"90:72:40:0f:5b:f8",11)
+CWLAP:(4,"SINGTEL-19B9",-89,"64:09:80:18:c5:d1",2)
+CWLAP:(4,"Argem",-90,"90:f6:52:ff:c1:cd",11)
+CWLAP:(4,"Argem_EXT",-80,"c4:6e:1f:8a:e8:bb",11)
+CWLAP:(4,"SINGTEL-3573",-88,"98:2c:be:93:69:36",4)
+CWLAP:(4,"SINGTEL-AE0F",-83,"00:26:75:a0:ae:10",4)
+CWLAP:(1,"abc",-85,"00:02:6f:5d:d0:54",11)
+CWLAP:(4,"SINGTEL-4162",-85,"16:0c:c3:e9:48:60",6)
+CWLAP:(3,"Choo_Family",-81,"08:62:66:90:0e:b0",6)
+CWLAP:(3,"Q-Network",-91,"ac:9e:17:49:4d:50",6)
+CWLAP:(1,"SINGTEL-B8FC",-89,"00:26:75:84:b8:fd",6)
+CWLAP:(3,"ASUS",-89,"74:d0:2b:66:c7:86",8)
+CWLAP:(4,"Singtel7002-639F",-92,"00:26:75:ab:63:a0",8)
+CWLAP:(3,"SunshineToo",-73,"90:94:e4:78:a3:72",8)
+CWLAP:(4,"SINGTEL-4757",-90,"00:26:75:e4:47:58",10)
+CWLAP:(4,"Singtel7002-68FD",-90,"00:26:75:c8:68:fe",10)
+CWLAP:(4,"SINGTEL-0557",-90,"00:26:75:ff:05:58",10)
+CWLAP:(3,"supernet fong",-88,"ac:22:0b:8e:6d:a2",12)
+CWLAP:(4,"icelink2",-89,"00:26:75:fd:df:38",11)

OK
AT+CWJAP="Sunshine","myPassword"


OK
AT+CIFSR
192.168.0.14

OK
AT+RST

[Vendor:www.ai-thinker.com Version:0.9.2.4]

ready
AT+CWJAP?
+CWJAP:"Sunshine"

OK
```

### GET a web page

Start a client request and get the time from http://www.timeapi.org/utc/now

```
AT+CWMODE?
+CWMODE:1

OK
AT+CIPSTART="TCP","www.timeapi.org",80

OK
Linked
AT+CIPSEND=88

> GET /utc/now HTTP/1.1
Host: www.timeapi.org
User-Agent: esp/0.9.2.4
Accept: */*



SEND OK

+IPD,277:HTTP/1.1 200 OK
Date: Wed, 14 Oct 2015 17:29:53 GMT
Connection: keep-alive
X-Frame-Options: sameorigin
X-Xss-Protection: 1; mode=block
Content-Type: text/html;charset=utf-8
Content-Length: 25
Server: thin 1.5.0 codename Knife
Via: 1.1 vegur

2015-10-14T17:29:54+00:00
OK
```

![timeapi4real](./assets/console_test.png?raw=true)

### Disconnect from the access point

Once disconnected, `AT+CWJAP?` returns an error:
```
AT+CWQAP

OK
AT+CWJAP?

ERROR
```

## Construction

NB: diagrams drawn with the custom parts from [ESP8266_fritzing](https://github.com/ydonnelly/ESP8266_fritzing).

![Breadboard](./assets/SerialTest_bb.jpg?raw=true)

![The Schematic](./assets/SerialTest_schematic.jpg?raw=true)

![The Build](./assets/SerialTest_build.jpg?raw=true)

## Credits and References

* [ESP8266 English datasheet](https://nurdspace.nl/File:ESP8266_Specifications_English.pdf)
* [LD1117 datasheet](http://pdf1.alldatasheet.com/datasheet-pdf/view/173710/UTC/LD1117AL-15-TA3-A-R.html)
* [ESP8266 Tutorial AT Commands](https://youtu.be/uznq8W9sOKQ)
* [ESP8266 Quick Start](http://benlo.com/esp8266/esp8266QuickStart.html)
* [electrodragon ESP8266 reference](http://www.electrodragon.com/w/ESP8266)
* [ESP8266 Community Forum](http://www.esp8266.com/)
* [nurdspace AT command reference](https://nurdspace.nl/ESP8266#AT_Commands)
* [Arduino Wifi - ESP8266: Schematic and Getting Started Code](https://www.youtube.com/watch?v=ayF4Oymf08k) - David Watts/youtube
* [LEAP#134 BidirectionalLevelShifterModule](../../Electronics101/BidirectionalLevelShifterModule)
