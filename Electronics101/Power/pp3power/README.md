# #638 9V (PP3) to 5V or 3.3V Power Adapter

Building an MC34063-based buck converter adapter for a 9V battery, with output voltage selectable between 5V and 3.3V.

![Build](./assets/pp3power_build.jpg?raw=true)

## Notes

This project is inspired by the
[snapVCC](https://www.crowdsupply.com/electronut-labs/snapvcc)
(no longer available) by
[electronut](https://github.com/electronut/ElectronutLabs-snapVCC)
back in 2015 or so. It is based around the Texas Instruments TPS560200 buck converter with 500 mA output current, mounted on a 9V battery clip. It allowed for a selectable 3.3V or 5V output.

[![snapvcc](./assets/snapvcc.jpg?raw=true)](https://www.crowdsupply.com/electronut-labs/snapvcc)

The
[Nine-volt battery](https://en.wikipedia.org/wiki/Nine-volt_battery)
size, regardless of chemistry, is commonly designated PP3 — a designation originally reserved solely for carbon-zinc, or in some countries, E or E-block. Designations for this format include `NEDA 1604` and `IEC 6F22` (for zinc-carbon) or `MN1604 6LR61` (for alkaline).

### Circuit Design

I've redesigned this around the Motorola MC34063A DC–to–DC converters, as this is a suitable chip that I have on hand.

OnSemi also provide a
[MC34063A Design Worksheet](https://www.onsemi.com/pub/Collateral/MC34063%20DWS.XLS)
to assist.

#### Some givens and assumptions

* `Vf = 0.6V` ; 1N5819 forward voltage
* `Vsat = 1.26V` ; saturation Voltage of Power Switch Transistor
* `Vripple = 100mV` ; chosen peak ripple voltage
* Design for 150mA and 30% inductor ripple (typical inductor use 20-40% of the average output current)
    * `Il(avg) = 150mA`
    * `Iripple = 150mA * 30% = 45mA`
    * `Ipk = Il(avg) + Iripple/2 = 150 + 45/2 = 172.5mA`
* `f = 40Khz` switching frequency

#### Parameter Calculations

| Parameter   | Formula                             | Vout = 5V                                                                                      | Vout = 3.3V |
|-------------|-------------------------------------|------------------------------------------------------------------------------------------------|-------------|
| `Ton/Toff`  | `(Vout + Vf) / (Vin - Vsat - Vout)` | [2.04](https://www.wolframalpha.com/input?i=%285+%2B+0.60%29%2F%289+-+1.26+-+5%29)             | [0.88](https://www.wolframalpha.com/input?i=%283.3+%2B+0.60%29%2F%289+-+1.26+-+3.3%29) |
| `Ton + Toff`| `1 / f`                             | [25µs](https://www.wolframalpha.com/input?i=1%2F40kHz)                                         | [25µs](https://www.wolframalpha.com/input?i=1%2F40kHz)  |
| `Toff`      | `(Ton + Toff)/(Ton/Toff + 1)`       | [8.22µs](https://www.wolframalpha.com/input?i=25%C2%B5s%2F%282.04+%2B+1%29)                    | [13.29µs](https://www.wolframalpha.com/input?i=25%C2%B5s%2F%280.88+%2B+1%29) |
| `Ton`       | `(Ton + Toff) – Toff`               | [16.78μs](https://www.wolframalpha.com/input?i=25%C2%B5s+%E2%80%93++8.22%C2%B5s)               | [11.71μs](https://www.wolframalpha.com/input?i=25%C2%B5s+%E2%80%93+13.29%C2%B5s) |
| `Ct`        | `4.0 * 10^-5 * Ton`                 | [671pF](https://www.wolframalpha.com/input?i=4.0+*+10%5E-5+*+16.78%CE%BCs)                     | [468pF](https://www.wolframalpha.com/input?i=4.0+*+10%5E-5+*+11.71%CE%BCs) |
| `Rsc`       | `0.3/Ipk`                           | [1.74Ω](https://www.wolframalpha.com/input?i=0.3V%2F172.5mA)                                   | [1.74Ω](https://www.wolframalpha.com/input?i=0.3V%2F172.5mA) |
| `Lmin`      | `(Vin - Vsat - Vout)/Ipk x Ton`     | [267.5μH](https://www.wolframalpha.com/input?i=%289V+-+1.25V+-+5V%29%2F172.5mA+*+16.78%CE%BCs) | [302µH](https://www.wolframalpha.com/input?i=%289V+-+1.25V+-+3.3V%29%2F172.5mA+*+11.71%CE%BCs&assumption=%22UnitClash%22+-%3E+%7B%22V%22%2C+%7B%22Volts%22%2C+%22dflt%22%7D%7D&assumption=%7B%22C%22%2C+%22V%22%7D+-%3E+%7B%22Unit%22%2C+%22dflt%22%7D&assumption=%22UnitClash%22+-%3E+%7B%22%CE%BCs%22%2C+%7B%22Microseconds%22%7D%7D) |
| `Cout`      | `Ipk (Ton + Toff)/(8 * Vripple)`    | [5.39μF](https://www.wolframalpha.com/input?i=172.5mA+*+25%C2%B5s%2F%288+*+100mV%29)           | [5.39μF](https://www.wolframalpha.com/input?i=172.5mA+*+25%C2%B5s%2F%288+*+100mV%29) |
| `R1`        | given                               | 12kΩ                                                                                           | 12kΩ |
| `R2`        | `R1 * (Vout/1.25 - 1)`              | [36kΩ](https://www.wolframalpha.com/input?i=12k%CE%A9+*+%285%2F1.25+-+1%29)                    | [19.68kΩ](https://www.wolframalpha.com/input?i=12k%CE%A9+*+%283.3%2F1.25+-+1%29) |

Note: the [MC34063A Design Worksheet](https://www.onsemi.com/pub/Collateral/MC34063%20DWS.XLS)
appears to have an error in the calculation of `Lmin` (it uses `Iripple` instead of `Ipk`)

With these components, we should be able to select between 3.3V and 5V output by selecting between R2 of 12kΩ and 20kΩ.

| Ref               | Selected |
|-------------------|----------|
| Co                | 10μF     |
| Ct                | 680pF    |
| L1                | 330μH    |
| R1                | 12kΩ     |
| R2 (Vout = 5V)    | 33kΩ // 33kΩ + 20kΩ = [36.5kΩ](https://toolbox.tardate.com/?formula=(33%7C33)%2B20#ResistorCalculator) |
| R2 (Vout = 3.3V)  | 20kΩ     |

### Circuit Layout

![bb](./assets/pp3power_bb.jpg?raw=true)

![schematic](./assets/pp3power_schematic.jpg?raw=true)

Breadboard build to validate the circuit:

![bb_build](./assets/pp3power_bb_build.jpg?raw=true)

Checking with R2=20kΩ, actual Vout = 3.41V:

![pp3power_bb_test_33](./assets/pp3power_bb_test_33.jpg?raw=true)

Checking with R2=20kΩ+(33kΩ|33kΩ), actual Vout = 5.12V:

![pp3power_bb_test_50](./assets/pp3power_bb_test_50.jpg?raw=true)

### Build Log

Planning the layout on a DIP28 adapter board using SMD components (except for the 1Ω sense resistor that I only had available in through-hole).

![build01](./assets/build01.jpg?raw=true)

I scavenged the 9V connector from a dead battery (just remember to reverse the polarity).

![build02](./assets/build02.jpg?raw=true)

Only a couple of bodge wires required to complete the circuit,
and I was able to keep the entire circuit within the available space.

![build03](./assets/build03.jpg?raw=true)

![build04](./assets/build04.jpg?raw=true)

Testing the 3.3V selector:

![build05](./assets/build05.jpg?raw=true)

Testing the 5V selector:

![build06](./assets/build06.jpg?raw=true)

The completed unit attached to a battery:

![build07](./assets/build07.jpg?raw=true)

The completed unit:

![build08](./assets/build08.jpg?raw=true)

## Credits and References

* [snapVCC](https://www.crowdsupply.com/electronut-labs/snapvcc)
    * The 3.3/5 V super-efficient regulator that snaps right on your 9 V battery
    * [electronut/ElectronutLabs-snapVCC](https://github.com/electronut/ElectronutLabs-snapVCC) - GitHub
* [Nine-volt battery](https://en.wikipedia.org/wiki/Nine-volt_battery)
* [MC34063 datasheet](https://www.futurlec.com/Motorola/MC34063.shtml)
* [MC34063A datasheet](https://www.onsemi.com/products/power-management/dc-dc-power-conversion/converters/mc34063a) - OnSemi
* [MC34063A Design Worksheet](https://www.onsemi.com/pub/Collateral/MC34063%20DWS.XLS) - OnSemi
