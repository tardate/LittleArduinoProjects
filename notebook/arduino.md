# Arduino Notes


## Getting Arduino Nano to work on a Mac

* see the offical [MacOSX setup notes](http://www.arduino.cc/en/Guide/MacOSX)
* if necessary, install the [FTDIUSBSerialDriver_v2_2_18.dmg](http://www.ftdichip.com/Drivers/VCP.htm)
* see the [arduino forum](http://forum.arduino.cc/index.php?topic=261375.0) - general discussion and updates on the issue

## Arduinos using the CH340G serial chip
Examined Arduino Nano and confirmed it is using the CH340G serial chip, which MacOSX Yosemite does not recognise by default

See ["How to use cheap Chinese Arduinos that come with with CH340G / CH341G Serial/USB chip"](http://kiguino.moos.io/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html) - a great guide.

Driver available from Chinese manufacturer 江苏沁恒股份有限公司 and mirrored [here](http://kiguino.moos.io/downloads/CH341SER_MAC.ZIP).

    sudo nvram boot-args="kext-dev-mode=1"
    # reboot and yay, it works!

NB: to look at device logs: `sudo dmesg`

There also seems to be a professional drive kit available(at cost) from https://www.mac-usb-serial.com/

