#include <stdio.h>

int main (){
  char arreglo[20];
  for (int i = 0; i <= 20; i++){
    printf("ingrese el elemento %d: ",i+1);
    scanf("%c",arreglo + i);
    getchar();
  }
  printf("%s",arreglo);
}
