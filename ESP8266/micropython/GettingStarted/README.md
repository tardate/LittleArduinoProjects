# #344 ESP8266/micropython/GettingStarted

Getting MicroPython up and running with an ESP-01 ESP8266.

![Build](./assets/GettingStarted_build.jpg?raw=true)

## Notes

I first heard about MicroPython from the [kickstarter](http://www.kickstarter.com/projects/214379695/micro-python-python-for-microcontrollers)
campaign to open source the software.

Although it makes more sense to use it with a more capable board, I'm starting with a 512kb ESP-01 module,
hosted in the [LEAP#194 DIYDevBoard](../../DIYDevBoard).

So the first test is to flash the ESP8266 with MicroPython and take it for a test-drive.

The
[MicroPython ESP8266 docs](http://docs.micropython.org/en/latest/esp8266/) and
[Adafruit guide](https://learn.adafruit.com/micropython-basics-how-to-load-micropython-on-a-board)
make this pretty straight-forward!


### Programming Setup

I'm using a [LEAP#194 DIYDevBoard](../../DIYDevBoard) to host the ESP-01 module,
and a cheap [CH340G-based USB to UART adapter](https://www.aliexpress.com/item/CH340-module-USB-to-TTL-CH340G-upgrade-download-a-small-wire-brush-plate-STC-microcontroller-board/32354359382.html).
With the
[correct drivers installed](../../../notebook/arduino.md#arduinos-using-the-ch340g-serial-chip),
it shows up in the tty device list.

My host computer is running MacOSX.

The notes below refer to switching flash mode and reset. These are DIP switches on the dev board.

### esptool

I'll need the [esptool](https://github.com/themadinventor/esptool) to flash the device.
It's python, so install with pip.

```
pip install esptool
```

### Testing the Connection

First find the device the CH340G-based USB to UART adapter is connected on, and set that as a variable for later use:

```
$ ls /dev/tty.wchusb*
/dev/tty.wchusbserial14510
$ export ESP_PORT=/dev/tty.wchusbserial14510
```

Verify the esptool install and connection by getting the chip_id.
This requires a switch into flash mode and reset on the dev board before it responds...

```
$ esptool.py --port ${ESP_PORT} chip_id
esptool.py v2.1
Connecting........_____....._____....._____.
Detecting chip type... ESP8266
Chip is ESP8266
Uploading stub...
Running stub...
Stub running...
Chip ID: 0x009ccdd2
Hard resetting...
```

### Flashing with MicroPython

Downloading the latest 512k build:

```
wget http://micropython.org/resources/firmware/esp8266-512k-20170925-v1.9.2-120-gf0082630.bin
```

Erasing then flash first (as recommended, probably not really necessary).
Again, this requires a switch into flash mode and reset on the dev board before it responds...

```
$ esptool.py --port ${ESP_PORT} erase_flash
esptool.py v2.1
Connecting........_____....._
Detecting chip type... ESP8266
Chip is ESP8266
Uploading stub...
Running stub...
Stub running...
Erasing flash (this may take a while)...
Chip erase completed successfully in 1.2s
Hard resetting...
```

Writing the image.
Again, this requires a switch into flash mode and reset on the dev board before it responds...

```
$ esptool.py --port ${ESP_PORT} --baud 115200 write_flash --flash_size=detect 0 esp8266-512k-20170925-v1.9.2-120-gf0082630.bin
esptool.py v2.1
Connecting........_____....._
Detecting chip type... ESP8266
Chip is ESP8266
Uploading stub...
Running stub...
Stub running...
Configuring flash size...
Auto-detected Flash size: 512KB
Compressed 502712 bytes to 333664...
Wrote 502712 bytes (333664 compressed) at 0x00000000 in 29.8 seconds (effective 134.8 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting...
```

### Testing the REPL

First switch off the flash mode and reset on the dev board..
Using `screen` to open a tty console and run some python and exercise the MicroPython libraries...


```
$ screen ${ESP_PORT} 115200

>>> print('hello esp8266!')
hello esp8266!
>>> import machine
>>> pin = machine.Pin(2, machine.Pin.OUT)
>>> pin.on()
>>> pin.off()
>>> import network
>>> sta_if = network.WLAN(network.STA_IF)
>>> sta_if.active()
False
>>> sta_if.ifconfig()
('0.0.0.0', '0.0.0.0', '0.0.0.0', '208.67.222.222')
>>>
<ctrl-a, ctrl-k>
```

### Connecting to WiFi

Obviously `mySSID` and `password` are not my real credentials..

```
>>> import network
>>> sta_if = network.WLAN(network.STA_IF)
>>> sta_if.active()
False
>>> sta_if.ifconfig()
('0.0.0.0', '0.0.0.0', '0.0.0.0', '208.67.222.222')
>>> sta_if.active(True)
mode : sta(18:fe:34:9c:cd:d2) + softAP(1a:fe:34:9c:cd:d2)
#6 ets_task(4020ed88, 28, 3fff99a8, 10)
add if0
>>> sta_if.connect('mySSID', 'password')
scandone
state: 0 -> 2 (b0)
state: 2 -> 3 (0)
state: 3 -> 5 (10)
add 0
aid 9
cnt

connected with mySSID, channel 11
dhcp client start...
ip:192.168.0.21,mask:255.255.255.0,gw:192.168.0.1
>>> sta_if.isconnected()
True
>>> sta_if.ifconfig()
('192.168.0.21', '255.255.255.0', '192.168.0.1', '8.8.8.8')
```

### Star Wars Asciimation

This is [a pretty neat demo](http://docs.micropython.org/en/latest/esp8266/esp8266/tutorial/network_tcp.html#star-wars-asciimation)
.. is this really the whole movie in glorious ascii art!??

```
import socket
addr_info = socket.getaddrinfo("towel.blinkenlights.nl", 23)
addr = addr_info[0][-1]
s = socket.socket()
s.connect(addr)
while True:
    data = s.recv(500)
    print(str(data, 'utf8'), end='')
```

Some console clips...

![asciimation_1](./assets/asciimation_1.png?raw=true)
![asciimation_2](./assets/asciimation_2.png?raw=true)
![asciimation_3](./assets/asciimation_3.png?raw=true)

## Construction

![Breadboard](./assets/GettingStarted_bb.jpg?raw=true)

![The Schematic](./assets/GettingStarted_schematic.jpg?raw=true)

![The Build](./assets/GettingStarted_build.jpg?raw=true)

## Credits and References

* [official site](http://www.micropython.org/)
* [MicroPython ESP8266 docs](http://docs.micropython.org/en/latest/esp8266/)
* [MicroPython ESP8266 downloads](http://micropython.org/download#esp8266)
* [MicroPython](https://github.com/micropython/micropython) - GitHub
* [kickstarter](http://www.kickstarter.com/projects/214379695/micro-python-python-for-microcontrollers)
* [Building and Running MicroPython on the ESP8266](https://learn.adafruit.com/micropython-basics-how-to-load-micropython-on-a-board)
* [Building and Running MicroPython on the ESP8266](https://learn.adafruit.com/building-and-running-micropython-on-the-esp8266?view=all) - original version
* [esptool](https://github.com/themadinventor/esptool)
* [Star Wars Asciimation](http://docs.micropython.org/en/latest/esp8266/esp8266/tutorial/network_tcp.html#star-wars-asciimation)
* [LEAP#194 DIYDevBoard](../../DIYDevBoard) - the dev board I'm using to host the ESP-01
* [..as mentioned on my blog](https://blog.tardate.com/2017/09/leap344-micropython-on-the-esp8266.html)
