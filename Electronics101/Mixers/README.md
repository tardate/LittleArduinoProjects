# #326 Mixers

All about frequency mixers.

![Build](./assets/Mixers_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

Frequency mixers are nonlinear devices that produce a signal at the sum and difference of the original frequencies of two signals applied to it.
Other frequency components may also be present in a practical frequency mixer.

Commonly used to shift signals from one frequency range to another (heterodyning).

Given their use in RF, the input signals are conventionally notated as:

* RF - input radio spectrum
* LO - local oscillator

And the output:

* IF - intermediate frequency.

Section 5 of [Experimental Methods in RF Design](https://www.goodreads.com/book/show/2386153.Experimental_Methods_in_RF_Design)
provides thorough and very understandable introduction to mixers of various types.

Some mixer implementations I have experimented with:

* [LEAP#327](./RFDiodeRing) - double-balanced diode ring mixer


### Theoretical Basis


```
cos(ω1t)cos(ω2t) = 1/2cos(ω1t - ω2t) + 1/2cos(ω1t + ω2t)
f(if) = ± m.f(rf) ± m.f(lo)
```

| Components of f(if) | Products |
|---------------------|----------|
| 1st order           | f(lo), f(rf) |
| 2nd order           | f(lo) - f(rf) or f(rf) - f(lo), f(lo) + f(rf) |
| 3rd order           | 2f(lo) - f(rf), 2f(lo) + f(rf), f(lo) - 2f(rf), f(lo) + 2f(rf) |
| ...                 | etc |


Typically want the upper or lower 2nd order products from the IF.

* the upper product (sum) is often called upper sideband, and is probably the one we want
* the lower product (difference) is often called lower sideband, and may not be desired because it exhibits spectrum inversion

### Balanced Designs

So-called "balanced mixers" eliminate feed-through of the input signals.
A double-blanaced design means both inputs (1st order products) are eliminated from the output.

### Filtering

1st order products are minimised with single or double balanced design.

Filters are often used in practical designs, potentially on all ports:

* RF - pre-selection filter
* LO - to eliminate oscillator harmonics
* IF - to select the desired product.



### Active and Passive

Mixers can be classified as active or passive:

* passive - typically using diodes, no additional power required
* active - typically JFET, BJT or MOSFETS with additional biasing power. Or packaged as ICs often with filtering and amplification.

Example active mixer integrated circuits:

* [LT5560](https://www.digikey.com/product-detail/en/LT5560EDD%23PBF/LT5560EDD%23PBF-ND/1620364) - double-balanced broadband
active mixer with integrated input amplifier
* [MAX2681](https://www.digikey.com/product-detail/en/maxim-integrated/MAX2681EUT-T/MAX2681EUT-TCT-ND/2699393) - double-balanced Gilbert-cell mixer with
single-ended RF, LO, and IF port connections
* [SA602A](http://www.nxp.com/docs/en/data-sheet/SA602A.pdf) - low-power VHF monolithic double-balanced mixer with input amplifier,
on-board oscillator, and voltage regulator

Mixers are also available as packaged/connectorised units, for example:

* [T3-03 High Linearity Triple Balanced RF Mixer](http://www.markimicrowave.com/T3-03-High-Linearity-Triple-Balanced-RF-Mixer-P1.aspx)




## Credits and References
* [Frequency mixer](https://en.wikipedia.org/wiki/Frequency_mixer) - wikipedia
* [The Basics of Mixers](https://www.digikey.com/en/articles/techzone/2011/oct/the-basics-of-mixers) - digikey
* [Experimental Methods in RF Design](https://www.goodreads.com/book/show/2386153.Experimental_Methods_in_RF_Design) - chapter 5.2
* [#83: Basics of RF Mixers in Radio Receivers / Mixer Tutorial / Frequency Conversion](https://www.youtube.com/watch?v=Mm7WfVzr1ao) - w2aew
* [RF Mixers: Three Options](https://www.youtube.com/watch?v=8q7GaTYpHn0) - Stan Gibilisco
* [LT5560 info and datasheet](https://www.digikey.com/product-detail/en/LT5560EDD%23PBF/LT5560EDD%23PBF-ND/1620364)
* [MAX2681 info and datasheet](https://www.digikey.com/product-detail/en/maxim-integrated/MAX2681EUT-T/MAX2681EUT-TCT-ND/2699393)
* [SA602A datasheet](http://www.nxp.com/docs/en/data-sheet/SA602A.pdf) - I believe previously known as the Phillips Semiconductor NE602AN
* [Round-Up of RTLSDR Upconverter Choices](https://retrovoltage.com/2012/09/14/round-up-of-rtlsdr-upconverter-choices/)
* [rtlsdr wiki](https://rtlsdr.org/)
