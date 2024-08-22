#include "Tanque.h"

Tanque::Tanque(int _pinBoya,int _pinEV){
  pinBoya = _pinBoya;
  pinEV = _pinEV;
}

void Tanque::setUp(){
  pinMode(pinBoya,INPUT);
  pinMode(pinEV,OUTPUT);
}

int Tanque::isEmpty(){
  return digitalRead(pinBoya);
}

void Tanque::EVOpen(){
  digitalWrite(pinEV,1);
}
void Tanque::EVClose(){
  digitalWrite(pinEV,0);
}
