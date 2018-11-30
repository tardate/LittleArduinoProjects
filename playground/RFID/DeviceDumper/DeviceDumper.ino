/*

  RFID/DeviceDumper
  Based on various examples from https://github.com/miguelbalboa/rfid

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/RFID/DeviceDumper

 */

#include <SPI.h>
#include <MFRC522.h>

const int RST_PIN = 9;
const int SS_PIN  = 10;

// Number of known default keys (hard-coded)
const byte KNOWN_KEYS_COUNT = 8;
byte knownKeys[KNOWN_KEYS_COUNT][MFRC522::MF_KEY_SIZE] =  {
    {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, // factory default
    {0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5},
    {0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5},
    {0x4d, 0x3a, 0x99, 0xc3, 0x51, 0xdd},
    {0x1a, 0x98, 0x2c, 0x7e, 0x45, 0x9a},
    {0xd3, 0xf7, 0xd3, 0xf7, 0xd3, 0xf7},
    {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};

MFRC522::MIFARE_Key key;

MFRC522 mfrc522(SS_PIN, RST_PIN);

/**
 * Helper routine to dump a byte array as hex values to Serial.
 *
 */
void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}

/**
 * Run self-test and show result
 *
 */
void selfTest() {
  Serial.println(F("-----------------------------"));
  Serial.println(F("MFRC522 Digital self test"));
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();
  Serial.print(F("Performing test... "));
  bool result = mfrc522.PCD_PerformSelfTest(); // perform the test
  Serial.print(F("Result: "));
  if (result)
    Serial.println(F("OK"));
  else
    Serial.println(F("DEFECT or UNKNOWN"));
  Serial.println(F("-----------------------------"));
}

/*
 * Try using the PICC (the tag/card) with the given key to access block 0.
 * On success, it will show the key details, and dump the block data on Serial.
 *
 * @return true when the given key worked, false otherwise.
 */
bool try_key(MFRC522::MIFARE_Key *key)
{
    bool result = false;
    byte buffer[18];
    byte block = 0;
    MFRC522::StatusCode status;

    Serial.print(F("Authenticating using key A = "));
    dump_byte_array((*key).keyByte, MFRC522::MF_KEY_SIZE);
    Serial.println();

    if ( ! mfrc522.PICC_IsNewCardPresent()) {
        Serial.println(F("Failed PICC_IsNewCardPresent"));
        return false;
    }
    if ( ! mfrc522.PICC_ReadCardSerial()){
        Serial.println(F("Failed PICC_ReadCardSerial"));
        return false;
    }

    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("PCD_Authenticate() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return false;
    }

    // Read block
    byte byteCount = sizeof(buffer);
    status = mfrc522.MIFARE_Read(block, buffer, &byteCount);
    if (status != MFRC522::STATUS_OK) {
      Serial.print(F("MIFARE_Read() failed: "));
      Serial.println(mfrc522.GetStatusCodeName(status));
      mfrc522.PICC_HaltA();       // Halt PICC
      mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
    } else {
      // Successful read
      result = true;
      Serial.print(F("Success with key:"));
      dump_byte_array((*key).keyByte, MFRC522::MF_KEY_SIZE);
      Serial.println();
    }
    return result;
}

bool findKey() {

  // if I don't (redundantly?) check this here,
  // the first key attempt will fail
  mfrc522.PICC_IsNewCardPresent();

  // try known keys to find on that works
  for (byte k = 0; k < KNOWN_KEYS_COUNT; k++) {
    for (byte i = 0; i < MFRC522::MF_KEY_SIZE; i++) {
        key.keyByte[i] = knownKeys[k][i];
    }
    if (try_key(&key)) {
      return true;
    }
  }
  return false;
}

/**
 * Dumps debug info about the selected PICC to Serial.
 * On success the PICC is halted after dumping the data.
 *
 */
void PICC_DumpToSerial(MFRC522::Uid *uid, MFRC522::MIFARE_Key *key) {

  // Dump UID, SAK and Type
  mfrc522.PICC_DumpDetailsToSerial(uid);

  // Dump contents
  MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(uid->sak);
  switch (piccType) {
    case MFRC522::PICC_TYPE_MIFARE_MINI:
    case MFRC522::PICC_TYPE_MIFARE_1K:
    case MFRC522::PICC_TYPE_MIFARE_4K:
      mfrc522.PICC_DumpMifareClassicToSerial(uid, piccType, key);
      break;

    case MFRC522::PICC_TYPE_MIFARE_UL:
      mfrc522.PICC_DumpMifareUltralightToSerial();
      break;

    case MFRC522::PICC_TYPE_ISO_14443_4:
    case MFRC522::PICC_TYPE_MIFARE_DESFIRE:
    case MFRC522::PICC_TYPE_ISO_18092:
    case MFRC522::PICC_TYPE_MIFARE_PLUS:
    case MFRC522::PICC_TYPE_TNP3XXX:
      Serial.println(F("Dumping memory contents not implemented for that PICC type."));
      break;

    case MFRC522::PICC_TYPE_UNKNOWN:
    case MFRC522::PICC_TYPE_NOT_COMPLETE:
    default:
      break; // No memory dump here
  }

  Serial.println();
  mfrc522.PICC_HaltA(); // Already done if it was a MIFARE Classic PICC.
  mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
}


/**
 * Setup serial and SPI comms, then run MFRC522 self test
 *
 */
void setup() {
  Serial.begin(115200);
  while (!Serial);
  SPI.begin();
  selfTest();
  mfrc522.PCD_Init();
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}


/**
 * Main loops looks for a card.
 * When one is presented, tries to find a matching key then dumps data from the card
 *
 */
void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) {
    if (findKey()) {
      PICC_DumpToSerial(&(mfrc522.uid), &key);
    }
  }
}


