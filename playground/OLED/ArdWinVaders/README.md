# #100 OLED/ArdWinVaders

An Arduino & OLED version of a classic game.

Here's a quick video of the game in action:

[![ArdWinVaders](http://img.youtube.com/vi/GBX0n_YXXcs/0.jpg)](http://www.youtube.com/watch?v=GBX0n_YXXcs)

Or [see this earlier video](http://youtu.be/m0XgdGztr8s) before the screen optimisations or sound. There's a huge performance difference!


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

Since playing around with driving an OLED with an Arduino (see the [SSD1306BareBack](../SSD1306BareBack) project for example),
it doesn't take long for the mind to wander into gaming territory...

So here's the first version of a retro classic: Space Invaders in full 128x64 mono resolution running on an Arduino Pro Mini at 8MHz!

For details and discussion of the hardware setup, see the [SSD1306BareBack](../SSD1306BareBack) project.
This build is mainly about the software.

The software is organised into a number of classes. You can see the code for more details, but here is the overview:
* ArdWinVaders.ino - main program, also handles all the controls input (fire, movement)
* game_board.h/cpp - implements the main game controller class, responsible for orchestrating actions and sequencing gameplay
* buffered_display.h/cpp - implements a logical display interface that GameBoard talks to. It maintains the screen buffer and handles movement, collision detection and so on.
* oled_driver.h/cpp - implements the OLED-specific display driver. It goes direct to the hardware via SPI.
* sound_system.h/cpp - music and sound effects support.

Game performance/screen refresh is pretty awesome even with the processor at 8Mhz. The big improvement came from switching to direct port manipulation
for SPI rather than using the standard library methods (digitalWrite, shiftOut).

### TODO
* put it in a hand-held form-factor

## Construction

![The Breadboard](./assets/ArdWinVaders_bb.jpg?raw=true)

![The Schematic](./assets/ArdWinVaders_schematic.jpg?raw=true)

![The Build](./assets/ArdWinVaders_build.jpg?raw=true)

## Credits and References
* [SSD1306 datasheet](https://www.adafruit.com/datasheets/SSD1306.pdf)
* [SSD1306BareBack](../SSD1306BareBack) - a sketch the exlores and explains OLED driving basics
* [Arduino Port Registers](https://www.arduino.cc/en/Reference/PortManipulation) - all the info needed for direct port manipulation
* [..as mentioned on my blog](https://blog.tardate.com/2015/06/retrogaming-on-arduinooled-console.html)
