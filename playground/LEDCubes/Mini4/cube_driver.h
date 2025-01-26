#ifndef CubeDriver_h
#define CubeDriver_h

#include <Arduino.h>

#define CUBE_LAYERS  4
#define CUBE_COLUMNS 4
#define CUBE_LAYER_LEDS (CUBE_COLUMNS * CUBE_COLUMNS)
#define CUBE_TOTAL_LEDS (CUBE_LAYER_LEDS * CUBE_LAYERS)

class CubeDriver {
  public:
    CubeDriver(int latch_pin, int clock_pin, int data_pin);

    void init();
    void reset();

    void redraw();
    void updateUtilitySettings(byte new_settings);
    void setLayer(byte layer, uint16_t data);
    void clearAll();
    void clearAllWithAnimation();
    void setAll();

  private:
    int latch_pin;
    int clock_pin;
    int data_pin;

    byte current_layer;                // current layer indicator
    uint16_t *layer_buffer;             // current LED cube settings (all layers)
    byte utility_settings;             // utility LED settings (lower 4 bits are significant)

};


#endif
