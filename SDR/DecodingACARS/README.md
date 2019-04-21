# #352 DecodingACARS

Decoding ACARS with rtl_acars_ng and a R820T2+RTL2832U dongle on MacOSX.

![Build](./assets/DecodingACARS_build.jpg?raw=true)

## Notes

I'm playing with a cheap [RTL-SDR Dongle](../RtlSdrDongle)
and one of the signals I can pick up quite well are the
[Aircraft Communications Addressing and Reporting System (ACARS)](https://en.wikipedia.org/wiki/Aircraft_Communications_Addressing_and_Reporting_System)
transmissions from the [air traffic around Singapore](http://flightaware.com/live/airport/WSSS).

ACARS is a short message digital datalink protocol, and thus needs decoding.

I quickly found a promising open-source package to try: [rtl_acars_ng](https://github.com/gat3way/rtl_acars_ng)


## Compiling `rtl_acars_ng`

I'm running on MacOSX and use brew for package management. So it was this easy...

```
$ brew install rtl-sdr
$ git clone git@github.com:gat3way/rtl_acars_ng.git
$ cd rtl_acars_ng
$ make
gcc -o rtl_acars_ng rtl_acars_ng.c `pkg-config --cflags --libs librtlsdr libusb-1.0` -lpthread -lm -O2
36 warnings generated.
```

## Command-line Options

```
$ ./rtl_acars_ng -h
rtl_acars_ng - decoding ACARS transmissions with RTL2832 based DVB-T receivers

Usage:  rtl_acars_ng -f freq [-options]
  -f frequency_to_tune_to [Hz]
   (use multiple -f for scanning, requires squelch)
   (ranges supported, -f 118M:137M:25k)
   (try 131.55M, 129.125M, 130.025M, or 130.425M)
  [-d device_index (default: 0)]
  [-g tuner_gain (default: automatic)]
  [-l squelch_level (default: 0/off)]
  [-o oversampling (default: 1, 4 recommended)]
  [-p ppm_error (default: 0)]
  [-r squelch debug mode ]
  [-t squelch_delay (default: 0)]
   (+values will mute/scan, -values will exit)
  [-D datasets_dir (default: ./datasets)]
  [-F enables Hamming FIR (default: off/square)
```

## Finding ACARS

The [Signal Identification Guide](https://www.sigidwiki.com/wiki/Aircraft_Communications_Addressing_and_Reporting_System_(ACARS))
indicates I should expect it probaby at 131.550 MHz in my area.

With [CubicSDR](http://cubicsdr.com/) I found ACARS broadcasts centered around 131.546MHz

![acars](./assets/acars.png?raw=true)


## Trial Run

So firing up rtl_acars_ng instead .. success!!

```
$ ./rtl_acars_ng -f 131546000
Found 1 device(s):
  0:  Realtek, RTL2838UHIDIR, SN: 00000001
Using device 0: Generic RTL2832U OEM
Found Rafael Micro R820T tuner
Oversampling input by: 21x.
Oversampling output by: 1x.
Buffer size: 8.13ms
Tuned to 131798000 Hz.
Sampling at 1008000 Hz.
Output at 48000 Hz.
Exact sample rate is: 1008000.009613 Hz
Tuner gain set to automatic.

Loaded: 406995 aircrafts from dataset.....
Loaded: 7733 airports from dataset.....
Loaded: 110952 flights from dataset.....
Loaded: 365 ACARS message labels from dataset.....
Listening for ACARS traffic...


[BEGIN_MESSAGE]----------------------------------------------------------

RX_IDX: 0
CRC: Correct
Timestamp: 28/10/2017 11:56
ACARS mode: 2
Message label: _ (ACK)
Aircraft reg: .9V-SFK, flight id: SQ7294
Aircraft: Boeing 747-412F
Registration: 9V-SFK
Mode-S ID: 76CCCB
Airline: Singapore Airlines Cargo

Block id: 52,  msg. no: S57A
Message content:-


[END_MESSAGE ]------------------------------------------------------------
```

![DecodingACARS_build](./assets/DecodingACARS_build.jpg?raw=true)


## Credits and References
* [Aircraft Communications Addressing and Reporting System (ACARS)](https://en.wikipedia.org/wiki/Aircraft_Communications_Addressing_and_Reporting_System) - wikipedia
* [rtl_acars_ng](https://github.com/gat3way/rtl_acars_ng) - GitHub
* [flightaware - Singapore](http://flightaware.com/live/airport/WSSS)
* [..as mentioned on my blog](https://blog.tardate.com/2017/10/leap352-decoding-acars.html)
