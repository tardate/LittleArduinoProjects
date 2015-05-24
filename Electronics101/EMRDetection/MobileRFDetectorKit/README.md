# MobileRFDetectorKit (WIP)

Build and investigate a commercially available "mobile phone signal" detector kit

## Notes

I picked up a ["Mobile Phone Signal Flash Light Radiation Power DIY Kit"](http://www.aliexpress.com/item/Mobile-Phone-Signal-Flash-Light-Radiation-Power-DIY-New-Kit-Components/32298290064.html) for USD1.15. Firstly to experiment with the kit/circuit, and secondly as its a pretty cheap way to get hold of a 1SS86 barrier diode.

### First Test - breadboard build

The circuit is supposed to be tuned for detecting mobile phone [GSM](http://en.wikipedia.org/wiki/GSM) signals - not CDMA or other -
but that itself is a [pretty big bag of frequencies](http://en.wikipedia.org/wiki/GSM_frequency_bands).

Putting the circuit on a breadboard will I expect affect it's behaviour, as I guess the breadboard rails act either as shield or antenna.

The breadboard build yields curious results:
* with antenna attached, the circuit is permanently "on"
* with no antenna, it detects a bunch of things:
  - flourescent light radiation
  - proximity to wires
  - hands and body parts!
* what it can't detect is a mobile phone signal;-)
  - perhaps because I think the phone is on [HSPA+ over WCDMA](http://en.wikipedia.org/wiki/Evolved_HSPA)


![The Build](./assets/MobileRFDetectorKit_breadboard.jpg?raw=true)



### Construction

![The Breadboard](./assets/MobileRFDetectorKit_bb.jpg?raw=true)

![The Schematic](./assets/MobileRFDetectorKit_schematic.jpg?raw=true)

![The Build](./assets/MobileRFDetectorKit_build.jpg?raw=true)

### Parts

| Qty | Description                   |
|-----|-------------------------------|
|   1 | PCB board                     |
|   1 | solid core wire ("Scrap Tin") |
|   1 | 0.35mm cable                  |
|   1 | 1SS86 detector diode          |
|   3 | S8050 transistor              |
|   1 | 5mm white green led           |
|   2 | 1MΩ resistor                  |
|   2 | 10kΩ resistor                 |
|   1 | 470kΩ resistor                |
|   1 | 220Ω resistor                 |
|   2 | 10nF 103 ceramic capacitor    |


## Credits and references
* [Mobile Phone Signal Flash Light Radiation Power DIY New Kit Components](http://www.aliexpress.com/item/Mobile-Phone-Signal-Flash-Light-Radiation-Power-DIY-New-Kit-Components/32298290064.html)
* [1SS86 Datasheet](http://www.datasheetwiki.com/entry/1SS86-Datasheet-PDF)
* [S8050 Datasheet](http://electronics.se-ed.com/magic/s8050.pdf) - NPN BJT, note there are other S8050 transistor datasheets on the web that purport to be PNP
* [GSM wikipedia](http://en.wikipedia.org/wiki/GSM) - Global System for Mobile Communications
