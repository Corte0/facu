#include "utils.h"

unsigned int pot(unsigned int base, int exponente){
  if(exponente == 0)
    return 1;
  return base * pot(base, exponente-1);
}
