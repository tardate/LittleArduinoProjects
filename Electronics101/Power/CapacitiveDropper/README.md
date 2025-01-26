# #472 Capacitive Dropper Power Supply

Understanding how to design a capacitive dropper, demonstrated with a low-voltage LED driver circuit.

![Build](./assets/CapacitiveDropper_build.jpg?raw=true)

## Notes

[Capacitive power supplies](https://en.wikipedia.org/wiki/Capacitive_power_supply) aka capacitive droppers,
are cheap and simple designs for generating a current-limited, rectified voltage, usually from mains power.

See [LEAP#067](../../LED/ACBulb) for an example of this used for mains powered LED lamp.

The essence of a capacitive dropper is to use a mains-rated capacitor in series with the power line.
The capacitive reactance at the supply frequency will limit the current that can be drawn.

Give a capacitive reactance `Xc = 1/ωC = 1/2πfC`, the available current is `I = Vac/Xc`.

There are particular safety concerns with capacitive droppers:

* the rectified circuit is not isolated, and will float relative to mains power.
* capacitors may retain a mains charge after power is disconnected if bleeder resistors are not included in the design

Typical capacitive droppers include the following circuit stages:

* AC power input with live and neutral connections. Most dropper circuits are not earthed or isolated.
* Capacitive current limiter C1 with parallel residual voltage protection R1
* Series resistor R2 to limit the impact of power-on voltage spikes on C1
* Full-wave rectifier
* DC bypass/smoothing capacitor C2
* C2 residual voltage protection R3.
* Finally, the load - often just LEDs in series with a small resistor R4 to take up the slack in the voltage drop.

Voltage regulation may be added to the load circuit if it is important.

## Low-power Demonstration Circuit

A good way of experimenting with dropper circuits is to avoid the high voltage risks of mains supply and use a low voltage AC adapter.
In this example, I'm using a 12V AC power adapter rated for 10VA.

I am using a 0.1µF X2 capacitor for C1.
In my location, our mains power is 50Hz, so the capacitive reactance Xc = 1/ωC = [31.8kΩ](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80*50Hz*0.1%CE%BCF)),
and at 12VAC, the circuit should be limited to around [0.38mA](https://www.wolframalpha.com/input/?i=12V*2%CF%80*50Hz*0.1%CE%BCF).
That's quite low, but ample for the LEDs I am driving.

I've set R1 at 220kΩ, so the discharge time constant on power off is [22ms](https://www.wolframalpha.com/input/?i=0.1%CE%BCF*220k%CE%A9).
This is perhaps on the low side for 50Hz, and would be better sized at say 1MΩ for a [100ms time constant](https://www.wolframalpha.com/input/?i=0.1%CE%BCF*1000k%CE%A9).

C2 is quite a chunky DC bypass capacitor of 220µF. This does provide very smooth power, but of course also means a slow ramp of the voltage at startup and shutdown.
With R3 at 100kΩ, the discharge time constant on power off is also very slow at [22s](https://www.wolframalpha.com/input/?i=220%CE%BCF*100k%CE%A9).
A better choice for C2 may be say 4.7µF, for a discharge time constant of [0.47s](https://www.wolframalpha.com/input/?i=4.7%C2%B5F*100k%CE%A9).

![Breadboard](./assets/CapacitiveDropper_bb.jpg?raw=true)

![Schematic](./assets/CapacitiveDropper_schematic.jpg?raw=true)

Initial testing on a breadboard:

![CapacitiveDropper_bb_build](./assets/CapacitiveDropper_bb_build.jpg?raw=true)

Here's a scope trace of:

* CH1 (Yellow) - AC input
* CH2 (Blue) - AC voltage across the bridge rectifier and R2 i.e. after C1

![scope_ac_drop](./assets/scope_ac_drop.gif?raw=true)

## Freeform Build

Just for fun, I whipped up a freeform realisation of the circuit.

![CapacitiveDropper_freeform](./assets/CapacitiveDropper_freeform.jpg?raw=true)

![CapacitiveDropper_build](./assets/CapacitiveDropper_build.jpg?raw=true)

## Credits and References

* [capacitive power supply](https://en.wikipedia.org/wiki/Capacitive_power_supply) - wikipedia
* Some good capacitive dropper circuit/project write-ups:
    * [Capacitive Dropper](https://bobparadiso.com/2015/02/03/capacitive-dropper/) - bobparadiso
    * [Capacitive Power Supply Circuit](https://www.electroschematics.com/5678/capacitor-power-supply/) - electroschematics
    * [Light Weight Capacitive Power Supply Design](https://www.engineersgarage.com/contribution/capacitor-power-supply-design)
    * [Transformer less AC to DC power supply circuit using dropping capacitor](https://www.circuitsgallery.com/2012/07/transformer-less-ac-to-dc-capacitor-power-supply-circuit2.html)
* [one of a few questions on EE.SE](http://electronics.stackexchange.com/questions/5572/how-efficient-is-a-capacitive-power-supply) on the subject.
