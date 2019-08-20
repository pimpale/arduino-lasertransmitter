#include <SoftwareSerial.h>

const byte rxPin = 2;
const byte txPin = 13; // LED is connected to pin 13

SoftwareSerial mySerial (rxPin, txPin);


void setup() {
  Serial.begin(9600);
  mySerial.begin(600);
}

void loop() {
  mySerial.println("victory is achieved");
}
