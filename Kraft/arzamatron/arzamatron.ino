/*

  arzamatron
  a simple sound-activated LED ornament

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Kraft/arzamatron

 */

#include <FlexiTimer2.h>

static const uint8_t MIC_PIN = A0;
static const uint8_t THREASHOLD_PIN = A1;
static const uint8_t BLUE_PIN = 5;
static const uint8_t WHITE_PIN = 6;

static const float SMOOTHING_FACTOR = 0.2;
static const uint8_t WHITE_THREASHOLD = 210;

volatile int mic_level = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(WHITE_PIN, OUTPUT);
  FlexiTimer2::set(10, read_mic);
  FlexiTimer2::start();
}

void loop() {
  static int white_level = 0;
  int current_mic_level = mic_level;

  Serial.println(current_mic_level);

  analogWrite(BLUE_PIN, current_mic_level / 4);
  if(current_mic_level / 4 > WHITE_THREASHOLD) white_level = 255;
  if(white_level > 10) {
    white_level =- 2;
  } else {
    white_level = 0;
  }
  analogWrite(WHITE_PIN, white_level);

  delay(25);
}

void read_mic() {
  int threshold_level = analogRead(THREASHOLD_PIN);
  int new_reading = map( analogRead(MIC_PIN), 0, 1023, 1023, 0);
  if(new_reading < threshold_level) new_reading = 0;
  mic_level = SMOOTHING_FACTOR * mic_level + (1.0 - SMOOTHING_FACTOR) * new_reading;
}
