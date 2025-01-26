#include "game_board.h"
#include <stdlib.h>

#define STARTUP_MESSAGE "Press fire to start"
#define WIN_MESSAGE "The Earthling Wins!"
#define FAIL_MESSAGE "Fail Earthling!"

#define FIREBASE_MOVE_SPEED 2
#define FIREBASE_LEFT_LIMIT_TEST FIREBASE_MOVE_SPEED
#define FIREBASE_RIGHT_LIMIT_TEST FIREBASE_MAX_X - FIREBASE_MOVE_SPEED

#define MISSILE_MOVE_SPEED 2
#define MISSILE_RUN_LENGTH DISPLAY_HEIGHT - FIREBASE_GUN_Y_OFFSET
#define BOMB_MOVE_SPEED 1
#define BOMB_COLLISION_Y_MIN (DISPLAY_HEIGHT - DISPLAY_PAGE_HEIGHT)

#define ALIEN_INITIAL_X ALIEN_WIDTH
#define ALIEN_JIGGLE_MAX ALIEN_INITIAL_X + ALIEN_WIDTH
#define ALIEN_MODE_JIGGLE_RIGHT 1
#define ALIEN_MODE_JIGGLE_LEFT -1
#define ALIEN_MODE_EXIT_RIGHT 2
#define ALIEN_MODE_ENTER_RIGHT 3
#define ALIEN_MODE_COUNT_BEFORE_EXIT_RIGHT (ALIEN_WIDTH * 6)

#define GAME_RESULT_NIL  0
#define GAME_RESULT_FAIL 1
#define GAME_RESULT_WIN  2

#define GAME_WINNING_SCORE  (ALIEN_ROWS * ALIENS_PER_ROW)

/*
 *   constructor
 */
GameBoard::GameBoard(BufferedDisplay *gameDisplay, SoundSystem *soundSystem) {
  this->gameDisplay = gameDisplay;
  this->soundSystem = soundSystem;
}

void GameBoard::init() {
  gameDisplay->init();
  srand(rand());
  setScore(0);
  resetGame();
  writeStartupMessage();
}

void GameBoard::resetGame() {
  gameDisplay->reset();
  game_in_progress = false;
  firebasePosition = FIREBASE_INITAL_X;
  alien_mode_counter = 0;
  clearMissiles();
  clearBombs();
  resetAliens();
}

void GameBoard::endGame() {
  resetGame();
  writeStartupMessage();
  switch(game_result) {
  case GAME_RESULT_WIN :
    writeWinMessage();
    break;
  case GAME_RESULT_FAIL :
    writeFailMessage();
    break;
  }
}

void GameBoard::startGame() {
  resetGame();
  setScore(0);
  game_in_progress = true;
  game_result = GAME_RESULT_NIL;
  gameDisplay->moveFireBase(firebasePosition);
}

void GameBoard::winGame() {
  game_in_progress = false;
  game_result = GAME_RESULT_WIN;
}

void GameBoard::loseGame() {
  game_in_progress = false;
  game_result = GAME_RESULT_FAIL;
}

bool GameBoard::beginRecalc() {
  if(!game_in_progress) return false;
  alien_mode_counter++;
  undrawMissiles();
  undrawBombs();
  return true;
}

void GameBoard::moveLeft() {
  if(firebasePosition<FIREBASE_LEFT_LIMIT_TEST) return;
  firebasePosition -= FIREBASE_MOVE_SPEED;
  gameDisplay->moveFireBase(firebasePosition);
}

void GameBoard::moveRight() {
  if(firebasePosition>FIREBASE_RIGHT_LIMIT_TEST) return;
  firebasePosition += FIREBASE_MOVE_SPEED;
  gameDisplay->moveFireBase(firebasePosition);
}

void GameBoard::finishRecalc() {
  moveAndDrawAliens();
  moveMissiles();
  moveBombs();
  if(score>=GAME_WINNING_SCORE) winGame();
  if(!game_in_progress) endGame();
}

