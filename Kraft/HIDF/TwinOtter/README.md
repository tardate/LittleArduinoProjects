# #720 HIDF Twin Otter Recon

DHC-6 Twin Otter from Revell (04901 in 1:72), as seen commandeered by HIDF Gendarmerie and pressed into service as a reconnaissance and special ops platform.
For the Micro Machines Podcast HIDF GB.

![Build](./assets/TwinOtter_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/hquGInDrmBc/0.jpg)](https://www.youtube.com/watch?v=hquGInDrmBc)

## Notes

I've had the [Revell DHC-6 Twin Otter No. 04901 in 1:72](https://www.scalemates.com/kits/revell-04901-dhc-6-twin-otter--607525)
sitting in my stash for a while.
 It's an "OK" kit and I love the float configuration, but I was searching for diorama inspiration.

When I head about the
[Micro Machines Podcast Horizon Islands Defense Force Group Build](https://www.youtube.com/watch?v=Dcp4T_c6mHw)
I thought .. ahah!

### Paint Scheme

Main colors used for the plane:

| Feature                  | Color                | Recommended | Paint Used |
|--------------------------|----------------------|-------------|------------|
| interior                 | gray                 |             | H61        |
| exterior - under coat  1 |                      |             | H8         |
| exterior - under coat  2 |                      |             | H4         |
| exterior                 |                      |             | H80 (was H303?) |
| HIDF flag                |                      |             | H1, H4, H5, H26 |

Ground-work was a mixture of Vallejo Model Color and Mr Hobby Aqueous.

### HIDF - Horizon Islands Defence Force

HIDF comes from the Arma3 game. Since I've never played it, I am totally faking it when it comes to the lore;-)

All I know comes from the
[Horizon Islands](https://armedassault.fandom.com/wiki/Horizon_Islands) - Armed Assault Wiki,
and the Micro Machines Podcast - Episode 22 (Horizon Islands Defense Forces)

[![clip](https://img.youtube.com/vi/Dcp4T_c6mHw/0.jpg)](https://www.youtube.com/watch?v=Dcp4T_c6mHw)

![hidf-flag](./assets/hidf-flag.jpg?raw=true)

### Circuit Design and Electronics

#### Motor Control

I'm using two [DC 3V-3.7V Coreless Motor 0408](https://www.aliexpress.com/item/4001279573187.html) for the props in the plane.
They are nice and small - 4mm x 8mm  - with an unusually long 7mm shaft making it easy for direct drive installation.

These motors spin anti-clockwise when powered +ve to red lead.
The model props are pitched to spin clockwise - so wire motors in reverse (+ve to black lead).

![bb](./assets/Motors_bb.jpg?raw=true)

![schematic](./assets/Motors_schematic.jpg?raw=true)

![build04c_Motors_bb_build](./assets/build04c_Motors_bb_build.jpg?raw=true)

#### Mini-gun Simulation

Aside from an impressive visual display, the mini-gun hide the in-flight mounting. It is simply a
[255mm Yellow LED Soft Silament / silicon rope DC3V](https://www.aliexpress.com/item/1005005242048043.html)
controlled by a 555 timer astable configured to run at
[10.213 Hz](https://visual555.tardate.com/?mode=astable&r1=10&r2=10&c=4.7)

![bb](./assets/MiniGun_bb.jpg?raw=true)

![schematic](./assets/MiniGun_schematic.jpg?raw=true)

![build04a_Minigun_bb_build](./assets/build04a_Minigun_bb_build.jpg?raw=true)

#### Fire/Explosion

The fire/explosion effect on the base is animated with a couple of 5050 LEDs:

* controlled with an OpAmp-generated triangle wave to give a slow "glow" effect
* driven via an amplified current mirror for better LED brightness control

![bb](./assets/Fire_bb.jpg?raw=true)

![schematic](./assets/Fire_schematic.jpg?raw=true)

![build04b_Fire_bb_build](./assets/build04b_Fire_bb_build.jpg?raw=true)

#### Final Protoboard Build

After checking all the electronics, I fitted all the circuits onto a 4x6cm protoboard with micro USB adapter for power.
Here's my plan of the layout with the final build:

![build04d_protoboard_build](./assets/build04d_protoboard_build.jpg?raw=true)

Connectors from plane:

| wire    | connection      |
|---------|-----------------|
| black   | ground          |
| red     | port motor      |
| orange  | starboard motor |
| yellow  | mini-gun        |

### Build Log

Customising the interior with open doors ready to take some heavy metal payload..

![build01a](./assets/build01a.jpg?raw-true)
![build01b](./assets/build01b.jpg?raw-true)

Some micro motors are going in the props.

![build01c](./assets/build01c.jpg?raw-true)

Motors installed and basic interior completed

![build01d](./assets/build01d.jpg?raw-true)

Main parts primed

![build01e](./assets/build01e.jpg?raw-true)

Starting to build up the "original" scheme (that will later be over-painted with khaki)

![build01f](./assets/build01f.jpg?raw-true)

Preparing the crew and miscellaneous interior fittings

![build02a](./assets/build02a.jpg?raw-true)
![build02b](./assets/build02b.jpg?raw-true)
![build02c](./assets/build02c.jpg?raw-true)
![build02d](./assets/build02d.jpg?raw-true)
![build02e](./assets/build02e.jpg?raw-true)

![build03a](./assets/build03a.jpg?raw-true)
![build03b](./assets/build03b.jpg?raw-true)
![build03c](./assets/build03c.jpg?raw-true)
![build03d](./assets/build03d.jpg?raw-true)
![build03e](./assets/build03e.jpg?raw-true)
![build03f](./assets/build03f.jpg?raw-true)
![build03g](./assets/build03g.jpg?raw-true)
![build03h](./assets/build03h.jpg?raw-true)
![build03i](./assets/build03i.jpg?raw-true)
![build03j](./assets/build03j.jpg?raw-true)

![build05a](./assets/build05a.jpg?raw-true)
![build05b](./assets/build05b.jpg?raw-true)
![build05c](./assets/build05c.jpg?raw-true)

oh shit, tick-tock,
better get moving.
carry on, unblock,
gotta get my build in.

Just sprayed on some HIDF markings on my "field-applied khaki" over the original yellow of this Twin Otter that's been commandeered for island recon and covert ops.
Classified weapons system is still under wraps;-)

Hope to get this completed by the weekend - all the bits are coming together (slowly!)

![build06a](./assets/build06a.jpg?raw-true)
![build06b](./assets/build06b.jpg?raw-true)
![build06c](./assets/build06c.jpg?raw-true)
![build06d](./assets/build06d.jpg?raw-true)
![build06e](./assets/build06e.jpg?raw-true)

### First Flight

First flight of the HIDF Twin Otter specops gunship. Based on the Revell 1:72 kit, this has been adapted for the @micromachinespodcast HIDF group build

![build07b](./assets/build07b.jpg?raw-true)
![build07d](./assets/build07d.jpg?raw-true)
![build07e](./assets/build07e.jpg?raw-true)
![build07f](./assets/build07f.jpg?raw-true)
![build07i](./assets/build07i.jpg?raw-true)
![build07k](./assets/build07k.jpg?raw-true)
![build07m](./assets/build07m.jpg?raw-true)
![build07o](./assets/build07o.jpg?raw-true)
![build07p](./assets/build07p.jpg?raw-true)
![build07q](./assets/build07q.jpg?raw-true)
![build07r](./assets/build07r.jpg?raw-true)

### Final Gallery

HIDF Twin Otter Recon/SpecOps

There's a backstory here ofc, but I just heard it thru the grapevine. Something like:
an ex-Canadian Armed Forces DHC-6 Twin Otter was on charter in the Horizon Islands when the South Pacific Disaster struck.
Needing only moderate repairs to get her back in the air, the DHC-6 was commandeered by the Gendarmerie and pressed into service
for island reconnaissance and covert operations. The interior was stripped and left with open side hatches to provide maximum payload flexibility - from transporting medical supplies, to extracting a tactical response unit. Although intended for stealthy operations under the radar, port and starboard waist gunner positions
can be fitted with a range of equipment, up to and including a wicked mini-gun for when things get a little hot.

About the build: this is the DHC-6 Twin Otter from Revell (04901 in 1:72), modified to take motors for each prop.
The mini-gun fire hides the in-flight mounting - 1.5mm annealed florist's wire from [Knorr Prandell](https://www.knorrprandell.com).
The explosion/flame effect on the base is animated with 5050 LEDs.

The electronics to control the motors, mini-gun effect and explosion are all mounted on a small protoboard.
Motors - 555 timer-based PWM circuit for independent variable speed control.
Explosion - variable current glow effect driven by OpAmp triangle-wave oscillator.
Mini-gun - LED rope driven by 555 timer.

![hero1-build07g](./assets/hero1-build07g.jpg?raw=true)
![hero2-build07h](./assets/hero2-build07h.jpg?raw=true)
![hero3-build07n](./assets/hero3-build07n.jpg?raw=true)
![hero4-build07a](./assets/hero4-build07a.jpg?raw=true)
![hero5-build07j](./assets/hero5-build07j.jpg?raw=true)
![hero6-build07l](./assets/hero6-build07l.jpg?raw=true)
![hero7-build07c](./assets/hero7-build07c.jpg?raw=true)

## Credits and References

* [this project on scalemates](https://www.scalemates.com/profiles/mate.php?id=74137&p=projects&project=152241)
* [DHC-6 Twin Otter Revell No. 04901 1:72](https://www.scalemates.com/kits/revell-04901-dhc-6-twin-otter--607525)
* [Horizon Islands](https://armedassault.fandom.com/wiki/Horizon_Islands) - Armed Assault Wiki
* [Horizon Islands Defense Force](https://www.reddit.com/r/arma/comments/zpuc88/horizon_islands_defense_force/) - reddit
* [1PC DC 3V-3.7V Coreless Motor 0408,412,612,615,617.716,720,816,8520,1020 High Speed RC Drone Strong Magnetic DIY Aircraft](https://www.aliexpress.com/item/4001279573187.html)
* [255mm Yellow LED Soft Silament / silicon rope DC3V](https://www.aliexpress.com/item/1005005242048043.html)
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
