# #224 LEDStrobeKit

Build and analyse a common LED strobe kit.

![The Build](./assets/LEDStrobeKit_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

Another cheap kit build, this time a [CD4017 + ne555 Strobe module](https://www.aliexpress.com/item/CD4017-ne555-Strobe-module-electronics-production-suite-DIY-Kits-electronic-diy-Learning-suite/32438304004.html)
that I picked up from a seller on aliexpress.

Turns out it is the same module that Julian Ilett covered in another of his excellent vidoes:
[Postbag #29: Fun Re-Wiring a 555 and 4017 LED Module](https://www.youtube.com/watch?v=bxyp4Jq8a3Y)

### The Kit

Here's the description from the product information provided by the seller:

* Kit Name: Strobe Kit
* Operating voltage : 12V
* Dashboard size : 5.4 * 3.1Cm
* Light board size : 3.5 * 2.6CM;


### LED Modules

The three LED arrays are of identical construction:

* 16 LEDs in 4 parallel strings, each with 4 LEDs in series
* a 27Ω current limiting resistor on the common anode connection

The common cathode of each module is connected to the 12V power supply.
Although the ICs in the circuit can work on much lower voltages,
in practice over about 10V is required
to overcome the forward voltage of the 4 LEDs in series. At 12V the modules are quite bright.

The brightness is not even for each color, since the LEDs have different forward voltages.
It would be a good idea to balance the brightness by adjusting the current-limiting resistor on each module
instead of using the 27Ω resistor in each.

**Modification**

After some calculation and test, I adjusted the current-limiting resistors as follows to give a decent brightness balance:

| Colour | Original | Replacement     |
|--------|----------|-----------------|
| Red    | 27Ω      | 220Ω            |
| White  | 27Ω      | 330Ω            |
| Blue   | 27Ω      | 27Ω (no change) |


### LED Switching

Each module is controlled by a low-side S8050 NPN transistor.
The signal to the base of the transistors is limited with a 10kΩ resistor.
The common cathode of each module connects to the collector.

At least .. that's how I think it should be.

First, the supplied transistors are marked S8050 but there are both
NPN and PNP transistors marked "S8050" in the amrket.
I verified these really are NPN, and the circuit expects an NPN low-side driver.

However all the S8050 NPN transistor datasheets indicate their pin configuration is EBC.
I have some other S8050 transistors which definitely have an EBC pin configuration.

But the PCB has them connected CBE
i.e. either these are placed with C-E reversed, or the kit came with some wierd-ass CBE S8050s.

Note that whether the S8050 is CBE or EBC, they basically work either way.
There are two issues if the transistors are indeed in backwards:

* exceeds the maximum Emitter-base voltage (only 5V according to one datasheet). Perhaps noticeable damage is avoided because of the switching frequency.
* the Collector-Emitter voltage drop is about double when backwards, so LEDs are not being driven as effectively.

**Modification**

I flipped the S8050 transistors so they match the schematic; all working well:

![kit_bjt_mods](./assets/kit_bjt_mods.jpg?raw=true)


### Clock Signal Generator

The clock signal is generated with a standard 555 time astable oscillator.

The 50kΩ trimmer potentiometer allows the frequency to be adjusted from
[1.35 Hz](http://visual555.tardate.com/?mode=astable&r1=2.2&r2=52.2&c=10) to
[21.8 Hz](http://visual555.tardate.com/?mode=astable&r1=2.2&r2=2.2&c=10).

### LED Control

The 555 timer output feeds the clock of the CD4017 Decade Counter/Divider with 10 Decoded Outputs.
Each pulse causes the CD4017BC to sequence its output signal through pins Q0-Q9.
Steering diodes are used to further decode these outputs to drive the 3 LED modules.

The following table summarises the default behaviour. Q1, Q2, and Q3 refer to the three BJT
driver transistors and their corresponding LED module.

| Pulse | Q0 | Q1 | Q2 | Q3 | Q4 | Q5 | Q6 | Q7 | Q8 | Q9 | **Q1** | **Q2** | **Q3** |
|-------|----|----|----|----|----|----|----|----|----|----|--------|--------|--------|
| 0     | 1  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  |  ON    |  -     |  -     |
| 1     | 0  | 1  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  |  -     |  -     |  -     |
| 2     | 0  | 0  | 1  | 0  | 0  | 0  | 0  | 0  | 0  | 0  |  ON    |  -     |  -     |
| 3     | 0  | 0  | 0  | 1  | 0  | 0  | 0  | 0  | 0  | 0  |  -     |  -     |  -     |
| 4     | 0  | 0  | 0  | 0  | 1  | 0  | 0  | 0  | 0  | 0  |  -     |  ON    |  -     |
| 5     | 0  | 0  | 0  | 0  | 0  | 1  | 0  | 0  | 0  | 0  |  -     |  -     |  -     |
| 6     | 0  | 0  | 0  | 0  | 0  | 0  | 1  | 0  | 0  | 0  |  -     |  ON    |  -     |
| 7     | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 1  | 0  | 0  |  -     |  -     |  -     |
| 8     | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 1  | 0  |  ON    |  ON    |  ON    |
| 9     | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 1  |  -     |  -     |  -     |

The LED sequence can be adjusted by altering the steering diode configuration.
This is exactly what Julian Ilett covered in
[Postbag #29: Fun Re-Wiring a 555 and 4017 LED Module](https://www.youtube.com/watch?v=bxyp4Jq8a3Y)

## Construction

![The Schematic](./assets/LEDStrobeKit_schematic.jpg?raw=true)

![The Build](./assets/LEDStrobeKit_build.jpg?raw=true)

## Credits and References
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [CD4017 datasheet](https://www.futurlec.com/4000Series/CD4017.shtml)
* [S8050 Datasheet](http://electronics.se-ed.com/magic/s8050.pdf) - NPN BJT, note there are other S8050 transistor datasheets on the web that purport to be PNP e.g. [S8050 PNP Datasheet](https://www.futurlec.com/Transistors/S8050.shtml)
* [CD4017 + ne555 Strobe module electronics production suite DIY Kits electronic diy Learning suite](https://www.aliexpress.com/item/CD4017-ne555-Strobe-module-electronics-production-suite-DIY-Kits-electronic-diy-Learning-suite/32438304004.html)
* [Postbag #29: Fun Re-Wiring a 555 and 4017 LED Module](https://www.youtube.com/watch?v=bxyp4Jq8a3Y)
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/littlearduinoprojects224-led-strobe-kit.html)
