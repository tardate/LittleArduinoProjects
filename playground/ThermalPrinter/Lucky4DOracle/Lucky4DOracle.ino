/*

  ThermalPrinter/Lucky4DOracle
  A "Lucky 4D" number generator, built a JP-QR701 Thermal Printer, including how to print Chinese (GB2312-80)

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ThermalPrinter/Lucky4DOracle

 */

#include <SoftwareSerial.h>
#include "Adafruit_Thermal.h" // import a patched local copy of the library


const byte BTN_PIN = 2; // push-button
const byte RX_PIN = 5; // goes to TX on printer
const byte TX_PIN = 6; // goes to RX on printer

const int BAUDRATE = 9600;

SoftwareSerial printerSerial(RX_PIN, TX_PIN);
Adafruit_Thermal printer(&printerSerial);

volatile boolean button_enabled = false;
volatile boolean button_pressed = false;


/*
 * Set button up flag on interrupt
 */
void handleButton(void) {
  if (button_enabled) {
    button_pressed = true;
  } else {
    // inhibit the first interrupt lest it fire automatically.
    // This just seems to be an issue with my Nano clone.
    // see https://forum.arduino.cc/index.php?topic=526497.0
    button_enabled = true;
  }
}


/*
 * Command: put printer to sleep
 */
void printerSleep(void) {
  printer.sleep();
  delay(3000L);
}


/*
 * Command: wake up printer for action
 */
void printerWakeUp(void) {
  printer.wake();       // MUST wake() before printing again, even if reset
  printer.setDefault(); // Restore printer to defaults
}


/*
 * Command: generate and print a prediction
 */
void printPrediction() {
  uint8_t i;
  static char numbers[10];

  randomSeed(analogRead(0));
  uint8_t d1 = random(10);
  uint8_t d2 = random(10);
  uint8_t d3 = random(10);
  uint8_t d4 = random(10);
  sprintf(
    numbers,
    " %1d %1d %1d %1d ",
    d1, d2, d3, d4
  );

  printerWakeUp();

  printer.setCharset(CHARSET_USA);
  printer.setCodePage(CODEPAGE_CP437);

  printer.boldOn();
  printer.setSize('L');
  printer.justify('C');

  printer.writeBytes(28, '&'); // FS &; Set Chinese Character Mode
  printer.writeBytes(0xB9, 0xA7); // gong
  printer.writeBytes(0xCF, 0xB2); // xi
  printer.writeBytes(0xB7, 0xA2); // fa
  printer.writeBytes(0xB2, 0xC6); // cai
  printer.println();
  printer.writeBytes(28, '.'); // FS .; Cancel Chinese Character Mode

  printer.write(0xC9);
  for (i=0; i<9; ++i) {
    printer.write(0xCD);
  }
  printer.write(0xBB);
  printer.println();

  printer.write(0xBA);
  printer.print(numbers);
  printer.write(0xBA);
  printer.println();

  printer.write(0xC8);
  for (i=0; i<9; ++i) {
    printer.write(0xCD);
  }
  printer.write(0xBC);
  printer.println();

  printer.feed(3);
  printerSleep();
}


/*
 * Command: one-time setup
 */
void setup() {
  printerSerial.begin(BAUDRATE);
  printer.begin();
  printerSleep();

  pinMode(BTN_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN_PIN), handleButton, FALLING);
}


/*
 * Command: main loop
 */
void loop() {
  if (button_pressed) {
    printPrediction();
    button_pressed = false;
  }
}
