const int ledPin = 3;    // LED connected to digital pin 13
const char* string = "This is Epic\n\0\0";

void setup() {
  pinMode(ledPin, OUTPUT);    // sets the digital pin as output
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < strlen(string)+2; i++) {
    char byteThing = string[i];
    for(uint8_t i = 0; i < 8; i++) {
      // get ith bit
      uint8_t currentBit = (byteThing >> i) & 1;
      if(currentBit == 1) {
       digitalWrite(ledPin, HIGH);
      } else {
       digitalWrite(ledPin, LOW);
      }
      delay(100);
    }
    Serial.println(byteThing);
  }
}