void GameBoard::setScore(int points) {
  score = points;
  writeScore();
}

void GameBoard::addScore(int points) {
  score += points;
  writeScore();
}

void GameBoard::fire() {
  int slot = getMissileSlot();
  if(slot<0) return;
  missile_vectors[slot] = firebasePosition + FIREBASE_GUN_X_OFFSET;
  missile_runs[slot] = MISSILE_RUN_LENGTH;
  soundSystem->fire();
}

void GameBoard::clearMissile(int i) {
  missile_vectors[i] = 0;
  missile_runs[i] = 0;
}

void GameBoard::clearMissiles() {
  for(int i=0; i<MAX_MISSILES; i++) clearMissile(i);
}

int GameBoard::getMissileSlot() {
  for(int i=0; i<MAX_MISSILES; i++) {
    if(missile_vectors[i]==0) return i;
  }
  return -1;
}

void GameBoard::undrawMissiles() {
  for(int i=0; i<MAX_MISSILES; i++) {
    if(missile_runs[i]>0) {
      gameDisplay->moveMissile(missile_vectors[i], missile_runs[i]);
    }
  }
}

void GameBoard::moveMissiles() {
  for(int i=0; i<MAX_MISSILES; i++) {
    if(missile_runs[i]>0) {
      missile_runs[i] -= MISSILE_MOVE_SPEED;
      if(missile_runs[i]>0) {
        if(gameDisplay->moveMissile(missile_vectors[i], missile_runs[i])) {
          handleMissileHit(i, missile_vectors[i], missile_runs[i]);
        }
      } else {
        clearMissile(i);
      }
    }
  }
}

void GameBoard::handleMissileHit(int missile, int missile_x, int missile_y) {
  int alien_index;
  int page = gameDisplay->getPage(missile_y);
  if(page<1) return; // ignore first row
  for(int row=0; row<ALIEN_ROWS; row++) {
    if(alien_rows_y[row]==page) {
      alien_index =  div(missile_x - alien_rows_x[row], ALIEN_WIDTH).quot;
      if(aliens[row][alien_index]>0) {
        aliens[row][alien_index] = 0;
        clearMissile(missile);
        addScore(1);
      }
      return;
    };
  }
}

inline bool GameBoard::decideToBomb() {
  return rand() % 100 > 97;
}

void GameBoard::dropBomb(int x, int y) {
  if(decideToBomb()) {
    int slot = getBombSlot();
    if(slot<0) return;
    bomb_vectors[slot] = x;
    bomb_runs[slot] = y;
  }
}

void GameBoard::clearBomb(int i) {
  bomb_vectors[i] = 0;
  bomb_runs[i] = 0;
}

void GameBoard::clearBombs() {
  for(int i=0; i<MAX_BOMBS; i++) clearBomb(i);
}

int  GameBoard::getBombSlot() {
  for(int i=0; i<MAX_BOMBS; i++) {
    if(bomb_vectors[i]==0) return i;
  }
}

void GameBoard::undrawBombs() {
  for(int i=0; i<MAX_BOMBS; i++) {
    if(bomb_runs[i]>0) {
      gameDisplay->moveMissile(bomb_vectors[i], bomb_runs[i]);
    }
  }
}

void GameBoard::moveBombs() {
  for(int i=0; i<MAX_BOMBS; i++) {
    if(bomb_runs[i]>0) {
      bomb_runs[i] += BOMB_MOVE_SPEED;
      if(bomb_runs[i]<DISPLAY_HEIGHT) {
        if(gameDisplay->moveMissile(bomb_vectors[i], bomb_runs[i])) {
          if(bomb_runs[i]>BOMB_COLLISION_Y_MIN) loseGame();
        }
      } else {
        clearBomb(i);
      }
    }
  }
}

