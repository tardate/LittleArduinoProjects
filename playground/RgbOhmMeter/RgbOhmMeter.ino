/*

  RgbOhmMeter
  An auto-ranging ohmmeter that uses an LCD and RGB LEDs to display the bes-matched E24 standard resistor color code for the measured resistance.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/RgbOhmMeter

 */


#include <FlexiTimer2.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

#define MEASURE_PIN (A0)
const int MEASURE_SETTLE = 250;
const int MEASURE_STEP = 400;
const int VREF_MV = 4940;

uint32_t rx_measured = 0;
bool new_measurement = false;
float e24 = 0;
uint32_t e24_scale = 1;
uint8_t e24_n = 0;
uint8_t e24_colors[] = {0, 0, 0};

// array of {digital_pin, r1 resistor value} probes in order we should try (R1 large to small)
// NB: for most accurate readings, these R1 values should be measured and as close to actual as possible
uint32_t probes[][2] = {
  { 5, 100000 },
  { 4, 10000 },
  { 3, 1000 },
  { 2, 220 }
};

int probe_count = sizeof(probes) / (sizeof(uint32_t) * 2);

// names of the colors for LCD display
String color_codes[] = {
  "Blk", // Black
  "Brn", // Brown
  "Red", // Red
  "Org", // Orange
  "Ylw", // Yellow
  "Grn", // Green
  "Blu", // Blue
  "Vlt", // Violet
  "Gry", // Grey
  "Whi"  // White
};

const int RGB_REFRESH_PERIOD_MS = 1;

const int RGB_L1_PIN = 6;
const int RGB_L2_PIN = 7;
const int RGB_L3_PIN = 8;

const int RGB_PWM_R_PIN = 9;
const int RGB_PWM_G_PIN = 10;
const int RGB_PWM_B_PIN = 11;

volatile uint8_t current_rgb_digit = 0;
volatile bool rgb_on = false;

// RGB duty cycles for each color (inverted as "active low" PWM logic)
const uint8_t rgb_codes[][3] = {
  { 255 -   0, 255 -   0, 255 -   0 }, // Black
  { 255 -  22, 255 -   8, 255 -   0 }, // Brown
  { 255 - 255, 255 -   0, 255 -   0 }, // Red
  { 255 - 141, 255 -  13, 255 -   0 }, // Orange
  { 255 - 255, 255 - 252, 255 -   0 }, // Yellow
  { 255 -   0, 255 - 255, 255 -   0 }, // Green
  { 255 -   0, 255 -   0, 255 - 255 }, // Blue
  { 255 - 255, 255 -   0, 255 -  92 }, // Violet
  { 255 -   2, 255 -   1, 255 -   0 }, // Grey
  { 255 - 249, 255 - 253, 255 - 250 }  // White
};


/*
 * Command: one-time setup. Init the LCD and RGB LEDs
 */
void setup() {
  for (int probe = 0; probe < probe_count; ++probe) {
    pinMode(probes[probe][0], INPUT); // Hi-Z
  }
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  sayHello();
  setupRGB();
}


/*
 * Command: main loop. Tries to take a new measurement each time around
 */
void loop() {
  if (measure()) {
    if (new_measurement) {
      // only update displays if the measurement has changed
      sayReading();
      setRGB();
      new_measurement = false;
    }
  } else {
    // if we failed to get a measurement, revert to "scanning..." mode
    sayHello();
    clearRGB();
  }
  delay(MEASURE_STEP);
}


/*
 * Returns: true if we got a new measurement
 */
bool measure() {
  bool result = false;

  for (int probe = 0; probe < probe_count; ++probe) {
    if(measureProbe(probe)) {
      result = true;
      break;
    }
  }

  return result;
}


/*
 * Returns: true if we got a new measurement with the specified probe ("known resistor")
 */
