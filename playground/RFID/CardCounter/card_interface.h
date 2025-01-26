/*

  A simplified MFRC522 interface

*/

#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>


const byte DATA_SECTOR       = 1; // Defines the sector used for the demo: sector 1, from block 4 to block 7
const byte CHARGE_BLOCK      = 4; // the charge value block
const byte USAGE_BLOCK       = 5; // the usage value block
const byte NULL_BLOCK        = 6; // unused
const byte TRAILER_BLOCK     = 7; // sector trailer


const byte CHARGE_ADDRESS    = 0xf0; // arbitrary address for the charge value block
const byte USAGE_ADDRESS     = 0x0f; // arbitrary address for the usage value block


const int32_t INITIAL_CHARGE = 3;
const int32_t INITIAL_USAGE  = 0;


class CardInterface {

  public:

    CardInterface(MFRC522 *mfrc522, MFRC522::MIFARE_Key *key);

    /**
     * Initializes the SPI bus and MFRC522
     */
    void begin();

    /**
     * Returns true if card detected and authenticated
     */
    bool authenticated();

    /**
     * Returns true if card is personalised and charged
     */
    bool charged();

    /**
     * Returns true if a deduction was successful.
     * Returns false if failed because no balance remaining.
     */
    bool deduct();

    /**
     * Setup the card with initial charge
     */
    bool personalize();

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
     * Increments specified value block (by 1)
     */
    bool increment(byte block);

    /**
     * Decrements specified value block (by 1)
     */
    bool decrement(byte block);

    /**
     * Performs transfer for specified value block
     */
    bool transfer(byte block);

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
