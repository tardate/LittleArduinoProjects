#include "card_interface.h"


CardInterface::CardInterface(MFRC522 *mfrc522, MFRC522::MIFARE_Key *key) : trailer_buffer {} {
  this->mfrc522 = mfrc522;
  this->key_pointer = key;
  resetCardInfo();
}


void CardInterface::begin() {
  SPI.begin();
  mfrc522->PCD_Init();

  Serial.println(F("MIFARE Classic simple value block interface."));
  Serial.print(F("Using key A/B = "));
  dump_byte_array(key_pointer->keyByte, MFRC522::MF_KEY_SIZE);
  Serial.println();
  Serial.print(F("BEWARE: Data will be written to the PICC in sector #"));
  Serial.println(DATA_SECTOR);
  Serial.println(F("Scan a card..."));
}


bool CardInterface::isDetected() {
  if (!mfrc522->PICC_IsNewCardPresent()) return false;
  if (!mfrc522->PICC_ReadCardSerial()) return false;

  Serial.print(F("Card UID:"));
  dump_byte_array(mfrc522->uid.uidByte, mfrc522->uid.size);
  Serial.println();
  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = mfrc522->PICC_GetType(mfrc522->uid.sak);
  Serial.println(mfrc522->PICC_GetTypeName(piccType));

  if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
      &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
      &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Sorry, only works with MIFARE Classic cards."));
    return false;
  }
  return true;
}


bool CardInterface::isCardRead() {
  if (authenticated() && readGameId() && readCardId()) {
    is_card_read = true;
  } else {
    resetCardInfo();
  }
  Serial.print(F("isCardRead = ")); Serial.println(is_card_read);
  return is_card_read;
}


bool CardInterface::isValidForGame(uint8_t game_id) {
  bool result = false;
  if (this->game_id == game_id) {
    Serial.print(F("Valid card for game_id = ")); Serial.println(game_id);
    result = true;
  } else {
    Serial.print(F("Card rejected, initialised for another game_id = ")); Serial.println(this->game_id);
  }
  return result;
}


uint8_t CardInterface::getCardId() {
  return card_id;
}


bool CardInterface::authenticated() {
  return auth_key_A() && read_trailer();
}


bool CardInterface::readGameId() {
  bool result = false;
  Serial.print(F("readGameId.."));
  byte access_bits[4] = {};
  mfrc522->MIFARE_SetAccessBits(&access_bits[0], ACCESS_BITS_g0, ACCESS_BITS_g1, ACCESS_BITS_g2, ACCESS_BITS_g3);
  if (
    trailer_buffer[6] == access_bits[0]
    && trailer_buffer[7] == access_bits[1]
    && trailer_buffer[8] == access_bits[2]
  ) {
    game_id = (uint8_t)get_value(GAME_ID_BLOCK);
    result = (game_id > 0);
    Serial.println(game_id);
  } else {
    Serial.println(F("invalid access bits"));
  }
  return result;
}


bool CardInterface::readCardId() {
  Serial.print(F("readCardId.."));
  card_id = (uint8_t)get_value(CARD_ID_BLOCK);
  Serial.println(card_id);
  return card_id > 0;
}


bool CardInterface::makeGameCard(uint8_t game_id, uint8_t card_id) {
  Serial.print(F("Personalizing the card in sector #")); Serial.print(DATA_SECTOR);
  Serial.print(F(" with game_id:")); Serial.print(game_id);
  Serial.print(F(" and card_id:")); Serial.println(card_id);

  byte buffer[16] = {};
  int32_t game_id_ex = game_id;
  int32_t card_id_ex = card_id;

  if (!auth_key_B()) return false; // assuming key B is required for block write

  format_value_block(GAME_ID_BLOCK, game_id_ex, BLOCK_ADDRESS);
  format_value_block(CARD_ID_BLOCK, card_id_ex, BLOCK_ADDRESS);
  write_block(NULL_BLOCK, buffer);

  setup_as_trailer_block(buffer, ACCESS_BITS_g0, ACCESS_BITS_g1, ACCESS_BITS_g2, ACCESS_BITS_g3);
  if (write_block(TRAILER_BLOCK, buffer)) {
    Serial.println(F("Personalization complete."));
    return true;
  } else {
    Serial.println(F("Personalization failed."));
    return false;
  }
}


