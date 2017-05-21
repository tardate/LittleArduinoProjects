# #302 TheMatrix/GameOfLife

A simple implementation of Conway's Game of Life on the Boldport Club Matrix.

Here's a quick video showing it in action..

[![Build](./assets/GameOfLife_cover.jpg?raw=true)](http://www.youtube.com/watch?v=xJM7nuiDj8w)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

This is a quick and dirty implementation of
[Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) on the
[Boldport Matrix](../TheMatrix), mainly to learn a bit more about using the AS1130 LED driver.

I'm using a [Boldport Cuttle](../../TheCuttle) as the controller (Arduino compatible).

## Game Play

I'm using the classic rules and a random seed:

* Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
* Any live cell with two or three live neighbours lives on to the next generation.
* Any live cell with more than three live neighbours dies, as if by overpopulation.
* Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

If all cells die, the game automatically restarts.

If the game reaches a still life or oscillating endpoint, it will just carry on and needs a reboot to restart!

## Algorithms

[GameOfLife.ino](./GameOfLife.ino) uses the `AS1130Picture24x5` class from the [LRAS1130 library](https://github.com/LuckyResistor/LRAS1130)
to represent to frames: the current "tick" (round) of the game, and the next one.

Processing a game round evaluates the cells in the current `AS1130Picture24x5` page,
and writes the next stage of life to the next `AS1130Picture24x5` page.
The AS1130 driver is asked to switch pages on the Matrix display and then the process repeats.

It is a pretty naïve implementation of the game, and certainly not optimised.
It spends a lot of time reading pixels from a `AS1130Picture24x5` page, and each time that involves
decoding the "virtual" LED/cell address into the page address.

But as it is, it runs perfectly fast enough - I even needed a delay between each game round to keep things at human speed!

## Construction

![Breadboard](./assets/GameOfLife_bb.jpg?raw=true)

![Schematic](./assets/GameOfLife_schematic.jpg?raw=true)

![Build](./assets/GameOfLife_build.jpg?raw=true)

## Credits and References
* [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) - wikipedia
* [AS1130 datasheet and info](ams.com/eng/Products/Power-Management/LED-Drivers/AS1130)
* [LuckyResistor/LRAS1130](https://github.com/LuckyResistor/LRAS1130) - A library to control the AS1130 LED driver chip.
* [LEAP#299 TheMatrix](../TheMatrix)
* [..as mentioned on my blog](http://blog.tardate.com/2017/05/leap302-game-of-life-on-the-boldport-club-matrix.html)
