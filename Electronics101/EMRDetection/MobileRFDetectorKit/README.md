# MobileRFDetectorKit

Build and investigate a commercially available "mobile phone signal" detector kit

## Notes

I picked up a ["Mobile Phone Signal Flash Light Radiation Power DIY Kit"](http://www.aliexpress.com/item/Mobile-Phone-Signal-Flash-Light-Radiation-Power-DIY-New-Kit-Components/32298290064.html) for USD1.15. Firstly to experiment with the kit/circuit, and secondly as its a pretty cheap way to get hold of a 1SS86 barrier diode.

### First Test - Breadboard Build

The circuit is supposed to be tuned for detecting mobile phone [GSM](http://en.wikipedia.org/wiki/GSM) signals - not CDMA or other -
but that itself is a [pretty big bag of frequencies](http://en.wikipedia.org/wiki/GSM_frequency_bands).

Putting the circuit on a breadboard will I expect affect it's behaviour, as I guess the breadboard rails act either as shield or antenna.

![The Build](./assets/MobileRFDetectorKit_breadboard.jpg?raw=true)

The breadboard build yields interesting (unexpected?) results:
* with antenna attached, the circuit is permanently "on"
* with no antenna, it detects a bunch of things:
  - flourescent light radiation
  - proximity to wires
  - hands and body parts!
* what it can't detect is a mobile phone signal;-)

In fact, it turns out to be a brilliant body-part detector. Arranged just so, it's possible to control the LED from a foot or so away
by angling your arms and uttering all manner of gong fu incantations. Or try "Expecto patronum!"

I couldn't figure out exactly what is going on, but given some sensitivity to how I had the power leads arranged, I'm guessing it is something
like this: the body is resonating(?) with the EM radiation from the power supply (among other things). Basically acting as an antenna,
and then bending the field towards the detector circuit. Or maybe that's just gobbledigook.

An interesting effect anyway. Opens the possibility of some neat parlour tricks and 'magic'. Maybe I could charge people to measure their 'aura';-)

### The PCB build

![The Build](./assets/MobileRFDetectorKit_build.jpg?raw=true)

After assembling the PCB, but without any antenna attached, I can now detect a mobile phone signal reasonably well.
For example, if I place an outbound call with the PCB sitting near the phone.

The phone I'm testing is using [HSPA+ over WCDMA](http://en.wikipedia.org/wiki/Evolved_HSPA).

However if I attach virtually any length of antenna, it goes full on all the time. Either I'm in a very noisy environment, or the
sensitivity of this circuit is incorrectly calibrated. I might come back to this later to investigate further.

### Construction

![The Breadboard](./assets/MobileRFDetectorKit_bb.jpg?raw=true)

![The Schematic](./assets/MobileRFDetectorKit_schematic.jpg?raw=true)

![The Build](./assets/MobileRFDetectorKit_build.jpg?raw=true)

![The Build](./assets/MobileRFDetectorKit_pcb.jpg?raw=true)

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
