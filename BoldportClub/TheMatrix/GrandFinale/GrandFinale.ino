/*

  TheMatrix/GrandFinale
  Solving cassidoo's Fireworks Grand Finale problem for Arduino and simulating the result with the BoldportClub Matrix.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/BoldportClub/TheMatrix/GrandFinale

 */

#include <Wire.h>
#include <LRAS1130.h>
#include "sparklie.h"

using namespace lr;
AS1130 ledDriver;

AS1130Picture24x5 pages[2]; // two pages for the current and next frame
uint8_t current_page = 0;   // index to the current page

static const uint16_t NOMINAL_RUNTIME = 1200;
static const uint8_t MAX_SPARKLIES = 55;
Sparklie sparklies[MAX_SPARKLIES];

static const uint8_t MAX_FIREWORKS = 10;
int fireworks[MAX_FIREWORKS][3]; // Array of [height, size, velocity] elements
uint8_t fireworks_count = 0;
uint8_t finale_start;
uint8_t finale_end;

static const uint16_t DELAY_BETWEEN_FIREWORKS = 100;


void setup() {
  // Initialize the Wire library.
  Wire.begin();

  // Initialize the serial port.
  Serial.begin(9600);

  // Give the matrix some time to boot
  delay(100);

  // Check if the matrix is addressable.
  if (!ledDriver.isChipConnected()) {
    Serial.println(F("Communication problem with The Matrix."));
    Serial.flush();
    return;
  }

  // Set-up everything.
  ledDriver.setRamConfiguration(AS1130::RamConfiguration1);
  ledDriver.setOnOffFrameAllOff(0);
  ledDriver.setOnOffFrameAllOff(1);
  ledDriver.setBlinkAndPwmSetAll(0);
  ledDriver.setCurrentSource(AS1130::Current30mA);
  ledDriver.setScanLimit(AS1130::ScanLimitFull);
  ledDriver.startPicture(0);

  // Enable the chip
  ledDriver.startChip();
  delay(100);

  Serial.println("The Matrix started, waiting for your fireworks command...");
}


/// @brief Command: main loop;
/// wait for fireworks command from serial input;
/// find the grand finale sequence (if any) and run the animation
///
void loop() {
  if (readFireworksCommand()) {
    if (calculateGrandFinale()) {
      Serial.print("fireworks_count: ");
      Serial.print(fireworks_count);
      Serial.print(" finale_start: ");
      Serial.print(finale_start);
      Serial.print(" finale_end: ");
      Serial.println(finale_end);
      for (int i = finale_start; i <= finale_end; i++) {
        explode(fireworks[i][0], fireworks[i][1], fireworks[i][2]);
        delay(DELAY_BETWEEN_FIREWORKS);
      }
    }
  }
}

/// @brief Command: read the fireworks command from serial input.
/// @return true if a valid command was read, false otherwise.
///
bool readFireworksCommand() {
  bool result = false;
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    fireworks_count = 0;

    if (input.startsWith("[") && input.endsWith("]")) {
      input.remove(0, 1); // Remove leading '['
      input.remove(input.length() - 1, 1); // Remove trailing ']'

      while (input.length() > 0 && fireworks_count < MAX_FIREWORKS) {
        int start = input.indexOf('[');
        int end = input.indexOf(']');
        if (start == -1 || end == -1) break;

        String firework = input.substring(start + 1, end);
        input.remove(0, end + 1);

        int values[3];
        int idx = 0;
        while (firework.length() > 0 && idx < 3) {
          int comma = firework.indexOf(',');
          String value = (comma == -1) ? firework : firework.substring(0, comma);
          firework.remove(0, (comma == -1) ? firework.length() : comma + 1);
          values[idx++] = value.toInt();
        }

        if (idx == 3) {
          fireworks[fireworks_count][0] = values[0];
          fireworks[fireworks_count][1] = values[1];
          fireworks[fireworks_count][2] = values[2];
          fireworks_count++;
        }
      }
      result = fireworks_count > 0; // Successfully parsed the command
    }
  }
  return result;
}


/// @brief Command: run the animation sequence
///
void explode(uint8_t firework_height, uint8_t firework_size, uint8_t firework_velocity) {
  Serial.print("explode(height: ");
  Serial.print(firework_height);
  Serial.print(" velocity: ");
  Serial.print(firework_size);
  Serial.print(" size: ");
  Serial.print(firework_velocity);
  Serial.println(")");

  uint16_t runtime = NOMINAL_RUNTIME;
  uint8_t live_sparklies;
  bool with_regeneration;
  if (firework_size > MAX_SPARKLIES) {
    firework_size = MAX_SPARKLIES; // limit to available sparklies
  }
  do {
    if(runtime>0) --runtime;
    with_regeneration = runtime > NOMINAL_RUNTIME / 2;
    live_sparklies = 0;
    uint8_t target_page = !current_page;
    for(uint8_t s=0; s<firework_size; ++s) {
      sparklies[s].clear(pages[current_page]);
      if(sparklies[s].recalculate(with_regeneration, firework_height, firework_velocity)) live_sparklies++;
      sparklies[s].draw(pages[target_page], ledDriver);
    }
    flipPage();
  } while(runtime>0 || live_sparklies>0);
}


/// @brief Command: switch display pages.
/// current_page is switched, and the new page displayed
///
void flipPage() {
  current_page = !current_page;
  ledDriver.setOnOffFrame(0, pages[current_page]);
}


/// @brief Check if the fireworks sequence from start to finish is valid.
/// i.e. average(size) >= 5,
/// minimum(velocity) == 3,
/// and maximum(height) - minimum(height) <= 10
/// @param start
/// @param finish
/// @return true if the sequence is valid, false otherwise
///
bool validSequence(int start, int finish) {
  if (start < 0 || finish >= fireworks_count || start > finish) {
    return false;
  }

  int total_size = 0;
  int min_velocity = INT8_MAX;
  int max_height = INT8_MIN;
  int min_height = INT8_MAX;

  for (int i = start; i <= finish; i++) {
    total_size += fireworks[i][1];
    min_velocity = min(min_velocity, fireworks[i][2]);
    max_height = max(max_height, fireworks[i][0]);
    min_height = min(min_height, fireworks[i][0]);
  }

  float average_size = static_cast<float>(total_size) / (finish - start + 1);

  return (average_size >= 5 &&
          min_velocity == 3 &&
          (max_height - min_height) <= 10);
}


/// @brief Analyse the fireworks data to find the longest valid sequence.
/// @return true if a valid sequence is found, false otherwise
///
bool calculateGrandFinale() {
  finale_start = 0;
  finale_end = 0;
  int finale_length = 0;
  bool found = false;

  for (int start = 0; start < fireworks_count; start++) {
    for (int finish = start; finish < fireworks_count; finish++) {
        int length = finish - start + 1;
        if ((length > finale_length) && validSequence(start, finish)) {
          finale_start = start;
          finale_end = finish;
          finale_length = length;
          found = true;
        }
    }
  }
  return found;
}
