# #358 MC34063 Boost Converter Kit

Build and test an MC34063-based boost converter kit.

![Build](./assets/ModuleKit_build.jpg?raw=true)

## Notes

The MC34063 is a monolithic DC-to-DC switching controller that can be adapted to step-down, step-up and inverting applications with a minimum of external components.

I purchased the
["Power module boost module 5V lift 12V l/c MC34063 module DIY electronic production kit IC" (aliexpress seller listing)](https://www.aliexpress.com/item/32830584255.html) for US$0.88 (Nov-2017).

The module is a very cheap kit designed by ICStation [ICSK034A](http://www.icstation.com/icstation-step-module-boost-converter-power-supply-module-p-4151.html)
but now available from many sellers on aliexpress, ebay etc.

It has a fixed configuration to boost 5V in to 12V out.

### Parts

| Ref  | Item                         | Qty |
|------|------------------------------|-----|
| U1   | MC34063AP1                   |   1 |
| C1   | electrolytic capacitor 47µF  |   1 |
| C2   | ceramic capacitor 104, 100nF |   1 |
| C3   | ceramic capacitor 101, 100pF |   1 |
| C4   | ceramic capacitor 104, 100nF |   1 |
| D1   | 1N5819                       |   1 |
| D2   | Red LED                      |   1 |
| J1,2 | terminal block               |   2 |

![kit_parts](./assets/kit_parts.jpg?raw=true)

![pcb_front](./assets/pcb_front.jpg?raw=true)

![pcb_rear](./assets/pcb_rear.jpg?raw=true)

## Construction

![Breadboard](./assets/ModuleKit_bb.jpg?raw=true)

![Schematic](./assets/ModuleKit_schematic.jpg?raw=true)

![Build](./assets/ModuleKit_build.jpg?raw=true)

Under test, it is delivering 11.52V (no load):

![ModuleKit_test](./assets/ModuleKit_test.jpg?raw=true)

## Credits and References

* [MC34063 datasheet](https://www.futurlec.com/Motorola/MC34063.shtml)
* ["Power module boost module 5V lift 12V l/c MC34063 module DIY electronic production kit IC" (aliexpress seller listing)](https://www.aliexpress.com/item/32830584255.html)
    * Originally purchased for US$0.88 (Nov-2017), no longer available from this seller
* ["Power Step Up Module 5V + 12V step-up Board MC34063 Module DIY Electronic Production Kit Converter" (aliexpress seller listing)](https://www.aliexpress.com/item/32811195648.html)
    * another seller, currently listing for SG$1.14 (Jan-2026)
* [ICSK034A](http://www.icstation.com/icstation-step-module-boost-converter-power-supply-module-p-4151.html) - icstation, original source?
* [..as mentioned on my blog](https://blog.tardate.com/2017/12/leap358-mc34063-boost-converter-kit.html)
