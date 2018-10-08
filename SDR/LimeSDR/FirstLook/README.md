# #421 LimeSDR/FirstLook

Unboxing and first test of the LimeSDR-USB software-defined radio with MacOSX host.

![Build](./assets/FirstLook_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes


I think I first heard about [LimeSDR-USB](https://wiki.myriadrf.org/LimeSDR-USB) on
[The Amp Hour](https://theamphour.com/314-an-interview-with-josh-lifton/).

I was convinced to jump in and give it a go particularly because
of the fully open-source nature of the platform - from hardware all the way to
software, including FPGA code. At the time, it was
available for purchase on [CrowdSupply](https://www.crowdsupply.com/lime-micro/limesdr) (still appears to be the case).

The unit is suited to research and development in a wide range of areas,
but I suspect as I get more into this I will be mainly focused on areas such as

* Test and measurement - e.g. spectrum analyzer
* Amateur radio


### About LimeSDR

Introductory video: What is the LimeSDR?

[![clip](http://img.youtube.com/vi/LnJLiOCEq9I/0.jpg)](http://www.youtube.com/watch?v=LnJLiOCEq9I)

### Hardware

Full details of the hardware are available on the Myriad-RF Wiki.
A good starting point: [LimeSDR-USB hardware description](https://wiki.myriadrf.org/LimeSDR-USB_hardware_description)


Summary of key features & specifications

* RF Transceiver: Lime Microsystems LMS7002M MIMO FPRF
* FPGA: Altera Cyclone IV EP4CE40F23 - also compatible with EP4CE30F23
* Memory: 256 MBytes DDR2 SDRAM
* USB 3.0 controller: Cypress USB 3.0 CYUSB3014-BZXC
* Oscillator: Rakon RPT7050A @30.72MHz
* Continuous frequency range: 100 kHz – 3.8 GHz
* Bandwidth: 61.44 MHz
* RF connection: 10 U.FL connectors (6 RX, 4 TX)
* Power Output (CW): up to 10 dBm
* Multiplexing: 2x2 MIMO
* Power: USB connector or optional external power supply
* Status indicators: programmable LEDs
* Antenna accessory pack:
    - Four antennas with SMA connectors
    - Four U.FL to SMA cables included - 8” (~203mm) cable, not measuring connectors
    - Antennas are omni-directional, and bend to -90, -45, 0, 45, and 90 degrees
    - Antennas tuned to the major bands: 800-960MHz / 1710-2170MHz / 2400-2700MHz


### LimeSDR-USB RF Ports

The unit has two transmit and two receive channels. There are multiple U.FL connectors
on the board for different applications.


My initial choices for where I've connected
the 4 antennas (A, B, C, D) are below:


| Label | Description                               | Antenna    |
|-------|-------------------------------------------|------------|
| RX1_H | Channel 1 RX: frequencies above 1.5GHz    |            |
| RX2_H | Channel 2 RX: frequencies above 1.5GHz    |            |
| RX1_L | Channel 1 RX: frequencies below 1.5GHz    | A          |
| RX2_L | Channel 2 RX: frequencies below 1.5GHz    | B          |
| RX1_W | Channel 1 RX: wideband                    |            |
| RX2_W | Channel 2 RX: wideband                    |            |
| TX1_1 | Channel 1 TX: primary (all frequencies)   | C          |
| TX2_1 | Channel 2 TX: primary (all frequencies)   | D          |
| TX1_2 | Channel 1 TX: secondary (all frequencies) |            |
| TX2_2 | Channel 2 TX: secondary (all frequencies) |            |



### LimeSDR Acrylic Case Assembly

Assembling the optional acrylic case is [documented here](https://github.com/myriadrf/LimeSDR-USB_acrylic_case#assembly),
and there is also a useful video:


[![clip](http://img.youtube.com/vi/4QyM0tKj0Co/0.jpg)](http://www.youtube.com/watch?v=4QyM0tKj0Co)


### Assembly


Here's my kit coming together from parts:

![kit_parts](./assets/kit_parts.jpg?raw=true)

![kit_board](./assets/kit_board.jpg?raw=true)

![kit_case_1](./assets/kit_case_1.jpg?raw=true)


### USB Connection

[LimeSDR Hardware Installation](https://wiki.myriadrf.org/LimeSDR_Hardware_Installation) provides details on connection options.

I'm running on MacOSX, so simply plugging into one of the USB ports and the device is correctly recognised:

> LimeSDR-USB:
>
>   Product ID: 0x6108
>   Vendor ID:  0x1d50
>   Version:  0.00
>   Serial Number:  0009070105C6281F
>   Speed:  Up to 480 Mb/sec
>   Manufacturer: Myriad-RF
>   Location ID:  0x14200000 / 22
>   Current Available (mA): 500
>   Current Required (mA):  100
>   Extra Operating Current (mA): 0

![usb_device_tree](./assets/usb_device_tree.png?raw=true)


### Installing Lime Suite

[Lime Suite](https://wiki.myriadrf.org/Lime_Suite) appears to be the quickest way to get something up and running.
Fortunately there is [homebrew support provided by pothosware](https://github.com/pothosware/homebrew-pothos/wiki),
so it turned out to be a piece of cake to isntall:


```
brew tap pothosware/homebrew-pothos
brew update
brew install limesuite
```

After installation, a quick test with `SoapySDRUtil` indicates my board is correctly detected:

```
$ SoapySDRUtil --find
######################################################
## Soapy SDR -- the SDR abstraction library
######################################################

Found device 0
  addr = 1d50:6108
  driver = lime
  label = LimeSDR-USB [USB 2.0] 9070105C6281F
  media = USB 2.0
  module = FX3
  name = LimeSDR-USB
  serial = 0009070105C6281F
```

### Getting Started with LimeSuiteGUI

There's [guide for getting started with LimeSuiteGUI](https://wiki.myriadrf.org/Getting_Started_with_LimeSDR-USB_and_LimeSuiteGUI)
(just ignore the Windows-specific screenshots).

On MacOSX, it is started from the command line with `LimeSuiteGUI`

First step is to connect to the board:

![LimeSuiteGUI_connect](./assets/LimeSuiteGUI_connect.png?raw=true)

At first I saw this message popup in the log panel, indicating my firmware is due for an update:

> [22:00:04] WARNING: Gateware version mismatch!
>   Expected gateware version 2, revision 16
>   But found version 2, revision 8
>   Follow the FW and FPGA upgrade instructions:
>   http://wiki.myriadrf.org/Lime_Suite#Flashing_images
>   Or run update on the command line: LimeUtil --update

Following the instruction `LimeUtil --update` updated the board without issue, and I no longer see the warning.


### Quick Test

Now I'm working through the [LimeSDR-USB Quick Test](https://wiki.myriadrf.org/LimeSDR-USB_Quick_Test).


My WCDMA loopback FFT looks as expected:

![LimeSuiteGUI_WCDMA_loopback_test](./assets/LimeSuiteGUI_WCDMA_loopback_test.png?raw=true)

More to come...


## Credits and References
* [LimeSDR](https://www.crowdsupply.com/lime-micro/limesdr) - crowdsupply
* [Myriad-RF Wiki - LimeSDR](https://wiki.myriadrf.org/LimeSDR)
* [The Amp Hour #314 – An Interview with Josh Lifton](https://theamphour.com/314-an-interview-with-josh-lifton/)
* [Lime Suite](https://wiki.myriadrf.org/Lime_Suite)
