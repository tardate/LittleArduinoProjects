# #171 SMDPracticeBoards

A collection of notes, kits and resources for hand-soldering surface mount devices


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

Through-hole and DIP components have historically made it really easy for the electronics hobbyist to hand-solder a project together.

These days it's getting harder to avoid surface mount components due to
* availability or cost of through-hole/DIP pacakges
* or that some newer components may only be available in surface mount packages

One effective solution is to use a "module" if one is available.
These are generally small boards holding surface mount chip(s) and supporting circuitry
but provide pins or sockets for easy external connections.
Although mainly geared for microcontroller market, there are many that are also relevant for standalone analog or digital circuits.
An example is [this CurrentSensorModule](../../playground/CurrentSensorModule).

However as I've found, surface-mount devices can be quite easy to use in a hobby project even in the absence of a suitable module.
The challenge kind of breaks down into two categories:

* larger pitch SMDs which can quite easily be soldered with traditional techniques
  * e.g. SOT/SOIC components and 0805 or even 0603 discrete components with a pitch of 0.95 or higher
  * [SO16 SSOP16 TSSOP16 SOIC16 To DIP adapter boards](http://www.aliexpress.com/item/20-Pcs-SO16-SSOP16-TSSOP16-SOIC16-To-DIP-Adapter-PCB-Board-Converter/32436820541.html) are handy to make the components breadboard-compatible

* small pitch SMD packages that generally require drag or reflow soldering techniques
  * e.g TSSOP/TQFP packages with a pitch of 0.80 or lower
  * magnifier and lots of flux! .. pretty much essential
  * I haven't quite mastered this yet ;-(

To get started, there are some pretty cheap practice boards available, like this:

![SMD Kit#2 test](./assets/kit2_test.jpg?raw=true)


### Surface Mount Nomenclature

* [Surface-mount technology](https://en.wikipedia.org/wiki/Surface-mount_technology) - wikipedia
* [List of integrated circuit package dimensions](https://en.wikipedia.org/wiki/List_of_integrated_circuit_package_dimensions) - wikipedia
* [MELFs](http://en.wikipedia.org/wiki/MELF_electronic_components).


### SMD Soldering Tutorials

There's some great tutorials on YouTube and around the net. Here are a few I've seen:

* [EEVblog #186 - Soldering Tutorial Part 3 - Surface Mount](https://www.youtube.com/watch?v=b9FC9fAlfQE)
* [The Ben Heck Show - Surface Mount Soldering Tips and Tricks](https://www.youtube.com/watch?v=f0KZbhvKqS0)
* [HowTo SMD Soldering](https://www.youtube.com/watch?v=z7Tu8NXu5UA)
* [HowTo: Drag Soldering Demo](https://www.youtube.com/watch?v=wUyetZ5RtPs)
* [sparkfun surface mount soldering tutorials](https://www.sparkfun.com/tutorials/category/2)

### SMD Practice Kit #1

Obtained from [a seller on aliexpress](http://www.aliexpress.com/item/SMT-SMD-Component-Welding-Practice-Board-Soldering-Practice-DIY-Kit-Better-US57-Free-Shipping/32243189935.html) for under USD1 per board.

This is an example of a basic practice board
* with 0603, 0805, 1206, SOT-23 and SOP-16 components.
* After welding, it can be powered 7V to 15V and an LED will light up if all 0603, 0805, 1206 resistors and diodes soldered correctly
* there's no test circuit for the SOT-23 and SOP-16 components

Here's the test circuit showing a pass on my practice board (yay! ... though you can see I bodged the SOP16 a bit):

![SMD Kit#1 test](./assets/kit1_test.jpg?raw=true)

### SMD Practice Kit #2

Obtained from [a seller on aliexpress](http://www.aliexpress.com/item/SMD-components-welding-practice-board-Welding-practice-light-kit-Skills-Training-welding-competition-kit/32315250409.html) for around USD2.50 per board.

This is an example of a pretty full-featured practice board with a wide range of components from 0402 to 1206 and SOP-8/16.
* central feature is a classic 4017/555 strobe circuit - similar to the [RingCounter](../RingCounter) project
* all components are laid out in circuits with clear test points

![parts and instructions](./assets/kit2_parts_and_instructions.jpg?raw=true)

Here's a quick video of the test circuit in action:

[![SMD Kit#2 demo](http://img.youtube.com/vi/-0-qbcGySPA/0.jpg)](http://www.youtube.com/watch?v=-0-qbcGySPA)


## Credits and References
* [Kit #1 Practice Board](http://www.aliexpress.com/item/SMT-SMD-Component-Welding-Practice-Board-Soldering-Practice-DIY-Kit-Better-US57-Free-Shipping/32243189935.html) - example of a basic practice board with 0603, 0805, 1206, SOT-23 and SOP-16 components
* [Kit #2 Practice Board](http://www.aliexpress.com/item/SMD-components-welding-practice-board-Welding-practice-light-kit-Skills-Training-welding-competition-kit/32315250409.html) - example of a pretty full-featured practice board
* [SO16 SSOP16 TSSOP16 SOIC16 To DIP Adapter PCB Board Converter](http://www.aliexpress.com/item/20-Pcs-SO16-SSOP16-TSSOP16-SOIC16-To-DIP-Adapter-PCB-Board-Converter/32436820541.html) - modules I used from an aliexpres seller to mount the SOP-8 chip

