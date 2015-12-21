#ifndef SeqRollingInTheDeep_h
#define SeqRollingInTheDeep_h

#include "cube_driver.h"

#define SEQ_RITD_UID      4
#define SEQ_RITD_CYCLES  10
#define SEQ_RITD_DELAY   50

/*
  This pattern does like a swiss roll effect
 */
void seq_rolling_in_the_deep(CubeDriver *cube_driver) {
  byte     layer;
  uint16_t data;

  cube_driver->updateUtilitySettings(SEQ_RITD_UID);

  for(int cycle=0; cycle < SEQ_RITD_CYCLES; cycle++) {

    for(int i=0; i < 26; i++) {

      switch(i) {

        case 0:
          layer = 0; data  = 0xF000; break;
        case 1:
        case 17:
          layer = 0; data  = 0x0F00; break;
        case 2:
        case 18:
          layer = 0; data  = 0x00F0; break;
        case 3:
        case 19:
          layer = 0; data  = 0x000F; break;
        case 4:
        case 20:
          layer = 1; data  = 0x000F; break;
        case 5:
        case 21:
          layer = 2; data  = 0x000F; break;
        case 6:
          layer = 3; data  = 0x000F; break;
        case 7:
          layer = 3; data  = 0x00F0; break;
        case 8:
          layer = 3; data  = 0x0F00; break;
        case 9:
          layer = 3; data  = 0xF000; break;
        case 10:
        case 24:
          layer = 2; data  = 0xF000; break;
        case 11:
        case 25:
          layer = 1; data  = 0xF000; break;
        case 12:
        case 16:
          layer = 1; data  = 0x0F00; break;
        case 13:
          layer = 1; data  = 0x00F0; break;
        case 14:
        case 22:
          layer = 2; data  = 0x00F0; break;
        case 15:
        case 23:
          layer = 2; data  = 0x0F00; break;

      }

      cube_driver->setLayer(layer, data);
      delay(SEQ_RITD_DELAY);
      cube_driver->setLayer(layer, 0);

    }

  }

  cube_driver->clearAllWithAnimation();
}


#endif
