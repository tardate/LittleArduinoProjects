# #339 GuitarEffects/DelayKit

Build and test a PT2399-based delay pedal kit.

Here's a quick hit to demo the delay unit, with a clean guitar signal and all the effects settings (mix, repeat, delay) on "11"..

[![Build](./assets/DelayKit_build.jpg?raw=true)](http://www.youtube.com/watch?v=7I3Oxd9LHHg)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

I have been reading up on the PT2399 echo audio processor, and a good way of seeing one action
is to pick up one of the many delay effects pedals.

[The kit I obtained](https://www.aliexpress.com/item/NEW-DIY-electric-Guitar-Delay-analog-Effect-Pedals-Electric-pedal-guitarra-delay-Suite-Delay-1-pedals/32589004909.html)
is nicely put together with a pre-drilled and decorated 1590B enclosure, and some very nice knobs and smooth pots.

## Unboxing

![DelayKit_parts](./assets/DelayKit_parts.jpg?raw=true)

![DelayKit_instructions](./assets/DelayKit_instructions.jpg?raw=true)

![DelayKit_pcb_front](./assets/DelayKit_pcb_front.jpg?raw=true)

![DelayKit_pcb_rear](./assets/DelayKit_pcb_rear.jpg?raw=true)

## Assembly

Assembly was a breeze - the silkscreen on the PCB is clearly and completely marked,
and the assembly instructions provided had the details on correctly wiring all the connectors and pots.

The only variation was two ceramic capacitors that were provided at slightly different values than
printed on the PCB. The values must not be that critical as it works fine with the substitutions.

![DelayKit_assembly1](./assets/DelayKit_assembly1.jpg?raw=true)

It's a tight squeeze, but all packs into the enclosure nicely.
The PCB is the correct size so that the lip on the base of the case will prevent the board shorting on the case
(obviously care required to ensure there are no protruding wires or over-sized solder joints).

![DelayKit_assembly2](./assets/DelayKit_assembly2.jpg?raw=true)

Assembly complete. The kit even included some nice rubber feet to stick on the bottom.

![DelayKit_assembly3](./assets/DelayKit_assembly3.jpg?raw=true)

Note that as is common for effects pedals, the 9V jack is centre-negative.

![Build](./assets/DelayKit_build.jpg?raw=true)

## Schematic

I think this is a reasonable transcription of the circuit. The use of the PT2399 is very similar to the echo circuit including in the datasheet.

Although the signals in and out are analog, the PT2399 appears to operate by digitally sampling and remixing with ADC and DAC and 44kb of internal memory.

![Schematic](./assets/DelayKit_schematic.jpg?raw=true)

## Credits and References
* [DIY Electric Guitar Delay Analog Effect Pedal guitarra delay with 1590B High Quality footswitch Effect pedal kits](https://www.aliexpress.com/item/NEW-DIY-electric-Guitar-Delay-analog-Effect-Pedals-Electric-pedal-guitarra-delay-Suite-Delay-1-pedals/32589004909.html) - from a seller on aliexpress
* [PT2399 datasheet](http://www.futurlec.com/Others/PT2399.shtml)
* [TL072CP datasheet](http://www.futurlec.com/Linear/TL072CP.shtml)
* [78L05 datasheet](http://www.futurlec.com/Linear/78L05.shtml)
* [..as mentioned on my blog](http://blog.tardate.com/2017/08/leap339-pt2399-delay-kit.html)
