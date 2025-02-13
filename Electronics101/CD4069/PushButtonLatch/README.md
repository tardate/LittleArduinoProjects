# #761 Inverter-based Push Button Latch

A latching pushbutton circuit using a CMOS inverter (CD4069).

![Build](./assets/PushButtonLatch_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/E-EettivcgY/0.jpg)](https://www.youtube.com/watch?v=E-EettivcgY)

## Notes

Latching push-button circuits are useful in any situation where one needs to toggle an electronic circuit between two states based on a pushbutton input.

There are many ways to achieve this. In the past I have covered:

* a 555 Timer based circuit, see [LEAP#692](https://leap.tardate.com/electronics101/555timer/latch/)
* an Arduino based solution, see [LEAP#004](https://leap.tardate.com/playground/pushbuttonled/)

A [discussions with steveschnepp](https://github.com/tardate/LittleArduinoProjects/issues/36) introduced me to an inverter-based solution. It has a number of benefits:

* very low quiescent power usage (<=1mA at 3V)
* cheap BoM (compared to an Arduino)

### Circuit Design

The basic concept is to use a push-button to toggle a chain of inverters,
where different stages of the inverter provide the "on" and "off" states.

To ensure the pushbutton provides a stable, de-bounced input:

* `R3` ensures the input to the inverter is pulled high or low to match the current `Q` output
* `SW` will be "charged" to "high" via R5,R6,C2
* when pressed, `SW1` will generate a pulse via the C1, R4 differentiator

The circuit and resistor values are scaled to work well between 3V and 9V. It could be used at higher voltages, but some values (like LED resistors) should be reviewed.

Note:

* unused inverter circuits are pulled low to a definite state (tbh, I can't remember whether the CD4069 needs this care and attention to void oscillating states, but there is no harm doing it)
* this circuit does not need a specific inverter chip, or Schmitt trigger inputs. I just used the CD4069 because I had one on hand.

![bb](./assets/PushButtonLatch_bb.jpg?raw=true)

![schematic](./assets/PushButtonLatch_schematic.jpg?raw=true)

![bb_build](./assets/PushButtonLatch_bb_build.jpg?raw=true)

## Credits and References

* [CD4069 datasheet](https://www.futurlec.com/4000Series/CD4069.shtml)
* [Push button latch circuit - switch issue](https://electronics.stackexchange.com/questions/651202/push-button-latch-circuit-switch-issue)
* [Pushbutton switch discussions - steveschnepp](https://github.com/tardate/LittleArduinoProjects/issues/36)
