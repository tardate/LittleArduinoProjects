# #344 ESP8266 GettingStarted with MicroPython

Getting MicroPython up and running with an ESP-01 ESP8266. Updated with the latest firmware from 2025-12-09.

![Build](./assets/GettingStarted_build.jpg?raw=true)

## Notes

I first heard about MicroPython from the [kickstarter](http://www.kickstarter.com/projects/214379695/micro-python-python-for-microcontrollers)
campaign to open source the software.

Although it makes more sense to use it with a more capable board, I'm starting with a 512kb ESP-01 module,
hosted in the [LEAP#194 DIYDevBoard](../../DIYDevBoard/).

So the first test is to flash the ESP8266 with MicroPython and take it for a test-drive.

The
[MicroPython ESP8266 docs](http://docs.micropython.org/en/latest/esp8266/) and
[Adafruit guide](https://learn.adafruit.com/micropython-basics-how-to-load-micropython-on-a-board)
make this pretty straight-forward!

NOTE: I first completed this in late 2017 with `esptool.py v2.1` and firmware `esp8266-512k-20170925-v1.9.2-120-gf0082630.bin`.
As of Jan-2016, I've updated the notes below with `esptool.py v4.8.1` and the latest firmware `ESP8266_GENERIC-FLASH_512K-20251209-v1.27.0.bin`.

### Programming Setup

I'm using a [LEAP#194 DIYDevBoard](../../DIYDevBoard/) to host the ESP-01 module,
and a cheap [CH340G-based USB to UART adapter](https://www.aliexpress.com/item/CH340-module-USB-to-TTL-CH340G-upgrade-download-a-small-wire-brush-plate-STC-microcontroller-board/32354359382.html).
With the
[correct drivers installed](../../../notebook/arduino/#arduinos-using-the-ch340g-serial-chip),
it shows up in the tty device list.

My host computer is running macOS.

The notes below refer to switching flash mode and reset. These are DIP switches on the dev board.

### esptool

I'll need the [esptool](https://github.com/themadinventor/esptool) to flash the device.
It's python, so install with pip.

```sh
pip install esptool
```

### Testing the Connection

First find the device the CH340G-based USB to UART adapter is connected on, and set that as a variable for later use:

```sh
$ export ESP_PORT=$(ls /dev/tty.wchusb*)
$ echo ${ESP_PORT}
/dev/tty.wchusbserial2420
```

Verify the esptool install and connection by getting the chip_id.
This requires a switch into flash mode and reset on the dev board before it responds...

```sh
$ esptool.py --port ${ESP_PORT} chip_id
esptool.py v4.8.1
Serial port /dev/tty.wchusbserial2420
Connecting....
Detecting chip type... Unsupported detection protocol, switching and trying again...
Connecting...
Detecting chip type... ESP8266
Chip is ESP8266EX
Features: WiFi
Crystal is 26MHz
MAC: 18:fe:34:9c:cd:d2
Uploading stub...
Running stub...
Stub running...
Chip ID: 0x009ccdd2
Hard resetting via RTS pin...
```

### Flashing with MicroPython

Downloading the latest 512k build:

```sh
wget https://micropython.org/resources/firmware/ESP8266_GENERIC-FLASH_512K-20251209-v1.27.0.bin
```

Erasing then flash first (as recommended, probably not really necessary).
Again, this requires a switch into flash mode and reset on the dev board before it responds...

```sh
$ esptool.py --port ${ESP_PORT} erase_flash
esptool.py v4.8.1
Serial port /dev/tty.wchusbserial2420
Connecting....
Detecting chip type... Unsupported detection protocol, switching and trying again...
Connecting...
Detecting chip type... ESP8266
Chip is ESP8266EX
Features: WiFi
Crystal is 26MHz
MAC: 18:fe:34:9c:cd:d2
Uploading stub...
Running stub...
Stub running...
Erasing flash (this may take a while)...
Chip erase completed successfully in 1.2s
Hard resetting via RTS pin...
```

Writing the image.
Again, this requires a switch into flash mode and reset on the dev board before it responds...

```sh
$ esptool.py --port ${ESP_PORT} --baud 115200 write_flash --flash_size=detect 0 ESP8266_GENERIC-FLASH_512K-20251209-v1.27.0.bin
esptool.py v4.8.1
Serial port /dev/tty.wchusbserial2420
Connecting....
Detecting chip type... Unsupported detection protocol, switching and trying again...
Connecting...
Detecting chip type... ESP8266
Chip is ESP8266EX
Features: WiFi
Crystal is 26MHz
MAC: 18:fe:34:9c:cd:d2
Uploading stub...
Running stub...
Stub running...
Configuring flash size...
Auto-detected Flash size: 512KB
Flash will be erased from 0x00000000 to 0x0007afff...
Flash params set to 0x0000
Compressed 501488 bytes to 337278...
Wrote 501488 bytes (337278 compressed) at 0x00000000 in 29.7 seconds (effective 134.9 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting via RTS pin...
```

### Testing the REPL

First switch off the flash mode and reset on the dev board..
Using `screen` to open a tty console and run some python and exercise the MicroPython libraries...

```sh
$ screen ${ESP_PORT} 115200

>>> print('hello esp8266!')
hello esp8266!
>>> import machine
>>> pin = machine.Pin(2, machine.Pin.OUT)
>>> pin.on()
>>> pin.off()
>>>
```

With an LED and current limiting resistor connected to pin2/GPIO2, the commands above toggle it on and off.

More information:

* [MicroPython machine library](https://docs.micropython.org/en/latest/library/machine.html)
* [Pin class](https://docs.micropython.org/en/latest/library/machine.Pin.html)

### Connecting to WiFi

Obviously `mySSID` and `password` are not my real credentials..

```sh

>>> import network
>>> wlan = network.WLAN(network.WLAN.IF_STA)
>>> wlan.active(True)
#4 ets_task(4020f538, 28, 3fff97e0, 10)
>>> wlan.scan()
[(b'SSID1', b'\x90r@\x0f[\xf8', 1, -48, 3, 0), (b'SSID2', b'\xe0\x1f+\xa8\xebz', 1, -88, 3, 0)...]
>>> wlan.isconnected()
False
>>> wlan.ipconfig('addr4')
('0.0.0.0', '0.0.0.0')
>>> wlan.connect('mySSID', 'password')
>>> wlan.isconnected()
True
>>> wlan.config('mac')
b'\x18\xfe4\x9c\xcd\xd2'
>>> print('network config:', wlan.ipconfig('addr4'))
network config: ('192.168.10.80', '255.255.255.0')
>>>

```

More information:

* [Networking docs](https://docs.micropython.org/en/latest/esp8266/quickref.html#networking) for more information.

### Star Wars Asciimation

This is [a pretty neat demo](https://docs.micropython.org/en/latest/esp8266/tutorial/network_tcp.html#star-wars-asciimation)
.. is this really the whole movie in glorious ascii art!??

NOTE: the following was captured back in 2016. Unfortunately, the `towel.blinkenlights.nl` site appears to no longer be online.

```sh
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

Designed with Fritzing: see [GettingStarted.fzz](./GettingStarted.fzz).

![Breadboard](./assets/GettingStarted_bb.jpg?raw=true)

![The Schematic](./assets/GettingStarted_schematic.jpg?raw=true)

![The Build](./assets/GettingStarted_build.jpg?raw=true)

## Credits and References

* [official site](https://micropython.org/)
* [MicroPython ESP8266 docs](https://docs.micropython.org/en/latest/esp8266/quickref.html)
* [MicroPython ESP8266 downloads](https://micropython.org/download/ESP8266_GENERIC/)
* [MicroPython](https://github.com/micropython/micropython) - GitHub
* [kickstarter](https://www.kickstarter.com/projects/214379695/micro-python-python-for-microcontrollers)
* [Building and Running MicroPython on the ESP8266](https://learn.adafruit.com/micropython-basics-how-to-load-micropython-on-a-board)
* [Building and Running MicroPython on the ESP8266](https://learn.adafruit.com/building-and-running-micropython-on-the-esp8266?view=all) - original version
* [esptool](https://github.com/themadinventor/esptool)
* [Star Wars Asciimation](https://docs.micropython.org/en/latest/esp8266/tutorial/network_tcp.html#star-wars-asciimation)
* [LEAP#194 DIYDevBoard](../../DIYDevBoard/) - the dev board I'm using to host the ESP-01
* [..as mentioned on my blog](https://blog.tardate.com/2017/09/leap344-micropython-on-the-esp8266.html)
