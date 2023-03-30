# #590 Tiger Moth

Royal Navy Fleet Air Arm Tiger Moth XL717 heading out over the rocky shors near Abbotsinch, Scotland - a small vignette featuring the Airfix De Havilland DH.82a Tiger Moth 1:72 A02106 with a custom motorised propeller.

![Build](./assets/TigerMoth_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/O2OxTApTwp4/0.jpg)](https://www.youtube.com/watch?v=O2OxTApTwp4)

## Notes

Still a familiar sight at airfields all over the world, the de Havilland Tiger Moth primary trainer made its first flight back in 1931 and went on to provide British and Commonwealth air forces with thousands of trained pilots for their operational squadrons. Performing a similar role to this day, the Tiger Moth allows prospective Warbird pilots to gain valuable experience in flying a tail-dragger aircraft.

The Airfix 1:72 De Havilland DH.82a Tiger Moth A02106 kit is a relatively new (2014) tool and this latest edition includes new decals and markings for a very attractive silver with yellow bands for a 1962 XL717 Royal Navy Fleet Air Arm based in Abbotsinch, Scotland.
The picture this immediately conjoured up for me was of the plane heading out to sea over a rocky coastline .. and so that is the vignette I set out to build here!

The kit came from my favourite local hobby shop - [Hobby Bounties](https://hobbybounties.com/).

![kit_parts](./assets/kit_parts.jpg?raw=true)

I did purchase a PE set for the kit from Brengun [BRL72108](http://www.brengun.cz/e-shop/1-72-accessories-21/dh-82a-tiger-moth-(airfix)-1247),
but it is still in the mail and I got impatient to go ahead with the build.

I guess I'll just have to build another Tiger Moth later (and this time perhaps attempt the rigging).

## Paint Schemes

Scheme 1: De Havilland DH.82a Tiger Moth Royal Naval Air Station Abbotsinch, Paisley, Scotland, 1962

Basic colors:

| Feature                     | Colour        | Humbrol   | Paint Used  |
|-----------------------------|---------------|-----------|-------------|
| fuselage                    | Silver        | 11        | Vallejo 70.997 Silver |
| fuselage stripes, prop tips | Matt Yellow   | 24        | Vallejo 70.952 Lemon Yellow|
| prop, wheels                | Black         | 33        | Vallejo 70.950 Black |
| grille                      | Gunmetal      | 53        | Vallejo 70.863 Gunmetal Grey|
| cockpit interiors           | Cockpit Green | 78        | Humbrol 78 |
| crew/uniform                | RAF Blue      | 96        | mixed acrylics |

## Installing the Engine

My chosen elctronics challenge with this build is to motorise the propeller.

The first mission: find the smallest motor to fit the engine cowling. These old mobile phone vibration motors are just the right size.

![engine_prep](./assets/engine_prep.jpg?raw=true)

## Motor Control

For simple motor control, I'll be using a 3V PWM controler using on a 555 Timer. The trim-pot provides adjustable duty cycle.

![Breadboard](./assets/TigerMoth_bb.jpg?raw=true)

![Schematic](./assets/TigerMoth_schematic.jpg?raw=true)

With the motor temporarily tcked in place, the first bench test of the motor goes smoothly!

![TigerMoth_bb_build](./assets/TigerMoth_bb_build.jpg?raw=true)

I built the circuit as deadbug/freeform and attached to a 2xAAA battery box.

![controller_test](./assets/controller_test.jpg?raw=true)

Here's a scope trace of the PWM signal at ~60% duty cycle:

![pwm_motor_drive](./assets/pwm_motor_drive.gif?raw=true)

## Construction

The generic Airfix aircrew got a few positional mods and an impressionistic paint job .. perhaps faintly reminiscent of the Ecce Homo resoration - but it does work from a distance!

![aircrew_mods](./assets/aircrew_mods.jpg?raw=true)

Testing the diorama concept - low pass over a rolling sea. A "found" piece of slate(?) is the base, and provides some nice texture for the sea.

![diorama_concept](./assets/diorama_concept.jpg?raw=true)

Motor wiring exits under the cockpit (~0.2mm enamelled winding wire)..

![fuselage_wiring](./assets/fuselage_wiring.jpg?raw=true)

Main assemblies before final construction. Almost forgot the extra yellow ribbon on the tail!

![in_the_spray_booth](./assets/in_the_spray_booth.jpg?raw=true)

All was going well until I blindly applied Mr Mark Softer decal solution. This was way to hot for the roundels, and melted away the white and red. Only just managed to save with some laborious touchups with a brush. Totally avoidable, as the decals didn't need the Mr Mark Softer treatment in the first place.

I have used Mr Mark Setter and Mr Mark Softer before without trouble on Airfix decals (Typhoon, Harrier builds), so this was a wake-up call to not be so blaze with the strong stuff.

![decal_disaster](./assets/decal_disaster.jpg?raw=true)

Starting to bring it all together..

![mounting_on_diorama](./assets/mounting_on_diorama.jpg?raw=true)

Final engine test before committing to assembly..

![final_engine_test_before_assembly](./assets/final_engine_test_before_assembly.jpg?raw=true)

## Gallery Shots

![gallery_1](./assets/gallery_1.jpg?raw=true)
![gallery_2](./assets/gallery_2.jpg?raw=true)
![gallery_4](./assets/gallery_4.jpg?raw=true)
![gallery_5](./assets/gallery_5.jpg?raw=true)
![gallery_6](./assets/gallery_6.jpg?raw=true)
![gallery_7](./assets/gallery_7.jpg?raw=true)

[![clip](https://img.youtube.com/vi/O2OxTApTwp4/0.jpg)](https://www.youtube.com/watch?v=O2OxTApTwp4)

## Out and About

After a last minute scramble, I had the model ready just in time to give it a showing at
the Mini-Airfix de Havilland Competition run by [Hobby Bounties](https://hobbybounties.com/).
I was lucky that day!

![dehavilland_competition_2021](./assets/dehavilland_competition_2021.jpg?raw=true)

## Credits and References

* [this project on scalemates](https://www.scalemates.com/profiles/mate.php?id=74137&p=projects&project=96413)
* [Airfix De Havilland DH.82a Tiger Moth 1:72 A02106](https://www.scalemates.com/kits/airfix-a02106-havilland-dh82a-tiger-moth--1121408) - scalemates
* [BRL72108 Brengun PE set](http://www.brengun.cz/e-shop/1-72-accessories-21/dh-82a-tiger-moth-(airfix)-1247)
