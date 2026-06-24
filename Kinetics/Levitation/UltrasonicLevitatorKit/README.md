# #xxx Ultrasonic Levitator Kit

description here

![Build](./assets/UltrasonicLevitatorKit_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/video_id/0.jpg)](https://www.youtube.com/watch?v=video_id)

## Notes

### Kit Specification

Features:
1.This is a small ultrasonic suspension device, which can suspend foam balls;
2.The suspending device operates at a frequency of 40KHZ in the air, and can capture light objects with a density of 2-3MM in diameter, such as foam balls, ants and other small objects that are stably suspended in the air for a long time, and the main board is slightly heated;
3.The circuit is mainly composed of a single chip computer, a driver chip and two ultrasonic emitters;
4.It is mainly used to learn about ultrasonic standing wave suspension.
5.It is suitable for students or DIY electronics enthusiasts to learn ultrasonic suspended standing wave.

Parameters:
Power input: DC 12V (0.5-1A)
Frequency: 40KHZ
Working temperature: - 25 ℃~85 ℃
External dimension (finished product): length 44 mm *width 40 mm* height 66 mm
Working principle: ultrasonic standing wave levitation is through the existence of a certain distance (called the resonant cavity distance) between the ultrasonic transmitting end and the transmitting end (or another transmitting end). The transmitted wave and the reflected wave (or another acoustic wave) are continuously superimposed to finally form a standing wave. The acoustic force on the object at the standing wave node overcomes the gravity effect and finally achieves the levitation effect.

### Parts

| Component name                      | Ref | Qty |
|-------------------------------------|-----|-----|
| Upper PCB board                     |     |   1 |
| Lower PCB                           |     |   1 |
| Ultrasonic transmitter 40T          |     |   2 |
| M2 * 4 screw                        |     |   5 |
| M2 * 7 two-way copper column        |     |   2 |
| M2 * 39+3 copper column             |     |   2 |
| M3 * 6 screw                        |     |   5 |
| M3 * 15 two-way nylon column        |     |   4 |
| 100µF 25V                           | C3  |   1 |
| DC005 socket                        |     |   1 |
| 104 Monolithic capacitor            |     |   2 |
| 4.7kΩ resistance                    |     |   1 |
| 3mm LED red                         |     |   1 |
| 1117-5.0 regulator SOT-223          | U1  |   1 |
| STC15F104W (pre-programmed)         | U2  |   1 |
| TC4427 Dual High-Speed Power MOSFET | U3  |   1 |

### Circuit Design

Designed with Fritzing: see [UltrasonicLevitatorKit.fzz](./UltrasonicLevitatorKit.fzz).

![bb](./assets/UltrasonicLevitatorKit_bb.jpg?raw=true)

![schematic](./assets/UltrasonicLevitatorKit_schematic.jpg?raw=true)

![bb_build](./assets/UltrasonicLevitatorKit_bb_build.jpg?raw=true)

### Build Log

![build01a](./assets/build01a.jpg?raw=true)

## Credits and References

* ["DIY Kit Ultrasonic Levitator Suspension Standing Wave Controller DIY Learning Kit Scientific Teaching Experiment Soldering" (aliexpress seller)](https://www.aliexpress.com/item/1005009594026733.html)
    * Purchased for SG$4.96 (Jun-2026)
* [AMS1117 datasheet](http://www.advanced-monolithic.com/pdf/ds1117.pdf)
* [STC15F101W series](https://www.stcmicro.com/stc/stc15f104w.html)
* [TC4427 datasheet](https://ww1.microchip.com/downloads/aemDocuments/documents/APID/ProductDocuments/DataSheets/20001422G.pdf)
