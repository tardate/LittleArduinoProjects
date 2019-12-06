# #513 Simple USB Dummy Load

Examining and testing a simple USB resistive dummy load.

![Build](./assets/SimpleResistiveUsbLoad_build.jpg?raw=true)

## Notes

I've seen a few people on YouTube using a simple USB dummy load
for battery testing - like [this one from an aliexpress seller](https://www.aliexpress.com/item/32871955119.html).
I picked one up to take a closer look.

![module](./assets/module.jpg?raw=true)

These really are at the dumb end of the [dummy load](https://en.wikipedia.org/wiki/Dummy_load) spectrum. For example:

* no over temp control
* no over-discharge protection
* no voltage/current/power measurement

Probably a very bad idea to use these for battery discharge tests unless closely monitored.
But fine when a simple resistive load is needed for crude bench tests.
But if nothing else, a pretty cheap way of sourcing some nice retro 10W resistors!

## Construction

The circuit is pretty straight-forward - two 10W resistors that can be switched in separately or on parallel,
for three load settings, plus 'off' (both resistors switched out).

With a 5V USB supply, expected current and power loads are as follows:

| Resistance        | Current                                                                                           | Power |
|-------------------|---------------------------------------------------------------------------------------------------|-------|
| R1 (4.7Ω)         | [1.06A](https://www.wolframalpha.com/input/?i=5V%2F4.7%CE%A9)                                     | [5.32W](https://www.wolframalpha.com/input/?i=5V*5V%2F4.7%CE%A9) |
| R2 (2.2Ω)         | [2.27A](https://www.wolframalpha.com/input/?i=5V%2F2.2%CE%A9)                                     | [11.4W](https://www.wolframalpha.com/input/?i=5V*5V%2F2.2%CE%A9) |
| R1‖R2 (4.7Ω‖2.2Ω) | [3.34A](https://www.wolframalpha.com/input/?i=5V%2F%281%2F%281%2F2.2%CE%A9%2B1%2F4.7%CE%A9%29%29) | [16.7W](https://www.wolframalpha.com/input/?i=5V*5V%2F%281%2F%281%2F2.2%CE%A9%2B1%2F4.7%CE%A9%29%29) |

Three LEDs indicate the current operating state:

| LED  | Description                        |
|------|------------------------------------|
| LED1 | ON when 4.7Ω resistor load enabled |
| LED2 | ON when 2.2Ω resistor load enabled |
| LED3 | ON when USB power present          |

My quick re-drawing of the circuit:

![Breadboard](./assets/SimpleResistiveUsbLoad_bb.jpg?raw=true)

![Schematic](./assets/SimpleResistiveUsbLoad_schematic.jpg?raw=true)

Here's an example under test, with R1 (4.7Ω) switched inline. The current draw and power are close to expected i.e. the resistance value is in spec!

![Build](./assets/SimpleResistiveUsbLoad_build.jpg?raw=true)

## Credits and References

* [Resistor USB dc Electronic Load Adjustable Switch 3 Current 5V 1A/2A/3A Battery Capacity Discharge Voltage Tester Resistance Hot](https://www.aliexpress.com/item/32871955119.html) - aliexpress seller
* [Dummy load](https://en.wikipedia.org/wiki/Dummy_load) - wikipedia
