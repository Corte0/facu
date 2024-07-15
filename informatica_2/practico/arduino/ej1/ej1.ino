void setup() {
  Serial.begin(9600);
  DDRD = 0b00011100;
  DDRB = 0b00000000;
}

void loop() {
  static unsigned long printTime = 500;
  static unsigned long lastPrint = 0;
  PORTD = (PORTD & 0b11100011) | ((PINB << 2) & 0b00011100);
  if (millis() - lastPrint >= printTime){
    Serial.print("entradas: ");
    Serial.println(PINB,BIN);
    Serial.print("salidas: ");
    Serial.println(PORTD,BIN);
    lastPrint=millis();
  }
}

