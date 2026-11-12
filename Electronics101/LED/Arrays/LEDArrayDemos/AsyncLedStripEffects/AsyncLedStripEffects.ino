/*

  AsyncLedStripEffects

  Demonstrates timer-interrupt triggering of addressable LED array effects using the FlexiTimer2 library

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/LEDArrayDemos/AsyncLedStripEffects

*/

#define USE_TIMER // comment this out to use normal loop-based effect instead of FlexiTimer2

#include <FastLED.h>
#ifdef USE_TIMER
#include <FlexiTimer2.h>
#endif

#define NUM_LEDS 24  // How many leds in your strip?
#define DATA_PIN 6   // signal pin pin


CRGB leds[NUM_LEDS];

volatile byte led_scale = 0;
volatile boolean led_brighten = true;

void setup() {
  delay(2000); // sanity check delay

  // you might need to change this based on your LED strip
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);

  FastLED.clear();
  FastLED.setBrightness(32);

#ifdef USE_TIMER
  FlexiTimer2::set(10, redraw_led_effect);
  FlexiTimer2::start();
#endif
}

void loop() {
#ifndef USE_TIMER
  redraw_led_effect();
  delay(10);
#endif
}

/*
  update the LED Array effect.
  should call this every 10ms or so to get a nice glow
  This pulses/scales the brightness of all LEDs in a single color (green)
 */
void redraw_led_effect() {
  LEDS.showColor(CRGB(0, 128, 0), led_scale);

  if(led_brighten){
    led_scale++;
    if(led_scale==128) led_brighten = false;
  } else {
    led_scale--;
    if(led_scale==0) led_brighten = true;
  }
}