bool CardInterface::factory_reset() {
  Serial.print(F("Reseting transport configuration for sector #"));
  Serial.println(DATA_SECTOR);

  byte buffer[16] = {};

  if (!auth_key_B()) return false; // assuming key B is required for block write

  write_block(GAME_ID_BLOCK, buffer);
  write_block(CARD_ID_BLOCK, buffer);
  write_block(NULL_BLOCK, buffer);

  setup_as_trailer_block(buffer, 0, 0, 0, 1);
  if (write_block(TRAILER_BLOCK, buffer)) {
    Serial.println(F("Reset complete."));
  }

  return auth_key_A();
}


void CardInterface::halt() {
  Serial.println(F("Ending card communication.\n"));
  mfrc522->PICC_HaltA();
  mfrc522->PCD_StopCrypto1();
  resetCardInfo();
}


void CardInterface::resetCardInfo() {
  this->is_card_read = false;
  this->card_id = 0;
  this->game_id = 0;
}


void CardInterface::dump_sector() {
  Serial.println(F("Current data in sector:"));
  mfrc522->PICC_DumpMifareClassicSectorToSerial(&(mfrc522->uid), key_pointer, DATA_SECTOR);
  Serial.println();
}


bool CardInterface::evaluate_status(MFRC522::StatusCode status) {
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("MIFARE transaction failed: "));
    Serial.println(mfrc522->GetStatusCodeName(status));
    return false;
  } else {
    return true;
  }
}


bool CardInterface::auth_key_A() {
  Serial.println(F("Authenticating using key A..."));
  return evaluate_status(
    mfrc522->PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, TRAILER_BLOCK, key_pointer, &(mfrc522->uid))
  );
}


bool CardInterface::auth_key_B() {
  Serial.println(F("Authenticating using key B..."));
  return evaluate_status(
    mfrc522->PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, TRAILER_BLOCK, key_pointer, &(mfrc522->uid))
  );
}


bool CardInterface::write_block(byte block, byte *buffer) {
  return evaluate_status(
    mfrc522->MIFARE_Write(block, buffer, 16)
  );
}


bool CardInterface::read_block(byte block, byte *buffer) {
  byte size = 18;
  return evaluate_status(
    mfrc522->MIFARE_Read(block, buffer, &size)
  );
}


int32_t CardInterface::get_value(byte block) {
  int32_t value = 0;
  evaluate_status(
    mfrc522->MIFARE_GetValue(block, &value)
  );
  return value;
}


bool CardInterface::read_trailer() {
  Serial.println(F("Reading sector trailer..."));
  return read_block(TRAILER_BLOCK, trailer_buffer);
}


void CardInterface::setup_as_trailer_block(byte *buffer, byte g0, byte g1, byte g2, byte g3) {
  for (byte i = 0; i < MFRC522::MF_KEY_SIZE; i++) {
      buffer[i] = key_pointer->keyByte[i];
      buffer[i + 10] = key_pointer->keyByte[i];
  }
  mfrc522->MIFARE_SetAccessBits(&buffer[6], g0, g1, g2, g3);
}


void CardInterface::format_value_block(byte block, int32_t initial_value, byte initial_address) {
  byte buffer[18];

  Serial.print(F("Reading block ")); Serial.println(block);

  if (!read_block(block, buffer)) {
    return;
  }

  if (    (buffer[0] == (byte)~buffer[4])
      &&  (buffer[1] == (byte)~buffer[5])
      &&  (buffer[2] == (byte)~buffer[6])
      &&  (buffer[3] == (byte)~buffer[7])

      &&  (buffer[0] == buffer[8])
      &&  (buffer[1] == buffer[9])
      &&  (buffer[2] == buffer[10])
      &&  (buffer[3] == buffer[11])

      &&  (buffer[12] == (byte)~buffer[13])
      &&  (buffer[12] ==        buffer[14])
      &&  (buffer[12] == (byte)~buffer[15])) {
      Serial.println(F("Block has correct Value Block format."));
  }

  Serial.print(F("Setting block value = ")); Serial.println(initial_value);

  int32_t initial_value_complement = ~initial_value;
  byte *vb = (byte*)&initial_value;
  byte *vbc = (byte*)&initial_value_complement;

  byte value_buffer[] = {
      *vb, *(vb + 1), *(vb + 2), *(vb + 3),
      *vbc, *(vbc + 1), *(vbc + 2), *(vbc + 3),
      *vb, *(vb + 1), *(vb + 2), *(vb + 3),
      initial_address,
      (byte)~initial_address,
      initial_address,
      (byte)~initial_address
  };
  write_block(block, value_buffer);
}


void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}
