# #434 krell

Building the Boldport Krell - a handheld DSP synthesiser built around a Microchip dsPIC and a design from madlab.

![Build](./assets/krell_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/FdNBNDGJCys/0.jpg)](https://www.youtube.com/watch?v=FdNBNDGJCys)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

Krell is a handheld DSP synthesiser. Buttons and potentiometers dial up a range of sounds.
The Boldport project is a remix of a soldering project by James Hutchby of MadLab.

At the core of the circuit is a [Microchip dsPIC33EP128MC202-I/SP](https://www.microchip.com/wwwproducts/en/dsPIC33EP128MC202).
It's an interesting choice - a digital signal controller that is really designed for precision motor control,
now put in service of creating music (or at least weird sounds).


## Kit

| Qty | Description                                               |
|-----|-----------------------------------------------------------|
| x1  | dsPIC microntroller, Microchip dsPIC33EP128MC202-I/SP     |
| x1  | 3.3V Regulator, TI LP2950-33LPRE3                         |
| x1  | NPN bipolar transistor, ON BC547CTFR                      |
| x1  | 220μF electrolytic capacitor, Multicomp MCUMR6V3227M6.3X5 |
| x2  | 10μF electrolytic capacitor, Multicomp MCUMR16V106M4X5    |
| x1  | 10μF tantalum capacitor, Suntan TS19001C100MSB0A0R        |
| x3  | 100nF capacitor, Suntan TS170R1H104MSBFB0R                |
| x6  | 47KΩ trimmer, Piher PT10MV10473A2020-I-PM-S               |
| x6  | Black thumbwheel, Piher 5034                              |
| x4  | White LED, Valcon VDIFFLED-3mm-W                          |
| x2  | 100Ω resistor, Multicomp MCF 0.25W 100R                   |
| x1  | 1KΩ resistor, Multicomp MCF 0.25W 1K                      |
| x6  | 10KΩ resistor, Multicomp MCF 0.25W 10K                    |
| x1  | Battery holder, TruPower BH 431-1P                        |
| x1  | 3.5mm stereo jack socket, TruConnect 20-0137              |
| x1  | 28-pin DIP socket, TruConnect 22-0114                     |
| x1  | DPDT slide switch, C&K JS202011SCQN                       |
| x1  | Button sheet, Snaptron Peel-N-Place™                      |
| x1  | PCB                                                       |


![kit_parts](./assets/kit_parts.jpg?raw=true)
![kit_pcb_back](./assets/kit_pcb_back.jpg?raw=true)
![kit_pcb_front](./assets/kit_pcb_front.jpg?raw=true)

## Circuit

My quick re-draw of the circuit..

![Schematic](./assets/krell_schematic.jpg?raw=true)

## Construction

It's a nice simple build this time for just an iron and my favourite 2% Ag solder.

The Snaptron buttons are an interesting construction variation: they come preset with clear adhesive strip.
With careful alignment, all buttons stick in place with no soldering required.
I can see this being super efficient for small batch assembly.

![build_01_back](./assets/build_01_back.jpg?raw=true)

![build_02_front](./assets/build_02_front.jpg?raw=true)

![build_03_with_battery](./assets/build_03_with_battery.jpg?raw=true)

The finished noise maker..

![Build](./assets/krell_build.jpg?raw=true)

## Credits and References
* [Krell](http://boldport.com/krell) - product page
* [Krell](https://www.boldport.club/shop/product/1736879828) - Boldport store
* [Krell source code](https://github.com/clubmadlab/Krell)
* [dsPIC33EP128MC202 product info](https://www.microchip.com/wwwproducts/en/dsPIC33EP128MC202)
* [..as mentioned on my blog](https://blog.tardate.com/2018/11/leap434-boldport-krell.html)
