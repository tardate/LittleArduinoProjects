/*

  Internals

  Dump to serial any and all internal details of the Arduino baord we can muster

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/Internals

 */

#pragma GCC optimize ("-O0") // avoid GCC memcpy inline

#define DEBUG  1 // Enables full diagnostic reporting

#include <avr/boot.h>
#include <avr/pgmspace.h>
#include <string.h>  // for memcpy
#include "quirks.h"
#include "utilities.h"

extern "C" {
  #include "md5.h"
}

byte readFlash(unsigned long addr) {
#if FLASHEND > 0xFFFF
    return pgm_read_byte_far(addr);
#else
    return pgm_read_byte_near(addr);
#endif
}

typedef struct {
   byte sig[3];
   const char * desc;
   unsigned long flashSize;
   unsigned int baseBootSize;
} signatureType;

const unsigned long kb = 1024;

// number of items in an array
#define NUMITEMS(arg) ((unsigned int) (sizeof (arg) / sizeof (arg [0])))

// see Atmega328 datasheet page 298
const signatureType signatures[] = {
//     signature          description   flash size  bootloader size

  // Attiny84 family
  { { 0x1E, 0x91, 0x0B }, "ATtiny24",   2 * kb,         0 },
  { { 0x1E, 0x92, 0x07 }, "ATtiny44",   4 * kb,         0 },
  { { 0x1E, 0x93, 0x0C }, "ATtiny84",   8 * kb,         0 },

  // Attiny85 family
  { { 0x1E, 0x91, 0x08 }, "ATtiny25",   2 * kb,         0 },
  { { 0x1E, 0x92, 0x06 }, "ATtiny45",   4 * kb,         0 },
  { { 0x1E, 0x93, 0x0B }, "ATtiny85",   8 * kb,         0 },

  // Atmega328 family
  { { 0x1E, 0x92, 0x0A }, "ATmega48PA",   4 * kb,         0 },
  { { 0x1E, 0x93, 0x0F }, "ATmega88PA",   8 * kb,       256 },
  { { 0x1E, 0x94, 0x0B }, "ATmega168PA", 16 * kb,       256 },
  { { 0x1E, 0x94, 0x06 }, "ATmega168V",  16 * kb,       256 },
  { { 0x1E, 0x95, 0x0F }, "ATmega328P",  32 * kb,       512 },
  { { 0x1E, 0x95, 0x16 }, "ATmega328PB", 32 * kb,       512 },

  // Atmega644 family
  { { 0x1E, 0x94, 0x0A }, "ATmega164P",   16 * kb,      256 },
  { { 0x1E, 0x95, 0x08 }, "ATmega324P",   32 * kb,      512 },
  { { 0x1E, 0x96, 0x0A }, "ATmega644P",   64 * kb,   1 * kb },

  // Atmega2560 family
  { { 0x1E, 0x96, 0x08 }, "ATmega640",    64 * kb,   1 * kb },
  { { 0x1E, 0x97, 0x03 }, "ATmega1280",  128 * kb,   1 * kb },
  { { 0x1E, 0x97, 0x04 }, "ATmega1281",  128 * kb,   1 * kb },
  { { 0x1E, 0x98, 0x01 }, "ATmega2560",  256 * kb,   1 * kb },
  { { 0x1E, 0x98, 0x02 }, "ATmega2561",  256 * kb,   1 * kb },

  // AT90USB family
  { { 0x1E, 0x93, 0x82 }, "At90USB82",    8 * kb, 512,  },
  { { 0x1E, 0x94, 0x82 }, "At90USB162",  16 * kb, 512,  },

  // Atmega32U2 family
  { { 0x1E, 0x93, 0x89 }, "ATmega8U2",    8 * kb,   512 },
  { { 0x1E, 0x94, 0x89 }, "ATmega16U2",  16 * kb,   512 },
  { { 0x1E, 0x95, 0x8A }, "ATmega32U2",  32 * kb,   512 },

  // Atmega32U4 family
  { { 0x1E, 0x94, 0x88 }, "ATmega16U4",  16 * kb,   512 },
  { { 0x1E, 0x95, 0x87 }, "ATmega32U4",  32 * kb,   512 },

  // ATmega1284P family
  { { 0x1E, 0x97, 0x05 }, "ATmega1284P", 128 * kb,   1 * kb },
  { { 0x1E, 0x97, 0x06 }, "ATmega1284",  128 * kb,   1 * kb },

  // ATtiny4313 family
  { { 0x1E, 0x91, 0x0A }, "ATtiny2313A", 2 * kb,   0 },
  { { 0x1E, 0x92, 0x0D }, "ATtiny4313",  4 * kb,   0 },

  // ATtiny13 family
  { { 0x1E, 0x90, 0x07 }, "ATtiny13A",   1 * kb,   0 },

  // Atmega8A family
  { { 0x1E, 0x93, 0x07 }, "ATmega8A",    8 * kb,  256 },
};

