# #468 BreadboardBling/DuplexTuningCapacitor

Making a breadboard-compatible variable capacitor for radio circuits.

![Build](./assets/DuplexTuningCapacitor_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

Duplex tuning capacitors aka radio or AM variable capcitors contain two sets of capacitor plates ganged together, with fine tuning adjustment screws for each capacitor.
Total capacitance is typically under 300pF, but mulitple arrangements are possible as either a single or dual variable capacitor.

These components are typically used for radio tuning, and while building radio circuits on a breadboard can be a hairy proposition
due to all the stray capcitance, a solid mounting for use on a breadboard can minimise the evils.

the specific part I'm using is a [duplex 223p 60pf/140pf 2.1mm Hole Shaft Radio Variable Capacitor](https://www.aliexpress.com/item/5-Sets-Duplex-223p-60pf-140pf-2-1mm-Hole-Shaft-Radio-Variable-Capacitor-Knob-Screw-s484/32578566833.html) from a seller on aliexpress.

### How They Work

The main tuning dial controls two variable capacitors (Co, Ca) that share a common connection G.
Ca is typically around twice the capacitance of Co.
Trimming capacitors are in parallel with each (Cto, Cta).

Ca and Co may be used as two linked/proportional variable capacitors with a common "ground": connections G & O, and G & A.

Alternatively, O and A may be bridged for a single variable capacitor between O/A & G or maximum capacitance.

For my specific part (without trim), I've measured the capacitance range at around:

* Ca: 18pF to 160pF
* Co: 17pF to 75pF
* or combined, from 35pF to 235pF

[![TuningCapacitor_schematic](./assets/TuningCapacitor_schematic.jpg?raw=true)](https://www.mikroe.com/ebooks/radio-receivers-from-crystal-set-to-stereo/other-components)

## Construction

I've simply mounted the capacitor on a piece of protoboard large enough to raise the tuning dial off the deck,
with two rows of header pins at the base and a little hot glue on the reverse to keep the capacitor secure.

This provides a very solid mount, so that when on a breadboard it can easily be adjusted without needing a second hand to keep things in place.

The O-G-A pins are unbridged and connect directly to the breadboard, so any combination of capacitance can be used by making the appropriate connections.

![DuplexTuningCapacitor_rear](./assets/DuplexTuningCapacitor_rear.jpg?raw=true)

![DuplexTuningCapacitor_side](./assets/DuplexTuningCapacitor_side.jpg?raw=true)

## Credits and References

* [Duplex 223p 60pf/140pf 2.1mm Hole Shaft Radio Variable Capacitor](https://www.aliexpress.com/item/5-Sets-Duplex-223p-60pf-140pf-2-1mm-Hole-Shaft-Radio-Variable-Capacitor-Knob-Screw-s484/32578566833.html) - from a seller on aliexpress
* [3.1.4 Other Components](https://www.mikroe.com/ebooks/radio-receivers-from-crystal-set-to-stereo/other-components) - Radio Receivers, from crystal set to stereo
