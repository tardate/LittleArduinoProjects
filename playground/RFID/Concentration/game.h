#pragma once

#include <Arduino.h>
#include "matrix_display.h"

const int SLOW_FLASH = 500;
const int FAST_FLASH = 100;
const int MODE_EXPIRY = 3000;

/**
 * Defines the allowed game states
 */
enum GameState : uint8_t {
    GameRunning,
    Initializing,
    CardInitialized,
    cardInitializeFail,
    CardAccepted,
    CardMatch,
    cardMismatch
};


/**
 * Main game controller.
 * Manages game state and indicators
 */
class Game {
  public:
    Game(MatrixDisplay *matrix, uint8_t red_led_pin, uint8_t yellow_led_pin, uint8_t green_led_pin, uint8_t speaker_pin);

    /**
     * Initializes indictor LEDs
     */
    void begin();

    /**
     * Command: sets game running mode
     */
    void gameRunning();

    /**
     * Command: sets initializing state
     * Returns: true if this was a state transition
     */
    bool initializing();

    /**
     * Returns: true if initializing
     */
    bool isInitializing();

    /**
     * Command: sets card initialized state
     */
    void cardInitialized();

    /**
     * Command: sets card initialize failure state
     */
    void cardInitializeFail();

    /**
     * Command: sets first card accepted state
     */
    void cardAccepted();

    /**
     * Command: sets card match state
     */
    void cardMatch();

    /**
     * Command: sets card mis-match state
     */
    void cardMismatch();

    /**
     * Returns: the next available card ID or 0 if no cards available
     */
    uint8_t peekNextMaxCardId();

    /**
     * Command: commits/confirms card increment
     */
    void incrementMaxCardId();

    /**
     * Command: records a card swipe
     */
    void recordCardId(uint8_t card_id);

    /**
     * Returns: current card id
     */
    uint8_t getCardId();

    /**
     * Returns: true if on the first card of a turn
     */
    bool isFirstCard();

    /**
     * Returns: true if last two cards match
     */
    bool isCardMatch();

    /**
     * Async processing interrupt
     */
    void tick();

  private:
    MatrixDisplay *matrix;

    uint8_t red_led_pin;
    uint8_t yellow_led_pin;
    uint8_t green_led_pin;
    uint8_t speaker_pin;
    int tick_counter;
    int mode_tick_counter;
    bool tick_state;
    GameState current_state;

    uint8_t max_cards;
    uint8_t max_card_id;
    uint8_t last_card_id;
    uint8_t current_card_id;
    bool waiting_for_second_card;

    /**
     * Flash a welcome sequence
     */
    void hello();

    /**
     * Flash a specific pin
     */
    void flash(int pin, int duration);

    /**
     * Command: reset game state
     */
    void reset_state();

    /**
     * Command: reset tick counters
     */
    void reset_indicators();

    /**
     * Signal tick complete
     */
    void toggle_tick();
};
