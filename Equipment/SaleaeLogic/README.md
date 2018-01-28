# #260 SaleaeLogic

Checking out a second-hand Saleae Logic (a 24 MS/s, 8 channel USB logic analyzer - that works on a Mac!!).

![Build](./assets/SaleaeLogic_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I recently had a Saleae Logic fall into my hands - it's an old model and was looking for a good home.

It is similar to the [current range of products](https://www.saleae.com), but lower specs:
* USB 2.0
* 24 MS/s
* 8 digital channels

I was a little curious, but didn't expect much since it was a discontinued product,
and I wasn't even sure if I could find the right software to make it go.

While playing with the [M62429](../../Electronics101/DigitalPots/M62429) today, I thought "why not give the Logic a go".

And I was very pleasantly surprised. Saleae have done a brilliant job of creating an excellent experience,
and continuing to support their discontinued products.

I was up and running in about 30 seconds!

I think this device just went from being a curiosity to something I can see my self reaching for quite frequently.

### Software

This put a smile on my face ... go to [Saleae Downloads](https://www.saleae.com/downloads), and they
have a good looking site that recognises me as a MacOSX user and offers to download Version 1.2.10 for Mac OSX 10.7 Lion+.
If only more electronics equipment manufactururs would come to the multi-platform party!

The software installed like a "real" Mac app, and immediately recognised the old Logic when I plugged it into the USB.
Here's my first trace. Unfortunately not a standard I2C or SPI protocol so I'm not sure how well the protocol recognition/analysis works yet.

![custom_serial_protocol_example](./assets/custom_serial_protocol_example.png?raw=true)

The USB device profile as it shows up on my machine:

```
Logic:

  Product ID: 0x3881
  Vendor ID:  0x0925
  Version:  0.00
  Speed:  Up to 480 Mb/sec
  Manufacturer: Saleae LLC
  Location ID:  0x14520000 / 23
  Current Available (mA): 500
  Current Required (mA):  100
```

![SaleaeLogic_test](./assets/SaleaeLogic_test.jpg?raw=true)


## Credits and References
* [Logic Tech Specs](http://downloads.saleae.com/specs/Logic+Tech+Specs.pdf) - for the
* [Saleae Downloads](https://www.saleae.com/downloads)
* [..as mentioned on my blog](https://blog.tardate.com/2017/03/leap260-saleae-logic.html)
