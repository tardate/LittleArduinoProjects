/*

  MilliVoltmeterDIY
  An ATmega328-base milli-volt meter, based on design and code from SCULLCOM HOBBY ELECTRONICS

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Equipment/MilliVoltmeterDIY

 */

#include <EEPROM.h>
#include <SPI.h>
#include <LiquidCrystal.h>

const int ADC_CS_PIN                       = 10;
const int SECOND_LINE_FUNCTION_BUTTON_PIN  =  8;
const int PRECISION_BUTTON_PIN             =  9;
const int CALIBRATE_BUTTON_PIN             = A0;
const int BATTERY_MONITOR_PIN              = A1;

const float ADC_REFERENCE_VOLTAGE          = 2.5;

const int calibration_factor_address       = 0;

#define MAIN_LOOP_DELAY_MS                 (30)
#define DEBOUNCE_DELAY_MS                  (250)
#define INTRO_DELAY_MS                     (2000)
#define CALIBRATION_PROMPT_DELAY_MS        (2000)
#define VREF_MV                            (5000) // chip voltage reference, in mV
#define BATTERY_MONITOR_R1                 (220.0)
#define BATTERY_MONITOR_R2                 (100.0)
#define BATTERY_MONITOR_SCALE_FACTOR       (BATTERY_MONITOR_R2/(BATTERY_MONITOR_R1 + BATTERY_MONITOR_R2) * 1000.0)
#define NUMBER_OF_SAMPLES                  (5)

#define BUTTON_LOGIC_ACTIVE_STATE          (LOW)

const int LCD_RS_PIN                       = 7;
const int LCD_ENABLE_PIN                   = 6;
const int LCD_D4_PIN                       = 5;
const int LCD_D5_PIN                       = 4;
const int LCD_D6_PIN                       = 3;
const int LCD_D7_PIN                       = 2;

LiquidCrystal lcd(LCD_RS_PIN, LCD_ENABLE_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

int32_t g_samples[NUMBER_OF_SAMPLES] = {0};
uint8_t g_current_sample = 0;
uint8_t g_number_of_decimals = 6;

int32_t calibration_factor = 0;

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
  setupSPI();
  setupLCD();

  showIntro();

  calibration_factor = EEPROMreadlong(calibration_factor_address);
  showCalibrationData();
}


void setupSPI(void) {
  // Mode 0 (MOSI read on rising edge (CPLI=0) and SCK idle low (CPOL=0))
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  SPI.begin();
}


void setupIOPins(void) {
  pinMode(CALIBRATE_BUTTON_PIN, INPUT_PULLUP);
  pinMode(PRECISION_BUTTON_PIN, INPUT_PULLUP);
  pinMode(SECOND_LINE_FUNCTION_BUTTON_PIN,INPUT_PULLUP);

  pinMode(BATTERY_MONITOR_PIN, INPUT);
  pinMode(ADC_CS_PIN, OUTPUT);
  digitalWrite(ADC_CS_PIN, HIGH);
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
    g_number_of_decimals++;
    if (g_number_of_decimals > 6) g_number_of_decimals = 0;
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

void debounce(void) {
  delay(DEBOUNCE_DELAY_MS);
}

// Command: requests and reads a single sample from the ADC
void readADC(void) {
  digitalWrite(ADC_CS_PIN, LOW);

  while ((PINB & (1 << 4))) { }               // wait till pin 12 goes low, indicating end of conversion

  int32_t reading = 0;
  for (int i = 0; i < 4; i++) {
    reading <<= 8;
    reading |= SPI.transfer(0xFF);
  }
  reading >>= 4;                              // Discard 4 sub-LSB bits on the right

  if(reading & 0x02000000) {                  // positive:
    reading &=   0x01FFFFFF;                  // discard flag bits, keep EXR
  } else {                                    // negative:
    reading |=   0xFF000000;                  // convert to pure 2's complement
  }

  digitalWrite(ADC_CS_PIN, HIGH);

  g_samples[g_current_sample++] = reading;
  if (g_current_sample == NUMBER_OF_SAMPLES) g_current_sample = 0;
}

void sampleVoltage(void) {
  readADC();
  current_adc_reading = getADCAverage();
  current_voltage = convertToVoltage(current_adc_reading);
}

// Returns: latest average value sampled from the ADC
int32_t getADCAverage(void) {
  int32_t sum = 0;
  for (int i = 0; i < NUMBER_OF_SAMPLES; i++) sum += g_samples[i];
  return sum / NUMBER_OF_SAMPLES;
}

// Returns: ADC reading as a voltage
float convertToVoltage(int32_t reading) {
  return ADC_REFERENCE_VOLTAGE * reading / calibration_factor;
}

// Command: calibrate to current incoming voltage (expected to be the ADC voltage ref)
void recalibrate(void) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Calibrating");

  for (int i = 0; i < NUMBER_OF_SAMPLES; i++) {
    readADC();
    lcd.print('.');
  }
  int32_t reading = getADCAverage();

  calibration_factor = reading;
  EEPROMwritelong(calibration_factor_address, calibration_factor);

  showCalibrationData();
}

