/*

  LED7Segment/MAX7219/RawDrive
  Driving a series of 7-segment LED displays with the MAX7219 and raw SPI commands.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/LED7Segment/MAX7219/RawDrive

 */

const uint8_t CS_PIN  = 10;
const uint8_t DIN_PIN = 11;
const uint8_t CLK_PIN = 13;

// register addresses
const uint8_t MAX7219_noop        = 0x00;
const uint8_t MAX7219_digit0      = 0x01;
const uint8_t MAX7219_digit1      = 0x02;
const uint8_t MAX7219_digit2      = 0x03;
const uint8_t MAX7219_digit3      = 0x04;
const uint8_t MAX7219_digit4      = 0x05;
const uint8_t MAX7219_digit5      = 0x06;
const uint8_t MAX7219_digit6      = 0x07;
const uint8_t MAX7219_digit7      = 0x08;
const uint8_t MAX7219_decodeMode  = 0x09;
const uint8_t MAX7219_intensity   = 0x0a;
const uint8_t MAX7219_scanLimit   = 0x0b;
const uint8_t MAX7219_shutdown    = 0x0c;
const uint8_t MAX7219_displayTest = 0x0f;

const uint8_t MAX7219_DECODE_NONE = 0x00;
const uint8_t MAX7219_DECODE_0    = 0x01;
const uint8_t MAX7219_DECODE_LOW  = 0x0f;
const uint8_t MAX7219_DECODE_ALL  = 0xff;

/*
  Send a 16-bit command packet to the device,
  comprising the +reg+ register selection and +data+ bytes.
  Data is latched on the rising edge of CS_PIN
 */
void maxWrite(byte reg, byte data) {
  digitalWrite(CS_PIN, LOW);
  shiftOut(DIN_PIN, CLK_PIN, MSBFIRST, reg);
  shiftOut(DIN_PIN, CLK_PIN, MSBFIRST, data);
  digitalWrite(CS_PIN, HIGH);
}

/*
On initial power-up, all control registers are reset, the
display is blanked, and the MAX7219/MAX7221 enter
shutdown mode. Program the display driver prior to
display use. Otherwise, it will initially be set to scan one
digit, it will not decode data in the data registers, and
the intensity register will be set to its minimum value.
*/
void initialiseDisplay() {
  maxWrite(MAX7219_scanLimit,   0x01); // only scan digits 0, 1
  maxWrite(MAX7219_decodeMode,  MAX7219_DECODE_LOW);
  maxWrite(MAX7219_displayTest, 0x00); // normal operation
  maxWrite(MAX7219_shutdown,    0x00); // display off
}

/*
 Turn on the display with LED +intensity+ from 0x0 (min) to 0xF (max).
 */
void startupDisplay(byte intensity) {
  maxWrite(MAX7219_shutdown,    0x01); // display on
  maxWrite(MAX7219_intensity,   intensity);
}

void setup() {
  pinMode(DIN_PIN, OUTPUT);
  pinMode(CS_PIN, OUTPUT);
  pinMode(CLK_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);

  initialiseDisplay();
  startupDisplay(0x0D);
}

void loop() {
  // run a simple display test
  counter();
}

/*
 Run a looping second counter ..
 */
void counter() {
  for (byte value=0; value<100; ++value) {
    maxWrite(MAX7219_digit0, value % 10 );
    maxWrite(MAX7219_digit1, (value / 10) | 0x80);
    delay(1000);
  }
}
