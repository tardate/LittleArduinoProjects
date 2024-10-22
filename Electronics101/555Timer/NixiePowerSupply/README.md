# #415 555Timer/NixiePowerSupply

Using a 555 boost converter to test some Nixie IN3 and IN14 tubes.

![Build](./assets/NixiePowerSupply_build.jpg?raw=true)

## Notes

I managed to get hold of some Nixie tubes (haven't exactly decided what I'm going to do with them yet - a clock would be obvious, but maybe something different).
First step is to test them of course, and for that a high voltage (supposedly up to 180V DC) is required.

Among the many examples, I found this interesting
[instructable by Andrea Biffi](https://www.instructables.com/id/High-Voltage-Power-Supply-for-Nixie-and-Valve-Tube/)
that used a 555 timer to drive a boost converter.
NB: it seems this and most other 555 Nixie driver circuits are probably derived from Ronald Dekker's
[A simple boost converter high voltage supply for NIXIEs](http://www.dos4ever.com/flyback/flyback.html#boost2).

From the outset, I knew this would not be a very practical circuit due to it's reported low conversion efficiency, but good enough
(and importantly: interesting enough) for a test.

### The Nixie Tubes

I have two types of tube that I obtained at a very good price from a Ukrainian seller [hfvhfparts](http://www.ebay.com/usr/hfvhfparts) on eBay:

* [IN-3: single bulb](https://www.ebay.com/itm/141804242605)
* [IN-14: 0-9 and decimal point](https://www.ebay.com/itm/131675056204)

![tube_delivery](./assets/tube_delivery.jpg?raw=true)

### IN-3

I was able to find an original
[IN-3 datasheet](http://www.tube-tester.com/sites/nixie/dat_arch/IN-3.pdf)
and some translation:

* Light up voltage - not less than 60v, not more than 90V
* Switch off voltage with anode resistor 300kOhm - not less than 55V
* Operational current -  0.8 mA
* Guaranteed life time  - not less than 5000 hours (with lighting up voltage not more than 95 V)
* Absolute maximum ratings:
    - Light up voltage - not less than 60v, not more than 95V
    - Switch off voltage - not less than 50v, not more than 80V
    - Anode current - not less than 0.2mA, not more than 1.0mA
    - Temperature - not more than plus 85C, not less than minus 60C

The anode has an arrow pointing to it on the base.

![tube_in3](./assets/tube_in3.jpg?raw=true)

### IN-14

The tube-tester site has a good
[IN-14 information](http://www.tube-tester.com/sites/nixie/data/in-14/in-14.htm)
page with the crucial details:

* Minimum supply voltage: 170v
* Typical maintaining voltage:  145v
* Typical cathode current: 2.5mA


The anode has an arrow pointing to it on the base of the tube. It also seems to be distinguished as the only pin with a white sheave inside the tube.
Pins are as follows (numbered clock-wise when looking at the base)


|Pin  | Connection                         |
|-----|------------------------------------|
|1    | Anode                              |
|2    | Cathode (PL - left decimal point)  |
|3    | Cathode (1)                        |
|4    | Cathode (2)                        |
|5    | Cathode (3)                        |
|6    | Cathode (4)                        |
|7    | Cathode (5)                        |
|8    | Cathode (6)                        |
|9    | Cathode (7)                        |
|10   | Cathode (8)                        |
|11   | Cathode (9)                        |
|12   | Cathode (0)                        |
|13   | Cathode (PR - right decimal point) |

![tube_in14](./assets/tube_in14.jpg?raw=true)

## Circuit Design - Version 1

> Note - see below for a revised circuit design and test results based on observations with this first version of the circuit.

I've used the schematic from the [instructable by Andrea Biffi](https://www.instructables.com/id/High-Voltage-Power-Supply-for-Nixie-and-Valve-Tube/)
with a few component variations including:

* for the main boost converter components:
    * 1000V 1µF X2 polypropylene film capacitor - similar to [this](https://www.mouser.com/ProductDetail/WIMA/MKP4O141007E00JSSD?qs=sGAEpiMZZMv1cc3ydrPrF8F7YPweoE08FeoTnF4ztX4%3d)
    * [FR107 1000V 1A Fast Recovery Diode](https://www.futurlec.com/Diodes/FR107.shtml)
    * [IRF730 400V n-channel MOSFET](https://www.futurlec.com/Transistors/IRF730.shtml)
* small signal transistors: I used 2N3904 NPN, 2N3906 PNP

NB: at the last minute, I realised I was out of IRF730, so I substituted an IRF610 which is only rated for 200V.
That's a bit close for comfort, but it is what I used in the examples that follow.

The currents and power consumption are reasonably low (peaking at 0.94W) so I'm building this on a breadboard.
I'm using my [LEAP#407 DPS3005-based power supply](../../../Equipment/DPS3005BenchPowerSupply) for power, set for 9V with a 0.5A current limit just in case.

Note that the danger of high-voltages are present. A nice feature of the circuit is that it does discharge capacitors on power-down.

![Breadboard](./assets/NixiePowerSupply_bb.jpg?raw=true)

![Schematic](./assets/NixiePowerSupply_schematic.jpg?raw=true)

A couple of things to note about the circuit:

* The 555 timer is configured as astable with a [basic frequency of 31kHz and 52% duty cycle](https://visual555.tardate.com/?mode=astable&r1=1&r2=10&c=0.0022)
* The R6 potentiometer taps a variable fraction of the boost converter output and this provides negative feedback to adjust the control voltage of the 555
* an "active pulldown" circuit comprising Q2 (2N3904), D2 (1N4148) and R8 (1kΩ) is used on the 555 output
    - this idea was borrowed from an [MC34063 design](https://threeneurons.wordpress.com/nixie-power-supply/)
    - I'm not sure this is really required, as the 555 presents an open-collector output when low. The active pulldown circuit is probably redundant (I'll test this).
* The R9/C4 across the switching FET:
    - is an RC snubber circuit, protecting the FET from voltage spikes from the inductor
    - but it is also essentially dampening the switching
    - and from my observations, responsible for perhaps 40% or more of the energy loss in the circuit
    - something to investigate further to perhaps find a better solution for protecting the FET at not such a high cost in efficiency

A similar circuit was critiqued in some detail is this Electronics StackExchange post:
[555 timer boost converter doesn't meet spec](https://electronics.stackexchange.com/questions/152432/555-timer-boost-converter-doesnt-meet-spec)

### Test Results

#### IN-3


![NixiePowerSupply_test_in3](./assets/NixiePowerSupply_test_in3.jpg?raw=true)

Here's a scope trace at the strike voltage.

* CH1 (yellow): Nixie anode voltage
* CH2 (blue): boost converter output
* CH3 (red): 555 timer output (pin 3)

According to my power supply, it is delivering around 0.94W (9V at 105mA) at the strike voltage.

![in3_strike](./assets/in3_strike.gif?raw=true)

Measured:
* boost voltage 90v
* anode voltage 58v
* 555 duty cycle ~30%

If those readings are reasonably correct, the IN-3 tube is juiced with [3.2mA](https://www.wolframalpha.com/input/?i=(90V+-+58V)%2F10k%CE%A9).

#### IN-14

![Build](./assets/NixiePowerSupply_build.jpg?raw=true)

Here's a scope trace at the strike voltage.

* CH1 (yellow): Nixie anode voltage
* CH2 (blue): boost converter output
* CH3 (red): 555 timer output (pin 3)

According to my power supply, it is delivering around 0.86W (9V at 96mA) at the strike voltage.

![in14_strike](./assets/in14_strike.gif?raw=true)

* boost voltage 132v
* anode voltage 130v
* 555 duty cycle ~35%

I'm doubting the accuracy not sure how accurate my oscilloscope is at those voltages,
but they would indicate the IN-14 tube is only needing [0.2mA](https://www.wolframalpha.com/input/?i=(132V+-+130V)%2F10k%CE%A9)
to light a digit. NB: I checked this with an ammeter and was a little suprised it's not far off - actually about 0.27mA.


## Circuit Design - Version 2

Base on the results above, there are a few things I wanted to investigate to see if an improved circuit was possible:

* is the active pulldown circuit really necessary?
* how much does the RC snubber contribute to inefficiency, and can it be better tuned?
* does the relatively low R3 value (1kΩ) in the 555 configuration lead to significant avoidable losses?

The details of my investigation are below, but here is the TL/DR:

* active pulldown circuit is actually a bad idea with the 555 timer as a switching controller and should be eliminated
* the RC snubber circuit reduces ringing in the boost circuit, but poor choice of components can have a significant impact on efficiency


### Active Pulldown?

In the original circuit, an "active pulldown" circuit comprising Q2 (2N3904), D2 (1N4148) and R8 (1kΩ) is used on the 555 output.
This idea was borrowed from an [MC34063 design](https://threeneurons.wordpress.com/nixie-power-supply/),
but I'm not sure this is really required, as the 555 presents an open-collector output when low:

![555_output_driver](./assets/555_output_driver.png?raw=true)

So, some measurements were in order.
Here are the results for tests with an IN-14 running at strike voltage, with various RC snubber combinations.
The "active pulldown" cases use the original circuit, those marked "direct gate drive" have the 555 output
directly coupled to the MOSFET gate.


| Configuration                          | Nixie Current  | Input Power |
|----------------------------------------|----------------|-------------|
| 30pF/4.7kΩ snubber, active pulldown    | 0.33mA         | 0.45W       |
| 30pF/4.7kΩ snubber, direct gate drive  | 0.39mA         | 0.45W       |
| 30pF/1kΩ snubber, active pulldown      | 0.30mA         | 0.44W       |
| 30pF/1kΩ snubber, direct gate drive    | 0.38mA         | 0.44W       |
| 470pF/4.7kΩ snubber, active pulldown   | 0.31mA         | 0.51W       |
| 470pF/4.7kΩ snubber, direct gate drive | 0.37mA         | 0.51W       |
| 470pF/1kΩ snubber, active pulldown     | 0.27mA         | 0.72W       |
| 470pF/1kΩ snubber, direct gate drive   | 0.31mA         | 0.71W       |


It is apparent that the active pulldown circuit has no real impact on the input power consumption,
but it does have the undesirable effect of actually reducing the Nixie current for the same power input.

I think this confirms my suspicion - the active pulldown circuit is redundant with a 555 timer and can be jetisoned.
NB: it may still be relevant for other ICs used as switching controllers.


### RC Snubber

In the original circuit, R9 (1kΩ) and C4 (470pF) across the drain-source of the switching FET act as an RC snubber.
The role of an RC snubber in switching circuits is explained pretty well in the article
[Resistor-Capacitor (RC) Snubber Design for Power Switches](https://www.digikey.sg/en/articles/techzone/2014/aug/resistor-capacitor-rc-snubber-design-for-power-switches).

The key points:

* snubbers are placed across the power switches to suppress voltage spikes and damp the ringing caused by circuit inductance when a switch opens
* power dissipation is proportional to snubber capacitance, output voltage (squared) and switching frequency.

In the following scope traces, channels are connected as follows:

* CH1 (yellow): Nixie anode
* CH2 (blue): junction of the inductor and MOSFET drain
* CH3 (red): 555 timer output

Note: these traces are captured with the active pulldown circuit already removed.

Some measurements for selected configurations:

| Snubber     | Nixie Voltage  | Nixie Current  | Input Power |                                                                        |
|-------------|----------------|----------------|-------------|------------------------------------------------------------------------|
| Removed     | 126.5V         | 0.40mA         | 0.44W       | [11.5%](https://www.wolframalpha.com/input/?i=(126.5V*0.40mA)%2F0.44W) |
| 30pF/4.7kΩ  | 126.5V         | 0.39mA         | 0.45W       | [11%](https://www.wolframalpha.com/input/?i=(126.5V*0.39mA)%2F0.45W)   |
| 30pF/4.7kΩ  | 148.0V         | 2.01mA         | 1.34W       | [22.2%](https://www.wolframalpha.com/input/?i=(148V*2.01mA)%2F1.34W)   |
| 30pF/1kΩ    | 126.5V         | 0.38mA         | 0.44W       | [10.9%](https://www.wolframalpha.com/input/?i=(126.5V*0.38mA)%2F0.44W) |
| 470pF/4.7kΩ | 126.5V         | 0.37mA         | 0.51W       | [9.2%](https://www.wolframalpha.com/input/?i=(126.5V*0.37mA)%2F0.51W)  |
| 470pF/1kΩ   | 126.5V         | 0.31mA         | 0.71W       | [5.5%](https://www.wolframalpha.com/input/?i=(126.5V*0.31mA)%2F0.71W)  |


Conclusions:
* a snubber capacitor around 30pF to 100pF with 4.7kΩ offers a good balance of stabilising the circuit without undue impact on efficiency (see scope traces below)
* at low Nixie currents, overall efficiency is swamped by other components in the system
* when Nixie current approaches higher/brighter values (say 2mA), or the power supply is being used to drive more Nixie tubes, efficiency becomes a little more decent.


#### Without Snubber

First, removing the snubber completely.
The ringing is very obvious, but it does not have any apparent impact on the Nixie voltage.

At 0.40mA, the current delivered to the Nixie tube is slightly more that with a snubber in place (for the same input power).

In this configuration, the efficiency of the circuit is only [11.5%](https://www.wolframalpha.com/input/?i=(126.5V*0.40mA)%2F0.44W)

![in14_strike_rc_na](./assets/in14_strike_rc_na.gif?raw=true)


####  RC Snubber Examples

Using a selection of RC values for the snubber...

30pF/1kΩ: has reduced the amplitude of the ringing but it still affect the entire on-cycle.

![in14_strike_rc_30_1k](./assets/in14_strike_rc_30_1k.gif?raw=true)

30pF/4.7kΩ: more ringing now fully dampened before the end of the on-cycle.

![in14_strike_rc_30_4k7](./assets/in14_strike_rc_30_4k7.gif?raw=true)

100pF/1kΩ: ringing dampened by much earlier in the the on-cycle.

![in14_strike_rc_101_1k](./assets/in14_strike_rc_101_1k.gif?raw=true)

100pF/4.7kΩ: not much different than the 1kΩ case.

![in14_strike_rc_101_4k7](./assets/in14_strike_rc_101_4k7.gif?raw=true)

150pF/1kΩ

![in14_strike_rc_151_1k](./assets/in14_strike_rc_151_1k.gif?raw=true)

150pF/4.7kΩ

![in14_strike_rc_151_4k7](./assets/in14_strike_rc_151_4k7.gif?raw=true)

470pF/1kΩ: ringing fully dampened

![in14_strike_rc_471_1k](./assets/in14_strike_rc_471_1k.gif?raw=true)

470pF/4.7kΩ: ringing deteriorates compared to the 1kΩ case

![in14_strike_rc_471_4k7](./assets/in14_strike_rc_471_4k7.gif?raw=true)


#### A Better 555 Astable Configuration?

When the 555 timer discharges, R3 (1kΩ) is placed essentially across the supply rails (plus a diode drop),
hence low values can lead to significant wasted power.

I switched the astable configuration to 10kΩ/47kΩ/470pF which produces a similar base oscillation of
[29kHz at 54% duty cycle](https://visual555.tardate.com/?mode=astable&r1=10&r2=47&c=0.00047).

However I was non-plussed by the results - negligible improvement in efficiency (in the 0.1% range) -
so I abandoned this idea.


### Version 2 Construction

Removes active pulldown circuit and adjusts RC snubber component values

![Breadboard](./assets/NixiePowerSupply_v2_bb.jpg?raw=true)

![Schematic](./assets/NixiePowerSupply_v2_schematic.jpg?raw=true)



## Credits and References

* [Nixie tube](https://en.wikipedia.org/wiki/Nixie_tube) - wikipedia
* [A simple boost converter high voltage supply for NIXIEs](http://www.dos4ever.com/flyback/flyback.html#boost2) - perhaps one of the earliest exampels of a 555 boost circuit for Nixies
* [HIGH VOLTAGE POWER SUPPLY FOR NIXIE AND VALVE TUBES by Andrea Biffi](https://www.instructables.com/id/High-Voltage-Power-Supply-for-Nixie-and-Valve-Tube/) - instructables
* [NIXIE TUBE HV DRIVER](https://www.instructables.com/id/Nixie-Tube-HV-Driver/) - another instructables, similar circuit
* [Nixie Stuff](https://threeneurons.wordpress.com/nixie-power-supply/) - threeneurons
* [IN-3 datasheet](http://www.tube-tester.com/sites/nixie/dat_arch/IN-3.pdf)
* [IN-14 information](http://www.tube-tester.com/sites/nixie/data/in-14/in-14.htm)
* [FR107 datasheet](https://www.futurlec.com/Diodes/FR107.shtml)
* [IRF730 datasheet](https://www.futurlec.com/Transistors/IRF730.shtml)
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [555 timer boost converter doesn't meet spec](https://electronics.stackexchange.com/questions/152432/555-timer-boost-converter-doesnt-meet-spec) - EE.SE
* [Resistor-Capacitor (RC) Snubber Design for Power Switches](https://www.digikey.sg/en/articles/techzone/2014/aug/resistor-capacitor-rc-snubber-design-for-power-switches)
* [..as mentioned on my blog](https://blog.tardate.com/2018/09/leap415-testing-nixies-with-a-555.html)
