# #400 USB Protector

Building the Silicon Chip USB Protector which demonstrates various methods of reverse-polarity, over-voltage and over-current protection.

![Build](./assets/USBProtector_build.jpg?raw=true)

## Notes

I picked up the Silicon Chip USB Protector not so much because of need, but because it is an interesting study
in a range of over-voltage and over-current protection mechanisms.

The project is written up in Silicon Chip May 2018 (p57), with the [kit and supporting materials available online](http://www.siliconchip.com.au/Shop/20/4574).

I just saw [μArt](https://www.crowdsupply.com/pylo/muart) on crowdsupply, which is an interesting
project with similar protection mechanism but intended for UART applications.

[ARRL Hands-on Radio (Vol 2)](../../books/arrl-hands-on-radio-experiments-vol2/) also has good coverage of these topics. See:

* [Experiment 120: Power Polarity Protection](http://www.arrl.org/files/file/protected/Group/Members/ProductReview/Hands%20On%20Radio%20January%202013.pdf)
* [Experiment 121: Transient Protection](http://www.arrl.org/files/file/protected/Group/Members/ProductReview/Hands%20On%20Radio%20February%202013.pdf)

## Circuit Description

I made a quick [transcription of the circuit in EasyEDA](https://easyeda.com/tardate/usb-protector) for the purpose of getting a little more
intimate with the circuit.

![Schematic](./assets/USBProtector_schematic.png?raw=true)

At it's core, the circuit is a pass-through of the USB power, ground and two data lines (D+, D-).
It then adds the following protection mechanisms:

| Component(s) | Protects             | Description                                                                                                       |
|--------------|----------------------|-------------------------------------------------------------------------------------------------------------------|
| PTC1         | Vcc over-current     | Resettable, handling moderate over-current without needing replacement                                             |
| Fuse         | Vcc over-current     | Reacts faster to very high currents than PTC                                                                      |
| D3           | Vcc reverse polarity | Limits Vcc to -0.55V. Protects PC-side from peripheral-side reverse voltage which should cause PTC or fuse to trip |
| Q1, REF1     | Vcc clamp            | Active protection from  over-voltage that may not trigger over-current. Reaction time relative slow               |
| TVS1         | Vcc clamp            | Passive over-voltage protection that is also fast-acting                                                          |
| D1,D2        | D+/D- clamp          | Over-voltage and reverse-voltage clamping for data lines                                                          |
| TVS1         | D+/D- clamp          | Transient voltage suppressor for data lines                                                                        |

The circuit includes two LED indicators:

* LED1 is simple power indicator, always on when Vcc powered
* LED2 turns on proportionally to the degree of voltage clamping being applied

## Construction

The kit primarily uses SMD components, but reasonably large packages and not too cramped so I decided to hand-solder rather than bust out the hot air.
the parts are conveniently provided taped up and labeled on a sheet or paper:

![kit_parts](./assets/kit_parts.jpg?raw=true)

The PCB had one error in the silk-screen. The lower component marked "10k" is in fact the 47kΩ resistor between Q1 and Q2.

![pcb_front](./assets/pcb_front.jpg?raw=true)
![pcb_rear](./assets/pcb_rear.jpg?raw=true)

Recommended construction order:

* top-side components:
    * Q1
    * TVS1, next to Q1
    * SMD passive components
    * REF1 and Q2
    * LEDs
    * D3
* bottom-side components:
    * D1, D2
    * TVS2
    * F1
* USB plug and socket

![USBProtector_build_front](./assets/USBProtector_build_front.jpg?raw=true)

![USBProtector_build_rear](./assets/USBProtector_build_rear.jpg?raw=true)

![Build](./assets/USBProtector_build.jpg?raw=true)

## Credits and References

* [Complete kit for the USB Port Protector](http://www.siliconchip.com.au/Shop/20/4574) - written up in Silicon Chip May 2018 p57
* [μArt](https://www.crowdsupply.com/pylo/muart) - a similar protection project but intended for UART applications, available on crowdsupply
* [SK153 DIODE SCHOTTKY 30V 15A](https://www.digikey.sg/product-detail/en/micro-commercial-co/SK153-TP/SK153-TPCT-ND/1306216)
* [CDSOD323-T05S TVS DIODE 5V 13.5V](https://www.digikey.sg/product-detail/en/bourns-inc/CDSOD323-T05S/CDSOD323-T05SCT-ND/5774994)
* [AN431AN Shunt Voltage Reference](https://www.digikey.sg/product-detail/en/diodes-incorporated/AN431AN-ATRG1/AN431AN-ATRG1DICT-ND/4505253)
* [ECH8102-TL Bipolar (BJT) Transistor PNP](https://www.digikey.sg/product-detail/en/on-semiconductor/ECH8102-TL-H/ECH8102-TL-HOSCT-ND/5801800) - high-current
* [SM2T3V3A TVS diode](https://www.digikey.sg/product-detail/en/stmicroelectronics/SM2T3V3A/497-7878-1-ND/1883813)
* [BAT54S SCHOTTKY DIODE ARRAY](https://www.digikey.sg/product-detail/en/on-semiconductor/BAT54S/BAT54SFSCT-ND/458930)
* [ARRL Hands-on Radio (Vol 2)](../../books/arrl-hands-on-radio-experiments-vol2/)
* [ARRL Hands-on Radio (Vol 2) Experiment 120: Power Polarity Protection](http://www.arrl.org/files/file/protected/Group/Members/ProductReview/Hands%20On%20Radio%20January%202013.pdf)
* [ARRL Hands-on Radio (Vol 2) Experiment 121: Transient Protection](http://www.arrl.org/files/file/protected/Group/Members/ProductReview/Hands%20On%20Radio%20February%202013.pdf)
