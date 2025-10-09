# #060 5V Breadboard Regulator

An LM7805 5V regulated power supply on breadboard-compatible protoboard.

![Breadboard5V_build](./assets/Breadboard5V_build.jpg?raw=true)

## Notes

See [LM7805 5V Regulated Supply](../LinearRegulators/LM7805) for a more detailed investigation of the 7805 voltage regulator.

The LM7805 provides regulated 5V, ideal when current requirements are moderate (up to 1A with heatsink).

This project puts a 5V regulated supply on a protoboard that is designed to plug into a standard breadboard with power rails.

It includes high and low frequency smoothing capacitors, and a master power switch and LED power indicator.

The LED indicator is provided on the regulated supply-side.
The 3mm green LED has a forward voltage drop of about 2.2V, so a 1kΩ current-limiting resistor was selected to
keep current draw approx [2.8mA](https://www.wolframalpha.com/input/?i=%285V+-+2.2V%29%2F1k%CE%A9).

Given that commercial units can be obtained for
[as low as 0.80USD](https://www.aliexpress.com/item/1PC-New-Breadboard-Power-Supply-Module-3-3V-5V-MB102-Solderless-Bread-Board-DIY-A3080-Free/32213993524.html) (with free shipping!),
I'm not sure if I saved any money. But it is more satisfying this way;-)

### Construction

![Breadboard5V_bb](./assets/Breadboard5V_bb.jpg?raw=true)

![Breadboard5V_schematic](./assets/Breadboard5V_schematic.jpg?raw=true)

Sketching a protoboard layout that would work:

![Protoboard layout Build](./assets/Breadboard5V_pcb.jpg?raw=true)

Testing - within a few mV of 5V as expected:

![Breadboard5V_test](./assets/Breadboard5V_test.jpg?raw=true)

## Credits and References

* [LM7805 datasheet](https://www.futurlec.com/Linear/7805T.shtml) - 5v regulator. Note that other chips in the LM78xx range are available to provide other voltages.
* [LEAP#027 LM7805 5V Regulated Supply](../LinearRegulators/LM7805) - related experiment testing the 7805
* [LEAP#028 MB102 3.3/5V Breadboard Supply](../MB102BreadboardPowerSupply/) - testing a commercial power supply unit
