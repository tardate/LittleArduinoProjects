# #500 RFID Concentration Game

Play a game of Concentration/Pairs with a stack of MIFARE Classic cards.

![Build](./assets/Concentration_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/e0_bCd3ZnEI/0.jpg)](https://www.youtube.com/watch?v=e0_bCd3ZnEI)

## Notes

You may have played [Concentration](https://en.wikipedia.org/wiki/Concentration_(card_game)) - the simple card game where
the objective is to pickup as many matching pairs of cards as possible.

I have a stack of RFID cards that I got with a reader, so attempting a version of Concentration was the first and most obvious thing that popped into my head!

## Gameplay Design

I decided to keep the interaction as simple as possible, and in particular avoid the need for a text display unit,
so I designed the game-play around:

* an 8x8 matrix to display the card identity and flash various effects
* a buzzer and LEDs for feedback
* and the cards themselves for all input

Feedback states:

| Name               | Buzzer     | Red      | Green      | Yellow     | Meaning..                              |
|--------------------|------------|----------|------------|------------|----------------------------------------|
| gameRunning        | off        | off      | off        | Fast Flash | in game mode, waiting for a card..     |
| initializing       | off        | Flashing | Flashing   | Flashing   | in card initialisation mode            |
| CardInitialized    | Beep       | off      | ON         | Flashing   | card initialized, ready for a new one  |
| CardInitializeFail | Beep       | ON       | off        | Flash ON   | card initialize failed                 |
| cardAccepted       | Beep       | off      | Flashing   | off        | first card accepted, present another.. |
| cardMatch          | Happy Beep | off      | ON         | off        | second card match. Win!                |
| cardMismatch       | Sad beep   | Flash ON | off        | off        | second card mis-match. Fail!           |


The Doxygen documentation for the code is [available here](./doc/html/index.html).

### Setup

The RFID cards need to be initialized before they can be used.

After power-on:

* if a recognised card is scanned, we assume you're starting a game using the card set retrieved from EEPROM.
* if an unrecognised card is scanned, we assume you're setting up a new stack of cards:
    * the card set is initialised
    * the card is added to a new card set in memory (grouped into pairs), and the card ID is written back to the card
    * positive feedback (a "good" beep and green LED)
    * keeps initialising any other cards that are presented until max card limit reached, or an already-initialised card is presented (which triggers game mode)

### Game Mode

* after first card is presented, provides a neutral beep and red/green LEDs flash
* when a second card is presented:
    * if it matches, plays a happy tune and green LED is on
    * if it does not match, plays a sad tune and red LED is on
* game is over when all pairs have been successfully matched

Note:

* it won't bother to warn on repeated presentations of the same pairs - assume players are policing the rules themselves!
* there's no score-keeping, that's up to players, as it doesn't know who or how many players are in the game


## Card Data

For simplicity, uses value blocks for a game ID and card ID.

Data is stored in sector 1. That is, block 4 to block 7:

* block 4: the game ID value block
* block 5: the card ID value block
* block 6: unused
* block 7: sector trailer

Each card is given a sequential number starting from 1. Pairs are the adjacent cards i.e. 1+2, 3+4 etc.
That's not random, as it assumes the players will use the age old technique of shuffling the cards before starting the game.


## Circuit Design and Breadboard Prototype

Power: the MFRC522 is 3.3V device, and officially tolerant up to around 4V.
So, running it with the 5V Uno is not strictly legit. Power is supplied
correctly at 3.3V, but data lines will stray up to 5V. I haven't included level shifters.
But it does seem to work, as many have proven before, though I wouldn't do it this way
for anything requiring long term reliability.

![Concentration_bb](./assets/Concentration_bb.jpg?raw=true)

![Concentration_schematic](./assets/Concentration_schematic.jpg?raw=true)

![Concentration_bb_test](./assets/Concentration_bb_test.jpg?raw=true)


## Final Build

Some decisions for the final build:

* I replaced the 3 LEDs with the [LEAP#269 Boldport Cordwood](../../../BoldportClub/cordwood) for the final build (because it's purdy).
* stuck with an Arduino Uno as the base board (as it has the 3.3V and 5V supply already taken care of)
* still left out the level shifters for the MFRC522 data lines. So far, so good (fingers crossed)


The Boldport Cordwood gets some copper wiring so it can stand proud:

![build_cordwood](./assets/build_cordwood.jpg?raw=true)

Wiring and testing the modules before mounting:

![build_wiring](./assets/build_wiring.jpg?raw=true)

I used some balsa wood with a clear varnish for the custom case. Mounting the modules:

![build_mounting_modules](./assets/build_mounting_modules.jpg?raw=true)

The final build in action:

![Build](./assets/Concentration_build.jpg?raw=true)

## Credits and References

* [The project on hackady.io](https://hackaday.io/project/168029-rfid-concentration-game)
* [Concentration](https://en.wikipedia.org/wiki/Concentration_(card_game)) - the card game
* [tone function](https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/) - Standard library
* [LEAP#269 Boldport Cordwood](../../../BoldportClub/cordwood)
* [RFID module RC522 Kits](https://www.aliexpress.com/item/Free-Shipping-RFID-module-RC522-Kits-S50-13-56-Mhz-6cm-With-Tags-SPI-Write-Read/32523771442.html) - examples from a seller on aliexpress
* [MAX7219 dot matrix module](https://www.aliexpress.com/item/32580532205.html) - example of the 8x8 LED matrix module used in the project
