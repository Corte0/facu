#include <stdio.h>
#include <math.h>

float calcularAreaCirculo(float radio);
float celciusAFarenheit(float celcius);
int esPar(int n);
int contarDigitos(int n);
int potencia (int n, int pot);
int invertirEntero(int n);

int main () {
  int n = 1234;
  printf("numero: %d\ninverso: %d\ndigitos: %d\n",n,invertirEntero(n), contarDigitos(n));
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
  int digitos = 1, potencia = 10;
  while (n %  potencia != n){
    digitos++;
    potencia *= 10;
  }
  return digitos;
}

int potencia (int n, int pot){
  int res = n;
  for(int i=1; i<pot; i++)
    res *= n;
  return res;
}

int invertirEntero(int n){
  int res = 0;
  while (n != 0){
    res = res * 10 + n % 10;
    n /= 10;
  }
  return res;
}