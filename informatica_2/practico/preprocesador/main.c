#include <stdio.h>

#ifndef A
  #define A 2
#endif

#ifndef B
  #define B 3
#endif

#ifndef MENSAJEA
  #define MENSAJE "Hola mundo"
#endif

#ifndef OPERACION
  #define OPERACION(a,b) (a)*(b)
#endif

#ifndef PI
  #define PI 3.14
#endif

#ifndef RADIO
  #define RADIO 2.00
#endif

#ifndef CIRCLE_AREA
  #define CIRCLE_AREA(r) PI*r*r
#endif

int main (){
  printf("%s\n",MENSAJE);
  printf("%d\n",OPERACION(A,B));
  printf("%f\n",PI);
  printf("%f\n",RADIO);
  printf("%f\n",CIRCLE_AREA(RADIO));
}
