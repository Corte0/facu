#include "Tanque.h"
#include "Bomba.h"

Tanque tanques[3] = {
    Tanque(8,9), //pinboya, pin electrovalvula
    Tanque(7,6),
    Tanque(4,6),
  };

Bomba bomba(13);

void setup() {
  bomba.setUp();
  for (int i = 0; i < 3; i++) {
       tanques[i].setUp();
  }
}

void loop() {
  if((tanques[0].isEmpty() || tanques[1].isEmpty() || tanques[2].isEmpty())){
    bomba.start();
    for (int i = 0; i < 3; i++)
      if (tanques[i].isEmpty()){
        while(tanques[i].isEmpty())
          tanques[i].EVOpen();
        tanques[i].EVClose();
      }
    bomba.stop();
  }
}