void GameBoard::resetAliens() {
  for(int row=0; row<ALIEN_ROWS; row++) {
    alien_rows_x[row] = ALIEN_INITIAL_X + row;
    alien_rows_y[row] = -1;
    alien_rows_mode[row] = ALIEN_MODE_JIGGLE_RIGHT;
    for(int a=0; a<ALIENS_PER_ROW; a++) aliens[row][a] = 1;
  }
  alien_rows_y[0] = 1;
}

void GameBoard::moveAndDrawAliens() {
  int page;
  for(int row=0; row<ALIEN_ROWS; row++) {
    page = alien_rows_y[row];
    if(page>0) {
      switch(alien_rows_mode[row]) {
        case ALIEN_MODE_EXIT_RIGHT:
          alien_rows_x[row]++;
          if(alien_rows_x[row]>=DISPLAY_WIDTH) {
            alien_mode_counter=0;
            alien_rows_mode[row]=ALIEN_MODE_ENTER_RIGHT;
            page = ++alien_rows_y[row];
            if(page>=DISPLAY_PAGE_COUNT-1) {
              loseGame();
            } else {
              int nrow=row+1;
              if(nrow<ALIEN_ROWS) {
                if(alien_rows_y[nrow]>0) {
                  alien_rows_mode[nrow] = ALIEN_MODE_EXIT_RIGHT;
                } else {
                  alien_rows_y[nrow] = 1;
                  alien_rows_x[nrow] = DISPLAY_WIDTH;
                  alien_rows_mode[nrow] = ALIEN_MODE_ENTER_RIGHT;
                }
              }
            }
          }
          break;
        case ALIEN_MODE_ENTER_RIGHT:
          alien_rows_x[row]--;
          if(alien_rows_x[row]<=ALIEN_INITIAL_X) {
            alien_mode_counter=0;
            alien_rows_mode[row]=ALIEN_MODE_JIGGLE_RIGHT;
          }
          break;
        default:
          // jiggle mode
          if(alien_rows_x[row]>=ALIEN_JIGGLE_MAX) alien_rows_mode[row] = ALIEN_MODE_JIGGLE_LEFT;
          if(alien_rows_x[row]<=ALIEN_INITIAL_X) alien_rows_mode[row] = ALIEN_MODE_JIGGLE_RIGHT;
          alien_rows_x[row] += alien_rows_mode[row];
          if(row==0 && alien_mode_counter>=ALIEN_MODE_COUNT_BEFORE_EXIT_RIGHT) alien_rows_mode[row] = ALIEN_MODE_EXIT_RIGHT;
      }

      int segmentLimit = gameDisplay->setSegmentByPageOffset(page, alien_rows_x[row]);

      for(int a=0; a<ALIENS_PER_ROW; a++) {
        if(aliens[row][a]>0) {
          if(gameDisplay->insertAlienAtCursor(segmentLimit)) {
            dropBomb(alien_rows_x[row] + (a * ALIEN_WIDTH) + ALIEN_GUN_X_OFFSET, (page * DISPLAY_PAGE_HEIGHT) + ALIEN_GUN_Y_OFFSET);
          }
        } else {
          gameDisplay->insertNoAlienAtCursor(segmentLimit);
        }
      }

    }
  }
}

void GameBoard::writeScore() {
  char score_text[4];
  if(score<1000) {
    sprintf(score_text, "%d", score);
  } else {
    sprintf(score_text, "***");
  }
  gameDisplay->setSegmentCursor(20);
  gameDisplay->writeString(score_text);
}

void GameBoard::writeStartupMessage() {
  gameDisplay->setSegmentByPageOffset(4, 20);;
  gameDisplay->writeString(STARTUP_MESSAGE);
}

void GameBoard::writeWinMessage() {
  writeScore();
  gameDisplay->setSegmentByPageOffset(2, 20);;
  gameDisplay->writeString(WIN_MESSAGE);
}

void GameBoard::writeFailMessage() {
  writeScore();
  gameDisplay->setSegmentByPageOffset(2, 20);;
  gameDisplay->writeString(FAIL_MESSAGE);
}
