#include "pines.h"
#include "utils.h"
#include "Tanque.h"
#include "Bomba.h"

Tanque tanques[3] = {
    Tanque(PIN_BOYA_1,PIN_EV_1),
    Tanque(PIN_BOYA_2,PIN_EV_2),
    Tanque(PIN_BOYA_3,PIN_EV_3),
  };

Bomba bomba(PIN_BOMBA);

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

  for (int i = 0; i < 3; i++)
    priority += tanques[i].isEmpty()*pot(2,(3-i));


  for (int i = 0; i < 3; i++)
    if(priority >= pot(2,3-i) && priority < pot(2,4-i)-1)
      tanques[i].EVOpen();
    else
      tanques[i].EVClose();
}
