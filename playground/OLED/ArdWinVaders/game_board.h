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
#define ALIENS_PER_ROW DISPLAY_WIDTH / ALIEN_WIDTH - 2

class GameBoard {
  public:
    GameBoard(BufferedDisplay *gameDisplay);

    void init();

    void resetGame();
    void endGame();
    void startGame();

    bool beginRecalc();
    void moveLeft();
    void moveRight();
    void fire();
    void finishRecalc();

    void setScore(int score);
    void addScore(int score);

  private:
    BufferedDisplay *gameDisplay;

    bool game_in_progress;

    int score;

    int firebasePosition;

    int alien_mode_counter;

    int alien_rows_x[ALIEN_ROWS];
    int alien_rows_y[ALIEN_ROWS];
    int alien_rows_mode[ALIEN_ROWS];
    int aliens[ALIEN_ROWS][ALIENS_PER_ROW];

    int missile_vectors[MAX_MISSILES];
    int missile_runs[MAX_MISSILES];


    void clearMissile(int i);
    void clearMissiles();
    int  getMissileSlot();
    void undrawMissiles();
    void moveMissiles();
    void handleMissileHit(int missile, int missile_x, int missile_y);

    void resetAliens();
    void drawAliens();

    void writeScore();
    void writeStartupMessage();
};

#endif
