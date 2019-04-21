# #322 cordwood-too/FidgetCube

Fidget Cube controller for the Boldport Cordwood Too.

Here's a quick video showing it in action..

[![Build](./assets/FidgetCube_build.jpg?raw=true)](https://www.youtube.com/watch?v=38SNS3a9aF8)

## Notes

A colleague gave us all [Fidget Cubes](https://thefidgetcube.co/), I think mainly to keep idle hands from causing too much mayhem in the office.

After building [Boldport Club Cordwood Too](./..), I was trying to think of interesting controls for it, and started wondering if the Fidget Cube
could be converted into a workable controller.

Answer is: Yes! It was a bit finicky, but here's what I have so far:

* the toggle switch on the Fidget Cube is also the main power switch for the Cordwood
* the cube contains a simple 5.1V zener dropper so everything can be powered by a convenient 9V battery
* many of the controls in the Fidget Cube are active and turn off one of the LEDs:
  * ball bearing switch
  * 5-button keypad switch
  * joystick control


### Secrets of the Fidget Cube

First step was of course to find out what was inside the Fidget Cube to see if was suitable for re-purposing,
and whether there was even enough room inside to do anything useful.

The most unexpected discovery was the neat use of neodymium magnets, which have replaced more traditional mechanisms
with simple machines that give a great tactile experience.

Here's a quick guide to what I found inside the cube..

#### Getting it Apart

I left a few prize marks on the case until I found the secret: pull off the rotating wheel, and underneath are two screws.
Remove those and the cube case comes apart in two halves.

![disassembly1](./assets/disassembly1.jpg?raw=true)

#### Toggle Switch

Ingenious mechanism:

* the plastic rocker has a neodymium magnet in each end
* a metal shaft is press-fit through the mounting posts on the inner chassis
* two screws are mounted on the inner chassis under each end of the rocker

So when you toggle the switch, the magnets provide a very nice resistance gradient.

I decided to use this switch as the main power switch. I wired up power to one of the magnets,
and tapped a wire from the corresponding screw, so closing the switch completes the circuit.


#### Ball Bearing Button

The ball bearing simply sits on a metal "clicker" (what is the technical term??)

I replaced the clicker with an SMD push button.
I had to file out a bit more space in the plastic mounting for the 1.5mm height of the push button
so it could still be activated by the ball bearing when re-assembled.


#### Joystick Control

The joystick control is another ingenious mechanism.
The metal joystick pole has a spherical base with flattened bottom.
This sits on another neodymium magnet, so movement in any direction is nicely resisted and the the joystick
snaps back to central position when released.

I decided to wire up LED controls to eight positions around the circumference of the joystick which would be grounded.
So a full rotation could control all LEDs

![disassembly2](./assets/disassembly2.jpg?raw=true)

![disassembly3](./assets/disassembly3.jpg?raw=true)


#### 5-button Keypad

The keypad is just a silicon button fabric backed by a metal plate.
Metal "clickers" were positioned under 3 of the buttons.

I decided to replace all 5 with SMD push buttons.

#### Combination Dialer

Unfortunately, these are just plastic spinners on a common metal shaft.
Not much I could do with these, so I left them as-is.

### Rotary Dial

This is just a plastic disk pressed into a metal shaft. No space and I couldn't think of anything to do with this.


## (Re-) Assembly


### Power

For simplicty, I decided to use a 9V bettery power supply. The Cordwood Too wants 6.5V at most,
and I decided to use a 5.1V zener dropper.


The 1N4733 is rated for 5.1V and maximum power of 1W.
The Cordwood Too draws around 100mA with all LEDs on at this voltage.

* max current = [196mA](https://www.wolframalpha.com/input/?i=1W%2F5.1V)
* minimum value of Rs = [19.9Ω](https://www.wolframalpha.com/input/?i=(9V+-+5.1V)%2F(1W%2F5.1V))
* maximum value of Rs = [39Ω](https://www.wolframalpha.com/input/?i=(9V+-+5.1V)%2F100mA)
* power dissipated over Rs when 39Ω = [3.9mW](https://www.wolframalpha.com/input/?i=100mA%5E2+*+39%CE%A9)

So I selected a 22Ω 1/4W for Rs:

* current through Rs = [177mA](https://www.wolframalpha.com/input/?i=(9V+-+5.1V)%2F22%CE%A9)
* power dissipated over Rs = [3.9mW](https://www.wolframalpha.com/input/?i=177mA%5E2+*+22%CE%A9)


### Joystick and Keypad

Wiring up the neck brace of the joystick and replacing clickers with push buttons under the keypad:

![assembly1](./assets/assembly1.jpg?raw=true)

### Partially Re-assembled

Kinda visible here:

* power wire to the rocker switch (connects to the magnet in the end of one arm)
* push button under the ball bearing is wired up
* micro PCB for the power circuit and terminating connections within the cube to the wires that will connect to the Cordwood

![assembly2](./assets/assembly2.jpg?raw=true)

### Final Connections before Closing the Cube

A few more more wires to solder before closing the cube, connecting the keypad.

![assembly3](./assets/assembly3.jpg?raw=true)

### All back together

![assembly4](./assets/assembly4.jpg?raw=true)

### Cordwood Adapter

Power and Cordwood pins terminate on a small strip of protoboard:

![assembly5](./assets/assembly5.jpg?raw=true)


## Construction

![Breadboard](./assets/FidgetCube_bb.jpg?raw=true)

![Schematic](./assets/FidgetCube_schematic.jpg?raw=true)

![Build](./assets/FidgetCube_build.jpg?raw=true)

## Credits and References
* [Fidget Cube](https://thefidgetcube.co/)
* [LEAP#321 Cordwood Too](./..)
* [Zener Diode tutorial](http://www.electronics-tutorials.ws/diode/diode_7.html)
* [1N4733 datasheet](https://www.futurlec.com/Diodes/1N4733.shtml)
* [4 x 4 x 1.5mm SMD push buttons](https://www.aliexpress.com/item/Free-shipping-100PCS-4-4-1-5mm-4x4x1-5mm-SMD-push-button-switch-microswitch-Tact-Switch/836256964.html)
* [..as mentioned on my blog](https://blog.tardate.com/2017/06/leap322-fidget-cube-cordwood-controller.html)
* [..as posted on hackady.io](https://hackaday.io/project/25626-fidgetcube-cordwood-controller)
