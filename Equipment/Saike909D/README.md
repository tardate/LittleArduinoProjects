# #272 Saike 909D

Unboxing and initial review of the Saike 909D 3-in-1 hot air rework station.

![Build](./assets/Saike909D_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

> you know what it's like when you go search for the cheapest hot-air station on the 11-11 sale; think well, I may as well get one of the better ones; and since the price not that much different I should go for the 3-in-1 instead of the 2-in-1, then have to sneak it home past your partner? ... well, like that :smiley:

I've been wanting a hot-air gun for a while, and I found a good deal on a Saike 909D recently.
It is actually a 3-in-1 unit, comprising:

* hot-air gun
* solder station
* DC power supply

It can usually be found sold with a bundle of supplies and attachments.

The TL/DR review: very good value for the price. Happy!


## Technical Specification

| Parameter                 | Specification        |
|---------------------------|----------------------|
| AC Supply                 | 220V, 50Hz           |
| Work environment          | 0 to 50°C            |
| **DC Power Supply**       |                      |
| Output Voltage            | 0-15V DC, <0.01 ±2mV |
| Output Power              | 15W max              |
| **Soldering Iron**        |                      |
| Output Power              | 50W                  |
| Temperature range         | 200-480°C            |
| Temperature stability     | ±2°C                 |
| Tip-ground voltage        | <2mV                 |
| Tip-ground resistance     | <2Ω                  |
| **Heat Gun**              |                      |
| Air flow type             | Brushless fan        |
| Air flow                  | 120l/min (max)       |
| Output power              | 700W                 |
| Temperature range         | 100-450°C            |
| Temperature stability     | ±1°C                 |


### Hot-air Gun

This is the main feature I bought the unit for .. and it works perfectly.
I grabbed a few faulty boards and was unmounting surface mount components within seconds.
The warm-up is very fast.

The only problem I encountered was with one of the nozzle attachments.
Poor quality construction - one of the adjustment lugs just fell off in my fingers:

![Saike909D_nozzles](./assets/Saike909D_nozzles.jpg?raw=true)

The other nozzles are fine. Maybe I can get the seller to provide a replacement, but if not then no great loss.

### Power Supply

The built-in supply is very convenient to have on the bench built-in to the unit.
It comes with full set of probes and power connectors (including USB socket).

It can supply 0-15V at up to 1A:

* digital voltage display at 0.1V precision
* analog ammeter, 1A full scale. Of course not much use for mA circuits, but fine to highlight a large power drain.
* has an isolated floating ground. There is ~0mA leakage when grounded to earth.

It can also operate as a crude voltmeter.

A quick test:

![Saike909D_psu](./assets/Saike909D_psu.jpg?raw=true)


### Solder Station

I already have a "favourite iron", so the solder station is kind of an unnecessary bonus.

In my first test at 300°C I was having a hard time getting the solder to flow.
I thought it was either taking a very long time to warm up, or it was just unable to deliver sufficient power.

After a bit of research - finding
[posts like this](http://www.eevblog.com/forum/beginners/smd-rework-station-temperature-not-accurate-!!!!!/) -
I suspect it is just not calibrated correctly.

I'll ask the seller before cracking the box to see if I can figure it out..


## Credits and References
* [Saike 853D/909D Manual](./assets/Saike909D_manual.pdf)
* [Saike 909D](https://www.aliexpress.com/item/high-quality-genuine-saike-909D-hot-air-gun-rework-station-with-Soldering-station-power-3-in1/32336689474.html) - from a seller on aliexpress
* [SAIKE 909D Review – Soldering iron, heat gun and DC PSU](http://diygeezer.com/saike-909d-review/)
* [SMD rework station temperature not accurate](http://www.eevblog.com/forum/beginners/smd-rework-station-temperature-not-accurate-!!!!!/) - seems to report the same problem with the soldering iron temperature as I've seen, and a possible solution.
