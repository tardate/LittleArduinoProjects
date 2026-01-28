/*

  BMP280 Module

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/BMP280/Module

 */

#include  <Adafruit_BMP280.h>
#include <U8x8lib.h>

U8X8_SSD1306_128X32_UNIVISION_HW_I2C oled(U8X8_PIN_NONE);
const uint8_t * LARGE_FONT = u8x8_font_px437wyse700a_2x2_r;
const uint8_t * SMALL_FONT = u8x8_font_amstrad_cpc_extended_r;
const uint32_t SERIAL_SPEED = 115200;

const int LED_PIN = 13;
const uint16_t SAMPLING_DELAY = 2000;
const uint16_t SPLASH_DELAY = 2000;
const int SENSOR_ADDRESS = 0x76;
const float SEA_LEVEL_PRESSURE = 1013.0;

Adafruit_BMP280 bmp;

/*
 * Command: one-time setup
 */
void setup() {
  pinMode(LED_PIN, OUTPUT);

  oled.begin();
  oled.setFont(LARGE_FONT);
  oled.drawString(2, 0, "BMP280");
  oled.setFont(SMALL_FONT);
  oled.drawString(0, 2, "Pressure  Sensor");
  oled.drawString(0, 3, "leap.tardate.com");

  Serial.begin(115200);
  while (!Serial) delay(100);
  Serial.println(F("BMP280 Pressure Sensor"));
  Serial.println();
  Serial.println(F("| Temperature | Pressure    | Altitude |"));
  Serial.println(F("|-------------|-------------|----------|"));

  if  (!bmp.begin(SENSOR_ADDRESS)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1) delay(10);
  }

  /* Default settings from datasheet.  */
  bmp.setSampling(
    Adafruit_BMP280::MODE_NORMAL,    /* Operating Mode. */
    Adafruit_BMP280::SAMPLING_X2,    /* Temp. oversampling */
    Adafruit_BMP280::SAMPLING_X16,   /* Pressure oversampling */
    Adafruit_BMP280::FILTER_X16,     /* Filtering. */
    Adafruit_BMP280::STANDBY_MS_500  /* Standby time. */
  );

  delay(SPLASH_DELAY);

  oled.clearDisplay();
  oled.setFont(LARGE_FONT);
  oled.drawString(13, 0, "C");
  oled.setFont(SMALL_FONT);
  oled.drawString(13, 2, "hPa");
  oled.drawString(13, 3, "m");
}


/*
 * Command: main loop
 */
void loop() {
  digitalWrite(LED_PIN, HIGH);

  static char temperature[15], pressure[15], altitude[15];

  dtostrf(bmp.readTemperature(), 5, 2, temperature);
  dtostrf(bmp.readPressure()/100, 7, 2, pressure);
  dtostrf(bmp.readAltitude(SEA_LEVEL_PRESSURE), 7, 2, altitude);

  Serial.print("|    ");
  Serial.print(temperature);
  Serial.print(" ˚C | ");
  Serial.print(pressure);
  Serial.print(" hPa |");
  Serial.print(altitude);
  Serial.println(" m |");

  oled.setFont(LARGE_FONT);
  oled.drawString(1, 0, temperature);
  oled.setFont(SMALL_FONT);
  oled.drawString(4, 2, pressure);
  oled.drawString(4, 3, altitude);

  digitalWrite(LED_PIN, LOW);

  delay(SAMPLING_DELAY);

}
