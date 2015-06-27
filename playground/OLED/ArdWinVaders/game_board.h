/*

  Orchestrate the game scene - the main controller.
  * actor positioning and movement
  * collision detection
  * delegates display updating to BufferedDisplay

*/

#ifndef GameBoard_h
#define GameBoard_h

#include "buffered_display.h"
#include "sound_system.h"

#define MAX_MISSILES 4
#define MAX_BOMBS 6
#define ALIEN_ROWS 4
#define ALIENS_PER_ROW (DISPLAY_WIDTH / ALIEN_WIDTH - 2)

class GameBoard {
  public:
    GameBoard(BufferedDisplay *gameDisplay, SoundSystem *soundSystem);

    void init();

    void resetGame();
    void winGame();
    void loseGame();
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
    SoundSystem *soundSystem;

    bool game_in_progress;
    int  game_result;
    int  score;
    int  firebasePosition;
    int  alien_mode_counter;

    void endGame();
    void writeScore();
    void writeStartupMessage();
    void writeWinMessage();
    void writeFailMessage();


    int  alien_rows_x[ALIEN_ROWS];
    int  alien_rows_y[ALIEN_ROWS];
    int  alien_rows_mode[ALIEN_ROWS];
    int  aliens[ALIEN_ROWS][ALIENS_PER_ROW];

    void resetAliens();
    void moveAndDrawAliens();

    int  missile_vectors[MAX_MISSILES];
    int  missile_runs[MAX_MISSILES];

    void clearMissile(int i);
    void clearMissiles();
    int  getMissileSlot();
    void undrawMissiles();
    void moveMissiles();
    void handleMissileHit(int missile, int missile_x, int missile_y);

    int  bomb_vectors[MAX_BOMBS];
    int  bomb_runs[MAX_BOMBS];

    bool decideToBomb();
    void dropBomb(int x, int y);
    void clearBomb(int i);
    void clearBombs();
    int  getBombSlot();
    void undrawBombs();
    void moveBombs();


};

#endif
