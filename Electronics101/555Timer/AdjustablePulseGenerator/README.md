# #184 555Timer/AdjustablePulseGenerator

A widely-adjustable square wave generator using the 555 timer


## Notes

This circuit is a variation on the basic 555 timer astable oscillator to allow the widest possible range of frequency and duty cycle adjustment.
The circuit is described in many places, and can also be found in
[kit form](https://www.aliexpress.com/item/E74-Free-Shipping-NE555-Duty-Cycle-Frequency-Adjustable-Square-Wave-Module-Parts-Components/32444736970.html).

R1 and R2 are adjustable between 220Ω and 10.22kΩ, and the capacitor can be switched between 1nF, 100nF, 1µF, and 100µF.

So far I've just tested this on a breadboard. If/when I can find a nice 4-position switch (for the capacitor selection) I'll probably put this in a project case.

### Frequency/Duty Cycle Ranges

Here are the theoretical minimum (Fmin) and maximum (Fmax) frequencies when duty cycle is adjusted as close to 50% as possible (i.e. when R2 is 10kΩ).

| Cap Selection | Fmin | Fmax |
|---------------|------|------|
| 100µF | [0.470Hz @ 66.667%](http://visual555.tardate.com/?mode=astable&r1=10.22&r2=10.22&c=100) | [0.697Hz @ 50.532%](http://visual555.tardate.com/?mode=astable&r1=0.22&r2=10.22&c=100) |
| 1µF   | [46.967Hz @ 66.667%](http://visual555.tardate.com/?mode=astable&r1=10.22&r2=10.22&c=1) | [69.700Hz @ 50.532%](http://visual555.tardate.com/?mode=astable&r1=0.22&r2=10.22&c=1) |
| 100nF | [469.667Hz @ 66.667%](http://visual555.tardate.com/?mode=astable&r1=10.22&r2=10.22&c=0.1) | [696.999Hz @ 50.532%](http://visual555.tardate.com/?mode=astable&r1=0.22&r2=10.22&c=0.1) |
| 1nF   | [46.966kHz @ 66.667%](http://visual555.tardate.com/?mode=astable&r1=10.22&r2=10.22&c=0.001) | [71.216kHz @ 50.532%](http://visual555.tardate.com/?mode=astable&r1=0.22&r2=10.22&c=0.001) |


Here are the theoretical minimum (Fmin) and maximum (Fmax) frequencies when duty cycle is not constrained (i.e. when R2 is 0kΩ).

| Cap Selection | Fmin | Fmax |
|---------------|------|------|
| 100µF | [1.351Hz @ 97.936%](http://visual555.tardate.com/?mode=astable&r1=10.22&r2=0.22&c=100) | [21.818Hz @ 66.667%](http://visual555.tardate.com/?mode=astable&r1=0.22&r2=0.22&c=100) |
| 1µF | [135.084Hz @ 97.936%](http://visual555.tardate.com/?mode=astable&r1=10.22&r2=0.22&c=1) | [2.181kHz @ 66.667%](http://visual555.tardate.com/?mode=astable&r1=0.22&r2=0.22&c=1) |
| 100nF | [1.350kHz @ 97.936%](http://visual555.tardate.com/?mode=astable&r1=10.22&r2=0.22&c=0.1) | [21.818kHz @ 66.667%](http://visual555.tardate.com/?mode=astable&r1=0.22&r2=0.22&c=0.1) |
| 1nF | [135.084kHz @ 97.936%](http://visual555.tardate.com/?mode=astable&r1=10.22&r2=0.22&c=0.001) | [2.181MHz @ 66.667%](http://visual555.tardate.com/?mode=astable&r1=0.22&r2=0.22&c=0.001) |

NB: the rated maximum frequency of the 555 timer is generally 500kHz, so theoretical values above that probably cannot be achieved.
In practice, the highest reliable frequencies squeezed out of a 555 are typically in the order of 600-700kHz.


Or more illustratively, we can use [wolframalpha to plot the frequency graph](https://www.wolframalpha.com/input/?i=plot3d+|+f+%3D+1%2F%28ln%282%29+*+c+*+%28r1+%2B+2*r2%29%29+|+r1+%3D+220+to+10220,+r2+%3D+220+to+10220,+c+%3D+1*10^-6)
(for the case of C=1µF):

![frequency_graph](./assets/frequency_graph.png?raw=true)

And corresponding [duty cycle](https://www.wolframalpha.com/input/?i=plot3d+|+d+%3D+%28r1+%2B+r2%29+%2F+%28r1+%2B+2*r2%29+|+r1+%3D+220+to+10220,+r2+%3D+220+to+10220)
(unaffected by the capacitor selection):

![duty_cycle](./assets/duty_cycle.png?raw=true)


## Construction

![Breadboard](./assets/AdjustablePulseGenerator_bb.jpg?raw=true)

![The Schematic](./assets/AdjustablePulseGenerator_schematic.jpg?raw=true)

![The Build](./assets/AdjustablePulseGenerator_build.jpg?raw=true)

## Credits and References
* [NE555 Duty Cycle Frequency Adjustable Square Wave Module](https://www.aliexpress.com/item/E74-Free-Shipping-NE555-Duty-Cycle-Frequency-Adjustable-Square-Wave-Module-Parts-Components/32444736970.html) - basically this circuit in kit form
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [Visual 555 Calculator](http://visual555.tardate.com)
* [Overclocking the 555 Timer](https://youtu.be/TCz1erC2onQ) - tutorial by Julian Ilett
* [..as mentioned on my blog](https://blog.tardate.com/2016/02/littlearduinoprojects184-adjustable.html)
