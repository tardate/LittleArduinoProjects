# #433 Adjustable Power Supply Kit

Building a popular 30V/3A adjustable power supply kit, making an enclosure and testing.

![Build](./assets/AdjustablePowerSupplyKit_build.jpg?raw=true)

## Notes

The [0-30V 2mA-3A Adjustable DC Regulated Power Supply DIY Kit](https://www.aliexpress.com/item/1Set-Red-0-30V-2mA-3A-Continuously-Adjustable-DC-Regulated-Power-Supply-DIY-Kit-For-School/32789006670.html) is widely available from most hobby electronics markets (aliexpress, Banggood, eBay).

It features continuously variable output voltage, and a variable current limit with overcurrent indicator/shutdown.

It appears this design may have originated from [SmartKit](https://www.smartkit.gr/stabilised-power-supply-0-30v-3a-m.html) in Greece,
improved by [various people](http://www.electronics-lab.com/project/0-30-vdc-stabilized-power-supply-with-current-control-0-002-3-a/),
and at some point the "canonical design" was picked up for mass production (instantly identifiable by the red PCB and tall cap).

I'm certainly not the first to build the kit - it's a common project, just [search YouTube for 0-30V power supply](https://www.youtube.com/results?search_query=0-30V+power+supply) - for example this build by Boris Dusnoki:

[![clip](https://img.youtube.com/vi/DLxOwVw1NEE/0.jpg)](https://www.youtube.com/watch?v=DLxOwVw1NEE)


## Kit Specifications

* Material: PCB
* Color: Red
* Input Voltage: 24V AC
* Input Current: Max 3A
* Output Voltage: 0-30V (continuously adjustable)
* Output Current: 2mA-3A (continuously adjustable)
* Output Voltage Ripple: Max 0.01%
* Assembled Item Size: 9 * 8.5 * 3.5cm / 3.5 * 3.4 * 1.4in
* Package Size: 15 * 11 * 2cm / 5.9 * 4.3 * 0.8in
* Package Weight: 86g / 3oz

### Parts

| Qty | Refs   | Description                             | Note |
|-----|--------|-----------------------------------------|------|
| 1   |        | 0.47Ω 5w                                |      |
| 1   |        | 33Ω 1/4w                                |      |
| 1   |        | 82Ω 1/4w                                |      |
| 1   |        | 220Ω 1/4w                               |      |
| 2   |        | 1kΩ 1/4w                                |      |
| 1   |        | 1.5kΩ 1/4w                              |      |
| 2   |        | 2.2kΩ 1/4w                              |      |
| 1   |        | 2.2kΩ 1w                                |      |
| 1   |        | 3.9kΩ 1/4w                              |      |
| 1   |        | 4.7kΩ 1/4w                              |      |
| 5   |        | 10kΩ 1/4w                               |      |
| 2   |        | 27kΩ 1/4w                               |      |
| 2   |        | 56kΩ 1/4w                               |      |
| 1   |        | 270kΩ 1/4w                              |      |
| 2   |        | B10kΩ variable pot                      |      |
| 1   |        | 100kΩ trim pot                          |      |
| 2   |        | 100pF                                   |      |
| 1   |        | 330pF                                   |      |
| 1   |        | 100nF                                   |      |
| 1   |        | 220nF                                   |      |
| 1   |        | 10µF 50V                                |      |
| 2   |        | 47µF 50V                                |      |
| 1   |        | 3300µF 50V                              |      |
| 1   |        | 1N4004                                  |      |
| 4   |        | 1N4148                                  | extras supplied |
| 4   |        | 1N5408                                  |      |
| 2   |        | 5V1                                     |      |
| 1   |        | 3mm white LED                           | replaced this with a red LED in the final build  |
| 1   |        | L7824 24V 1A Positive Regulator         |      |
| 1   |        | 9014 NPN Small Signal Transistor        |      |
| 1   |        | 9015 PNP Small Signal Transistor        |      |
| 1   |        | D882 NPN Power Transistor               | [datasheet](https://www.st.com/resource/en/datasheet/2sd882.pdf)     |
| 1   |        | D1047 High power NPN bipolar transistor | [datasheet](https://www.st.com/resource/en/datasheet/2sd1047.pdf)     |
| 3   |        | TL081 JFET Input Op Amp                 |      |
| 1   |        | 2-pin terminal block                    |      |
| 1   |        | 3-pin terminal block                    |      |
| 1   |        | heatsink                                |      |
| 2   |        | XH2.54 3P female plug and wire          |      |
| 2   |        | XH2.54 3P male PCB socket               |      |
| 1   |        | 2 pin header                            |      |
| 4   |        | M3 screw                                |      |
|     |        | 22pF                                    | extra 3 in the kit for some reason! |


![kit_parts](./assets/kit_parts.jpg?raw=true)

![kit_pcb](./assets/kit_pcb.jpg?raw=true)


## Construction

The board is an easy build. At this point I tested it to verify operation.
Note that it requires an AC supply to operate correctly.

![AdjustablePowerSupplyKit_base_build](./assets/AdjustablePowerSupplyKit_base_build.jpg?raw=true)


## How It Works

More information can be found in various places, such as:

* [electronics-lab.com](http://www.electronics-lab.com/project/0-30-vdc-stabilized-power-supply-with-current-control-0-002-3-a/)
* [Banggood](https://sea.banggood.com/0-30V-2mA-3A-Adjustable-DC-Regulated-Power-Supply-DIY-Kit-p-958308.html)

Here's a partial schematic of the main power supply circuit. I'll probably tidy and complete this later (e.g. it does not include the 24V fan power supply).

![core_schematic](./assets/core_schematic.jpg?raw=true)


## Enclosure and Additional Hardware


To trick this out as a finished bench power supply, I opted for the following:

A [6.7" x 5.1" x 3.1" Blue Metal Enclosure Project Case](https://www.aliexpress.com/item/6-7-x-5-1-x-3-1-Blue-Metal-Enclosure-Project-Case-DIY-Junction-Box/32825937652.html)

![kit_extras_enclosure](./assets/kit_extras_enclosure.jpg?raw=true)

Mains power supply via [fused socket and switch](https://www.aliexpress.com/item/NEW-HIGH-QUALITY-Red-Light-Power-Rocker-Switch-Fused-IEC-320-C14-Inlet-Power-Socket-Fuse/32801835266.html):

![kit_extras_fused_switch](./assets/kit_extras_fused_switch.jpg?raw=true)


A [15W, 24VAC step-down transformer](https://www.aliexpress.com/item/9VAC-0-9VAC-Output-Voltage-15W-EI-Ferrite-Core-Input-220V-50Hz-Vertical-Mount-Electric-Power/1695406839.html)

![kit_extras_transformer](./assets/kit_extras_transformer.jpg?raw=true)

A Volt/Ammeter display for the front panel. I've covered this component in detail in [LEAP#289 VoltmeterAmmeterModule](../../Electronics101/VoltmeterAmmeterModule)
It is powered from the 24V fan power supply, in parallel with the fan.

![kit_extras_voltammeter](./assets/kit_extras_voltammeter.jpg?raw=true)

I've mounted a [40mm  9 blade 24V fan](https://www.aliexpress.com/item/40mm-4cm-2-Pin-9-Blades-Computer-Chipset-Cooling-Fan-DC-24V/32852382945.html)
on the side of the unit, without any additional heat-sink on the main power transistor.
It turned out to be a noisy bugger.
My power requirements are minimal for now, I will proabbly re-assess in the future and make some temperature measurements under load.

![kit_extras_fan](./assets/kit_extras_fan.jpg?raw=true)

For the front panel power connectors, I've used a [nice dual banana binding post](https://www.aliexpress.com/item/High-Quality-Speaker-Amplifier-Dual-Binding-Post-Banana-Plug-Socket-Connectors-5pcs/32738527737.html).

![kit_extras_binding_post](./assets/kit_extras_binding_post.jpg?raw=true)


Finally a [metal bezel](https://www.aliexpress.com/item/10pcs-3mm-LED-Emitting-Diode-Metal-Bezel-Holder-Round-Chrome-LED-Lamp-Base-with-10pcs-Plastic/32881242918.html)
for mounting the current-limit LED on the front panel

![kit_extras_bezel](./assets/kit_extras_bezel.jpg?raw=true)

## Final Build

![AdjustablePowerSupplyKit_build_internal_front](./assets/AdjustablePowerSupplyKit_build_internal_front.jpg?raw=true)

![AdjustablePowerSupplyKit_build_internal_rear](./assets/AdjustablePowerSupplyKit_build_internal_rear.jpg?raw=true)

![AdjustablePowerSupplyKit_build_rear](./assets/AdjustablePowerSupplyKit_build_rear.jpg?raw=true)

![Build](./assets/AdjustablePowerSupplyKit_build.jpg?raw=true)

## Calibration

There are three calibration points for my build: zero volt offset for the regulator, and voltage/current adjustment for the panel meter.

The VR1 (blue pot) on the PCB is to zero the voltage offset of the power supply:

![calibration_zero_offset](./assets/calibration_zero_offset.jpg?raw=true)


The meter has adjustments for voltage and current on the rear of the unit.
With a 50Ω load (actually 49Ω according to my DMM), I'm reading 0.19A at 11.8V according to the panel meter.
The voltage is spot on, but the current is off from the expected [~0.23A](https://www.wolframalpha.com/input/?i=11.8V%2F49%CE%A9),
and I later made the adjustment to get this within 10mA of actual.

![calibration_voltammeter](./assets/calibration_voltammeter.jpg?raw=true)


## Over-current Test

The current-limit setting (blue knob in my build) works as expected. When current limit is exceeded, the output shuts off:

![AdjustablePowerSupplyKit_test_overcurrent](./assets/AdjustablePowerSupplyKit_test_overcurrent.jpg?raw=true)


## Final Comments

This is a nice kit and a fun build, but a couple of draw-backs:

* the voltage output is only as accurate as your meter, and fine adjustment is tricky. I've seen build variations that include course and fine voltage adjustments; this would be a good variation on the build (two pots or large and small resistance in series would work fine)
* the current-limiting feature works well, but suffers from the fact that there is no feedback on what the setting is (without tripping it to test.
* the fan is a very noisy heat-management solution - my own fault for selecting the fan I did. I would be interested in seeing how much power the unit could handle with heatsink alone.


All in all, a good general purpose power supply for the bench, especially where voltage/current limits do not have to be extremely precise.
I think I still prefer my DPS-3005-based power supply as a more accurate and featured solution - see [LEAP#407 DPS3005BenchPowerSupply](../DPS3005BenchPowerSupply) for more on that project.

## Credits and References
* [0-30V 2mA-3A Adjustable DC Regulated Power Supply DIY Kit Short Circuit Current Limiting Protection For School Education Lab](https://www.aliexpress.com/item/1Set-Red-0-30V-2mA-3A-Continuously-Adjustable-DC-Regulated-Power-Supply-DIY-Kit-For-School/32789006670.html)
* [same/similar kit from banggood](https://sea.banggood.com/0-30V-2mA-3A-Adjustable-DC-Regulated-Power-Supply-DIY-Kit-p-958308.html)
* original (?) design from [SmartKit](https://www.smartkit.gr/stabilised-power-supply-0-30v-3a-m.html)
* [example pre-cursor design](http://www.electronics-lab.com/project/0-30-vdc-stabilized-power-supply-with-current-control-0-002-3-a/) - electronics-lab
* [LEAP#289 VoltmeterAmmeterModule](https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/VoltmeterAmmeterModule)
* [LEAP#407 DPS3005BenchPowerSupply](../DPS3005BenchPowerSupply)
* [D882 datasheet](https://www.st.com/resource/en/datasheet/2sd882.pdf)
* [D1047 datasheet](https://www.st.com/resource/en/datasheet/2sd1047.pdf)
* [..as mentioned on my blog](https://blog.tardate.com/2018/11/leap433-0-30v-3a-adjustable-power-supply-kit.html)
