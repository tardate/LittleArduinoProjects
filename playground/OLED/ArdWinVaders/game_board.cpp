#include "game_board.h"
#include <stdlib.h>

#define FIREBASE_MOVE_SPEED 2
#define FIREBASE_LEFT_LIMIT_TEST FIREBASE_MOVE_SPEED
#define FIREBASE_RIGHT_LIMIT_TEST FIREBASE_MAX_X - FIREBASE_MOVE_SPEED

#define MISSILE_MOVE_SPEED 2
#define MISSILE_RUN_LENGTH DISPLAY_HEIGHT - FIREBASE_GUN_Y_OFFSET

#define ALIEN_INITIAL_X ALIEN_WIDTH
#define ALIEN_JIGGLE_MAX ALIEN_INITIAL_X + ALIEN_WIDTH
#define ALIEN_MODE_JIGGLE_RIGHT 1
#define ALIEN_MODE_JIGGLE_LEFT -1
#define ALIEN_MODE_EXIT_RIGHT 2

/*
 *   constructor
 */

GameBoard::GameBoard(BufferedDisplay *gameDisplay) {
  this->gameDisplay = gameDisplay;
}

void GameBoard::init() {
  gameDisplay->init();
  endGame();
}

void GameBoard::resetGame() {
  gameDisplay->reset();
  game_in_progress = false;
  firebasePosition = FIREBASE_INITAL_X;
  alien_mode_counter = 0;
  clearMissiles();
  resetAliens();
  setScore(0);
  gameDisplay->moveFireBase(firebasePosition);
}

void GameBoard::endGame() {
  resetGame();
  writeStartupMessage();
}

void GameBoard::startGame() {
  resetGame();
  game_in_progress = true;
}

bool GameBoard::beginRecalc() {
  if(!game_in_progress) return false;
  alien_mode_counter++;
  undrawMissiles();
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

void GameBoard::fire() {
  int slot = getMissileSlot();
  if(slot<0) return;
  missile_vectors[slot] = firebasePosition + FIREBASE_GUN_X_OFFSET;
  missile_runs[slot] = MISSILE_RUN_LENGTH;
}

void GameBoard::finishRecalc() {
  drawAliens();
  moveMissiles();
}

void GameBoard::setScore(int points) {
  score = points;
  writeScore();
}

void GameBoard::addScore(int points) {
  score += points;
  writeScore();
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
  int old_y;
  for(int i=0; i<MAX_MISSILES; i++) {
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

void GameBoard::resetAliens() {
  for(int row=0; row<ALIEN_ROWS; row++) {
    alien_rows_x[row] = ALIEN_INITIAL_X + row;
    alien_rows_y[row] = -1;
    alien_rows_mode[row] = ALIEN_MODE_JIGGLE_RIGHT;
    for(int a=0; a<ALIENS_PER_ROW; a++) aliens[row][a] = 1;
  }
  alien_rows_y[0] = 1;
}

void GameBoard::drawAliens() {
  int page;
  for(int row=0; row<ALIEN_ROWS; row++) {
    page = alien_rows_y[row];
    if(page>0) {
      // jiggle mode
      if(alien_rows_x[row]>=ALIEN_JIGGLE_MAX) alien_rows_mode[row] = ALIEN_MODE_JIGGLE_LEFT;
      if(alien_rows_x[row]<=ALIEN_INITIAL_X) alien_rows_mode[row] = ALIEN_MODE_JIGGLE_RIGHT;
      alien_rows_x[row] += alien_rows_mode[row];

      gameDisplay->setSegmentByPageOffset(page, alien_rows_x[row]);

      for(int a=0; a<ALIENS_PER_ROW; a++) {
        if(aliens[row][a]>0) {
          gameDisplay->insertAlienAtCursor();
        } else {
          gameDisplay->insertNoAlienAtCursor();
        }
      }

    }
  }
  alien_rows_y[0] = 1;
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
  gameDisplay->setSegmentByPageOffset(3, 20);;
  gameDisplay->writeString("Press fire to start");
}

