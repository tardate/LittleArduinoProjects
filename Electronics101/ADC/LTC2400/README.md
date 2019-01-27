# #448 LTC2400 ADC

Exploring the tips and traps involved in getting accurate readings from the LTC2400 24-bit ADC.

![Build](./assets/LTC2400_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I used a combination of an LTC2400 ADC with LT1019 2.5V voltage reference and voltage divider front-end
for the [LEAP#372 MilliVoltmeter](../../../Equipment/MilliVoltmeterDIY) build.

But as @alex1sh pointed out in [#11](https://github.com/tardate/LittleArduinoProjects/issues/11),
the accuracy is far from ideal (in my case it skews from +27mV for low voltages to -90mV for high voltages).

The LTC2400 advertises 4ppm full-scale error, so what is going on? That's what I'm investigating and documenting here.

Note: this is a work-in-progress, as I've yet to get good reproduceable results. See the final section of these notes for the current summary and planned next steps.


### Choice Picks from the LTC2400 Datasheet

A close read of the [LTC2400 info and datasheet](http://www.linear.com/product/LTC2400) is a good place to start.
Some key things I noted:

#### Voltage Reference Range

While Analog Input Voltage is rated for `–0.3V` to `VCC + 0.3V` (p2, Absolute Maximum Ratings), it is qualified with notes, in particular:

Note 14:

* For reference voltage values VREF > 2.5V the extended input of –0.125 • VREF to 1.125 • VREF is limited by the absolute maximum rating of the Analog Input Voltage pin (Pin 3).
* For 2.5V < VREF ≤ 0.267V + 0.89 • VCC the input voltage range is – 0.3V to 1.125 • VREF.
* For 0.267V + 0.89 • VCC < VREF ≤ VCC the input voltage range is – 0.3V to VCC + 0.3V.

Since I am using a 2.5V VREF, and VCC = 5.0V:

* `0.267V + 0.89 • VCC` = [4.717V](https://www.wolframalpha.com/input/?i=0.267V+%2B+0.89+*+5V)
* so my input voltage range is –0.3V to [1.125 • VREF = 2.8125V](https://www.wolframalpha.com/input/?i=1.125*2.5)

With the 1MΩ : 100kΩ voltage divider on the analog input, the
maximum input voltage possible before maxing out the reading is therefore
[30.94V](https://www.wolframalpha.com/input/?i=2.8125V*(100k%CE%A9%2B1M%CE%A9)%2F100k%CE%A9).
At this scaling, 1 bit resolution in the ADC represents [1.77µV](https://www.wolframalpha.com/input/?i=30%2F2%5E24) input.


#### Output Data Format

Covered on p12, Table 2. LTC2400 Output Data Format:

* input from 0V to VREF, are represented by 0x000000 to 0xFFFFFF in the 24 bits from MSB to LSB of the data frame
* the 4 sub LSBs are valid conversion results beyond the 24-bit level that may be included in averaging or discarded without loss of resolution
* SIG and EXR bits are used to extend the range above VREF and below 0V (subject to limits above)


#### Driving the Input and Reference

From p22..

The LTC2400 is a [delta-sigma analog-to-digital converter](https://en.wikipedia.org/wiki/Delta-sigma_modulation)

The analog input and reference are applied to a switched capacitor network, clocked at 153,600Hz i.e. a 6.5μs sampling period.
The switching/sampling actually results in "small" current spikes on VIN and VREF.

![ltc2400_equivalent_input](./assets/ltc2400_equivalent_input.png?raw=true)

This puts an important constraint on the analog input and reference signals:

* the datasheet quotes fourteen time constants required each time a capacitor is switched to achieve 1ppm settling accuracy.
* so time constant at VIN and VREF should be less than 6.5μs/14 = 460ns

Higher resistance and capacitance at VIN contribute to offset and full-scale error. General rule:

* if small capacitance at VIN (<0.01μF), relatively large external source resistances (up to 20k for 20pF parasitic capacitance) can be tolerated without any offset/full-scale error.
* for large input capacitor values (CIN > 0.01μF), the gain shift becomes a linear function of input source resistance independent of input capacitance, corresponding to a 0.3ppm shift in offset and full-scale readings for every 1Ω of input source resistance.


General rule for reference input:

* if capacitance tied to VREF is small (CVREF < 0.01μF), an input resistance of up to 20k (20pF parasitic capacitance at VREF) may be tolerated
* if external capacitance is large (CVREF > 0.01μF)
    * linearity degraded by 0.15ppm/Ω
    * full-scale error shift is 0.3ppm/Ω of


#### Application Notes

The [LTC2400 info page](http://www.linear.com/product/LTC2400) has a few relevant application notes.
Nothing that precisely covers the scenario and issues I'm concerned with, but some points to note:

* most circuits employ a buffer opamp
* few (no?) examples use as external voltage reference. For demonstration purposes, most use VREF = VCC.


## Test Code

In the following scenarios, I'm using the [LTC2400.ino](./LTC2400.ino) sketch to calibrate and perform data logging from the LTC2400.
The ADC peripheral interface is implemented in ltc2400_adc.h/ltc2400_adc.cpp.

The sketch is used via the serial interface:

* on start, it asks for the voltage reference to be entered
* performs a calibration to that reference value
* then proceeds to log ADC readings every few seconds. It shows raw ADC values and the implied input voltage based on the calibration factor


![LTC2400_console](./assets/LTC2400_console.png?raw=true)


## Scenario 1: Baseline Circuit

As a baseline test, I'm first using a reference voltage and ADC circuit identical to the one used for the MilliVoltmeter build.

It is calibrated to 2.5V, and takes an input voltage directly through a 1MΩ:100kΩ voltage divider, without the 10µF C6 installed.

    LTC2400 Diags
    Connect VIN to VREF and enter the reference voltage (in volts):
    Calibrating for VREF = 2.5000000000
    Calibration complete. ADC Calibration Factor = 0x1745B6
    ADC Raw: 0x21745B29,  Current sample: 0x1745B2 = 2.4999933242V,  Average sample: 0x1745C1 = 2.5000181198V


![Breadboard](./assets/LTC2400_baseline_bb.jpg?raw=true)

![Schematic](./assets/LTC2400_baseline_schematic.jpg?raw=true)


Sample readings for VREF=2.5 and ADC Calibration Factor = 0x1745B6:

| VIN   | ADC Raw    | Sample   | Voltage Reading | Error |
|-------|------------|----------|-----------------|-------|
| 1.250 | 0x20BC961B | 0xBC961  | 1.2661653757V   | [1.293%](https://www.wolframalpha.com/input/?i=(1.2661653757+-+1.250)%2F1.250+to+percent) |
| 1.901 | 0x211DC088 | 0x11DC08 | 1.9185352325V   |       |
| 5.05  | 0x22E641F9 | 0x2E641F | 4.9835085868V   |       |
| 7.65  | 0x24612C32 | 0x4612C3 | 7.5275397300V   |       |
| 10.27 | 0x25DEB659 | 0x5DEB65 | 10.0891914367V  | [-1.761%](https://www.wolframalpha.com/input/?i=(10.0891914367+-+10.27)%2F10.27+to+percent) |


These readings have significantly skew and error just like I'd seen in the MilliVoltmeter.

Attaching a scope probe to the vin pin of the LTC2400, it is possible to see the effect of the
switched-capacitor network during the sampling phase. A series of spikes and discharge curves are present:

![scope_vin_scenario_1](./assets/scope_vin_scenario_1.gif?raw=true)


## Scenario 2: Capacitor Stabilisation

A quick variation on scenario 1 is to add a 10µF capacitor C6 to stabilise VIN.
The 24-Bit A/D Demo Board Schematic from the datasheet (Figure 42) implies this might be a good idea.

But experimentally, when using it to stabilise a 1MΩ:100kΩ voltage divider, the effect is to degrade the accuracy even further.

    LTC2400 Diags
    Connect VIN to VREF and enter the reference voltage (in volts):
    Calibrating for VREF = 2.5000000000
    Calibration complete. ADC Calibration Factor = 0x17B47C
    ADC Raw: 0x21873FC4,  Current sample: 0x1873FC = 2.5788912773V,  Average sample: 0x17D9B6 = 2.5153360366V


| VIN   | ADC Raw    | Sample   | Voltage Reading | Error |
|-------|------------|----------|-----------------|-------|
| 1.253 | 0x20B3D923 | 0xB3D92  | 1.1854567527V   | [-5.39%](https://www.wolframalpha.com/input/?i=(1.1854567527+-+1.253)%2F1.253+to+percent) |
| 10.18 | 0x25DCF857 | 0x5DCF85 | 9.8935403823V   | [-2.814%](https://www.wolframalpha.com/input/?i=(9.8935403823+-+10.18)%2F10.18+to+percent) |

As might be expected, the additional large-value capacitor is significantly affecting the
switched-capacitor network during the sampling phase:

![scope_vin_scenario_2](./assets/scope_vin_scenario_2.gif?raw=true)


## Scenario 3: Buffered VREF and VIN Signals

Given the non-trivial impact that the switched-capacitor network of the LTC2400 has on reference and input signals,
it follows that buffering these inputs may lead to better stability and accuracy.

This technique is actually described in many of the examples in application note
[AN78-8 "A Collection of Differential to Single-Ended Signal Conditioning Circuits for Use with the LTC2400"](https://www.analog.com/media/en/technical-documentation/application-notes/an78fs.pdf).

For this test, I have an LMV324 buffering the 2.5V voltage reference in two independent buffers:

* one buffer feeds the LTC2400 reference input
* the other buffer is directly feeding the LTC2400 vin

In this configuration, once would expect:

* the ADC reading should be 0xFFFFFF, i.e. exactly equal to the reference voltage
* errors and fluctuations should be minimised

Here's an example trace:

    LTC2400 Diags
    Connect VIN to VREF and enter the reference voltage (in volts):
    Calibrating for VREF = 2.5000000000
    Calibration complete. ADC Calibration Factor = 0xFFEF28
    ADC Raw: 0x2FFEEDB9,  Current sample: 0xFFEEDB = 2.4999885559V,  Average sample: 0xFFEED5 = 2.4999876022V
    ADC Raw: 0x2FFF18C1,  Current sample: 0xFFF18C = 2.5000913143V,  Average sample: 0xFFEF24 = 2.4999992847V
    ADC Raw: 0x2FFF0795,  Current sample: 0xFFF079 = 2.5000503063V,  Average sample: 0xFFEF43 = 2.5000040531V
    ADC Raw: 0x2FFF1676,  Current sample: 0xFFF167 = 2.5000855922V,  Average sample: 0xFFEF8E = 2.5000152587V
    ADC Raw: 0x2FFF1DC1,  Current sample: 0xFFF1DC = 2.5001032352V,  Average sample: 0xFFEFC0 = 2.5000226497V
    ADC Raw: 0x2FFF1F80,  Current sample: 0xFFF1F8 = 2.5001072883V,  Average sample: 0xFFF01B = 2.5000362396V
    ADC Raw: 0x2FFF1B08,  Current sample: 0xFFF1B0 = 2.5000965595V,  Average sample: 0xFFF069 = 2.5000479221V
    ADC Raw: 0x2FFF1AF7,  Current sample: 0xFFF1AF = 2.5000963211V,  Average sample: 0xFFF0BC = 2.5000603199V
    ADC Raw: 0x2FFF1DA8,  Current sample: 0xFFF1DA = 2.5001027584V,  Average sample: 0xFFF106 = 2.5000712871V
    ADC Raw: 0x2FFF20D1,  Current sample: 0xFFF20D = 2.5001103878V,  Average sample: 0xFFF156 = 2.5000832080V
    ADC Raw: 0x2FFF207B,  Current sample: 0xFFF207 = 2.5001094341V,  Average sample: 0xFFF1A7 = 2.5000951290V
    ADC Raw: 0x2FFF1F1D,  Current sample: 0xFFF1F1 = 2.5001063346V,  Average sample: 0xFFF1B1 = 2.5000967979V
    ADC Raw: 0x2FFF22AB,  Current sample: 0xFFF22A = 2.5001146793V,  Average sample: 0xFFF1DD = 2.5001032352V
    ADC Raw: 0x2FFF20CA,  Current sample: 0xFFF20C = 2.5001103878V,  Average sample: 0xFFF1ED = 2.5001056194V
    ADC Raw: 0x2FFF2A45,  Current sample: 0xFFF2A4 = 2.5001327991V,  Average sample: 0xFFF201 = 2.5001087188V
    ADC Raw: 0x2FFF209B,  Current sample: 0xFFF209 = 2.5001099109V,  Average sample: 0xFFF203 = 2.5001089572V
    ADC Raw: 0x2FFF21C6,  Current sample: 0xFFF21C = 2.5001127719V,  Average sample: 0xFFF20E = 2.5001106262V
    ADC Raw: 0x2FFF1C5C,  Current sample: 0xFFF1C5 = 2.5000996589V,  Average sample: 0xFFF210 = 2.5001108646V


That is a disappointing result on two points:

* the average ADC reading 0xFFF18A is offset from the expected 0xFFFFFF by -0.022%
* and the results vary by a range of 0x3C9. Given that readings are in the order of 16 million, that represents a range of around 60 ppm - far above the stated error bands in the datasheet.


![LTC2400_buffered_vref_bb](./assets/LTC2400_buffered_vref_bb.jpg?raw=true)

![LTC2400_buffered_vref_schematic](./assets/LTC2400_buffered_vref_schematic.jpg?raw=true)


## Regrouping / Conclusions to-date

My next steps would be to test buffered input with and without a voltage divider,
however the error encountered in Scenario 3: Buffered VREF and VIN Signals give some pause:
if acceptable error levels cannot be maintained in this case,
it would be reasonable to expect the further tests would fair no better, and likely perform worse.

So what could be contributing to the error levels I'm seeing. Some possibilities:

1. excessive noise in the experimental setup. All the tests so far have been performed on a breadboard, using the 5V supply form the Arduino
2. the LMV324 op-amp buffer varies from the ideal buffer model and actively interferes with the switched-capacitor sampling model used by the LTC2400
3. faulty components? The LT1019 and LTC2400 chips I'm using ware obtained from a reputable channel so I would not blame the parts in the first instance. I have also switched chips along the way and results remain consistent
4. I've made some fundamental mistake here in the application, or understanding of how to correctly use the LTC2400


I would guess that (1) and (2) are the most likely problem areas, and also the ones easiest to test further.
I think my next steps may be to:

1. Put the circuit on a PCB, perhaps Manhattan style over a solid ground plane and an independent low-noise power supply
2. Replace the LMV324 op-amp with either:
    * LT1077 precision op-amp, as the LT1077 is the part used in LTC2400 reference designs in application notes so may be assumed to be "well matched". The LT1077 has much better voltage offset and drift specifications and also a lower slew rate which may be beneficial in this application
    * another alternative is the OP07DD, as it's also been seen in precision analog front-end designs and better specs than the LMV324
    * or the AD8628ARZ as used in the Scullcom millivoltmeter design and better specs than the LMV324


Comparing op-amp options:

| Measure                  | LMV324    | LT1077                 | OP07DD   | AD8628ARZ              |
|--------------------------|-----------|------------------------|----------|------------------------|
| Max Supply Current       | 200µA     | 60µA                   |          |                        |
| Max Offset Voltage       | 3mV       | 40µV                   | 150µV    | 5µV                    |
| Max Offset Current       | 9nA       | 350pA                  | 6nA      | 200pA                  |
| Voltage Noise            | ?         | 0.5µVp-p 0.1Hz to 10Hz |          | 0.5µVp-p 0.1Hz to 10Hz |
| Current Noise            | ?         | 2.5pAp-p 0.1Hz to 10Hz |          |                        |
| Offset Voltage Drift     | 2µV/°C    | 0.4µV/°C               | 2.5µV/°C | 0.02µV/°C              |
| Gain-Bandwidth Product   | 1MHz      | 250kHz                 | 0.6MHz   | 2.5MHz                 |
| Slew Rate                | 0.35V/µs  | 0.12V/µs               | 0.3V/µs  | 1V/µs                  |



## Credits and References
* [LTC2400 info and datasheet](http://www.linear.com/product/LTC2400)
* [LT1019 info and datasheet](http://www.linear.com/product/LT1019)
* [LMV324 Datasheet](https://www.fairchildsemi.com/datasheets/LM/LMV324.pdf)
* [LT1077](https://www.analog.com/en/products/lt1077.html)
* [OP07DD](https://www.ti.com/store/ti/en/p/product?p=OP07DD)
* [AD8628ARZ](https://www.analog.com/media/en/technical-documentation/data-sheets/ad8628_8629_8630.pdf)
* [Delta-sigma modulation](https://en.wikipedia.org/wiki/Delta-sigma_modulation) - wikipedia
* [Delta-Sigma Analog to Digital Converters](https://www.youtube.com/watch?v=SFAS8nE4_ZM) - Hackaday on Youtube
* [LEAP#372 MilliVoltmeter](../../../Equipment/MilliVoltmeterDIY) build.
