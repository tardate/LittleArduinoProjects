# #165 Power2662Inverter

Test a negative 5V power supply using the LM2662 Switched Capacitor Voltage Converter


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The LM2662 is a single-chip CMOS charge pump voltage converter:
* 1.5V to 5.5V positive voltage input
* up to 200 mA of output current
* operating efficiency greater than 90% at most loads

There are three basic application topologies:
* voltage inverter (Vout = - Vin)
* voltage divider (Vout = 1/2 Vin)
* voltage doubler (Vout = 2 Vin)

This circuit is a basic test of the voltage inverter configuration, with a few simplifications:
* 5V regulated input voltage
* frequency control is left open, so operates at 20kHz (as opposed to 150kHz)
* I'm using 47µF electrolytic capacitors since they are what I have on hand. The datasheet recommends low-ESR ceramic or tantalum for better performance.

I have some LM2662MX chips in SOP-8 packaging, so I mounted one on an adapter module for easy breadboarding.

The circuit includes a simple LED/resistor fixed load.

### Some Measurements

| Item | Value  | Notes                                       |
|------|--------|---------------------------------------------|
| Vin  |  4.97V | from LM7805 regulator powered by 9V battery |
| Vout | -4.96V | with no load                                |
| Vout | -4.83V | with LED/resistor load                      |


Here's Vin (CH1) and Vout (CH2) DC-coupled on a scope, with load attached:

![vin vout](./assets/scope_vin_vout.gif?raw=true)

Zooming in on Vout (CH1) AC-coupled to see the ripple:

![vout ripple](./assets/scope_vout_ripple.gif?raw=true)

I'm seeing 200-400mV dropouts every few seconds as captured above. I'm not sure of the source or if that is particularly normal.
The electrolytic capacitors may play a role, so I might measure that again if/when I can get my hands on some
sufficiently large low-ESR ceramic capacitors.

As it is, it seems the inverted voltage output would need further filtering/smoothing and perhaps regulation
for applications requiring a good clean negative voltage supply.

## Construction

NB: Fritzing diagrams use the [LM2662 Switched Capacitor Voltage Converter - DIP8 module](../../FritzingParts/LM2662) custom part

![Breadboard](./assets/Power2662Inverter_bb.jpg?raw=true)

![The Schematic](./assets/Power2662Inverter_schematic.jpg?raw=true)

![The Build](./assets/Power2662Inverter_build.jpg?raw=true)

## Credits and References
* [LM2662M datasheet](http://www.futurlec.com/Linear/LM2662M.shtml)
* [LM7805 datasheet](http://www.futurlec.com/Linear/7805T.shtml)
* [SO16 SSOP16 TSSOP16 SOIC16 To DIP Adapter PCB Board Converter](http://www.aliexpress.com/item/20-Pcs-SO16-SSOP16-TSSOP16-SOIC16-To-DIP-Adapter-PCB-Board-Converter/32436820541.html) - modules I used from an aliexpres seller to mount the SOP-8 chip
* [LM2662 Switched Capacitor Voltage Converter - DIP8 module](../../FritzingParts/LM2662) custom part
