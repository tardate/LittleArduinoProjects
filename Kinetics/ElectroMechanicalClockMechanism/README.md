# #xxx Electro-mechanical Clock Mechanism

Examining a common crystal-disciplined quartz clock movement mechanism, figuring out how to tap a 1Hz timing signal.

![Build](./assets/ElectroMechanicalClockMechanism_build.jpg?raw=true)

## Notes

### Quartz Clock Movement

[DIY Wall Clock Quartz Movement Mechanism Black Red Removable Wall Clock Quartz Hour/Minute Hand Clock Movement](https://www.aliexpress.com/item/32687248673.html)

![kit1](./assets/kit1.jpg)

![kit2](./assets/kit2.jpg)

The "quartz" mechanism is encased on a potted PCB labelled "SY09".
The hidden circuitry divides the 32768Hz crystal by 4096 to produce an 8Hz pulse. The 8Hz pulse is used to energize the coil and spin the magnetised first drive gear.

![assembly-06](./assets/assembly-06.jpg)

The SY09 PCB decoded:

![assembly-board-01](./assets/assembly-board-01.jpg)

Measuring the scaled pulse that drives the coil on an oscilloscope:

![scope-8hz](./assets/scope-8hz.gif)

### Circuit Design

Now that I've identified the 8Hz signal produced by the SY09 board, let's have some fun and reduce it further to 1Hz with a CD4017 decade counter. An LED is attached on "0" output, and "8" wired to reset to convert the CD4017 into a divide-by-8 counter.

Why would I want to do this? Well, it may have something to do with the [2025 Hackaday One Hertz Challenge](https://hackaday.com/2025/06/26/announcing-the-2025-hackaday-one-hertz-challenge/)!

![bb](./assets/ElectroMechanicalClockMechanism_bb.jpg?raw=true)

![schematic](./assets/ElectroMechanicalClockMechanism_schematic.jpg?raw=true)

![bb_build](./assets/ElectroMechanicalClockMechanism_bb_build.jpg?raw=true)

Re-assembly with Power wires (red/black) and 8Hz clock signal (yellow) attached:

![custom-01](./assets/custom-01.jpg)

![bb_test](./assets/ElectroMechanicalClockMechanism_bb_test.jpg?raw=true)

Checking the result on an oscilloscope, we get a clean 1 Hz pulse:

![scope-1hz](./assets/scope-1hz.gif)

## Reduction Gear Assembly

This is mainly for my reference so I can re-assemble the gearing correctly!

![assembly-00](./assets/assembly-00.jpg)
![assembly-01](./assets/assembly-01.jpg)
![assembly-02](./assets/assembly-02.jpg)
![assembly-03](./assets/assembly-03.jpg)
![assembly-04](./assets/assembly-04.jpg)
![assembly-05](./assets/assembly-05.jpg)
![assembly-06](./assets/assembly-06.jpg)
![assembly-07](./assets/assembly-07.jpg)

## Credits and References

* [DIY Wall Clock Quartz Movement Mechanism Black Red Removable Wall Clock Quartz Hour/Minute Hand Clock Movement](https://www.aliexpress.com/item/32687248673.html) - similar clock movement mechanism from an aliexpress seller
* [CD4017 datasheet](https://www.futurlec.com/4000Series/CD4017.shtml)
