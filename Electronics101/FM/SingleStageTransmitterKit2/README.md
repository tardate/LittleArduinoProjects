# #279 FM/SingleStageTransmitterKit2

Build, tweak and tune another simple single-stage FM Transmitter Kit

![Build](./assets/SingleStageTransmitterKit2_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I picked up another [FM transmitter kit](https://www.aliexpress.com/item/Simple-FM-FM-wireless-microphone-FM-transmitter-board-parts-electronic-training-DIY-kit-Kit-not-including/32660667774.html) because it was too cheap to ignore.

It turns out to have a typical 1-transistor circuit, similar to [LEAP#208 SingleStageTransmitterKit](../SingleStageTransmitterKit).

### Kit Details

Some details according to the product info available from the seller:

* Frequency range: 88MHz-108MHz
* Working voltage: 3V (with CR2032 button cell)
* PCB materials: FR-4 glass fiber board
* PCB specifications: 48*26mm thickness: 1.6mm

### Tuning

After a quick build, the device was transmitting slightly high on the FM band
(I could get some interference but not a good signal at the upper limits ~108MHz).

Taking a look at the air-coil inductor, seems it should have an inductance of around 66nH:

| Measure      | Value |
|--------------|-------|
| diameter (d) | 3.5mm |
| length (l)   | 3mm   |
| turns (n)    | 5     |
| Inductance   | 65.9nH [per IN3OTD's calculator](http://www.qsl.net/in3otd/indcalc.html) |

The simplified formula:

    L = (d^2 n^2) / (l + 0.45d) [μH]

gets close to the same result: [66.9nH](https://www.wolframalpha.com/input/?i=1000+*+5%5E2+*+0.0035%5E2+%2F+(0.45+*+0.0035+%2B++0.003))

Assuming that's about right, the supplied C4 value of 30pF predict a resonant frequency of
[113MHz](https://www.wolframalpha.com/input/?i=(2*%CF%80*sqrt(66nH*30pF))%5E-1), which would explain
and confirm why I can't get anything in the standard FM range.

Around 90MHz is pretty clear for me, so I tried replacing C4 with [47pF](https://www.wolframalpha.com/input/?i=(1%2F(2*%CF%80*90MHz))%5E2%2F66nH).

This worked! I'm getting a signal at 84.15MHz, from which I infer the coil inductance might be closer to
[76nH](https://www.wolframalpha.com/input/?i=(1%2F(2*%CF%80*84.15MHz))%5E2%2F0.047nF).


### Performance

OK, I guess you shouldn't expect great things from such a dinky 1-transistor circuit. At least it works!

With 30cm antenna wire, reception beyond 5m was getting a bit dodgy.
Frequency stability was reasonably good; once locked in I didn't need to re-tune much.

Here's and SDR capture of the device broadcasting on 84.15MHz. All the peaks in the waterfall are
harmonic noise from the device.

![broadcast_capture](./assets/broadcast_capture.png?raw=true)


## Construction

The schematic shown here has component values as per my final build, *not* as provided in the kit. Two details changed:

| Ref | Kit Value | Actual Value   |
|-----|-----------|----------------|
| C4  | 30pF      | 47pF           |
| L1  | 4T        | 5T approx 76nH |

![Breadboard](./assets/SingleStageTransmitterKit2_bb.jpg?raw=true)

![Schematic](./assets/SingleStageTransmitterKit2_schematic.jpg?raw=true)

![Build](./assets/SingleStageTransmitterKit2_build.jpg?raw=true)

![Build](./assets/SingleStageTransmitterKit2_build_rear.jpg?raw=true)

## Credits and References
* [DIY kit Simple FM wireless microphone FM transmitter board parts electronic training DIY kit radio fm microphone transmitter](https://www.aliexpress.com/item/Simple-FM-FM-wireless-microphone-FM-transmitter-board-parts-electronic-training-DIY-kit-Kit-not-including/32660667774.html) - from seller on aliexpress
* [kit instructions](./assets/kit_instructions.pdf?raw=true)
* [LEAP#208 SingleStageTransmitterKit](../SingleStageTransmitterKit) - another similar kit
* [name](url)
* [Air core induction calculator](http://www.daycounter.com/Calculators/Air-Core-Inductor-Calculator.phtml)
* [LC resonance calculator](http://www.daycounter.com/Calculators/LC-Resonance-Calculator.phtml)
* [Single-layer Coil Inductance and Q](http://www.qsl.net/in3otd/indcalc.html) - IN3OTD
* [S9018 NPN transistor data](http://parts.io/detail/178104407/S9018) - parts.io
* [..as mentioned on my blog](https://blog.tardate.com/2017/04/leap279-single-stage-fm-transmitter-kit.html)
