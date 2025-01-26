#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>


const byte DATA_SECTOR       = 1; // Defines the sector used for the demo: sector 1, from block 4 to block 7
const byte GAME_ID_BLOCK     = 4; // the game id value block
const byte CARD_ID_BLOCK     = 5; // the card id value block
const byte NULL_BLOCK        = 6; // unused
const byte TRAILER_BLOCK     = 7; // sector trailer

const byte ACCESS_BITS_g0    = 6; // block 1: value block. A: r,dec; B: r/w,inc,dec,transfer
const byte ACCESS_BITS_g1    = 6; // block 2: value block. A: r,dec; B: r/w,inc,dec,transfer
const byte ACCESS_BITS_g2    = 0; // block 3: data block, A|B r/w
const byte ACCESS_BITS_g3    = 3; // sector trailer. B: write

const byte BLOCK_ADDRESS     = 0xf0; // arbitrary address for the value blocks


/**
 * A simplified MFRC522 interface, tailored for use in the Conventration game
 */
class CardInterface {
  public:
    CardInterface(MFRC522 *mfrc522, MFRC522::MIFARE_Key *key);

    /**
     * Initializes the SPI bus and MFRC522
     */
    void begin();

    /**
     * Returns true if card isDetected
     */
    bool isDetected();

    /**
     * Returns true if card has been authenticated and read (whether successful or not)
     */
    bool isCardRead();

    /**
     * Returns true if card is personalised and charged for specified game_id
     */
    bool isValidForGame(uint8_t game_id);

    /**
     * Returns the card id
     */
    uint8_t getCardId();

    /**
     * Setup the card with initial charge
     */
    bool makeGameCard(uint8_t game_id, uint8_t card_id);

    /**
     * Resets the data sector to default transport configuration
     */
    bool factory_reset();

    /**
     * Ends communication with a card
     */
    void halt();

    /**
     * Dumps the current sector data to Serial
     */
    void dump_sector();

  private:
    MFRC522 *mfrc522;
    MFRC522::MIFARE_Key *key_pointer;
    byte trailer_buffer[18];

    bool is_card_read;
    uint8_t card_id;
    uint8_t game_id;

    /**
     * Returns true if card authenticated
     */
    bool authenticated();

    /**
     * Returns true if game id was read OK
     */
    bool readGameId();

    /**
     * Returns true if game id was read OK
     */
    bool readCardId();

    /**
     * Command: resets ached card details
     */
    void resetCardInfo();

    /**
     * Returns true if status code provided checks OK
     */
    bool evaluate_status(MFRC522::StatusCode status);

    /**
     * Returns true if authentication with key A succeeds
     */
    bool auth_key_A();

    /**
     * Returns true if authentication with key B succeeds
     */
    bool auth_key_B();

    /**
     * Writes the specified 16-byte block
     */
    bool write_block(byte block, byte *buffer);

    /**
     * Reads the specified block into an 18-byte buffer
     */
    bool read_block(byte block, byte *buffer);

    /**
     * Returns the value from the specified value block
     */
    int32_t get_value(byte block);

    /**
     * Reads the trailer to trailer_buffer
     */
    bool read_trailer();

    /**
     * Initialises buffer as trailer block structure and values
     */
    void setup_as_trailer_block(byte *buffer, byte g0, byte g1, byte g2, byte g3);

    /**
     * Ensure that a given block is formatted as a Value Block.
     */
    void format_value_block(byte block, int32_t initial_value, byte initial_address);
};


/**
 * Helper routine to dump a byte array as hex values to Serial.
 */
void dump_byte_array(byte *buffer, byte bufferSize);
