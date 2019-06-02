#include "settings.h"
#include <EEPROM.h>


Settings::Settings(void) {
  game_id = 0;
  loaded = false;
}


void Settings::loadGameDetails(void) {
  if (loaded) return;
  game_id = read(GAME_ID_ADDRESS);
  if ((game_id < MIN_GAME_ID) || (game_id > MAX_GAME_ID)) {
    resetGameId();
  } else {
    loaded = true;
  }
  Serial.print(F("Game ID: ")); Serial.println(game_id);
}


uint8_t Settings::getGameId(void) {
  loadGameDetails();
  return game_id;
}


uint8_t Settings::resetGameId(void) {
  uint8_t old_game_id = game_id;
  while (old_game_id == game_id) {
    game_id = random(MIN_GAME_ID, MAX_GAME_ID);
  }
  loaded = true;
  write(GAME_ID_ADDRESS, game_id);
  Serial.print(F("Reset Game ID: ")); Serial.println(game_id);
  return game_id;
}


void Settings::write(int address, byte value) {
  EEPROM.write(address, value);
}


byte Settings::read(int address) {
  return EEPROM.read(address);
}
