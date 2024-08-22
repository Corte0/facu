#include <Arduino.h>

class Bomba{
  public:
    Bomba(int _pin);
    void setUp();
    int readStatus();
    int start();
    int stop();
  private:
    int pin=0;
    int status;
};
