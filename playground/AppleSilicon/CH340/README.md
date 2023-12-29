# #736 CH340 on Apple Silicon

Programming over CH340-based serial interfaces (such as with some versions of the Arduino Nano) from macOS on Apple Silicon

![Build](./assets/CH340_build.jpg?raw=true)

## Notes

Apple's macOS does not come with drivers for the CH340 series of USB-Serial interface chips.

The CH340 is commonly used instead of FTDI chips and drivers.
They are produced by [南京沁恒微电子股份有限公司 (Nanjing Qinheng Microelectronics Co., Ltd.)](https://www.wch.cn/).

### Circuit Design

I am testing with a version of the Arduino Nano that uses the CH340G chip.

![bb](./assets/CH340_bb.jpg?raw=true)

![schematic](./assets/CH340_schematic.jpg?raw=true)

### Obtaining Drivers

Current drivers are available from
[keyestudio](https://wiki.keyestudio.com/Download_CH340_Driver_on_MAC_System):

* CH34xVCPDriver.pkg - I think for use with OS X 10.9 to OS X 10.15
* CH34xVCPDriver.dmg - for use in later macOS version (this is the driver I am using)

### Driver Installation

Running `CH34xVCPDriver.dmg` - drag to Applications to install as usual

![install1](./assets/install1.png?raw=true)

run the app from the Applications folder. Grant first-time access

![install2](./assets/install2.png?raw=true)

System Extension is initially blocked - go to System Settings

![install3](./assets/install3.png?raw=true)

From System Settings, allow the `CH34xVCPDriver.app` application:

![install4](./assets/install4.png?raw=true)

Install is a success!

![install5](./assets/install5.png?raw=true)

### Programming a CH340G Nano

Plugging in my Nano with hte CH340G interface driver, I see it correctly recognised in the System Report USB tree.
The Vendor ID 0x1a86 is the expected value.

![system_report](./assets/system_report.png?raw=true)

Programming the Nano with the [AppleSilicon.ino](../AppleSilicon.ino) sketch works perfectly:

![nano](./assets/nano.png?raw=true)

## Credits and References

* [Download CH340 Driver on MAC System](https://wiki.keyestudio.com/Download_CH340_Driver_on_MAC_System)
* [USBSerialDriverKit CH340g Not Appearing in /dev](https://forums.developer.apple.com/forums/thread/675685)
* [南京沁恒微电子股份有限公司 (Nanjing Qinheng Microelectronics Co., Ltd.)](https://www.wch.cn/)
* [FTDI](https://ftdichip.com/)
