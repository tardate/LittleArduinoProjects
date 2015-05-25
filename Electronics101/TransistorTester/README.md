# TransistorTester

Use an Arduino to test NPN and PNP BJTs.

## Notes

A bipolar junction transistor (BJT) can be considered a back-to-back pair of diodes.
* NPN have the common anode on the base
* PNP have the common cathode on the base

Given this arrangement, one technique for testing BJTs is to measure the forward voltage between Base-Emitter and Base-Collector.
* if small positive forward voltage is found from Base to Emitter and Base to Collector, we can assume a properly functioning NPN
* if small positive forward voltage is found from Emitter to Base and Collector to Base, we can assume a properly functioning PNP

### Construction

![The Breadboard](./assets/TransistorTester_bb.jpg?raw=true)

![The Schematic](./assets/TransistorTester_schematic.jpg?raw=true)

![The Build](./assets/TransistorTester_build.jpg?raw=true)

## Credits and References
* [Meter check of a diode - All About Circuits](http://www.allaboutcircuits.com/vol_3/chpt_3/2.html)
* [How to test a diode - Circuits Today](http://www.circuitstoday.com/how-to-test-a-diode)
* [Testing Transistors](http://www.learnabout-electronics.org/transistor_faults_04.php)
