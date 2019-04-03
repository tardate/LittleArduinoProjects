# #199 LED7Segment/CD4026BucketBrigade

A CD4026 bucket-brigade for driving multiple 7-segment displays

Here's a quick video of the circuit in action:

[![LED7Segment/CD4026BucketBrigade](https://img.youtube.com/vi/-gfQWZTg-N8/0.jpg)](https://www.youtube.com/watch?v=-gfQWZTg-N8)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The [CD4026Drive](../CD4026Drive) project explored the CD4026 as an easy way to drive a 7-segment display.
This project simply extends the idea for driving multiple digits.

It just requires the carry-out from the first CD4026 to be chained as the clock input for the second.
Here I've wired up two digits, but can be replicated for any number of digits.

A second GPIO pin is used to control the reset.

Note that in my breadboard build, I cheated on the current-limiting resistors: placing a single 220Ω on each LED digit cathode
rather than a 220Ω on each segment anode as per the schematic. Using a single anode resistor works fine - the downside
being that segment brightness will consequently vary to a degree depending on how many segments are on.

## Construction

![Breadboard](./assets/CD4026BucketBrigade_bb.jpg?raw=true)

![The Schematic](./assets/CD4026BucketBrigade_schematic.jpg?raw=true)

![The Build](./assets/CD4026BucketBrigade_build.jpg?raw=true)

## Credits and References
* [CD4026 Datasheet](https://www.futurlec.com/4000Series/CD4026.shtml)
* [ST HCF4026B Datasheet](http://www.digchip.com/datasheets/parts/datasheet/456/HCF4026-pdf.php) - closest I could find to the actual chip I have. Functionally identical to the CD4026.
* [SC56-11 Datasheet](../assets/SC56-11_datasheet.pdf?raw=true)
* [2 Digit Simple digital counter circuit using CD4026](http://www.eleccircuit.com/simple-two-digits-counter-using-cd4026/)
* [..as mentioned on my blog](https://blog.tardate.com/2016/04/littlearduinoprojects199-cd4026-bucket.html)