// if signature found in above table, this is its index
int found_sig_index = -1;


void readBootloader() {
  unsigned long bootloader_addr;
  unsigned int  bootloader_size;

  if (signatures[found_sig_index].baseBootSize == 0) {
    Serial.println (F("No bootloader support."));
    return;
  }

  byte hFuse = boot_lock_fuse_bits_get(GET_HIGH_FUSE_BITS);

  Serial.print(F("Bootloader in use: "));
  showYesNo((hFuse & bit (0)) == 0, true);
  Serial.print(F("EEPROM preserved through erase: "));
  showYesNo((hFuse & bit (3)) == 0, true);
  Serial.print(F("Watchdog timer always on: "));
  showYesNo((hFuse & bit (4)) == 0, true);

  // work out bootloader size
  // these 2 bits basically give a base bootloader size multiplier
  bootloader_size = signatures[found_sig_index].baseBootSize;
  switch ((hFuse >> 1) & 3) {
    case 0: bootloader_size *= 8; break;
    case 1: bootloader_size *= 4; break;
    case 2: bootloader_size *= 2; break;
    case 3: bootloader_size *= 1; break;
  }

  bootloader_addr = signatures[found_sig_index].flashSize - bootloader_size;

  Serial.print(F("Bootloader is "));
  Serial.print(bootloader_size);
  Serial.print(F(" bytes starting at "));
  Serial.println(bootloader_addr, HEX);

  for (unsigned int i = 0; i < bootloader_size; i++) {
    // show address
    if (i % 16 == 0) {
      Serial.print(bootloader_addr + i, HEX);
      Serial.print(": ");
    }
    showHex(readFlash(bootloader_addr + i), false, false);
    // new line every 16 bytes
    if (i % 16 == 15) Serial.println ();
  }

  Serial.println();
  Serial.print(F("MD5 sum of bootloader = "));

  md5_context ctx;
  byte md5sum[16];
  byte mem;

  md5_starts( &ctx );

  while (bootloader_size--) {
    mem = readFlash(bootloader_addr++);
    md5_update( &ctx, &mem, 1);
  }

  md5_finish( &ctx, md5sum );

  for (unsigned int i = 0; i < sizeof md5sum; i++)
    showHex(md5sum[i]);
  Serial.println();
}


void find_signature() {
  byte sig[3];

  Serial.print(F("Signature: "));

  sig[0] = boot_signature_byte_get(0);
  sig[1] = boot_signature_byte_get(2);
  sig[2] = boot_signature_byte_get(4);

  showHex(sig[0], false, true, false);
  showHex(sig[1], false, false, false);
  showHex(sig[2], true, false, false);

  for (unsigned int j = 0; j < NUMITEMS(signatures); j++) {
    if (memcmp(sig, signatures[j].sig, sizeof sig) == 0) {
      found_sig_index = j;
      return;
    }
  }
  Serial.println(F("Unrecogized signature."));
}


/*
  display intro
 */
void prologue() {
  hr();
  Serial.println(F("A Rundown of the Board Internals"));
  Serial.print(F("Compiled on " __DATE__ " at " __TIME__ " with Arduino IDE "));
  Serial.print(ARDUINO);
  Serial.println(F("."));
}


/*
  display processor details
 */
void processorDetails() {

  Serial.print(F("Processor: "));
  if(found_sig_index==-1) Serial.println(F("n/a"));
  else Serial.println(signatures[found_sig_index].desc);

  Serial.print(F("Clock speed: "));
  Serial.print(clockCyclesPerMicrosecond());
  Serial.println(F(" MHz"));

  Serial.println(F("Fuses:"));
  byte fuse;

  Serial.print(F("  Low:  "));
  fuse = boot_lock_fuse_bits_get(GET_LOW_FUSE_BITS);
  Serial.println(fuse, BIN);
  Serial.print(F("  High: "));
  fuse = boot_lock_fuse_bits_get(GET_HIGH_FUSE_BITS);
  Serial.println(fuse, BIN);
  Serial.print(F("  Ext:  "));
  fuse = boot_lock_fuse_bits_get(GET_EXTENDED_FUSE_BITS);
  Serial.println(fuse, BIN);
  Serial.print(F("  Lock: "));
  fuse = boot_lock_fuse_bits_get(GET_LOCK_BITS);
  Serial.println(fuse, BIN);
}


/*
  Return the amount of free RAM
 */
