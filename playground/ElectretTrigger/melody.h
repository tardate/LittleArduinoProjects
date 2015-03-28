
#include "pitches.h"

#define BPM 145       // beats per minute for the playboack

// notes in the melody:
int melody[] = {
  NOTE_C5,
  NOTE_C4,
  NOTE_C5,
  NOTE_C5,
  NOTE_C4,
  NOTE_C5,
  NOTE_C6,
  NOTE_C5,

};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  32,
  32,
  32,
  32,
  32,
  16,
  16,
  16
 
};

const int noteCount = sizeof(melody) / sizeof(int);

