/*

  NTP Client Demo
  Simple demonstration of NTP client requests using an Arduino Ethernet Shield.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/NTP/NtpClientDemo

 */

#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

unsigned int localPort = 8888;             // local port to listen for UDP packets
const char timeServer[] = "time.nist.gov"; // time.nist.gov NTP server
const int NTP_PACKET_SIZE = 48;            // NTP time stamp is in the first 48 bytes of the message
byte packetBuffer[NTP_PACKET_SIZE];        // buffer to hold incoming and outgoing packets
EthernetUDP Udp;                           // A UDP instance to let us send and receive packets over UDP

const int WAIT_FOR_REPLY_MS = 1000;
const int DELAY_BETWEEN_REQUESTS_MS = 10000;

void setup() {
  // You can use Ethernet.init(pin) to configure the CS pin
  //Ethernet.init(10);  // Most Arduino shields
  //Ethernet.init(5);   // MKR ETH shield
  //Ethernet.init(0);   // Teensy 2.0
  //Ethernet.init(20);  // Teensy++ 2.0
  //Ethernet.init(15);  // ESP8266 with Adafruit Featherwing Ethernet
  //Ethernet.init(33);  // ESP32 with Adafruit Featherwing Ethernet

  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // start Ethernet and UDP
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    } else if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    // no point in carrying on, so do nothing forevermore:
    while (true) {
      delay(1);
    }
  }

  // give the Ethernet shield a second to initialize
  Serial.println("Ethernet started...");
  delay(1000);
  Udp.begin(localPort);
}

void loop() {
  sendNTPpacket(timeServer);

  delay(WAIT_FOR_REPLY_MS);
  if (Udp.parsePacket()) {
    Udp.read(packetBuffer, NTP_PACKET_SIZE);
    unsigned long secsSince1900 = ntpTimeFromBuffer();
    printNtpTime(secsSince1900);
    printEpoch(ntpTimeToEpoch(secsSince1900));
  }

  delay(DELAY_BETWEEN_REQUESTS_MS);
  Ethernet.maintain();
}

unsigned long ntpTimeFromBuffer() {
  // the timestamp starts at byte 40 of the received packet and is four bytes,
  // or two words, long. First, extract the two words:
  unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
  unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);

  // combine the four bytes (two words) into a long integer
  // this is NTP time (seconds since Jan 1 1900):
  return highWord << 16 | lowWord;
}

unsigned long ntpTimeToEpoch(unsigned long secsSince1900) {
  // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
  const unsigned long seventyYears = 2208988800UL;
  return secsSince1900 - seventyYears;
}

void printNtpTime(unsigned long secsSince1900) {
  Serial.print("Seconds since Jan 1 1900 = ");
  Serial.println(secsSince1900);
}

void printEpoch(unsigned long epoch) {
  // print Unix time:
  Serial.print("Unix time = ");
  Serial.println(epoch);

  const unsigned long SECONDS_PER_DAY = 86400;
  const unsigned long SECONDS_PER_HOUR = 3600;
  const unsigned long SECONDS_PER_MINUTE = 60;

  // print the hour, minute and second:
  Serial.print("The UTC time is ");
  Serial.print((epoch  % SECONDS_PER_DAY) / SECONDS_PER_HOUR);
  Serial.print(':');
  if (((epoch % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE) < 10) Serial.print('0');
  Serial.print((epoch  % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE);
  Serial.print(':');
  if ((epoch % SECONDS_PER_MINUTE) < 10) Serial.print('0');
  Serial.println(epoch % SECONDS_PER_MINUTE); // print the second
}

// send an NTP request to the time server at the given address
void sendNTPpacket(const char * address) {
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(address, 123); // NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}