bool measureProbe(int probe) {
  int probe_pin = probes[probe][0];
  uint32_t probe_r1 = probes[probe][1];

  pinMode(probe_pin, OUTPUT);
  digitalWrite(probe_pin, HIGH);
  delay(MEASURE_SETTLE);
  int vx_mv = map(analogRead(MEASURE_PIN), 0, 1023, 0, VREF_MV);
  pinMode(probe_pin, INPUT); // return to Hi-Z

  Serial.print("probe_pin: "); Serial.print(probe_pin);
  Serial.print("; probe_r1: "); Serial.print(probe_r1);
  Serial.print("; vx_mv: "); Serial.print(vx_mv);

  if (vx_mv > 1000 && vx_mv < 4000) {
    uint32_t new_rx_measured = (float) vx_mv * probe_r1 / (VREF_MV - vx_mv);
    Serial.print("; rx_measured: "); Serial.print(rx_measured);

    if (new_rx_measured != rx_measured) {
      rx_measured = new_rx_measured;
      new_measurement = true;
      estimateStandardValue(rx_measured);
    }
    Serial.println("");
    return true;
  } else {
    Serial.println("; skip");
    return false;
  }
}


/*
 * Command: brute force method that tries to match a standard resistor value
 */
void estimateStandardValue(uint32_t measured) {
  float e24_est = 0;

  e24_scale = 1;
  for (e24_n = 0; e24_n < 5; ++e24_n) {
    e24_scale = e24_scale * 10;
    e24_est = ((uint16_t)(10.0 * measured / e24_scale)) / 10.0;

    if (e24_est < 10) break;
  }
  Serial.print("; e24_est: "); Serial.print(e24_est);

  e24 = e24_est;
  if (e24_est > 1.3 && e24_est <= 1.5) e24 = 1.5; // E24 values: 1.0, 1.1, 1.2, 1.3, 1.5, 1.6,
  else if (e24_est > 1.6 && e24_est <= 1.8) e24 = 1.8; // 1.8,
  else if (e24_est > 1.8 && e24_est <= 2.0) e24 = 2.0; // 2.0,
  else if (e24_est > 2.0 && e24_est <= 2.2) e24 = 2.2; // 2.2,
  else if (e24_est > 2.2 && e24_est <= 2.5) e24 = 2.4; // 2.4,
  else if (e24_est > 2.5 && e24_est <= 2.8) e24 = 2.7; // 2.7,
  else if (e24_est > 2.8 && e24_est <= 3.1) e24 = 3.0; // 3.0,
  else if (e24_est > 3.1 && e24_est <= 3.4) e24 = 3.3; // 3.3,
  else if (e24_est > 3.4 && e24_est <= 3.7) e24 = 3.6; // 3.6,
  else if (e24_est > 3.7 && e24_est <= 4.0) e24 = 3.9; // 3.9,
  else if (e24_est > 4.9 && e24_est <= 4.4) e24 = 4.3; // 4.3,
  else if (e24_est > 4.4 && e24_est <= 4.8) e24 = 4.7; // 4.7,
  else if (e24_est > 4.8 && e24_est <= 5.2) e24 = 5.1; // 5.1,
  else if (e24_est > 5.2 && e24_est <= 5.7) e24 = 5.6; // 5.6,
  else if (e24_est > 5.7 && e24_est <= 6.3) e24 = 6.2; // 6.2,
  else if (e24_est > 6.3 && e24_est <= 7.1) e24 = 6.8; // 6.8,
  else if (e24_est > 7.1 && e24_est <= 7.8) e24 = 7.5; // 7.5,
  else if (e24_est > 7.8 && e24_est <= 8.7) e24 = 8.2; // 8.2,
  else if (e24_est > 8.7 && e24_est <= 9.4) e24 = 9.1; // 9.1
  else if (e24_est > 9.4) {
    e24 = 1.0;
    e24_scale = e24_scale * 10;
    ++e24_n;
  }
  Serial.print("; e24_n: "); Serial.print(e24_n);
  Serial.print("; e24_scale: "); Serial.print(e24_scale);
  Serial.print("; e24: "); Serial.print(e24);
  Serial.print("; closest_standard_value: "); Serial.print(e24 * e24_scale);

  e24_colors[0] = (uint8_t)e24;
  e24_colors[1] = (uint8_t)(e24 * 10) % 10;
  e24_colors[2] = e24_n;
}


/*
 * Command: set LCD to display "scanning.." mode
 */
