#include <SoftwareSerial.h>

const byte rxPin = 2;
const byte txPin = 13; // LED is connected to pin 13

SoftwareSerial mySerial (rxPin, txPin);

#define BUFFERLEN 512
int buffer[BUFFERLEN];
int bufferIndex = 0;

void setup() {
  Serial.begin(9600);
  mySerial.begin(300);

  while(true) {
    while(Serial.available()) {
      int c = Serial.read();
      buffer[bufferIndex++] = c;
      if(bufferIndex == BUFFERLEN || c == '\n') {
        for(int i = 0; i < bufferIndex; i++) {
          mySerial.write(buffer[i]);
        }
        bufferIndex = 0;
      }
    }
  }
}

void loop() {
  if(random(0, 10000) == 99) {
    mySerial.println("yeet");
    Serial.println("yeet");
  }
  
}
