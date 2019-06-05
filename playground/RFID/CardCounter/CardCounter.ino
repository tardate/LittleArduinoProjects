/*

  RFID/CardCounter
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/RFID/CardCounter

 */

#include "card_interface.h"
#include "charge_indicator.h"

const int RED_LED_PIN    = 5;
const int GREEN_LED_PIN  = 6;
const int YELLOW_LED_PIN = 7;

const int RST_PIN = 9;
const int SS_PIN  = 10;

MFRC522 mfrc522(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}; // factory default

CardInterface card(&mfrc522, &key);

ChargeIndicator charger(RED_LED_PIN, GREEN_LED_PIN, YELLOW_LED_PIN);


/**
 * Initialize.
 */
void setup() {
  Serial.begin(115200);
  while (!Serial);
  card.begin();
  charger.begin();
}


/**
 * Main loop.
 */
void loop() {
  if (card.authenticated()) {
    card.dump_sector();
    if (card.charged()) {
      if (card.deduct()) {
        charger.start_deduct();
      } else {
        charger.start_reset();
        card.factory_reset();
      }
    } else {
      charger.start_charge();
      card.personalize();
    }
    card.dump_sector();
    card.halt();
    charger.end_state();
  }
}
