#include "game.h"
#include "melody.h"


Game::Game(MatrixDisplay *matrix, uint8_t red_led_pin, uint8_t yellow_led_pin, uint8_t green_led_pin, uint8_t speaker_pin) {
  this->matrix = matrix;
  this->red_led_pin = red_led_pin;
  this->yellow_led_pin = yellow_led_pin;
  this->green_led_pin = green_led_pin;
  this->speaker_pin = speaker_pin;
  max_cards = matrix->maxCardPairs() * 2;
  reset_state();
}


void Game::begin() {
  pinMode(red_led_pin, OUTPUT);
  pinMode(yellow_led_pin, OUTPUT);
  pinMode(green_led_pin, OUTPUT);
  hello();
}


void Game::gameRunning() {
  Serial.println(F("set state: gameRunning"));
  current_state = GameState::GameRunning;
  reset_indicators();
  matrix->writeSprite(Sprites::Question);
}


bool Game::initializing() {
  bool wip = isInitializing();
  if (wip) {
    Serial.println(F("set state: continuing card initialization"));
  } else {
    Serial.println(F("set state: starting card initialization"));
    reset_state();
    reset_indicators();
  }
  current_state = GameState::Initializing;
  matrix->writeSprite(Sprites::Question);
  return !wip;
}


bool Game::isInitializing() {
  return (
    current_state == GameState::Initializing ||
    current_state == GameState::CardInitialized ||
    current_state == GameState::cardInitializeFail
  );
}


void Game::cardInitialized() {
  Serial.println(F("set state: cardInitialized"));
  current_state = GameState::CardInitialized;
  reset_indicators();
  playMelody(speaker_pin, Melodies::HappyBeep);
}


void Game::cardInitializeFail() {
  Serial.println(F("set state: cardInitializeFail"));
  current_state = GameState::cardInitializeFail;
  reset_indicators();
  playMelody(speaker_pin, Melodies::SadBeep);
}


void Game::cardAccepted() {
  Serial.println(F("set state: cardAccepted"));
  current_state = GameState::CardAccepted;
  reset_indicators();
  playMelody(speaker_pin, Melodies::HappyBeep);
}


void Game::cardMatch() {
  Serial.println(F("set state: cardMatch"));
  current_state = GameState::CardMatch;
  reset_indicators();
  playMelody(speaker_pin, Melodies::HappyTune);
  matrix->writeSprite(Sprites::Correct);
}


void Game::cardMismatch() {
  Serial.println(F("set state: cardMismatch"));
  current_state = GameState::cardMismatch;
  reset_indicators();
  playMelody(speaker_pin, Melodies::SadTune);
  matrix->writeSprite(Sprites::Incorrect);
}


uint8_t Game::peekNextMaxCardId() {
  uint8_t result = 0;
  if (max_card_id < max_cards) {
    result = max_card_id + 1;
  }
  Serial.print(F("peekNextMaxCardId: ")); Serial.println(result);
  return result;
}


void Game::incrementMaxCardId() {
  this->max_card_id += 1;
  Serial.print(F("incrementMaxCardId: ")); Serial.println(max_card_id);
}


void Game::recordCardId(uint8_t card_id) {
  last_card_id = current_card_id;
  waiting_for_second_card = !waiting_for_second_card;
  current_card_id = card_id;
  Serial.print(F("recordCardId. card_id:")); Serial.print(card_id);
  Serial.print(F(", last_card_id:")); Serial.print(last_card_id);
  Serial.print(F(", current_card_id:")); Serial.println(current_card_id);
  matrix->showCardEmoji(current_card_id);

  // calculate state based on the new card
  if (isFirstCard()) {
    cardAccepted();
  } else {
    if (isCardMatch()) {
      cardMatch();
      // could add game-over checks here, but we're not yet
      // actually tracking that all pairs of cards have been read
    } else {
      cardMismatch();
    }
  }
}


uint8_t Game::getCardId() {
  return current_card_id;
}


bool Game::isFirstCard() {
  return waiting_for_second_card;
}


bool Game::isCardMatch() {
  return (
    (last_card_id > 0) &&
    (last_card_id != current_card_id) &&
    (
      ((last_card_id + 1) / 2) == ((current_card_id + 1) / 2)
    )
  );
}


void Game::tick() {
  int elapsed = millis() - tick_counter;
  int mode_elapsed = millis() - mode_tick_counter;

  switch (current_state) {
  case GameState::GameRunning:
    digitalWrite(yellow_led_pin, tick_state);
    if (elapsed > FAST_FLASH) {
      toggle_tick();
    }
    break;
  case GameState::Initializing:
    digitalWrite(red_led_pin, tick_state);
    digitalWrite(yellow_led_pin, tick_state);
    digitalWrite(green_led_pin, tick_state);
    if (elapsed > SLOW_FLASH) {
      toggle_tick();
    }
    break;
  case GameState::CardInitialized:
    digitalWrite(yellow_led_pin, tick_state);
    digitalWrite(green_led_pin, HIGH);
    if (elapsed > SLOW_FLASH) {
      toggle_tick();
    }
    if (mode_elapsed > MODE_EXPIRY) {
      initializing();
    }
    break;
  case GameState::cardInitializeFail:
    digitalWrite(yellow_led_pin, tick_state);
    digitalWrite(red_led_pin, HIGH);
    if (elapsed > SLOW_FLASH) {
      toggle_tick();
    }
    if (mode_elapsed > MODE_EXPIRY) {
      initializing();
    }
    break;
  case GameState::CardAccepted:
    digitalWrite(green_led_pin, tick_state);
    if (elapsed > SLOW_FLASH) {
      toggle_tick();
    }
    if (mode_elapsed > MODE_EXPIRY) {
      matrix->writeSprite(Sprites::Question);
    }
    break;
  case GameState::CardMatch:
    digitalWrite(green_led_pin, HIGH);
    if (mode_elapsed > MODE_EXPIRY) {
      gameRunning();
    }
    break;
  case GameState::cardMismatch:
    digitalWrite(red_led_pin, HIGH);
    if (mode_elapsed > MODE_EXPIRY) {
      gameRunning();
    }
    break;
  };

}


void Game::toggle_tick() {
  tick_state = !tick_state;
  tick_counter = millis();
}


void Game::reset_indicators() {
  tick_counter = millis();
  mode_tick_counter = millis();
  tick_state = true;
  digitalWrite(red_led_pin, LOW);
  digitalWrite(yellow_led_pin, LOW);
  digitalWrite(green_led_pin, LOW);
  tick();
}


void Game::reset_state() {
  Serial.println(F("reset_state"));
  current_state = GameState::GameRunning;
  max_card_id = 0;
  last_card_id = 0;
  current_card_id = 0;
  waiting_for_second_card = false;
}


void Game::hello() {
  int duration = 75;
  flash(green_led_pin, duration);
  flash(yellow_led_pin, duration);
  flash(red_led_pin, duration);
  flash(yellow_led_pin, duration);
  flash(green_led_pin, duration);
}


void Game::flash(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
}

