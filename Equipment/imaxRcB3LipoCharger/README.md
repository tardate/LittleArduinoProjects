# #503 imaxRC B3 Lipo Charger

Quick teardown and review of the imax B3 Pro charger for 2s and 3s Lithium-polymer battery packs.

![Build](./assets/imaxRcB3LipoCharger_build.jpg?raw=true)

## Notes

I bought the [imaxRC B3 Pro](https://www.aliexpress.com/item/4000106254839.html)
to charger some [HRB 3S1P Lipo 11.1V 2200mah battery packs](https://www.aliexpress.com/item/2054907588.html).

I haven't used it much except to top-up the packs.
My initial observation is that the charger gets very warm to the touch (batteries remain cool); not sure what's going on here.

This charger probably falls into the "too dodgy, buy a decent one" category per: [Everything you need to know about LiPo Battery chargers](https://www.dronetrest.com/t/everything-you-need-to-know-about-lipo-battery-chargers/1326)

## Specifications

| Item                    | Specification    |
|-------------------------|------------------|
| Input voltage           | AC 100V-240V     |
| Balance charge current  | 850mA            |
| Max charger current     | 3*800mA          |
| Display                 | 3x Bicolor LED   |
| Power plug              | EU Plug          |
| Display                 | Green & Red LED  |
| Case material           | ABS              |
| Dimension               | 90 x 55 x 35mm   |
| Compatible batteries    | 2S/3S Lipo       |

![manual-en](./assets/manual-en.jpg?raw=true)

## Quick Teardown

![teardown-1-front](./assets/teardown-1-front.jpg?raw=true)

![teardown-2-rear](./assets/teardown-2-rear.jpg?raw=true)

![teardown-3-board](./assets/teardown-3-board.jpg?raw=true)

The AC-DC rectification use the DK112 Switching Power Supply Control Chip:

![teardown-4-smps](./assets/teardown-4-smps.jpg?raw=true)

Charge circuit uses a AD4056ES or TP4056 equivalent. I don't see any active re-balancing support, so not sure what would be generating so much heat.

![teardown-5-bms](./assets/teardown-5-bms.jpg?raw=true)

## Circuit Design

The high-voltage side is a conventional application of the DK112, similar to Typical application #1 from the datasheet (12V/1A output offline flyback switching power supply).

![DK114_example_schematic](./assets/DK114_example_schematic.jpg?raw=true)

The more interesting part is the low-voltage side and how the TP4056 has been used.
Here's a partial re-drawing of the circuit.

Essentially, there are three low-voltage windings that are half-wave rectified to power three TP4056 circuits (for each batter cell).
Since the power supply is floating, these are stacked in series.

Main things to note:

* regulation is a bit howsyourfather. Single bulk filter capacitor after the half-wave rectification and a 750Ω bleed resistor
* they've skimped on the thermal regulation. There's not NTC; the TEMP pin of the TP4056's is permanently pulled low.
* Rprog = 1.8kΩ, corresponding the a charge current (Ibat) of ~600mA (each cell).

![imaxRcB3LipoCharger_schematic](./assets/imaxRcB3LipoCharger_schematic.jpg?raw=true)

## Credits and References

* [High Quality iMaxRC iMax B3 Pro Compact 2S 3S Lipo Balance Battery Charger For RC Helicopter 6.17](https://www.aliexpress.com/item/4000106254839.html)
* [2pcs HRB 11.1V 2200mah Lipo Battery T Deans XT60 XT90 EC5 3.5mm EC3 30C For HPI Racing Cars Monster Truck Boat Airplane RC Parts](https://www.aliexpress.com/item/2054907588.html)
* [DK112 info and datasheet](https://lcsc.com/product-detail/Switching-Controllers_DK112_C78751.html)
* [AD4056ES](https://lcsc.com/product-detail/Others_IDCHIP-AD4056ES_C329456.html)
* [Everything you need to know about LiPo Battery chargers](https://www.dronetrest.com/t/everything-you-need-to-know-about-lipo-battery-chargers/1326)
