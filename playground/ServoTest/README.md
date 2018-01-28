# #042 ServoTest

Test the positioning accuracy of a servo motor driven by an Arduino


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I'm testing the control of a TowerPro SG90 9g Micro Servo.
According the the [datasheet](http://datasheet.sparkgo.com.br/SG90Servo.pdf), this has a 180 degree sweep.

ServoTest accepts a range of commands over the serial interface to perform various servo positioning tasks.
See the spash screen when you open the console window for options.

### Cable connections

The three cable connections to the servo are identified as follows:

| Connection | Wire   |
|------------|--------|
| PWM        | orange |
| Vcc        | red    |
| Ground     | brown  |


### Powering the Servo

The servo operates at 4.8V/5V. While you can tap power directly from 5V Arduino pin,
this is not really recommended (especially if more than one servo connected) as the current requirements
can overwhelm the Arduino.

### Performance

First up, the servo is pretty zippy.

But as can be seen in the chart below, the default positioning using the Servo library with this specific servo is a bit off.
Specifically:
* The full sweep is accurate - very close to 180 degrees.
* When positioning at 0 or 180, it overshoots by 5 degrees or so before rebounding to the correct position. It doesn't have this behaviour for intermediate settings. Curious.
* The step positioning between 0 and 180 under by about 15 degrees e.g. the request top position at 45 degrees results in an actual position of about 30 degrees.
* I tried a few different SG90 units, and the all exhibit similar but not exactly identical behaviour.

Here is my little positioning chart:

![Performance](./assets/SG90_default_positioning_accuracy.jpg?raw=true)

I suspect the positioning accurcy may be largely fixed by tuning the Servo pulse width settings. TODO: that's an investigation for another day..

### Performance - Refined

So I came back to the issue of accuracy, with some interesting findings:

* for the particular servo in hand, the min/max pulse widths needed some modification. Using `myservo.attach(SERVO_PIN,600,2320);` gives a much high degree of accuracy fo 0-180 degree sweep than with the default settings (544/2400).
* the servo appear quite sensitive to power. If a battery is running out of juice, will start to get trembling in the positioning.

## Construction

![The Breadboard](./assets/ServoTest_bb.jpg?raw=true)

![The Schematic](./assets/ServoTest_schematic.jpg?raw=true)

![The Build](./assets/ServoTest_build.jpg?raw=true)

## Credits and references
* [TowerPro SG90 datasheet](http://datasheet.sparkgo.com.br/SG90Servo.pdf) - 9g Micro Servo
* [Servo library reference](http://arduino.cc/en/Reference/Servo)
* Based on the [Arduino Sweep example](http://arduino.cc/en/Tutorial/Sweep)
