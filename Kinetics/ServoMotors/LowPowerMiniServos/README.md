# #601 Low Power Mini Servos

Testing a few low power mini servo motors with an Arduino and MOSFET level shifter.

![Build](./assets/LowPowerMiniServos_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/MunymlUziEs/0.jpg)](https://www.youtube.com/watch?v=MunymlUziEs)

## Notes

So-called low power / mini servos are generally designed to work from lithium battery packs in RC vehicles - so voltages in the 3.7 to 4.2V range.
I have a few of these servos, and the notes that follow document some quick tests using an Arduino Uno as a driver.

### 2.2g Mini Digital Servo

Available from [shopee.sg](https://shopee.sg/Low-Voltage-2.2g-Digital-Steering-Gear-Servo-Coreless-For-RC-Crawler-Model-Car-Ready-Stock--i.360726180.8991019964), aliexpress and other sources.

| Item                     | Specification                                         |
|--------------------------|-------------------------------------------------------|
| No-Load Velocity         | 3.7V: 0.07 ± 0.01 sec/60˚ , 4.2V: 0.06 ± 0.01 sec/60˚ |
| No-load current          | 3.7V: 60 ± 15mA           , 4.2V: 65 ± 15mA           |
| Stop Torsion             | 3.7V: 95g.cm              , 4.2V: 110g.cm             |
| Stop Current             | 3.7V: 210 ± 30mA          , 4.2V: 310 ± 30mA          |
| Standby Current          | 3.7V: 2 ± 1mA             , 4.2V: 2 ± 1mA             |
| No-load life             | 3.7V: >6000 times         , 4.2V: >4000 times         |
| Limit angle of mechanism | 180˚ ± 10˚                                            |
| Weight                   | 2.2 ± 0.2g                                            |
| Wire Length              | 110 ± 5 mm                                            |
| Size                     | 20mm x 16mm x 8mm / 0.78in x0.62in x 0.31in           |

![2.2g_mini_servo](./assets/2.2g_mini_servo.jpg?raw=true)

In practice, the servos I got worked smoothly from ~3.5V

### 1.7G Mini Digital Servo

Available from [shopee.sg](https://shopee.sg/Hot-%E3%80%90IN-STOCK%E3%80%91T-power-1.7G-Low-Voltage-Digital-Servo-JST-Connector-KIT-RC-Mini-Car-Drone-i.340360558.8423268127), aliexpress and other sources.

| Item              | Specification |
|-------------------|----------------|
| Brand             | T-power                                       |
| Operating voltage | 2.8V-4.2V (No more than 4.2 V, or be damaged) |
| Operating speed   | 0.06s/60°2.8V, 0.05s/60°3.7V                  |
| Torque value      | 0.06Kg/2.5V, 0.075Kg/3.7V                     |
| Gear type         | plastic                                       |
| Connector         | mini JST                                      |
| line length       | 10cm                                          |
| Size              | 20*20*6mm                                     |
| Weight            | 1.7g                                          |

![1.7g_mini_servo](./assets/1.7g_mini_servo.jpg?raw=true)

In practice, the servo I got seemed to need at least 4V to rotate smoothly.

## Construction

Since the Arduino runs at 5V, the PWM control signal is put through a MOSFET level shifter to prevent damage to the servo.
NB: I suspect the servo control pin is probably 5V tolerant, but I've not put that theory to the test!

The servos are also separately powered from a bench power supply - I varied the voltage to test the impact on performance.

![Breadboard](./assets/LowPowerMiniServos_bb.jpg?raw=true)

![Schematic](./assets/LowPowerMiniServos_schematic.jpg?raw=true)

## Credits and References

* [Low Voltage 2.2g Digital Steering Gear Servo Coreless For RC Crawler Model Car](https://shopee.sg/Low-Voltage-2.2g-Digital-Steering-Gear-Servo-Coreless-For-RC-Crawler-Model-Car-Ready-Stock--i.360726180.8991019964) - shopee
* [T-power 1.7G Low Voltage Digital Servo JST Connector KIT RC Mini Car Drone](https://shopee.sg/Hot-%E3%80%90IN-STOCK%E3%80%91T-power-1.7G-Low-Voltage-Digital-Servo-JST-Connector-KIT-RC-Mini-Car-Drone-i.340360558.8423268127) - shopee
* [Servo library reference](https://www.arduino.cc/reference/en/libraries/servo/)
