#include "Bomba.h"

Bomba::Bomba(int _pin){
  pin = _pin;
}

void Bomba::setUp(){
  pinMode(pin,OUTPUT);
}

int Bomba::readStatus(){
  return status;
}

int Bomba::start(){
  status = 1;
  digitalWrite(pin,status);
  return status;
}

int Bomba::stop(){
  status = 0;
  digitalWrite(pin,status);
  return status;
}
