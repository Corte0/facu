#include <stdio.h>

int main(){
  char var[20];
  char* ptr = var;


  for(int i=0; i<20; i++){
    printf("ingrese huevada\n");
    scanf("%c", (ptr+i));
        }

  for(int i=0; i<=20; i++){
    printf("%c\n", *(ptr+i));
        }
}
