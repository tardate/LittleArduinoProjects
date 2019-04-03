# #067 LEDLampAC

An AC-powered LED lamp


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

So I got this
[LED Lamp Kit](https://www.aliexpress.com/item/Free-Shipping-New-Energy-Saving-38-LEDs-Lamps-DIY-Kits-Electronic-Suite-1-Set/32266628111.html),
mainly because it was quite cheap (1.59USD) and I was interested to see what's inside.
It arrived fast (free shipping), assembled without problem (no dud parts) and even came with an extra 7 LEDs thrown in for good measure.

So is it a very good lamp? Not particularly, unless you are after a fairly dim warm white glow. Perhaps good enough for a night-light.
It's also not the safest. When assembled, there's no exposed AC or even DC power, however the only protection is the "snap-in" LED board. If that falls or is knocked out, AC circuits and wires will be exposed.

### Circuit overview

It seems the circuit is an example of a [capacitive power supply](http://en.wikipedia.org/wiki/Capacitive_power_supply).
Here are some links:
* [a good write-up on a Capacitive Power Supply Circuit](http://www.electroschematics.com/5678/capacitor-power-supply/)
* [another pretty good description](http://www.engineersgarage.com/contribution/capacitor-power-supply-design)
* [another example example](http://www.circuitsgallery.com/2012/07/transformer-less-ac-to-dc-capacitor-power-supply-circuit.html) (but seems with a few errors)
* [one of a few questions on EE.SE](http://electronics.stackexchange.com/questions/5572/how-efficient-is-a-capacitive-power-supply) on the subject.

The basic stages in the circuit:

* AC power supply
* Capacitive current limiter C1 with residual voltage protection R1
* full wave rectifier
* DC low-pass filter (R2/C2) with RC time constant of [1.8s](https://www.wolframalpha.com/input/?i=4.7%CE%BCF+*+390k%CE%A9)
* LEDs in series with R3

Capacitive reactance = 1/ωC = [4680](https://www.wolframalpha.com/input/?i=1%2F%28+2+*+pi+*+50Hz+*+0.68%CE%BCF%29)
so at 230V it will deliver [49.1mA](https://www.wolframalpha.com/input/?i=230V+%2F+%281%2F%28+2+*+pi+*+50Hz+*+0.68%CE%BCF%29%29).
Note there is no series resistor that is often recommended to handle possible startup voltage surge ("short") into the capacitor.

OK, so the more I look at the circuit the more it looks a bit nasty, and it's not clear the LEDs are being driven optimally.

Here's an attempt to [simulate it with CircuitLab](https://www.circuitlab.com/circuit/689p94/ledlampac-capacitive-power-supply/).

### LEDs

The LEDs are some variety of 5mm warm white, perhaps similar to those in [this datasheet](https://www.futurlec.com/LED/LED5WWULB.shtml).
I measured the actual forward voltage, and it ranges from about 2.69-3.02V.
So the 38 LEDs will require a total voltage drop of around 114V; not surprising as I guess this is designed to support 110V AC as a minimum.

### Construction

![The Build](./assets/LEDLampAC_build.jpg?raw=true)

![The Build](./assets/LEDLampAC_build2.jpg?raw=true)

![The Schematic](./assets/LEDLampAC_schematic.jpg?raw=true)

![Internals Front](./assets/LEDLampAC_pcb_front.jpg?raw=true)

![Internals Rear](./assets/LEDLampAC_pcb_rear.jpg?raw=true)

![Demo](./assets/LEDLampAC_demo.jpg?raw=true)

## Parts

| Ref | Part                            | Notes     |
|-----|---------------------------------|-----------|
| R1  | 390kΩ resistor                  | AC residual voltage protection  |
| R2  | 390kΩ resistor                  | DC RC low-pass filter |
| R3  | 100Ω resistor                   | LED excess voltage disipation |
| D1  | 1N4007 diode                    | 1/4 full wave rectifier [datasheet](https://www.futurlec.com/Diodes/1N4007.shtml)  |
| D2  | 1N4007 diode                    | 1/4 full wave rectifier [datasheet](https://www.futurlec.com/Diodes/1N4007.shtml)  |
| D3  | 1N4007 diode                    | 1/4 full wave rectifier [datasheet](https://www.futurlec.com/Diodes/1N4007.shtml)  |
| D4  | 1N4007 diode                    | 1/4 full wave rectifier [datasheet](https://www.futurlec.com/Diodes/1N4007.shtml)  |
| C1  | 684J 0.68μF polyester 630V      | [datasheet](http://sg.element14.com/panasonic-electronic-components/ecqe6684jf/capacitor-film-630v-0-68uf/dp/1744822?CMP=GRHB-OCTOPART-1000755)  |
| C2  | 4.7μF electrolytic capacitor    | DC RC low-pass filter |
| L1-38 | 5mm Warm White LED            | perhaps similar to this [datasheet](https://www.futurlec.com/LED/LED5WWULB.shtml) |


## Credits and References
* [38 LED Lamp DIY Kit](https://www.aliexpress.com/item/Free-Shipping-New-Energy-Saving-38-LEDs-Lamps-DIY-Kits-Electronic-Suite-1-Set/32266628111.html) - as purchased on AliExpress
* [Inside some of my earliest DIY LED lamps](https://www.youtube.com/watch?v=Ju1CQF39DH8) - excellent video by bigclivedotcom, discussing circuit design and construction of LED lamps like this

