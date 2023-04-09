# #697 IJN/Mitsubishi A5M2b

Building the Wingsy Kits A5M2b in-flight for the 2023 Model Officers Mess birthday bash raising money and awareness for the Models for Heroes charity.

![Build](./assets/MitsubishiA5M2b_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/YFmZ_wTpKk4/0.jpg)](https://www.youtube.com/watch?v=YFmZ_wTpKk4)

## Notes

Model length: 157.6 mm
Wingspan: 229.2 mm

Kit contents:

* Plastic parts: 90
    * 6 plastic runners
    * 1 clear runner
* Photoetched parts: 48
* Film
* Decal sheet, 4 options:
    * IJN Type 96 carrier-based fighter II 12 Kokutai, China 1938, (155)
    * IJN Type 96 carrier-based fighter II 12 Kokutai, China 1938, (154)
    * IJN Type 96 carrier-based fighter II 12 Kokutai, China 1938, (165)
    * IJN Type 96 carrier-based fighter II Hyakurihara Kokutai, Ibaraki, 1940-1941 (113)

### Scheme 4

IJN Type 96 carrier-based fighter II Hyakurihara Kokutai, Ibaraki, 1940-1941 (113)

| Feature               | Color                      | Recommended | Paint Used |
|-----------------------|----------------------------|-------------|------------|
| instrument detail     | black                      | C2/H2     | H2           |
| Tail                  | red                        | C3/H3     | H3            |
| Fuselage              | silver                     | C8/H8     | H8           |
| Prop front, engine    | steel                      | C28/H18   | H18           |
| Cowling               | Cowling color              | C125      | H2            |
| Cockpit interior      | Cockpit color (Mitsubishi) | C126      | H60 + H31           |
| Prop rear, antenna mast | Red Brown                | C131      | H47 (darkened a little?)           |
| exhaust               | Burnt Iron                 | C61/H76   | H76           |
|                       | Tire Black                 | C137      |            |
|                       | IJN Gray                   | C35/H61   | H61           |

### Circuit Design

The controller is implemented in code on an ATtiny85. Some circuit notes:

* the PWM outputs are used to control low-side n-channel FETs rather than directly drive the outputs. This ensures that current load on the ATtiny85 does not exceed limits (10mA per pin, 60mA total).
* the LEDs and accompanying current-limiting resistors are just for demonstration purposes - these can be changed as required for a particular application.
* the duty cycle of the motor control is set based on reading a variable resistor.
* a [fly-back diode](http://en.wikipedia.org/wiki/Flyback_diode) is placed across the motor to drain any voltage spike as the motor load is switched
* I initially built this to be run from 5V USB but got stumped trying to hide a suitable power supply in the picture frame. Luckily, the circuit also works just fin on 3V (2xAAA) - though I don't know how long the batteries will last.

![bb](./assets/MitsubishiA5M2b_bb.jpg?raw=true)

![schematic](./assets/MitsubishiA5M2b_schematic.jpg?raw=true)

Testing the circuits on a breadboard:

![bb_build](./assets/build05b.jpg?raw=true)

Note: with this motor and propeller, I needed the motor connected in "reverse" for correct prop rotation.

### Code Organisation

The main script [MitsubishiA5M2b.ino](./MitsubishiA5M2b.ino) runs the main loop. It uses two support classes to orchestrate the effects:

* `pwm_motor.h`/`pwm_motor.cpp` encapsulates the PWM motor drive, using variable resistor input to set the duty cycle.
* `flame.h`/`flame.cpp` implements the flickering algorithm for a the flames.
    * on each update it adjusts the flames brightness
    * the maximum change per update is set by the brightness input
    * the actual change in brightness is determined by the `mix` value for each flame. This sets the percentage of the new value that is mixed with the old value. Lower values will mean more slowly changing updates

See the [GitHub repo](https://github.com/tardate/LittleArduinoProjects/tree/master/Kraft/IJN/MitsubishiA5M2b) for sources.

The ATtiny85 is programmed using an Arduino Uno as the in-circuit programmer

![programming_the_attiny](./assets/programming_the_attiny.png?raw=true)

### Build Log

This is how I started - just past 7:30pm Singapore UTC+8.
I've got the Wingsy Kits A5M2b "Claude" (early version) a micro motor, a pilot stolen from anther kit and a frame I'm planning to use for mounting.

![fri-night-start](./assets/fri-night-start.jpg?raw=true)

![build01a](./assets/build01a.jpg?raw=true)
![build01b](./assets/build01b.jpg?raw=true)
![build01c](./assets/build01c.jpg?raw=true)
![build01d](./assets/build01d.jpg?raw=true)

we have ignition! motorising was a stretch goal, but the way Wingsy have designed the engine makes it quite easy to mount a micro motor .. controlled by a microprocessor .. it's a micro machine;-)

![build01e](./assets/build01e.jpg?raw=true)

engine detail coming together!

![build01f](./assets/build01f.jpg?raw=true)

Saying goodnight from UTC+8 for now and see you all in the morning. Great time so far - caught the live streams starting with Oz and it got me moving. Got most of the subassemblies ready: have ignition; got air! Hopefully it'll all just fall together tomorrow. As I write, the fund-raiser is already 15% to the goal .. and the event hasn't even "started" yet. That is pretty amazing!

![fri-night-close](./assets/fri-night-close.jpg?raw=true)

a bit of head-scratching later and I figured out how all the engine parts fit together!

![build01g](./assets/build01g.jpg?raw=true)

![build02a](./assets/build02a.jpg?raw=true)
![build02b](./assets/build02b.jpg?raw=true)
![build02c](./assets/build02c.jpg?raw=true)
![build02d](./assets/build02d.jpg?raw=true)
![build02e](./assets/build02e.jpg?raw=true)
![build02f](./assets/build02f.jpg?raw=true)
![build02g](./assets/build02g.jpg?raw=true)
![build02h](./assets/build02h.jpg?raw=true)
![build02i](./assets/build02i.jpg?raw=true)

a pity it's all going to be hidden away, but I blew my morning time budget on the cockpit. the kit makes it pretty irresistible!

![build02j](./assets/build02j.jpg?raw=true)

![build03a](./assets/build03a.jpg?raw=true)
![build03b](./assets/build03b.jpg?raw=true)
![build03c](./assets/build03c.jpg?raw=true)

finally closed up the fuselage

![build03d](./assets/build03d.jpg?raw=true)

Since the plane is in-flight, I need a pilot! I stole this from the Tamiya Ki-61 Hien kit and did a rapid paint job. I have a feeling the flying kit is a little too advanced for the Claude but, hey..

![build04b](./assets/build04b.jpg?raw=true)
![build04c](./assets/build04c.jpg?raw=true)

![build05a](./assets/build05a.jpg?raw=true)
![build05b](./assets/build05b.jpg?raw=true)
![build05c](./assets/build05c.jpg?raw=true)

not enough time to paint my own background, so I tropical storm  picture from a calendar (shot in Darwin actually)

![build05d](./assets/build05d.jpg?raw=true)

put the electronics on protoboard and installed in the rear of the frame

![build05f](./assets/build05f.jpg?raw=true)

stuck on the wall (to give it time to cure before I add the load of the plane)

![build05g](./assets/build05g.jpg?raw=true)

a few coats of H8 later and I'm ready to call it a night (Sat). Just got final paint, decals weathering and installation for Sunday. Pretty confident of finishing this in 48 now!

![sat-night-close](./assets/sat-night-close.jpg?raw=true)

painting the tail

![build06a](./assets/build06a.jpg?raw=true)
![build06b](./assets/build06b.jpg?raw=true)
![build06c](./assets/build06c.jpg?raw=true)
![build06d](./assets/build06d.jpg?raw=true)

![build07a](./assets/build07a.jpg?raw=true)

canopy closed up and now starting to wrangle the wiring

![build07b](./assets/build07b.jpg?raw=true)

mounted and wiring up..

![build07c](./assets/build07c.jpg?raw=true)

smoke trails..

![build07d](./assets/build07d.jpg?raw=true)

I was impressed by the kit decals: good strong white over red, and they settled down major rudder parts with nothing more than Mr Mark Setter and time.

![build07e](./assets/build07e.jpg?raw=true)

Mounted on the wall (velcro sticky strips - nice and secure).

![build08a](./assets/build08a.jpg?raw=true)
![build08b](./assets/build08b.jpg?raw=true)
![build08c](./assets/build08c.jpg?raw=true)
![build08d](./assets/build08d.jpg?raw=true)
![build08e](./assets/build08e.jpg?raw=true)
![build08f](./assets/build08f.jpg?raw=true)
![build08g](./assets/build08g.jpg?raw=true)
![build08h](./assets/build08h.jpg?raw=true)

Wingsy Kits A5M2b "bring it home through the fire and flames". Had a little fun with an ATtiny for motor and flame effects.

![build09a](./assets/build09a.jpg?raw=true)
![build09b](./assets/build09b.jpg?raw=true)
![build09c](./assets/build09c.jpg?raw=true)
![build09d](./assets/build09d.jpg?raw=true)
![build09e](./assets/build09e.jpg?raw=true)
![build09f](./assets/build09f.jpg?raw=true)
![build09g](./assets/build09g.jpg?raw=true)

Amazing - the model got featured as the Model Officers' Mess banner for April 2023..

![mom-april-banner](./assets/mom-april-banner.jpg?raw=true)

## Credits and References

* [this project on scalemates](https://www.scalemates.com/profiles/mate.php?id=74137&p=projects&project=141873)
* [A5M2b "Claude" (early version) Wingsy Kits No. D5-03 1:48](https://www.scalemates.com/kits/wingsy-kits-d5-03-a5m2b-claude-early-version--1073901)
* [D5-03 IJN Type 96 carrier-based fighter II A5M2b “Claude” (early) 1/48](https://www.wingsykits.com/product/d5-03-ijn-type-96-carrier-based-fighter-ii-a5m2b-claude-early-version-148/) - wingsykits
* [Mitsubishi A5M](https://en.wikipedia.org/wiki/Mitsubishi_A5M) - wikipedia
* [A5M2b 'Claude' (Early) D5-03 Build By Chris Meddings - Models for Ukraine Vol2 p114](https://www.insidethearmour.com/product-page/models-for-ukraine-vol-2-preorder)
* [A5M4 D5-02 Build By Jeremy Moore - Models for Ukraine Vol1 p11](https://www.insidethearmour.com/product-page/models-for-ukraine-ebook)
* [Kawasaki Ki-61-Id Hien (Tony) Tamiya No. 61115 1:48](https://www.scalemates.com/kits/tamiya-61115-kawasaki-ki-61-id-hien-tony--1017255)
* [ATtiny85 datasheet](https://www.microchip.com/en-us/product/ATTINY85)
* [2N7000 datasheet](https://www.futurlec.com/Transistors/2N7000.shtml)
* [1N4001 Datasheet](https://www.futurlec.com/Diodes/1N4001.shtml)
