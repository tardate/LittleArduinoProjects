# #741 PLJ-1601 Frequency Counter

Testing the PLJ-1601-C 0.1MHz-1.2GHz Frequency counter.

![Build](./assets/PLJ1601_build.jpg?raw=true)

## Notes

I bought the
"PLJ-1601-C 0.1MHz-1.2GHz Frequency counter"
back in 2015 for SGD$15.99 but haven't used it much beyond an unboxing test. IIRC, it didn't seem that accurate or useful so it got put aside...

I just dug it out and finally figured out some of the "magic settings" required to get it to work. Not so bad after all! Just needs a case or base...

Long story short, the two settings I made to get it working well:

* disable the filter for signals below 3MHz
* make sure the reference is set to 13 MHz internal benchmark. It seems that by default it was set for 12.8 MHz external benchmark.

And two important things to note:

* the signal input ground line is actually connected to power ground, so be careful when interconnecting equipment.
* the JST connector for the input signal is wired the reverse of the more common convention, so beware of accidentally shorting to ground.

### Product Specs

The original seller listing is long gone, but I've seen it listed recently on amazon and alibaba:

* <https://www.amazon.sg/Reland-Sun-PLJ-1601-C-measurement-0-1MHz-1-2GHz/dp/B091KM5M22>
* <https://www.alibaba.com/product-detail/PLJ-1601-C-Frequency-meter-frequency_1600588075139.html>

It seems the PLJ-1601 has since been superseded by the PLJ-0802-E
e.g. <https://www.aliexpress.com/item/1005008750872275.html>

I found some manuals for the PLJ-1601 on the 2e0dfu blog:
<https://2e0dfu.wordpress.com/2016/10/09/plj-1601-c-frequency-counter-manual-english-language-version/>.
these were invaluable for getting the device working effectively. For posterity, I've mirrored the manuals here:

* [Chinese version](./assets/plj_1601a-manual-zh.pdf)
* [English version](./assets/plj_1601a-manual-en.pdf)

### Test Circuit

For testing, I'm using an [FY3200S](../FY3200S/) signal generator set for a 0.4V peak-peak sine wave through a simple attenuation circuit as follows:

![bb](./assets/PLJ1601_bb.jpg?raw=true)

![schematic](./assets/PLJ1601_schematic.jpg?raw=true)

### Tests

My first tests were not great.
Measured values are noticeably off.
For example, a 6 MHz sine measuring 5.9 MHz:

![test01a](./assets/test01a.jpg?raw=true)

The scope shows the signal source is really bang-on 6 MHz:

![test-signal](./assets/test-signal.gif?raw=true)

### Making Adjustments

After reading the manual, I switched the reference to 13 MHz internal benchmark (through the on-screen menu). It seems that by default it was set for 12.8 MHz external benchmark.

And now ... oh, my: measurements are spot on:

![test01b](./assets/test01b.jpg?raw=true)

Going below 3 MHz, it is necessary to turn off the filter (through the on-screen menu).

![test01c](./assets/test01c.jpg?raw=true)

At the upper end of the signal generator range (24 MHz), measurements are starting to get a little off:

![test01d](./assets/test01d.jpg?raw=true)

## Credits and References

* PLJ-1601 product listings:
    * <https://www.amazon.sg/Reland-Sun-PLJ-1601-C-measurement-0-1MHz-1-2GHz/dp/B091KM5M22>
    * <https://www.alibaba.com/product-detail/PLJ-1601-C-Frequency-meter-frequency_1600588075139.html>
* Documentation
    * <https://2e0dfu.wordpress.com/2016/10/09/plj-1601-c-frequency-counter-manual-english-language-version/>
* [PLJ-0802-E listing](https://www.aliexpress.com/item/1005008750872275.html)
