#pragma once

#include <Arduino.h>

const int GAME_ID_ADDRESS = 0;
const int MIN_GAME_ID = 10;
const int MAX_GAME_ID = 90;


/**
 * Game-specific settings (peristed in EEPROM)
 */
class Settings {
  public:
    Settings(void);

    /**
     * Command: loads or initialises game details (game id, card details)
     */
    void loadGameDetails(void);

    /**
     * Returns: current game id setting. Resets if required
     */
    uint8_t getGameId(void);

    /**
     * Command: reset the game details and save to EEPROM
     */
    uint8_t resetGameId(void);

  private:
    bool loaded;
    uint8_t game_id;

    /**
     * Command: writes (8 bit) byte value to EEPROM address
     */
    void write(int address, byte value);

    /**
     * Returns: (8 bit) byte value from EEPROM address
     */
    byte read(int address);
};
