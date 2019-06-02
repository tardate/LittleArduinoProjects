/*

  RFID/Concentration
  Play a game of Concentration/Pairs with a stack of MIFARE Classic cards.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/RFID/Concentration

 */

#include <FlexiTimer2.h>
#include <LedControl.h>

#include "matrix_display.h"
#include "card_interface.h"
#include "game.h"
#include "settings.h"


const uint8_t L88_CS_PIN     = 2;
const uint8_t L88_MOSI_PIN   = 3;
const uint8_t L88_CLK_PIN    = 4;
const uint8_t RED_LED_PIN    = 5;
const uint8_t GREEN_LED_PIN  = 6;
const uint8_t YELLOW_LED_PIN = 7;
const uint8_t SPEAKER_PIN    = 8;
const uint8_t RST_PIN        = 9;
const uint8_t SS_PIN         = 10;


Settings settings;

MFRC522 mfrc522(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}; // use factory defaults

CardInterface card(&mfrc522, &key);

LedControl lc = LedControl(L88_MOSI_PIN, L88_CLK_PIN, L88_CS_PIN, 1);

MatrixDisplay matrix = MatrixDisplay(&lc);

Game game(&matrix, RED_LED_PIN, YELLOW_LED_PIN, GREEN_LED_PIN, SPEAKER_PIN);

bool is_card_read_debounced = true;


/**
 * Command: interrupt routine to re-enable card detection.
 */
void debounceCardRead() {
  is_card_read_debounced = true;
}


/**
 * Initialize.
 */
void setup() {
  Serial.begin(115200);
  while (!Serial);

  settings.loadGameDetails();
  matrix.begin();
  game.begin();
  card.begin();

  FlexiTimer2::set(750, 1.0/1000, debounceCardRead); // every 750ms
  FlexiTimer2::start();
}


/**
 * Main loop.
 */
void loop() {
  if (is_card_read_debounced && card.isDetected()) {
    if (card.isCardRead()) {
      if (card.isValidForGame(settings.getGameId())) {
        game.recordCardId(card.getCardId());
      } else {
        if (game.initializing()) {
          settings.resetGameId();
        };
        uint8_t next_card_id = game.peekNextMaxCardId();
        if (next_card_id > 0) {
          if (card.makeGameCard(settings.getGameId(), next_card_id)) {
            game.incrementMaxCardId();
            game.cardInitialized();
          } else {
            game.cardInitializeFail();
          }
        } else {
          game.gameRunning();
        }
      }
    }
    card.halt();
    is_card_read_debounced = false;
  }
  game.tick();
}
