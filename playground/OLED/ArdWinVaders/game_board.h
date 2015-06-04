/*

  Orchestrate the game scene - the main controller.
  * actor positioning and movement
  * collision detection
  * delegates display updating to BufferedDisplay

*/

#ifndef GameBoard_h
#define GameBoard_h

#include "buffered_display.h"

#define MAX_MISSILES 4
#define ALIEN_ROWS 4
#define ALIENS_PER_ROW DISPLAY_WIDTH / (ALIEN_SPACING) - 2

class GameBoard {
  public:
    GameBoard(BufferedDisplay *gameDisplay);

    void init();
    void moveLeft();
    void moveRight();
    void fire();
    void recalc();
    void addScore(int score);

  private:
    BufferedDisplay *gameDisplay;

    int score;
    char score_text[4];

    int firebasePosition;

    int alien_rows_x[ALIEN_ROWS];
    int alien_rows_y[ALIEN_ROWS];
    int alien_rows_jiggle[ALIEN_ROWS];
    int aliens[ALIEN_ROWS][ALIENS_PER_ROW];

    int missile_vectors[MAX_MISSILES];
    int missile_runs[MAX_MISSILES];

    void clearMissile(int i);
    void clearMissiles();
    int getMissileSlot();
    void moveMissiles();

    void resetAliens();
    void drawAliens();

};

#endif
