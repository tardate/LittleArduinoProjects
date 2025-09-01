/*

  nRF24/Scanner
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/nRF24/Scanner

 */

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <nRF24L01.h>
#include <RF24.h>

#include "settings.h"

const int RADIO_SS_PIN  = 8;
const int RADIO_CSN_PIN = 9;

const int LCD_SS_PIN = 4;
const int LCD_CSN_PIN = 3;
const int LCD_RST_PIN = 5;
const int LCD_MOSI_PIN = 6;
const int LCD_SCK_PIN = 7;



//
// Hardware configuration
//

RF24 radio(RADIO_SS_PIN, RADIO_CSN_PIN);
Adafruit_PCD8544 lcd = Adafruit_PCD8544(LCD_SCK_PIN, LCD_MOSI_PIN, LCD_CSN_PIN, LCD_SS_PIN, LCD_RST_PIN);

//
// Channel metrics
//
const uint8_t SCAN_SAMPLES = 100;
const uint8_t CHANNELS = 128;
uint8_t channel_counters[CHANNELS];
uint8_t channel_samples[CHANNELS];

//
// Mode Switch Support
//
const int MODE_SWITCH_PIN = 2;
const int MODES = 2;
volatile int mode = 0;
volatile bool mode_changed = false;

void handle_mode_switch() {
  if(mode_changed) return;
  mode_changed = true;
  ++mode;
  if(mode>=MODES) mode=0;
}

/*
 * Setup
 */
void setup(void)
{
  pinMode(MODE_SWITCH_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(MODE_SWITCH_PIN), handle_mode_switch, FALLING);

  // clear metrics
  memset(channel_counters, 0, sizeof(channel_counters));
  clearSamples();

  #ifdef SERIAL_DEBUG
  Serial.begin(57600);
  Serial.println("nRF24/Scanner");
  // Print out header, high then low digit
  for(uint8_t i=0; i < CHANNELS; ++i) Serial.print(i>>4, HEX);
  Serial.println("");
  for(uint8_t i=0; i < CHANNELS; ++i) Serial.print(i&0xf, HEX);
  Serial.println("");
  #endif

  // Setup screen
  lcd.begin();
  lcd.setContrast(50);

  // Setup and configure rf radio
  // and get into standby mode
  //
  radio.begin();
  radio.setAutoAck(false);
  radio.startListening();
  radio.stopListening();

  updateDisplay();
}

/*
 * main loop
 */
void loop(void) {
  clearSamples();

  // Scan all channels
  for(uint8_t rep_counter=0; rep_counter < SCAN_SAMPLES; ++rep_counter) {
    for(uint8_t channel=0; channel < CHANNELS; ++channel) {
      // Select this channel
      radio.setChannel(channel);

      // Listen for a little
      radio.startListening();
      delayMicroseconds(128);
      radio.stopListening();

      // Did we get a carrier?
      if(radio.testCarrier()) {
        ++channel_samples[channel];
        ++channel_counters[channel];
      }
    }
  }

  updateDisplay();
  mode_changed = false;

  #ifdef SERIAL_DEBUG
  // Print out channel measurements, clamped to a single hex digit
  for(uint8_t i=0; i < CHANNELS; ++i) Serial.print(min(0xf,channel_samples[i]&0xf), HEX);
  Serial.println("");
  #endif

}

/*
 * clear the sample array
 */
void clearSamples() {
  memset(channel_samples, 0, sizeof(channel_samples));
}

const int GRAPH_X_OFFSET = 16;
const int GRAPH_X_WIDTH = 64;
const int GRAPH_Y0_OFFSET = 31;
const int GRAPH_Y1_OFFSET = GRAPH_Y0_OFFSET + 16;
const int GRAPH_Y_MAX = 12;

/*
 * update LCD display
 */
void updateDisplay() {
  lcd.clearDisplay();
  lcd.setTextSize(1);

  lcd.setCursor(0, 10);
  lcd.setTextColor(WHITE, BLACK);
  switch(mode) {
  case 1:
    lcd.println("cummulative");
    break;
  default:
    lcd.println("current");
  }

  lcd.setTextColor(BLACK);
  lcd.setCursor(0, 0);
  lcd.println("nRF24 Scanner");


  lcd.setCursor(0, GRAPH_Y0_OFFSET - 6);
  lcd.println(" 0");
  lcd.setCursor(0, GRAPH_Y1_OFFSET - 6);
  lcd.println("64");


  for(uint8_t channel=0; channel < CHANNELS; ++channel) {
    uint8_t dY;
    switch(mode) {
    case 1:
      dY = min(GRAPH_Y_MAX, channel_counters[channel]);
      break;
    default:
      dY = min(GRAPH_Y_MAX, channel_samples[channel]);
    }

    if(channel < GRAPH_X_WIDTH) {
      lcd.drawLine(
        GRAPH_X_OFFSET + channel,
        GRAPH_Y0_OFFSET - dY,
        GRAPH_X_OFFSET + channel,
        GRAPH_Y0_OFFSET,
        BLACK
      );
    } else {
      lcd.drawLine(
        GRAPH_X_OFFSET + channel - GRAPH_X_WIDTH,
        GRAPH_Y1_OFFSET - dY,
        GRAPH_X_OFFSET + channel - GRAPH_X_WIDTH,
        GRAPH_Y1_OFFSET,
        BLACK
      );
    }

  }
  lcd.display();
}
