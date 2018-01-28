# #360 TL431 Shunt Regulator

Testing a TL431 voltage reference (regulator) circuit with manual coarse and fine trim.

![Build](./assets/ShuntRegulator_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The TL431 Precision Programmable Reference is a cheap and easily adjustable shunt regulator.
The standard grade offers a reasonable 2% reference voltage tolerance.

In this mini-circuit I am testing the common application as a shunt regulator/reference voltage e.g. for use in power supplies.
This just requires a voltage divider (R1, R2) across Vref (2.5V). The output voltage will then be:

```
Vout = (1 + R1/R2) * Vref
```

For adjustment, I'm using two variable pots to provide course and fine grained control:

| R1 Range   | R2 Trim Range |
|------------|---------------|
| Min: 0Ω    | 105kΩ - 110kΩ |
| Max: 100kΩ | 5kΩ - 10kΩ    |


## Construction

See the [schematic in EasyEDA](https://easyeda.com/tardate/TL431ShuntRegulator-b6752f91b5504d789d9fae42ff297b5a).

![Schematic](./assets/ShuntRegulator_schematic.png?raw=true)

First testing on a breadboard:

![Breadboard](./assets/ShuntRegulator_bb.jpg?raw=true)

I put the circuit on some protoboard to improve the stability:

![protoboard_layout](./assets/protoboard_layout.jpg?raw=true)

![protoboard_build](./assets/protoboard_build.jpg?raw=true)


Under test. Set to 4.00V, remains stable as long as input voltage is > Vout.

![Build](./assets/ShuntRegulator_build.jpg?raw=true)

Here's a very unexciting demonstration of a quick test:

[![LISIbO5tJvY](http://img.youtube.com/vi/LISIbO5tJvY/0.jpg)](http://www.youtube.com/watch?v=LISIbO5tJvY)

## Credits and References
* [TL431 datasheet](http://www.ti.com/lit/ds/symlink/tl431a.pdf)
* [..as mentioned on my blog](https://blog.tardate.com/2017/12/leap360-tl431-shunt-regulator.html)
