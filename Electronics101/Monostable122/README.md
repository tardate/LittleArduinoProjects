# #074 Monostable122

Simple pulse trigger using 74LS122 monostable with external timing configuration.

## Notes

The 74LS122 monostable multivibrator in this circuit has pulse width programmed by selection of external resistance and capacitance values
R2 and C2. Pulse width is given as:

    tW = K * R2 * C2
    => where K is nominally 0.45. If C2 is in μF and R2 is in kΩ then tW is in seconds

For 33μF and 100kΩ then pulse width is [1.485s](http://www.wolframalpha.com/input/?i=0.45+*+100+*+10^3+*+33+*+10^-6).
This is intentionally large so that a visible pulse produced.

Once triggered, the basic pulse width may be extended by retriggering the gated low-level-active (A) or high-level-active (B) inputs,
or be reduced by use of the overriding clear.

In this circuit we have a pushbutton to trigger the pulse. LEDs are separately connected to output Q and Q complement,
so they will toggle as the pulse goes high and low respectively.

### Construction

![The Breadboard](./assets/Monostable122_bb.jpg?raw=true)

![The Schematic](./assets/Monostable122_schematic.jpg?raw=true)

![The Build](./assets/Monostable122_build.jpg?raw=true)

## Credits and References
* [74LS122 Datasheet](http://www.futurlec.com/74LS/74LS122.shtml)
* A similar circuit can be found in "Project 18 - 74LS122 Monostable" from [Beginning Digital Electronics Through Projects](http://www.amazon.com/gp/product/0750672692/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=0750672692&linkCode=as2&tag=itsaprli-20&linkId=S6GVIV6DHZABMHTA)
