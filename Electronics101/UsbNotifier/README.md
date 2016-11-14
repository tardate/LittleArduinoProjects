# #174 UsbNotifier

Tear-down and demo code for some old USB Webmail Notifier devices.

Here's a quick video of the blinky test program in action:

[![UsbNotifier demo](http://img.youtube.com/vi/KEg5rtU9RK4/0.jpg)](http://www.youtube.com/watch?v=KEg5rtU9RK4)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

So four of these [USB Webmail Notifier](http://www.usbgeek.com/products/usb-webmail-notifier) devices turned up in a dusty cupboard
in the office.

A quick tear-down shows they contain a super-simple circuit - just a
SONiX Technology SN8P2203SB 8-Bit microcontroller that handles the USB protocol and drives an RGB LED.
The SN8P2203SB is an old chip phased out 2010/04/30, superseded by the SN8P2240.

The USB implementation is extremely minimal - the device appears as a USB 1.0 HID device:
* Product ID: 0x1320
* Vendor ID:  0x1294  (RISO KAGAKU CORP.)
* Version:  1.00
* Speed:  Up to 1.5 Mb/sec
* Manufacturer: MAIL
* Current Required (mA):  100

A quick google reveals quite a bit of old code lying around for various projects using devices like this.
Most seem to use [libusb](http://www.libusb.org/) for convenience - and often 0.1 legacy libusb that.
As I'm mainly on MacOSX, the code is not much use since Apple no longer allows claiming of HID devices
and the libusb team decided not to try to get around that.

But as I just proved to myself, [hidapi](http://www.signal11.us/oss/hidapi/) works fine.

Now I just need to ponder on good ideas for what to do with these things!

### The Blinky Test

[blinky](./blinky/blinky.c) is a simple test program written in C using [hidapi](http://www.signal11.us/oss/hidapi/).
I've tested it on MacOSX. It probably works fine on Linux too, but may need some platform tweaks to compile on Windows.

I installed hidapi with [brew](http://brew.sh/):

```
$ brew install hidapi
```

Once `hidapi` is installed, the `blinky` test program is easily compiled and run:

```
cd blinky
make
./blinky
```

The `blinky` program can handle up to 4 Notifier devices and simply:
* reports the details of each device found
* cycles through a color test on each device until you stop it

With 4 of the notifiers plugged into a USB hub, here's what I get on my console:

```
$ make && ./blinky
gcc `pkg-config --cflags hidapi` -g -Wall -O3    blinky.c  `pkg-config --libs hidapi` -o blinky
Device Found
  type: 1294 1320
  path: USB_1294_1320_14540000
  serial_number:
  Manufacturer: MAIL
  Product:      MAIL

Device Found
  type: 1294 1320
  path: USB_1294_1320_14520000
  serial_number:
  Manufacturer: MAIL
  Product:      MAIL

Device Found
  type: 1294 1320
  path: USB_1294_1320_14510000
  serial_number:
  Manufacturer: MAIL
  Product:      MAIL

Device Found
  type: 1294 1320
  path: USB_1294_1320_14530000
  serial_number:
  Manufacturer: MAIL
  Product:      MAIL

Running a blinking demo; ctrl-c to end ..

```

And here are the 4 units blinking...

![UsbNotifier_blinking_demo](./assets/UsbNotifier_blinking_demo.jpg?raw=true)

### Device Teardown

![PCB front](./assets/UsbNotifier_pcb_front.jpg?raw=true)

![PCB rear](./assets/UsbNotifier_pcb_rear.jpg?raw=true)

## Credits and References
* [USB Webmail Notifier](http://www.usbgeek.com/products/usb-webmail-notifier)
* [SONiX SN8P2241 8-Bit OTP Microcontrollers product info](http://www.sonix.com.tw/article-en-1009-3146)
* [hidapi source](http://www.signal11.us/oss/hidapi/)
* [Someone hacked an earlier version](http://www.wabbitwanch.net/blog/?p=728) - basically just to use the LED
* [LightControlMenu](https://github.com/bettse/LightControlMenu) - a MacOSX Xcode project that looks like it might know how to talk to these devices
* [dbird notifier](http://sourceforge.net/projects/dbirdnotifier/) - interesting old project doing similar things
* [..as mentioned on my blog](http://blog.tardate.com/2016/02/littlearduinoprojects174-usb-led.html)
