# #330 Power/Any2AnyPowerPack

A 2.1mm DC adapter pack with battery bypass and any-polarity to any-polarity connectors.

![Build](./assets/Any2AnyPowerPack_build.jpg?raw=true)

## Notes

I recently got a flamenco metronome that has a 2.1mm power connector but in centre-negative configuration.
Unfortunately I don't have any centre-negative power packs on hand. I could of course just rewire one,
but decided it might be the time to make up a generic any-to-any connector.

Features I'll add:

* centre-positive and centre-negative output plugs
* 9V battery bypass
* polarity rectifier, so that the input supports both centre-positive and centre-negative connections
* a power switch
* an LED power indicator

### Input Power Rectifier

To protect against reverse polarity input power, I could just add a single rectifier diode in series.
That would prevent the connection of power with the wrong polarity.

A little more fancy is a rectifier bridge that allows connection in either polarity.
There is a price to pay however: loss of two diode drops from the power supply.

Since I'm not dealing with huge voltages here (planning for 5-9V), and DC operation so switching speed is irrelevant,
there's a broad choice of rectifiers possible e.g.

* 1N4001-7 standard go-to rectifiers with a pretty high average Vf of 0.8V, but extremely low reverse current of 30µA
* 1N5819 offers extremely low Vf (0.34 V at 100mA), however the maximum reverse current at rated voltage is pretty high at 1mA

I decided to use the 1N5819 in the bridge rectifier to get the low forward voltage benefit.
The reverse current is a little high, but at low voltages and currents perhaps negligible enough and in practice this
should be swallowed by the bridge rectifier (just showing up as a reduced efficiency)

Some measurements to back that up:


| Diode  | Input Voltage | Output Voltage, No Load | 1kΩ Load | 10kΩ Load | 100kΩ Load |
|--------|---------------|-------------------------|----------|-----------|------------|
| 1N4007 | 8.72V         | 8.13V                   | 6.88V    | 7.54V     | 7.78V      |
| 1N5819 | 8.72V         | 8.62V                   | 7.97V    | 8.29V     | 8.43V      |


PS: the "evils" of centre-negative jacks has now been explored in [EEVblog #1015](https://www.youtube.com/watch?v=ix2fR-rh1vc) - some great background
and demonstration of how these work.

## Circuit

![Breadboard](./assets/Any2AnyPowerPack_bb.jpg?raw=true)

![Schematic](./assets/Any2AnyPowerPack_schematic.jpg?raw=true)

## Construction

![Any2AnyPowerPack_construction_1](./assets/Any2AnyPowerPack_construction_1.jpg?raw=true)

![Any2AnyPowerPack_construction_2](./assets/Any2AnyPowerPack_construction_2.jpg?raw=true)

![Build](./assets/Any2AnyPowerPack_build.jpg?raw=true)

## Credits and References
* [EEVblog #1015 - Beware Evil (But Clever) DC Jacks!](https://www.youtube.com/watch?v=ix2fR-rh1vc)
* [1N5819 Datasheet](https://www.futurlec.com/Diodes/1N5819.shtml)
* [1N4001-7 Datasheet](https://www.futurlec.com/Diodes/1N4001.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2017/08/leap330-any-to-an-polarity-dc-power-adapter.html)
