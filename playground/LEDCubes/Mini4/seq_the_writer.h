#ifndef SeqTheWriter_h
#define SeqTheWriter_h

#include "cube_driver.h"
#include <stdlib.h>

#define SEQ_TW_UID     7
#define SEQ_TW_CYCLES  2
#define SEQ_TW_DELAY  50

/*
  This pattern sends a single on-LED 'writing' line by line
 */
void seq_the_writer(CubeDriver *cube_driver) {
  byte     layer;
  uint16_t data;
  div_t    positioning;

  cube_driver->updateUtilitySettings(SEQ_TW_UID);

  for(int cycle=0; cycle < SEQ_TW_CYCLES; cycle++) {

    for(int i=0; i < CUBE_TOTAL_LEDS; i++) {

      positioning = div (i, CUBE_LAYER_LEDS);

      layer = positioning.quot;
      data  = 1 << positioning.rem;

      cube_driver->setLayer(layer, data);
      delay(SEQ_TW_DELAY);
      cube_driver->setLayer(layer, 0);

    }

  }

  cube_driver->clearAllWithAnimation();
}


#endif
