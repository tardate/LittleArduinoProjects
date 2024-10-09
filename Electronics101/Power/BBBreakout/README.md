# #407 Power/BBBreakout

A little breadboard power adapter and breakout with 5.5x2.1mm barrel jack, terminal block and XH2.54 connectors.

![Build](./assets/BBBreakout_build.jpg?raw=true)

## Notes

Just a simple little project to clean up my desk a little, where I often have various power adapters and connectors cluttering up my space.
This is an adapter that can plug into the power rails of a breadboard, and provides:

* LED power indicator
* pins to plug into a breadboard power rail
* [5.5x2.1mm centre-positive barrel jack](https://www.aliexpress.com/item/10PCS-5-5x2-1mm-Electrical-Socket-Outlet-DC-005-DC-Outlet-5000-Times-Black/32265586514.html)
* [2-pin terminal block](https://www.aliexpress.com/item/Free-Shipping-20pcs-2-Pin-Screw-Terminal-Block-Connector-5mm-Pitch-B/663929906.html)
* [XH2.54-2P connector](https://www.aliexpress.com/store/product/5OPCS-XH2-54-2P-2-54mm-2A-Pitch-White-Tower-Connector-Straight-Needle-Seat-XH2-54/1246743_32787163509.html)

While I'm normally powering this from the barrel jack, it can actually be used to route power in with any of the connectors and out all the others.

The connectors and LED, with current limiting resistor good for [up to 24V conservatively](https://www.wolframalpha.com/input/?i=2.2k%CE%A9*10mA+%2B+2.0V),
are mounted on a small piece of protoboard, roughly laid out like this:

![BBBreakout_layout](./assets/BBBreakout_layout.jpg?raw=true)

![Breadboard](./assets/BBBreakout_bb.jpg?raw=true)

![Schematic](./assets/BBBreakout_schematic.jpg?raw=true)

The end result:

![Build](./assets/BBBreakout_build.jpg?raw=true)

## Credits and References

* [5.5x2.1mm centre-positive barrel jack](https://www.aliexpress.com/item/10PCS-5-5x2-1mm-Electrical-Socket-Outlet-DC-005-DC-Outlet-5000-Times-Black/32265586514.html)
* [2-pin terminal block](https://www.aliexpress.com/item/Free-Shipping-20pcs-2-Pin-Screw-Terminal-Block-Connector-5mm-Pitch-B/663929906.html)
* [XH2.54-2P connector](https://www.aliexpress.com/store/product/5OPCS-XH2-54-2P-2-54mm-2A-Pitch-White-Tower-Connector-Straight-Needle-Seat-XH2-54/1246743_32787163509.html)
