# #311 Juice

Building the Boldport Juice battery replacement kit (Project #12).

![Build](./assets/Juice_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

Juice is a battery replacement kit that uses a pretty nifty set of AA, AAA, A23 and CR2032 inserts
to inject the required regulated power where a battery or two would normally be required.

Power can be supplied via the micro USB connector, or any other power supply that can be clipped or screwed on to the body of the Juice.

All the structural parts punch out from the classy PCB like a model plane kit;-) The box folds up and doubles as a "Juice box".

![Juice_pcb_front](./assets/Juice_pcb_front.jpg?raw=true)

![Juice_pcb_rear](./assets/Juice_pcb_rear.jpg?raw=true)

![Juice_box](./assets/Juice_box.jpg?raw=true)

![Juice_box_closed](./assets/Juice_box_closed.jpg?raw=true)


### Regulating the Supply

The core of the kit is the ST LDF regulator, which has a very low-dropout voltage (500 mV max. at 1 A load).

Resistor networks and the "chooser" plug allow switching between 1.5, 3V, 4.5V or an adjustable output.

### Parts

| Ref  | Description                                               |  Qty |
|------|-----------------------------------------------------------|------|
| IC1  | Adjustable LDO regulator, ST LDFPT-TR                     |  1x  |
| VR1  | 20KΩ trimmer, Bourns TC33X-2-203E                         |  1x  |
| R1,3 | 1KΩ resistor, Multicomp MF25 1K                           |  2x  |
| R2   | 3.3KΩ resistor, Multicomp MF25 3K3                        |  1x  |
| R4   | 5.6KΩ resistor, Multicomp MF25 5K6                        |  1x  |
| R5,6 | 1.2KΩ resistor, Multicomp MF25 1K2                        |  2x  |
| C1,2 | 2.2µF ceramic capacitor, Multicomp MCMLR50V225MY5V        |  2x  |
| C3   | 10µF electrolytic capacitor, Multicomp MCMR35V106M4X7     |  1x  |
| LED1 | Orange LED, Kingbright L-9294SECK                         |  1x  |
|      | Micro USB connector, Multicomp MC001009                   |  1x  |
|      | 6 contacts long pin header, Samtec TSW-106-22-T-S         |  1x  |
|      | 3 contacts 2.54 mm SMD header, Samtec TSM-103-01-T-SH     |  1x  |

![Juice_parts](./assets/Juice_parts.jpg?raw=true)

## Construction

![Schematic](./assets/Juice_schematic.jpg?raw=true)

![Build](./assets/Juice_build.jpg?raw=true)

![Juice_build_front](./assets/Juice_build_front.jpg?raw=true)
![Juice_build_rear](./assets/Juice_build_rear.jpg?raw=true)

The SS Juice with CR2032 adapter:

![Juice_complete_cr2032](./assets/Juice_complete_cr2032.jpg?raw=true)

The SS Juice with A-series battery adapters.

![Juice_complete_a_series](./assets/Juice_complete_a_series.jpg?raw=true)

Note the jumper to allow multiple batteries to be replaced in series.
Here's the Juice replacing a 2xAA battery holder:

![Juice_2xAA_replacement](./assets/Juice_2xAA_replacement.jpg?raw=true)

## Credits and References
* [ST LDF info/datasheet](http://www.st.com/content/st_com/en/products/power-management/linear-voltage-regulators/low-dropout-ldo-linear-regulators/ldf.html)
* [Boldport Juice](https://www.boldport.com/products/juice) - official product page
* [..as mentioned on my blog](http://blog.tardate.com/2017/05/leap311-the-boldport-club-juice.html)
