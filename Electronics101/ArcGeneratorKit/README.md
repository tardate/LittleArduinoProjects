# #451 Arc Generator Kit

Playing with a high-voltage arc generator kit that uses step-up transformer with a simple feedback control of a D882 power transistor.

![Build](./assets/ArcGeneratorKit_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/ad8vV-S-dqo/0.jpg)](https://www.youtube.com/watch?v=ad8vV-S-dqo)

## Notes

This is a version of a very common High Voltage Arc Kit.
It is basically a step-up transformer with a simple feedback control of a D882 power transistor.
It is actually a demonstration of the same circuit used on "plasma lighters".

Specifications

* Input Voltage: 3.7-4.2V
* Input Current: <= 2A
* Output Voltage: <= 15kV
* Output Current: <= 0.4A
* High Voltage Polarization Ignition Distance: <= 0.5cm

## The Basic Circuit

I redrew the basic schematic [here in EasyEDA](https://easyeda.com/tardate/ArcGeneratorKit).

![Schematic](./assets/ArcGeneratorKit_schematic.png?raw=true)

bigclivedotcom did a tear-down of a commercial "plasma lighter" and no surprise, it uses the same circuit as demonstrated with this kit.

[![clip](https://img.youtube.com/vi/4aK1GK1KBGc/0.jpg)](https://www.youtube.com/watch?v=4aK1GK1KBGc)

## Parts

This is a simple circuit with few parts - most of the magic happens in the transformer windings.

Interestingly, the kit I purchased contained two of each transistor, diode and resistor.
Have they learned that people who buy HV arcs are more than likely to smoke at least one part?!!

| Item                  | Qty | Notes |
|-----------------------|-----|-------|
| 15KVE-1 Step-Up Coil  | 1   | 3 windings |
| 470Ω resistor         | 1   | 2 x 470Ω supplied. Other versions of this kit use 120Ω or 200Ω |
| FR107 Diode           | 1   | 2 supplied |
| NPN Power Transistor  | 1   | 2 supplied. Unmarked, but appears to be D882 |
| Insulated Wire        | 2   | for power connector |
| Heatsink              | 1   | for transistor, with mounting nut & bolt (nut is not actually required as the heatsink has tapped mounting hole) |
| heatshrink tubing     | 3cm | presumably to insulate connections if built ugly style |

Many of the kits currently available seem to have been upgraded slightly, to include a switch and PCB.

![kit_parts](./assets/kit_parts.jpg?raw=true)

### Step-up Transformer Details

| Winding       | Inductance | Note |
|---------------|------------|------|
| Primary       | 17µH       | thicker magnet wire |
| Feedback      | 27µH       | thinner magnet wire |
| Arc/secondary | 1.5H       | mounted opposite the primary and feedback windings |

The primary and feedback windings come with the ends to be connected to the positive power supply already wound together.
This hopefully ensures correct connections!

## Construction

I used a 5cm x 7cm piece of single-sided protoboard to mount the kit, adding:

* push-button switch
* 5.5 x 2.1mm barrel jack for power supply

![kit_build](./assets/kit_build.jpg?raw=true)

## Performance

Works just fine. With a supply of 5V, it draws around 1.6A during arc.

![ArcGeneratorKit_test](./assets/ArcGeneratorKit_test.jpg?raw=true)

## Credits and References

* ["15KV High Frequency DC High Voltage Arc Ignition Generator Inverter Boost Step Up 18650 DIY Kit U Core Transformer Suite 3.7V"](https://www.aliexpress.com/item/15KV-High-Frequency-DC-High-Voltage-Arc-Ignition-Generator-Inverter-Boost-Step-Up-18650-DIY-Kit/32864946448.html) - similar kit (but also includes PCB)
* [D882 datasheet](https://www.st.com/resource/en/datasheet/2sd882.pdf)
* [..as mentioned on my blog](https://blog.tardate.com/2019/02/leap451-arc-lighter.html)
