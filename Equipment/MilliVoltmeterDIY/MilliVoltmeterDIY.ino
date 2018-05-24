/*

  MilliVoltmeterDIY
  An ATmega328-base milli-volt meter, based on design and code from SCULLCOM HOBBY ELECTRONICS

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Equipment/MilliVoltmeterDIY

 */


#include <LiquidCrystal.h>
#include "ltc2400_adc.h"
#include "saved_settings.h"


const int ADC_CS_PIN                       = 10;
const int SECOND_LINE_FUNCTION_BUTTON_PIN  =  8;
const int PRECISION_BUTTON_PIN             =  9;
const int CALIBRATE_BUTTON_PIN             = A0;
const int BATTERY_MONITOR_PIN              = A1;

const int LCD_RS_PIN                       = 7;
const int LCD_ENABLE_PIN                   = 6;
const int LCD_D4_PIN                       = 5;
const int LCD_D5_PIN                       = 4;
const int LCD_D6_PIN                       = 3;
const int LCD_D7_PIN                       = 2;

const float ADC_REFERENCE_VOLTAGE          = 2.5;
const int NUMBER_OF_SAMPLES                = 5;

#define MAIN_LOOP_DELAY_MS                 (30)
#define DEBOUNCE_DELAY_MS                  (250)
#define INTRO_DELAY_MS                     (2000)
#define CALIBRATION_PROMPT_DELAY_MS        (2000)

#define AREF_MV                            (5000) // chip voltage reference, in mV
#define BATTERY_MONITOR_R1                 (220.0)
#define BATTERY_MONITOR_R2                 (100.0)
#define BATTERY_MONITOR_SCALE_FACTOR       (1/BATTERY_MONITOR_R2*AREF_MV/1000*(BATTERY_MONITOR_R1 + BATTERY_MONITOR_R2)/1023)

#define BUTTON_LOGIC_ACTIVE_STATE          (LOW)


SavedSettings settings;
LTC2400_ADC adc(ADC_CS_PIN, NUMBER_OF_SAMPLES);
LiquidCrystal lcd(LCD_RS_PIN, LCD_ENABLE_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

uint8_t current_precision = 6;
int second_line_function = 0;
float current_voltage = 0;
int32_t current_adc_reading = 0;
float bar_voltage_minor = 0;
int bar_voltage_major = 0;

byte p20 [8] = {B10000,B10000,B10000,B10000,B10000,B10000,B10000,B10000,};  // 20% battery character
byte p40 [8] = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11000,};  // 40% battery character
byte p60 [8] = {B11100,B11100,B11100,B11100,B11100,B11100,B11100,B11100,};  // 60% battery character
byte p80 [8] = {B11110,B11110,B11110,B11110,B11110,B11110,B11110,B11110,};  // 80% battery character
byte p100[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111,};  // 100% battery character


void setup(void) {
  setupIOPins();
  adc.begin();
  setupLCD();

  showIntro();


  showCalibrationData();
}


void setupIOPins(void) {
  pinMode(CALIBRATE_BUTTON_PIN, INPUT_PULLUP);
  pinMode(PRECISION_BUTTON_PIN, INPUT_PULLUP);
  pinMode(SECOND_LINE_FUNCTION_BUTTON_PIN,INPUT_PULLUP);
  pinMode(BATTERY_MONITOR_PIN, INPUT);
}


void setupLCD(void) {
  lcd.begin(16, 2);

  lcd.createChar(1, p20);
  lcd.createChar(2, p40);
  lcd.createChar(3, p60);
  lcd.createChar(4, p80);
  lcd.createChar(5, p100);
}


void loop(void) {
  if (digitalRead(PRECISION_BUTTON_PIN) == BUTTON_LOGIC_ACTIVE_STATE) {
    current_precision++;
    if (current_precision > 6) current_precision = 0;
    debounce();
    clearRow(0);
  } else if (digitalRead(SECOND_LINE_FUNCTION_BUTTON_PIN) == BUTTON_LOGIC_ACTIVE_STATE) {
    second_line_function++;
    if(second_line_function > 2) second_line_function = 0;
    clearRow(1);
    switch(second_line_function) {
    case 0:
      clearBarGraph();
      break;
    case 1:
      holdReading();
      break;
    }
    debounce();
  } else if (digitalRead(CALIBRATE_BUTTON_PIN) == BUTTON_LOGIC_ACTIVE_STATE) {
    recalibrate();
  } else {
    sampleVoltage();
    showReading();
    delay(MAIN_LOOP_DELAY_MS);
  }
}


