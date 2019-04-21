# #234 CMOSInverterOscillator

Use a CD4096 to generate an oscillating waveform and plot the results

![Build](./assets/CMOSInverterOscillator_build.jpg?raw=true)

## Notes

I found this oscillator circuit as part of the [LEAP#182 PowerSupply317Kit](../PowerSupply317Kit).

It is another variation of the basic Schmitt Inverter Waveform Generator pattern,
which I tested in [LEAP#022 SchmittOscillator](../SchmittOscillator).

### Performance

... is quite terrible actually. Oscillation is only sustained for a small sweep of the 100kΩ pot.
The waveform is also heavily asymmetric - with a duty cycle at most 25%.

| Setting                   | C1   | R1 (pin 2-3) | Frequency |
|---------------------------|------|--------------|-----------|
| max sustained oscillation | 10µF | 2.5kΩ        | 27Hz      |
| min sustained oscillation | 10µF | 40kΩ         | 0.4Hz     |
| max sustained oscillation | 1µF  | 2.15kΩ       | 165Hz     |
| min sustained oscillation | 1µF  | 40kΩ         | 4Hz       |


Scope trace for C1=1µF, R1(2-3)=2.15kΩ:

![1uf_2k](./assets/1uf_2k.gif?raw=true)

Scope trace for C1=1µF, R1(2-3)=40kΩ:

![1uf_40k](./assets/1uf_40k.gif?raw=true)


## Construction

![Breadboard](./assets/CMOSInverterOscillator_bb.jpg?raw=true)

![The Schematic](./assets/CMOSInverterOscillator_schematic.jpg?raw=true)

![Build](./assets/CMOSInverterOscillator_build.jpg?raw=true)

## Credits and References
* [LEAP#182 PowerSupply317Kit](../PowerSupply317Kit) - a DIY kit project that included this oscillator
* [LEAP#022 SchmittOscillator](../SchmittOscillator) - a similar (better performing) circuit using a 74LS14
* [CD4096 datasheet](http://www.alldatasheet.com/datasheet-pdf/pdf/66451/INTERSIL/CD4096BMS.html)
* [Schmitt Waveform Generators](http://www.electronics-tutorials.ws/waveforms/generators.html)
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/leap234-cmos-inverter-oscillator.html)
