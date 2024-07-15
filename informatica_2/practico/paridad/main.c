#include <stdio.h>

int checkParity(void *a, size_t size);
void printBinary(void *a, size_t size);

int main (int argc, char *argv[]){
  char a = 'a';
  int num = 3;

  printBinary(&a,sizeof(a));
  printf("\nthe parity of '%c' is %s\n",a,checkParity(&a,sizeof(a))?"odd":"even");

  printBinary(&num,sizeof(num));
  printf("\nthe parity of '%d' is %s\n",num,checkParity(&num,sizeof(num))?"odd":"even");
}

int checkParity(void *a, size_t size){
  int count = 0;
  char *ptr = (char*) a;

  for (int j = 0; j < size; j++)
    for (int i = 0; i < 8 ; i++)
      if((*(ptr+j) >> i) & 0x1) count++;

  return count % 2;
}

void printBinary(void *a, size_t size){
  int count = 0;
  char *ptr = (char*) a;

  for (int j = size - 1; j >= 0; j--)
    for (int i = 7; i >= 0 ; i--)
      printf("%d",*(ptr+j) & (1 << i) ? 1 : 0);

  return;
}