void sayHello() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("RGB Ohmmeter"));
  lcd.setCursor(0, 1);
  lcd.print(F("scanning.."));
}


/*
 * Command: set LCD to display the reading
 */
void sayReading() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(rx_measured);
  lcd.write(0xF4);
  sayStandardValue();
  lcd.setCursor(0, 1);
  sayColorCode();
}

/*
 * Command: write standard resistance value to LCD current position
 */
void sayStandardValue() {
  uint32_t rx_closest_standard_value = e24 * e24_scale;

  lcd.print(" (");
  if (rx_closest_standard_value < 10000) {
    lcd.print(rx_closest_standard_value);
    lcd.print(")");
  } else {
    lcd.print(rx_closest_standard_value / 1000);
    lcd.print("k)");
  }
}

/*
 * Command: write standard resistance value color codes to LCD current position
 */
void sayColorCode() {
  lcd.print(color_codes[e24_colors[0]]);
  lcd.print("-");
  lcd.print(color_codes[e24_colors[1]]);
  lcd.print("-");
  lcd.print(color_codes[e24_colors[2]]);
}


/*
 * Command: init the RGB pins and start the display timer
 */
void setupRGB() {
  pinMode(RGB_L1_PIN, INPUT);
  pinMode(RGB_L2_PIN, INPUT);
  pinMode(RGB_L3_PIN, INPUT);
  pinMode(RGB_PWM_R_PIN, OUTPUT);
  pinMode(RGB_PWM_G_PIN, OUTPUT);
  pinMode(RGB_PWM_B_PIN, OUTPUT);
  FlexiTimer2::set(RGB_REFRESH_PERIOD_MS, rgb_refresh);
  FlexiTimer2::start();
}


/*
 * Command: set RGB to value display mode (i.e. reading available)
 */
void setRGB() {
  pinMode(RGB_L1_PIN, OUTPUT);
  pinMode(RGB_L2_PIN, OUTPUT);
  pinMode(RGB_L3_PIN, OUTPUT);
  digitalWrite(RGB_L1_PIN, LOW);
  digitalWrite(RGB_L2_PIN, LOW);
  digitalWrite(RGB_L3_PIN, LOW);
  rgb_on = true;
}


/*
 * Command: set RGB to no output (i.e. no reading available)
 */
void clearRGB() {
  rgb_on = false;
  pinMode(RGB_L1_PIN, INPUT);
  pinMode(RGB_L2_PIN, INPUT);
  pinMode(RGB_L3_PIN, INPUT);
}


/*
 * ISR: multiplexes the RGB output - steps to the next LED
 */
void rgb_refresh() {
  if (!rgb_on) return;

  if (++current_rgb_digit > 2) current_rgb_digit = 0;

  switch (current_rgb_digit) {
    case 0:
      digitalWrite(RGB_L3_PIN, LOW);
      analogWrite(RGB_PWM_R_PIN, rgb_codes[e24_colors[0]][0]);
      analogWrite(RGB_PWM_G_PIN, rgb_codes[e24_colors[0]][1]);
      analogWrite(RGB_PWM_B_PIN, rgb_codes[e24_colors[0]][2]);
      digitalWrite(RGB_L1_PIN, HIGH);
      break;
    case 1:
      digitalWrite(RGB_L1_PIN, LOW);
      analogWrite(RGB_PWM_R_PIN, rgb_codes[e24_colors[1]][0]);
      analogWrite(RGB_PWM_G_PIN, rgb_codes[e24_colors[1]][1]);
      analogWrite(RGB_PWM_B_PIN, rgb_codes[e24_colors[1]][2]);
      digitalWrite(RGB_L2_PIN, HIGH);
      break;
    case 2:
      digitalWrite(RGB_L2_PIN, LOW);
      analogWrite(RGB_PWM_R_PIN, rgb_codes[e24_colors[2]][0]);
      analogWrite(RGB_PWM_G_PIN, rgb_codes[e24_colors[2]][1]);
      analogWrite(RGB_PWM_B_PIN, rgb_codes[e24_colors[2]][2]);
      digitalWrite(RGB_L3_PIN, HIGH);
      break;
  }
}
