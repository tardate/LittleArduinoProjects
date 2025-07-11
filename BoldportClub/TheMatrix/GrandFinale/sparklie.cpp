#include "Arduino.h"
#include "sparklie.h"

#define MAX_HEIGHT         (23)  // cheat: max-width of the matrix (0-based)
#define MAX_DISPLACEMENT   (4)   // cheat: max-height of the matrix (0-based)
#define MAX_TICKS_PER_STEP (12)


Sparklie::Sparklie() {
  this->alive = false;
  this->x = 0;
  this->y = 2;
}


bool Sparklie::recalculate(bool with_regeneration, uint8_t custom_height, uint8_t custom_velocity) {
  if(alive) {
    if(++(this->tick_counter) >= ticks_per_step) {
      this->tick_counter = 0;
      // move
      if(up) {
        ++(this->x);
        if(x==max_height) {

          this->up = false;
          this->ticks_per_step += random(2, 6);
        } else if(x==max_height - 1) {
          switch(max_displacement) {
          case 0:
            this->y = 1;
            break;
          case 4:
            this->y = 3;
            break;
          }
        }
      } else {
        if(x>0) {
          --(this->x);
          this->y = max_displacement;
        } else if(--(this->ttl) == 0) this->alive = false;
      }
    }
  } else {
    if(with_regeneration && shouldRegenerate()) initialiseSettings(custom_height, custom_velocity);
  }
  return alive;
}


void Sparklie::clear(lr::AS1130Picture24x5& page) {
  page.setPixel(MAX_HEIGHT - x, y, false);
}


void Sparklie::draw(lr::AS1130Picture24x5& page, lr::AS1130& driver) {
  if(alive) {
    if(!up && ((x == MAX_HEIGHT) || (!page.getPixel(MAX_HEIGHT - x, y)))) {
      uint8_t led_index = driver.getLedIndex24x5(MAX_HEIGHT - x, y);
      driver.setPwmValue(0, led_index, random(32, 200));
    }
    page.setPixel(MAX_HEIGHT - x, y, true);
  }
}


void Sparklie::initialiseSettings(uint8_t custom_height, uint8_t custom_velocity) {
  randomSeed(analogRead(0));
  this->alive = true;
  this->x = 0;
  this->y = 2;
  if (custom_height > MAX_HEIGHT) {
    this->max_height = MAX_HEIGHT;
  } else {
    this->max_height = custom_height;
  }
  this->max_displacement = random(0, MAX_DISPLACEMENT + 1);
  this->ttl = random(4, 35);
  if (custom_velocity > MAX_TICKS_PER_STEP - 2) {
    this->ticks_per_step = 2;
  } else {
    this->ticks_per_step = MAX_TICKS_PER_STEP - custom_velocity;
  }
  this->tick_counter = 0;
  this->up = true;
}


bool Sparklie::shouldRegenerate() {
  return random(100) > 97;
}
