# #059 Breadboard 5V Regulated Power Supply

An LM7805-based 5V regulated power supply for use in breadboard projects.

## Notes

See [LM7805 5V Regulated Supply](../Power7805) for a more detailed investigation of the 7805 voltage regulator.

The LM7805 provides regulated 5V, ideal when current requirements are moderate (up to 1A with heatsink).

This project puts a 5V regulated supply on a protoboard that is designed to plug into a standard breadboard with power rails.

It includes high and low frequency smoothing capacitors, and a master power switch and LED power indicator.

The LED indicator is provided on the regulated supply-side.
The 3mm green LED has a forward voltage drop of about 2.2V, so a 1kΩ current-limiting resistor was selected to
keep current draw approx [2.8mA](http://www.wolframalpha.com/input/?i=%285V+-+2.2V%29%2F1k%CE%A9).

Given that commercial units can be obtained for
[as low as 0.80USD](http://www.aliexpress.com/item/1PC-New-Breadboard-Power-Supply-Module-3-3V-5V-MB102-Solderless-Bread-Board-DIY-A3080-Free/32213993524.html) (with free shipping!),
I'm not sure if I saved any money. But it is more satisfying this way;-)

### Construction

![The Breadboard](./assets/PowerBreadboard5V_bb.jpg?raw=true)

![The Schematic](./assets/PowerBreadboard5V_schematic.jpg?raw=true)

![The Build](./assets/PowerBreadboard5V_build.jpg?raw=true)

![Protoboard layout Build](./assets/PowerBreadboard5V_pcb.jpg?raw=true)

## Credits and References
* [LM7805 datasheet](http://www.futurlec.com/Linear/7805T.shtml) - 5v regulator. Note that other chips in the LM78xx range are available to provide other voltages.
* [LM7805 5V Regulated Supply](../Power7805) - related LittleArduinoProjects experiment testing the 7805
* [MB102 3.3/5V Breadboard Supply](../PowerMB102) - testing a commercial power supply unit
