/*

  AT89C2051/Programmer
  Based on https://github.com/piotrb5e3/AT89C2051_programmer but with modifications for charge pump control.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/8051/AT89C2051/Programmer

 */

#include <stdint.h>
#include "rst_vpp.h"

#define CMD_ERASE 'X'
#define CMD_READ_FULL 'R'
#define CMD_WRITE_FULL 'W'
#define CMD_READ_SIGNATURE 'S'
#define COMM_STATUS_OK '$'
#define COMM_STATUS_ERR '^'
#define COMM_STATUS_CHUNK_OK '%'


#define XTAL1_PIN (A1)
#define P32_PIN   (A2)
#define P33_PIN   (A3)
#define P34_PIN   (A4)
#define P35_PIN   (A5)
#define P37_PIN   (12)

const uint8_t DATA_PINS_SIZE = 8;
uint8_t DATA_PINS[] = {
  2,  //P1.0
  4,  //P1.1
  5,  //P1.2
  6,  //P1.3
  7,  //P1.4
  8,  //P1.5
  9,  //P1.6
  10, //P1.7
};

uint8_t hex2int(char c) {
  if(c >= '0' && c<= '9') {
    return c - '0';
  } else if(c >= 'a' && c<= 'f') {
    return c - 'a' + 10;
  } else if(c >= 'A' && c<= 'F') {
    return c - 'A' + 10;
  } else return 0;
}

uint8_t serial_get_byte() {
  uint8_t ret = 0;
  while(!Serial.available());
  ret = 16*hex2int(Serial.read());
  while(!Serial.available());
  ret += hex2int(Serial.read());
  return ret;
}

void serial_write_byte(uint8_t b) {
  char str[3];
  sprintf(str, "%.2X\0", b);
  Serial.print(str);
}


uint8_t read_byte() {
  for(uint8_t i = 0; i<DATA_PINS_SIZE; i++)
    pinMode(DATA_PINS[i], INPUT);
  uint8_t r = 0;
  for(uint8_t i = 0; i<DATA_PINS_SIZE; i++)
    r |= digitalRead(DATA_PINS[i]) << i;
  return r;
}

void put_byte(uint8_t dt) {
  for(uint8_t i = 0; i<DATA_PINS_SIZE; i++)
    pinMode(DATA_PINS[i], OUTPUT);
  for(uint8_t i = 0; i<DATA_PINS_SIZE; i++)
    digitalWrite(DATA_PINS[i],dt & (1 << i));
}

void advance_counter() {
  digitalWrite(XTAL1_PIN, HIGH);
  delayMicroseconds(1);
  digitalWrite(XTAL1_PIN, LOW);
}

void init_prog() {
  digitalWrite(XTAL1_PIN, LOW);
  RST_VPP::setVoltage(5);
  digitalWrite(P32_PIN, HIGH);
  delay(1);
}

void setProgrammingMode(int p33, int p34, int p35, int p37) {
  digitalWrite(P33_PIN, p33);
  digitalWrite(P34_PIN, p34);
  digitalWrite(P35_PIN, p35);
  digitalWrite(P37_PIN, p37);
}

void read_signature() {
  init_prog();
  setProgrammingMode(LOW, LOW, LOW, LOW);
  delay(1);
  serial_write_byte(read_byte());
  advance_counter();
  serial_write_byte(read_byte());
  advance_counter();
  Serial.write(COMM_STATUS_OK);
}

void chip_erase() {
  init_prog();
  setProgrammingMode(HIGH, LOW, LOW, LOW);
  RST_VPP::setVoltage(12);
  digitalWrite(P32_PIN, LOW);
  delay(12);
  digitalWrite(P32_PIN, HIGH);
  RST_VPP::setVoltage(0);
  Serial.write(COMM_STATUS_OK);
}

void read_flash(int count) {
  init_prog();
  setProgrammingMode(LOW, LOW, HIGH, HIGH);
  for(int i = 0; i < count; i++) {
    delay(1);
    serial_write_byte(read_byte());
    advance_counter();
  }
}

void chip_read() {
  uint8_t hi = serial_get_byte();
  uint8_t lo = serial_get_byte();
  uint16_t count = hi * 256 + lo;
  Serial.write(COMM_STATUS_OK);
  read_flash(count);
  Serial.write(COMM_STATUS_OK);
}

void write_next(uint8_t dat) {
  //Set byte
  put_byte(dat);
  delayMicroseconds(2);
  //Pulse to start write
  digitalWrite(P32_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(P32_PIN, HIGH);

  //Wait for the write cycle to complete
  delayMicroseconds(2500);
  advance_counter();
  delayMicroseconds(15);
}

void start_write() {
  setProgrammingMode(LOW, HIGH, HIGH, HIGH);
  RST_VPP::setVoltage(12);
  delayMicroseconds(1500);
}

void stop_write() {
  RST_VPP::setVoltage(0);
  setProgrammingMode(LOW, LOW, LOW, LOW);
}

void chip_write() {
  uint16_t chunksize = 256;
  uint8_t data[256];
  uint8_t hi = serial_get_byte();
  uint8_t lo = serial_get_byte();
  uint16_t count = hi * 256 + lo;
  init_prog();
  Serial.write(COMM_STATUS_OK);

  start_write();
  for(uint16_t i = 0; i<count;) {
    uint16_t ct = 0;
    for(;ct<chunksize && i<count; i++,ct++) {
      uint8_t tmp = serial_get_byte();
      data[ct] = tmp;
    }
    for(uint16_t j = 0; j<ct;j++) {
      write_next(data[j]);
    }
    Serial.write(COMM_STATUS_CHUNK_OK);
  }
  stop_write();

  Serial.write(COMM_STATUS_OK);
}

void setup() {
  Serial.begin(9600);

  pinMode(P32_PIN, OUTPUT);
  pinMode(P33_PIN, OUTPUT);
  pinMode(P34_PIN, OUTPUT);
  pinMode(P35_PIN, OUTPUT);
  pinMode(P37_PIN, OUTPUT);
  pinMode(XTAL1_PIN, OUTPUT);

  for(uint8_t i = 0; i<DATA_PINS_SIZE; i++)
    pinMode(DATA_PINS[i], INPUT);

  digitalWrite(P32_PIN, LOW);
  digitalWrite(P33_PIN, LOW);
  digitalWrite(P34_PIN, LOW);
  digitalWrite(P35_PIN, LOW);
  digitalWrite(P37_PIN, LOW);
  digitalWrite(XTAL1_PIN, LOW);

  RST_VPP::setup();
  RST_VPP::setVoltage(0);

  Serial.println("Device ready");
  Serial.write(COMM_STATUS_OK);

}

void loop() {
  while(!Serial.available());

  switch(Serial.read()) {
    case CMD_ERASE:
    chip_erase();
    break;

    case CMD_READ_FULL:
    chip_read();
    break;

    case CMD_WRITE_FULL:
    chip_write();
    break;

    case CMD_READ_SIGNATURE:
    read_signature();
    break;

    default:
    Serial.println("Unknown cmd");
    Serial.write(COMM_STATUS_ERR);
  }
}
