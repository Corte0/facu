#include <stdint.h>

void setup() {
  Serial.begin(9600);
  DDRD = 0b00011100;
  DDRB = 0b00000000;
}

void loop() {
  static char buf [3];

  if (readSerial(buf)){
    (buf[1] & ~0x03) != 0 ? Serial.println("invalid action") :
    PORTD = (PORTD & ~0x1C) | ((buf[1] << 2) & 0x1C);
  }
}

uint8_t readSerial (char* buf){
  uint8_t receivedMessage = 0;
  if(Serial.available()){
    Serial.readBytes(buf,2);
    if (~buf[0] != buf[1]){
      Serial.println("invalid message");
    }
    else {
      Serial.println("received");
      receivedMessage = 1;
    }
  }
  return receivedMessage;
}

