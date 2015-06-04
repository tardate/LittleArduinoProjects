#include "game_board.h"

#define FIREBASE_MOVE_SPEED 2
#define FIREBASE_LEFT_LIMIT_TEST FIREBASE_MOVE_SPEED
#define FIREBASE_RIGHT_LIMIT_TEST FIREBASE_MAX_X - FIREBASE_MOVE_SPEED

#define MISSILE_MOVE_SPEED 2
#define MISSILE_RUN_LENGTH DISPLAY_HEIGHT - FIREBASE_GUN_Y_OFFSET

#define ALIEN_INITIAL_X ALIEN_WIDTH
#define ALIEN_JIGGLE_MAX ALIEN_INITIAL_X + ALIEN_WIDTH

/*
 *   constructor
 */

GameBoard::GameBoard(BufferedDisplay *gameDisplay) {
  this->gameDisplay = gameDisplay;
}

void GameBoard::init() {
  firebasePosition = FIREBASE_INITAL_X;
  clearMissiles();
  resetAliens();
  score = 0;
  addScore(0);
  gameDisplay->moveFireBase(firebasePosition);
}

void GameBoard::moveLeft() {
  if(firebasePosition<FIREBASE_LEFT_LIMIT_TEST) return;
  firebasePosition -= FIREBASE_MOVE_SPEED;
  gameDisplay->moveFireBase(firebasePosition,-FIREBASE_MOVE_SPEED);
}

void GameBoard::moveRight() {
  if(firebasePosition>FIREBASE_RIGHT_LIMIT_TEST) return;
  firebasePosition += FIREBASE_MOVE_SPEED;
  gameDisplay->moveFireBase(firebasePosition,FIREBASE_MOVE_SPEED);
}

void GameBoard::fire() {
  int slot = getMissileSlot();
  if(slot<0) return;
  missile_vectors[slot] = firebasePosition + FIREBASE_GUN_X_OFFSET;
  missile_runs[slot] = MISSILE_RUN_LENGTH;
}

void GameBoard::recalc() {
  drawAliens();
  moveMissiles();
}

void GameBoard::addScore(int points) {
  score += points;
  if(score<1000) {
    sprintf(score_text, "%d", score);
  } else {
    sprintf(score_text, "***");
  }
  gameDisplay->setSegmentCursor(20);
  gameDisplay->writeString(score_text);
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

void GameBoard::moveMissiles() {
  int old_y;
  for(int i=0; i<MAX_MISSILES; i++) {
    if(missile_runs[i]>0) {
      old_y = missile_runs[i];
      missile_runs[i] -= MISSILE_MOVE_SPEED;
      if(missile_runs[i]<0) {
        gameDisplay->moveMissile(missile_vectors[i], old_y);
        clearMissile(i);
      } else {
        if(old_y<MISSILE_RUN_LENGTH) {
          gameDisplay->moveMissile(missile_vectors[i], old_y, missile_runs[i]);
        } else {
          gameDisplay->moveMissile(missile_vectors[i], missile_runs[i]);
        }
      }
    }
  }
}

void GameBoard::resetAliens() {
  for(int row=0; row<ALIEN_ROWS; row++) {
    alien_rows_x[row] = ALIEN_INITIAL_X + row;
    alien_rows_y[row] = -1;
    alien_rows_jiggle[row] = 1;
    for(int a=0; a<ALIENS_PER_ROW; a++) aliens[row][a] = 1;
  }
  alien_rows_y[0] = 1;
}

void GameBoard::drawAliens() {
  for(int row=0; row<ALIEN_ROWS; row++) {
    if(alien_rows_y[row]>0) {
      gameDisplay->setSegmentByPageOffset(alien_rows_y[row], alien_rows_x[row]);
      for(int a=0; a<ALIENS_PER_ROW; a++) {
        if(aliens[row][a]>0) {
          gameDisplay->insertAlienAtCursor();
        } else {
          gameDisplay->insertNoAlienAtCursor();
        }
      }
      // jiggle
      if(alien_rows_x[row]>=ALIEN_JIGGLE_MAX) alien_rows_jiggle[row] = -1;
      if(alien_rows_x[row]<=ALIEN_INITIAL_X) alien_rows_jiggle[row] = 1;
      alien_rows_x[row] += alien_rows_jiggle[row];

    }
  }
  alien_rows_y[0] = 1;
}


