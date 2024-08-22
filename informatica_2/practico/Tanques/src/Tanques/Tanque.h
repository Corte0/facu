#include <Arduino.h>

class Tanque{
  public:
    Tanque(int _pinBoya,int _pinEV);
    void setUp();
    int isEmpty();
    void EVOpen();
    void EVClose();
  private:
    int pinBoya=0;
    int pinEV=0;
};
