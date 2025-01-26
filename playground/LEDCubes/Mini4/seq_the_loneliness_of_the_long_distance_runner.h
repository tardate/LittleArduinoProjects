#ifndef SeqTLOTLDR_h
#define SeqTLOTLDR_h

#include "cube_driver.h"
#include <stdlib.h>

#define SEQ_TLOTLDR_UID     2
#define SEQ_TLOTLDR_CYCLES  2
#define SEQ_TLOTLDR_DELAY  50

/*
  This pattern sends a single on-LED around the cube on a marathon
 */
void seq_the_loneliness_of_the_long_distance_runner(CubeDriver *cube_driver) {
  byte     layer;
  byte     row;
  byte     offset;
  uint16_t data;
  div_t    layering;
  div_t    rows;

  cube_driver->updateUtilitySettings(SEQ_TLOTLDR_UID);

  for(int cycle=0; cycle < SEQ_TLOTLDR_CYCLES; cycle++) {

    for(int i=0; i < CUBE_TOTAL_LEDS; i++) {

      layering = div (i, CUBE_LAYER_LEDS);
      rows     = div (layering.rem, CUBE_COLUMNS);

      layer = layering.quot;
      row   = rows.quot;

      offset = row * CUBE_COLUMNS;

      if(layer % 2 > 0) {

        if(row % 2 > 0) {
          offset += rows.rem;
        } else {
          offset += CUBE_COLUMNS - rows.rem - 1;
        }
        data = 1 << offset;

      } else {

        if(row % 2 > 0) {
          offset += CUBE_COLUMNS - rows.rem - 1;
        } else {
          offset += rows.rem;
        }
        data = 1 << (CUBE_LAYER_LEDS - offset - 1);

      }

      cube_driver->setLayer(layer, data);
      delay(SEQ_TLOTLDR_DELAY);
      cube_driver->setLayer(layer, 0);

    }

  }

  cube_driver->clearAllWithAnimation();
}


#endif
