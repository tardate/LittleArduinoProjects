# #415 555Timer/NixiePowerSupply

Using a 555 boost converter to test some Nixie IN3 and IN14 tubes.

![Build](./assets/NixiePowerSupply_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I managed to get hold of some Nixie tubes (haven't exactly decided what I'm going to do with them yet - a clock would be obvious, but maybe something different).
First step is to test them of course, and for that a high voltage (supposedly up to 180V DC) is required.

Among the many examples, I found this interesting
[instructable by Andrea Biffi](https://www.instructables.com/id/High-Voltage-Power-Supply-for-Nixie-and-Valve-Tube/)
that used a 555 timer to drive a boost converter.

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

## Circuit Design

I've used the schematic from the [instructable by Andrea Biffi](https://www.instructables.com/id/High-Voltage-Power-Supply-for-Nixie-and-Valve-Tube/)
with a few component variations including:

* for the main boost converter components:
    * 1000V 1µF X2 polypropylene film capacitor - similar to [this](https://www.mouser.com/ProductDetail/WIMA/MKP4O141007E00JSSD?qs=sGAEpiMZZMv1cc3ydrPrF8F7YPweoE08FeoTnF4ztX4%3d)
    * [FR107 1000V 1A Fast Recovery Diode](http://www.futurlec.com/Diodes/FR107.shtml)
    * [IRF730 400V n-channel MOSFET](http://www.futurlec.com/Transistors/IRF730.shtml)
* small signal transistors: I used 2N3904 NPN, 2N3906 PNP

NB: at the last minute, I realised I was out of IRF730, so I substituted an IRF610 which is only rated for 200V.
That's a bit close for comfort, but it is what I used in the examples that follow.

The currents and power consumption are reasonably low (peaking at 0.94W) so I'm building this on a breadboard.

Note that the danger of high-voltages are present. A nice feature of the circuit is that it does discharge capacitors on power-down.

![Breadboard](./assets/NixiePowerSupply_bb.jpg?raw=true)

![Schematic](./assets/NixiePowerSupply_schematic.jpg?raw=true)

A couple of things to note about the circuit:

* The 555 timer is configured as astable with a [basic frequency of 31kHz and 52% duty cycle](https://visual555.tardate.com/?mode=astable&r1=1&r2=10&c=0.0022)
* The R6 potentiometer taps a variable fraction of the boost converter output and this provides negative feedback to adjust the control voltage of the 555
* an "active pulldown" circuit comprising Q2 (2N3904), D2 (1N4148) and R8 (1kΩ) is used on the 555 output
    - this idea was borrowed from a [MC34063 design](https://threeneurons.wordpress.com/nixie-power-supply/)
    - I'm not sure this is really required, as the 555 presents an open-collector output when low. The active pulldown circuit is probably redundant (I'll test this).
* The R9/C4 across the switching FET:
    - is an RC snubber circuit, protecting the FET from voltage spikes from the inductor
    - but it is also essentially dampening the switching
    - and from my observations, responsible for perhaps 40% or more of the energy loss in the circuit
    - something to investigate further to perhaps find a better solution for protecting the FET at not such a high cost in efficiency

A similar circuit was critiqued in some detail is this Electronics StackExchange post:
[555 timer boost converter doesn't meet spec](https://electronics.stackexchange.com/questions/152432/555-timer-boost-converter-doesnt-meet-spec)

## Test Results

### IN-3


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

### IN-14

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
to light a digit. I suspect quite an error in that.


## Credits and References
* [Nixie tube](https://en.wikipedia.org/wiki/Nixie_tube) - wikipedia
* [HIGH VOLTAGE POWER SUPPLY FOR NIXIE AND VALVE TUBES by Andrea Biffi](https://www.instructables.com/id/High-Voltage-Power-Supply-for-Nixie-and-Valve-Tube/) - instructables
* [NIXIE TUBE HV DRIVER](https://www.instructables.com/id/Nixie-Tube-HV-Driver/) - another instructables, similar circuit
* [Nixie Stuff](https://threeneurons.wordpress.com/nixie-power-supply/) - threeneurons
* [IN-3 datasheet](http://www.tube-tester.com/sites/nixie/dat_arch/IN-3.pdf)
* [IN-14 information](http://www.tube-tester.com/sites/nixie/data/in-14/in-14.htm)
* [FR107 datasheet](http://www.futurlec.com/Diodes/FR107.shtml)
* [IRF730 datasheet](http://www.futurlec.com/Transistors/IRF730.shtml)
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [555 timer boost converter doesn't meet spec](https://electronics.stackexchange.com/questions/152432/555-timer-boost-converter-doesnt-meet-spec) - EE.SE
* [Resistor-Capacitor (RC) Snubber Design for Power Switches](https://www.digikey.sg/en/articles/techzone/2014/aug/resistor-capacitor-rc-snubber-design-for-power-switches)
* [..as mentioned on my blog](https://blog.tardate.com/2018/09/leap415-testing-nixies-with-a-555.html)
