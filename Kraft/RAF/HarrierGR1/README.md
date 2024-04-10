# #558 Harrier GR.1

Building the Airfix 1:72 Hawker Siddeley Harrier GR.1, electrifying it with lights and engine sounds and putting it in a cold war forward deployment diorama
(somewhere in a German forest circa 1970)

![Build](./assets/HarrierGR1_build.jpg?raw=true)

Here's a quick demo, the first engines and lights test in the diorama setting..

[![clip](https://img.youtube.com/vi/oKDRqEsg5nY/0.jpg)](https://www.youtube.com/watch?v=oKDRqEsg5nY)

## Notes

This started out as a simple idea - build a model as a demonstration platform for the
[LEAP#554 Jet Engine Startup Effect](../../Audio/AudioEffects/JetEngine). But down the rabbit hole I went,
and before I knew it I'd somehow decided to build a full diorama and this kept me occupied for weeks (a useful distraction during COVID19 lockdown).

I haven't built a model plane in (many) decades, so it was a bit of a walk down memory lane
to browse the current offerings of my old favourite, [Airfix](https://www.airfix.com).
Little did I realise how lucky I am to be able to do that - I learned from maxsmodels' excellent
[Airfix kit models: a brief history movie](https://www.youtube.com/watch?v=KjxaJgxXavc)
how many times the company came so close to folding in the intervening years.

The good news is that the company now seems in good health as part of the Hornby group,
with many of the models in the current catalog using new tools and the quality of the kits far superior to what I remember.
In fact the whole industry appears to be quite alive, with some very interesting names that are new to me (I have my eye on a Trumpeter PLA Navy model).

It didn't take long to pick the Hawker Harrier GR.1 as the subject for my build.
The Harrier was the closest thing to real life science fiction when I grew up, and I've always loved it's brutish yet graceful lines.
I never got to make it as a model when I was a kid. But now I'm a fully grown big kid, here's is my chance!

The [Airfix A55205 Medium Starter Set - Hawker Harrier GR.1](https://www.airfix.com/uk-en/hawker-harrier-gr1-starter-set-1-72.html) is perfect for my purposes:

* it's a starter set, so has all the bits I no longer have on-hand (cement, paints, brushes)
* at 1:72 scale, the fuselage of the Harrier gives me just enough interior space to pack in a decent electronics load

Plan for the build:

* build the jet-engine sound effect and navigation lights for installation in the kit
* build the kit(!), with control wires sneakily coming out of the rear landing gear
* build a controller for the engines and lights with 18650 battery, charger, and boost mode switching power supply (to provide the voltage necessary for the jet engine)
* a diorama based on a classic photograph of a Harrier GR1 on forward deployment in (West) German forest around 1970

## About the Harrier

I won't recount the history of the Harrier, except to say that the GR1 was the first to see service with the RAF, with  No. 1 Squadron starting to convert to the aircraft at RAF Wittering in April 1969.
Two Harrier squadrons were established in 1970 at the RAF's air base in Wildenrath to be part of its air force in Germany.
In 1977, the squadrons were moved forward to the air base at Gütersloh, closer to the prospective front line in the event of an outbreak of a European war.

Some good resources for more information:

* [Hawker Siddeley Harrier](https://en.wikipedia.org/wiki/Hawker_Siddeley_Harrier) - wikipedia
* [Hawker Siddeley BAe Harrier](https://www.baesystems.com/en/heritage/hawker-siddeley-harrier) - BAe Systems
* [Zarco Macross](http://zarco-macross.wikidot.com/wiki:harriers) - great collection of resources
* [Hawker Harrier model blueprints](https://www.the-blueprints.com/blueprints/modernplanes/hawker/28015/view/hawker_harrier/)

## The Electronics

The onboard electronics comprise:

* the jet engine sound simulator (zener noise source, CD4046 PLL, LM386 amplifier with piezo speaker), powered with ~9.4V (needs to be > 9V for the zener noise source to fire)
* a dual 555 timer to flash the dome navigation strobe beacon (red LED)
* wingtip navigation read/green LEDs and a white flood LED on the forward landing gear
* power is externally switched, with separate power lines for the engine (VENG) and the LEDs (VNAV)

These circuits were first verified on a breadboard

![Breadboard](./assets/HarrierGR1_bb.jpg?raw=true)

![Schematic](./assets/HarrierGR1_schematic.jpg?raw=true)

![HarrierGR1_bb_build_nav_lights](./assets/HarrierGR1_bb_build_nav_lights.jpg?raw=true)

### Navigation Strobe

The red light on the upper fuselage uses two 555 timers to blink once every second:

* astable with R1=47kΩ, R2=680kΩ, C1=1µF for a frequency of [1.023 Hz](https://visual555.tardate.com/?mode=astable&r1=47&r2=680&c=1)
* monostable with R1=100kΩ, C1=1µF for an on-time of [110.000 ms](https://visual555.tardate.com/?mode=monostable&r1=100&c=1)

Here's the scope trace of the flasher running on the breadboard:

![scope_nav_strobe](./assets/scope_nav_strobe.gif?raw=true)

### Jet Engine Sound

See [LEAP#554 Jet Engine Startup Effect](../../Audio/AudioEffects/JetEngine) for more details, but here's the essence:

The trick I'm using with the jet engine sound is to mix a zener noise source (roughly white noise)
with a gradually rising tone generated with the VCO in the CD4046 PLL chip.
To my ears at least, this produces a fairly convincing simulation of a jet engine turbine winding up to speed.

In this spectrum view, the peak to the left is the tone that rises from about 425 Hz to 4680 Hz over a period with time constant (𝛕) of ~4.7s.

![scope_jet_sound_spectrum](./assets/scope_jet_sound_spectrum.gif?raw=true)

### Onboard Electronics Build

Making sure it all fits inside the fuselage is the main constraint. I used a mix of DIP, through-hole and SMT parts and a freeform/dead-bug
construction to pack it all in.

The jet engine is built around the CD4046. The arrangement of components was a meditative evening's work!
The result has the piezo speaker forward, and power connections to the rear.
I retained the trim pots for volume and noise/tone mix so that I could make fine adjustments after installation.

![build_jet_engine](./assets/build_jet_engine.jpg?raw=true)

The navigation strobe circuit comprises two 555 timers and supporting components installed to the rear.
Although there is enough room to use through-hole components, I switched to surface mount resistors and capacitors for this module (just because).

Note: here's where I made an irreversible mistake: I tested the strobe circuit for basic operation before installation,
BUT DIDN'T CHECK THE TIMING. I think my SMT components had very different tolerances and actual component values than the through-hole
components I used on the breadboard test. I only noticed it was off after sealing the fuselage (and my fate!).
So my navigation strobe in the final build is a bit disappointing - in particular, the on-time is too short for it to flash with a decent brightness.

![build_nav_strobe](./assets/build_nav_strobe.jpg?raw=true)

### Onboard Electronics Installation

This cross-section shot shows the basic layout:

* jet engine circuit forward
* strobe flasher in the rear
* a small SMD DIP adapter board in the middle for mounting connections and the current-limiting resistors for the LEDs
* power connections come out of the rear landing gear housing

![build_electronics_installation1](./assets/build_electronics_installation1.jpg?raw=true)

Wingtip navigation LEDs have their wiring (0.2mm enamelled winding wire) routed inside the wing, with the navigation beacon attached to the upper fuselage.
It was only after finishing the fuselage construction that I discovered there is another navigation beacon on the lower fuselage near the rear landing gear.
Unfortunately too late in the build to also wire this up.

![build_wing_lights](./assets/build_wing_lights.jpg?raw=true)

The flood light on the forward landing gear has it control wires snaking up through the engine compartment:

![build_front_wheel](./assets/build_front_wheel.jpg?raw=true)

I had to make some fine adjustments to the engine mounting, volume and mix settings before glueing the fuselage together.
I wanted sufficient volume and a good mix without vibrations.

[![clip](https://img.youtube.com/vi/xQYLu9OQzMY/0.jpg)](https://www.youtube.com/watch?v=xQYLu9OQzMY)

Last chance to test before glueing on the wings!

![build_electronics_installation2](./assets/build_electronics_installation2.jpg?raw=true)

### Controller

The controller for the plane is housed in a 100x60x25mm plastic project box. It contains:

* single 18650 lithium-polymer battery
* TP4056 BMS module - for USB 5V charge control and battery protection
* MT3608 boost module - for boosting the battery output to ~9.4V for the model
* 3 switches: main battery power switch; VENG output; VNAV output
* 3 LEDs in snazzy bezels: power indicator (green); VENG output (red); VNAV output (blue)
* smoothing capacitors for VENG (220µF) and VNAV (100nF)
* 2x1N4001 in the VNAV line to drop the VNAV voltage down by two diode drops and provide further isolation from interference from the engine circuit

These are all parts that I had on hand, generally purchased from aliexpress:

* [100x60x25mm Plastic Electronic Project Box Black DIY Enclosure Instrument Case Electrical Supplies](https://www.aliexpress.com/item/4000460501514.html)
* [TP4056 module](https://www.aliexpress.com/item/32986135934.html)
* [MT3608 boost module](https://www.aliexpress.com/item/32948417810.html)
* [18650 3.7V 5000mAh Battery](https://www.aliexpress.com/item/33024456380.html) (the one I'm using right now is actually 3300mAh)
* [10*15mm SPST rocker switch](https://www.aliexpress.com/item/32997395813.html) - for power
* [3-Pin SPDT Toggle Switch](https://www.aliexpress.com/item/32944145213.html) - for engine and nav lights control

The following diagram shows the basic wiring of the controller (not including LEDs, smoothing capacitors and diodes).
See the main schematic for the smoothing capacitors and diodes.
For the indicator LEDs, there are wired with suitable currently limiting resistors as follows:

| LED                         | Resistor |
|-----------------------------|----------|
| 3mm Green (power indicator) | 2.2kΩ |
| 3mm Red (VENG indicator)    | 2.2kΩ |
| 3mm Blue (VNAV indicator)   | 6.8kΩ |

![controller_wiring](./assets/controller_wiring.jpg?raw=true)

The finished controller, with everything powered on. The box lid is painted with some paints from the Harrier kit, and
the Hawker Siddeley Harrier GR.1 name decal attached.
I still need to find some decent lettering to label the switches.

![controller_on](./assets/controller_on.jpg?raw=true)

Components pack in quite snugly to the project box.
Note the piece of clear sprue cut, polished and hot-glued to the charging status LEDs, forming a light channel so that status can be monitored from the outside -
I learned this trick from a [SteamGeezer and Son Independent Traders](https://www.youtube.com/watch?v=Y5XRY_WaHYA) video.

![controller_internals](./assets/controller_internals.jpg?raw=true)

With 5V USB attached, red indicates charging, green fully charged:

![controller_charging](./assets/controller_charging.jpg?raw=true)

The controller can either be plugged directly into the diorama base, or attached with a 3-wire cable:

![controller_operating_positions](./assets/controller_operating_positions.jpg?raw=true)

### Building the Kit

The new tool version of Hawker Harrier GR.1 was released in 2013 as [item code A03003](https://www.airfix.com/uk-en/hawker-siddeley-harrier-gr1-1-72.html).
Currently it is marketed by Airfix packaged as a starter kit with [item code A55205](https://www.airfix.com/uk-en/hawker-harrier-gr1-starter-set-1-72.html).

I obtained my kit from [Hobby Bounties in Singapore](https://hobbybounties.com/airfix-medium-starter-set-hawker-siddeley-harrier-gr1-1-72-scale-model-kit/)
for SGD$41.50. At the time pretty much everything was closed for COVID19 containment, but I was glad to find that they were still shipping online orders.

The kit comes in 89 parts on 5 sprues (one transparent).

[![a55205-front](./assets/a55205-front.jpg?raw=true)](https://www.airfix.com/uk-en/hawker-harrier-gr1-starter-set-1-72.html)

Cockpit decals are quite nice:

![build_pilot](./assets/build_pilot.jpg?raw=true)

### Finished Model

Despite being brush painted (using the Humbrol Acrylics supplied in the kit), I'm very happy with the finish.
Few noticeable brush strokes as a result of many layers of watered down paint - following tips from [Owen's Quick Kits channel](https://www.youtube.com/watch?v=wbV_ORs6160).

The wind indicator(?) near the canopy is not yet attached in this upper shot, as it is so fragile I only installed it when ready for the diorama assembly.

![build_plane_complete_upper](./assets/build_plane_complete_upper.jpg?raw=true)

The control wires can be seen coming out from under the rear landing gear in this lower shot.
In this photo, the wires are still terminated with a scrap of protoboard used for testing during construction.
This is replaced in the final build with a "scenery plug" and the wires painted to blend in.

![build_plane_complete_lower](./assets/build_plane_complete_lower.jpg?raw=true)

> Whether to weather or not? That is the question!

I'm so impressed by my paint job - far better than I think I ever achieved back in the day - that I am now faced with a dilemma:
should I attempt some weathering or not? Especially in this environment, one would expect a pretty grimy finish, particularly on the underside.
I will have to think on it - don't want to steal defeat from the jaws of victory by fiddling around with the model too much!

## Diorama

The inspiration for the diorama comes from this fairly famous photo of a GR1 on forward deployment in (West) Germany, probably sometime between 1970 and 1977:

[![harrier-gr-1-raf-cold-war](./assets/harrier-gr-1-raf-cold-war.jpg?raw=true)](https://acesflyinghigh.wordpress.com/2015/07/01/brief-history-of-vstol-combat-aircraft-part-ii-enter-the-harrier-and-the-soviet-yak/)

I found a [transparent cake box](https://shopee.sg/product/116658682/2672632249) - 25cm * 26cm, 2 layer, SGD$7.90 - that I thought might make a good diorama
base and also protective display case. This turned out just fine!

![diorama_box](./assets/diorama_box.jpg?raw=true)

This work-in-progress shot shows the base starting to build up, but also features the electrical connectors - plugged at this moment to stop them getting gunked up.

![diorama_base_1](./assets/diorama_base_1.jpg?raw=true)

The "scenery plug" is wired to the plane but gets disguised as scenery so that the plane can be plugged/unplugged from the base at will.

![diorama_base_2](./assets/diorama_base_2.jpg?raw=true)

I followed Luke Towan's [Tall Forest Pine Trees](https://www.youtube.com/watch?v=Hztif1KoJ-g) tutorial for making the trees, and I think they turned out great!

* some large BBQ skewers
* [Round Coconut Liner Coco Fiber Replacement Liner SGD$1.89](https://shopee.sg/product/83440644/4533824991)
* [Sponge Foliage Model Scenic Material](https://shopee.sg/product/140624501/5708148543) - dark green, medium green SGD$1.67 each
* [Tamiya Linoleum Deck Brown Paint Spray TS-69](https://shopee.sg/product/182871175/3603478107)

![diorama_making_trees](./assets/diorama_making_trees.jpg?raw=true)

Here's the diorama base pretty much complete now: additional foliage and forest litter added; and a hand-painted backdrop for some depth.

![diorama_base_complete](./assets/diorama_base_complete.jpg?raw=true)

## Final Build Gallery

![gallery_three_filters](./assets/gallery_three_filters.jpg?raw=true)

![gallery_1](./assets/gallery_1.jpg?raw=true)
![gallery_2](./assets/gallery_2.jpg?raw=true)
![gallery_3](./assets/gallery_3.jpg?raw=true)
![gallery_4](./assets/gallery_4.jpg?raw=true)
![gallery_5](./assets/gallery_5.jpg?raw=true)
![gallery_6](./assets/gallery_6.jpg?raw=true)
![gallery_7](./assets/gallery_7.jpg?raw=true)
![gallery_8](./assets/gallery_8.jpg?raw=true)

Some demonstration videos:

[![clip](https://img.youtube.com/vi/ntyk_z7kn18/0.jpg)](https://www.youtube.com/watch?v=ntyk_z7kn18)
[![clip](https://img.youtube.com/vi/X3xzvHmxe28/0.jpg)](https://www.youtube.com/watch?v=X3xzvHmxe28)
[![clip](https://img.youtube.com/vi/yGEwxE6NhOA/0.jpg)](https://www.youtube.com/watch?v=yGEwxE6NhOA)
[![clip](https://img.youtube.com/vi/oKDRqEsg5nY/0.jpg)](https://www.youtube.com/watch?v=oKDRqEsg5nY)

## Final Thoughts

This is the first model I've made in *mumble-mumble* decades.
The electronics were the easy part as that's what I've been playing with more recently.

On reflection, I have mixed feelings about the paint job: it's not a "magazine quality" finish,
but probably better than anything I achieved back in the day, and I was just brush painting using the paints from the starter kit.
Some of the Humbrol colours (notably 33 matt black and 163 dark green) seemed prone to be a bit gritty with undissolved pigment,
but it was a good opportunity to "brush up" on my technique. Looking forward to doing better in another project.

A few things I may come back and take care of later:

* camo netting - would match the source photographs better, but I don't want to obscure the plane too much
* weathering - especially for the undercarriage and gun pods

## Out and About

I experimented with creating my first [project page on scalemates](https://www.scalemates.com/profiles/mate.php?id=74137&p=projects&project=88607).

Appearing as a contribution on the [Airfix product page](https://www.airfix.com/uk-en/hawker-harrier-gr1-starter-set-1-72.html):

[![oaa_airfix](./assets/oaa_airfix.jpg?raw=true)](https://www.airfix.com/uk-en/hawker-harrier-gr1-starter-set-1-72.html)

I entered the project into the "social distanced" [Singapore Airfix Cup 2020](https://www.airfixcup.com/).
No prize, but at least I think I held my own amongst a truly impressive showing.

[![oaa_airfixcup](./assets/oaa_airfixcup.jpg?raw=true)](https://www.airfixcup.com/)

## Credits and References

* [Airfix A55205 Medium Starter Set - Hawker Harrier GR.1](https://www.airfix.com/uk-en/hawker-harrier-gr1-starter-set-1-72.html)
* [Airfix A55205 Medium Starter Set - Hawker Harrier GR.1](https://www.scalemates.com/kits/airfix-a55205-hawker-siddeley-harrier-gr1--174713) - Scalemates
* [Airfix A03003 Hawker Siddeley Harrier GR.1](https://www.scalemates.com/kits/airfix-a03003-hawker-siddeley-harrier-gr1--173960) (base kit) - Scalemates
* [Hawker Siddeley BAe Harrier](https://www.baesystems.com/en/heritage/hawker-siddeley-harrier) - baesystems
* [LEAP#554 Jet Engine Startup Effect](../../Audio/AudioEffects/JetEngine)

Some great resources I found for learning or brushing up my modelling skills:

* [Quick Kits](https://www.youtube.com/user/quickkits) - Owen's YouTube channel, especially good for brush painting models
* [Luke Towan's Boulder Creek Railroad](https://www.youtube.com/channel/UCjRkUtHQ774mTg1vrQ6uA5A) YouTube channel - tricks for modelling amazingly realistic scenery
* [Building an infantry diorama with lights and a twist](https://www.youtube.com/watch?v=Y5XRY_WaHYA) - SteamGeezer and Son Independent Traders; where I learned the trick of using some clear sprue as a light channel for internal LEDs
