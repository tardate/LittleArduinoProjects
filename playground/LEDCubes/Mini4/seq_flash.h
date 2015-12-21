#ifndef SeqFlash_h
#define SeqFlash_h

#include "cube_driver.h"

#define SEQ_FLASH_UID      1
#define SEQ_FLASH_REPEATS  2
#define SEQ_FLASH_CYCLES   8
#define SEQ_FLASH_DELAY  240

/*
  This pattern flashes the entire cube on and off
 */
void seq_flash(CubeDriver *cube_driver) {
  int delay_ms;

  cube_driver->updateUtilitySettings(SEQ_FLASH_UID);

  for(int repeats=0; repeats < SEQ_FLASH_REPEATS; repeats++) {

    delay_ms = SEQ_FLASH_DELAY;

    for(int cycles=0; cycles < SEQ_FLASH_CYCLES; cycles++) {

      cube_driver->setAll();
      delay(delay_ms);
      cube_driver->clearAll();
      delay(delay_ms);
      delay_ms /= 2;

    }

  }

  cube_driver->clearAllWithAnimation();
}


#endif
