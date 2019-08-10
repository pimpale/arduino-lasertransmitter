const int ledPin = 3;              // LED connected to digital pin 13

void setup() {
  pinMode(ledPin, OUTPUT);    // sets the digital pin as output

  while(true) {
    out_byte(random(255));
  }
  
}

void loop() {}

void out_byte(unsigned char out) {
  
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(out);
  digitalWrite(ledPin, LOW);
  delayMicroseconds( - out);
}
