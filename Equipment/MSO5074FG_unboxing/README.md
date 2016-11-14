# #156 MSO5074FG_unboxing

Unboxing and first tests of a Hantek MSO5074FG oscilloscope


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

For a while I've been contemplating a new oscilloscope purchase.
In the end my decision boiled down to two in a similar price range:
* Hantek MSO5074FG - 70MHz 4-channel scope with 25MHz function generator and 8 channel logic analyzer
* Rigol DS1074Z - 70MHz 4-channel scope

It really was a balance between the brand value of Rigol and the excellent communications interfaces of the DS1074Z,
compared to an unbeatable price and set of features in the Hantek MSO5074FG (but without the range of communications interfaces).
In the end I decided to take a bet on the Hantek.

The MSO5074FG is in the [Hantek MSO5054F(G) range](http://www.hantek.com/en/ProductDetail_3_127.html) - basically the same specs
but with increased bandwidth.

I was concerned at first by the fact the the product is not listed on http://www.hantek.com,
but very pleasantly surprised when emails to both Hantek and the [seller on aliexpress](http://www.aliexpress.com/store/100653)
were answered within hours, with the explanation that the MSO5074FG is not marketed internationally (yet) and so not listed on
the English web site.

### Unboxing and First Impressions

Not disappointed! With DHL shipping, I had it in my hands within a week. All arrived to spec, nothing missing and no damage.
I even had an email from the seller with a picture of the benchtest they performed prior to shipping.

First thoughts?

* build quality is quite impressive
* knobs and buttons all have a firm positive feel
* no obvious issues such as misalignment of labels or connectors with the faceplate

A CD comes with the product, but I believe nothing that you cannot also download from the
[Hantek product page](http://www.hantek.com/en/ProductDetail_3_127.html). That includes manuals and software.
The manual is pretty decent; available in English and all the basic info and technical specs you need to use the product correctly.

![parts](./assets/MSO5074FG_parts.jpg?raw=true)

### First Boot and Probe Compensation

Switching on .. and it boots fine! From system info I can see that this is it's second boot (the first being the seller's benchtest).

The manual describes how to perform probe compensation and that all goes well...

![probe comp](./assets/MSO5074FG_probe_comp.jpg?raw=true)

### First Test - DDS Sine Wave

Still finding my way around the features, but here's an easy test:
* setup the DDS function generator for a simple 1kHz sine wave
* monitor the function generator output on channel 1

Here's what it looks like:

![DDS Sine Trace](./assets/MSO5074FG_dds_sine_trace.jpg?raw=true)

And here's a test of the 'save to USB device' to capture the screenshot.
Unfortunately I still haven't figured out how to take the screenshot without the utility menu edging it's way into the picture:

![DDS Sine Trace Export](./assets/dds_sine.jpg?raw=true)

### Conclusion .. For Now

OK, I've barely started to scratch the surface, and have yet to try anything that will really push the scope's capabilities.
As I learn more or run into issues, I'll probably update my notes here.

But so far I'm a very happy camper!
It will definitely start popping up as a tool used in the little projects I add to this collection.

## Essential Scope Viewing

Some great tutorials:

* [Oscilloscope operation AC DC GND coupling](https://youtu.be/VJJ-y9gjjkI) - BTCInstrumentation - a great starter on coupling
* [#10: AC / DC Coupling on an Oscilloscope](https://youtu.be/Hkq-fvb5-NI) - w2aew - more practical implications of coupling
* [EEVblog #279 - How NOT To Blow Up Your Oscilloscope!](https://youtu.be/xaELqAo4kkQ) - EEVblog - understanding "ground" is important
* [#9: Basic 1X and 10X Oscilloscope Probe tutorial](https://youtu.be/SX4HGNWBe5M) - w2aew - passive probes in depth
* [#206: Importance of 10X Probe Compensation with your Oscilloscope](https://youtu.be/oxJQr4dKnys) - w2aew - compensation in depth
* [#69: Basics of Analog Oscilloscope Bandwidth](https://youtu.be/hXbPnY7VIes) - w2aew - what is scope bandwidth and how to measure it
* [#160: Oscilloscope Basics, and how they can be used in the hamshack](https://youtu.be/067W7h1BhxE) - if you have 1.5 hours and want a thorough education in scopes, watch this great presentation by w2aew

## Credits and References
* [Hantek MSO5074FG listing on aliexpress](http://www.aliexpress.com/item/High-quality-Hantek-MSO5074FG-70Mhz-4-Channel-Oscilloscope-8-Channel-Logic-Analyzer-25MHz-Arb-Waveform-Generator/1596199238.html) from seller [Shenzhen Laesent Technology Co., Ltd.](http://www.aliexpress.com/store/100653)
* [Hantek MSO5054F(G)](http://www.hantek.com/en/ProductDetail_3_127.html) product listing, manuals and software
* [Rigol DS1074Z](http://www.rigolna.com/products/digital-oscilloscopes/ds1000Z/ds1074z/)
