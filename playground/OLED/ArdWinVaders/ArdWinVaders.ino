/*

  OLED/ArdWinVaders
  An Arduino & OLED version of a classic.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/OLED/ArdWinVaders

 */

#include <FlexiTimer2.h>

//** control pins
#define FIRE_PIN 2
#define FIRE_INTERRUPT 0
#define LEFT_PIN 3
#define RIGHT_PIN 4

volatile int fireStatus = 0;
volatile int moveLeft = 0;
volatile int moveRight = 0;

//** display pin connections
#define MOSI_PIN 9
#define CLK_PIN 10
#define DC_PIN 11
#define CS_PIN 12

#include "oled_driver.h"
#include "buffered_display.h"
#include "game_board.h"

OledDriver displayDriver(MOSI_PIN,CLK_PIN,DC_PIN,CS_PIN);
BufferedDisplay gameDisplay(&displayDriver);
GameBoard gameBoard(&gameDisplay);

void setup() {
  gameDisplay.init();
  gameBoard.init();

  pinMode(LEFT_PIN, INPUT);
  pinMode(RIGHT_PIN, INPUT);
  FlexiTimer2::set(20, sampleMovement);
  FlexiTimer2::start();

  pinMode(FIRE_PIN, INPUT);
  attachInterrupt(FIRE_INTERRUPT, handleFireButtonPress, RISING);
}

void loop() {
  if(moveLeft) gameBoard.moveLeft();
  if(moveRight) gameBoard.moveRight();
  if(fireStatus) {
    gameBoard.fire();
    fireStatus = 0;
  }
  gameBoard.recalc();
  gameDisplay.redraw();
}

void sampleMovement() {
  moveLeft = digitalRead(LEFT_PIN);
  moveRight = digitalRead(RIGHT_PIN);
}

void handleFireButtonPress() {
  fireStatus = 1;
}

/*

game phases
  if fire button
    fire
    add missile to board
  if position input
    recalc fire base position
  recalc alien ships positions
  recalc missile positions
  collision detect
  draw ships
  draw missiles
  draw firebase
  update display

async:
  accept fire input
  accept movement input
  play sound



*/
