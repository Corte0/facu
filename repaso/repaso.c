#include <stdio.h>
#include <math.h>

float calcularAreaCirculo(float radio);
float celciusAFarenheit(float celcius);
int esPar(int n);
int contarDigitos(int n);
int potencia (int n, int pot);

int main () {
  printf("digitos: %d\n",contarDigitos(120));
  return 0;
}

float calcularAreaCirculo(float radio){
  return (M_PI * radio * radio);
}

float celciusAFarenheit(float celcius){
  return (float)180/100 * celcius + 32;
}

int esPar(int n){
  return n % 2;
}

int contarDigitos(int n){
  int digitos = 1;
  while (n % potencia(10,digitos) != n)
    digitos++;
  return digitos;
}

int potencia (int n, int pot){
  int res = n;
  for(int i=1; i<pot; i++)
    res = res*n;
  return res;
}
