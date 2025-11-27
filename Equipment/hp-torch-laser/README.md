# #801 HP Torch/Laser

Fixing a laser pointer and torch powered by a 3V coin cell.

![Build](./assets/hp-torch-laser_build.jpg?raw=true)

## Notes

I found this dinky little laser pointer/torch device in the back of a drawer.
Obviously the give-away from some previous HP event.
A quick test proved it wasn't working any longer.

![build01a](./assets/build01a.jpg?raw=true)

A look inside and I found a coupled of problems:

* battery connections broken
* laser diode had broken from its substrate and disconnected from the board

![build01b](./assets/build01b.jpg?raw=true)

Do I really need this device? No! But let's fix it anyway..

### Circuit Design

Quickly retracing the circuit with Fritzing: see [hp-torch-laser.fzz](./hp-torch-laser.fzz).

It's simple:

* one push-button switching a white LED with 60Ω current-limiting resistor
* second push-button switching a red laser unit, with a 180Ω current-limiting resistor

![bb](./assets/hp-torch-laser_bb.jpg?raw=true)

![schematic](./assets/hp-torch-laser_schematic.jpg?raw=true)

### Build Log

I checked the white LED was still OK, so the main task is to replace the laser unit.

I have some
[3V/5V 650nm 5mW red laser units](https://www.aliexpress.com/item/1005007530265787.html).
These come with a built-in 30Ω current-limiting resistor, so I'm going to remove the onboard 180Ω current-limiting resistor.

They also have a full metal bezel/heatsink/shield that was not in the original laser diode.
Rather than remove it, I'll bodge-it and cut away the case to make space.

![build02a](./assets/build02a.jpg?raw=true)

With the new laser unit installed with some hot glue to keep it in position.

![build02b](./assets/build02b.jpg?raw=true)

Reassembled:

![build03b](./assets/build03b.jpg?raw=true)

And front panel label re-attached with Bu Lai En B-7000 jewelers glue

![build03a](./assets/build03a.jpg?raw=true)

Testing the laser:

![build03c](./assets/build03c.jpg?raw=true)

Testing the LED (it is not very bright):

![build03d](./assets/build03d.jpg?raw=true)

## Credits and References

* [3V/5V 650nm 5mW red laser module](https://www.aliexpress.com/item/1005007530265787.html)