void memoryMap() {
  // extern int __bss_end;
  extern unsigned int __heap_start, __heap_end;
  extern unsigned int __data_start, __data_end;
  extern unsigned int __bss_start, __bss_end;
  extern void *__brkval;

  int free_memory;

  if((int)__brkval == 0)
    free_memory = ((int)&free_memory) - ((int)&__bss_end);
  else
    free_memory = ((int)&free_memory) - ((int)__brkval);

  Serial.println(F("Memory Map:"));
  showHex4((unsigned int)&__data_start);       Serial.println(F(" __data_start"));
  showHex4((unsigned int)&__data_end);         Serial.println(F(" __data_end"));
  showHex4((unsigned int)&__bss_start);        Serial.println(F(" __bss_start"));
  showHex4((unsigned int)&__bss_end);          Serial.println(F(" __bss_end"));
  showHex4((unsigned int)&__heap_start);       Serial.println(F(" __heap_start"));
  showHex4((unsigned int)&__heap_end);         Serial.println(F(" __heap_end"));
  showHex4((unsigned int)&__brkval);           Serial.println(F(" __brkval"));
  showHex4((unsigned int)__malloc_heap_start); Serial.println(F(" __malloc_heap_start"));
  showHex4((unsigned int)__malloc_heap_end);   Serial.println(F(" __malloc_heap_end"));

  Serial.print(F("Free memory: "));
  Serial.print(free_memory);                   Serial.println(F(" bytes"));
  #ifdef DEBUG
    showHex4((unsigned int)&free_memory);        Serial.println(F(" &free_memory"));
  #endif
}


/*
  display memory details
 */
void memoryDetails() {
  Serial.print(F("Flash memory size: "));
  if(found_sig_index==-1) Serial.print(F("n/a"));
  else Serial.print(signatures[found_sig_index].flashSize, DEC);
  Serial.println(F(" bytes"));

  Serial.print(F("Flash Page Size: "));
  #ifdef SPM_PAGESIZE
    Serial.print(SPM_PAGESIZE);
    Serial.println(F(" bytes"));
  #else
    Serial.println(F(" not available"));
  #endif

  Serial.print(F("Last Flash Address: "));
  #ifdef FLASHEND
    showHex4(FLASHEND, true);
  #else
    Serial.println(F(" not available"));
  #endif

  Serial.print(F("Last RAM Address: "));
  #ifdef RAMEND
    showHex4(RAMEND, true);
  #else
    Serial.println(F(" not available"));
  #endif

  Serial.print(F("Last Extended RAM Address: "));
  #ifdef XRAMEND
    showHex4(XRAMEND, true);
  #else
    Serial.println(F(" not available"));
  #endif
}


/*
  display EEPROM details
 */
void eepromDetails() {
  Serial.print(F("EEPROM memory: "));
  #ifdef E2END
    Serial.print(E2END + 1);
    Serial.println(F(" bytes"));
  #else
    Serial.println(F(" not available"));
  #endif

  Serial.print(F("EEPROM page size: "));
  #ifdef E2PAGESIZE
    Serial.print(E2PAGESIZE);
    Serial.println(F(" bytes"));
  #else
    Serial.println(F(" not available"));
  #endif
}


/*
  display pin details
 */
void pinDetails() {
  Serial.print(F("Number of digital pins: "));
  Serial.println(NUM_DIGITAL_PINS);
  for(int p = 0; p < NUM_DIGITAL_PINS; p++) {
    Serial.print(p);
    Serial.print(F(":"));
    if(digitalPinToInterrupt(p) != NOT_AN_INTERRUPT) {
      Serial.print(F(" (interrupt:"));
      Serial.print(digitalPinToInterrupt(p));
      Serial.print(F(")"));
    }
    if(p == LED_BUILTIN) Serial.print(F(" (internal LED)"));
    if(digitalPinHasPWM(p)) Serial.print(F(" (PWM)"));
    Serial.println();

  }
  Serial.print(F("Number of analog inputs: "));
  Serial.println(NUM_ANALOG_INPUTS);
  for(int p = 0; p < NUM_ANALOG_INPUTS; p++) {
    Serial.print(F("A"));
    Serial.print(p);
    Serial.print(F(":"));
    Serial.print(F(" (pin:"));
    Serial.print(analogInputToDigitalPin(p));
    Serial.print(F(")"));
    Serial.println();
  }
}


void setup () {
  Serial.begin (115200);
  while (!Serial) {}

  prologue();

  find_signature();

  processorDetails();
  hr();
  pinDetails();
  hr();
  memoryMap();
  hr();
  memoryDetails();
  hr();
  eepromDetails();
  hr();

  if (found_sig_index != -1) {
    readBootloader ();
  }
}


void loop () {}
