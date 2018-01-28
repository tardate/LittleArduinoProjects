# #329 Power Connectors

Obsessing over all manner of DC power connectors.

![Power_build](./assets/Power_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

How many types of power connector is there? In addition to just two bits of wire twisted together, it is pretty much an uncountable selection!

The [DC connector wikipedia](https://en.wikipedia.org/wiki/DC_connector) page gives a good run down of the main types:

* Cylindrical connectors (aka barrel, "2.1mm")
* Snap and lock DC power connectors (aka Kycon 3-pin, 4-pin)
* Molex connector
* IEC 60906-3:1994
* Outdoor light systems connectors
* Tamiya connectors
* JST RCY connector
* Inverter tabs/lugs
* Airline in-seat power supply system
* Anderson Powerpole connectors
* SAE connector
* Cigar lighter sockets and plugs
* ISO 4165 connector
* XLR connectors used for power
* Clipsal connectors
* USB socket

## 2.1mm Cylindrical/Barrel Connectors

The 2.1mm barrel connector is very common for DC power supplies (wall-warts), but perhaps overtaken these days by the ubiquitous USB.
The "2.1mm" refers to the diameter of the centre pin, although there are also 2.5mm versions.
Sometimes these are referred to as "5.5mm" connectors, which refers to the outer diameter or the plug.

![cylindrical](./assets/cylindrical.jpg?raw=true)

### Polarity

Unfortunately, the polarity is not standardised. Centre-positive and centre-negative configurations are both in circulation,
and devices don't necessarily have reverse-polarity protection so it is always good to check!

### Bypass Connection

Many 2.1mm sockets feature a "bypass" connector, primarily to allow a battery to be switched in and out depending on
whether a plug is inserted or not. Here are some configurations for components I have on hand..

The components below have the bypass switching on the sleeve. In fact I'd guess that all would switch on the sleeve,
as it is the simplest mechanism (plug insertion pushes the sleeve out of contact with the bypass connector).

| Pin | Role |
|-----|------|
| 1   | Always connected to the centre pin of the socket |
| 2   | Always connected to the sleeve of the socket |
| 3   | Not connected when With plug is inserted: not connected. Without plug: connected to sleeve/pin 2 |

For a centre-positive configuration, a battery could be connected:

* positive to pin 1
* negative to pin 3

Connections are reversed for a centre-negative configuration.


#### Panel-mount Socket

![cylindrical_bypass_1](./assets/cylindrical_bypass_1.jpg?raw=true)

#### PCB-mount Socket

![cylindrical_bypass_2](./assets/cylindrical_bypass_2.jpg?raw=true)


## Credits and References
* [DC connector](https://en.wikipedia.org/wiki/DC_connector) - wikipedia
* [..as mentioned on my blog](https://blog.tardate.com/2017/08/leap329-on-dc-power-connectors.html)
