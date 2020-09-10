# #560 Hurst Point Lighthouse

Building the wonderful Paper Shipwright model of the historic Hurst Point Lighthouse, and bringing it to life with a Fl(4) W 15s LED array.

![Build](./assets/HurstPointLighthouse_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/T73apPPELso/0.jpg)](https://www.youtube.com/watch?v=T73apPPELso)

## Notes

I recently stumbled upon David Hathaway's [Paper Shipwright](https://www.papershipwright.co.uk), offering a range of paper models
of ships, lighthouses and other buildings. I had to buy a few (some are even available for free download if you have a suitable printer).

Hurst Point Lighthouse held special appeal for me, as I grew up in the area and spent many a day sailing this part of the Solent with my father.

[![HurstPointLighthouse_map](./assets/HurstPointLighthouse_map.png?raw=true)](https://www.google.com/maps/place/Hurst+Point+Lighthouse/@50.7079456,-1.5526078,17z/data=!3m1!4b1!4m5!3m4!1s0x487381a1b327e0e9:0xc1237661c4bbdf05!8m2!3d50.7079422!4d-1.5504138)

The paper model is a 1:250 rendition of Hurst Point Lighthouse (Hampshire, UK). The current lighthouse dates from 1867 and was modernised and electrified in 1997.

* Location: Hampshire, UK
* Position: 50 42′. 44 N 01 32′.94 W
* Height: 26m
* Built: 1867
* Light: Fl(4) WR 15s 14nm

![kit](./assets/kit.jpg?raw=true)

## The Light

The [lighthouse characteristics](https://en.wikipedia.org/wiki/Light_characteristic) are recorded as "Fl(4) WR 15s 14nm".

Translated, this means flashing 4 times every 15 seconds, visible to 14 nautical miles. "WR" I think means alternating white and red, but I'm not too sure and wasn't able to find any clear confirmation. For the build, I'm going to simply do a flashing white light.

I decided to use a simple 555 timer circuit comprising two cascaded timers: the first provides the overall 15 second window with an on-period long enough to enable the second timer to perform 4 flashes at about [0.65 Hz](https://visual555.tardate.com/?mode=astable&r1=4.7&r2=330&c=3.3).

![Breadboard](./assets/HurstPointLighthouse_bb.jpg?raw=true)

![Schematic](./assets/HurstPointLighthouse_schematic.jpg?raw=true)

First testing the basic circuit on a breadboard:

![HurstPointLighthouse_bb_build](./assets/HurstPointLighthouse_bb_build.jpg?raw=true)

Some circuit notes:

* diode D2 is not required (I had it in circuit as originally I was using a smoothing RC circuit on the LEDs, but removed this in the final build as it wasnt adding much to the effect)
* timing is not 100% accurate, as it is at the whim of component values and tolerances. But I have it close enough for my liking.
* the first flash is a little longer than the following ones, as C5 must charge from fully discharged to 2/3 VCC and then oscillating between 1/3 and 2/3 VCC. There is probably a way to avoid this but I haven't solved that problem yet.

Here's a scope trace of the flashing sequence:

![timing](./assets/timing.gif?raw=true)

The circuit was finally transferred to some protoboard before installation:

![build_soldering](./assets/build_soldering.jpg?raw=true)
![protoboard_layout](./assets/protoboard_layout.jpg?raw=true)

I used three SMD white LEDs in a parallel radial array for installation in the model. Copper wire provides a solid mast making installation easier. A plastic sleeve and some aluminium foil complete the light fixture.

![build_led_mast](./assets/build_led_mast.jpg?raw=true)

Testing the LED mast on the breadboard:

![build_led_mast_test](./assets/build_led_mast_test.jpg?raw=true)

## Building the Model

It's quite an easy model to assemble, just requires a steady cutting hand and some patience. The fit of the parts was very good.

The support buildings:

![build_buildings](./assets/build_buildings.jpg?raw=true)

I diverged from the paper model for the railing and light enclosure, fashioning these with some clear acrylic, cotton thread, and some component lead offcuts.

![build_upper_tower](./assets/build_upper_tower.jpg?raw=true)

The base is made from some random balsa wood that I had on hand, and painted with a "seafarer's oak chest" impression in mind.

![build_base](./assets/build_base.jpg?raw=true)

The base after varnish and switch installation. Ready for the electronics and final assembly.

![build_base_final](./assets/build_base_final.jpg?raw=true)

Circuit installation in the base of the model:

![build_electronics_installed](./assets/build_electronics_installed.jpg?raw=true)

All assembled:

![build_final](./assets/build_final.jpg?raw=true)

With a dramatic backdrop!

![build_final2](./assets/build_final2.jpg?raw=true)

## Credits and References

* [Hurst Point Lighthouse](https://www.papershipwright.co.uk/product/hurst-point-lighthouse/) - Paper Shipwright/ David Hathaway
* [Hurst Point Lighthouse](https://en.wikipedia.org/wiki/Hurst_Point_Lighthouse) - wikipedia
