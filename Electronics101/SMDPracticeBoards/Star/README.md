# #597 Glowing Star SMD Practice Board

Testing the Five-Pointed Star SMD Practice Board with LM358 oscillator LED effects.

![Build](./assets/Star_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/k2FOthK3eTM/0.jpg)](https://www.youtube.com/watch?v=k2FOthK3eTM)

## Notes

I've seen this
[Five-Pointed Star Breathing Light DIY Kit](https://www.aliexpress.com/item/1005002131149229.html)
around for some time, and finalled shelled out a $1 or so to try one out.

It's maybe a change from the typical 4017+555 circuits used in these SMD soldering kits!

It is quite a nice little practice board for SMD soldering - or perhaps you are just after a twinkling star!

## Kit

Parts:

| Item        | Ref     | Qty |
|-------------|---------|-----|
| 22Ω         | R5      | 1   |
| 33kΩ        | R6      | 1   |
| 47kΩ        | R1,2,4  | 3   |
| 100kΩ       | R3      | 1   |
| 47µF        | C1      | 1   |
| LM358       | U1      | 1   |
| 8050-J3Y    | Q1      | 1   |
| 0805 LED    | LED1-20 | 20  |
| power wires |         | 2   |
| PCB         |         | 1   |

![kit_parts](./assets/kit_parts.jpg?raw=true)

![kit_pcb](./assets/kit_pcb.jpg?raw=true)

## Circuit

The circuit is a simple OpAmp triangle-wave oscillator using a high-side NPN transistor to drive the LED array.

![bb](./assets/Star_bb.jpg?raw=true)

![schematic](./assets/Star_schematic.jpg?raw=true)

![bb_build](./assets/Star_bb_build.jpg?raw=true)

The Q1 base voltage over time - showing the triangle wave:

![scope](./assets/scope.gif?raw=true)

## Construction

Haven't done any hot air work for a while. Thought I'd do that rather than hand-solder. All good...

![build_front](./assets/build_front.jpg?raw=true)
![build_rear](./assets/build_rear.jpg?raw=true)

## Credits and References

* [Students training DIY Kit Five-Pointed Star Breathing Light Gradient LED Light for Christmas Soldering Training Red Green Blue](https://www.aliexpress.com/item/1005002131149229.html) - aliexpress seller
* [LM358N Datasheet](https://www.futurlec.com/Linear/LM358N.shtml)