//--- Show Calibration Data -----------------------------------------------------------------
void showCalibrationData(void) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Calibrated:");
  lcd.setCursor(0, 1);
  lcd.print(calibration_factor, HEX);
  delay(CALIBRATION_PROMPT_DELAY_MS);
  lcd.clear();
}

//--- Print Voltage Reading to Display -----------------------------------------------------------------
void showReading(void) {
  displayVoltage(current_voltage, 0);
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

// formats a voltage and prints to display on specified row
void displayVoltage(float volts, int row) {
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
  lcd.print(scaled_volts, g_number_of_decimals);
  lcd.print(" ");
  if (prefix)
    lcd.print(prefix);
  lcd.print("V     ");
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
  int battery_mv = map(analogRead(BATTERY_MONITOR_PIN), 0, 1023, 0, VREF_MV);
  float batteryVolts = battery_mv / BATTERY_MONITOR_SCALE_FACTOR;
  lcd.setCursor(0, row);
  lcd.print("Battery ");
  lcd.print(batteryVolts, 2);
  lcd.print(" V");
}


void clearBarGraph(void) {
  bar_voltage_major = bar_voltage_minor = 0;
}

// Command: updates bargraph display as second-line function
void updateBarGraph(void) {
  float barDiffVolts = (bar_voltage_major + bar_voltage_minor) - current_voltage;
  if (barDiffVolts > 0.1 || barDiffVolts < -0.1) {

    bar_voltage_major = (int) current_voltage;
    bar_voltage_minor = current_voltage - bar_voltage_major;

    lcd.setCursor(0,1);
    lcd.print("                ");
    for (int i=0; i <(bar_voltage_major); ++i) {
        lcd.setCursor(i,1);
        lcd.write(5);
    }
    if (bar_voltage_minor > 0.9) {
      lcd.setCursor(bar_voltage_major,1);
      lcd.write(5);

    } else if (bar_voltage_minor > 0.7) {
      lcd.setCursor(bar_voltage_major,1);
      lcd.write(4);

   } else if (bar_voltage_minor > 0.5) {
      lcd.setCursor(bar_voltage_major,1);
      lcd.write(3);

    } else if (bar_voltage_minor > 0.3) {
      lcd.setCursor(bar_voltage_major,1);
      lcd.write(2);

    } else if (bar_voltage_minor > 0.1){
      lcd.setCursor(bar_voltage_major,1);
      lcd.write(1);
    }
  }
}

// Command: snapshot current reading as second-line function
void holdReading(void) {
  displayVoltage(current_voltage, 1);
  lcd.setCursor(15,1);
  lcd.print("H");
}

// Command: clear specified row if the display
void clearRow(int row) {
  lcd.setCursor(0, row);
  lcd.print("                ");
  lcd.setCursor(0, row);
}

// Command: writes (32 bit) long value to EEPROM address
void EEPROMwritelong(int calibration_factor_address, long value) {
  byte four = (value & 0xFF);
  byte three = ((value>>8) & 0xFF);
  byte two = ((value>>16) & 0xFF);
  byte one = ((value>>24) & 0xFF);

  EEPROM.write(calibration_factor_address, four);
  EEPROM.write(calibration_factor_address +1, three);
  EEPROM.write(calibration_factor_address +2, two);
  EEPROM.write(calibration_factor_address +3, one);
}

// Returns: (32 bit) long value from EEPROM address
long EEPROMreadlong(long calibration_factor_address) {
  long four = EEPROM.read(calibration_factor_address);
  long three = EEPROM.read(calibration_factor_address + 1);
  long two = EEPROM.read(calibration_factor_address + 2);
  long one = EEPROM.read(calibration_factor_address + 3);
  return (four)+(three << 8)+(two << 16)+(one << 24);
}