// Command: pause a bit to provide software debouncing
void debounce(void) {
  delay(DEBOUNCE_DELAY_MS);
}

// Command: sample ADC and update current values
void sampleVoltage(void) {
  adc.read();
  current_adc_reading = adc.current_average();
  current_voltage = convertToVoltage(current_adc_reading);
}


// Returns: ADC reading as a voltage
float convertToVoltage(int32_t reading) {
  return ADC_REFERENCE_VOLTAGE * reading / settings.get_calibration_factor();
}


// Command: calibrate to current incoming voltage (expected to be the ADC voltage ref)
void recalibrate(void) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Calibrating");

  for (int i = 0; i < NUMBER_OF_SAMPLES; i++) {
    adc.read();
    lcd.print('.');
  }
  int32_t reading = adc.current_average();

  settings.set_calibration_factor(reading);

  showCalibrationData();
}


// Command: show calibration data on the display
void showCalibrationData(void) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Calibrated:");
  lcd.setCursor(0, 1);
  lcd.print(settings.get_calibration_factor(), HEX);
  delay(CALIBRATION_PROMPT_DELAY_MS);
  lcd.clear();
}


// Command: show the intro screen
void showIntro(void) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Millivolt Meter");
  showBatteryStatus(1);
  delay(INTRO_DELAY_MS);
  lcd.clear();
}


// Command: tests and reports battery status to specified LCD line
void showBatteryStatus(int row) {
  float batteryVolts = analogRead(BATTERY_MONITOR_PIN) * BATTERY_MONITOR_SCALE_FACTOR;
  lcd.setCursor(0, row);
  lcd.print("Battery ");
  lcd.print(batteryVolts, 2);
  lcd.print(" V");
}


// Command: update the display
void showReading(void) {
  showVoltage(current_voltage, 0);
  switch(second_line_function) {
  case 1: // hold
    // nop
    break;
  case 2: // raw reading
    clearRow(1);
    lcd.print("ADC: ");
    lcd.print(current_adc_reading, HEX);
    break;
  default: // bar graph
    updateBarGraph();
  }
}


// Command: formats a voltage and prints to display on specified row
void showVoltage(float volts, int row) {
  float scaled_volts = volts;
  char prefix = 0;

  if (volts < 0.001) {
    scaled_volts = volts * 1000000;
    prefix = 'u';

  } else if (volts < 1) {
    scaled_volts = volts * 1000;
    prefix = 'm';
  }

  lcd.setCursor(0, row);
  lcd.print(scaled_volts, current_precision);
  lcd.print(" ");
  if (prefix)
    lcd.print(prefix);
  lcd.print("V     ");
}


// Command: reset bar graph variables to ensure refresh
void clearBarGraph(void) {
  bar_voltage_major = bar_voltage_minor = 0;
}


// Command: updates bargraph display as second-line function
void updateBarGraph(void) {
  float voltage_delta = (bar_voltage_major + bar_voltage_minor) - current_voltage;
  if (voltage_delta > 0.1 || voltage_delta < -0.1) {

    if(current_voltage < 16) {
      bar_voltage_major = (int) current_voltage;
      bar_voltage_minor = current_voltage - bar_voltage_major;
    } else {
      bar_voltage_major = 16;
      bar_voltage_minor = 0;
    }

    lcd.setCursor(0,1);
    lcd.print("                ");
    for (int i=0; i < bar_voltage_major; ++i) {
        lcd.setCursor(i, 1);
        lcd.write(5);
    }
    if (bar_voltage_minor > 0.9) {
      lcd.setCursor(bar_voltage_major, 1);
      lcd.write(5);

    } else if (bar_voltage_minor > 0.7) {
      lcd.setCursor(bar_voltage_major, 1);
      lcd.write(4);

   } else if (bar_voltage_minor > 0.5) {
      lcd.setCursor(bar_voltage_major, 1);
      lcd.write(3);

    } else if (bar_voltage_minor > 0.3) {
      lcd.setCursor(bar_voltage_major, 1);
      lcd.write(2);

    } else if (bar_voltage_minor > 0.1){
      lcd.setCursor(bar_voltage_major, 1);
      lcd.write(1);
    }
  }
}


// Command: snapshot current reading as second-line function
void holdReading(void) {
  showVoltage(current_voltage, 1);
  lcd.setCursor(15, 1);
  lcd.print("H");
}


// Command: clear specified row if the display
void clearRow(int row) {
  lcd.setCursor(0, row);
  lcd.print("                ");
  lcd.setCursor(0, row);
}
