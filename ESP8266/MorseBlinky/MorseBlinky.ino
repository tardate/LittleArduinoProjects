/*

  MorseBlinky
  Building code for an ESP-01 with the ESP8266 core for Arduino and demonstrate with a simple morse code blinker

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/ESP8266/MorseBlinky

 */

#define ACTIVE_LOW_LED_LOGIC  // if defined, LED is ON when pin LOW

const int LED_PIN = LED_BUILTIN;
const int TIME_UNIT = 150;

char message[] = ". ... .--. / .- .-.. .. ...- .";


void setup() {
  pinMode(LED_PIN, OUTPUT);
}

/*
 * Command: set LED to level for specified number of time units
 * knows how to apply ACTIVE_LOW_LED_LOGIC setting or not
 */
void pulseLed(int level, int time_units) {
  #ifdef ACTIVE_LOW_LED_LOGIC
  digitalWrite(LED_PIN, !level);
  delay(TIME_UNIT * time_units);
  digitalWrite(LED_PIN, HIGH);
  #else
  digitalWrite(LED_PIN, level);
  delay(TIME_UNIT * time_units);
  digitalWrite(LED_PIN, LOW);
  #endif
}

/*
 * Command: pulse morse message to LED
 * Morse rules:
 *  - short mark, dot or "dit": "dot duration" is one time unit long
 *  - longer mark, dash or "dah": three time units long
 *  - inter-element gap between the dots and dashes within a character: one dot duration or one unit long
 *  - short gap (between letters): three time units long
 *  - medium gap (between words): seven time units long
 */
void pulseMessage() {
  char* character_pointer = message;

  while (*character_pointer) {
    switch(*character_pointer) {
      case '.':
        pulseLed(HIGH, 1);
        pulseLed(LOW, 1);
        break;
      case '-':
        pulseLed(HIGH, 3);
        pulseLed(LOW, 1);
        break;
      case '/':
        pulseLed(LOW, 7 - 2); // because surrounded by spaces
        break;
      default:
        pulseLed(LOW, 2 -1); // because preceeded by space
    }
    ++character_pointer;
  }
}

void loop() {
  pulseMessage();
  delay(TIME_UNIT * 14);
}
