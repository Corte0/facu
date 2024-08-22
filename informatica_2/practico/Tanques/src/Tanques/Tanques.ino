#include "Tanque.h"
#include "Bomba.h"

Tanque tanques[3] = {
    Tanque(8,9), //pinboya, pin electrovalvula
    Tanque(7,6),
    Tanque(4,5),
  };

Bomba bomba(13);

void setup() {
  bomba.setUp();
  for (int i = 0; i < 3; i++)
       tanques[i].setUp();

  Serial.begin(9600);
  delay(100);
}

void loop() {
  int priority = 0;

  if((tanques[0].isEmpty() || tanques[1].isEmpty() || tanques[2].isEmpty()))
    bomba.start();
  if(!(tanques[0].isEmpty() || tanques[1].isEmpty() || tanques[2].isEmpty()))
    bomba.stop();

  for (int i = 0; i < 3; i++){
    priority += tanques[i].isEmpty()*(int)pow(2,(3-i));
    Serial.println(priority);
    }


  for (int i = 0; i < 3; i++){
    if(priority >= pow(2,3-i) && priority < pow(2,4-i)-1)
      tanques[i].EVOpen();
    else{
      tanques[i].EVClose();
    }
  }
}
