# #211 BuckConverterModules

Test a range of low-cost buck converter modules


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

There are many super-cheap buck converter modules available, many based on the LM2596S-ADJ. This is the place I record any notes on the individual units I get to see.

Four so far:

* Module 1 - LM2596S 2.6-30V Buck Module
* Module 2 - LM2596S 1.23V-30V Buck Module
* Module 3 - XL4015 1.25V-36V Buck Module
* Module 4 - MP2307DN 1.0V-17V Buck Module

### Module 1 - LM2596S 2.6-30V Buck Module

The example I'm using is similar to this [seller listing](http://www.aliexpress.com/item/1PCS-NEW-LM2596-DC-DC-adjustable-power-step-down-module/32276206956.html). Typical price USD$0.93 with free shipping.

![module_1](./assets/module_1.jpg?raw=true)

Buck circuit comprises:
* LM2596S-ADJ (as marked, but behaves more like an LM2576 - see note below)
* 330µH output inductor
* 220µF output capacitor

Performance:
* minimum voltage achieved in practice: 2.56V
* switching frequency appears to be in the ~50kHz range rather than the 150kHz per datasheet(??)
* switching spikes around 30-40mV

*Conclusion*

This is one of the most common modules, but quite noisy and can't regulate to very low voltages.

It also behaves more like an LM2576:
* the 330µH inductor is also more suited to a standard LM2576 topology rather than the 33µF recommended for the LM2596.
* the apparent switching frequency is closer to the LM2576 52kHz rather than the LM2596's 150kHz.
* so is this a fake or QC-fail LM2596S-ADJ? Possibly, if my scope traces are reliable.


![module_1_test](./assets/module_1_test.jpg?raw=true)

![module_1_scope](./assets/module_1_scope.gif?raw=true)


### Module 2 - LM2596S 1.23V-30V Buck Module

The example I'm using is similar to this  [seller listing](http://www.aliexpress.com/item/5PCS-DC-DC-Buck-Converter-Step-Down-Module-LM2596-Power-Supply-Output-1-23V-30V/2013251353.html?spm=2114.01010208.3.22.tfzVTK&ws_ab_test=searchweb201556_0,searchweb201602_3_10037_10017_10034_10021_507_10033_10022_10032_10020_10018_10019,searchweb201603_1&btsid=b6cc6379-547e-4d9c-8217-6a28b26787fb). Typical price USD$0.79 with free shipping.

![module_2](./assets/module_2.jpg?raw=true)

Buck circuit comprises:
* LM2596S-ADJ (as marked, but behaves more like an LM2576 - see note below)
* 470µH output inductor
* 220µF output capacitor

Performance:
* minimum voltage achieved in practice: 1.22V
* switching frequency appears to be ~50kHz, not 150kHz per LM2596 specs.
* switching spikes under 10mV

*Conclusion*

Performance is pretty good, but this does not appear to be a genuine LM2596S-ADJ.

* the 470µH inductor is also more suited to a standard LM2576 topology rather than the 33µF recommended for the LM2596.
* the apparent switching frequency is closer to the LM2576 52kHz rather than the LM2596's 150kHz.
* so is this a fake or QC-fail LM2596S-ADJ? Possibly, if my scope traces are reliable.


![module_2_test](./assets/module_2_test.jpg?raw=true)

![module_2_scope](./assets/module_2_scope.gif?raw=true)


### Module 3 - XL4015 1.25V-36V Buck Module

The example I'm using is similar to this [seller listing](http://www.aliexpress.com/item/5A-High-power-75W-DC-DC-adjustable-step-down-module-LED-Can-be-calibrated-voltmeter-Power/32411291600.html). Typical price USD$2.68 with free shipping.

![module_3](./assets/module_3.jpg?raw=true)

Board comprises:
* XL4015E5 with toroidal inductor and capacitors as per datasheet recommendations
* digital voltmeter with pushbuttons to switch display on/off and select input/output voltage for display

Performance: up with the best. There's no scope capture below because despite my best attempts, the output voltage remained flat as a board (no detectable ripples or spikes .. just the normal noise floor)

![module_3_test](./assets/module_3_test.jpg?raw=true)


### Module 4 - MP2307DN 1.0V-17V Buck Module

The example I'm using is similar to this [seller listing](http://www.aliexpress.com/item/Mini-360-DC-DC-Buck-Converter-Step-Down-Module-4-75-23V-to-1-17V-for/32436860547.html). Typical price USD$0.51 (USD$5.06 for 10) with free shipping.

![module_4](./assets/module_4.jpg?raw=true)

Board comprises:
* MP2307 monolithic buck converter with standard support circuits per datasheet recommendations
* pretty small package!

Performance: quite impressive for the size. There's no scope capture below because despite my best attempts, the output voltage remained flat as a board (no detectable ripples or spikes .. just the normal noise floor)

![module_4_test](./assets/module_4_test.jpg?raw=true)


## Test Bed Construction

![Breadboard](./assets/BuckConverterModules_bb.jpg?raw=true)

In the test configuration, I have the buck converters adjusted to ~3V output,
and two blue LEDs in parallel form the load. the LEDs have a forward voltage Vf of ~3V.

![The Schematic](./assets/BuckConverterModules_schematic.jpg?raw=true)

## Credits and References
* [LM2596 product page](http://www.ti.com/product/LM2596) - TI
* [LM2596 datasheet](http://www.ti.com/lit/ds/symlink/lm2596.pdf) - TI
* [LM2576 product page](http://www.ti.com/product/LM2576) - TI
* [LM2576 datasheet](http://www.ti.com/lit/ds/symlink/lm2576.pdf)
* [XL4015 datasheet](http://i-makers.info/resource/XL4015%20datasheet.pdf)
* [XL4015 DEMO board manual](http://www.xlsemi.com/demo/XL4015%20DEMO%20board%20manual.pdf) - xlsemi
# [MP2307 datasheet](https://cdn-shop.adafruit.com/datasheets/MP2307_r1.9.pdf)
* [App note: Diode turn-on time induced failures in switching regulators](http://dangerousprototypes.com/2013/01/05/diode-turn-on-time-induced-failures-in-switching-regulators/)
* [..as mentioned on my blog](http://blog.tardate.com/2016/07/littlearduinoprojects211-buck-converter.html)
