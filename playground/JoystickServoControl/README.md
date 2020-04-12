# #056 JoystickServoControl

Control two SG90 servos with a joystick. Here's a quick demo:

[![JoystickServoControl](https://img.youtube.com/vi/P8883DkE3Jo/0.jpg)](https://www.youtube.com/watch?v=P8883DkE3Jo)


## Notes

This is a demonstration of joystick control of two servos. This would be how you could setup pan/tilt control for example.

It's a simple circuit:

* two digital pins are used for PWM control signals to the servos.
* two analog pins are used to read the X-Y joystick input

A separate power supply is used for the servo motors to ensure they get enough current and to avoid interference.

I'm using custom pulse width settings that I've found suit my particular servos best to give accurate 0-180 degree control.
See the [ServoTest](../ServoTest) project for more exploration of servo control and fine-tuning servo parameters.

## Construction

![The Breadboard](./assets/JoystickServoControl_bb.jpg?raw=true)

![The Schematic](./assets/JoystickServoControl_schematic.jpg?raw=true)

![The Build](./assets/JoystickServoControl_build.jpg?raw=true)

## Credits and References

* [TowerPro SG90 datasheet](http://datasheet.sparkgo.com.br/SG90Servo.pdf) - 9g Micro Servo
* [Servo library reference](http://arduino.cc/en/Reference/Servo)
