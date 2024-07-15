#include <stdint.h>

void setup() {
  Serial.begin(9600);
  DDRD = 0b00011100;
  DDRB = 0b00000000;
}

void loop() {
  static char buf[500];
  static char message[500] = "puto el que lee!";

  if (readSerial(buf, sizeof(buf)/sizeof(char))){
  }

  Encrypt(message,500);
  Serial.println(message);
  delay (5000);
}

void Encrypt(char* message, int size){
  int i = 0;
  while (message[i] != '\0'){
    if (size == i) break;
    flipBits(&message[i],4,2);
    i++;
  }
  return;
}

void deEncrypt(char* message, int size){
  int i = 0;
  while (message[i] != '\0'){
    if (size == i) break;
    flipBits(&message[i],4,2);
    i++;
  }
  return;
}

uint8_t flipBits(char *ptr, uint8_t bit1, uint8_t bit2){
  if (bit1 > 8) return -1;
  if (bit2 > 8) return -1;

  uint8_t tmp = (*ptr >> bit1) & 0x1;
/*             clean bits                     switch values       */
  *ptr = (*ptr & ~(0x1 << bit1)) | ((*ptr >> bit2) & 0x1) << bit1;
  *ptr = (*ptr & ~(0x1 << bit2)) | (tmp << bit2);

  return 0;
}

uint8_t readSerial (char* buf, int size){
  uint8_t receivedMessage = 0;
  if(Serial.available()){
    Serial.readBytes(buf,size-1);
    receivedMessage = 1;
  }
  return receivedMessage;
}

