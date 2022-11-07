# #667 MC34063 Buck Converter

Design and test a basic 9v to 5v step-down regulator circuit using the MC34063A.

![Build](./assets/BuckConverter_build.jpg?raw=true)

## Notes

The [MC34063A](https://www.onsemi.com/products/power-management/dc-dc-power-conversion/converters/mc34063a)
is a Buck / Boost / Inverting Regulator with a minimum number of external
components.

* Operation from 3.0 V to 40 V Input
* Output Switch Current to 1.5 A
* Frequency Operation to 100 kHz
* Precision 2% Reference

### Circuit Design Calculations

The [MC34063A datasheet](https://www.onsemi.com/products/power-management/dc-dc-power-conversion/converters/mc34063a)
provides the design guidelines and calculations for step-down converter.

OnSemi also provide a
[MC34063A Design Worksheet](https://www.onsemi.com/pub/Collateral/MC34063%20DWS.XLS)
to assist.

### Circuit Design Calculations for 9V to 5V Converter

I'm going to work this through from scratch.

#### Some givens and assumptions

* `Vf = 0.6V` ; 1N5819 forward voltage
* `Vsat = 1V` ; 1N5819 saturation voltage
* `Vripple = 100mV` ; chosen peak ripple voltage
* Design for 1A and 30% inductor ripple (typical inductor use 20-40% of the average output current)
    * `Il(avg) = 1A`
    * `Iripple = 1A * 30% = 0.30A`
    * `Ipk = Il(avg) + Iripple/2 = 1 + .30/2 = 1.15A`
* 40Khz switching frequency

Calculate `Ton/Toff`

    Ton/Toff
    = (Vout + Vf) / (Vin - Vsat - Vout)
    = (5 + 0.60) / (9 - 1 - 5)
    = [1.87](https://www.wolframalpha.com/input?i=%285+%2B+0.60%29%2F%289+-+1+-+5%29)

Calculate `Ton + Toff`

    Ton + Toff
    = 1 / f
    = 1 / 40kHz
    = [25µs](https://www.wolframalpha.com/input?i=1%2F40kHz)

Calculate `Toff`

    Toff
    = (Ton + Toff)/(Ton/Toff + 1)
    = 25µs/(1.87 + 1)
    = [8.71µs](https://www.wolframalpha.com/input?i=25%C2%B5s%2F%281.87+%2B+1%29) =

Calculate `Ton`

    Ton
    = (Ton + Toff) – Toff
    = 25µs –  8.71µs
    = [16.29 μs](https://www.wolframalpha.com/input?i=25%C2%B5s+%E2%80%93++8.71%C2%B5s)

Calculate timing Capacitor Ct to produce the desired frequency.

    Ct
    = 4.0 * 10^-5 * Ton
    = 4.0 * 10^-5 * 16.29μs
    = [652pf](https://www.wolframalpha.com/input?i=4.0+*+10%5E-5+*+16.29%CE%BCs)

Calculate the minimum inductor value `Lmin`

    Lmin
    = (Vin - Vsat - Vout)/Ipk x Ton
    = (9V - 1V - 5V)/1.15A * 16.29µs
    = [42.5μH](https://www.wolframalpha.com/input?i=%289V+-+1V+-+5V%29%2F1.15A+*+16.29%C2%B5s)

Calculate `Rsc`

    Rsc
    = 0.3/Ipk
    = 0.3/1.15
    = [0.260Ω](https://www.wolframalpha.com/input?i=0.3%2F1.15

Calculate `Cout`

Step 12:- Let’s calculate the output capacitor values, we can choose a ripple value of 100mV (peak to peak) from the boost output.

    Cout
    = Ipk (Ton + Toff)/(8 * Vripple)
    = 1.15A * 25µs/(8 * 100mV)
    = [35.94μF](https://www.wolframalpha.com/input?i=1.15A+*+25%C2%B5s%2F%288+*+100mV%29)

Calculate feedback resistors R1 and R2, given `R1 = 2kΩ` and `Vout = 1.25 (1 + R2/R1)`

    R2
    = R1 * (Vout/1.25 - 1)
    = 2kΩ * (5/1.25 - 1)
    = [6kΩ](https://www.wolframalpha.com/input?i=2k%CE%A9+*+%285%2F1.25+-+1%29)

Finally, selecting available components close to the theoretical:

| Ref  | Design Value (Ideal) | Selected |
|------|----------------------|----------|
| Co   | 35.94μF              | 47μF     |
| L1   | 42.5μH               | 47μH     |
| R1   | 2kΩ                  | 2kΩ      |
| R2   | 6kΩ                  | 6.8kΩ    |
| Vout | 5V                   | [5.5V(<https://www.wolframalpha.com/input?i=1.25+%281+%2B+6.8%2F2%29>) ]

### Circuit Construction

![bb](./assets/BuckConverter_bb.jpg?raw=true)

![schematic](./assets/BuckConverter_schematic.jpg?raw=true)

### Testing

The output voltage I'm seeing is 5.6V, close to the expected 5.5V with these components:

![bb_build](./assets/BuckConverter_bb_build.jpg?raw=true)

The ripple (captured AC-coupled on the following scope trace) appears to be running at around

* 200mV peak-peak
* 600µs period i.e. [1.7kHz](https://www.wolframalpha.com/input?i=1%2F%28600%C2%B5s%29)

That's quite a bit off from the design parameters; probably worth re-testing with a protoboard/PCB version of the circuit
and perhaps a load closer to the design current.

![scope](./assets/scope.gif?raw=true)

## Credits and References

* [MC34063 datasheet](https://www.futurlec.com/Motorola/MC34063.shtml)
* [MC34063A datasheet](https://www.onsemi.com/products/power-management/dc-dc-power-conversion/converters/mc34063a) - OnSemi
* [MC34063A Design Worksheet](https://www.onsemi.com/pub/Collateral/MC34063%20DWS.XLS) - OnSemi
* [1N5819 datasheet](https://www.onsemi.com/products/discrete-power-modules/schottky-diodes-schottky-rectifiers/1n5819) - OnSemi
* [MC34063A Buck, Boost, Inverting Regulator](https://microcontrollerslab.com/mc34063a-buck-boost-inverting-regulator/)
* [12V to 5V Buck Converter Circuit using MC34063](https://circuitdigest.com/electronic-circuits/12v-to-5v-buck-converter-circuit-diagram)
