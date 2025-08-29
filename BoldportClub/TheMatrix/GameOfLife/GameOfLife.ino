/*

  TheMatrix/GameOfLife
  A simple implementation of Conway's Game of Life running on the BoldportClub Matrix

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/BoldportClub/TheMatrix/GameOfLife

 */

#include <Wire.h>
#include <LRAS1130.h>

using namespace lr;
AS1130 ledDriver;

AS1130Picture24x5 pages[2]; // two pages for the current and next game round
uint8_t current_page = 0;   // index to the current game round pages

static const uint8_t INITIAL_CELL_COUNT = 50;
static const uint8_t WIDTH = 24; // cheating; = pages[0].getWidth()
static const uint8_t HEIGHT = 5; // cheating; = pages[0].getHeight()

void setup() {
  // Initialize the Wire library.
  Wire.begin();

  // Initialize the serial port.
  Serial.begin(115200);

  // Wait until the chip is ready.
  delay(100);
  Serial.println(F("Initialize chip"));

  // Check if the chip is addressable.
  if (!ledDriver.isChipConnected()) {
    Serial.println(F("Communication problem with chip."));
    Serial.flush();
    return;
  }

  // Set-up everything.
  ledDriver.setRamConfiguration(AS1130::RamConfiguration1);
  ledDriver.setOnOffFrameAllOff(0);
  ledDriver.setBlinkAndPwmSetAll(0);
  ledDriver.setCurrentSource(AS1130::Current30mA);
  ledDriver.setScanLimit(AS1130::ScanLimitFull);
  ledDriver.startPicture(0);

  // Enable the chip
  ledDriver.startChip();

  // kick off the game
  restart();
}

void loop() {
  delay(100);
  if(propagateLife()==0) restart();
}

/*
 * Command: start a new game
 */
void restart() {
  blinkAll();
  seedLife();
}

/*
  Command: seeds up to INITIAL_CELL_COUNT live cells at random locations on a new page.
  NB: does not eliminate duplicates
 */
void seedLife() {
  randomSeed(analogRead(0));
  for (uint8_t i=0; i<INITIAL_CELL_COUNT; ++i) {
    uint8_t x = random(WIDTH);
    uint8_t y = random(HEIGHT);
    pages[current_page].setPixel(x, y, true);
  }
  ledDriver.setOnOffFrame(0, pages[current_page]);
}

/*
  Command: Applies the rules of the game and flips to new page.
  Returns 0 if there are no cells alive at the end.

  Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
  Any live cell with two or three live neighbours lives on to the next generation.
  Any live cell with more than three live neighbours dies, as if by overpopulation.
  Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
 */
uint8_t propagateLife() {
  uint8_t other_page = !current_page;
  uint8_t alive = 0;
  for (uint8_t x=0; x<WIDTH; ++x) {
    for (uint8_t y=0; y<HEIGHT; ++y) {
      uint8_t neighbours = livingNeighbours(x, y);
      bool current_status = pages[current_page].getPixel(x, y);
      bool new_status = false;
      if(current_status) {
        if(neighbours == 3) new_status = true;
        if(neighbours == 4) new_status = true;
      } else {
        if(neighbours == 3) new_status = true;
      }
      if(new_status) alive++;
      pages[other_page].setPixel(x, y, new_status);
    }
  }
  flipPage();
  return alive;
}

/*
 * Returns the number of live cell neighours to cell(x, y)
 * Considers cells outside the matrix as dead
 * NB: if the current cell is alive, it gets counted as a "neighbour"
 */
uint8_t livingNeighbours(uint8_t x, uint8_t y) {
  uint8_t count = 0;
  uint8_t min_x = x > 0 ? x - 1 : 0;
  uint8_t max_x = x < WIDTH - 1 ? x + 1 : WIDTH - 1;
  uint8_t min_y = y > 0 ? y - 1 : 0;
  uint8_t max_y = y < HEIGHT - 1 ? y + 1 : HEIGHT - 1;
  for (uint8_t n_x=min_x; n_x<=max_x; ++n_x) {
    for (uint8_t n_y=min_y ; n_y<=max_y; ++n_y) {
      if(pages[current_page].getPixel(n_x, n_y)) count++;
    }
  }
  return count;
}

/*
 * Command: switch display pages.
 * current_page is switched, and the new page displayed
 */
void flipPage() {
  current_page = !current_page;
  ledDriver.setOnOffFrame(0, pages[current_page]);
}

/*
 * Command: run a little animation to signal start of the game
 */
void blinkAll() {
  static const int BLINK_DELAY = 100;
  for (int i=0; i<4; ++i) {
    ledDriver.setOnOffFrameAllOn(0);
    delay(BLINK_DELAY);
    ledDriver.setOnOffFrameAllOff(0);
    delay(BLINK_DELAY);
  }
}
