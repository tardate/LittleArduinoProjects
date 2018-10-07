/*

  lite2sound-bc/CuttleTalk
  Playing audio from a Boldport Cuttle (Arduino) over LiFi with lite2sound

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/BoldportClub/lite2sound-bc/CuttleTalk

 */

#include <PCM.h>

/* audio sample definition */
#include "sample_saar_from_boldport.h"

/* playback control variables */
const int LOOP_DELAY_MILLISECONDS = 3000;


/*
 * Command: play the sample
 */
void play_sample() {
  startPlayback(sample, sizeof(sample));
  delay(LOOP_DELAY_MILLISECONDS);
}


void setup() {
}


void loop() {
  play_sample();
}
