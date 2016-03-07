# #193 ESP8266/DIYDevBoard

a DIY devboard for an ESP-01 ESP8266

![DIYDevBoard_demo](./assets/DIYDevBoard_demo.jpg?raw=true)

## Notes

With the funding of the [MicroPython on the ESP8266](https://www.kickstarter.com/projects/214379695/micropython-on-the-esp8266-beautifully-easy-iot) campaign, my interest in the ESP8266 is rekindled.

I have an ESP-01 module that I'd played around with before, but I was a bit tired of wiring it up a breadboard again.
So here are my notes on a little "devboard" I whipped up on a 4x6cm protoboard and hot-glued to a business card holder.

Now it's plug'n'play - add power and plug in my CH340G USB adapter and I'm good to go.

### Features

This is what I've included on the board:

* LD1117 3.3V regulator circuit (power from a barrel jack)
* [BidirectionalLevelShifterModule](../../../Electronics101/BidirectionalLevelShifterModule) to convert 5V serial signals to 3.3V
* fixed pull-up on the CH_PD chip enable
* pull-up resistors on GPIO_0 and RESET, with pull-down toggle switches
* breakout pins for GND and GPIO2
* 2x4 socket for the ESP8266

### Switch Controls

There are two switches on the board (I used a DIP switch module).
These are for controlling the reset and GPIO_0 lines.
The normal position is "off".

| Switch      | Pin    | Off         | On         | Usage |
|-------------|--------|-------------|------------|-------|
| SW1 (left)  | GPIO_0 | Pulled high | Pulled low | Pull low to enter flash mode |
| SW2 (right) | RESET  | Pulled high | Pulled low | Toggle low then high to reset the board |

### Test Drive with espy.rb

To verify everything was working OK on the devboard, I plugged in the ESP8266 with default firmware
and I exercised it with [SerialTest/ruby](../SerialTest/ruby). Here's a test of getting the time:

```
$ ./espy.rb /dev/tty.wchusbserial14540 get http://www.timeapi.org/utc/now
ESP8266 Client initialised for : /dev/tty.wchusbserial14540
            connection options : {"baud"=>9600, "data_bits"=>8, "stop_bits"=>1, "parity"=>0}
                       signals : {"rts"=>1, "dtr"=>1, "cts"=>0, "dsr"=>0, "dcd"=>0, "ri"=>0}
Waiting to warm up the connection..
AT+CIPSTART="TCP","www.timeapi.org",80

OK
Linked
AT+CIPSEND=93
> GET /utc/now HTTP/1.1
Host: www.timeapi.org
User-Agent: EspyClient/0.9.2.4
Accept: */*
SEND OK

+IPD,277:HTTP/1.1 200 OK
Date: Mon, 07 Mar 2016 17:19:38 GMT
Connection: keep-alive
X-Frame-Options: sameorigin
X-Xss-Protection: 1; mode=block
Content-Type: text/html;charset=utf-8
Content-Length: 25
Server: thin 1.5.0 codename Knife
Via: 1.1 vegur

2016-03-07T17:19:39+00:00
OK
AT+CIPCLOSE

OK
Unlink
```

### Test Drive with the esptool

[esptool.py](https://github.com/themadinventor/esptool) requires the board to be in flash mode:
* SW1 "on" to pull-down GPIO_0 (flash mode)
* SW2 toggled on then off (reset the baord)

Then the basic esptool.py commands to interrogate the board work fine:

```
$ esptool.py --port /dev/tty.wchusbserial14540 chip_id
Connecting...
Chip ID: 0x009ccdd2
$ esptool.py --port /dev/tty.wchusbserial14540 flash_id
Connecting...
Manufacturer: c8
Device: 4013
$ esptool.py --port /dev/tty.wchusbserial14540 read_mac
Connecting...
MAC: 18:fe:34:9c:cd:d2
```

## Construction

Here's the equivalent breadboard circuit:

![Breadboard](./assets/DIYDevBoard_bb.jpg?raw=true)

And schematic:

![The Schematic](./assets/DIYDevBoard_schematic.jpg?raw=true)

My rough 4x6cm protoboard layout:

![DIYDevBoard_layout](./assets/DIYDevBoard_layout.jpg?raw=true)

The end result:

![The Build](./assets/DIYDevBoard_build.jpg?raw=true)

![DIYDevBoard_demo](./assets/DIYDevBoard_demo.jpg?raw=true)

## Credits and References
* [esptool.py](https://github.com/themadinventor/esptool)
* [BidirectionalLevelShifterModule](../../../Electronics101/BidirectionalLevelShifterModule)
* [SerialTest](../SerialTest) - my first test of the ESP8266, with more details of board use
* [PowerLD1117](../../../Electronics101/PowerLD1117) - LD1117 circuit and notes
