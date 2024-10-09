# #476 Rakit Drum Synth

Building the Rakit Drum Synth kit - a very nicely produced clone of the classic Boss PC-2/AMDEK PCK-100 percussion synthesizer.

![Build](./assets/RakitDrumSynth_build.jpg?raw=true)

## Notes

I just had some fun building the Rakit Drum Synth kit.
It's a very well produced kit that recreates the classic Boss PC-2/AMDEK PCK-100 percussion synthesizer,
staying very true to the original design and components.

Here's the demo from Rakit:

[![clip](https://img.youtube.com/vi/m6eRdDSn84I/0.jpg)](https://www.youtube.com/watch?v=m6eRdDSn84I)

## Circuit Design

The Rakit Drum Synth is based on the classic Boss PC-2/AMDEK PCK-100 percussion synthesizer, with mods:

* Attack on/off
* VCO & LFO wave shape selection
* Pitch CV input

In layout and parts selection it is very close to this old AMDEK PCK-100 schematic:

[![amdek_pck-100_schematic](./assets/amdek_pck-100_schematic.gif?raw=true)](http://www.synthdiy.com/show/tags.asp?tag=schematics)

The design uses a number of legendary parts that are interesting in themselves including the: the JRC4558 JFET opamp,
and Rohm BA6110 voltage controlled op-amp in an unusual SIP-9 package. These parts are common in
many famous products from guitar pedals to synths. Whether these parts are "key" to the sound is a matter of great debate;-)

I discovered interesting attempts to recreate the (now largely unobtainium) BA6110,
including this [PCB design on OSHPark](https://oshpark.com/shared_projects/QCnNP4oK).

## Parts

| Component                                | Qty | Checked & Installed |
|------------------------------------------|-----|---------------------|
| 3.5mm Mono Socket                        | 3   | √                   |
| A100k Log Potentiometer                  | 4   | √                   |
| B504 500k Linear Potentiometer           | 1   | √                   |
| B102 1k0 Linear Potentiometer            | 1   | √                   |
| 50k Trim potentiometer                   | 2   | √                   |
| 2.1mm/5.5mm Barrel Power Socket          | 1   | √                   |
| Right Angle SPST Slide Switch            | 2   | √                   |
| Horizontal DPDT Slide Switch             | 3   | √                   |
| 1n0 Box Capacitor                        | 4   | √                   |
| 3n3 Box Capacitor                        | 1   | √                   |
| 22n Box Capacitor                        | 1   | √                   |
| 47n Box Capacitor                        | 3   | √                   |
| 390R 0.6W 1% Resistor                    | 1   | √                   |
| 1k0 0.6W 1% Resistor                     | 5   | √                   |
| 4k7 0.6W 1% Resistor                     | 4   | √                   |
| 10k 0.6W 1% Resistor                     | 5   | √                   |
| 22k 0.6W 1% Resistor                     | 4   | √                   |
| 33k 0.6W 1% Resistor                     | 2   | √                   |
| 47k 0.6W 1% Resistor                     | 12  | √                   |
| 56k 0.6W 1% Resistor                     | 1   | √                   |
| 100k 0.6W 1% Resistor                    | 11  | √                   |
| 220k 0.6W 1% Resistor                    | 2   | √                   |
| 1M0 0.6W 1% Resistor                     | 1   | √                   |
| 4M7 0.6W 1% Resistor                     | 1   | √                   |
| OTA IC BA6110                            | 1   | √                   |
| Op Amp 4558 IC                           | 1   | √                   |
| Op Amp 358/2904 IC                       | 3   | √                   |
| 3mm Blue LED                             | 2   | √                   |
| Signal Diode 1N4148                      | 3   | √                   |
| Schottky diode IN5819                    | 1   | √                   |
| 2N3904 NPN Transistor                    | 2   | √                   |
| 2N3906 PNP Transistor                    | 2   | √                   |
| 2SC945P NPN Transistor                   | 2   | √                   |
| 1u0 Electrolytic Capacitor               | 3   | √                   |
| 10u Electrolytic Capacitor               | 2   | √                   |
| 100u Electrolytic Capacitor              | 1   | √                   |
| PCB – Top, Inside, Left Wing, Right Wing | 4   | √                   |
| Battery Snap to Barrel                   | 1   | √                   |
| Rubber Tube                              | 4   | √                   |


![kit_parts](./assets/kit_parts.jpg?raw=true)

## Construction

Rakit have a very clear [assembly guide online](https://www.rakits.co.uk/assembly-guides/drum-synth/).
Recommended build sequence:

* IC’s
* transistors
* diodes
* electrolytic capacitors
* LEDs
* resistors (all vertically mounted)
* Trimmers
* box capacitors (not polarised)
* slide switches
* 3.5mm mono sockets
* piezo disc wires
* potentiometers and switches
* rubber feet

My only embellishment on the procedure was to go for Boldport-style solder domes with my favourite 2% Ag solder;-)

Fitting the all the semi-conductors and electrolytic capacitors..

![build_step_1](./assets/build_step_1.jpg?raw=true)

With remaining caps,resistors, slide switches and sockets..

![build_step_2](./assets/build_step_2.jpg?raw=true)

Attaching the piezo pad:

![build_step_3a](./assets/build_step_3a.jpg?raw=true)

And seating the pots and top-panel switches..

![build_step_3b](./assets/build_step_3b.jpg?raw=true)

All finished! Rear view..

![build_step_4a](./assets/build_step_4a.jpg?raw=true)

And from the top..

![build_step_4c](./assets/build_step_4c.jpg?raw=true)

Here's a quick demo.. just mucking around trying to discover the range of sounds it can produce:

[![clip](https://img.youtube.com/vi/AXDuCx-s4Lo/0.jpg)](https://www.youtube.com/watch?v=AXDuCx-s4Lo)

## Credits and References

* [Drum Synth Assembly Guide](https://www.rakits.co.uk/assembly-guides/drum-synth/)
* [LM2904N](https://www.futurlec.com/Linear/LM2904N.shtml)
* [JRC4558 analysis](https://www.electrosmash.com/jrc4558-analysis)
* [2SC945 info](https://components101.com/transistors/2sc945-bipolar-npn-transistor)
* [Comparing BA662A and BA6110 vca chips in the x0xb0x](http://www.synthdiy.com/show/link/?id=2274)
* [BA662 Clone with DC offset Trimmer](https://oshpark.com/shared_projects/QCnNP4oK) - oshpark
