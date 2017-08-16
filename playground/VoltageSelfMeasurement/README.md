# #333 VoltageSelfMeasurement

Self-measurement of an Arduino's supply voltage (Vcc).

![Build](./assets/VoltageSelfMeasurement_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

One of the issues with analgue measurements on the arduino is that typically we assume an accurate 5V reference.
When that is not actually true, all the readings are off.

In the past I've typically measured the actual rail voltage and scripted with a corresponding "fudge factor".
But wouldn't it be nice if the Arduino could actually do this itself?

[SecretVoltmeter](https://code.google.com/archive/p/tinkerit/wikis/SecretVoltmeter.wiki) is a snippet of code
that demonstrates how to get an Arduino (at least Atmega 168 and 328 processors) to measure it's own supply rail.
I found this via [Julian Ilett's video on the subject](https://www.youtube.com/watch?v=G6dvDgCOyqk).

I've cleaned up and modified the code a little in the [VoltageSelfMeasurement.ino](./VoltageSelfMeasurement.ino) sketch.


### How It Works

It relies on two things:

* the Atmega chip has an internal 1.1V voltage reference (Vbg) that we assume is a known and precise value.
* it is possible to configure the ADC to measure AVcc with respect to Vbg

So it is then trivial to calculate AVcc in mV.

Note: I've also followed the Atmel recommendation to put a 10nF cap on AREF to help stabilise the ADC readings.

### Results

Measurements are piped to the serial port. These are pretty accurate according to my other meters:

![console](./assets/console.png?raw=true)


### But...

Two things:

* the ADC is only 10-bit, and
* how accurate is the internal 1.1V voltage reference anyway?

I put my 1.1V reference to the test, and according to the most accurate device I have on hand, it is actually
running at 1.063V. The sketch includes some techniques for compensation.

But ... if we're compensating for innaccuracies in Vbg, aren't we back to square one and no better off than calibrating Vcc in the first place?
Perhaps. I haven't done measurements to back this up, but one benefit of this approach
could be if Vbg is relatively stable over variations in supply voltage.

Measuring the 1.1V reference:

![VoltageSelfMeasurement_vbg_test](./assets/VoltageSelfMeasurement_vbg_test.jpg?raw=true)


## Construction

![Breadboard](./assets/VoltageSelfMeasurement_bb.jpg?raw=true)

![Schematic](./assets/VoltageSelfMeasurement_schematic.jpg?raw=true)

![Build](./assets/VoltageSelfMeasurement_build.jpg?raw=true)

## Credits and References
* [Playing with: the Arduino Secret Voltmeter](https://www.youtube.com/watch?v=G6dvDgCOyqk) - Julian Ilett
* [SecretVoltmeter](https://code.google.com/archive/p/tinkerit/wikis/SecretVoltmeter.wiki)
* [AVR datasheet](http://www.atmel.com/images/Atmel-8271-8-bit-AVR-Microcontroller-ATmega48A-48PA-88A-88PA-168A-168PA-328-328P_datasheet_Complete.pdf)
* [AREF decoupling capacitor](http://www.atmel.com/webdoc/stk600/stk600.section.qim_lde_lc.html) - 10nF suggested
