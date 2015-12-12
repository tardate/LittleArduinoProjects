/*

  DS3231RTC/TimeDemo
  Prints the system time synced from the RTC to the serial output

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/DS3231RTC/TimeDemo

 */

#include <DS3232RTC.h>    // https://github.com/JChristensen/DS3232RTC
#include <Time.h>         // http://playground.arduino.cc/Code/Time
#include <Wire.h>         // http://arduino.cc/en/Reference/Wire (included with Arduino IDE)

#include <stdarg.h>
void serial_printf(char *fmt, ... );

void setup() {
  Serial.begin(9600);

  // attempt to set the time from the RTC
  setSyncProvider(RTC.get);

  if(timeStatus() != timeSet) Serial.println("Unable to sync with the RTC");
  else Serial.println("RTC has set the system time");
}

void loop() {
  digitalClockDisplay();
  delay(1000);
}

// digital clock display of the time and date
void digitalClockDisplay() {
  serial_printf("%4d-%02d-%02d %02d:%02d:%02d\n", year(), month(), day(), hour(), minute(), second());
}

// Serial print with printf-like string formatting
// http://www.cplusplus.com/reference/cstdio/printf/
void serial_printf(char *fmt, ... ) {
  char buf[128]; // max 128 chars
  va_list args;
  va_start (args, fmt );
  vsnprintf(buf, 128, fmt, args);
  va_end (args);
  Serial.print(buf);
}