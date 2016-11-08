# #263 ligemdio

An LED tester kit featuring a classic BJT constant current source. From The Boldport Club (Project #8).

![Build](./assets/ligemdio_build.jpg?raw=true)

## Notes

Another beautiful board from the Boldport Club.

The embossed patterns are truly marvelous (made with copper trace designs I think).

So does the world need another LED tester? Probably not, but this is certainly better than the
ad-hoc breadboard test circuits I tend to reach for whenever working on a project with a significant number of LEDs.

Whether the pack of LEDs says "QC tested" or not, I've learned to expect a non-zero failure rate.
I gather LEDs can degrade in storage too (esp in high humidity).
So rather than find a dud in the middle of a LED cube...no regrets if you test;-)

And if you are going to test, then gazing at the intricate designs of the ligemdio makes the time
pass just that much faster!

### How It Works

The dual-BJT circuit is a classic constant current source. Essentially:

* Given Vbe is fairly "stiff" (at around 0.6V for the PN2222ATA)..
* So there is a constant voltage across R1 of ~0.6V
* Therefore current thru R1 of [18.2mA](http://www.wolframalpha.com/input/?i=0.6V%2F33%CE%A9)
* Assuming negligible base current (Ib) current for T2,
* And assuming R2 and supply voltage are sufficient to saturate T2,
* Then the current through the load (LED DUT) is also ~18.2mA

This holds to a degree, however Vbe is subject to temperature fluctuations and can also vary significanty with collector current.

But what this circuit does buy is constant current independant of the supply voltage.

This circuit is actually the inverse (NPN) version of the (PNP) voltage-independant current source
discussed in 2.06/p75 of the Art of Electronics (second edition).

## Parts Checklist

| Item                                                   | Qty | Ref |
|--------------------------------------------------------|-----|-----|
| 33Ω through-hole resistor, Multicomp MF25 33R          |  x1 | R1  |
| 1KΩ through-hole resistor, Multicomp MF25 1K           |  x2 | R2, R5 |
| USB connector, Multicomp MC32603                       |  x1 | J2    |
| Orange LED, Kingbright L-9294SECK                      |  x1 | LED3 |
| NPN BJT, Fairchild PN2222ATA                           |  x2 | T1, T2 |
| 3.3µF electrolytic capacitor, Multicomp MCMR50V335M4X7 |  x1 | C1 |

## Construction

Unboxed..

![kit_parts](./assets/kit_parts.jpg?raw=true)

Once again, a beautiful PCB. The embossed designs are amazing..

![kit_pcb_top](./assets/kit_pcb_top.jpg?raw=true)

![kit_pcb_bottom](./assets/kit_pcb_bottom.jpg?raw=true)

Let's not forget the circuit..

![Breadboard](./assets/ligemdio_bb.jpg?raw=true)

![Schematic](./assets/ligemdio_schematic.jpg?raw=true)

Somewhat OK solder job. Top:

![ligemdio_build_top](./assets/ligemdio_build_top.jpg?raw=true)

Bottom:

![ligemdio_build_bottom](./assets/ligemdio_build_bottom.jpg?raw=true)

Completed build, testing an SMD LED...

![ligemdio_testing_smd_led](./assets/ligemdio_testing_smd_led.jpg?raw=true)

More testing. 999 to go ;-)

![999_to_go](./assets/999_to_go.jpg?raw=true)

## Credits and References
* [LIGEMDIO infographic](https://github.com/boldport/ligemdio/blob/master/docs/infographic.pdf)
* [LIGEMDIO](http://www.boldport.club/shop/product/480066844) - in the Boldport shop
* [LIGEMDIO](http://www.boldport.com/products/ligemdio) - project page
* [LIGEMDIO](https://github.com/boldport/ligemdio) - OSH files on GitHub
* [PN2222ATA datasheet](http://parts.io/detail/1027929/PN2222ATA)
* [The Art of Electronics](https://www.goodreads.com/book/show/569775.The_Art_of_Electronics)
