# #351 RTL-SDR Dongle

Getting started with an R820T2+RTL2832U dongle and open-source SDR software on macOS (Gqrx, CubicSDR).

![Build](./assets/RtlSdrDongle_build.jpg?raw=true)

## Notes

I've been hearing about SDR and in particular [RTL-SDR](https://www.rtl-sdr.com/) for a while.
Time to jump in, especially with the many cheap USB dongles available.

I picked a random RTL2832U+R820T2 USB2.0 device [from a seller on aliexpress](https://www.aliexpress.com/item/NI5L-USB2-0Digital-DVB-T-SDR-DAB-FM-HDTV-TV-Tuner-Receiver-Stick-RTL2832U-R820T2-Free/32498634779.html).
Like most, it is marketed primarily as a DAB/HDTV receiver, but first thing I did was "throw away" the software provided (windows-only anyway),
as I was more interested in the device as a broad-spectrum SDR receiver.

I'm testing this with my favourite macOS machine.

## What is this R820T2+RTL2832U magic?

Cheap SDR dongles?
Apparently it all started when a bunch of folks (Antti Palosaari, Eric Fry and Osmocom)
found that the signal I/Q data could be accessed directly from the Realtek RTL2832U digital TV tuner chip,
allowing it to be turned into a wideband software defined radio receiver with just a little extra hardware and software.

Combined with a tuner front-end (commonly the Rafael Micro R820T2) in a USB dongle package with dinky antenna,
these now show up in droves online for under $20.

### Rafael Micro R820T2

The R820T2 is a highly integrated tuner from Rafael Micro of Taiwan.
They are notoriously guarded with information (datasheets under NDA etc),
but in essence:

* integrated low-noise amplifier that takes the RF input
* RF filter, mixer, and automatic gain control
* minimal external components required
* I²C controlled
* 3.3V, low-power ＜ ~180mA
* "supports all digital TV standards"

### Realtek RTL2832U

The [RTL2832U](http://www.realtek.com.tw/products/productsView.aspx?Langid=1&PFid=35&Level=4&Conn=3&ProdID=257)
is a digital TV demodulator that supports a USB 2.0 interface and requires a front-end tuner.
It is produced by Realtek of Taiwan.

### How they Work together

I found this RTLSDR design posted by hap4ev. I imagine these dongles do something similar..

[![block-diagram-hap4ev](https://i.imgur.com/Fpgu3bO.jpg)](https://imgur.com/gallery/la4YH)

## Unboxing and Specifications

Per the seller:

Contents:

* 1 X DVB-T
* 1 X Antenna
* 1 X Remote Control
* 1 X Disc (BlazeVid HDTV Player - Windows)

Specifications:

* Remote Control Size: Approx.8.6 X 4 X 0.6cm(L X W X H)
* DVB-T Size: Approx.8.8 X 2.7 X 0.8cm(L X W X H)
* Net Weight: 66g
* Type: R820T2
* Antenna Cable Length: Approx.108.5cm

Features:

* R820T2+RTL2832U chip
* Support SDR
* Support DAB
* Support FM
* Support DVB-T
* Watch and record digital terrestrial TV on PC or Laptop
* Full DVB-T bandwidth reception (6/7/8 MHz)
* Digital TV recording and playback as DVD quality
* Remote control
* Support Windows 2000/XP/Vista/WIN7
* Support both MPEG-2, MPEG-4(H.264) encoding

![unboxing](./assets/unboxing.jpg?raw=true)

## Plugging in: USB Connection

No issues with the device being recognised under MacOSX. Here's how it appears:

```sh
RTL2838UHIDIR:

  Product ID: 0x2838
  Vendor ID:  0x0bda  (Realtek Semiconductor Corp.)
  Version:  1.00
  Serial Number:  00000001
  Speed:  Up to 480 Mb/sec
  Manufacturer: Realtek
  Location ID:  0x14100000 / 3
  Current Available (mA): 500
  Current Required (mA):  500
```

![usb_connection](./assets/usb_connection.png?raw=true)

### Software

I picked two open source packages at random to try. Success with both! I'm liking CubicSDR in particular.

#### Gqrx SDR

[Gqrx](http://gqrx.dk/) is an
[open source](https://github.com/csete/gqrx)
software defined radio receiver (SDR)
by Alexandru Csete OZ9AEC. It uses the GNU Radio and Qt graphical toolkits.

Here's a shot of gqrz locked in on a [local FM station](https://ufm1003.sg/):

![gqrx_fm](./assets/gqrx_fm.png?raw=true)

#### CubicSDR

[CubicSDR](http://cubicsdr.com/) is an
[open source](https://github.com/cjcliffe/CubicSDR)
package by Charles J. Cliffe.
It uses liquid-dsp and SoapySDR libraries.

Here's a shot of CubicSDR locked in on a [local FM station](https://ufm1003.sg/):

![CubicSDR_fm](./assets/CubicSDR_fm.png?raw=true)

## Finding Interesting Signals in Singapore

Being a small city-state with a well-developed and urbanised environment,
I've always assumed that there's not much amateur radio action here, nor are the airways particularly friendly for
trying to pull down low-power signals from a-far.

Well, that's kinda true. I need to learn more, and this presentation
"The Journey through Amateur Radio" for the Singapore Heritage Festival by Roland Turner was a good start:

[![The Journey through Amateur Radio - Singapore Heritage Festival](https://img.youtube.com/vi/KvrZ5o4Q8kQ/0.jpg)](https://www.youtube.com/watch?v=KvrZ5o4Q8kQ)

While amateurs may be hard to find, the airways are obviously very busy with commercial traffic.
the population is very wired, and the ports (air and sea) are some of the busiest in the world.

The [Spectrum chart for Singapore](https://www.imda.gov.sg/-/media/imda/files/regulation-licensing-and-consultations/frameworks-and-policies/spectrum-management-and-coordination/spectrumchart.pdf?la=en) published by the IMDA does make the conventional allocations for amateur radio.

## Catching Some Sample Signals

.. and in doing so I discover that the dinky 5" aerial provided with the dongle (and where I put it)
is on the one hand surprisingly capable, while also having very little chance of picking out weaker signals.

The dongle appears to process signals from 24MHz to 1766Mhz.

The [Signal Identification Guide](https://www.sigidwiki.com/wiki/Signal_Identification_Guide) is a great resource
for trying to ident especially non-voice transmissions.

Here are some quick samples from my first session playing around..

Aircraft Communications Addressing and Reporting System (ACARS)..

![CubicSDR_acars](./assets/CubicSDR_acars.png?raw=true)

Air traffic control (AM voice)..

![CubicSDR_atc](./assets/CubicSDR_atc.png?raw=true)

## Credits and References

* [NI5L USB2.0 Digital DVB-T SDR DAB FM HDTV TV Tuner Receiver Stick RTL2832U+R820T2](https://www.aliexpress.com/item/NI5L-USB2-0Digital-DVB-T-SDR-DAB-FM-HDTV-TV-Tuner-Receiver-Stick-RTL2832U-R820T2-Free/32498634779.html) - from a seller on aliexpress
* [www.rtl-sdr.com](https://www.rtl-sdr.com/)
* [Rafael Micro](http://www.rafaelmicro.com/)
* [Realtek RTL2832U](http://www.realtek.com.tw/products/productsView.aspx?Langid=1&PFid=35&Level=4&Conn=3&ProdID=257)
* [Gqrx](http://gqrx.dk/)
* [Gqrx - GitHub](https://github.com/csete/gqrx)
* [CubicSDR](http://cubicsdr.com/)
* [CubicSDR - GitHub](https://github.com/cjcliffe/CubicSDR)
* [Spectrum chart for Singapore](https://www.imda.gov.sg/-/media/imda/files/regulation-licensing-and-consultations/frameworks-and-policies/spectrum-management-and-coordination/spectrumchart.pdf?la=en)
* [Signal Identification Guide](https://www.sigidwiki.com/wiki/Signal_Identification_Guide)
* [..as mentioned on my blog](https://blog.tardate.com/2017/10/leap351-sdr-with-cheap-r820t2-rtl2832u-dongles.html)
