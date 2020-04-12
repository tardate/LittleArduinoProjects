# #155 ESP8266/SerialTest/ruby

Exercising ESP8266 module serial communications with Ruby


## Notes

I'm using an ESP8266 ESP-01 module with default firmware as detailed in the [ESP8266/SerialTest](../) project.

This is a test of driving it with a simple [ruby script](./espy.rb)

```
bundle       # install gem dependencies
./espy.rb    # prints command help
```

### status
if possible it will return software details, access point and IP address..
```
$ ./espy.rb /dev/tty.wchusbserial14540:9600 status
ESP8266 Client initialised for : /dev/tty.wchusbserial14540
            connection options : {"baud"=>9600, "data_bits"=>8, "stop_bits"=>1, "parity"=>0}
                       signals : {"rts"=>1, "dtr"=>1, "cts"=>0, "dsr"=>0, "dcd"=>0, "ri"=>0}
Waiting to warm up the connection..
AT

OK
AT+GMR
0018000902-AI03

OK
AT+CWMODE?
+CWMODE:1

OK
AT+CWJAP?
+CWJAP:"Sunshine"

OK
AT+CIFSR
192.168.0.14

OK
```

### reset

```
$ ./espy.rb /dev/tty.wchusbserial14540:9600 reset
ESP8266 Client initialised for : /dev/tty.wchusbserial14540
            connection options : {"baud"=>9600, "data_bits"=>8, "stop_bits"=>1, "parity"=>0}
                       signals : {"rts"=>1, "dtr"=>1, "cts"=>0, "dsr"=>0, "dcd"=>0, "ri"=>0}
Waiting to warm up the connection..
AT+RST

OK
H!???F
?!9?????)?
[Vendor:www.ai-thinker.com Version:0.9.2.4]

ready
```

### get web page

Let's query a time service: http://tycho.usno.navy.mil/timer.pl
Note: I used to use http://www.timeapi.org/utc/now for tests like this, but that site appears to no longer exist.

```
$ ./espy.rb /dev/tty.wchusbserial14530 get http://tycho.usno.navy.mil/timer.pl
ESP8266 Client initialised for : /dev/tty.wchusbserial14530
            connection options : {"baud"=>9600, "data_bits"=>8, "stop_bits"=>1, "parity"=>0}
                       signals : {"rts"=>1, "dtr"=>1, "cts"=>0, "dsr"=>0, "dcd"=>0, "ri"=>0}
Waiting to warm up the connection..
AT+CIPSTART="TCP","tycho.usno.navy.mil",80

OK
Linked
AT+CIPSEND=98
> GET /timer.pl HTTP/1.1
Host: tycho.usno.navy.mil
User-Agent: EspyClient/0.9.2.4
Accept: */*
SEND OK

+IPD,819:HTTP/1.1 200 OK
Date: Tue, 19 Sep 2017 16:26:05 GMT
Server: Apache/2.4.25 (Unix)
X-Frame-Options: SAMEORIGIN
Last-Modified: Tue, 19 Sep 2017 16:26:04 GMT
ETag: W/"231-5598d50d4878d"
Accept-Ranges: bytes
Content-Length: 561
Content-Type: text/html

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 3.2 Final"//EN>
<html>
<body>
<TITLE>What time is it?</TITLE>
<H2> US Naval Observatory Master Clock Time</H2> <H3><PRE>
<BR>Sep. 19, 16:26:04 UTC   Universal Time
<BR>Sep. 19, 12:26:04 PM EDT    Eastern Time
<BR>Sep. 19, 11:26:04 AM CDT    Central Time
<BR>Sep. 19, 10:26:04 AM MDT    Mountain Time
<BR>Sep. 19, 09:26:04 AM PDT    Pacific Time
<BR>Sep. 19, 08:26:04 AM AKDT Alaska Time
<BR>Sep. 19, 06:26:04 AM HAST Hawaii-Aleutian Time
</PRE></H3><P><A HREF="http://www.usno.navy.mil"> US Naval Observatory</A>

</body></html>


OK
AT+CIPCLOSE

OK
Unlink
```

## Construction

NB: diagrams drawn with the custom parts from [ESP8266_fritzing](https://github.com/ydonnelly/ESP8266_fritzing).

![Breadboard](../assets/SerialTest_bb.jpg?raw=true)

![The Schematic](../assets/SerialTest_schematic.jpg?raw=true)

![The Build](../assets/SerialTest_build.jpg?raw=true)

## Credits and References

* [serialport gem](https://rubygems.org/gems/serialport)
* [ESP8266 English datasheet](https://nurdspace.nl/File:ESP8266_Specifications_English.pdf)
* [LD1117 datasheet](http://pdf1.alldatasheet.com/datasheet-pdf/view/173710/UTC/LD1117AL-15-TA3-A-R.html)
* [ESP8266 Tutorial AT Commands](https://youtu.be/uznq8W9sOKQ)
* [ESP8266 Quick Start](http://benlo.com/esp8266/esp8266QuickStart.html)
* [electrodragon ESP8266 reference](http://www.electrodragon.com/w/ESP8266)
* [ESP8266 Community Forum](http://www.esp8266.com/)
* [nurdspace AT command reference](https://nurdspace.nl/ESP8266#AT_Commands)
