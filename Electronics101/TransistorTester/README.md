# #083 TransistorTester

Use an Arduino to test NPN and PNP BJTs.

Here's a quick video of the circuit in action:

[![TransistorTester demo](https://img.youtube.com/vi/LyhCdzWy1SI/0.jpg)](https://www.youtube.com/watch?v=LyhCdzWy1SI)


## Notes

A bipolar junction transistor (BJT) can be considered a back-to-back pair of diodes.
* NPN have the common anode on the base
* PNP have the common cathode on the base

Given this arrangement, one technique for testing BJTs is to measure the forward voltage between Base-Emitter and Base-Collector.
* if positive forward voltage is found from Base to Emitter and Base to Collector, we assume a properly functioning NPN
* if positive forward voltage is found from Emitter to Base and Collector to Base, we assume a properly functioning PNP
* the forward voltage will be around 0.7V for silicon transistors

The Arduino sketch periodically probes the transistor test pad. This invovles checking the various possible
forward voltage combinations and recording the results. From this it concludes:
* if a functioning transistor is currently on the test pad
* whether the transistor is NPN or PNP
* the forward voltage in mV

Once we have that information, we just need a way to display it.
In the first version of the sketch, it was simply written to the serial out.
The current version uses a 16x2 LCD to display the results.

The "test pad" is the three sockets into which a transistor is plugged for testing.
The sketch currently requires that the transistor base be plugged into the designated socket.
It does not matter which way around the emitter and collector pins are plugged in.

Some limitations and things to improve:
* it doesn't do a very rigorous check of the transistor at present
* it could test regardless of pin arrangement and determine B-C-E configuration
* it could/should report Vce(sat) rather than the forward voltage
* it would be nice if it also measured β/hFE

## Construction

![The Breadboard](./assets/TransistorTester_bb.jpg?raw=true)

![The Schematic](./assets/TransistorTester_schematic.jpg?raw=true)

![The Build](./assets/TransistorTester_build.jpg?raw=true)

## Credits and References
* [Meter check of a diode - All About Circuits](http://www.allaboutcircuits.com/vol_3/chpt_3/2.html)
* [How to test a diode - Circuits Today](http://www.circuitstoday.com/how-to-test-a-diode)
* [Testing Transistors](http://www.learnabout-electronics.org/transistor_faults_04.php)
