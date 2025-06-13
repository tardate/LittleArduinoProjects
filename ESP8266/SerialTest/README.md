# #154 ESP8266 SerialTest

First test of an ESP8266 module - serial communication to the SoC

![The Build](./assets/SerialTest_build.jpg?raw=true)

## Notes

The ESP8266 wifi SoC and derivative modules on offer caused a bit of a flurry in the IoT community (it seems).

That was last year. As usual, I'm late to the party! But I do have an ESP8266 module that I bought a while back for USD3.09 and have not really put to the test.
These days you can get them for
[USD2.40 or less](https://www.aliexpress.com/item/Free-shipping-ESP8266-serial-WIFI-wireless-module-wireless-transceiver/2044444348.html?spm=2114.01020208.3.12.kit3o3&ws_ab_test=searchweb201556_8,searchweb201527_3_71_72_73_74_75,searchweb201560_1).

This project is a first test of the basics: communicating with the default firmware and hopefully connecting to an access point in my area.

My objective is to use a serial console on a computer (macOS),
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
It's pretty neat in that it has a 5V/3.3V selector on the adapter, however I discovered that this switches VCC from 5V/3.3V.
It *does not* level shift the data lines - they will still be 5V.

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

### To level-shift or not? That is a good question

While the ESP8266 is a 3.3V circuit, it does seem to work fine with 5V TX/RX signals.
However in the final circuit I'm using here, I decided to not take any chances, so I'm level-shifting the
5V signals from the CH340G USB adapter to 3.3V for the ESP8266 module.

## First Tests

Powering up:

* connect the CH340G USB adapter
* fire up a terminal program set for 115200 baud with CR/LF (I'm using the serial console in the Arduino IDE)
* turn on the 3.3V external power supply to the ESP8266
* watch for a "ready" in the console window; pull the ESP8266 RST pin low to force a reset and try again (I seem to be doing this quite a bit)

I'm mainly using the
[nurdspace](https://nurdspace.nl/ESP8266#AT_Commands)
and [esp8266-wiki](https://github.com/esp8266/esp8266-wiki/wiki/at_0.9.1)
AT command references for the following tests..

### Hello

(AT), reset (AT+RST) and show software and SDK version (AT+GMR)..

```sh
AT

OK
AT+RST

Ai-Thinker Technology Co.,Ltd.

ready
WIFI CONNECTED
WIFI GOT IP

AT+GMR

AT version:0.40.0.0(Aug  8 2015 14:45:58)
SDK version:1.3.0
Ai-Thinker Technology Co.,Ltd.
Build:1.3.0.2 Sep 11 2015 11:48:04
OK
```

### Connect to an Access Point

..list the access points we can see (AT+CWLAP), and join (AT+CWJAP).
Test to see if we are still joined after a reset: yes.

```sh
AT+CWLAP
+CWLAP:(3,"Sunshine",-42,"90:72:40:0f:5b:f8",1,-26)
+CWLAP:(3,"SH-EB810V_7484_MLO",-80,"86:fe:ce:b2:74:84",2,-47)

OK
AT+CWJAP="Sunshine","myPassword"
WIFI CONNECTED
WIFI GOT IP

OK
AT+CIFSR
+CIFSR:STAIP,"192.168.10.66"
+CIFSR:STAMAC,"5c:cf:7f:8b:56:e1"

OK

AT+CWJAP?
+CWJAP:"Sunshine","90:72:40:0f:5b:f8",1,-54

OK
```

### GET a web page

Start a client request and get the time from a website.

In the past I've used <http://www.timeapi.org/utc/now>, but that has disappeared, as have many alternatives.
For a reliable HTTP time service, I now run <https://hub.docker.com/r/tardate/echo-tools> in Docker for testing.
In the run below, my docker container is running on `http://192.168.10.87/time/now.txt`.

```sh
curl http://192.168.10.87/time/now.txt
2025-06-13T05:42:32Z
```

Making the call from the ESP8266:

```sh
AT+CWMODE?
+CWMODE:1

OK
AT+CIPSTART="TCP","192.168.10.87",80

OK
AT+CIPSEND=91

> GET /time/now.txt HTTP/1.1
Host: 192.168.10.87
User-Agent: esp/0.9.2.4
Accept: */*

OK
>
Recv 91 bytes

SEND OK

+IPD,170:HTTP/1.1 200 OK
Content-Type: text/plain;charset=utf-8
Content-Length: 20
X-Content-Type-Options: nosniff
Connection: keep-alive
Server: thin

2025-06-13T05:58:32Z

```

![console_test](./assets/console_test.png?raw=true)

### Disconnect from the access point

Once disconnected, `AT+CWJAP?` returns no AP:

```sh
AT+CWQAP

OK
WIFI DISCONNECT

AT+CWJAP?
No AP

OK
```

## Using Screen for the Serial Console

I'm using [screen](https://codingkata.tardate.com/tools/screen/) on macOS to connect at 115200:

```sh
screen /dev/tty.wchusbserial2420 115200
```

On macOS, cr/lf must be entered in two steps: press `<return>`, then `ctrl-j`.

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
* [LEAP#134 BidirectionalLevelShifterModule](../../Electronics101/BidirectionalLevelShifterModule/)
