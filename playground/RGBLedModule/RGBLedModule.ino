/*

  RGBLedModule
  Demo an RGB LED module

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/RGBLedModule

 */

#define RED_LED_PIN    9
#define GREEN_LED_PIN 10
#define BLUE_LED_PIN  11

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup() {
  pinMode(RED_LED_PIN,   OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN,  OUTPUT);
}

void loop() {
  glow();
  pause();
  colorTester();
  pause();
}

void pause() {
  clear();
  delay(100);
}

void glow() {
  int step=1;
  int step_delay=2;

  for(int r=0; r<256; r+=step) setColor(r,0,0,step_delay);
  for(int r=255; r>=0; r-=step) setColor(r,0,0,step_delay);

  for(int g=0; g<256; g+=step) setColor(0,g,0,step_delay);
  for(int g=255; g>=0; g-=step) setColor(0,g,0,step_delay);

  for(int b=0; b<256; b+=step) setColor(0,0,b,step_delay);
  for(int b=255; b>=0; b-=step) setColor(0,0,b,step_delay);
}

void colorTester() {
  int step_delay=250;
  setColor( 80,  0,  0,step_delay);
  setColor(160,  0,  0,step_delay);
  setColor(  0, 80,  0,step_delay);
  setColor(  0,160,  0,step_delay);
  setColor(  0,  0, 80,step_delay);
  setColor(  0,  0,160,step_delay);
  setColor( 80,  0, 80,step_delay);
  setColor(160,  0,160,step_delay);
  setColor(  0, 80, 80,step_delay);
  setColor(  0,160,160,step_delay);
  setColor( 80, 80,  0,step_delay);
  setColor(160,160,  0,step_delay);
}

void clear() {
  setColor(0,0,0);
}

void setColor(int red, int green, int blue) {
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(RED_LED_PIN, red);
  analogWrite(GREEN_LED_PIN, green);
  analogWrite(BLUE_LED_PIN, blue);
}

void setColor(int red, int green, int blue, int step_delay) {
  setColor(red, green, blue);
  delay(step_delay);
}
