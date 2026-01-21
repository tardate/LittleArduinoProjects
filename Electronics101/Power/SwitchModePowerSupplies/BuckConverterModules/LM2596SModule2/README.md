# #822 LM2596S 1.23V-30V Buck Converter Module

Another common LM2596S-based buck converter module with adjustable-voltage control, operating at around 50kHz switching frequency.

![Build](./assets/LM2596SModule2_build.jpg?raw=true)

## Notes

NB: see [LEAP211 Buck Converter Modules](../) for an overview of all the buck converter modules I have tried.

This item is very similar to
[LEAP#821 LM2596S 2.6-30V Buck Module](../LM2596SModule1/)
but with slightly different components.

I purchased the
["Power Output 1.23V-30V DC-DC Buck Converter Step Down Module LM2596 Best Selling" (aliexpress seller listing)](https://www.aliexpress.com/item/32263989083.html)
for US$0.79 (Oct-2015).

The product is no longer available from the same seller, but the same item is
["10PCS LM2596 LM2596S DC-DC Step Down Variable Volt Regulator Input 3.0-40V Output 1.5-35V Adjustable Buck Converter Electronic" (aliexpress seller listing)](https://www.aliexpress.com/item/1005008535110639.html)
currently listed as a lot of 10 items for SG$6.95/lot (Jan-2026).

Buck circuit comprises:

* LM2596S-ADJ (as marked, but behaves more like an LM2576 - see note below)
* 470µH output inductor
* 220µF output capacitor

### Test Circuit Design

In the test configuration, I have the buck converter adjusted to ~3V output,
and two blue LEDs in parallel with the load. The LEDs have a forward voltage Vf of ~3V.

Designed with Fritzing: see [LM2596SModule2.fzz](./LM2596SModule2.fzz).

![bb](./assets/LM2596SModule2_bb.jpg?raw=true)

![schematic](./assets/LM2596SModule2_schematic.jpg?raw=true)

![bb_build](./assets/LM2596SModule2_bb_build.jpg?raw=true)

### Test Results

* minimum voltage achieved in practice: 1.22V
* switching frequency appears to be ~50kHz, not 150kHz per LM2596 specs.
* switching spikes under 10mV

![scope](./assets/scope.gif?raw=true)

### Conclusion

Performance is pretty good, but this does not appear to be a genuine LM2596S-ADJ.

* the 470µH inductor is also more suited to a standard LM2576 topology rather than the 33µF recommended for the LM2596.
* the apparent switching frequency is closer to the LM2576 52kHz rather than the LM2596's 150kHz.
* so is this a fake or QC-fail LM2596S-ADJ? Possibly, if my scope traces are reliable.

## Credits and References

* ["Power Output 1.23V-30V DC-DC Buck Converter Step Down Module LM2596 Best Selling" (aliexpress seller listing)](https://www.aliexpress.com/item/32263989083.html)
    * Originally purchased for US$0.79 (Oct-2015).
    * No longer offered by this seller.
* ["10PCS LM2596 LM2596S DC-DC Step Down Variable Volt Regulator Input 3.0-40V Output 1.5-35V Adjustable Buck Converter Electronic" (aliexpress seller listing)](https://www.aliexpress.com/item/1005008535110639.html)
    * Same product, currently listed as a lot of 10 items for SG$6.95/lot (Jan-2026).
* Texas Instruments:
    * [LM2596 product page](https://www.ti.com/product/LM2596)
    * [LM2596 datasheet](https://www.ti.com/lit/ds/symlink/lm2596.pdf)
    * [LM2576 product page](https://www.ti.com/product/LM2576)
    * [LM2576 datasheet](https://www.ti.com/lit/ds/symlink/lm2576.pdf)
